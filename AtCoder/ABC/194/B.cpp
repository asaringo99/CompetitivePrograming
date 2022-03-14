#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define M 100005
#define YES cout << "Yes" << endl 
#define NO cout << "No" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)

int n ;


// 解法1
/*
int main(){
    cin >> n ;
    pair<int,int> A[n] , B[n] ;
    for(int i = 0 ; i < n ; i++){
        int a , b ;
        cin >> a >> b ;
        A[i].first = a ; A[i].second = i ;
        B[i].first = b ; B[i].second = i ;
    }
    sort(A,A+n) ;
    sort(B,B+n) ;
    if(A[0].second != B[0].second) cout << max(A[0].first,B[0].first) ;
    else{
        int tmp = min(max(A[0].first,B[1].first),max(B[0].first,A[1].first)) ;
        cout << min(A[0].first + B[0].first,tmp) << endl ;
    }
}
*/

// 解法2
int main(){
    cin >> n ;
    int A[n] , B[n] ;
    for(int i = 0 ; i < n ; i++) cin >> A[i] >> B[i] ;
    int res = INT_MAX ;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            if(i == j) res = min(res,A[i] + B[j]) ;
            else res = min(res,max(A[i],B[j])) ;
        }
    }
    cout << res << endl ;
}