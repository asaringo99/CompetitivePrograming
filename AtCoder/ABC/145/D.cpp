#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define MAX_N (ll)2e6
#define YES cout << "Yes" << endl 
#define NO cout << "No" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)
#define a_z "abcdefghijklmnopqrstuvwxyz"

const int mod = 1000000000 + 7 ;

ll x , y ;

ll pes[MAX_N+1] ; // (n!)^(p-2) (mod p) を格納
ll tes[MAX_N+1] ; // (n!) (mod p) を格納

// 逆元(1/n)のmod計算
ll invmodcal(ll A , ll N){
    ll res = 1 ;
    while(N > 0){
        if(N & 1) res = (res * A) % mod ;
        A = (A * A) % mod ;
        N >>= 1 ;
    }
    return res % mod ;
}

// 階乗の逆元(n!)^(-1)のmodを配列に格納
void invmod(){
    pes[0] = 1 ; pes[1] = 1 ;
    for(ll i = 2 ; i <= MAX_N ; i++){
        pes[i] = invmodcal(i,mod-2) * pes[i-1] % mod ;
    }
}

// 階乗のmodを配列に格納
void powmod(){
    tes[0] = 1 ; tes[1] = 1 ;
    for(ll i = 2 ; i <= MAX_N ; i++){
        tes[i] = (tes[i-1] * i) % mod ;
    }
}

//nCrの計算
ll combination(ll n , ll r){
    return tes[n] * pes[n-r] % mod * pes[r] % mod ;
}

int main(){
    // pesが逆元の階乗(1/n!)のmod配列
    // tesが階乗(n!)のmod配列
    powmod() ; invmod() ;  
    cin >> x >> y ;
    if((2 * y - x) % 3 != 0 || 2 * y - x < 0 || 2 * x - y < 0){
        cout << 0 << endl ;
        return 0 ;
    }
    ll rig = (2 * y - x) / 3 ;
    ll lef = y - 2 * rig ;
    cout << combination(rig + lef , rig) << endl ;
}