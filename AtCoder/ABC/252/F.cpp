#include <bits/stdc++.h>
using namespace std ;
#define fast_input_output ios::sync_with_stdio(false); cin.tie(nullptr);
typedef unsigned long long ll ;
typedef long double ld ;
typedef pair<ll,ll> P ;
typedef tuple<ll,ll,ll> TP ;
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define bit_count(x) __builtin_popcountll(x)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a / gcd(a,b) * b
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

int n ;
ll L ;
ll A[202020] ;
priority_queue<ll,vector<ll>,greater<ll>> que ;

int main(){
    fast_input_output
    cin >> n >> L ;
    ll sum = 0 ;
    rep(i,n) {
        ll a ;
        cin >> a ;
        que.push(a) ;
        sum += a ;
    }
    ll res = 0 ;
    if(sum != L) que.push(L-sum) ;
    while(que.size() > 1){
        ll top1 = que.top() ; que.pop() ;
        ll top2 = que.top() ; que.pop() ;
        res += top1 + top2 ;
        que.push(top1+top2) ;
    }
    cout << res << endl ;
}