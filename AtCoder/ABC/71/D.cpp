#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

const int mod = 1000000007 ;

int n ;
string S , T ;

int main(){
    cin >> n >> S >> T ;
    bool ok = true ;
    ll res = 1 ;
    rep(i,n){
        if(ok) {
            res *= 3 ;
            ok = false ;
            if(S[i] != T[i]) res *= 2 ;
        }
        else if(S[i] == T[i]){
            if(S[i-1] == T[i-1]) (res *= 2) %= mod ;
        }
        else {
            if(S[i-1] != S[i] && T[i-1] != T[i] && S[i-1] != T[i-1]) (res *= 3) %= mod ;
            if(S[i-1] != S[i] && T[i-1] != T[i] && S[i-1] == T[i-1]) (res *= 3) %= mod ;
        }
    }
    cout << res << endl ;
}