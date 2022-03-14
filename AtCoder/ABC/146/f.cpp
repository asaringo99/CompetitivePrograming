#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<int,int> P ;
typedef tuple<int,int,int> TP ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

int n , m ;
string S ;
vector<int> vec ;
set<int> st ;

int main(){
    cin >> n >> m >> S ;
    reverse(S.begin(),S.end()) ;
    int i = 0 ;
    while(i <= n){
        int v = i ;
        i += m ;
        if(i >= n){
            vec.push_back(n - v) ;
            break ;
        }
        while(S[i] == '1') i-- ;
        if(i == v){
            cout << -1 << endl ;
            return 0 ;
        }
        vec.push_back(i - v) ;
    }
    reverse(vec.begin(),vec.end()) ;
    for(int u : vec) cout << u << " " ;
    cout << endl ;
}