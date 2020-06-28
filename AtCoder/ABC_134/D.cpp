#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    vector<int> A(N);
    vector<int> B(N);
    for(int i=0; i<N; i++){
        cin >> A[i];
    }

    int count = 0;
    for (int j=N; j>=1; j--){
        if(N/j == 1){
            B[j-1] = A[j-1];
        }else{
            int k = j;
            B[j-1] = A[j-1];
            k += j;
            while(k <= N){
                B[j-1] = B[j-1] ^ B[k-1];
                k += j;
            }
        }

        if (B[j-1] == 1){
            count ++;
        }
    }

    cout << count << endl;
    for (int j=1; j<=N; j++){
        if(B[j-1] == 1){
            printf("%d",j);
            count --;
            if (count > 0){
                printf(" ");
            }
        }
    }
    

}
