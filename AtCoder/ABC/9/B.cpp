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
    int mx1 = 0 , mx2 = 0 ;
    map<int,bool> rem ;
    for(int i = 0 ; i < n ; i++){
        int a ;
        cin >> a ;
        if(rem[a]) continue ;
        rem[a] = true ;
        if(a > mx2) mx2 = a ;
        if(mx2 > mx1) swap(mx1,mx2) ;
    }
    cout << mx2 << endl ;
}