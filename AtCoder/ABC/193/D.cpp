#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define INF (ll)1e12

ll k ;
string S , T ;

int main(){
  cin >> k ;
  cin >> S >> T ;
  map<int,ll> pok ;
  int point_A[10] , point_B[10] ;
  memset(point_A,0,sizeof(point_A)) ;
  memset(point_B,0,sizeof(point_B)) ;
  for(int i = 1 ; i < 10 ; i++) pok[i] = k ;
  for(int i = 0 ; i < 4 ; i++){
    pok[S[i] - '0']-- ;
    point_A[S[i]-'0']++ ;
  }
  for(int i = 0 ; i < 4 ; i++){
    pok[T[i] - '0']-- ;
    point_B[T[i]-'0']++ ;
  }
  ll count = 0 ;
  ll sum = 0 ;
  for(int i = 1 ; i < 10 ; i++){
    if(pok[i] == 0) continue ;
    pok[i]-- ;
    point_A[i]++ ;
    ll p_a = 0 ;
    for(int j = 1 ; j < 10 ; j++){
      p_a += j * pow(10,point_A[j]) ;
    }
    for(int j = 1 ; j < 10 ; j++){
      if(pok[j] == 0) continue ;
      point_B[j]++ ;
      ll p_b = 0 ;
      for(int k = 1 ; k < 10 ; k++){
        p_b += k * pow(10,point_B[k]) ;
      }
      //cout << p_a << " " << p_b << endl ;
      if(p_a > p_b) count += pok[j] * (pok[i] + 1) ;
      sum += pok[j] * (pok[i] + 1) ;
      point_B[j]-- ;
    }
    pok[i]++ ;
    point_A[i]-- ;
  }
  cout << setprecision(10) << (double)count / sum << endl ;
}