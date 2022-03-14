#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n ;
priority_queue<ll,vector<ll>,greater<ll>> que ;

int main(){
    cin >> n ;
    rrep(i,1,10) que.push(i) ;
    n-- ;
    while(n > 0){
        n-- ;
        ll val = que.top() ; que.pop() ;
        ll pls = val % 10 ;
        if(pls != 0) que.push(10 * val + pls - 1) ;
        if(pls != 9) que.push(10 * val + pls + 1) ;
        que.push(10*val+pls) ;
    }
    cout << que.top() << endl ;
}