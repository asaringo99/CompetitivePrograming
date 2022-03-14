#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

const int mod = 1000000007 ;

int n , k ;
int prime_factor[1000007] ;
vector<int> divisor ;

void f(){
    memset(prime_factor,-1,sizeof(prime_factor)) ;
    prime_factor[0] = prime_factor[1] = 1 ;
    for(int i = 2 ; i < 1000001 ; i++){
        if(prime_factor[i] == -1){
            for(int j = i ; j < 1000001 ; j++) prime_factor[j] = i ;
        }
    }
}

void g(ll x){
    for(int i = 1 ; i * i <= x ; i++){
        if(x % i == 0){
            divisor.push_back(i) ;
            if(i * i != x) divisor.push_back(x/i) ;
        }
    }
    sort(divisor.begin(),divisor.end()) ;
}

int main(){
    cin >> n >> k ;
    f() ; g(k) ;
    int m = divisor.size() ;
    ll res = 0 ;
    for(int i = 0 ; i < m ; i++){
        int di = divisor[i] , div = divisor[i] ;
        set<int> st ;
        while(di != 1){
            st.insert(prime_factor[di]) ;
            di /= prime_factor[di] ;
        }
        int o = st.size() ;
        vector<int> vec ;
        for(int u : st) vec.push_back(u) ;
        ll sum = 0 ;
        ll range = n / div ;
        for(int S = 1 ; S < (1 << o) ; S++){
            int count = 0 ;
            ll val = 1 ;
            for(int j = 0 ; j < o ; j++) if(S >> j & 1){
                count++ ;
                val *= vec[j] ;
            }
            ll a = range / val ;
            ll b = a * (a+1) / 2 % mod * val ;
            if(count % 2 == 1) sum = (sum + b) % mod ;
            if(count % 2 == 0) sum = (sum - b) % mod ;
        }
        cout << range << " " << range * (range + 1) / 2 << " " << sum << endl ;
        res += (range * (range - 1) / 2 % mod - sum + mod) % mod ;
        cout << res << endl ;
    }
    cout << (res * k) % mod << endl ;
}