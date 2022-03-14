#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> P ;
#define MAX_N (ll)2e5
#define YES cout << "Yes" << endl 
#define NO cout << "No" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)
#define a_z "abcdefghijklmnopqrstuvwxyz"

int n , m ;

int is_prime[MAX_N] ;

void prime_value(){
    memset(is_prime,0,sizeof(is_prime)) ;
    is_prime[0] = 1 ;
    is_prime[1] = 1 ;
    for(int i = 2 ; i <= MAX_N ; i++){
        if(is_prime[i] == 0){
            for(int j = i ; j <= MAX_N ; j += i){
                is_prime[j] = i ;
            }
        }
    }
}

vector<int> prime_seprator(int n){
    vector<int> res ;
    set<int> S ;
    while(is_prime[n] != 1){
        //cout << n << endl ;
        S.insert(is_prime[n]) ;
        n /= is_prime[n] ;
    }
    for(int u : S) res.push_back(u) ;
    return res ;
}

int main(){
    prime_value() ;
    cin >> n >> m ;
    int A[n] ;
    map<int,int> rem , ex ;
    for(int i = 0 ; i < n ; i++) cin >> A[i] ;
    for(int i = 0 ; i < n ; i++){
        vector<int> res = prime_seprator(A[i]) ;
        int N = res.size() ;
        for(int j = 0 ; j < (1 << N) ; j++){
            int count = 0 , tmp = 1 ;
            for(int k = 0 ; k < N ; k++){
                //cout << k << endl ;
                if(j >> k & 1){
                    count++ ;
                    tmp *= res[k] ;
                }
            }
            if(count == 0) continue ;
            if(count % 2 == 0) rem[j]-- ;
            else rem[j]++ ;
        }
    }
    for(int i = 2 ; i <= m ; i++){
        for(int j = i ; j <= m ; j += i) ex[j] += rem[i] ;
    }
    for(int i = 1 ; i <= m ; i++) cout << n - ex[i] << endl ;
}