#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef tuple<int,int,int,char> TP ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n , A , B , C ;
string S[101010] ;
vector<char> res ;

bool dp[101010][6][6][6] ;
TP sp[101010][6][6][6] ;


int main(){
    cin >> n >> A >> B >> C ;
    rep(i,n) cin >> S[i] ;
    A = min(A,3) ;
    B = min(B,3) ;
    C = min(C,3) ;
    memset(dp,0,sizeof(dp)) ;
    dp[0][A][B][C] = true ;
    sp[0][A][B][C] = {0,0,0,'0'} ;
    rep(i,n) rep(a,4) rep(b,4) rep(c,4){
        if(dp[i][a][b][c]){
            if(S[i] == "AB"){
                if(b > 0) {
                    dp[i+1][min(a+1,3)][b-1][c] = true ;
                    sp[i+1][min(a+1,3)][b-1][c] = {a,b,c,'A'} ;
                }
                if(a > 0) {
                    dp[i+1][a-1][min(b+1,3)][c] = true ;
                    sp[i+1][a-1][min(b+1,3)][c] = {a,b,c,'B'} ;
                }
            }
            if(S[i] == "AC"){
                if(c > 0) {
                    dp[i+1][min(a+1,3)][b][c-1] = true ;
                    sp[i+1][min(a+1,3)][b][c-1] = {a,b,c,'A'} ;
                }
                if(a > 0) {
                    dp[i+1][a-1][b][min(c+1,3)] = true ;
                    sp[i+1][a-1][b][min(c+1,3)] = {a,b,c,'C'} ;
                }
            }
            if(S[i] == "BC"){
                if(c > 0) {
                    dp[i+1][a][min(b+1,3)][c-1] = true ;
                    sp[i+1][a][min(b+1,3)][c-1] = {a,b,c,'B'} ;
                }
                if(b > 0) {
                    dp[i+1][a][b-1][min(c+1,3)] = true ;
                    sp[i+1][a][b-1][min(c+1,3)] = {a,b,c,'C'} ;
                }
            }
        }
    }
    rep(a,4) rep(b,4) rep(c,4) if(dp[n][a][b][c]){
        int m = n ;
        TP tp = sp[n][a][b][c] ;
        while(m > 0){
            int A , B , C ; char word ;
            tie(A,B,C,word) = tp ;
            res.push_back(word) ;
            m-- ;
            tp = sp[m][A][B][C] ;
        }
        cout << "Yes" << endl ;
        rep(i,n) cout << res[n-1-i] << endl ;
        return 0 ;
    }
    cout << "No" << endl ;
}