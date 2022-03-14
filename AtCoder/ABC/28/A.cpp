#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n ;

int main(){
    cin >> n ;
    if(n <= 59) cout << "Bad" << endl ;
    else if(n <= 89) cout << "Good" << endl ;
    else if(n <= 99) cout << "Great" << endl ;
    else  cout << "Perfect" << endl ;
}