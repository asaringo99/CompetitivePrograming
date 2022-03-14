#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef tuple<int,int,ll> TP ;
typedef pair<int,int> P ;
#define MAX_N (ll)2e5
#define YES cout << "Yes" << endl 
#define NO cout << "No" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)
#define a_z "abcdefghijklmnopqrstuvwxyz"
#define A_Z "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

int n ;

int main(){
    cin >> n ;
    map<TP,ll> rem ;
    set<TP> st ;
    for(int i = 0 ; i < n ; i++) {
        ll x , y , h ;
        cin >> x >> y >> h ;
        if(h == 0) continue ;
        for(ll nx = 0 ; nx <= 100 ; nx++){
            for(ll ny = 0 ; ny <= 100 ; ny++){
                TP tp = {nx,ny,abs(nx-x)+abs(ny-y)+h} ;
                st.insert(tp) ;
                rem[tp]++ ;
            }
        }
    }
    TP res = {0,0,-1} ;
    ll count = 0 ;
    for(TP tp : st){
        if(count <= rem[tp]){
            count = rem[tp] ;
            res = tp ;
        }
    }
    ll x , y , h ;
    tie(x,y,h) = res ;
    cout << x << " " << y << " " << h << endl ;
    
}