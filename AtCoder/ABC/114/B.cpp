#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define MAX_N (ll)2e5
#define YES cout << "YES" << endl 
#define NO cout << "NO" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)
#define a_z "abcdefghijklmnopqrstuvwxyz"
#define A_Z "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

string S ;

int main(){
    cin >> S ;
    int n = S.size() - 2 ;
    int res = INT_MAX ;
    for(int i = 0 ; i < n ; i++){
        res = min(res,abs(753-((S[i]-'0')*100+(S[i+1]-'0')*10+(S[i+2]-'0')))) ;
    }
    cout << res << endl ;
}