#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> P ;
#define YES cout << "Yes" << endl 
#define NO cout << "No" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)
#define a_z "abcdefghijklmnopqrstuvwxyz"

const int MAX_N = 1 << 17 ;
const int INF = INT_MAX ;

int n ;
int dat[2 * MAX_N - 1] , A[MAX_N] ;

void init(int p){
    n = 1 ;
    while(n < p) n *= 2 ;
    for(int i = 0 ; i < p ; i++) dat[i + n - 1] = A[i] ;
}