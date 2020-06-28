#include <bits/stdc++.h>
using namespace std;

int main() {
    long int S;
    cin >> S;
    long int X2 = 1000000000;
    long int X3, Y3;
    X3 = X2 - S%X2;
    Y3 = 1 + S/X2;
    if(X3 == X2){
        X3 = 0;
        Y3 --;
    }

    cout<<"0 0 1000000000 1 "<<X3<<" "<<Y3;
}
