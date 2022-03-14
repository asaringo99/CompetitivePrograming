#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define MAX_N 3007
#define YES cout << "Yes" << endl 
#define NO cout << "No" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)
#define a_z "abcdefghijklmnopqrstuvwxyz"
#define A_Z "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

double pes[1007][1007] ; // (n!)を格納

void cal(){
    memset(pes,0,sizeof(pes)) ;
    pes[0][0] = 1 ;
    for(int i = 1 ; i < 1005 ; i++){
        pes[i][0] = pes[i-1][0] / 2 ;
        for(int j = 1 ; j <= i ; j++){
            pes[i][j] = (pes[i-1][j-1] + pes[i-1][j]) / 2 ;
        }
    }
}

int n , d ;
int x , y ;

int main(){
    cal() ;
    cin >> n >> d >> x >> y ;
    if(x % d != 0 || y % d != 0){
        cout << 0 << endl ;
        return 0 ;
    }
    int dx = abs(x / d) , dy = abs(y / d) ;
    if(dx + dy > n){
        cout << 0 << endl ;
        return 0 ;
    }
    if((n - dx - dy) % 2 != 0){
        cout << 0 << endl ;
        return 0 ;
    }
    double P = 0 ;
    for(int i = dx ; n - i >= dy ; i += 2){
        int x = (i - dx) / 2 , y = (n - i - dy) / 2 ;
        P += pes[n][i] * pes[i][x] * pes[n-i][y] ;
    }
    cout << setprecision(15) << P << endl ;
}