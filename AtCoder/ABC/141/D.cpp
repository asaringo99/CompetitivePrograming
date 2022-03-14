#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<int,int> P ;
typedef tuple<int,int,int> TP ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

int n , m ;
ll A[101010] ;
priority_queue<ll> que ;

int main(){
    cin >> n >> m ;
    rep(i,n) {
        ll a ;
        cin >> a ;
        que.push(a) ;
    }
    rep(i,m){
        ll top = que.top() ; que.pop() ;
        que.push(top / 2) ;
    }
    ll res = 0 ;
    while(!que.empty()){
        res += que.top() ; que.pop() ;
    }
    cout << res << endl ;
}