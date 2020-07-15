#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 1e9

int main() {
    string S;
    cin >> S;
    int count=0;
    int max=0;
    bool flag = false;
    for (int i=0; i<S.size(); i++){
        if (S[i]=='A' || S[i]=='C' || S[i]=='G' || S[i]=='T'){
            flag = true;
            count++;
        }
        else{
            flag = false;
            if(max < count){
                max = count;
            }
            count = 0;
        }

    }
    if(max < count){
                max = count;
    }
    cout << max << endl;

}
