#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n ;
map<ll,ll> mp ;
int A[202020] ;

int main(){
    cin >> n ;
    rep(i,n){
        int a ;
        cin >> a ;
        mp[a]++ ;
        A[i] = a ;
    }
    ll sum = 0 ;
    for(auto it : mp) sum += it.second * (it.second - 1) / 2 ;
    rep(i,n){
        ll res = sum ;
        res -= mp[A[i]] * (mp[A[i]] - 1) / 2 ;
        res += (mp[A[i]] - 2) * (mp[A[i]] - 1) / 2 ;
        cout << res << endl ;
    }
}