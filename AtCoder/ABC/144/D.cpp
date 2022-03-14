#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define MAX_N (ll)2e5
#define YES cout << "Yes" << endl 
#define NO cout << "No" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)

double a , b , x ;

int main(){
    cin >> a >> b >> x ;
    if(a * a * b < 2 * x) cout << setprecision(10) << atan2(2 * a * a * b - 2 * x , a * a * a) * 180 / M_PI << endl ;
    else cout << syosu << atan2(a * b * b , 2 * x) * 180 / M_PI << endl ;
}
