#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define MAX_N (ll)2e5
#define YES cout << "Yes" << endl 
#define NO cout << "No" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)
#define a_z "abcdefghijklmnopqrstuvwxyz"
#define A_Z "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

int n ;

bool is_prime[MAX_N] ;
vector<int> five ;

void eratosthenes(){
    memset(is_prime,1,sizeof(is_prime)) ;
    is_prime[0] = false ;
    is_prime[1] = false ;
    for(int i = 2 ; i <= MAX_N ; i++){
        if(is_prime[i]){
            for(int j = i * 2 ; j <= MAX_N ; j += i) is_prime[j] = false ;
            if(i % 5 == 1) five.push_back(i) ;
        }
    }
}

int main(){
    cin >> n ;
    eratosthenes() ;
    for(int i = 0 ; i < n ; i++) cout << five[i] << " " ;
    cout << endl ;
}