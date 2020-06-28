
#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 1e9


int main() {
    int N,K;
    cin >> N >> K;
    vector<long long int> a(N);
    vector<long long int> max_a(N);
    for (int i=0;i<N; i++){
        cin >> a[i];
        if (i==0){
            max_a[0] = a[i];
        }else{
            if(max_a[i-1]< a[i]){
                max_a[i] = a[i];
            }else{
                max_a[i] = max_a[i-1];
            }
        }

    }

    
    long long int min_cost = LLONG_MAX;

    for (int j=0; j<(1<<N); j++){
        vector<int> S;
        for (int k=0; k<N; k++){
            if (j & (1<<k)){
                S.push_back(k);
            }
        }
        if (S.size() >= K && S[0] == 0){
            long long int max_height = 0;
            long long int cost = 0;
            for (int l=0; l<S.size(); l++){
                if (l == 0){
                    max_height = a[S[0]];
                    continue;
                }
                if(max_height < max_a[S[l]]){
                    if(max_a[S[l]] > max_a[S[l]-1]){
                        max_height = max_a[S[l]];
                        continue;
                    }
                    max_height = max_a[S[l]];
                }

                if (max_height >= a[S[l]]){
                    cost += max_height - a[S[l]] +1;
                    max_height ++;
                }
                else{
                    max_height = a[S[l]];
                }


            }
            if (min_cost > cost){
                min_cost = cost;
            }
        }
    }
    cout << min_cost << endl;


    return 0;
}
