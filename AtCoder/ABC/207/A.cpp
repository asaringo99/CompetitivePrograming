#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int a , b , c ;

int main(){
    cin >> a >> b >> c ;
    int A[] = {a,b,c} ;
    sort(A,A+3) ;
    cout << A[1] + A[2] << endl ;
}