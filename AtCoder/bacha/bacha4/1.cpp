#include <bits/stdc++.h>
using namespace std ;
#define fast_input_output ios::sync_with_stdio(false); cin.tie(nullptr);
typedef long long ll ;
typedef long double ld ;
typedef pair<ll,ll> P ;
typedef tuple<ll,ll,ll> TP ;
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define bit_count(x) __builtin_popcountll(x)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a / gcd(a,b) * b
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

double EPS = 1e-10 ;
const double PI = 3.1415926535 ;

int n ;

// a > 0 : +1
// a < 0 : -1
// a = 0 :  0
int sgn(double a){
    if(a < -EPS) return -1 ;
    if(a > EPS)  return 1 ;
    return 0 ;
}
// double型の足し算は怖い
double add(double a , double b){
    if(abs(a + b) < EPS * (abs(a) + abs(b))) return 0 ;
    return a + b ;
}
// double型の == は怖い
inline bool equal(double a , double b){
    return fabs(a - b) < EPS ;
}

// 二次元ベクトル構造体
struct Point{
    double x , y ;
    Point(double x , double y) : x(x) , y(y) {}
    Point operator + (Point v) { return Point(add(x , v.x),add(y , v.y)) ;}
    Point operator - (Point v) { return Point(add(x ,-v.x),add(y ,-v.y)) ;}
    Point operator * (double d) { return Point(x * d , y * d) ;}
    Point operator / (double d) { return Point(x / d , y / d) ;}
    Point& operator += (Point v) { x = add(x , v.x) ; y = add(y , v.y) ; return *this ; }
    Point& operator -= (Point v) { x = add(x ,-v.x) ; y = add(y ,-v.y) ; return *this ; }
    Point& operator *= (double d) { x *= d ; y *= d ; return *this ; }
    Point& operator /= (double d) { x /= d ; y /= d ; return *this ; }
    bool operator == (Point v) { return equal(x,v.x) && equal(y,v.y) ; }
    bool operator != (Point v) { return !equal(x,v.x) || !equal(y,v.y) ; }
    bool operator < (Point v){
        if(sgn(x - v.x) != 0) return sgn(x - v.x) < 0 ;
        else return sgn(y - v.y) < 0 ;
    }
    // 内積演算
    double dot (Point v) { return add(x * v.x , y * v.y) ;}
    // 外積演算
    double cross (Point v) { return add(x * v.y ,-y * v.x) ;}
    // 回転
    Point rotate(double theta){ return Point(add(x * cos(theta) , -y * sin(theta)) , add(x * sin(theta) , y * cos(theta))) ; }
    // ベクトルの長さ
    double length(){ return sqrt(add(x * x , y * y)) ; }
    // ベクトルの長さの二乗
    double lengthSquare(){ return add(x * x , y * y) ; }
    // ベクトルの正規化
    Point normalized(){ return Point(x / length() , y / length()) ; }
    // ベクトルとベクトルの距離
    double distanceFrom(Point vec){ return sqrt(add((vec.x - x) * (vec.x - x) , (vec.y - y) * (vec.y - y))) ; }
    // 点かどうか
    bool isZero(){ return x == 0.0 && y == 0.0 ; }
    // 偏角演算
    double argument (Point v){
        Point u(x,y) ;
        if(u.cross(v) > 0) return acos(u.dot(v) / u.length() / v.length()) ;
        else return 2 * PI - acos(u.dot(v) / u.length() / v.length()) ;
    }
    // 出力
    void console(){ cout << setprecision(15) << x << " " << setprecision(15) << y << endl ; }
};

ld p2Line(Point a, Point b, Point p) {
  return abs((b - a).cross(p - a)) / (b - a).length();
}

ld p2Seg(Point a, Point b, Point p) {
  if ((p - a).dot(b - a) < 0.0) return (p - a).length();
  if ((p - b).dot(a - b) < 0.0) return (p - b).length();
  return p2Line(a, b, p);
}

ld x , y ;
ld X[101] , Y[101] ;

int main(){
    fast_input_output
    cin >> x >> y >> n ;
    Point point(x,y) ;
    rep(i,n) cin >> X[i] >> Y[i] ;
    ld res = 1e18 ;
    rep(i,n){
        Point a(X[i],Y[i]) ;
        Point b(X[(i+1)%n],Y[(i+1)%n]) ;
        chmin(res,p2Seg(b,a,point)) ;
    }
    cout << fixed << setprecision(25) << res << endl ;
}