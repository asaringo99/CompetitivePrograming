#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define INF (ll)1e12

int n ;

int main(){
    cin >> n ;
    int A[n] , B[n] ;
    for(int i = 0 ; i < n ; i++){
        cin >> A[i] >> B[i] ;
    }
    sort(A,A+n) ;
    sort(B,B+n) ;
    if(n % 2 == 1){
        int ind = n / 2 ;
        cout << B[ind] - A[ind] + 1 << endl ;
        return 0 ;
    }
    else{
        int ind = n / 2 ;
        cout << B[ind] + B[ind - 1] - A[ind] - A[ind - 1] + 1 << endl ;
    }
}