#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

string S ;
int res[101010] ;

int main(){
    cin >> S ;
    int n = S.size() ;
    int lef = 0 , rig = 0 ;
    while(rig < n){
        while(rig < n && S[rig] == 'R') rig++ ;
        int l , r ;
        if((rig - lef) % 2 != 0){
            l = (rig - lef) / 2 + 1 ;
            r = (rig - lef) / 2 + 1 ;
        }
        else{
            l = (rig - lef) / 2 ;
            r = (rig - lef) / 2 + 1 ;
        }
        res[rig-1] += l ;
        res[rig] += r ;
        lef = rig ;
        while(rig < n && S[rig] == 'L') rig++ ;
        int s , t ;
        if((rig - lef) % 2 == 0){
            s = (rig - lef) / 2 ;
            t = (rig - lef) / 2 - 1 ;
        }
        else{
            s = (rig - lef) / 2 ;
            t = (rig - lef) / 2 ;
        }
        res[lef-1] += s ;
        res[lef] += t ;
        lef = rig ;
    }
    rep(i,n) cout << res[i] << " " ;
    cout << endl ;
}