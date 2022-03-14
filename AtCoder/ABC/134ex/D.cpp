#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)

int n ;

int main(){
    cin >> n ;
    int A[n] ;
    vector<int> X ;
    rep(i,n) cin >> A[i] ;
    map<int,int> rem ;
    for(int i = n - 1 ; i >= 0 ; i--){
        if(rem[i+1] % 2 == A[i]) continue ;
        X.push_back(i+1) ;
        for(int j = 1 ; j * j <= (i + 1) ; j++){
            if((i + 1) % j == 0){
                rem[j]++ ;
                if(j * j != (i + 1)) rem[(i+1)/j]++ ;
            }
        }
    }
    cout << X.size() << endl ;
    reverse(X.begin(),X.end()) ;
    for(int u : X) cout << u << endl ;
}