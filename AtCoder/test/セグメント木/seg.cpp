#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> P ;
#define YES cout << "Yes" << endl 
#define NO cout << "No" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)
#define a_z "abcdefghijklmnopqrstuvwxyz"

int n ;

const int MAX_N = (1 << 17) ;
int dat[2 * MAX_N - 1] ;

int A[MAX_N] ;

ll gcd(ll a , ll b){
    if(b == 0) return a ;
    return gcd(b , a % b) ;
}

void init(int n_){
    n = 1 ;
    while(n < n_) n *= 2 ;
    memset(dat,0,sizeof(dat)) ;
    for(int i = 0 ; i < n_ ; i++) dat[n - 1 + i] = A[i] ;
    for(int i = n - 2 ; i >= 0 ; i--){
        dat[i] = gcd(dat[2*i+1],dat[2*i+2]) ;
    }
}

int check(int a , int b , int k , int l , int r){
    if(l == a && r == b) return 0 ;
    if(b <= l || r <= a) return dat[k] ;
    int lef = check(a,b,2*k+1,l,(l+r)/2) ;
    int rig = check(a,b,2*k+2,(l+r)/2,r) ;
    return gcd(lef,rig) ;
}

int main(){
    cin >> n ;
    for(int i = 0 ; i < n ; i++) cin >> A[i] ;
    init(n) ;
    int res = 0 ;
    for(int i = 0 ; i < n ; i++){
        res = max(res,check(i,i+1,0,0,n)) ;
    }
    cout << res << endl ;
}