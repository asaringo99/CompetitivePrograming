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

string S ;

int main(){
    cin >> S ;
    int aa = (S[0] - '0') * 10 + (S[1] - '0') ;
    int bb = (S[2] - '0') * 10 + (S[3] - '0') ;
    int count = 0 ;
    if(0 < aa && aa <= 12) count++ ;
    if(0 < bb && bb <= 12) count++ ;
    if(count == 0) cout << "NA" << endl ;
    if(count == 1 && 0 < aa && aa <= 12) cout << "MMYY" << endl ;
    if(count == 1 && 0 < bb && bb <= 12) cout << "YYMM" << endl ;
    if(count == 2) cout << "AMBIGUOUS" << endl ;
}