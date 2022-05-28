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
ll W ;
int A[101010] ;
int prevv[101010] ;

int main(){
    fast_input_output
    cin >> W ;
    int count = 0 , w = 1 ;
    while(count < 300 && w <= 100000){
        if(A[w] > 0){
            w++ ;
            continue;
        }
        A[w] = 1 ;
        rrep(i,1,w){
            if(A[w] + A[i] <= 3) {
                A[i+w] = A[w] + A[i] ;
                prevv[i+w] = w ;
            }
        }
        w++ ;
        count++ ;
    }
    set<int> st ;
    rep(i,)
}