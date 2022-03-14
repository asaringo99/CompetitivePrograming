#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define MAX_N (ll)2e5
#define YES cout << "Yes" << endl 
#define NO cout << "No" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)
#define a_z "abcdefghijklmnopqrstuvwxyz"

int n , A , B ;

int main(){
    cin >> n >> A >> B ;
    int count = 0 ;
    for(int i = 1 ; i <= n ; i++){
        string S = to_string(i) ;
        int sum = 0 ;
        for(char u : S){
            int t = u - '0' ;
            sum += t ;
        }
        if(A <= sum && sum <= B) count += i ;
    }
    cout << count << endl ;
}