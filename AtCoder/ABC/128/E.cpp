#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> P ;
#define INF (ll)1e12

int N , Q ;

int main(){
    cin >> N >> Q ;
    tuple<int,int,int> tp[N] ;

    for(int i = 0 ; i < N ; i++){
        int s , t , x ;
        cin >> s >> t >> x ;
        s -= x ; t -= x ;
        tp[i] = tie(x,s,t) ;
    }
    sort(tp,tp+N) ;
    set<P> D ;
    for(int i = 0 ; i < Q ; i++){
        int d ;
        cin >> d ;
        D.insert(P(d,i)) ;
    }

    int ans[Q] ;
    for(int i = 0 ; i < N ; i++){
        int x , s , t ;
        tie(x,s,t) = tp[i] ;
        P p(s,-1) ;
        auto it = D.lower_bound(p) ;
        while(it != D.end()){
            if(it->first >= t) break ;
            ans[it->second] = x ;
            D.erase(it++) ;
        }
    }
    for(auto it = D.begin() ; it != D.end() ; it++){
        ans[it->second] = -1 ;
    }
    for(int u : ans) cout << u << endl ;
}