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

int n , m , r ;

ll d[207][207] ;

void warshall_floyd(){
    for(int k = 0 ; k < n ; k++)
        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < n ; j++) d[i][j] = min(d[i][j] , d[i][k] + d[k][j]) ;
}

int main(){
    cin >> n >> m >> r ;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            if(i == j) d[i][j] = 0 ;
            else d[i][j] = 1e12 ;
        }
    }
    int R[r] ;
    for(int i = 0 ; i < r ; i++){
        cin >> R[i] ;
        R[i]-- ;
    }
    sort(R,R+r) ;
    for(int i = 0 ; i < m ; i++){
        int a , b , c ;
        cin >> a >> b >> c ;
        a-- ;
        b-- ;
        d[a][b] = c ;
        d[b][a] = c ;
    }
    warshall_floyd() ;
    ll res = LLONG_MAX ;
    do
    {
        ll tmp = 0 ;
        for(int i = 0 ; i < r - 1 ; i++){
            tmp += d[R[i]][R[i+1]] ;
        }
        res = min(tmp,res) ;
    } while (next_permutation(R,R+r));
    cout << res << endl ;
}