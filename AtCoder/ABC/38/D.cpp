#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n ;
set<int> st ;
map<int,vector<int>> mp ;
int dp[101010] ;

int main(){
    cin >> n ;
    rep(i,n){
        int h , w ;
        cin >> h >> w ;
        st.insert(w) ;
        mp[w].push_back(h) ;
    }
    for(int u : st) sort(mp[u].begin(),mp[u].end(),greater<int>()) ;
    rep(i,n) dp[i] = 1e9 ;
    for(int u : st){
        for(int v : mp[u]){
            auto it = lower_bound(dp,dp+n,v) ;
            int id = it - dp ;
            dp[id] = v ;
        }
    }
    int res = 0 ;
    rep(i,n){
        if(dp[i] == 1e9) break ;
        res++ ;
    }
    cout << res << endl ;
}