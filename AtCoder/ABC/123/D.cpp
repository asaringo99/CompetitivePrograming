#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define MAX_N (ll)2e5
#define YES cout << "Yes" << endl 
#define NO cout << "No" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)
#define a_z "abcdefghijklmnopqrstuvwxyz"
#define A_Z "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

int x , y , z , k ;
ll A[1007] , B[1007] , C[1007] ;

vector<ll> val ;

bool cal(ll m){
    int count = 0 ;
    vector<ll> vec ;
    for(int i = 0 ; i < x ; i++){
        for(int j = 0 ; j < y ; j++){
            for(int l = 0 ; l < z ; l++){
                if(A[i] + B[j] + C[l] < m) break ;
                vec.push_back(A[i] + B[j] + C[l]) ;
                count++ ;
                if(count == 1000000) {
                    val = vec ;
                    return true ;
                }
            }
        }
    }
    if(count >= k){
        val = vec ;
        return true ;
    }
    return false ;
}

int main(){
    cin >> x >> y >> z >> k ;
    for(int i = 0 ; i < x ; i++) cin >> A[i] ;
    for(int i = 0 ; i < y ; i++) cin >> B[i] ;
    for(int i = 0 ; i < z ; i++) cin >> C[i] ;
    sort(A,A+x,greater<ll>()) ;
    sort(B,B+y,greater<ll>()) ;
    sort(C,C+z,greater<ll>()) ;
    ll lef = 0 , rig = 30000000000 ;
    vector<ll> res ;
    while(rig - lef > 0){
        ll m = (rig + lef) / 2 ;
        if(cal(m)){
            lef = m + 1 ;
            res = val ;
        }
        else rig = m ;
    }
    sort(res.begin(),res.end(),greater<ll>()) ;
    for(int i = 0 ; i < k ; i++) cout << res[i] << endl ;
}