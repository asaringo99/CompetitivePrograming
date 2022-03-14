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
string S ;

int main(){
    cin >> n >> k >> S ;
    string R = S ;
    for(int i = 0 ; i < n ; i++){
        int num = i ;
        for(int j = i + 1 ; j < n ; j++){
            string T = S ;
            if(S[num] > S[j]){
                swap(T[i],T[j]) ;
                int sum = 0 ;
                for(int m = 0 ; m < n ; m++){
                    if(R[m] != T[m]) sum++ ;
                }
                if(sum > k) continue ;
                num = j ;
            }
        }
        swap(S[i],S[num]) ;
    }
    cout << S << endl ;
}