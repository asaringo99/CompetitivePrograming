#include <bits/stdc++.h>
using namespace std ;
using V_2 = vector<vector<int>> ;
using ll = long long ;
#define M 100005

int n ;

int main(){
    cin >> n ;
    int res = 0 ;
    for(int i = 1 ; i <= n ; i++){
        bool ok = true ;
        stringstream ss ;
        ss << oct << i ;
        for(int j = 0 ; j < ss.str().size() ; j++){
            if(ss.str()[j] == '7') ok = false ;
        }
        string S = to_string(i) ;
        for(int j = 0 ; j < S.size() ; j++){
            if(S[j] == '7') ok = false ;
        }
        if(ok) res++ ;
    }
    cout << res << endl ;
}