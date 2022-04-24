#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<int,int> P ;
typedef tuple<int,int,int> TP ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

int n , k ;
string S ;

int main(){
    cin >> n >> k >> S ;
    int R = 0 , L = 0 ;
    int sum = 0 ;
    bool lb = true , rb = true ;
    rep(i,n){
        if(i < n && S[i] == S[i+1]) sum++ ;
        if(S[i] =='L' && lb){
            lb = false ;
            rb = true ;
            L++ ;
        }
        if(S[i] =='R' && rb){
            lb = true ;
            rb = false ;
            R++ ;
        }
    }
    if(L == R){
        if(k >= L) cout << sum + 2 * L - 1 << endl ;
        else cout << sum + 2 * k << endl ;
    }
    else{
        L = min(L,R) ;
        if(k >= L) cout << sum + 2 * L << endl ;
        else cout << sum + 2 * k << endl ;
    }
}