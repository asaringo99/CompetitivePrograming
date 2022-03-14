#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int x , y , a , b , c ;
ll p[101010] , q[101010] , r[101010] ;

int main(){
    cin >> x >> y >> a >> b >> c ;
    rep(i,a) cin >> p[i] ;
    rep(i,b) cin >> q[i] ;
    rep(i,c) cin >> r[i] ;
    sort(p,p+a,greater<ll>()) ;
    sort(q,q+b,greater<ll>()) ;
    sort(r,r+c,greater<ll>()) ;
    priority_queue<ll> que ;
    rep(i,x) que.push(p[i]) ;
    rep(i,y) que.push(q[i]) ;
    rep(i,c) que.push(r[i]) ;
    ll res = 0 , count = 0 ;
    while(count < x + y){
        res += que.top() ; que.pop() ;
        count++ ;
    }
    cout << res << endl ;
}