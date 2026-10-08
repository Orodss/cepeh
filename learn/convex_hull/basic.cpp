#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct point{
    long long x,y;
};

ll cross(point a,point b,point c){
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

vector<point> generate_lower_hull(vector<point> &points){
    vector<point> hull;
    if(points.size() <= 1) return points;
    for(point p : points){
        while(hull.size() >= 2 && cross(hull[hull.size() - 2],hull[hull.size() - 1],p) <= 0){
            hull.pop_back();
        }
        hull.push_back(p);
    }
    return hull;
}
vector<point> generate_upper_hull(vector<point> &points){
    vector<point> hull;
    if(points.size() <= 1) return points;
    for(int i = points.size() - 1; i >= 0; --i){
        while(hull.size() >= 2 && cross(hull[hull.size() - 2],hull[hull.size() - 1],points[i]) <= 0){
            hull.pop_back();
        }
        hull.push_back(points[i]);
    }
    return hull;
}
double dist(point a,point b){
    double dx = a.x - b.x;
    double dy = a.y - b.y;
}
double kel(vector<point> hull){
    double res = 0;
    for(int i = 0; i < hull.size(); ++i){
        res += dist(hull[i],hull[(i + 1) % hull.size()]);
    }
    return res;
}
double luas(vector<point> hull){
    double res = 0;
    for(int i = 0; i < hull.size(); ++i){
        ll j = (i + 1) % hull.size();
        res += hull[i].x * hull[j].y;
        res += hull[i].y * hull[j].x;
    }
    return res / 2.0;
}
int main(){
    vector<point> points = {
        {0,1},
        {0,2},
        {1,3},
        {4,5},
        {2,3},
        {1,5},
    };
    sort(points.begin(),points.end(),[](point a,point b){
        if(a.x != b.x) return a.x < b.x;
        return a.y < b.y;
    });
    vector<point> lower = generate_lower_hull(points);
    vector<point> upper = generate_upper_hull(points);
    lower.pop_back();
    upper.pop_back();
    lower.insert(lower.end(),upper.begin(),upper.end());
    for(auto p : lower){
        cout << p.x << " " << p.y << "\n";
    }
}