#include <iostream>
#include <vector>
using namespace std;
#define MAX1 65536
#define MAX2 6

vector<vector<int>> mem(MAX2,vector<int> (MAX1,-1)); 

int ackermann(int m ,int n){

    if(n>=MAX1){
        if(m==0) return n+1;
        if(n==0) return ackermann(m-1,1);
        return ackermann(m-1,ackermann(m,n-1));
    }
  
    if (mem[m][n] != -1){
        return mem[m][n];
    }

    int result;
    if(m == 0){
        result = n+1;
    }else if(m > 0 && n ==0){
        result = ackermann(m-1,1);
    }else {
        int mid = ackermann(m,n-1);
        result = ackermann(m-1,mid);
    }

    if(n < MAX1){
        mem[m][n]=result;
    }
    
    return result;
}

int main(){
    int T;
    cin >> T;

    for (int i = 0;i<T;i++){
        int m,n;
        cin >> m >> n; 

        cout << ackermann(m,n) << endl;

    }

    return 0;
}