#include <bits/stdc++.h>
using namespace std ;
using V_2 = vector<vector<int>> ;
using Gragh = vector<vector<char>> ;
using Pair = pair<int,int> ;
using ll = long long ;
using que = queue<Pair> ;
using pque = priority_queue<int> ;
using rpque = priority_queue<int,vector<int>,greater<int>> ;
#define N 105
#define INFO 100000005

int n , k ;
int a[20] ;

bool dfs(int d , int sum){
  if(d == n) return sum == k ;
  if(dfs(d + 1 , sum + a[d])) return true ;
  if(dfs(d + 1 , sum)) return true ;
  return false ;
}

int main(){
  cin >> n >> k ;
  for(int i = 0 ; i < n ; i++) cin >> a[i] ;
  if(dfs(0,0)) cout << "Yes" << endl ;
  else cout << "No" << endl ;
}