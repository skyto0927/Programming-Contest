#include <cstdio>
using namespace std;

/*
1.本数指定
2.数値入力
3.最大周長を返す
*/

int max(int a, int b){
    if(a>=b)return a;
    return b;
}

void solve(int n, int *a){
    int max_a, len;
    int max_len = 0;
    for (int i=0; i<n; i++){
        for (int j=i+1; j<n; j++){
            for (int k=j+1; k<n; k++){
                len = a[i] + a[j] + a[k];
                max_a = max(max(a[i], a[j]), a[k]);
                if(len - max_a > max_a){
                    max_len = max(max_len, len);
                }
            }
        }
    }
    printf("%d\n", max_len);
}

int main(){
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i=0; i<n; i++){
        int x;
        scanf("%d", &x);
        a[i] = x;
    }
    solve(n, a);
    return 0;
}
