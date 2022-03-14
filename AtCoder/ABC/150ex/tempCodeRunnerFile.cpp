#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<int,int> P ;
typedef tuple<int,int,int> TP ;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

// kmp をやるための前計算
vector<int> makeTable(const vector<int> s) {
    int n = s.size();
    vector<int> ret(n+1);
    ret[0] = -1;
    int j = -1;
    for (int i = 0; i < n; i++) {
        while (j >= 0 && s[i] != s[j]) j = ret[j];
        j++ ;
        if(s[i+1] == s[j]) ret[i+1] = ret[j] ;
        else ret[i+1] = j ;
    }
    return ret;
}

// str の中に word とマッチする場所のリストを返す
// ret のそれぞれの要素 el は, 「str[el] からの文字列が word と一致する」ことを示す
vector<int> kmp(const vector<int> str, const vector<int> word) {
    vector<int> table = makeTable(word), ret;
    int m = 0, i = 0, n = str.size();
    while (m+i < n) {
        if (word[i] == str[m+i]) {
            if (++i == (int)(word.size())) {
                ret.push_back(m);
                m = m+i-table[i];
                i = table[i];
            }
        }
        else {
            m = m+i-table[i];
            if (i > 0) i = table[i];
        }
    }
    return ret;
}

int n ;
int A[404040] , B[404040] ; 
vector<int> SA , SB ; 

int main(){
    cin >> n ;
    rep(i,n) cin >> A[i] ;
    rep(i,n) cin >> B[i] ;
    rep(i,n-1) A[n+i] = A[i] ;
    rep(i,n-1) B[n+i] = B[i] ;
    rep(i,2*n-2) SA.push_back(A[i+1] ^ A[i]) ;
    rep(i,n-1) SB.push_back(B[i+1] ^ B[i]) ;
    vector<int> vec = kmp(SA,SB) ;
    for(int u : vec){
        cout << u << " " << (A[u] ^ B[0]) << endl ;
    }
}