#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define MAX_N (ll)2e5
#define YES cout << "Yes" << endl 
#define NO cout << "No" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)
#define a_z "abcdefghijklmnopqrstuvwxyz"
#define A_Z "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

int n , k ;

int main(){
    cin >> n >> k ;
    map<int,int> rem ;
    set<int> st ;
    for(int i = 0 ; i < n ; i++){
        int a ; 
        cin >> a ;
        rem[a]++ ;
        st.insert(a) ;
    }
    vector<int> vec ;
    for(int u : st) vec.push_back(rem[u]) ;
    sort(vec.begin(),vec.end(),greater<int>()) ;
    int res = 0 ;
    for(int i = k ; i < vec.size() ; i++) res += vec[i] ;
    cout << res << endl ;
}