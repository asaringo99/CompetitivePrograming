#include <bits/stdc++.h>
using namespace std ;
using ll = long long ;
#define M 100005

int n , k ;
int a[M] ;
bool ok = false ;

queue<pair<int,int>> Q ;

void bfs(int s){
  pair<int,int> P = Q.front() ;
  Q.pop() ;
  int dep = P.first , cnt = P.second ;
  if(dep == n && cnt == k) ok = true ;
  for(bool u : {true,false}){
    pair<int,int> pir ;
    if(u) pir = {dep += 1 , cnt += a[dep]} ;
    else pir = {dep += 1 , cnt} ;
    Q.push(pir) ;
  }
}

int main(){
  cin >> n ;
  for(int i = 0 ; i < n ; i++) cin >> a[i] ;

}