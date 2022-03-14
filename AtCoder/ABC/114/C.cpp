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

ll n ;

int main(){
    cin >> n ;
    queue<ll> que ;
    que.push(3) ;
    que.push(5) ;
    que.push(7) ;
    int count = 0 ;
    while(!que.empty()){
        ll val = que.front() ; que.pop() ;
        if(val > n) break ;
        string S = to_string(val) ;
        map<char,bool> rem ;
        for(char u : S) rem[u] = true ;
        if(rem['3'] && rem['5'] && rem['7']) count++ ;
        //cout << val << " " << count << endl ;
        que.push(10 * val + 3) ;
        que.push(10 * val + 5) ;
        que.push(10 * val + 7) ;
    }
    cout << count << endl ;
}