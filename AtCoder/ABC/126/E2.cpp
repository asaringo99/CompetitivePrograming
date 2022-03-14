#include<bits/stdc++.h>
using namespace std ;
using ll = long long ;
#define MAX_N (ll)1e8

int n , m ;

int par[MAX_N] ; //親
int lank[MAX_N] ; //木の深さ

//n要素で初期化

void init(int n) {
  for(int i = 0 ; i < n ; i++){
    par[i] = i ;
    lank[i] = 0 ;
  }
}

//木の根を求める
int find(int x){
  if(par[x] == x){
    return x ;
  } else{
    return par[x] = find(par[x]) ;
  }
}

//xとyの属する集合を合併
void unite(int x , int y){
  x = find(x) ;
  y = find(y) ;
  if(x == y) return ;

  if(lank[x] < lank[y]){
    par[x] = y ;
  } else {
    par[y] = x ;
    if(lank[x] == lank[y]) lank[x]++ ;
  }
}

bool same(int x , int y){
  return find(x) == find(y) ;
}

int main(){
  cin >> n >> m ;
  init(n) ;
  set<int> tmp ;
  int count = 0 ;
  for(int i = 0 ; i < m ; i++){
    int x , y , z ;
    cin >> x >> y >> z ;
    unite(x-1,y-1) ;
  }
  for(int i = 0 ; i < n ; i++){
    tmp.insert(find(i)) ;
  }
  cout << tmp.size() << endl ;
}