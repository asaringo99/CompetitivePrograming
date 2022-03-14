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
    map<string,int> rem ;
    cin >> n ;
    string res = "" ;
    int tmp = 0 ;
    for(int i = 0 ; i < n ; i++){
        string s ;
        cin >> s ;
        rem[s]++ ;
        if(rem[s] > tmp){
            tmp = rem[s] ;
            res = s ;
        }
    }
    cout << res << endl ;
}