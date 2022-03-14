#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n ;
map<int,int> mp ;

int main(){
    string S ;
    cin >> S ;
    for(char u : S) mp[u - 'A']++ ;
    cout << mp[0] << " " << mp[1] << " " << mp[2] << " " << mp[3] << " " << mp[4] << " " << mp[5] << endl ;
}