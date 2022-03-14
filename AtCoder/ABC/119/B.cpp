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

int main(){
    int n ;
    cin >> n ;
    double sum = 0 ;
    for(int i = 0 ; i < n ; i++){
        double x ;
        string u ;
        cin >> x >> u ;
        if(u == "JPY"){
            sum += x ;
        }
        else{
            sum += x * 380000 ;
        }
    }
    cout << setprecision(10) << sum << endl ;
}