#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<int,int> P ;
typedef tuple<int,int,int> TP ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

int n ;
int A[101010] ;

int main(){
    cin >> n ;
    rrep(i,1,n+1){
        int a ;
        cin >> a ;
        A[a] = i ;
    }
    rrep(i,1,n+1) cout << A[i] << " " ;
    cout << endl ;
}