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
    int A[n] ;
    for(int i = 0 ; i < n ; i++){
        cin >> A[i] ;
    }
    ll rig = 0 , lef = 0 , res = 0 , XOR = 0 ;
    while(rig < n){
        while(rig < n && (XOR & A[rig]) == 0){
            XOR ^= A[rig] ;
            res += rig - lef + 1 ;
            rig++ ;
        }
        if(rig == n) break ;
        while((XOR & A[rig]) != 0){
            XOR ^= A[lef] ;
            lef++ ;
        }
    }
    cout << res << endl ;
}