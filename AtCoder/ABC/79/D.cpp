#include <bits/stdc++.h>
using namespace std ;
using V_2 = vector<vector<int>> ;
using ll = long long ;

int d[10][10] ;
int H , W ;

void warshall_floyd(){
    for(int k = 0 ; k < 10 ; k++)
        for(int i = 0 ; i < 10 ; i++)
            for(int j = 0 ; j < 10 ; j++) d[i][j] = min(d[i][j] , d[i][k] + d[k][j]) ;
}

int main(){
    cin >> H >> W ;
    for(int i = 0 ; i < 10 ; i++){
        for(int j = 0 ; j < 10 ; j++){
            cin >> d[i][j] ;
        }
    }
    warshall_floyd() ;
    ll res = 0 ;
    for(int i = 0 ; i < H ; i++){
        for(int j = 0 ; j < W ; j++){
            int a ;
            cin >> a ;
            if(a == -1) continue ;
            res += d[a][1] ;
        }
    }
    cout << res << endl ;
}