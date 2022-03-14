#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,int> P ;
#define MAX_N (ll)1e5
#define YES cout << "Yes" << endl 
#define NO cout << "No" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)
#define a_z "abcdefghijklmnopqrstuvwxyz"
#define A_Z "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

int n , k ;

int main(){
    cin >> n >> k ;
    int V[n] ;
    for(int i = 0 ; i < n ; i++) cin >> V[i] ;
    int res = 0 , num = min(n,k) ;
    for(int i = 1 ; i <= num ; i++){
        for(int j = 0 ; j <= i ; j++){
            int tmp = 0 ;
            priority_queue<int> que ;
            for(int lef = 0 ; lef < i - j ; lef++){
                if(V[lef] >= 0) tmp += V[lef] ;
                else que.push(V[lef]) ;
                if(que.size() > k - i){
                    int noval = que.top() ; que.pop() ;
                    tmp += noval ;
                }
            }
            for(int rig = 0 ; rig < j ; rig++){
                if(V[n - 1 - rig] >= 0) tmp += V[n - 1 - rig] ;
                else que.push(V[n - 1 - rig]) ;
                if(que.size() > k - i){
                    int noval = que.top() ; que.pop() ;
                    tmp += noval ;
                }
            }
            res = max(res,tmp) ;
        }
    }
    cout << res << endl ;
}