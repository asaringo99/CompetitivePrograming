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

int main(){
    cin >> n ;
    int sum = 0 ;
    for(int i = 1 ; i <= 9 ; i++) for(int j = 1 ; j <= 9 ; j++) sum += i * j ;
    n = sum - n ;
    vector<pair<int,int>> res ;
    for(int i = 1 ; i * i <= n ; i++){
        if(n % i == 0 && n / i <= 9 && i <= 9){
            pair<int,int> P(i,n/i) , Q(n/i,i) ;
            res.push_back(P) ;
            res.push_back(Q) ;
            if(i * i == n) res.pop_back() ;
        }
    }
    sort(res.begin(),res.end()) ;
    for(pair<int,int> p : res) cout << p.first << " x " << p.second << endl ;
}