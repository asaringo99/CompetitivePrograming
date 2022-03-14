#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> P ;
#define MAX_N (ll)1e6
#define YES cout << "Yes" << endl 
#define NO cout << "No" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)
#define a_z "abcdefghijklmnopqrstuvwxyz"

int n ;

int prime_factor[MAX_N + 1] ;

void prime_factor_calculation(){
    fill(prime_factor,prime_factor+MAX_N+1,-1) ;
    for(int i = 2 ; i <= MAX_N ; i++){
        if(prime_factor[i] == -1){
            for(int j = i ; j <= MAX_N ; j += i){
                prime_factor[j] = i ;
            }
        }
    }
}

vector<int> prime_factorization(int n){
    set<int> st ;
    int i = n ;
    while(prime_factor[i] != -1){
        st.insert(prime_factor[i]) ;
        i /= prime_factor[i] ;
    }
    vector<int> res ;
    for(int u : st) res.push_back(u) ;
    return res ;
}

int gcd(int a , int b){
    if(b == 0) return a ;
    return gcd(b,a%b) ;
}

int main(){
    cin >> n ;
    int A[n] ;
    int res = 1 ;
    for(int i = 0 ; i < n ; i++){
        cin >> A[i] ;
        if(i == 0){
            res = A[i] ;
        }
        else{
            res = gcd(res,A[i]) ;
        }
    }
    if(res > 1){
        cout << "not coprime" << endl ;
        return 0 ;
    }
    prime_factor_calculation() ;
    set<int> S ;
    for(int i = 0 ; i < n ; i++){
        vector<int> tmp = prime_factorization(A[i]) ;
        for(int u : tmp){
            if(S.count(u) == 1){
                cout << "setwise coprime" << endl ;
                return 0 ;
            }
            S.insert(u) ;
        }
    }
    cout << "pairwise coprime" << endl ;
}