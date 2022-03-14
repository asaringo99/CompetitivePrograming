#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n ;
string S ;

int main(){
    cin >> n >> S ;
    string T = "b" ;
    if(T == S){
        cout << 0 << endl ;
        return 0 ;
    }
    rrep(i,1,n){
        if(i % 3 == 1){
            T = "a" + T ;
            T += "c" ;
        }
        else if(i % 3 == 2){
            T = "c" + T ;
            T += "a" ;
        }
        else{
            T = "b" + T ;
            T += "b" ;
        }
        if(T == S){
            cout << i << endl ;
            return 0 ;
        }
    }
    cout << -1 << endl ;
}