#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> P ;
#define MAX_N (ll)2e5
#define YES cout << "Yes" << endl 
#define NO cout << "No" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)
#define a_z "abcdefghijklmnopqrstuvwxyz"

int H , W , A , B ;
char hanjo[16][16] ; 
int dx[4] = {-1,1,0,0} , dy[4] = {0,0,-1,1} ;

int rec(int i , int j , bool used[16][16]){
    if(j == W){
        rec(i + 1 , 0 , used) ;
    }
    if(i == H){
        return 1 ;
    }
    if(used[i][j] || hanjo[i][j] == '.'){
        return rec(i, j+1,used) ;
    }
    int res = 0 ;
    used[i][j] = true ;

    if(j + 1 < W && !used[i][j+1] && hanjo[i][j] == '#'){
        used[i][j+1] = true ;res += rec(i,j+1,used) ;
        used[i][j+1] = false ;
    }
    if(j + 1 < W && !used[i][j+1] && hanjo[i][j] == '#'){
        used[i+1][j] = true ;res += rec(i,j+1,used) ;
        used[i+1][j] = false ;
    }
    used[i][j] = false ;
    return res ;
}

int main(){
    cin >> H >> W >> A >> B ;
    ll res = 0 ;
    for(int i = 0 ; i < (1 << H * W) ; i++){
        bool used[16][16] ;
        memset(used,0,sizeof(used)) ;
        for(int j = 0 ; j < H ; j++) fill(hanjo[j],hanjo[j]+W,'.') ;
        int count = 0 ;
        for(int j = 0 ; j < H * W ; j++){
            if(i >> j & 1){
                count++ ;
                int x = j / H , y = j % H ;
                hanjo[x][y] = '#' ;
            }
        }
        if(count != B) continue ;
        res += rec(0,0,used) ;
    }
    cout << res << endl ;
}