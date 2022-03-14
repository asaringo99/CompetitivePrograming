#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> P ;
#define MAX_N (ll)2e5
#define YES cout << "Yes" << endl 
#define NO cout << "No" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)
#define a_z "abcdefghijklmnopqrstuvwxyz"
#define A_Z "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

int n , m ;

int main(){
    cin >> n >> m ;
    P A[n] ;
    for(int i = 0 ; i < n ; i++) cin >> A[i].first >> A[i].second ;
    sort(A,A+n) ;
    ll res = 0 ;
    for(int i = 0 ; i < n ; i++){
        if(m == 0) break ;
        while(m > 0 && A[i].second > 0){
            A[i].second-- ;
            res += A[i].first ;
            m-- ;
        }
    }
    cout << res << endl ;
}