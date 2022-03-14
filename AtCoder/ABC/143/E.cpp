#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<int,int> P ;
typedef tuple<int,int,int> TP ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

const ll MAX_N = 300 ;
const ll INF = 1e18 ;

ll d[MAX_N][MAX_N] ;
int N , M , L ;

void warshall_floyd(){
    for(int k = 0 ; k < N ; k++)
        for(int i = 0 ; i < N ; i++)
            for(int j = 0 ; j < N ; j++) d[i][j] = min(d[i][j] , d[i][k] + d[k][j]) <= L ? min(d[i][j] , d[i][k] + d[k][j]) : INF ;
}

int main(){
    cin >> N >> M >> L ; 
    for(int i = 0 ; i < N ; i++) fill(d[i],d[i]+N,INF) ;
    for(int i = 0 ; i < M ; i++){
        int A , B , C ;
        cin >> A >> B >> C ;
        A-- ; B-- ;
        d[A][B] = C ;
        d[B][A] = C ;
    }
    warshall_floyd() ;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            //cout << i << " " << j << " " << d[i][j] << endl ;
            if(d[i][j] != INF) d[i][j] = 1 ; 
            if(i == j) d[i][j] = 0 ;
        }
    }
    warshall_floyd() ;
    int Q ; 
    cin >> Q ;
    vector<ll> res ;
    for(int i = 0 ; i < Q ; i++){
        int s , t ; 
        cin >> s >> t ;
        s-- ; t-- ;
        ll ans = d[s][t] ;
        if(ans == INF) ans = -1 ;
        else ans -= 1 ;
        res.push_back(ans) ;
    }
    for(ll u : res) cout << u << endl ;
}