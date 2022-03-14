#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define MAX_N (ll)2e5
#define YES cout << "Yes" << endl 
#define NO cout << "No" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)
#define a_z "abcdefghijklmnopqrstuvwxyz"

int H , W , X , Y ;

char S[100][100] ;

int main(){
    cin >> H >> W >> X >> Y ;
    X-- ; Y-- ;
    for(int i = 0 ; i < H ; i++){
        for(int j = 0 ; j < W ; j++) cin >> S[i][j] ;
    }
    int count = 1 ;
    for(int i = Y + 1 ; i < W ; i++){
        if(S[X][i] == '#') break ;
        count++ ;
    }
    for(int i = Y - 1 ; i >= 0 ; i--){
        if(S[X][i] == '#') break ;
        count++ ;
    }
    for(int i = X + 1 ; i < H ; i++){
        if(S[i][Y] == '#') break ;
        count++ ;
    }
    for(int i = X - 1 ; i >= 0 ; i--){
        if(S[i][Y] == '#') break ;
        count++ ;
    }
    cout << count << endl ;
}