#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;

int main() {
    int N,M;
    cin >> N >> M;
    vector<pair <int, int>> p; 
    for (int i=0; i<M; i++){
        int x,y;
        cin >> x >> y;
        p.push_back(make_pair(x-1,y-1));
    }
    
    sort(ALL(p));


    if(N==1 || M==0){
        cout << 1 << endl;
        return 0;
    }
    int maxSize = 0;
    for (int bit=0; bit<(1<<N); bit++){
        vector<int> S;
        for (int i=0; i<N; i++){
            if (bit & (1<<i)){
                S.push_back(i);
            }
        }

        if(S.size() <= 1)continue;

        bool check = true;
        for (int i=0;i<S.size()-1; i++){
            for (int j=i+1; j<S.size(); j++){
                bool flag = false;
                for (int k=0; k<M; k++){
                    if(S[i]==p[k].first && S[j]==p[k].second){
                        flag = true;
                    }
                }
                if(!flag){
                    check = false;
                    break;
                }
            }
            if(!check)break;
        }

        if (check){
            maxSize = max(maxSize, (int)S.size());
        }
    }

    cout << maxSize << endl;




    return 0;
}
