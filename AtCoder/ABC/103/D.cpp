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

int n , m ;

int main(){
    cin >> n >> m ;
    map<int,vector<int>> rem ;
    for(int i = 0 ; i < m ; i++){
        int a , b ;
        cin >> a >> b ;
        a-- ;
        b-- ;
        rem[a].push_back(b) ;
    }
    set<int> st ;
    int count = 0 ;
    for(int i = 0 ; i < n ; i++){
        if(st.count(i) == 1) {
            st = {} ;
            count++ ;
        }
        for(int u : rem[i]) st.insert(u) ;
    }
    cout << count << endl ;
}