#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ALL(obj) (obj).begin(), (obj).end()

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i=0; i<N; i++){
    cin >> A[i]; 
  }
  sort(ALL(A));
  int intMax = 10E6+1;
  vector<bool> hyo(intMax, true);

  for (int i=0; i<N; i++){
    if(i>0){
      if(A[i] == A[i-1]){
        hyo[A[i]] = false;
      }
    }
    if(hyo[A[i]]){
      for (int j=2; j*A[i]<=intMax; j++){
        hyo[j*A[i]] = false;
      }
    }
  }
  int count = 0;
  for(int i=0; i<N; i++){
    if(hyo[A[i]] == true) count++;
  }

  cout << count << endl;
  // int count = 0;
  // while ((int)A.size() != 0){
  //   if((int)A.size() == 1){
  //     count++;
  //   }else if(A[0] != A[1]){
  //     count++;
  //   }
  //   for (int i=(int)A.size()-1; i>=0; i--){
  //     if(A[i]%A[0] == 0){
  //       A.erase(A.begin() + i);
  //     }
  //   }
  //   //for(auto a: A){
  //   //  cout << a << " ";
  //   //}
  //   //cout <<count << endl;
  // }

  // cout << count << endl;

}
