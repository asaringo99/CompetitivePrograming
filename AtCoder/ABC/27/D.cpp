#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

string S ;
int pls[101010] , mns[101010] ;
vector<int> res ;

int main(){
    cin >> S ;
    int n = S.size() ;
    int p = 0 , m = 0 ;
    rep(i,n){
        if(S[n-1-i] == '+') p++ ;
        if(S[n-1-i] == '-') m++ ;
        pls[n-1-i] = p ;
        mns[n-1-i] = m ;
    }
    rep(i,n) if(S[i] == 'M') res.push_back(pls[i]-mns[i]) ;
    sort(res.begin(),res.end()) ;
    ll sum = 0 ;
    rep(i,res.size()/2) sum -= res[i] ;
    rrep(i,res.size()/2,res.size()) sum += res[i] ;
    cout << sum << endl ;
}