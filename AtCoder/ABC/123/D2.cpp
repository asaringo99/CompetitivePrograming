#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define MAX_N (ll)2e5
#define YES cout << "Yes" << endl 
#define NO cout << "No" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)
#define a_z "abcdefghijklmnopqrstuvwxyz"
#define A_Z "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

int x , y , z , k ;
ll A[1007] , B[1007] , C[1007] ;
vector<ll> AB , XY , res ;

int main(){
    cin >> x >> y >> z >> k ;
    for(int i = 0 ; i < x ; i++) cin >> A[i] ;
    for(int i = 0 ; i < y ; i++) cin >> B[i] ;
    for(int i = 0 ; i < z ; i++) cin >> C[i] ;
    sort(A,A+x,greater<ll>()) ;
    sort(B,B+y,greater<ll>()) ;
    sort(C,C+z,greater<ll>()) ;
    for(int i = 0 ; i < x ; i++) for(int j = 0 ; j < y ; j++) AB.push_back(A[i] + B[j]) ;
    sort(AB.begin(),AB.end(),greater<ll>()) ;
    for(int i = 0 ; i < AB.size() ; i++){
        if(i > k) break ;
        XY.push_back(AB[i]) ;
    }
    for(int i = 0 ; i < XY.size() ; i++) for(int j = 0 ; j < z ; j++) res.push_back(XY[i] + C[j]) ;
    sort(res.begin(),res.end(),greater<ll>()) ;
    for(int i = 0 ; i < k ; i++) cout << res[i] << endl ;
}