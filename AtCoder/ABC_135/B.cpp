#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> p(N);
    for (int i=0; i<N; i++){
        cin >> p[i];
    }
    
    for (int i=1; i<=N; i++){
       if (i != p[i-1]){
           int k = p[i-1];
           if(p[k-1] == i){
               p[i-1] = i;
               p[k-1] = k;
               break;
           }
       }
    }
    for (int i=1; i<=N; i++){
       if (i != p[i-1]){
           cout << "NO";
           return 0;
       }
    }
    cout << "YES";
    
}