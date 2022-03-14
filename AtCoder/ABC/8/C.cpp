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
double kaijo[101] ;

void cal(int n){
    kaijo[0] = 1 ;
    for(int i = 0 ; i < n ; i++) kaijo[i + 1] = kaijo[i] * (i + 1) ;
}

double perm(ll n , ll r){
    return kaijo[n] / kaijo[n-r] ;
}

int main(){
    cin >> n ;
    cal(n) ;
    int C[n] , D[n] ;
    memset(D,0,sizeof(D)) ;
    for(int i = 0 ; i < n ; i++) cin >> C[i] ;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            if(i == j) continue ;
            if(C[i] % C[j] == 0) D[i]++ ;
        }
    }
    double res = 0 ;
    for(int i = 0 ; i < n ; i++){
        double rmp = 0 ;
        for(int j = 0 ; j < n ; j++){
            for(int k = 0 ; k <= D[i] ; k += 2){
                if(j < k || n - 1 - j < k) continue ;
                rmp += perm(j,k) * perm(n-j-1,D[i]-k) * kaijo[n-1-D[i]] ;
                cout << D[i] << " " << j << " " << k << endl ;
                cout << perm(j,k) << " " << perm(n-j-1,D[i]-k) << " " << kaijo[n-1-D[i]] << endl ;
            }
        }
        res += rmp / kaijo[n] ;
    }
    cout << res << endl ;
}