#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 1e9

int main() {
    long long N;
    cin >> N;

    vector<pair<long long, long long>> p;

    for (long long i=2; i*i<=N; i++){
        if(N%i != 0)continue;

        long long e = 0;

        while (N%i == 0){
            e++;
            N /= i;
        }
        p.push_back({i, e});
    }
    if (N!=1){
        p.push_back({N,1});
    }

    int count = 0;
    for (long long j=0; j<p.size(); j++){
        int ex = p[j].second;
        int counter = 1;
        while (ex >= counter){
            ex -= counter;
            count ++;
            counter ++;

        }
    }

    cout << count << endl;
    return 0;
}
