#include <bits/stdc++.h>
using namespace std;

int main() {
  int A,  B, C;
  cin>>A>>B>>C;

  int ans = -A+B+C;
  if(ans < 0){
    ans = 0;
  }
  cout << ans << endl;
}
