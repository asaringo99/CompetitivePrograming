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

int N , M , Q ;
int train[501][501] , S[501][501] ;

int main(){
    cin >> N >> M >> Q ;
    memset(train,0,sizeof(train)) ;
    for(int i = 0 ; i < M ; i++){
        int l , r ;
        cin >> l >> r ;
        
        train[l][r]++ ;
    }
    for(int i = 0 ; i < 501 ; i++){
        S[0][i] = 0 ;
        S[i][0] = 0 ;
    }
    for(int i = 1 ; i < 501 ; i++){
        for(int j = 1 ; j < 501 ; j++){
            S[i][j] = S[i-1][j] + S[i][j-1] - S[i-1][j-1] + train[i][j] ;
        }
    }
    for(int i = 0 ; i < Q ; i++){
        int p , q ;
        cin >> p >> q ;
        cout << S[q][q] - S[q][p-1] - S[p-1][q] + S[p-1][p-1] << endl ;
    }
}