#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ALL(obj) (obj).begin(), (obj).end()

int main() {
  vector<multiset<int>> school(2*10e5+1);//1-indexed
  int N, Q;
  cin >> N >> Q;

  vector<vector<int>> number(N+1, vector<int>(2));//1-indexed
  for (int i=1; i<=N; i++){
    int A,B;
    cin >> A >> B;
    school[B].insert(A);
    number[i][0] = B;
    number[i][1] = A; // {園児のID}{園児のいる場所、レート}
  }

  multiset<int> saikyo;

  for (int i=1; i<=2*10e5; i++){
    if(!school[i].empty()){
      saikyo.insert(*school[i].rbegin());
    }
  }

  vector<vector<int>> CD(Q,vector<int>(2));
  for (int i=0; i<Q; i++){
    cin >> CD[i][0] >> CD[i][1]; //{園児のID、園児の移動先} 0-indexed
  }


  for (int i=0; i<Q; i++){
    int beforePlace = number[CD[i][0]][0]; //元いた場所

    saikyo.erase(saikyo.find(*school[beforePlace].rbegin() )); //の最強レートを削除

    school[beforePlace].erase(school[beforePlace].find(number[CD[i][0]][1] ));//園児を削除

    if (!school[beforePlace].empty()){
      saikyo.insert(*school[beforePlace].rbegin()); //新しい最強レートを挿入
    }
  
    int afterPlace = CD[i][1];//次に入る場所

    if (!school[afterPlace].empty()){
      saikyo.erase(saikyo.find(*school[afterPlace].rbegin() )); //の最強レートを削除
    }
    

    school[afterPlace].insert(number[CD[i][0]][1]);//園児を挿入

    saikyo.insert(*school[afterPlace].rbegin()); //新しい最強レートを挿入

    number[CD[i][0]][0] = CD[i][1];//園児のいる場所更新

    cout << *saikyo.begin() << endl;
  }
}
