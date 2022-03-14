#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n , m ;

int main(){
    cin >> n >> m ;
    if(!(n&1)){
        int i = 1 , j = n , cnt = 0 ;
        set<int> st ;
        while(cnt < m){
            if(st.count(j - i) == 1 || st.count(i + n - j) == 1 || i + n / 2 == j) j-- ;
            st.insert(j-i) ;
            st.insert(i-j+n) ;
            cout << i << " " << j << endl ;
            i++ ;
            j-- ;
            cnt++ ;
        }
    }
    else{
        int i = 1 , j = n - 1 , cnt = 0 ;
        while(cnt < m){
            cout << i << " " << j << endl ;
            i++ ;
            j-- ;
            cnt++ ;
        }
    }
}