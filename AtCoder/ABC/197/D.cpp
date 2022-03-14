#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define MAX_N (ll)2e5
#define YES cout << "Yes" << endl 
#define NO cout << "No" << endl 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define syosu setprecision(10)
#define a_z "abcdefghijklmnopqrstuvwxyz"
#define PI 3.14159265359

int n ;

double xz , yz , xo , yo ;

int main(){
    cin >> n >> xz >> yz >> xo >> yo ;
    double X = (xz + xo) / 2 , Y = (yz + yo) / 2 ;
    double nx = xz - X , ny = yz - Y ;
    double theta = 2 * PI / n ;
    double res_x = nx * cos(theta) - ny * sin(theta) ;
    double res_y = ny * cos(theta) + nx * sin(theta) ;
    double ans_x = res_x + X , ans_y = res_y + Y ;
    cout << setprecision(10) << ans_x << " " ;
    cout << setprecision(10) << ans_y << endl ;
}