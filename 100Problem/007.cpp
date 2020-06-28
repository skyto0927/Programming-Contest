
#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 1e9

bool binary_search(int N, int key, vector<int> xy){
    int ng = -1;
    int ok = N;
    while (abs(ok-ng) > 1){
        int mid = (ok+ng)/2;

        if (xy[mid] >= key){
            ok = mid;
        }else{
            ng = mid;
        }
    }
    if (key == xy[ok]){
        return true;
    }else{
        return false;
    }
}

int main() {
    int N;
    cin >> N;
    vector<pair<int, int>> xy(N);
    vector<int> coodinate(N);
    for (int i=0; i<N; i++){
        cin >> xy[i].first >> xy[i].second;
        coodinate[i] = 5000*xy[i].first + xy[i].second;
    }

    sort(coodinate.begin(), coodinate.end());

    int max_S = 0;

    for (int j=0; j<N; j++){
        for (int k=j+1; k<N; k++){
            if (j==k) continue;
            vector<int> vec(2);
            vec[0] = xy[k].first - xy[j].first;
            vec[1] = xy[k].second - xy[j].second;

            int c;
            int d;

            c = 5000*(xy[k].first - vec[1]) + xy[k].second + vec[0];

            d = 5000*(xy[j].first - vec[1]) + xy[j].second + vec[0];

            if (binary_search(N, c, coodinate)){
                if (binary_search(N, d, coodinate)){
                    int S = pow(vec[0],2) + pow(vec[1],2);
                    max_S = max(max_S, S);
                }
            }
        }
    }
    cout << max_S << endl;
    return 0;
}


