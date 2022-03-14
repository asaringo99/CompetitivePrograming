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

int a , b , k ;

int main(){
    cin >> a >> b >> k ;
    vector<int> res ;
    for(int i = 1 ; i <= min(a,b) ; i++){
        if(a % i == 0 && b % i == 0){
            res.push_back(i) ;
        }
    }
    cout << res[res.size() - k] << endl ;
}