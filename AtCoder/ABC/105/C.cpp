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

int n ;

int main(){
    cin >> n ;
    if(n == 0){
        cout << 0 << endl ;
        return 0 ;
    }
    bool prime[33] ;
    memset(prime,0,sizeof(prime)) ;
    for(int i = 0 ; i < 33 ; i++){
        int k ;
        if(n == 0) break ;
        if(n == -1){
            k = 1 ;
            prime[33 - i - 1] = k ;
            n = 1 ;
        }
        else{
            k = ((n % 2) + 2) % 2 ;
            prime[33 - 1 - i] = k ;
            n /= -2 ;
            if(n > 0 && k) n += 1 ;
        }
    }
    bool ok = false ;
    for(int i = 0 ; i < 33 ; i++){
        if(!ok && prime[i]) ok = true ;
        if(ok) cout << prime[i] ;
    }
    cout << endl; 
}