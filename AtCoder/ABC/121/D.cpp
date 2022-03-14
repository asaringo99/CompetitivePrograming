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

ll A , B ;

int main(){
    cin >> A >> B ;
    bool digit_A[45] , digit_B[45] ;
    memset(digit_A,0,sizeof(digit_A)) ;
    memset(digit_B,0,sizeof(digit_B)) ;
    for(int i = 0 ; i < 45 ; i++){
        if(i == 0){
            if(A % 4 == 2 || A % 4 == 3) digit_A[0] = true ;
        }
        else{
            ll k = pow(2,i + 1) ;
            ll div = A % k - pow(2,i) ;
            if(div < 0) continue ;
            if(div % 2 == 1) digit_A[i] = true ;
        }
    }
    B++ ;
    for(int i = 0 ; i < 45 ; i++){
        if(i == 0){
            if(B % 4 == 2 || B % 4 == 3) digit_B[0] = true ;
        }
        else{
            ll k = pow(2,i + 1) ;
            ll div = B % k - pow(2,i) ;
            if(div < 0) continue ;
            if(div % 2 == 1) digit_B[i] = true ;
        }
    }
    ll res = 0 ;
    for(int i = 0 ; i < 45 ; i++){
        if(digit_A[i] ^ digit_B[i]){
            res += pow(2,i) ;
        }
    }
    cout << res << endl ;
}