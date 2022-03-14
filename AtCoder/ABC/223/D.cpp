#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

//グラフの隣接リスト
vector<int> g[202020];
//頂点の入次数を管理
int h[202020];

int main(){
    //頂点数v、辺の数e
    int v, e;
    cin >> v >> e;
    rep(i, e) {
        int s, t;
        cin >> s >> t;
        s-- ; t-- ;
        //頂点sから頂点tへの有向辺
        g[s].push_back(t);
        h[t]++;
    }

  //入次数が0の頂点の集合
    set<int> st;
    

    //入次数が0の頂点であればstに追加
    rep(i, v) if(h[i] == 0) st.insert(i);

    //ソートされた後のグラフ
    vector<int> ans;
    //stがなくなるまでループ
    while(st.size() != 0) {
        //stの集合のから一つ取り出す
        auto it = st.begin();
        int i = *it ;
        st.erase(it);
        ans.push_back(i+1);
        for(int j: g[i]) {
            //隣接する頂点の入次数をマイナス1
            h[j]--;
            //これによって入次数が0になればstに追加
            if(h[j] == 0) st.insert(j);
        }
    }

    //ansを順に出力
    if(ans.size() != v) {
        cout << -1 << endl ;
        return 0 ;
    }
    for(int i: ans) cout << i << " ";
    cout << endl ;
    return 0;
}