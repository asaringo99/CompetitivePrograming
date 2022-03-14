#include <bits/stdc++.h>
using namespace std ;
using ll = long long ;
#define MAX_V 205
#define INFO 100007


int main(){
  vector<int> a ;

    vector<int> v{ 1, 2, 3 }; //要素は昇順にソートしておく
    
    for( int i = 0; i < 6; ++i )
    {
        for( auto &x : v )
        {
            cout << x << " ";
        }
        cout << endl;
        next_permutation( begin( v ), end( v ) ); //次の順列が生成される
    }
}