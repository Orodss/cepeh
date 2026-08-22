#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin>>n>>m;

	int digits[n], temp;
	for(temp=0;temp<n;temp++) cin>>digits[temp];

	string ans;
	for(auto digit : digits) {

		if(digit == 0) continue;

		int occ[m];
		memset(occ, -1, sizeof(occ));
		int curmod = 0, curcnt = 0;
		while(true) {
			curmod = (curmod*10 + digit)%m;
			curcnt++;
			if(occ[curmod] != -1) {
				break;
			} else {
				occ[curmod] = curcnt;
			}
		}
		for(int temp=occ[curmod]; temp<curcnt; temp++) ans+=to_string(digit);
		for(int temp=0;temp<occ[curmod];temp++) ans+="0";
	}
	cout<<ans<<"\n";
}
