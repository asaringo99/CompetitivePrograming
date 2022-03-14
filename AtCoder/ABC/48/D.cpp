#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

string S ;

int main(){
    cin >> S ;
    int n = S.size() ;
    if(S[0] == S[n-1]){
        if(n & 1) cout << "Second" << endl ;
        else cout << "First" << endl ;
    }
    if(S[0] != S[n-1]){
        if(n & 1) cout << "First" << endl ;
        else cout << "Second" << endl ;
    }
}