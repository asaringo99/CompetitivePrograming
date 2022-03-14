#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define M 100005
#define YES cout << "Yes" << endl 
#define NO cout << "No" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)

double n ;

int main(){
    cin >> n ;
    double ans = 0 ;
    for(int i = 1 ; i <= n ; i++){
        ans += n / i ;
    }
    cout << setprecision(10) << ans - 1 << endl ;
}