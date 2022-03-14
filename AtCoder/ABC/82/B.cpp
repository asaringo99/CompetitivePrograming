#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define M 100005
#define YES cout << "Yes" << endl 
#define NO cout << "No" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)

string S , T ;

int main(){
    cin >> S >> T ;
    sort(S.begin(),S.end()) ;
    sort(T.begin(),T.end(),greater<char>()) ;
    if(S < T) YES ;
    else NO ;
}