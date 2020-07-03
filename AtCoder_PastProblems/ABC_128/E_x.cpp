#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


struct Event{
    ll time,type,d;
    bool operator<(const Event& a){
        return time < a.time;
    }
};

int main() {
    ll N,Q;
    cin >> N >> Q;
    vector<Event> X;
    REP(i,N){
        ll s,t,x;
        cin >> s >> t >> x;
        X.push_back({s-x,1,x});//add
        X.push_back({t-x,-1,x});//remove
    }

    vector<ll> D(Q);

    
    REP(i,Q){
        cin >> D[i];
    }
    sort(ALL(X));

    int k=0;
    multiset<ll> S;

    REP(i,Q){
        while(k < X.size() && X[k].time <= D[i]){
            if(X[k].type == 1){
                S.insert(X[k].d);
            }else{
                S.erase(S.find(X[k].d));
            }
            k++;
        }

        if(S.empty()){
            cout << -1 << endl;
        }else{
            cout << *S.begin() << endl;
        }
    }
    return 0;
}

//イベントソートなるものを使う
