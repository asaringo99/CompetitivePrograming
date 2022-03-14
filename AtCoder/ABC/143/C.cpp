#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define INF (ll)1e12

int N ;
string S ;

int main(){
    cin >> N >> S ;
    int kind = 1 ;
    char col = S[0] ;
    for(int i = 1 ; i < N ; i++){
        if(S[i] == col) continue ;
        else{
            col = S[i] ;
            kind++ ;
        }
    }
    cout << kind << endl ;
}