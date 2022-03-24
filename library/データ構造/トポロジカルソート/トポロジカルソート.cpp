#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<ll,ll> P ;
typedef tuple<ll,ll,ll> TP ;
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define bit_count(x) __builtin_popcountll(x)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a / gcd(a,b) * b
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

template<typename T> struct TpologicalSort{
    int n ; // ノード数
    vector<T> order ; // トポロジカルソート後のノードの並び
    vector<T> start ; // 始点ノード
    vector<T> end ; // 終点ノード

    // コンストラクタ
    TpologicalSort(int n_ , vector<int> *G){
        n = n_ ;
        build(G) ;
    }
    // トポロジカルソートを実施
    void build(vector<int> *G){
        vector<T> in(n,0) ;
        queue<int> que ;
        for(int i = 0 ; i < n ; i++){
            for(int u : G[i]) in[u]++ ;
        }
        for(int i = 0 ; i < n ; i++) if(in[i] == 0) {
            que.push(i) ;
            start.push_back(i) ;
        }
        while(!que.empty()){
            int v = que.front() ; que.pop() ;
            order.push_back(v) ;
            if(G[v].empty()) end.push_back(v) ;
            for(int u : G[v]) {
                in[u]-- ;
                if(in[u] == 0) que.push(u) ;
            }
        }
    }
    // 閉路判定: true: 閉路あり, false: 閉路なし, O(1)
    bool hasCycle(){
        int m = order.size() ;
        if(n != m) return true ;
        return false ;
    }
    vector<T> getStartNode() {return start ; }
    vector<T> getEndNode() {return end ; }
    inline int operator [] (int i) { return order[i] ; }
};