#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,int> P ;
#define MAX_N (ll)1e5
#define YES cout << "Yes" << endl 
#define NO cout << "No" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)
#define a_z "abcdefghijklmnopqrstuvwxyz"
#define A_Z "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

string S ;

int calculation(int a , int b , int c){
    if(c == 0) return a + b ;
    else return a - b ;
}

int main(){
    char pls[2] = {'+' , '-'} ;
    cin >> S ;
    int a = S[0] - '0' , b = S[1] - '0' , c = S[2] - '0' , d = S[3] - '0' ;
    for(int i = 0 ; i < 2 ; i++){
        for(int j = 0 ; j < 2 ; j++){
            for(int k = 0 ; k < 2 ; k++){
                int res = calculation(a,b,i) ;
                res = calculation(res,c,j) ;
                res = calculation(res,d,k) ;
                if(res == 7) {
                    cout << a << pls[i] << b << pls[j] << c << pls[k] << d << "=7" << endl ;
                    return 0 ;
                }
            }
        }
    }
}