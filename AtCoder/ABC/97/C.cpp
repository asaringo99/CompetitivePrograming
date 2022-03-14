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

string S ;
int k ;

int main(){
    cin >> S >> k ;
    priority_queue<string> que ;
    map<string,bool> rem ;
    for(int i = 0 ; i < S.size() ; i++){
        string T = "" ;
        int N = i + k < S.size() ? i + k : S.size() ;
        for(int j = i ; j < N ; j++){
            T += S[j] ;
            if(rem[T]) continue ;
            rem[T] = true ;
            que.push(T) ;
            if(que.size() > k) que.pop() ;
            //cout << T << endl ;
        }
    }
    vector<string> res ;
    while(!que.empty()){
        string k = que.top() ; que.pop() ;
        res.push_back(k) ;
    }
    sort(res.begin(),res.end()) ;
    cout << res[k - 1] << endl ;
}