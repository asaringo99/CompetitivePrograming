#include <bits/stdc++.h>
using namespace std ;
using V_2 = vector<vector<int>> ;
using ll = long long ;
#define M 100005

int A , B , C ;
const int X = 100 ;
double dp[101][101][101] ;

int main(){
    cin >> A >> B >> C ;
    memset(dp,0,sizeof(dp)) ;
    for(int i = X - 1 ; i >= 0 ; i--){
        for(int j = X - 1 ; j >= 0 ; j--){
            for(int k = X - 1 ; k >= 0 ; k--){
                if(i + j + k == 0) continue ;
                double tmp = 1 ;
                tmp += dp[i+1][j][k] * i / (i + j + k) ;
                tmp += dp[i][j+1][k] * j / (i + j + k) ;
                tmp += dp[i][j][k+1] * k / (i + j + k) ;
                dp[i][j][k] = tmp ;
            }
        }
    }
    cout << setprecision(15) << dp[A][B][C] << endl ;
}