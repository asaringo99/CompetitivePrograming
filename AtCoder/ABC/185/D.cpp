#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define YES cout << "Yes" << endl 
#define NO cout << "No" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)
#define MAX_N (ll)2e5

int n , m ;

int main(){
    cin >> n >> m ;
    int tmp = n ;
    int front = 0 ;
    vector<int> res ;
    int A[m] ;
    for(int i = 0 ; i < m ; i++) cin >> A[i] ;
    sort(A,A+m) ;
    for(int i = 0 ; i < m + 1 ; i++){
        int magin ;
        if(i == m) magin = n - front ;
        else magin = A[i] - front - 1 ;
        
        if(magin > 0){
            tmp = min(tmp,magin) ;
            res.push_back(magin) ;
        }
        front = A[i] ;
    }
    ll ans = 0 ;
    for(int magin : res){
        if(magin % tmp == 0) ans += magin / tmp ;
        else ans += magin / tmp + 1 ;
    }
    cout << ans << endl ;
}