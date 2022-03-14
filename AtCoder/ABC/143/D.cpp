#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define INF (ll)1e12

int n ;

int main(){
    cin >> n ;
    vector<int> L(n) ;
    for(int i = 0 ; i < n ; i++){
        cin >> L[i] ;
    }
    sort(L.begin(),L.end()) ;
    int res = 0 ;
    for(int i = 0 ; i < n ; i++){
        for(int j = i + 1 ; j < n ; j++){
            int tri = L[i] + L[j] ;
            auto it = lower_bound(L.begin() , L.end() , tri) ;
            if(it - L.begin() - 1 == j) continue ;
            int siz = (it - L.begin() - 1) ;
            res += siz - j ;
        }
    }
    cout << res << endl ;
}