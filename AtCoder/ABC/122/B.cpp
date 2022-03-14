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
    int res = 0 ;
    int count = 0 ;
    for(int i = 0 ; i < n ; i++){
        if(S[i] == 'A' || S[i] == 'T' || S[i] == 'G' || S[i] == 'C'){
            count++ ;
        }
        else count = 0 ;
        res = max(res,count) ;
    }
    cout << res << endl ;
}