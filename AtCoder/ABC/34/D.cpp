#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<ll,ld> P ;
typedef tuple<int,int,int> TP ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

int n, k ;
ld W[1010] , p[1010];
vector<ld> vec ;

bool f(ld x){
    vec = {} ;
    rep(i,n) vec.push_back((p[i] - x) * W[i] / 100) ;
    sort(vec.begin(),vec.end(),greater<ld>()) ;
    ld sum = 0 ;
    rep(i,k) sum += vec[i] ;
    return sum >= 0 ;
}

int main(){
    cin >> n >> k ;
    rep(i,n) cin >> W[i] >> p[i] ;
    ld lef = 0 , rig = 100 ;
    int count = 1000 ;
    while(count > 0){
        ld mid = (lef + rig) / 2 ;
        if(f(mid)) lef = mid ;
        else rig = mid ;
        count-- ;
    }
    cout << fixed << setprecision(25) << lef << endl ;
}