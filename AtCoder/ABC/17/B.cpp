#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

string X ;

int main(){
    cin >> X ;
    if(X == ""){
        cout << "YES" << endl ;
        return 0 ;
    }
    int i = 0 ;
    bool ok = true ;
    while(i < X.size()){
        if(i == X.size() - 1){
            if(X[i] == 'o') {
                i++ ;
                continue ;
            }
            if(X[i] == 'k') {
                i++ ;
                continue ;
            }
            if(X[i] == 'u') {
                i++ ;
                continue ;
            }
            ok = false ;
            break ;
        }
        else{
            if(X[i] == 'o') {
                i++ ;
                continue ;
            }
            if(X[i] == 'k') {
                i++ ;
                continue ;
            }
            if(X[i] == 'u') {
                i++ ;
                continue ;
            }
            if(X[i] == 'c' && X[i+1] == 'h'){
                i += 2 ;
                continue ;
            }
            ok = false ;
            break ;
        }
    }
    if(ok) cout << "YES" << endl ;
    else cout << "NO" << endl ;
}