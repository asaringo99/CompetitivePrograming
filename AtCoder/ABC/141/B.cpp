#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<int,int> P ;
typedef tuple<int,int,int> TP ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

string S ;

int main(){
    cin >> S ;
    int n = S.size() ;
    rep(i,n){
        if(i % 2 == 0) if(S[i] == 'L'){
            cout << "No" << endl ;
            return 0 ;
        }
        if(i % 2 == 1) if(S[i] == 'R'){
            cout << "No" << endl ;
            return 0 ;
        }
    }
    cout << "Yes" << endl ;
}