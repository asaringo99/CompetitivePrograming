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
#define A_Z "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

int n ;

int main(){
    cin >> n ;
    set<int> st1 , st2 ;
    map<int,int> rem1 , rem2 ;
    for(int i = 0 ; i < n ; i++){
        int a ;
        cin >> a ;
        if(i % 2 == 0){
            st1.insert(a) ;
            rem1[a]++ ;
        }
        else{
            st2.insert(a) ;
            rem2[a]++ ;
        }
    }
    priority_queue<P> que1 , que2 ;
    que1.push(P(0,-1)) ; que2.push(P(0,-2)) ;
    for(auto it = st1.begin() ; it != st1.end() ; it++) que1.push(P(rem1[*it],*it)) ;
    for(auto it = st2.begin() ; it != st2.end() ; it++) que2.push(P(rem2[*it],*it)) ;
    P p1 = que1.top() , p2 = que2.top() ; que1.pop() ; que2.pop() ;
    if(p1.second == p2.second){
        cout << min(n - que1.top().first - p2.first,n - que2.top().first - p1.first) << endl ;
    }
    else{
        cout << n - p1.first - p2.first << endl ;
    }
}