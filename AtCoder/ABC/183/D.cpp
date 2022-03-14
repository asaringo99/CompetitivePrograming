#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,ll> P ;
#define M 100005
#define YES cout << "Yes" << endl 
#define NO cout << "No" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)
#define MAX_N (ll)2e5

int N ;
ll W ;

/*
int main(){
    cin >> N >> W ;

    ll pod[MAX_N + 2] ;
    memset(pod,0,sizeof(pod)) ;
    rep(i,N){
        int s , t ;
        ll p ;
        cin >> s >> t >> p ;
        pod[s] += p ;
        pod[t] -= p ;
    }
    ll sum = 0 ;
    bool ok = true ;
    for(int i = 0 ; i < MAX_N + 2 ; i++){
        sum += pod[i] ;
        if(sum > W) ok = false ;
    }
    if(ok) YES ;
    else NO ;
}
*/

int main(){
    cin >> N >> W ;
    vector<P> tim ;
    for(int i = 0 ; i < N ; i++){
        int s , t , p ;
        cin >> s >> t >> p ;
        tim.push_back(P(s,p)) ;
        tim.push_back(P(t,-p)) ;
    }
    sort(tim.begin(),tim.end()) ;
    ll simulation = 0 ;
    bool ok = true ;
    for(int i = 0 ; i < tim.size() ; i++){
        simulation += tim[i].second ;
        if(simulation > W) ok = false ;
    }
    if(ok) YES ;
    else NO ;
}