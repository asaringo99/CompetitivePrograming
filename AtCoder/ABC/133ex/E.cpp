#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)

const int MAX_N = 100007 ;
const int mod = 1000000007 ;

ll pes[MAX_N+1] ; // (n!)^(p-2) (mod p) を格納
ll tes[MAX_N+1] ; // (n!) (mod p) を格納

// 逆元(1/n)のmod計算
ll invmodcal(ll A , ll N){
    ll res = 1 ;
    while(N > 0){
        if(N & 1) res = (res * A) % mod ;
        A = (A * A) % mod ;
        N >>= 1 ;
    }
    return res % mod ;
}

// 階乗の逆元(n!)^(-1)のmodを配列に格納
void invmod(){
    pes[0] = 1 ; pes[1] = 1 ;
    for(ll i = 2 ; i <= MAX_N ; i++){
        pes[i] = invmodcal(i,mod-2) * pes[i-1] % mod ;
    }
}

// 階乗のmodを配列に格納
void powmod(){
    tes[0] = 1 ; tes[1] = 1 ;
    for(ll i = 2 ; i <= MAX_N ; i++){
        tes[i] = (tes[i-1] * i) % mod ;
    }
}

ll permutation(ll a , ll b){
    return (tes[a] * pes[a - b]) % mod ;
}

ll n , k ;
vector<int> G[MAX_N] ;
bool d[MAX_N] ;

ll bfs(){
    invmod() ;
    powmod() ;
    memset(d,0,sizeof(d)) ;
    d[0] = true ;
    queue<int> que ;
    que.push(0) ;
    ll val = k ;
    bool ok = true ;
    while(!que.empty()){
        int v = que.front() ; que.pop() ;
        d[v] = true ;
        if(ok) {
            if(k - 1 < G[v].size()) return 0 ;
            (val *= permutation(k - 1 , G[v].size())) %= mod ;
            ok = false ;
        }
        else{
            if(k - 2 < G[v].size() - 1) return 0 ;
            (val *= permutation(k - 2 , G[v].size() - 1)) %= mod ;
        }
        for(int i = 0 ; i < G[v].size() ; i++){
            int u = G[v][i] ;
            if(!d[u]){
                que.push(u) ;
            }
        }
    }
    return val ;
}

int main(){
    cin >> n >> k ;
    for(int i = 0 ; i < n - 1 ; i++){
        int a , b ;
        cin >> a >> b ;
        a-- ;
        b-- ;
        G[a].push_back(b) ;
        G[b].push_back(a) ;
    }
    cout << bfs() << endl ;
}