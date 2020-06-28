#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ALL(obj) (obj).begin, (obj).end()

int main() {
  ll A,B,V,W,T;
  cin >> A >> V;
  cin >> B >> W;
  cin >> T;
  if (V <= W) {
    cout << "NO" << endl;
    return 0;
  }else{
    ll d = abs(A-B);
    ll vel = V-W;
    if (d <= T * vel){
      cout << "YES" << endl;
      return 0;
    }
    
  }
  cout << "NO" << endl;
  return 0;
}
