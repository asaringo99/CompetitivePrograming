#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define INF (ll)1e12
#define MAX_N 12
#define mod (ll)(1e9+7)

int n , k ;

int main(){
  cin >> n >> k ;
  vector<ll> mns , pls ;
  for(int i = 0 ; i < n ; i++){
    ll a ; cin >> a ;
    if(a < 0) mns.push_back(a) ;
    else pls.push_back(a) ;
  }

  ll res = 1 ;
  if(n == k){
    if(mns.size() != 0){
      for(ll u : mns){
        res = (res * u) % mod ;
      }
    }
    if(pls.size() != 0){
      for(ll u : pls){
        res = (res * u) % mod ;
      }
    }
    cout << res << endl ;
    return 0 ;
  }

  sort(pls.begin(),pls.end()) ;
  sort(mns.begin(),mns.end()) ;

  if(pls.size() == 0){
    for(int i = 0 ; i < k ; i++) res = res * mns[mns.size() - 1 - i] % mod ;
    cout << (res + mod) % mod << endl ;
    return 0 ;
  }

  int i = 0 , j = 0 ;
  while(i + j < k){
    if(mns.size() - j <= 1){
      res = res * pls[pls.size() - 1 - i] % mod ;
      i++ ;
    }
    else if(pls.size() == i){
      res = res * mns[j] % mod ;
      j++ ;
    }
    else if(pls.size() - i == 1 && (k - i + j) % 2 == 0){
      res = res * mns[j] % mod * mns[j+1] % mod ;
      j += 2 ;
    }
    else{
      if(mns[j] * mns[j+1] > pls[pls.size() - 1 - i] * pls[pls.size() - 2 - i]){
        res = res * mns[j] % mod * mns[j+1] % mod ;
        j += 2 ;
      }
      else{
        res = res * pls[pls.size() - 1 - i] % mod * pls[pls.size() - 2 - i] % mod ;
        i += 2 ;
      }
    }
  }

  cout << res % mod << endl ;
  return 0 ;
}