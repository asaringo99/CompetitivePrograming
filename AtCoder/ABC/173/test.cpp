#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define INF (ll)1e12
#define MAX_N 12
#define mod (ll)(1e9+7)

string S ;

int main(){
  cin >> S ;
  int N = S.size() ;
  vector<int> digit ;
  for(int i = 0 ; i < N ; i++) digit.push_back(S[i] - '0') ;

  // 3が含まれるか
  ll dp[N+1][2][2] ;
  memset(dp,0,sizeof(dp)) ;
  dp[0][0][0] = 1 ;
  //3段目までのfor文はi桁目（自分の状況を見ている）
  for(int i = 0 ; i < N ; i++){
    for(int smaller = 0 ; smaller < 2 ; smaller++){
      for(int k = 0 ; k < 2 ; k++){
        //4段目のfor文は次の桁(i+1桁)がどのような数字をとるかを考えている
        //smallerがtrueかfalseかでxの範囲を変える
        for(int x = 0 ; x <= (smaller ? 9 : digit[i]) ; x++){
          //2番目の要素は、i+1桁目でsmallerがtrueかfalseかを考える
          //3番目の要素は、i+1桁目で3を取得済みか否かを考える
          dp[ i + 1 ][ smaller || x < digit[i] ][ k || x == 3 ] += dp[i][smaller][k] ;
        }
      }
    }
  }
  cout << dp[N][0][1] + dp[N][1][1] << endl ;
  cout << dp[N][0][1] << endl ;
}