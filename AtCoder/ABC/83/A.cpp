#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define MAX_N (ll)2e5
#define YES cout << "Yes" << endl 
#define NO cout << "No" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)
#define a_z "abcdefghijklmnopqrstuvwxyz"

int A , B , C , D ;

int main(){
    cin >> A >> B >> C >> D ;
    if(A + B > C + D) cout << "Left" << endl ;
    else if(A + B == C + D) cout << "Balanced" << endl ;
    else cout << "Right" << endl ;
}