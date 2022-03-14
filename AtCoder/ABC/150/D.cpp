#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n , m ;
ll A[101010] ;
set<int> st ;

ll gcd(ll a , ll b){
    if(b == 0) return a ;
    return gcd(b,a%b) ;
}

ll lcm(ll a , ll b){
    return a / gcd(a,b) * b ;
}

int main(){
    cin >> n >> m ;
    rep(i,n){
        ll a , count = 0 ;
        cin >> a ;
        A[i] = a / 2 ;
        while(a % 2 == 0){
            a /= 2 ;
            count++ ;
        }
        st.insert(count) ;
    }
    if(st.size() != 1){
        cout << 0 << endl ;
        return 0 ;
    }
    ll val = 1 ;
    rep(i,n){
        val = lcm(A[i],val) ;
    }
    ll res = m / val ;
    ll mns = res / 2 ;
    cout << res - mns << endl ;
}