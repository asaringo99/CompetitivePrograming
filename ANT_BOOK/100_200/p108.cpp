#include <bits/stdc++.h>
using namespace std ;
using V_2 = vector<vector<int>> ;
using Gragh = vector<vector<char>> ;
using P = pair<int,int> ;
using ll = long long ;
using que = queue<P> ;
using pque = priority_queue<int> ;
using rpque = priority_queue<int,vector<int>,greater<int>> ;
#define MAX_N 5000
#define INFO 1000000

int Euclid(int a , int b){
  if(b == 0) return a ;
  else return Euclid(b , a % b) ;
}

int main(){
  int a , b ;
  cin >> a >> b ;
  cout << Euclid(a,b) << endl ;
}