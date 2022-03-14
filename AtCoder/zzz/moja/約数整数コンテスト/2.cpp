#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n ;
ll A[101010] ;
vector<P> vec ;

ll gcd(ll a , ll b){
    if(b == 0) return a ; 
    return gcd(b,a%b) ;
}

int main(){
    cin >> n ;
    ll res = 0 ;
    rep(i,n) {
        ll a ;
        cin >> a ;
        res = gcd(a,res) ;
    }
    for(ll i = 2 ; i * i <= res ; i++){
        if(res % i != 0) continue ;
        int ex = 0 ;
        while(res % i == 0){
            ex++ ;
            res /= i ;
        }
        vec.push_back(P(i,ex+1)) ;
    }
    if(res != 1) vec.push_back(P(res,2)) ;
    ll ans = 1 ;
    rep(i,vec.size()) ans *= vec[i].second ;
    cout << ans << endl ;
}