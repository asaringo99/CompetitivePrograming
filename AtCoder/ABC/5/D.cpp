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

int n , q ;

int main(){
    cin >> n ;
    int D[n+1][n+1] ;
    for(int i = 0 ; i <= n ; i++){
        D[0][i] = 0 ;
        D[i][0] = 0 ;
    }
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            int d ;
            cin >> d ;
            D[i+1][j+1] = D[i+1][j] + D[i][j+1] - D[i][j] + d ;
        }
    }
    int value[n * n + 1] ;
    memset(value,0,sizeof(value)) ;
    for(int x1 = 0 ; x1 < n ; x1++){
        for(int y1 = 0 ; y1 < n ; y1++){
            for(int x2 = x1 + 1 ; x2 <= n ; x2++){
                for(int y2 = y1 + 1 ; y2 <= n ; y2++){
                    int square = (y2 - y1) * (x2 - x1) ;
                    int v = D[x2][y2] - D[x2][y1] - D[x1][y2] + D[x1][y1] ;
                    value[square] = max(value[square],v) ;
                }
            }
        }
    }
    for(int i = 0 ; i < n * n ; i++) value[i+1] = max(value[i+1],value[i]) ;

    cin >> q ;
    vector<int> res ;
    for(int i = 0 ; i < q ; i++){
        int num ;
        cin >> num ;
        cout << value[num] << endl ;
    }
}