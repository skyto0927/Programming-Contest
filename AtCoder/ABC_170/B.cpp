#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ALL(obj) (obj).begin(), (obj).end()

int main() {
  int X,Y;
  cin >> X >> Y;
  int crane, turtle;
  crane = 2*X - Y/2;
  turtle = Y/2 - X;

  if (Y%2==0 && crane>=0 && turtle>=0){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
  return 0;
}
