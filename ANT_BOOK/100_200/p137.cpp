#include <bits/stdc++.h>
using namespace std ;
using V_2 = vector<vector<int>> ;
using Gragh = vector<vector<char>> ;
using P = pair<int,int> ;
using ll = long long ;
using que = queue<P> ;
using pque = priority_queue<int> ;
using rpque = priority_queue<int,vector<int>,greater<int>> ;
#define MAX_N 65000
#define INF 10007

int n , S ;
int a[INF] ;

int solve(){
  int s = 0 , sum = 0 , res = n ;
  for(int t = 0 ; t < n ; t++){
    sum += a[t] ;
    while(sum > S){
      res = min(res,t-s) ;
      sum -= a[s] ;
      s++ ;
    }
  }
  return res ;
}

int main(){
  cin >> n >> S ;
  for(int i = 0 ; i < n ; i++){
    cin >> a[i] ;
  }
  cout << solve() << endl ;
}