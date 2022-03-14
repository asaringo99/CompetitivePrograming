#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define MAX_N (ll)2e5
#define YES cout << "Yes" << endl 
#define NO cout << "No" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)

ll n ;

int main(){
    cin >> n ;
    string S = to_string(n) ;
    ll ten = 10 , nine = 9 ;
    ll T = pow(ten,S.size() - 1) ;
    //ll K = ((S[0] - '0') - 1) * ((S.size() - 1) / 3)
    ll K = (n - T + 1) * ((S.size() - 1) / 3) ;
    //cout << K << endl ;
    for(ll i = S.size() - 1 ; i >= 1 ; i--){
        K += nine * pow(ten,i-1) * ((i - 1) / 3) ;
    }
    cout << K << endl ;
}