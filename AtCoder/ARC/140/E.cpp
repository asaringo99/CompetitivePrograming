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
string S ;

int main(){
    // fast_input_output
    cin >> n >> S ;
    priority_queue<ll,vector<ll>,greater<ll>> pq2 ;
    multiset<ll> pq1 ;
    rep(i,n){
        if(S[i] == 'R'){
            int lef = 0 , rig = 0 ;
            for(int j = i - 1 ; j >= 0 ; j--){
                if(S[j] != 'A') break;
                lef++ ;
            }
            for(int j = i + 1 ; j < n ; j++){
                if(S[j] != 'C') break;
                rig++ ;
            }
            int sum = min(lef,rig) ;
            if(sum == 0) continue;
            if(sum == 1) pq2.push(sum) ;
            else pq1.insert(sum) ;
        }
    }
    int num = 0 ;
    while(!(pq1.empty() && pq2.empty())){
        if(num % 2 == 0){
            if(pq1.empty()){
                pq2.pop() ;
            }
            else{
                if(pq2.empty()){
                    auto it = pq1.begin() ;
                    pq1.erase(it) ;
                    pq2.push(1) ;
                }
                else{
                    auto it = pq1.end() ; it-- ;
                    ll top = *it ; pq1.erase(it) ;
                    if(top > 2) pq1.insert(top-1) ;
                    else pq2.push(1) ;
                }
            }
        }
        else{
            pq2.pop() ;
        }
        num++ ;
    }
    cout << num << endl ;
}