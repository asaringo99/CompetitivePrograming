#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)

int n ;
vector<P> lef , rig ;

ll f(vector<P> X){
    ll sum = 0 ;
    rep(i,X.size()){
        ll down = X[i].first , pls = X[i].second ;
        if(sum - down < 0) return -1 ;
        sum += pls ;
    }
    return sum ;
}

int main(){
    cin >> n ;
    rep(i,n){
        string S  ;
        cin >> S ;
        ll sum = 0 , down = 0 ;
        for(char u : S){
            if(u == '(') sum++ ;
            if(u == ')') sum-- ;
            down = min(down,sum) ;
        }
        if(sum > 0) lef.push_back(P(abs(down),sum)) ;
        else{
            down = 0 , sum = 0 ;
            reverse(S.begin(),S.end()) ;
            for(char u : S){
                if(u == ')') sum++ ;
                if(u == '(') sum-- ;
                down = min(down,sum) ;
            }
            rig.push_back(P(abs(down),sum)) ;
        }
    }
    sort(lef.begin(),lef.end()) ;
    sort(rig.begin(),rig.end()) ;
    ll l = f(lef) , r = f(rig) ;
    if(l == -1 || r == -1 || l != r) cout << "No" << endl ;
    else cout << "Yes" << endl ;
}