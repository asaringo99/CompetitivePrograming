#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<double,double> P ;
#define MAX_N (ll)2e5
#define YES cout << "Yes" << endl 
#define NO cout << "No" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)
#define a_z "abcdefghijklmnopqrstuvwxyz"

int n ;

int kaijo(int n){
    if(n == 1) return 1 ;
    return kaijo(n-1) * n ;
}

int main(){
    cin >> n ;
    P xy[n] ;
    for(int i = 0 ; i < n ; i++) cin >> xy[i].first >> xy[i].second ;
    sort(xy,xy+n) ;
    double sum = 0 ;
    int count = 0 ;
    int div = kaijo(n) ;
    do{
        double s = 0;
        for(int i = 1 ; i < n ; i++){
            double d = (xy[i].first - xy[i-1].first) * (xy[i].first - xy[i-1].first) + (xy[i].second - xy[i-1].second) * (xy[i].second - xy[i-1].second);
            s += sqrt(d) ;
        }
        sum += s ;
        count++ ;
    } while (next_permutation(xy,xy+n)) ;
    double res = sum / div ;
    cout << setprecision(15) << res << endl ;
}