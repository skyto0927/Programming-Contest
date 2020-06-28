#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ALL(obj) (obj).begin, (obj).end()

int main() {
  ll N, K;
  cin >> N >> K;
  vector<ll> A(N);

  ll minA = N+1;

  for (int i=0; i<N; i++){
    cin >> A[i];
  }

  while(K>0){
    minA = N+1;

    vector<ll> B(N,0);
    for (int j=0; j<N; j++){
      if (j-A[j] < 0){
        B[0]+=1;
      }else{
        B[j-A[j]] += 1;
      }

      if (j+A[j]< N-1){
        B[j+A[j]+1] -= 1;
      }
    }

    A[0] = B[0];
    minA = min(minA, A[0]);
    for (int j=1; j<N; j++){
      A[j] = A[j-1] + B[j];
      minA = min(minA, A[j]);
    }
    if (minA == N){
      for (int j=0; j<N; j++){
        cout << N << " ";
      }
      return 0;
    }
  
  K-=1;
  }



  for (int j=0; j<N; j++){
    cout << A[j] << " ";
  }
}
