/////////////////////////////////////////////////////////
//     HELLO !! THANK YOU FOR COMING TO MY PAGE !!     //
//     MY NAME IS GOZYO TARO !!                        //
//     NICE TO MEET YOU !!                             //
/////////////////////////////////////////////////////////

#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)

int n ;

int main(){
    cin >> n ;
    vector<P> X ;
    for(int i = 0 ; i < n ; i++){
        int a , b ;
        cin >> a >> b ;
        b++ ;
        X.push_back(P(a,1)) ;
        X.push_back(P(b,-1)) ;
    }
    sort(X.begin(),X.end()) ;
    int sum = 0 , res = 0 ;
    for(int i = 0 ; i < X.size() ; i++){
        sum += X[i].second ;
        res = max(res,sum) ;
    }
    cout << res << endl ;
}