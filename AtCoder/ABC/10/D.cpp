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

int n , g , e ;

vector<int> G[100] ;
bool lady[100] ;

int main(){
    cin >> n >> g >> e ;
    for(int i = 0 ; i < g ; i++){
        int girl ;
        cin >> girl ;
        lady[girl] = true ;
    }
    for(int i = 0 ; i < e ; i++){
        int a , b ;
        cin >> a >> b ;
        G[a].push_back(b) ;
        G[b].push_back(a) ;
    }
}