#include <bits/stdc++.h>
using namespace std ;
using ll = long long ;
#define M (ll)1e9+7

int n ;
char s[M] , t[M] ;

bool solve(int i , int j){
  if(j - i <= 0) return true ;
  if(s[i] == s[j]) return solve(i+1,j-1) ;
  return s[i] < s[j] ;
}

int main(){
  cin >> n >> s ;
  int i = 0 , j = n - 1 , ind = 0 ;
  while(i <= j){
    if(s[i] < s[j]){
      t[ind] = s[i] ;
      i++ ;
    }
    else if(s[i] > s[j]){
      t[ind] = s[j] ;
      j-- ;
    }
    else{
      if(solve(i+1,j-1)){
        t[ind] = s[i] ;
        i++ ;
      }
      else{
        t[ind] = s[j] ;
        j-- ;
      }
    }
    ind++ ;
  }
  for(int i = 0 ; i < n ; i++) cout << t[i] ;
  cout << endl ;
}