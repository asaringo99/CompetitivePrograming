#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n ;
set<ll> st ;

int main(){
    cin >> n ;
    rep(i,n){
        ll a ;
        cin >> a ;
        while(a % 2 == 0){
            a /= 2 ;
        }
        st.insert(a) ;
    }
    cout << st.size() << endl ;
}