#include<iostream>
#include<vector>
#include<algorithm>
using namespace std ;


int main()
{
    int n,k,count ;
    count = 0 ;
    cin >> n >> k ;
    int A[k+1][n] ;
    int gragh[n][n] ;
    for(int i = 0 ; i < k + 1 ; i++){
        for(int j = 0 ; j < n ; j++){
            A[i][j] = 0 ;
        }
    }
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            gragh[i][j] = 'F' ;
        }
    }

    for(int i = 0 ; i < n ; i++) cin >> A[0][i] ;

    for(int i = 1 ; i < k + 1 ; i++){
        for(int j = 0 ; j < n ; j++){
            for(int m = 0 ; m < n ; m++){
                if(abs(m-j)<=A[i-1][j]){
                    if(gragh[j][m] == 'F'){
                    count = count + 1 ;
                    gragh[j][m] = 'T' ;
                    }
                }
                else continue ;
            }
            A[i][j] = A[i-1][j] + count ;
            count = 0 ; 
        }
    }
    for(int j = 0 ; j < n ; j++){
        cout << A[k][j] << " " ;
    }
    cout << "\n" ;
}
