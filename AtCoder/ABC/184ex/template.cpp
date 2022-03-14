#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<int,int> P ;
typedef tuple<int,int,int> TP ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

int x , y;

int main(){
    cin >> x >> y ;
    if(x > y){
        y += 3 ;
        if(y > x) cout << "Yes" << endl ;
        else cout << "No" << endl ;
    }
    else{
        x += 3 ;
        if(x > y) cout << "Yes" << endl ;
        else cout << "No" << endl ;
    }
}