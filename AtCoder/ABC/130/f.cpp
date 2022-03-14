#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<int,int> P ;
typedef tuple<int,int,int> TP ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define endl "\n"

int n ;

struct vex{
    ld pls[2] , mns[2] , sty[2] ;
    vex(){
        pls[0] = mns[0] = sty[0] = 1e18 ;
        pls[1] = mns[1] = sty[1] = -1e18 ;
    }
    void stay(ld x){
        chmin(sty[0],x) ;
        chmax(sty[1],x) ;
    }
    void plus(ld x){
        chmin(pls[0],x) ;
        chmax(pls[1],x) ;
    }
    void mins(ld x){
        chmin(mns[0],x) ;
        chmax(mns[1],x) ;
    }
    ld f(ld t){
        ld minval = 1e18 , maxval = -1e18 ;
        maxval = max({sty[1],pls[1]+t,mns[1]-t}) ;
        minval = min({sty[0],pls[0]+t,mns[0]-t}) ;
        return maxval - minval ;
    }
};

int main(){
    cin >> n ;
    vex X , Y ;
    rep(i,n){
        ld x , y ;
        char d ;
        cin >> x >> y >> d ;
        if(d == 'R'){
            X.plus(x) ;
            Y.stay(y) ;
        }
        if(d == 'L'){
            X.mins(x) ;
            Y.stay(y) ;
        }
        if(d == 'U'){
            Y.plus(y) ;
            X.stay(x) ;
        }
        if(d == 'D'){
            Y.mins(y) ;
            X.stay(x) ;
        }
    }
    ld lef = 0 , rig = 1e18 ;
    int count = 0 ; 
    while(count < 1000){
        ld ml = (2 * lef + rig) / 3 , mr = (lef + 2 * rig) / 3 ;
        if(X.f(ml) * Y.f(ml) < X.f(mr) * Y.f(mr)) rig = mr ;
        else lef = ml ;
        count++ ;
    }
    cout << fixed << setprecision(25) << X.f(lef) * Y.f(lef) << endl ;
}