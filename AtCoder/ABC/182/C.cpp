#include <bits/stdc++.h>
using namespace std ;
using V_2 = vector<vector<int>> ;
using ll = long long ;
#define M 100005

string S ;

int main(){
    cin >> S ;
    int n = S.size() ;
    int sum = 0 ;
    map<int,int> mod ;
    for(int i = 0 ; i < n ; i++){
        sum += S[i] - '0' ;
        mod[(S[i]-'0') % 3]++ ;
    }
    sum %= 3 ;
    if(sum == 0) {
        cout << 0 << endl ;
        return 0 ;
    }
    int ans = -1 ;
    if(mod[0] > 0) ans = 2 ;
    if(mod[sum] > 0 && mod[sum] < n) ans = 1 ;
    cout << ans << endl ;
}