#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define MAX_N (ll)1e9

int n , m , k ;

int main(){
    cin >> n >> m ;
    int A[m] , B[m] ;
    for(int i = 0 ; i < m ; i++){
        int a , b ;
        cin >> a >> b ;
        a-- ; b-- ;
        A[i] = a ;
        B[i] = b ;
    }
    cin >> k ;
    int C[n] , D[n] ;
    for(int i = 0 ; i < k ; i++){
        int c , d ;
        cin >> c >> d ;
        c-- ; d-- ;
        C[i] = c ;
        D[i] = d ;
    }

    int res = 0 ;
    for(int i = 0 ; i < (1 << k) ; i++){
        int count = 0 ;
        bool ball[n] ;
        fill(ball,ball+n,false) ;
        for(int j = 0 ; j < k ; j++){
            if(i >> j & 1) ball[C[j]] = true ;
            else ball[D[j]] = true ;
        }
        for(int j = 0 ; j < m ; j++){
            if(ball[A[j]] && ball[B[j]]) count++ ;
        }
        res = max(res,count) ;
    }
    cout << res << endl ;
}