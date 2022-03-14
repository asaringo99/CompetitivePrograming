#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

string S ;

int main(){
    cin >> S ;
    int n = S.size() ;
    string res = "" ;
    int count = 1 ;
    rep(i,n){
        if(i == n - 1){
            res += S[i] + to_string(count) ;
            break ;
        }
        if(S[i] == S[i+1]) count++ ;
        else{
            res += S[i] + to_string(count) ;
            count = 1 ;
        }
    }
    cout << res << endl ;
}