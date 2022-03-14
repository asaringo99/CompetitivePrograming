#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

string S ;

int main(){
    cin >> S ;
    sort(S.begin(),S.end()) ;
    if(S[0] == S[1] && S[2] == S[3] && S[0] != S[2]) cout << "Yes" << endl ;
    else cout << "No" << endl ;
}