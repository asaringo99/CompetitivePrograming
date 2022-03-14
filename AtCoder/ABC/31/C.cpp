#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n ;
int A[100] ;

int main(){
    cin >> n ;
    rep(i,n) cin >> A[i] ;
    ll res = -1e15 ;
    rep(i,n){
        ll taka = 0 , aoki = 0 , val = -1e15 , tmp = -1e15, id_a = -1 , id_b = -1 ;
        for(int j = i - 1 ; j >= 0 ; j -= 2){
            aoki += A[j] ;
            if(val < aoki){
                val = aoki ;
                id_a = j ;
            }
        }
        aoki = 0 ;
        for(int j = i + 1 ; j < n ; j += 2){
            aoki += A[j] ;
            if(tmp < aoki){
                tmp = aoki ;
                id_b = j ;
            }
        }
        if(tmp < val){
            for(int j = i ; j > id_a ; j -= 2) taka += A[j] ;
        }
        else{
            for(int j = i ; j < id_b ; j += 2) taka += A[j] ;
        }
        cout << i << " " << taka << endl ;
        res = max(res,taka) ;
    }
    cout << res << endl ;
}