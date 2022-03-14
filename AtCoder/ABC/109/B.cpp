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
    map<string,bool> rem ;
    vector<string> res ;
    for(int i = 0 ; i < n ; i++){
        string s ;
        cin >> s ;
        res.push_back(s) ;
        if(rem[s]){
            NO ;
            return 0 ;
        }
        rem[s] = true ;
    }
    for(int i = 0 ; i < n - 1 ; i++){
        if(res[i][res[i].size()-1] != res[i+1][0]){
            NO ;
            return 0 ;
        }
    }
    YES ;
    return 0 ;
}