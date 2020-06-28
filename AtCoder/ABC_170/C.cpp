#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ALL(obj) (obj).begin(), (obj).end()

int main() {
  int X, N;
  cin >> X >> N;
  if (N==0){
    cout << X << endl;
    return 0;
  }
  vector<int> p(N);

  int min = 1000;
  for (int i=0; i<N; i++){
    cin >> p[i];
  }
  sort(ALL(p));
  
  int ng = -1;
  int ok = (int)p.size();

  while(abs(ok-ng) > 1){
    int mid = (ok+ng)/2;
    if(p[mid] >= X){
      ok = mid;
    }else{
      ng = mid;
    }
  }

  if (p[ok] != X){
    cout << X << endl;
    return 0;
  }else;
  int index = 1;
  int left = ok-index;
  int right = ok+index;
  while(1){

    if(ok-index<0){
      cout << X-index << endl;
      return 0;
    }else if(p[ok-index]!=X-index){
      cout << X-index << endl;
      return 0;
    }else if(ok+index>=N){
      cout << X+index << endl;
      return 0;      
    }else if(p[ok+index]!=X+index){
      cout << X+index << endl;
      return 0;
    }else{
      index++;
    }
  }
}
