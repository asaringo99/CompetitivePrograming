#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> P ;
#define MAX_N (ll)2e5
#define YES cout << "Yes" << endl 
#define NO cout << "No" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)
#define a_z "abcdefghijklmnopqrstuvwxyz"
#define A_Z "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

ll n , m ;

int par[MAX_N] ; //親
int lank[MAX_N] ; //木の深さ
ll siz[MAX_N] ; //木のサイズ

//n要素で初期化

void init(int n) {
    for(int i = 0 ; i < n ; i++){
        par[i] = i ;
        lank[i] = 0 ;
        siz[i] = 1 ;
    }
}

//木の根を求める
int find(int x){
    if(par[x] == x){
        return x ;
    } else{
        return par[x] = find(par[x]) ;
    }
}

//xとyの属する集合を合併
void unite(int x , int y){
    x = find(x) ;
    y = find(y) ;
    if(x == y) return ;

    if(lank[x] < lank[y]){
        par[x] = y ;
        siz[y] += siz[x] ;
    } else {
        par[y] = x ;
        if(lank[x] == lank[y]) lank[x]++ ;
        siz[x] += siz[y] ;
    }
}

bool same(int x , int y){
    return find(x) == find(y) ;
}

ll ufsize(int x){
    x = find(x) ;
    return siz[x] ;
}

int main(){
    cin >> n >> m ;
    init(n) ;
    P bridge[m] ;
    for(int i = 0 ; i < m ; i++){
        int a , b ;
        cin >> a >> b ;
        a-- ;
        b-- ;
        bridge[i] = P(a,b) ;
    }
    ll tmp = n * (n - 1) / 2 ;
    vector<ll> res ;
    for(int i = m - 1 ; i >= 0 ; i--){
        res.push_back(tmp) ;
        int a = bridge[i].first , b = bridge[i].second ;
        if(!same(a,b)) tmp -= ufsize(a) * ufsize(b) ;
        unite(a,b) ;
    }
    for(int i = res.size() - 1 ; i >= 0 ; i--) cout << res[i] << endl ;
}