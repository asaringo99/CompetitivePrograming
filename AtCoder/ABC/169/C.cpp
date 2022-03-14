#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define INF (ll)1e12

ll A ;
double B ;

int main(){
    cin >> A >> B ;
    ll b = B * 100 + 0.5 ;
    ll C = A * b / 100 ;
    cout << C << endl ;
}