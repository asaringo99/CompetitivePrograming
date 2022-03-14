#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> P ;
#define MAX_N 3000
#define YES cout << "Yes" << endl 
#define NO cout << "No" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)
#define a_z "abcdefghijklmnopqrstuvwxyz"

int N , T ;

int main(){
    cin >> N >> T ;
    int A[N] , B[N] ;
    rep(i,N) cin >> A[i] >> B[i] ;
    int dp1[N+1][T] , dp2[N+1][T] ;
    memset(dp1,0,sizeof(dp1)) ;
    memset(dp2,0,sizeof(dp2)) ;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < T ; j++){
            //dp1
            dp1[i+1][j] = max(dp1[i+1][j],dp1[i][j]) ;
            if(j + A[i] > T) continue ;
            dp1[i+1][j + A[i]] = max(dp1[i+1][j + A[i]],dp1[i][j] + B[i] ) ;
            dp1[i+1][j + A[i]] = max(dp1[i+1][j + A[i]],dp1[i][j + A[i]]) ;
            //dp2
            dp2[i+1][j] = max(dp2[i+1][j],dp2[i][j]) ;
            if(j + A[N - 1 - i] > T) continue ;
            dp2[i+1][j + A[N - 1 - i]] = max(dp2[i+1][j + A[N - 1 - i]],dp2[i][j] + B[N - 1 - i] ) ;
            dp2[i+1][j + A[N - 1 - i]] = max(dp2[i+1][j + A[N - 1 - i]],dp2[i][j + A[N - 1 - i]]) ;
        }
    }
    for(int i = 0 ; i < N ; i++){
        
    }
}