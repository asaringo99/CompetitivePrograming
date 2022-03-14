#include <bits/stdc++.h>
using namespace std ;
using ll = long long ;
using P = pair<int,int> ;
#define M 100005

int n ;

int main(){
    cin >> n ;
    P x[n] ;
    for(int i = 0 ; i < n ; i++) cin >> x[i].first >> x[i].second ;
    sort(x,x+n) ;
    for(int i = 0 ; i < n ; i++){
        for(int j = i + 1 ; j < n ; j++){
            double dx = x[j].first - x[i].first , dy = x[j].second - x[i].second ;
            double a = dy / dx ;
            for(int k = j + 1 ; j < n ; j++){
                double dy2 = x[k].second - x[i].second , dx2 = x[k].first - x[i].first ;
                double a2 = dy2 / dx2 ;
                if(a == a2){
                    cout << "Yes" << endl ;
                    return 0 ;
                }
            }
        }
    }
    cout << "No" << endl ;
}