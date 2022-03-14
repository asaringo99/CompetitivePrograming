#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<ld,ld> P ;
typedef tuple<ld,ld,ld> TP ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"
#define dist(a,b,c,d) (a - c) * (a - c) + (b - d) * (b - d)

const ld pi = 3.1415926535 ;
const ld eps = 0.0000000001 ;

int n ;
unordered_map<int,int> mp ;
vector<TP> X ;
ld SX[303] , SY[303] ;

int main(){
    cin >> n ;
    rep(i,n){
        ld x , y ;
        cin >> x >> y ;
        if(x == 0 && y == 0) continue ;
        ld theta = abs(atan(y/x)) ;
        if(x >= 0 && y >= 0) X.push_back({theta,x,y}) ;
        if(x >= 0 && y < 0) X.push_back({2*pi-theta,x,y}) ;
        if(x < 0 && y >= 0) X.push_back({pi-theta,x,y}) ;
        if(x < 0 && y < 0) X.push_back({pi+theta,x,y}) ;
    }
    sort(X.begin(),X.end()) ;
    int m = X.size() ;
    rep(i,2*m){
        ld theta , x , y ;
        tie(theta,x,y) = X[i%m] ;
        SX[i+1] = x + SX[i] ;
        SY[i+1] = y + SY[i] ;
    }
    ld res = 0 ;
    rep(i,m) rrep(j,1,m+1) res = max(res,sqrt(dist(SX[i+j]-SX[i],SY[i+j]-SY[i],0,0))) ;
    cout << fixed << setprecision(25) << res << endl ;
}