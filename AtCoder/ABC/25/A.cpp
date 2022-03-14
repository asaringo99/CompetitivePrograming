#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

string S ;
set<string> st ;
int n ;

int main(){
    cin >> S >> n ;
    rep(i,5) rep(j,5){
        string T = "" ;
        T += S[i] ;
        T += S[j] ;
        st.insert(T) ;
    }
    n-- ;
    while(n > 0){
        st.erase(st.begin()) ;
        n-- ;
    }
    cout << *st.begin() << endl ;
}