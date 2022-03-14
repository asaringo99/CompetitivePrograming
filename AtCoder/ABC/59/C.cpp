#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n ;
ll A[101010] ;
int flg ;

int g(ll x){
    if(x > 0) return 1 ;
    if(x < 0) return -1 ;
    return 0 ;
}

ll f(ll sum , ll cnt){
    if(sum > 0) flg = 1 ;
    else flg = -1 ;
    rrep(i,1,n){
        sum += A[i] ;
        if(g(sum) * (-1) != flg){
            cnt += abs(sum) + 1 ;
            flg *= -1 ;
            sum = flg ;
        }
        else{
            flg *= -1 ;
        }
    }
    return cnt ;
}

int main(){
    cin >> n ;
    rep(i,n) cin >> A[i] ;
    ll sum = A[0] ;
    if(sum > 0) cout << min({f(sum,0),f(-1,abs(sum)+1)}) << endl ;
    if(sum < 0) cout << min({f(sum,0),f(1,abs(sum)+1)}) << endl ;
    if(sum == 0) cout << min(f(1,1),f(-1,1)) << endl ;
    
}