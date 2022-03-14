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

string S ;

int main(){
    cin >> S ;
    int n = S.size() ;
    int cnt = 0 ;
    for(int i = 0 ; i < n ; i++){
        if(S[i] == '0') cnt++ ;
    }
    cout << min(cnt,n-cnt) * 2 << endl ;
}