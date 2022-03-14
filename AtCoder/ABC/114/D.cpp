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

int n ;
int arr[] = {74,24,14,4,2} ;

int combination(int n , int r){
    int val = 1 , tmp = 1 ;
    for(int i = 0 ; i < r ; i++) val *= (n - i) ;
    for(int i = 0 ; i < r ; i++) tmp *= (r - i) ;
    return val / tmp ;
}

int main(){
    cin >> n ;
    map<int,int> rem ;
    set<int> st ;
    for(int i = 2 ; i <= n ; i++){
        int k = i ;
        for(int j = 2 ; j * j <= k ; j++){
            if(k % j != 0) continue ;
            while(k % j == 0){
                k /= j ;
                rem[j]++ ;
            }
            st.insert(j) ;
        }
        if(k != 1) {
            st.insert(k) ;
            rem[k]++ ;
        }
    }
    int res = 0 ;
    map<int,int> pes ;
    for(int u : arr){
        int count = 0 ;
        for(int s : st){
            if(rem[s] >= u) pes[u]++ ;
        }
    }
    cout << pes[74] + pes[24] * (pes[2] - 1) + (pes[4] - 1) * pes[14] + pes[4] * (pes[4] - 1) / 2 * (pes[2] - 2) << endl ;
}