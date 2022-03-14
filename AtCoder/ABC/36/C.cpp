#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n ;
vector<int> vec ;

vector<int> f(vector<int> x){
    vector<int> y = x , res ;
    sort(x.begin(),x.end()) ;
    rep(i,n){
        auto it = lower_bound(x.begin(),x.end(),y[i]) ;
        
    }
}

int main(){
    cin >> n ;
    rep(i,n){
        int a ;
        cin >> a ;
        vec.push_back(a) ;
    }
}