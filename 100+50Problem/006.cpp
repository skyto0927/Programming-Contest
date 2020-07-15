
#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 1e9


int main() {
    int N;
    cin >> N;
    string s;
    vector<int> S(N);
    cin >> s;
    for (int i=0; i<N; i++){
        S[i] = s[i]-'0';
    }
    

    if (N< 1){
        cout << 0 << endl;
    }
    else if (N>=1 && N<3){
        cout << 1 << endl;
    }
    else{
        int count = 0;
        for (int i=0; i<1000; i++){
            int num[3] = {(i/100)%10, (i/10)%10, i%10};
            int check = 0;
            for (int j=0; j<N; j++){
                if (S[j] == num[check]){
                    check++;
                }
                if(check == 3)break;
            }
            if(check == 3)count++;
        }
        cout << count << endl;
    }

    return 0;
}
