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
map<char,ll> rem ;

int main(){
    cin >> n ;
    for(int i = 0 ; i < n ; i++){
        string S ;
        cin >> S ;
        if(S[0] == 'M' || S[0] == 'A' || S[0] == 'R' || S[0] == 'C' || S[0] == 'H') rem[S[0]]++ ;
    }
    string march = "MARCH" ;
    ll res = 0 ;
    for(int i = 0 ; i < 5 ; i++){
        for(int j = i + 1 ; j < 5 ; j++){
            for(int k = j + 1 ; k < 5 ; k++){
                res += rem[march[i]] * rem[march[j]] * rem[march[k]] ;
            }
        }
    }
    cout << res << endl ;
}