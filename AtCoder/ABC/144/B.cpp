#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define MAX_N (ll)2e5
#define YES cout << "Yes" << endl 
#define NO cout << "No" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)

int n ;

int main(){
    cin >> n ;
    bool ok = false  ;
    for(int i = 1 ; i < 10 ; i++){
        for(int j = 1 ; j < 10 ; j++){
            if(i * j == n) ok = true ;
        }
    }
    if(ok) YES ;
    else NO ;
}