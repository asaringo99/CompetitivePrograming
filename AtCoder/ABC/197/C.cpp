#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define MAX_N (ll)2e5
#define YES cout << "Yes" << endl 
#define NO cout << "No" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)
#define a_z "abcdefghijklmnopqrstuvwxyz"

int n ;

int main(){
    cin >> n ;
    ll A[n] ;
    for(int i = 0 ; i < n ; i++) cin >> A[i] ;
    ll res = LLONG_MAX ;
    for(int i = 0 ; i < (1 << n) ; i++){
        vector<ll> pes ;
        ll tmp = 0 ;
        int bef = 0 ;
        for(int j = 0 ; j < n ; j++){
            if(i >> j & 1){
                if(bef) tmp |= A[j] ;
                else{
                    pes.push_back(tmp) ;
                    tmp = A[j] ;
                    bef = 1 ;
                }
            }
            else{
                if(!bef) tmp |= A[j] ;
                else{
                    pes.push_back(tmp) ;
                    tmp = A[j] ;
                    bef = 0 ;
                }
            }
        }
        pes.push_back(tmp) ;
        ll sum = 0 ;
        for(int j = 0 ; j < pes.size() ; j++){
            sum ^= pes[j] ;
            //cout << i << " " << pes[j] << endl ;
        }
        res = min(res,sum) ;
    }
    cout << res << endl ;
}