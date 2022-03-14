#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,int> P ;
#define MAX_N (ll)1e5
#define YES cout << "Yes" << endl 
#define NO cout << "No" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)
#define a_z "abcdefghijklmnopqrstuvwxyz"
#define A_Z "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

int n ;

int main(){
    cin >> n ;
    map<int,int> rem ;
    for(int i = 0 ; i < n ; i++){
        int a ;
        cin >> a ;
        rem[a-1]++ ;
        rem[a]++ ;
        rem[a+1]++ ;
    }
    int res = 0 ;
    for(int i = -1 ; i <= 1e5+7 ; i++){
        res = max(res,rem[i]) ;
    }
    cout << res << endl ;
}