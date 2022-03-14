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

int H , W ;

int main(){
    cin >> H >> W ;
    bool row[H] , col[W] ;
    char S[H][W] ;
    for(int i = 0 ; i < H ; i++){
        for(int j = 0 ; j < W ; j++) cin >> S[i][j] ;
    }
    for(int i = 0 ; i < H ; i++){
        bool ok = true ;
        for(int j = 0 ; j < W ; j++){
            if(S[i][j] == '#') ok = false ;
        }
        if(ok) row[i] = true ;
        else row[i] = false ;
    }
    for(int i = 0 ; i < W ; i++){
        bool ok = true ;
        for(int j = 0 ; j < H ; j++){
            if(S[j][i] == '#') ok = false ;
        }
        if(ok) col[i] = true ;
        else col[i] = false ;
    }
    for(int i = 0 ; i < H ; i++){
        if(row[i]) continue ;
        for(int j = 0 ; j < W ; j++){
            if(col[j]) continue ;
            cout << S[i][j] ;
        }
        cout << endl ;
    }
}