#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
ll n , z , w ;
ll A[2020] ;
int main(){
    cin >> n >> z >> w ;
    rep(i,n) cin >> A[i] ;
    if(n == 1) cout << abs(A[0] - w) << endl ;
    else cout << max(abs(A[n-1]-w),abs(A[n-2]-A[n-1])) << endl ;
}