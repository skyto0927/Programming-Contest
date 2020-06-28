
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> H(N);
    for (int i=0; i<N; i++){
        cin >> H[i];
    }
    if (N==1){
        cout << "Yes";
    return 0;
    }
    for (int j=N-2; j>=0; j--){
        if (H[j] > H[j+1]){
            if ((H[j] - H[j+1]) == 1){
                H[j] --;
            }else{
                cout << "No";
                return 0;
            }
        }
    }
    cout << "Yes";
    return 0;
}
