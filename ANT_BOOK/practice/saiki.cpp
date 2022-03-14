#include <bits/stdc++.h>
using namespace std ;
using ll = long long ;

int k ;

ll ddd(int i , ll sum){
  if(i == k) return sum ;

  for(int j = 0 ; j < i ; j++) sum = sum + j ;
  return ddd(i + 1,sum) ;
}

int main()
{
  int i ;
  cin >> k ;
  cout << ddd(0,0) << endl ;
}