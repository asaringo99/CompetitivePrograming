#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

string S ;

int main(){
    cin >> S ;
    int n = S.size() ;
    if(n == 2){
        if(S[0] != S[1]) cout << -1 << " " << -1 << endl ;
        if(S[0] == S[1]) cout << 1 << " " << 2 << endl ;
        return 0 ;
    }
    rep(i,n-3){
        int alf[26] ;
        memset(alf,0,sizeof(alf)) ;
        rep(j,3) alf[S[i+j]-'a']++ ;
        rep(j,26) if(alf[j] >= 2){
            cout << i + 1 << " " << i + 3 << endl ;
            return 0 ;
        }
    }
    cout << -1 << " " << -1 << endl ;
}