#include <bits/stdc++.h>
using namespace std ;
using V_2 = vector<vector<int>> ;
using ll = long long ;
#define M 100005
#define H 2005
#define W 2005

int h , w ;
char S[H][W] ;
int var[H][W] ;
int hor[H][W] ;

void dfshor(int p , int q , int &count){
  count++ ;
  if(S[p][q+1] != '#' && q + 1 < w){
    dfshor(p,q+1,count) ;
  }
  hor[p][q] = count ;
  cout << p << " " << q << " " << hor[p][q] << endl ;
}

void dfsvar(int p , int q , int &count){
  count++ ;
  if(S[p+1][q] != '#' && p + 1 < h){
    dfsvar(p+1,q,count) ;
  }
  hor[p][q] = count ;
}

int main(){
  cin >> h >> w ;
  for(int i = 0 ; i < h ; i++){
    for(int j = 0 ; j < w ; j++){
      cin >> S[i][j] ;
    }
  }

  for(int i = 0 ; i < h ; i++){
    for(int j = 0 ; j < w ; j++){
        hor[i][j] = 0 ;
        var[i][j] = 0 ;
    }
  }

  for(int i = 0 ; i < h ; i++){
    for(int j = 0 ; j < w ; j++){
      if(S[i][j] == '.'){
        int count = 0 ;
        if(hor[i][j] == 0) dfshor(i,j,count) ;
        if(var[i][j] == 0) dfsvar(i,j,count) ;
      }
    }
  }

  int res = 0 ;

  for(int i = 0 ; i < h ; i++){
    for(int j = 0 ; j < w ; j++){
      res = max(res,hor[i][j]+var[i][j]) ;
    }
  }

  cout << res << endl ;
}