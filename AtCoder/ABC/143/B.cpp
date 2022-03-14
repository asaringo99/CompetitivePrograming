#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define INF (ll)1e12

int n ;

int main(){
    cin >> n ;
    int D[n] ;
    for(int i = 0 ; i < n ; i++) cin >> D[i] ;
    int sum = 0 ;
    for(int i = 0 ; i < n ; i++){
        for(int j = i + 1 ; j < n ; j++) sum += D[i] * D[j] ;
    }
    cout << sum << endl ;
}