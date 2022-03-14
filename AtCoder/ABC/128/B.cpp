#include <bits/stdc++.h>
using namespace std ;
using V_2 = vector<vector<int>> ;
using ll = long long ;
#define INF 10007

int n ;
pair<string,int> word[INF] , memo[INF] ;
int num[INF] ;

int main(){
  cin >> n ;
  for(int i = 0 ; i < n ; i++) {
    string s ; int p ;
    cin >> s >> p ;
    word[i].first = s ; word[i].second = p * -1 ;
    memo[i].first = s ; memo[i].second = p ;
  }
  sort(word,word+n) ;

  int i = 0 ;
  string mo = word[i].first ;

  for(int i = 0 ; i < n ; i++){
    for(int j = 0 ; j < n ; j++){
      if(word[i].first == memo[j].first && word[i].second == -1 * memo[j].second){
        num[j] = i + 1 ;
        cout << j + 1 << endl ;
      }
    }
  }
}