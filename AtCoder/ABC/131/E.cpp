#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n , k ;
vector<P> vec ;

int main(){
    cin >> n >> k ;
    int sum = n - 1 , res = (n - 2) * (n - 1) / 2 ;
    if(k > res){
        cout << -1 << endl ;
        return 0 ;
    }
    rrep(i,2,n+1) vec.push_back(P(1,i))  ;
    rrep(i,2,n+1) rrep(j,i+1,n+1){
        if(res == k) break ;
        vec.push_back(P(i,j)) ;
        res-- ;
    }
    cout << vec.size() << endl ;
    rep(i,vec.size()) cout << vec[i].first << " " << vec[i].second << endl ;
}