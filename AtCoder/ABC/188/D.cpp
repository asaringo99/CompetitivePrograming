#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> P ;
#define M 100005

int N , C ;

int main(){
    cin >> N >> C ;
    vector<P> tim ;
    for(int i = 0 ; i < N ; i++){
        ll a , b , c ;
        cin >> a >> b >> c ;
        tim.push_back(P(a,c)) ;
        tim.push_back(P(b+1,-c)) ;
    }
    sort(tim.begin(),tim.end()) ;
    ll start = 0 , mon = 0 , ans = 0 ;
    for(int i = 0 ; i < tim.size() ; i++){
        ll fin = tim[i].first ;
        if(mon > C) ans += C * (fin - start) ;
        else ans += mon * (fin - start) ;
        mon += tim[i].second ;
        start = fin ;
    }
    cout << ans << endl ;
}