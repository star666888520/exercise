#include <iostream>
using namespace std;

void hanoi(char x,char y,char z,int n){
    if (n == 1){
        cout <<n << ' ' << x <<' '<< y << endl;
    }else {
        hanoi(x,z,y,n-1);
        cout << n << ' ' << x <<' '<<y <<endl;
        hanoi(z,y,x,n-1); 
    }
}                                                       

int main(){
    int n;
    cin >> n;

    hanoi('A','B','C',n);

    return 0;
}


