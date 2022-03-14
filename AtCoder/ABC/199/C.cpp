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

int n , Q ;
string R ;

int main(){
    cin >> n >> R >> Q ;
    string S = "" , T = "" ;
    for(int i = 0 ; i < 2 * n ; i++){
        if(i < n) S += R[i] ;
        else T += R[i] ;
    }
    for(int i = 0 ; i < Q ; i++){
        int t , a , b ;
        cin >> t >> a >> b ;
        a-- ;
        b-- ;
        if(t == 2) swap(S,T) ;
        else{
            if(a < n && b < n){
                swap(S[a],S[b]) ;
            }
            else if(a < n && b >= n){
                swap(S[a],T[b%n]) ;
            }
            else if(a >= n && b < n){
                swap(T[a%n],S[b]) ;
            }
            else if(a >= n && b >= n){
                swap(T[a%n],T[b%n]) ;
            }
        }
    }
    cout << S + T << endl ;
}