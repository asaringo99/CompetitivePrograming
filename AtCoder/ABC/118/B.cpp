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

int n , m ;

int main(){
    cin >> n >> m ;
    map<int,int> rem ;
    for(int i = 0 ; i < n ; i++){
        int k ;
        cin >> k ;
        for(int j = 0 ; j < k ; j++){
            int a ;
            cin >> a ;
            rem[a]++ ;
        }
    }
    int count = 0 ;
    for(int i = 1 ; i <= m ; i++) if(rem[i] == n) count++ ;
    cout << count << endl ;
}