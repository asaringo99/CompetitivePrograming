#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define YES cout << "Yes" << endl 
#define NO cout << "No" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)
#define a_z "abcdefghijklmnopqrstuvwxyz"

int n , m ;

int main(){
    cin >> n >> m ;
    vector<int> S[m] ;
    for(int i = 0 ; i < m ; i++){
        int k ;
        cin >> k ;
        for(int j = 0 ; j < k ; j++) {
            int p ;
            cin >> p ;
            p-- ;
            S[i].push_back(p) ;
        }
    }
    int P[m] ;
    for(int i = 0 ; i < m ; i++) cin >> P[i] ;
    int res = 0 ;
    for(int i = 0 ; i < (1 << n) ; i++){
        set<int> st ;
        for(int j = 0 ; j < n ; j++){
            if(i >> j & 1) st.insert(j) ;
        }
        bool ok = true ;
        for(int j = 0 ; j < m ; j++){
            int count = 0 ;
            for(int k = 0 ; k < S[j].size() ; k++){
                if(st.count(S[j][k]) == 1) count++ ;
            }
            if(count % 2 != P[j]) ok = false ;
        }
        if(ok) res++ ;
    }
    cout << res << endl ;
}