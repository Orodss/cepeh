#!/usr/bin/env python3

import os
import time
import numpy as np
import matplotlib
matplotlib.use("Agg")
import matplotlib.pyplot as plt
from matplotlib.patches import FancyArrowPatch

N = 6
NAMA = ["R1", "R2", "R3", "R4", "R5", "R6"]

FORWARD = {
    (0, 1): 0.4, (0, 2): 0.3,          # R1 -> R2, R3
    (1, 2): 0.3, (1, 3): 0.4,          # R2 -> R3, R4
    (2, 4): 0.5, (2, 1): 0.1,          # R3 -> R5, R2
    (3, 4): 0.3, (3, 5): 0.4,          # R4 -> R5, R6
    (4, 5): 0.5, (4, 2): 0.1,          # R5 -> R6, R3
    (5, 0): 0.2, (5, 3): 0.1,          # R6 -> R1, R4
}
B = np.array([100.0, 80.0, 60.0, 40.0, 20.0, 10.0])

MANUAL_A = None
MANUAL_B = None

TOL = 1e-6
MAX_ITER = 1000
TEBAKAN_AWAL = {
    "x0 = 0": np.zeros(N),
    "x0 = b": B.copy(),
    "x0 = 1000": np.full(N, 1000.0),
}
OUT_DIR = "hasil_output"
# =====================================================================


def bangun_sistem(forward, b, n):
    """Susun A = I - P^T dan b dari fraksi penerusan aliran."""
    P = np.zeros((n, n))
    for (i, j), p in forward.items():
        P[i, j] = p
    return np.eye(n) - P.T, b.astype(float), P


def gauss_jordan(A, b, eps=1e-12):
    """Eliminasi Gauss-Jordan dengan partial pivoting.
    Mengembalikan (x, jumlah_operasi_kali_bagi)."""
    n = len(b)
    M = np.hstack([A.astype(float), b.astype(float).reshape(-1, 1)])
    ops = 0
    for k in range(n):
        p = k + int(np.argmax(np.abs(M[k:, k])))      # partial pivoting
        if abs(M[p, k]) < eps:
            raise ValueError("Matriks singular: pivot mendekati nol.")
        if p != k:
            M[[k, p]] = M[[p, k]]
        M[k] = M[k] / M[k, k]             
        ops += n + 1
        for i in range(n):  
            if i != k:
                M[i] = M[i] - M[i, k] * M[k]
                ops += n + 1
    return M[:, -1].copy(), ops


def gauss_seidel(A, b, x0, tol=TOL, max_iter=MAX_ITER, x_acuan=None):
    n = len(b)
    x = x0.astype(float).copy()
    selisih, residu, galat = [], [], []
    for k in range(1, max_iter + 1):
        x_lama = x.copy()
        for i in range(n):
            s = A[i, :i] @ x[:i] + A[i, i + 1:] @ x[i + 1:]
            x[i] = (b[i] - s) / A[i, i]
        selisih.append(np.max(np.abs(x - x_lama)))
        residu.append(np.linalg.norm(A @ x - b, np.inf))
        if x_acuan is not None:
            galat.append(np.max(np.abs(x - x_acuan)))
        if selisih[-1] < tol:
            return dict(x=x, iterasi=k, konvergen=True,
                        selisih=selisih, residu=residu, galat=galat)
        if not np.all(np.isfinite(x)):
            break
    return dict(x=x, iterasi=len(selisih), konvergen=False,
                selisih=selisih, residu=residu, galat=galat)


def analisis_matriks(A):
    D = np.diag(np.diag(A))
    L = np.tril(A, -1)
    U = np.triu(A, 1)
    T_gs = -np.linalg.solve(D + L, U)                  # matriks iterasi G-S
    T_j = -np.linalg.solve(D, L + U)                   # matriks iterasi Jacobi
    off = np.sum(np.abs(A), axis=1) - np.abs(np.diag(A))
    return dict(
        det=float(np.linalg.det(A)),
        cond=float(np.linalg.cond(A)),
        rank=int(np.linalg.matrix_rank(A)),
        simetris=bool(np.allclose(A, A.T)),
        rasio_dominan=(off / np.abs(np.diag(A))).tolist(),
        dominan_ketat=bool(np.all(np.abs(np.diag(A)) > off)),
        rho_gs=float(np.max(np.abs(np.linalg.eigvals(T_gs)))),
        rho_jacobi=float(np.max(np.abs(np.linalg.eigvals(T_j)))),
    )


def waktu_rata2(fungsi, ulang=200):
    t0 = time.perf_counter()
    for _ in range(ulang):
        fungsi()
    return (time.perf_counter() - t0) / ulang


def persamaan_teks(forward, b, n, nama):
    hasil = []
    for i in range(n):
        masuk = [f"{p:g}·x{j + 1}" for (j, k), p in sorted(forward.items()) if k == i]
        keluar_ke = [f"{nama[k]} ({p:g})" for (j, k), p in sorted(forward.items()) if j == i]
        sisi = f"x{i + 1} = {b[i]:g}" + "".join(f" + {m}" for m in masuk)
        hasil.append((nama[i], sisi, ", ".join(keluar_ke)))
    return hasil


def gambar_topologi(forward, b, path):
    pos = {0: (0, 1), 1: (1.3, 2.2), 2: (1.3, -0.2), 3: (3.0, 2.2),
           4: (3.0, -0.2), 5: (4.3, 1)}
    fig, ax = plt.subplots(figsize=(9, 5))
    ax.set_aspect("equal")
    ax.axis("off")
    ada = set(forward)
    for (i, j), p in forward.items():
        (x1, y1), (x2, y2) = pos[i], pos[j]
        rad = 0.18 if (j, i) in ada else 0.0               # panah dua arah dilengkungkan
        if (i, j) == (5, 0):
            rad = -1.3
        ax.add_patch(FancyArrowPatch(
            (x1, y1), (x2, y2), connectionstyle=f"arc3,rad={rad}",
            arrowstyle="-|>", mutation_scale=14, lw=1.3, color="#2F5496",
            shrinkA=24, shrinkB=24))
        mx = (x1 + x2) / 2 + 0.5 * rad * (y2 - y1)
        my = (y1 + y2) / 2 - 0.5 * rad * (x2 - x1)
        ax.text(mx, my, f"{p:g}", fontsize=9, ha="center", va="center",
                bbox=dict(boxstyle="round,pad=0.15", fc="white", ec="none"))
    for i, (x, y) in pos.items():
        ax.add_patch(plt.Circle((x, y), 0.4, fc="#D9E2F3", ec="#1F3864", lw=1.6, zorder=3))
        ax.text(x, y + 0.1, NAMA[i], ha="center", va="center", fontsize=12,
                weight="bold", zorder=4)
        ax.text(x, y - 0.14, f"b={b[i]:g}", ha="center", va="center", fontsize=8.5,
                color="#C00000", zorder=4)
    ax.set_xlim(-0.8, 5.1)
    ax.set_ylim(-2.1, 2.9)
    ax.set_title("Topologi 6 router (label panah = fraksi aliran diteruskan, "
                 "b = aliran masuk dari luar, paket/detik)", fontsize=10)
    fig.tight_layout()
    fig.savefig(path, dpi=160)
    plt.close(fig)


def gambar_konvergensi(hasil_gs, path):
    fig, ax = plt.subplots(1, 2, figsize=(11, 4.2))
    for nama, r in hasil_gs.items():
        k = np.arange(1, len(r["selisih"]) + 1)
        ax[0].semilogy(k, r["selisih"], marker="o", ms=3, label=nama)
        if r["galat"]:
            ax[1].semilogy(k, np.maximum(r["galat"], 1e-16), marker="o", ms=3, label=nama)
    ax[0].axhline(TOL, color="gray", ls="--", lw=1, label=f"toleransi {TOL:g}")
    ax[0].set(title="Selisih antar iterasi ||x(k) - x(k-1)||∞",
              xlabel="iterasi k", ylabel="selisih")
    ax[1].set(title="Galat terhadap solusi Gauss-Jordan ||x(k) - x*||∞",
              xlabel="iterasi k", ylabel="galat")
    for a in ax:
        a.grid(True, which="both", alpha=0.3)
        a.legend()
    fig.tight_layout()
    fig.savefig(path, dpi=160)
    plt.close(fig)


def main():
    os.makedirs(OUT_DIR, exist_ok=True)
    np.set_printoptions(precision=4, suppress=True, linewidth=120)

    if MANUAL_A is not None and MANUAL_B is not None:
        A, b = np.array(MANUAL_A, float), np.array(MANUAL_B, float)
    else:
        A, b, _ = bangun_sistem(FORWARD, B, N)

    print("=" * 70)
    print("1. FORMULASI SISTEM Ax = b")
    print("=" * 70)
    for nama, pers, ke in persamaan_teks(FORWARD, b, N, NAMA):
        print(f"  {nama}: {pers}      [meneruskan ke: {ke}]")
    print("\nMatriks A =\n", A)
    print("\nVektor b =", b)

    print("\n" + "=" * 70)
    print("2. ANALISIS MATRIKS A")
    print("=" * 70)
    info = analisis_matriks(A)
    print(f"  determinan            : {info['det']:.6f}")
    print(f"  kondisi cond_2(A)     : {info['cond']:.4f}")
    print(f"  rank                  : {info['rank']} (dari {N})")
    print(f"  simetris              : {info['simetris']}")
    print(f"  rasio dominan / baris : {np.round(info['rasio_dominan'], 3)}")
    print(f"  dominan diagonal ketat: {info['dominan_ketat']}")
    print(f"  radius spektral Jacobi: {info['rho_jacobi']:.6f}")
    print(f"  radius spektral G-S   : {info['rho_gs']:.6f}"
          f"  -> {'konvergen (rho < 1)' if info['rho_gs'] < 1 else 'TIDAK konvergen'}")

    print("\n" + "=" * 70)
    print("3. GAUSS-JORDAN (partial pivoting)")
    print("=" * 70)
    x_gj, ops_gj = gauss_jordan(A, b)
    x_np = np.linalg.solve(A, b)
    for i in range(N):
        print(f"  x{i + 1} ({NAMA[i]}) = {x_gj[i]:.6f} paket/detik")
    res_gj = np.linalg.norm(A @ x_gj - b, np.inf)
    sel_np = np.max(np.abs(x_gj - x_np))
    print(f"  residu ||Ax-b||∞         : {res_gj:.3e}")
    print(f"  selisih vs numpy.solve   : {sel_np:.3e}")
    print(f"  operasi kali/bagi        : {ops_gj}")

    print("\n" + "=" * 70)
    print(f"4. GAUSS-SEIDEL (tol = {TOL:g}, maks iterasi = {MAX_ITER})")
    print("=" * 70)
    hasil_gs = {}
    for nama, x0 in TEBAKAN_AWAL.items():
        r = gauss_seidel(A, b, x0, x_acuan=x_gj)
        hasil_gs[nama] = r
        print(f"  {nama:10s}: iterasi = {r['iterasi']:3d}, konvergen = {r['konvergen']}, "
              f"residu = {r['residu'][-1]:.3e}, "
              f"selisih vs G-J = {np.max(np.abs(r['x'] - x_gj)):.3e}")
    r0 = hasil_gs["x0 = 0"]
    print("\n  Solusi (x0 = 0):", np.round(r0["x"], 6))
    print("\n  Riwayat iterasi (x0 = 0):")
    print("   k   selisih      residu       galat vs G-J")
    for k in list(range(1, min(len(r0["selisih"]), 8) + 1)) + [len(r0["selisih"])]:
        print(f"  {k:3d}  {r0['selisih'][k - 1]:.3e}   {r0['residu'][k - 1]:.3e}   "
              f"{r0['galat'][k - 1]:.3e}")

    print("\n  Pengaruh toleransi (x0 = 0):")
    for tol in (1e-3, 1e-6, 1e-9, 1e-12):
        r = gauss_seidel(A, b, np.zeros(N), tol=tol)
        print(f"   tol = {tol:.0e}  -> {r['iterasi']:3d} iterasi")
    if 0 < info["rho_gs"] < 1:
        e0 = np.max(np.abs(np.zeros(N) - x_gj))            # galat awal untuk x0 = 0
        perkiraan = np.log(TOL / e0) / np.log(info["rho_gs"])
        print(f"\n  Perkiraan teoretis iterasi ln(tol/e0) / ln(rho) ≈ {perkiraan:.1f}")

    print("\n" + "=" * 70)
    print("5. PERBANDINGAN KEDUA METODE")
    print("=" * 70)
    t_gj = waktu_rata2(lambda: gauss_jordan(A, b))
    t_gs = waktu_rata2(lambda: gauss_seidel(A, b, np.zeros(N)))
    t_np = waktu_rata2(lambda: np.linalg.solve(A, b))
    print(f"  waktu rata-rata Gauss-Jordan : {t_gj * 1e3:.4f} ms")
    print(f"  waktu rata-rata Gauss-Seidel : {t_gs * 1e3:.4f} ms")
    print(f"  waktu rata-rata numpy.solve  : {t_np * 1e3:.4f} ms")
    print(f"  selisih maksimum G-J vs G-S  : {np.max(np.abs(x_gj - r0['x'])):.3e}")
    print(f"  residu G-J / G-S             : {res_gj:.3e} / {r0['residu'][-1]:.3e}")
    print(f"  cek konservasi: total masuk = {b.sum():g}, "
          f"total keluar (lokal) = {np.sum(x_gj * (1 - np.array([sum(p for (i, j), p in FORWARD.items() if i == r) for r in range(N)]))):.6f}")

    gambar_topologi(FORWARD, b, os.path.join(OUT_DIR, "topologi.png"))
    gambar_konvergensi(hasil_gs, os.path.join(OUT_DIR, "konvergensi.png"))
    print(f"\nGambar disimpan di folder '{OUT_DIR}/'.")

    return dict(A=A, b=b, info=info, x_gj=x_gj, x_np=x_np, ops_gj=ops_gj,
                res_gj=res_gj, hasil_gs=hasil_gs, waktu=(t_gj, t_gs, t_np))


if __name__ == "__main__":
    main()