#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define MAX_N (ll)2e5
#define YES cout << "Yes" << endl 
#define NO cout << "No" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)
#define a_z "abcdefghijklmnopqrstuvwxyz"

ll N ;

int main(){
    cin >> N ;
    string S = to_string(N) ;
    bool ok = true ;
    for(int i = 1 ; i < S.size() ; i++){
        if(S[i] != '0') ok = false ;
    }
    if(ok){
        N = N - 1 ;
        S = to_string(N) ;
    }
    if(S.size() % 2 != 0) {
        int n = S.size() ;
        N = pow(10,n / 2) - 1 ;
        cout << N << endl ;
        return 0 ;
    }
    else{
        ll a = 0 , b = 0 ;
        for(int i = 0 ; i < S.size() / 2 ; i++) a += pow(10,i) * (S[S.size() / 2 - 1 - i] - '0') ;
        for(int i = 0 ; i < S.size() / 2 ; i++) b += pow(10,i) * (S[S.size() - 1 - i] - '0') ;
        if(a <= b) cout << a << endl ;
        else cout << a - 1 << endl ;
    }
}