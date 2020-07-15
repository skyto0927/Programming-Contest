
#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 1e9

bool binary_search(int N, int key, vector<int> xy){
    int ng = -1;
    int ok = N;
    while (abs(ok-ng) > 1){
        int mid = (ok+ng)/2;

        if (xy[mid] >= key){
            ok = mid;
        }else{
            ng = mid;
        }
    }
    if (key == xy[ok]){
        return true;
    }else{
        return false;
    }
}

int main() {
    int N;
    cin >> N;
    vector<long long int> A(N);
    vector<long long int> B(N);
    long long int distance;
    for (int i=0; i<N; i++){
        cin >> A[i] >> B[i];
        distance += B[i] - A[i];
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    long long int mid_A = A[N/2];
    long long int mid_B = B[N/2];
    for (int i=0; i<N; i++){
        distance += abs(A[i]-mid_A);
        distance += abs(B[i]-mid_B);
    }
    cout << distance << endl;


    return 0;
}


