#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

ll B[2][3] , C[3][2] ;
vector<vector<char>> A(3,vector<char>(3,'.')) ;

P rec(vector<vector<char>> A){
    int count = 0 ;
    rep(i,3) rep(j,3) if(A[i][j] != '.') count++ ;
    if(count == 9){
        int s = 0 , t = 0 ;
        rep(i,2) rep(j,3){
            if(A[i][j] == A[i+1][j]) s += B[i][j] ;
            if(A[i][j] != A[i+1][j]) t += B[i][j] ;
        }
        rep(i,3) rep(j,2){
            if(A[i][j] == A[i][j+1]) s += C[i][j] ;
            if(A[i][j] != A[i][j+1]) t += C[i][j] ;
        }
        return P(s,t) ;
    }
    else{
        P res = P(-1,-1) ;
        rep(i,3) rep(j,3){
            if(A[i][j] != '.') continue ;
            if(count % 2 == 0) A[i][j] = 'o' ;
            if(count % 2 == 1) A[i][j] = 'x' ;
            P p = rec(A) ;
            A[i][j] = '.' ;
            if(res.first < p.first) res = p ;
        }
        swap(res.first,res.second) ;
        return res ;
    }
}

int main(){
    rep(i,2) rep(j,3) cin >> B[i][j] ;
    rep(i,3) rep(j,2) cin >> C[i][j] ;
    P res = rec(A) ;
    cout << res.second << endl << res.first << endl ;
}