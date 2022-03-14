#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

string S , T ;
vector<int> vec[26] ;

int main(){
    cin >> S >> T ;
    int n = S.size() , m = T.size() ;
    rep(i,n) vec[S[i] - 'a'].push_back(i) ;
    ll res = 0 , id = 0 ;
    rep(i,m){
        if(vec[T[i] - 'a'].size() == 0){
            cout << -1 << endl ;
            return 0 ;
        }
        auto it = lower_bound(vec[T[i]-'a'].begin(),vec[T[i]-'a'].end(),id) ;
        if(it != vec[T[i]-'a'].end()){
            id = *it;
            id++;
        }
        else{
            res += n ;
            id = 0 ;
            auto it = lower_bound(vec[T[i]-'a'].begin(),vec[T[i]-'a'].end(),id) ;
            id = *it;
            id++ ;
        }
    }
    cout << res + id << endl ;
}