#include <bits/stdc++.h>
using namespace std ;
using V_2 = vector<vector<int>> ;
using ll = long long ;
using P = pair<int,int> ;
#define MAX_N (ll)1e3

int h , w , m ;

int main(){
    cin >> h >> w >> m ;
    vector<int> H[h] , W[w] ;
    map<P,bool> rem ;
    for(int i = 0 ; i < m ; i++){
        int x , y ;
        cin >> x >> y ;
        x-- ;
        y-- ;
        H[x].push_back(y) ;
        W[y].push_back(x) ;
        rem[P(x,y)] = true ;
    }
    int res = 0 ;
    for(int i = 0 ; i < m ; i++){
        int x = H[i].size() , y = W[i].size() ;
        res = max(res,x+y-1) ;
    }
    cout << res << endl ;
}