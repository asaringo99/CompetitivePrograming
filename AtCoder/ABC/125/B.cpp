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

int main(){
    cin >> n ;
    int V[n] , C[n] ;
    for(int i = 0 ; i < n ; i++) cin >> V[i] ;
    for(int i = 0 ; i < n ; i++) cin >> C[i] ;
    int sum = 0 ;
    for(int i = 0 ; i < n ; i++){
        if(V[i] - C[i] > 0) sum += V[i] - C[i] ;
    }
    cout << sum << endl ;
}