#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> P ;
typedef tuple<int,int,int> TP ;
#define MAX_N (ll)2e5
#define YES cout << "Yes" << endl 
#define NO cout << "No" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)
#define a_z "abcdefghijklmnopqrstuvwxyz"
#define A_Z "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

int n , m ;
string zero[6] = {"","0","00","000","0000","00000"} ;
set<int> S ;
map<int,vector<P>> rem ;

int main(){
    cin >> n >> m ;
    for(int i = 0 ; i < m ; i++){
        int p , y ;
        cin >> p >> y ;
        S.insert(p) ;
        rem[p].push_back(P(y,i)) ;
    }
    P res[m] ;
    for(int u : S){
        // string pre = to_string(u) ;
        // pre = zero[5 - pre.size()] + pre ;
        sort(rem[u].begin(),rem[u].end()) ;
        int count = 0 ;
        for(P p : rem[u]){
            count++ ;
            // string cit = to_string(count) ;
            // cit = zero[5 - cit.size()] + cit ;
            // res[p.second] = pre + cit ;
            res[p.second] = P(u,count) ;
        }
    }
    for(int i = 0 ; i < m ; i++){
        string pre = to_string(res[i].first) , cit = to_string(res[i].second) ;
        pre = zero[6 - pre.size()] + pre ;
        cit = zero[6 - cit.size()] + cit ;
        cout << pre + cit << endl ;
    }
}