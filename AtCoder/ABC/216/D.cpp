#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define MAX_E 200
#define MAX_V 100
#define INF 1000000

int n , m ;
vector<int> G[202020] ;

struct edge{
    int from , to , cost ;
} ;

edge es[MAX_E] ;
ll d[MAX_V] ;

class tsort {
public:
	int V;
	vector<vector<int> > G;
	vector<int> deg,res;
	tsort(int node_size) : V(node_size), G(V), deg(V, 0){}
	void add_edge(int from,int to){
		G[from].push_back(to);
		deg[to]++;
	}
	bool solve() {
		queue<int> que;
		for(int i = 0; i < V; i++){
			if(deg[i] == 0){
				que.push(i);
			}
		}
		while(!que.empty()){
			int p = que.front();
			que.pop();
			res.push_back(p);
			for(int v : G[p]){
				if(--deg[v] == 0){
					que.push(v);
				}
			}
		}
		return (*max_element(deg.begin(),deg.end()) == 0);
	}
};

int main(){
    cin >> n >> m ;
    tsort TS(n) ;
    rep(i,m){
        int k ;
        cin >> k ;
        vector<int> vec ;
        rep(j,k){
            int a ;
            cin >> a ;
            a-- ;
            vec.push_back(a) ;
        }
        rep(j,vec.size()-1) TS.add_edge(vec[j],vec[j+1]) ;
    }
    if(TS.solve()) cout << "Yes" << endl ;
    else cout << "No" << endl ;
}