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

int n , k ;
string S ;

int main(){
    cin >> n >> k >> S ;
    int lef = 0 , rig = 0 , res = 0 ;
    int change = 0 ;
    while(rig < n){
        while(rig < n && change < k){
            while(rig < n && S[rig] == '1') rig++ ;
            while(rig < n && S[rig] == '0') rig++ ;
            change++ ;
        }
        while(rig < n && S[rig] == '1') rig++ ;
        res = max(res,rig - lef) ;
        while(S[lef] == '1') lef++ ;
        while(S[lef] == '0') lef++ ;
        change-- ;
    }
    cout << res << endl ;
}