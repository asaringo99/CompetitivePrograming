#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,int> PP ;
#define MAX_N (ll)2e5
#define YES cout << "Yes" << endl 
#define NO cout << "No" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)
#define a_z "abcdefghijklmnopqrstuvwxyz"
#define A_Z "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

int n ;
ll P ;

int main(){
    cin >> n >> P ;
    ll X[n] , V[n] ;
    for(int i = 0 ; i < n ; i++) cin >> X[i] >> V[i] ;
    ll A[n] , B[n] , a = 0 , b = 0 ;
    for(int i = 0 ; i < n ; i++){
        A[i] = V[i] - X[i] + a ;
        a = X[i] ;
        B[i] = V[n-1-i] - (P - X[n-1-i] - b) ;
        b = P - X[n-1-i] ;
    }
    ll C[n+1] , D[n+1] ;
    C[0] = 0 ;
    D[0] = 0 ;
    for(int i = 0 ; i < n ; i++){
        C[i+1] = C[i] + A[i] ;
        D[i+1] = D[i] + B[i] ;
    }
    PP S[n+1] , T[n+1] ;
    S[0].first = 0 ;
    T[0].first = 0 ;
    S[0].second = 0 ;
    T[0].second = n - 1 ;
    for(int i = 0 ; i < n ; i++){
        if(S[i].first > C[i+1]){
            S[i+1].first = S[i].first ;
            S[i+1].second = S[i].second ;
        }
        else{
            S[i+1].first = C[i+1] ;
            S[i+1].second = i ;
        }
        if(T[i].first > D[i+1]){
            T[i+1].first = T[i].first ;
            T[i+1].second = T[i].second ;
        }
        else{
            T[i+1].first = D[i+1] ;
            T[i+1].second = n - 1 - i ;
        }
    }
    ll res = 0 ;
    for(int i = 0 ; i < n + 1 ; i++){
        if(i == 0 || i == n){
            res = max(T[i].first + S[n-i].first , res) ;
            res = max(S[i].first + T[n-i].first , res) ;            
        }
        else{
            res = max(T[i].first + S[n-i].first - (P - X[T[i].second]) , res) ;
            res = max(S[i].first + T[n-i].first - X[S[i].second] , res) ;
        }
    }
    cout << res << endl ;
}