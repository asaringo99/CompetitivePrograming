#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> P ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

string S , T , U ;
bool used[2020202] ;
set<int> st , stb ;

vector<int> f(const string& s) {
    int n = s.size();
    vector<int> ret(n+1);
    ret[0] = -1;
    int j = -1;
    for (int i = 0; i < n; i++) {
        while (j >= 0 && s[i] != s[j]) j = ret[j];
        j++ ;
        ret[i+1] = j ;
    }
    return ret;
}

vector<int> g(const string& str, const string& word) {
    vector<int> vec = f(word), ret;
    int m = 0, i = 0, n = str.size();
    while (m+i < n) {
        if (word[i] == str[m+i]) {
            if (++i == (int)(word.size())) {
                ret.push_back(m);
                m = m+i-vec[i];
                i = vec[i];
            }
        }
        else {
            m = m+i-vec[i];
            if (i > 0) i = vec[i];
        }
    }
    return ret;
}

int main(){
    cin >> U >> T ;
    int t = T.size() ;
    while(S.size() < 1500000) S += U ;
    int s = S.size() ;
    vector<int> vec = g(S,T) ;
    for(int u : vec) st.insert(u) , stb.insert(u) ;
    ll res = 0 ;
    for(int u : stb){
        int k = u ;
        ll sum = 0 ;
        while(true){
            if(st.count(k) == 0) break ;
            sum++ ;
            st.erase(k) ;
            k += t ;
        }
        res = max(res,sum) ;
    }
    int maxval = 2 * S.size() / 3 / t ;
    if(maxval <= res) cout << -1 << endl ;
    else cout << res << endl ;

}