#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define MAX_N (ll)2e5
#define YES cout << "Yes" << endl 
#define NO cout << "No" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)
#define a_z "abcdefghijklmnopqrstuvwxyz"
#define A_Z "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

ll s , t ;

int main(){
    cin >> s >> t ;
    s-- ;
    string S = to_string(s) , T = to_string(t) ;
    vector<int> A , B ;
    for(int i = 0 ; i < S.size() ; i++) A.push_back(S[i] - '0') ;
    for(int i = 0 ; i < T.size() ; i++) B.push_back(T[i] - '0') ;
    ll dpa[S.size() + 1][2][2] , dpb[T.size() + 1][2][2] ;
    memset(dpa,0,sizeof(dpa)) ;
    memset(dpb,0,sizeof(dpb)) ;
    dpa[0][0][0] = 1 ;
    dpb[0][0][0] = 1 ;
    for(int i = 0 ; i < S.size() ; i++){
        for(int smaller = 0 ; smaller < 2 ; smaller++){
            for(int j = 0 ; j < 2 ; j++){
                for(int x = 0 ; x <= (smaller ? 9 : A[i]) ; x++){
                    dpa[i+1][smaller || x < A[i]][j || (x == 4 || x == 9) ] += dpa[i][smaller][j] ;
                }
            }
        }
    }
    for(int i = 0 ; i < T.size() ; i++){
        for(int smaller = 0 ; smaller < 2 ; smaller++){
            for(int j = 0 ; j < 2 ; j++){
                for(int x = 0 ; x <= (smaller ? 9 : B[i]) ; x++){
                    dpb[i+1][smaller || x < B[i]][j || (x == 4 || x == 9) ] += dpb[i][smaller][j] ;
                }
            }
        }
    }
    cout << dpb[B.size()][0][1] + dpb[B.size()][1][1] - dpa[A.size()][0][1] - dpa[A.size()][1][1] << endl ;
}