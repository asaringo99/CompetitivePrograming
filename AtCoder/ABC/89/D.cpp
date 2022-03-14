#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> P ;
#define MAX_N (ll)2e5
#define YES cout << "Yes" << endl 
#define NO cout << "No" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)
#define a_z "abcdefghijklmnopqrstuvwxyz"
#define A_Z "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

int H , W , d , q ;
map<int,P> rem ;

int S[90001] ;

void bfs(){
    for(int i = 0 ; i < d ; i++){
        S[i] = 0 ;
        for(int j = i + d ; j < H * W ; j += d){
            S[j] = S[j - d] + abs(rem[j].first - rem[j - d].first) + abs(rem[j].second - rem[j - d].second) ;
        }
    }
}

int main(){
    cin >> H >> W >> d ;
    for(int i = 1 ; i <= H ; i++){
        for(int j = 1 ; j <= W ; j++){
            int a ;
            cin >> a ;
            a-- ;
            rem[a] = P(i,j) ;
        }
    }
    bfs() ;
    cin >> q ;
    for(int i = 0 ; i < q ; i++){
        int l , r ;
        cin >> l >> r ;
        r-- ;
        l-- ;
        cout << S[r] - S[l] << endl ;
    }
}