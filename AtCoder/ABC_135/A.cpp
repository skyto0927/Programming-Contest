#include <bits/stdc++.h>
using namespace std;

int main() {
    long int A,B;
    scanf("%ld %ld",&A,&B);
    if ((A+B)%2 == 1){
        cout << "IMPOSSIBLE";
    }else{
        cout << (A+B)/2;
    }

}

