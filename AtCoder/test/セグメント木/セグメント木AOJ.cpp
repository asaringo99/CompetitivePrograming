#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> P ;
#define YES cout << "Yes" << endl 
#define NO cout << "No" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)
#define a_z "abcdefghijklmnopqrstuvwxyz"

const ll MAX_N = 1 << 17 ;
const ll INF = INT_MAX ;
ll dat[2 * MAX_N - 1] ;

int n , q ;

void init(int p){
    n = 1 ;
    while(n < p) n *= 2 ;
    for(int i = 0 ; i < 2 * n - 1 ; i++) dat[i] = INF ;
}

void update(int x , ll value){
    x += n - 1 ;
    dat[x] = value ;
    while(x > 0){
        x = (x - 1) / 2 ;
        dat[x] = min(dat[2*x+1],dat[2*x+2]) ;
    }
}

ll query(int a , int b , int k , int l , int r){
    if(r <= a || b <= l) return INF ;
    if(a <= l && r <= b) return dat[k] ;
    ll lv = query(a,b,2*k+1,l,(l+r)/2) ;
    ll rv = query(a,b,2*k+2,(l+r)/2,r) ;
    return min(lv,rv) ;
}

int main(){
    cin >> n >> q ;
    init(n) ;
    for(int i = 0 ; i < q ; i++){
        int com , x , y ;
        cin >> com >> x >> y ;
        if(com == 0) update(x,y) ;
        
        else cout << query(x,y+1,0,0,n) << endl ; ;
    }
}