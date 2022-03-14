#include <bits/stdc++.h>
using namespace std ;
typedef unsigned long long ll ;
#define MAX_N (ll)2e5
#define YES cout << "Yes" << endl 
#define NO cout << "No" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)
#define a_z "abcdefghijklmnopqrstuvwxyz"

ll x , y ;

int main(){
    cin >> x >> y ;
    int count = 0 ;
    while(x <= y){
        x *= 2 ;
        count++ ;
    }
    cout << count << endl ;
}