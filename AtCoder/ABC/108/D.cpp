#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef tuple<int,int,int> TP ;
#define MAX_N (ll)2e5
#define YES cout << "Yes" << endl 
#define NO cout << "No" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)
#define a_z "abcdefghijklmnopqrstuvwxyz"
#define A_Z "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

int L ;

int main(){
    cin >> L ;
    vector<int> rem ;
    vector<TP> res ;
    int node = 1 , cost = 1 ;
    while(true){
        if(L % 2 == 1){
            rem.push_back(node) ;
        }
        L /= 2 ;
        if(L == 0){
            break ;
        }
        res.push_back({node,node+1,0}) ;
        res.push_back({node,node+1,cost}) ;
        node++ ;
        cost *= 2 ;
    }
    for(int i = 0 ; i < rem.size() - 1 ; i++){
        res.push_back({rem[i],node,cost}) ;
        cost += pow(2,rem[i]-1) ;
    }
    //res.push_back({rem[rem.size()-1],node,0}) ;
    cout << node << " " << res.size() << endl ;
    for(int i = 0 ; i < res.size() ; i++){
        int a , b , c ;
        tie(a,b,c) = res[i] ;
        cout << a << " " << b << " " << c << endl ;
    }

}