#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin>>N;

  if(N<10){
    cout<<N<<endl;
    return 0;
  }
  if(10<=N && N<100){
    cout<<9<<endl;
    return 0;
  }
  if(100<=N && N<1000){
    cout<<9+N-99<<endl;
    return 0;
  }
  if(1000<=N && N<10000){
    cout<<909<<endl;
    return 0;
  }
  if(10000<=N && N<100000){
    cout<<909+N-9999<<endl;
    return 0;
  }
  if(N=100000){
    cout<<90909<<endl;
    return 0;
  }
}
