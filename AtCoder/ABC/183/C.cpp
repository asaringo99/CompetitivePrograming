#include <bits/stdc++.h>
using namespace std ;
using V_2 = vector<vector<int>> ;
using ll = long long ;
#define INF 10007

int n ;
ll k ;
ll T[INF][INF] ;

int kaijo(int t){
  if(t == 0) return 1 ;
  return t * kaijo(t - 1) ;
}

int main() {
    cin >> n >> k ;
    for(int i = 0 ; i < n ; i++){
      for(int j = 0 ; j < n ; j++){
        cin >> T[i][j] ;
      }
    }
    vector<int> v(n);
    int i = 1 ;
    int count = 0 ;
    int pr = 0 ;
    ll point = 0 ;
    int ans = 0 ;
    iota(v.begin(), v.end(), 1);       // v に 1, 2, ... N を設定
    do {
      if(count == kaijo(n - 1) ) break ;
      int st = 0 ;
      point = 0 ;
        for(auto x : v){
          pr++ ;
          if(x == 1) continue ;
          point += T[st][x - 1] ;
          //cout << point << " " << st << " " << x - 1 << endl ;
          st = x - 1 ;
          if(pr == n){
            point += T[st][0] ;
            //cout << point << " " << st << " " << 0 << endl ;
            pr = 0 ;
            if(point == k) ans++ ;
            break ;
          }
        }
        count++ ;
    } while( next_permutation(v.begin(), v.end()));     // 次の順列を生成
    cout << ans << endl ;
}