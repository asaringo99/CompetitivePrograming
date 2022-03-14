#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n ;
int A[202020] ;
bool use[202020] ;
vector<int> res ;

int main(){
    cin >> n ;
    rrep(i,1,n+1) cin >> A[i] ;
    for(int i = n ; i > 0 ; i--){
        int sum = 0 ;
        for(int j = 2 * i ; j <= n ; j += i){
            if(use[j]) sum++ ;
        }
        if(sum % 2 != A[i]){
            use[i] = true ;
            res.push_back(i) ;
        }
    }
    cout << res.size() << endl ;
    rep(i,res.size()) cout << res[res.size() - 1 - i] << endl ;
}