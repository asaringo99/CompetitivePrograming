#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n , a , b ;

int main(){
    cin >> n >> a >> b ;
    int res = 0 ;
    rep(i,n+1){
        int sum = 0 ;
        for(int j = 1 ; j * j <= i ; j++){
            if(i % j == 0){
                sum++ ;
                if(j * j != i) sum++ ;
            }
        }
        if(i % 2 == 1 && sum == a) res++ ;
        if(i % 2 == 0 && sum == b) res++ ;
    }
    cout << res << endl ;
}