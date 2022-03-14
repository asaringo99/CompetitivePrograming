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

int Euclid(int a , int b , int &x , int &y){
  int d = a ;
  if(b == 0){
    x = 1 ;
    y = 0 ;
  }
  else{
    d = Euclid(b , a % b , y , x) ;
    cout << x << " " << y << endl ;
    y -= (a / b) * x ;
  }
  return d ;
}

int main(){
  int a , b , x , y ;
  cin >> a >> b ;
  cout << Euclid(a,b,x,y) << endl ;
  cout << x << " " << y << endl ;
}