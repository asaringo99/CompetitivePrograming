#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define MAX_N (ll)1e5
#define YES cout << "Yes" << endl 
#define NO cout << "No" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)
#define a_z "abcdefghijklmnopqrstuvwxyz"

char S[100007] ;

int main(){
    cin >> S ;
    int tmp = 1 , k = 0 ;
    while(S[k]) k++ ;
    if(k % 2 == 0){
    if(S[k/2] != S[k/2-1]) tmp = 0;
    else{
        for(int i = 1 ; i < k / 2 ; i++){
            if(S[k / 2 + i] == S[k / 2 - 1 - i] && S[k / 2 + i] == S[k / 2])tmp++;
            else break ;
        }
        }
    }
    else{
        for(int i = 1 ; i <= k / 2 ; i++){
            if(S[k / 2] == S[k / 2 + i] && S[k / 2] == S[k / 2 - i])tmp++;
            else break ;
        }
    }
    int res = tmp + k / 2 ;
    cout << res << endl ;
}