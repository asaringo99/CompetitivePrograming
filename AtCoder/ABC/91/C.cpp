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
    P A[n] , B[n] ;
    for(int i = 0 ; i < n ; i++) cin >> A[i].first >> A[i].second ;
    for(int i = 0 ; i < n ; i++) cin >> B[i].first >> B[i].second ;
    sort(A,A+n) ;
    sort(B,B+n) ;
    map<P,bool> rem ;
    int res = 0 ;
    for(int i = n - 1 ; i >= 0 ; i--){
        int y = INT_MAX , num ;
        bool ok = false ;
        for(int j = 0 ; j < n ; j++){
            if(A[i].first < B[j].first && A[i].second < B[j].second && !rem[B[j]]) {
                if(y > B[j].second){
                    num = j ;
                    y = B[j].second ;
                    ok = true ;
                }
            }
        }
        if(ok){
            rem[B[num]] = true ;
            res++ ;
        }
    }
    cout << res << endl ;
}