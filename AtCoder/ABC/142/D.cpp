#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<int,int> P ;
typedef tuple<int,int,int> TP ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

ll a , b ;
set<ll> sa , sb ;

int main(){
    cin >> a >> b ;
    for(ll i = 2 ; i * i <= a ; i++){
        while(a % i == 0){
            a /= i ;
            sa.insert(i) ;
        }
    }
    if(a != 1) sa.insert(a) ;

    for(ll i = 2 ; i * i <= b ; i++){
        while(b % i == 0){
            b /= i ;
            sb.insert(i) ;
        }
    }
    if(b != 1) sb.insert(b) ;
    ll sum = 0 ;
    for(ll a : sa) if(sb.count(a)) sum++ ;
    cout << sum + 1 << endl ;
}