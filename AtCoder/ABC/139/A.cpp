#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<int,int> P ;
typedef tuple<int,int,int> TP ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

string S , T ;

int main(){
    cin >> S >> T ;
    int res = 0 ;
    rep(i,3) if(S[i] == T[i]) res++ ;
    cout << res << endl ;
}