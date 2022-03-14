#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<ll,ll> P ;
typedef tuple<ll,ll,ll,ll> TP ;
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define bit_count(x) __builtin_popcountll(x)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a / gcd(a,b) * b
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

// 座標圧縮
struct Compress{
    vector<int> vec ; // 元の値の座標圧縮後の値
    unordered_map<ll,ll> mp ; // 元の値がどの値に変換されたか
    Compress(vector<int> A){
        int n = A.size() ;
        vector<int> B ;
        set<int> st ;
        for(int i = 0 ; i < n ; i++) st.insert(A[i]) ;
        for(int u : st) B.push_back(u) ;
        // for(int i = 0 ; i < n ; i++) B[i] = A[i] ;
        vec.resize(n) ;
        for(int i = 0 ; i < n ; i++){
            auto it = lower_bound(B.begin(),B.end(),A[i]) ;
            vec[i] = it - B.begin() ;
            mp[A[i]] = it - B.begin();
        }
    }
    size_t size() {return vec.size() ; }
    inline int at(ll i) { return mp[i] ; } // 例: 341234125353 -> 6 的な
    inline int operator [] (int i) { return vec[i] ; } // 例: 5番目の値は -> 11 的な
};

int W , H , n ;
vector<TP> X ;
int T[2020][2020] ;
int U[2020][2020] ;
char S[2020][2020] ;

void f(Compress R , Compress C){
    H = C.at(H) ; W = R.at(W) ;
    rep(i,n){
        ll sx , sy , gx , gy ;
        tie(sx,sy,gx,gy) = X[i] ;
        sx = R.at(sx) ;
        gx = R.at(gx) ;
        sy = C.at(sy) ;
        gy = C.at(gy) ;
        for(int i = sy ; i < gy ; i++){
            T[i][sx]++ ;
            T[i][gx]-- ;
        }
        for(int i = sx ; i < gx ; i++){
            U[sy][i]++ ;
            U[gy][i]-- ;
        }
    }
    rep(i,H){
        int sum = 0 ;
        rep(j,W){
            sum += T[i][j] ;
            if(sum > 0) S[i][j] = '#' ;
            else S[i][j] = '.' ;
        }
    }
    rep(j,W){
        int sum = 0 ;
        rep(i,H){
            sum += U[i][j] ;
            if(sum > 0) U[i][j] = '#' ;
            else U[i][j] = '.' ;
        }
    }
}

const int dx[] = {1,-1,0,0} , dy[] = {0,0,1,-1} ;
bool used[2020][2020] ;

void bfs(int s , int t){
    queue<P> que ;
    que.push(P(s,t)) ;
    while(!que.empty()){
        P p = que.front() ; que.pop() ;
        int x = p.first , y = p.second ;
        used[x][y] = true ;
        for(int i = 0 ; i < 4 ; i++){
            int nx = x + dx[i] , ny = y + dy[i] ;
            if(0 > nx || nx >= H || 0 > ny || ny >= W || S[nx][ny] == '#') continue ;
            if(used[nx][ny]) continue ;
            used[nx][ny] = true ;
            que.push(P(nx,ny)) ;
        }
    }
}

int main(){
    cin >> W >> H >> n ;
    vector<int> h , w ;
    h.push_back(0) ;
    h.push_back(H) ;
    w.push_back(0) ;
    w.push_back(W) ;
    rep(i,n){
        int a , b , c , d ;
        cin >> a >> b >> c >> d ;
        X.push_back({a,b,c,d}) ;
        w.push_back(a) ;
        w.push_back(c) ;
        h.push_back(b) ;
        h.push_back(d) ;
    }
    Compress R(w) , C(h) ;
    f(R,C) ;
    int res = 0 ;
    rep(i,H) rep(j,W){
        if(used[i][j] || S[i][j] == '#') continue ;
        bfs(i,j) ;
        res++ ;
    }
    cout << res << endl ;
}