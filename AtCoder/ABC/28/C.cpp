#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int A[10] ;

int main(){
    rep(i,5) cin >> A[i] ;
    vector<int> vec ;
    rep(i,5) rrep(j,i+1,5) rrep(k,j+1,5) vec.push_back(A[i]+A[j]+A[k]) ;
    sort(vec.begin(),vec.end()) ;
    cout << vec[vec.size() - 3] << endl ;
}