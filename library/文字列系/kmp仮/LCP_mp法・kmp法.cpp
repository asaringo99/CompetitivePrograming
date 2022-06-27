#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int A[505050] ;
string S ;

// 使い方 : 引数にS(文字列)をいれる
void mp(string S){
    int n = S.size() ;
    int j = -1 ;
    A[0] = -1 ;
    for(int i = 0 ; i < n ; i++){
        while(j >= 0 && S[i] != S[j]) j = A[j] ;
        j++ ;
        A[i+1] = j ;
    }
}

// 使い方 : 引数にS(文字列)をいれる
void kmp(string S){
    int n = S.size() ;
    int j = -1 ;
    A[0] = -1 ;
    for(int i = 0 ; i < n ; i++){
        while(j >= 0 && S[i] != S[j]) j = A[j] ;
        j++ ;
        if(S[i+1] == S[j]) A[i+1] = A[j] ;
        else A[i+1] = j ;
    }
}

// 例題 S := abcdefghiabcdefghi => ans := 9
int main(){
    S = "abcdefghiabcdefghi" ;
    kmp(S) ;
    int ans = 0 ;
    rep(i,S.size()+1) cout << A[i] << " " ; cout << endl ;
    cout << ans << endl ;
}