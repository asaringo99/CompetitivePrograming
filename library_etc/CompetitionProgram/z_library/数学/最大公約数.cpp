#include <bits/stdc++.h>
using namespace std ;
using ll = long long ;
#define MAX_N (ll)1e8+7

int gcd(int a ,int b){
    if(b == 0) return a ;
    return gcd(b,a%b) ;
}

int extgcd(int a , int b , int& x , int& y){
    int d = a ;
    if(b == 0){
        x = 1 ; y = 0 ;
    }
    else{
        d = extgcd(b , a % b , y , x) ;
        y -=  (a / b) * x ;
    }
    return d ;
}