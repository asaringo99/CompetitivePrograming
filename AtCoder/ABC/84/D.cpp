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

int q ;

bool is_prime[100007] ;
int S[100007] ;

void prime_check(){
    memset(is_prime,1,sizeof(is_prime)) ;
    is_prime[0] = is_prime[1] = false ;
    for(int i = 2 ; i <= 100007 ; i++){
        if(!is_prime[i]) continue ;
        for(int j = 2 * i ; j <= 100007 ; j += i){
            is_prime[j] = false ;
        }
    }
}

void like_number(){
    S[1] = 0 ;
    for(int i = 3 ; i <= 100007 ; i += 2){
        if(is_prime[i] && is_prime[(i + 1) / 2]) S[i] = S[i-2] + 1 ;
        else S[i] = S[i-2] ; 
    }
}

int main(){
    cin >> q ;
    prime_check() ;
    like_number() ;
    for(int i = 0 ; i < q ; i++){
        int l , r ;
        cin >> l >> r ;
        l = l - 2 < 0 ? 1 : l - 2 ;
        cout << S[r] - S[l] << endl ;
    }
}