#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define MAX_N 20
#define INF INT_MAX

double calculation(double a , double b , int c){
    ll res ;
    if(c == 0) return a * b ;
    else if(c == 1) return a + b ;
    else if(c == 2) return a - b ;
    else return a / b ;
}

char S[4] = {'*' , '+' , '-' , '/'} ;

int main(){
    double A[4] ;
    cout << "Input the Number :" << endl ;
    for(int i = 0 ; i < 4 ; i++){
        cin >> A[i] ;
    }
    vector<vector<char>> res ;
    sort(A,A+4) ;
    do{
        double tmp , rmp , nmp ;
        for(int i = 0 ; i < 4 ; i++){
            tmp = calculation(A[0],A[1],i) ;
            for(int j = 0 ; j < 4 ; j++){
                rmp = calculation(tmp,A[2],j) ;
                for(int k = 0 ; k < 4 ; k++){
                    nmp = calculation(rmp,A[3],k) ;
                    //cout << A[0] << " " << S[i] << " " << A[1] << " " << S[j] << " " << A[2] << " " << S[k] << " " << A[3] << " " << nmp << endl ;
                    if(abs(nmp - 10) < 0.000001){
                        vector<char> slv ;
                        slv.push_back('{') ;
                        slv.push_back('(') ;
                        slv.push_back(A[0] + '0') ;
                        slv.push_back(S[i]) ;
                        slv.push_back(A[1] + '0') ;
                        slv.push_back(')') ;
                        slv.push_back(S[j]) ;
                        slv.push_back(A[2] + '0') ;
                        slv.push_back('}') ;
                        slv.push_back(S[k]) ;
                        slv.push_back(A[3] + '0') ;
                        res.push_back(slv) ;
                    }
                }
            }
        }
    }while(next_permutation(A,A+4)) ;
    if(res.size() == 0) cout << "No" << endl ;
    else{
        cout << "Yes" << endl ;
        for(int i = 0 ; i < res.size() ; i++){
            for(char u : res[i]) cout << u ;
            cout << endl ;
        }
    }
}