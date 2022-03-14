#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int t ;

int main(){
    cin >> t ;
    rep(z,t){
        int n ;
        string S ;
        cin >> n >> S ;
        int id = -1 ;
        rep(i,n) if(S[i] != '?'){
            id = i ;
            break ;
        }
        int count = 0 ;
        rrep(i,id,n-1){
            if(S[i+1] == '?') S[i+1] = S[i] == 'B' ? 'R' : 'B' ;
        }
        for(int i = id ; i > 0 ; i--){
            if(S[i-1] == '?') S[i-1] = S[i] == 'B' ? 'R' : 'B' ;
        }
        cout << S << endl ;
    }
}