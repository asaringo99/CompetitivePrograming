#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define MAX_N (ll)1e5
#define YES cout << "Yes" << endl 
#define NO cout << "No" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)
#define a_z "abcdefghijklmnopqrstuvwxyz"
#define A_Z "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

int n , m ;

int par[MAX_N] ; //親
int lank[MAX_N] ; //木の深さ

//n要素で初期化

void init(int n) {
    for(int i = 0 ; i < n ; i++){
        par[i] = i ;
        lank[i] = 0 ;
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
    } else {
        par[y] = x ;
        if(lank[x] == lank[y]) lank[x]++ ;
    }
}

bool same(int x , int y){
    return find(x) == find(y) ;
}

int main(){
    cin >> n >> m ;
    int p[n] ;
    for(int i = 0 ; i < n ; i++){
        int P ;
        cin >> P ; 
        P-- ;
        p[i] = P ;
    }
    init(n) ;
    for(int i = 0 ; i < m ; i++){
        int x , y ;
        cin >> x >> y ;
        x-- ;
        y-- ;
        unite(x,y) ;
    }
    int res = 0 ;
    for(int i = 0 ; i < n ; i++){
        if(same(p[i],i)) res++ ;
    }
    cout << res << endl ;
}