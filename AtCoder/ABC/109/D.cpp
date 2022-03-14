#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef tuple<int,int,int,int> TP ;
#define MAX_N (ll)500
#define YES cout << "Yes" << endl 
#define NO cout << "No" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)
#define a_z "abcdefghijklmnopqrstuvwxyz"
#define A_Z "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

int H , W ;

int main(){
    cin >> H >> W ;
    int S[H][W] ;
    for(int i = 0 ; i < H ; i++){
        for(int j = 0 ; j < W ; j++){
            cin >> S[i][j] ;
        }
    }
    int sum = 0 ;
    vector<TP> res ;
    for(int i = 0 ; i < H - 1 ; i++){
        for(int j = 0 ; j < W ; j++){
            if(S[i][j] % 2 != 0) {
                res.push_back({i+1,j+1,i+2,j+1}) ;
                S[i+1][j]++ ;
                sum++ ;
            }
        }
    }
    for(int i = 0 ; i < W - 1 ; i++){
        if(S[H-1][i] % 2 != 0){
            res.push_back({H,i+1,H,i+2}) ;
            S[H-1][i+1]++ ;
            sum++ ;
        }
    }
    cout << sum << endl ;
    for(TP tpl : res){
        int a , b , c , d ;
        tie(a , b , c , d) = tpl ;
        cout << a << " " << b << " " << c << " " << d << endl ;
    }
}