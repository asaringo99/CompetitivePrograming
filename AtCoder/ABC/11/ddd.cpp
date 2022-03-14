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

double pes[MAX_N+1] ; // (n!)を格納
double tes[MAX_N+1] ; // (x^n)を格納

void cal(){
    pes[0] = 1 ;
    pes[1] = 1 ;
    for(int i = 2 ; i <= 1001 ; i++){
        pes[i] = pes[i-1] * i ;
    }
}

void powcal(){
    tes[0] = 1 ;
    for(int i = 0 ; i <= 1001 ; i++){
        tes[i+1] = 4 * tes[i] ;
    }
}

double combination(int n , int r){
    return pes[n] / pes[n - r] / pes[r] ;
}

int n , d ;
int x , y ;

int main(){
    cal() ;
    powcal() ;
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
        P += pes[n] / pes[dx + x] / pes[x] / pes[dy + y] / pes[y] / tes[n] ;
        //cout << pes[n] << " " << pes[i] << " " << pes[i - dx] << " " << pes[dy + ] << " " << pes[k] << " " << tes[n] << endl ;
    }
    cout << setprecision(10) << P << endl ;
}