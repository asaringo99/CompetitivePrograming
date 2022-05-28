#include <bits/stdc++.h>
using namespace std ;
#define fast_input_output ios::sync_with_stdio(false); cin.tie(nullptr);
typedef long long ll ;
typedef long double ld ;
typedef pair<ll,ll> P ;
typedef tuple<ll,ll,ll> TP ;
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define bit_count(x) __builtin_popcountll(x)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a / gcd(a,b) * b
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

int n ;
int M[] = {31,29,31,30,31,30,31,31,30,31,30,31} ;
int S[101] ;
bool C[4040] ;

int main(){
    // fast_input_output
    rrep(i,1,367){
        if(i % 7 == 1) C[i] = true ;
        if(i % 7 == 0) C[i] = true ;
    }
    rep(i,12) S[i+1] = S[i] + M[i] ;
    cin >> n ;
    rep(i,n){
        string T ;
        cin >> T ;
        bool day = false ;
        int m = 0 , d = 0 ;
        for(char u : T){
            if(u == '/') {
                day = true ;
                continue;
            }
            if(day){
                d *= 10 ;
                d += (u - '0') ;
            }
            else{
                m *= 10 ;
                m += (u - '0') ;
            }
        }
        int c = S[m-1]+d ;
        while(C[c]) c++ ;
        C[c] = true ;
    }
    int res = 0 , sum = 0 ;
    rrep(i,1,367) {
        if(C[i]) sum++ ;
        else sum = 0 ;
        chmax(res,sum) ;
    }
    cout << res << endl ;
}