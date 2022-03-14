#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> P ;
#define MAX_N 3000
#define YES cout << "Yes" << endl 
#define NO cout << "No" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)
#define a_z "abcdefghijklmnopqrstuvwxyz"

int N , Q ;
char S[500007] ;

int main(){
    cin >> N >> S >> Q ;
    map<char,set<int>> rem ;
    for(int i = 0 ; i < N ; i++){
        rem[S[i]].insert(i) ;
    }
    for(char u : a_z) rem[u].insert(N) ;
    vector<int> res ;
    for(int i = 0 ; i < Q ; i++){
        int t ;
        cin >> t ;
        if(t == 1){
            int j ;
            char c ;
            cin >> j >> c ;
            j-- ;
            //for(int u : rem[c]) cout << u << " " ;
            //cout << endl ;
            rem[S[j]].erase(j) ;
            rem[c].insert(j) ;
            S[j] = c ;
            //for(int u : rem[c]) cout << u << " " ;
            //cout << endl ;
        }
        else{
            int l , r , count = 0 ;
            cin >> l >> r ;
            l-- ;
            r-- ;
            for(char u : a_z){
                if(rem[u].empty()) continue ;
                auto it = rem[u].lower_bound(l) ;
                if(*it <= r) count++ ;
            }
            res.push_back(count) ;
        }
    }
    for(int u : res) cout << u << endl ;
}