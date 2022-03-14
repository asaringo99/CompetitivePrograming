#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define M 100005
#define YES cout << "Yes" << endl 
#define NO cout << "No" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)
#define inf (ll)1e15

int n , m ;

int main(){
    cin >> n >> m ;
    ll A[n] ;
    map<int,int> conf ;
    ll val = inf ;
    for(int i = 0 ; i < n ; i++){
        cin >> A[i] ;
        if(i < m) conf[A[i]]++ ;
    }
    for(ll i = 0 ; i <= n ; i++){
        if(conf[i] > 0) continue ;
        val = min(val,i) ;
    }

    int l = 0 , r = m - 1 ;
    while(r < n - 1){
        r++ ;
        conf[A[r]]++ ;
        if(conf[A[l]] == 1){
            val = min(val,A[l]) ;
        }
        conf[A[l]]-- ;
        l++ ;
    }
    cout << val << endl ;
}