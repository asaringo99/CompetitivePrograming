#include <bits/stdc++.h>
using namespace std ;
using V_2 = vector<vector<int>> ;
using ll = long long ;
#define M 100005
#define INF (ll) 1e8

int N ;

int main(){
  cin >> N ;
  int t[N] , v[N+1] ;
  int sum = 0 ;
  for(int i = 0 ; i < N ; i++){
    int s ;
    cin >> s ;
    sum += s ;
    t[i] = s ;
  }
  for(int i = 0 ; i < N ; i++) cin >> v[i] ;
  v[N] = 0 ;

  int fro = 0 ;
  double sqa = 0 ;
  for(int i = 1 ; i <= sum ; i++){
    int k ;
    int tim = 0 ;
    for(int j = 0 ; j < N ; j++){
      tim += t[j] ;
      if(i <= tim){
        k = j ;
        break ;
      }
    }
    int count = 0 ;
    int res = INF ;
    for(int j = 0 ; j < N ; j++){
      count += t[j] ;
      if(count < i) continue ;
      res = min(v[j + 1] + (count - i) , res) ;
    }
    res = min(res,min(fro+1,v[k])) ;

    if(res == fro) sqa += fro ;
    if(res > fro) sqa += fro + (double) 1 / 2 ;
    if(res < fro) sqa += fro - (double) 1 / 2 ;
    fro = res ;
    cout << i << " " << res << " " << fro << " " << count << " " << sqa << endl ;
  }
  cout << setprecision(15) << sqa << endl ;
}