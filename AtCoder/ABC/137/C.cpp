#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

int n ;

map<string,int> mp ;

int main(){
    cin >> n ;
    ll res = 0 ;
    rep(i,n){
        string S ;
        cin >> S ;
        sort(S.begin(),S.end()) ;
        res += mp[S] ;
        mp[S]++ ;
    }
    cout << res << endl ;
}