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

int n , k ;

int main(){
    cin >> n >> k ;
    double p = 0 ;
    for(int i = 1 ; i <= n ; i++){
        double s = (double) 1 / n ;
        int score = i , count = 0 ;
        while(score < k) {
            score *= 2 ;
            count++ ;
        }
        p += s * 1 / (double)pow(2,count) ;
    }
    cout << setprecision(13) << p << endl ;
}