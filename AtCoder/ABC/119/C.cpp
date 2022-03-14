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

int n , A , B , C ;
int L[8] ;

int dfs(int d , int a , int b , int c , int sum_a , int sum_b , int sum_c){
    int res = INT_MAX ;
    if(d == n) {
        if(sum_a == 0 || sum_b == 0 || sum_c == 0) return INT_MAX ;
        else return (sum_a + sum_b + sum_c - 3) * 10 + abs(A - a) + abs(B - b) + abs(C - c) ;
    }
    res = min(res,dfs(d+1,a+L[d],b,c,sum_a+1,sum_b,sum_c)) ;
    res = min(res,dfs(d+1,a,b+L[d],c,sum_a,sum_b+1,sum_c)) ;
    res = min(res,dfs(d+1,a,b,c+L[d],sum_a,sum_b,sum_c+1)) ;
    res = min(res,dfs(d+1,a,b,c,sum_a,sum_b,sum_c)) ;
    return res ;
}

int main(){
    cin >> n >> A >> B >> C ;
    for(int i = 0 ; i < n ; i++) cin >> L[i] ;
    cout << dfs(0,0,0,0,0,0,0) << endl ;
}