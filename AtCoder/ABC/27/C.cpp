#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

ll n ;

int main(){
    cin >> n ;
    int count = 0 ;
    while(n > 0){
        if(count % 2 == 0) n /= 2 ;
        else n = (n - 1) / 2 ;
        count++ ;
    }
    if(count & 1) cout << "Aoki" << endl ;
    else cout << "Takahashi" << endl ;
}