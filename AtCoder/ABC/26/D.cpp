#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

const double pi = 3.1415926535 ;
const double eps = 1e-10 ;

double a , b , c ;

int main(){
    cin >> a >> b >> c ;
    if(a > b * c * pi){
        double lef = 0 , rig = 1e18 ;
        int count = 0 ;
        while(count < 10000){
            double mid = (lef + rig) / 2 ;
            if(a*mid+b*sin(c*mid*pi) >= 100) rig = mid ;
            else lef = mid ;
            count++ ;
        }
        cout << setprecision(15) << lef << endl ;
    }
    else{
        double y = - a / (b * c * pi) ;
        double theta = acos(y) ;
        theta = theta / c / pi ;
        double mag = 2 / c - 2 * theta ;
        double lef = (theta + mag - 2 / c) ;
        double rig = theta ;
        while(b * sin(c*rig*pi) + a*rig < 100) {
            rig += (2 / c) ;
            lef += (2 / c) ;
        }
        int count = 0 ;
        while(count < 10000){
            double mid = (lef + rig) / 2 ;
            if(a*mid+b*sin(c*mid*pi) >= 100) rig = mid ;
            else lef = mid ;
            count++ ;
        }
        cout << setprecision(15) << lef << endl ;
    }
}