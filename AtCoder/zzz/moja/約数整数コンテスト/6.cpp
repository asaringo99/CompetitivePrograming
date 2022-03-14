#include <bits/stdc++.h>
using namespace std ;
typedef unsigned long long ll ;
typedef pair<int,int> P ;
#define rep(i,n) for(ll i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(ll i = a ; i < b ; i++)

vector<int> vec ;
bool prime[10000000] ;

void ertstns(){
    memset(prime,1,sizeof(prime)) ;
    prime[0] = prime[1] = false ;
    for(int i = 2 ; i < 606060 ; i++){
        if(prime[i]){
            vec.push_back(i) ;
            for(int j = i * 2 ; j < 606060 ; j += i){
                prime[j] = false ;
            }
        }
    }
}

int n ;
ll a , b ;

int main(){
    cin >> a >> b ;
    ertstns() ;
    int res = 0 ;
    rep(i,vec.size()){
        int sum = 0 ;
        ll v = 1 ;
        while(true){
            v *= vec[i] ;
            ll lef = a / v + 1 , rig = b / v ;
            if(a % v == 0) lef-- ;
            if(rig < lef) break ;
            sum++ ;
            res = max(res,sum) ;
        }
    }
    cout << res << endl ;
}