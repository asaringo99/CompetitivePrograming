#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n , d , k ;
int L[10100] , R[10100] ;

int main(){
    cin >> n >> d >> k ;
    rep(i,d) cin >> L[i] >> R[i] ;
    rep(i,k){
        int s , t ;
        cin >> s >> t ;
        int lef = s , rig = s ;
        rep(j,d){
            if((L[j] <= lef && lef <= R[j]) || (L[j] <= rig && rig <= R[j])){
                lef = min(lef,L[j]) ;
                rig = max(rig,R[j]) ;
            }
            if(lef <= t && t <= rig){
                cout << j + 1 << endl ;
                break ;
            }
        }
    }
}