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
#define INF 1000007

int p ;
int a[INF] ;
map<int,int> book , book2;

int solve(){
  int count = 0 , res = p ;
  int kind = book.size() ;
  int s = 0 ;
  for(int t = 0 ; t < p ; t++){
    book2[a[t]]++ ;
    if(book2[a[t]] == 1) count++ ;
    cout << count << endl ;
    while(count == kind){
      res = min(res,t-s+1) ;
      book2[a[s]]-- ;
      if(book2[a[s]] == 0) count-- ;
      s++ ; 
    }
  }
  return res ;
}

int main(){
  cin >> p ;
  for(int i = 0 ; i < p ; i++){
    cin >> a[i] ;
    book[a[i]]++ ;
  }
  cout << solve() << endl ;
}