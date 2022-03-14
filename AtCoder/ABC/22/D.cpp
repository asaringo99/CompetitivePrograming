#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n ;

struct Point {
    double x, y;
    bool operator <(const Point &p) const {
        return x < p.x || (x == p.x && y < p.y);
    }
};

ll cross(const Point &O, const Point &A, const Point &B){
    return (A.x - O.x) * (ll)(B.y - O.y) - (A.y - O.y) * (ll)(B.x - O.x);
}

vector<Point> convex_hull(vector<Point> P){
    int n = P.size(), k = 0;
    vector<Point> H(2*n);

    sort(P.begin(), P.end());

    for (int i = 0; i < n; i++) {
        while (k >= 2 && cross(H[k-2], H[k-1], P[i]) <= 0) k--;
        H[k++] = P[i];
    }

    for (int i = n-2, t = k+1; i >= 0; i--) {
        while (k >= t && cross(H[k-2], H[k-1], P[i]) <= 0) k--;
        H[k++] = P[i];
    }

    H.resize(k);
    return H;
}

int main(){
    cin >> n ;
    vector<Point> vec1 , vec2 ;
    rep(i,n){
        double x , y ;
        cin >> x >> y ;
        vec1.push_back(Point{x,y}) ;
    }
    rep(i,n){
        double x , y ;
        cin >> x >> y ;
        vec2.push_back(Point{x,y}) ;
    }
    vector<Point> tur = convex_hull(vec1) , fal = convex_hull(vec2) ;
    int v = tur.size() ;
    double T = 0 ;
    for(int i = 0 ; i < v - 1 ; i++){
        Point t1 = tur[i] , t2 = tur[i+1] ;
        T += sqrt((double)(t1.x - t2.x) * (t1.x - t2.x) + (t1.y - t2.y) * (t1.y - t2.y)) ;
    }
    double S = 0 ;
    for(int i = 0 ; i < v - 1 ; i++){
        Point s1 = fal[i] , s2 = fal[i+1] ;
        S += sqrt((double)(s1.x - s2.x) * (s1.x - s2.x) + (s1.y - s2.y) * (s1.y - s2.y)) ;
    }
    cout << setprecision(15) << S / T << endl ;
}