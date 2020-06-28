#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N;
    vector<char> S;
    cin >> N;

    while (N!=0){

        long long A = N%26;//Nのあまりを求める
        N/=26;//商も求める
        if (A==0) {//割り切れた場合はあまりを26とみなす
            A=26;
            N-=1;
        }

        A-=1;//0-indexに変換

        char alpha = 'a' + A;//文字コードの加算、'A'から何個先かで'Z'まで表記可能
        S.push_back(alpha);//S末尾に追加
        
    }

    for (int i=S.size()-1; i>=0; i--){//push_backしたので降順に表示
        cout << S[i];
    }
    cout << endl;
    return 0;
}