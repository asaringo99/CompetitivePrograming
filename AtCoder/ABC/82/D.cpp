#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define MAX_S 8000
#define YES cout << "Yes" << endl 
#define NO cout << "No" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)

string S ;
int x , y ;

int main(){
    cin >> S >> x >> y ;
    x += 10000 ;
    y += 10000 ;
    int nx = 10000 , ny = 10000 ;
    vector<int> dx , dy ;
    int i = 0 ;
    while(i < S.size() && S[i] == 'F'){
        nx++ ;
        i++ ;
    }
    while(i < S.size()){
        i++ ;
        int to_y = 0 ;
        while(i < S.size() && S[i] == 'F'){
            to_y++ ;
            i++ ;
        }
        i++ ;
        int to_x = 0 ;
        while(i < S.size() && S[i] == 'F'){
            to_x++ ;
            i++ ;
        }
        if(to_x > 0) dx.push_back(to_x) ;
        if(to_y > 0) dy.push_back(to_y) ;
    }
    bool dpx[dx.size()+1][20001] ;
    memset(dpx,0,sizeof(dpx)) ;
    dpx[0][nx] = true ;
    for(int i = 0 ; i < dx.size() ; i++){
        for(int j = 0 ; j < 20001 ; j++){
            //dpx[i+1][j] = dpx[i][j] ;
            if(dpx[i][j]){
                dpx[i+1][j+dx[i]] = true ;
                dpx[i+1][j-dx[i]] = true ;
            }
        }
    }
    bool dpy[dy.size()+1][20001] ;
    memset(dpy,0,sizeof(dpy)) ;
    dpy[0][ny] = true ;
    for(int i = 0 ; i < dy.size() ; i++){
        for(int j = 0 ; j < 20001 ; j++){
            //dpy[i+1][j] = dpy[i][j] ;
            if(dpy[i][j]){
                dpy[i+1][j+dy[i]] = true ;
                dpy[i+1][j-dy[i]] = true ;
            }
        }
    }
    if(dpx[dx.size()][x] && dpy[dy.size()][y]) YES ;
    else NO ;
}