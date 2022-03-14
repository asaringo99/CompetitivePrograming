#include <bits/stdc++.h>
using namespace std ;
using ll = long long ;

int k ;

void ddd(int i , ll &sum){
  if(i == k) sum = sum ;

  else {
    for(int j = 0 ; j < i ; j++) sum = sum + j ;
    ddd(i + 1,sum) ;
  }
}

int main()
{
  int i ;
  ll sum = 0 ;
  cin >> k ;
  ddd(0,sum) ;
  cout << sum << endl ;
}