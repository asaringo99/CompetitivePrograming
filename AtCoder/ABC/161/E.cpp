#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n , k , c ;
string S ;

ll dp[202020] , sp[202020] ;
vector<int> rem[202020] ;
bool ng[202020] ;

int main(){
    cin >> n >> k >> c >> S ;
    rep(i,n){
        if(S[i] == 'o'){
            if(i+c+1 <= n){
                dp[i+c+1] = dp[i] + 1 ;
                sp[i+c+1] = i ;
            }
            else dp[i] = dp[i-c-1] + 1 ;
            rem[dp[i]].push_back(i) ;
        }
    }
}