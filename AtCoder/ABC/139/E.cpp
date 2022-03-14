#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<int,int> P ;
typedef tuple<int,int,int> TP ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

int n ;
vector<int> G[1010101] ;
unordered_map<int,int> cnt ;
int A[1010][1010] ;
set<int> st , check ;

int main(){
    cin >> n ;
    rep(i,n) rep(j,n-1) cin >> A[i][j] , A[i][j]-- ;
    rep(i,n) rep(j,n-2){
        int u = min(i,A[i][j]) * n + max(i,A[i][j]) ;
        int v = min(i,A[i][j+1]) * n + max(i,A[i][j+1]) ;
        cnt[v]++ ;
        G[u].push_back(v) ;
        st.insert(u) ;
        st.insert(v) ;
        check.insert(u) ;
        check.insert(v) ;
    }
    vector<int> ord ;
    for(int u : st) if(cnt[u] == 0) ord.push_back(u) ;
    int res = 0 ;
    while(true){
        if(ord.size() == 0) break ;
        set<int> tmp ;
        for(int u : ord){
            for(int v : G[u]){
                cnt[v]-- ;
                if(cnt[v] == 0) tmp.insert(v) ;
            }
            check.erase(u) ;
        }
        ord = {} ;
        for(int u : tmp) ord.push_back(u) ;
        res++ ;
    }
    if(check.empty()) cout << res << endl ;
    else cout << -1 << endl ;
}