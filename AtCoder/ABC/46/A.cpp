#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int a , b , c ;

int main(){
    cin >> a >> b >> c ;
    set<int> st ;
    st.insert(a) ;
    st.insert(b) ;
    st.insert(c) ;
    cout << st.size() << endl ;
}