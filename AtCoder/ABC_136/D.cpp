#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  int s[S.size()] = {0};
  int R_count = 0;
  int L_count = 0;
  int flag = 0;
  int RtoL;
  for (int i=0; i<S.size(); i++){
    if (S[i] == 'R'){
      if (flag == 1){
        flag = 0;

        if ((R_count + L_count)%2 == 0){
          s[RtoL] = (R_count + L_count)/2;
          s[RtoL+1] = (R_count + L_count)/2;
        }else{
          int max;
          max = (R_count>L_count) ? R_count : L_count;
          if(max%2 == 0){
            if(R_count>L_count){
              s[RtoL] = (R_count + L_count)/2;
            s[RtoL+1] = (R_count + L_count)/2+1;
            }else{
              s[RtoL] = (R_count + L_count)/2+1;
            s[RtoL+1] = (R_count + L_count)/2;
            }
          }else{
              if(R_count>L_count){
              s[RtoL] = (R_count + L_count)/2+1;
            s[RtoL+1] = (R_count + L_count)/2;
            }else{
              s[RtoL] = (R_count + L_count)/2;
            s[RtoL+1] = (R_count + L_count)/2+1;
            }
          }
        }
        R_count = 0;
        L_count = 0;
      }
      R_count++;
    }
    if (S[i] == 'L'){
      L_count++;
      if (flag == 0){
        flag = 1;
        RtoL = i-1;
      }

      if (i== S.size()-1){
        if ((R_count + L_count)%2 == 0){
          s[RtoL] = (R_count + L_count)/2;
          s[RtoL+1] = (R_count + L_count)/2;
        }else{
          int max;
          max = (R_count>L_count) ? R_count : L_count;
          if(max%2 == 0){
            if(R_count>L_count){
              s[RtoL] = (R_count + L_count)/2;
            s[RtoL+1] = (R_count + L_count)/2+1;
            }else{
              s[RtoL] = (R_count + L_count)/2+1;
            s[RtoL+1] = (R_count + L_count)/2;
            }
          }else{
              if(R_count>L_count){
              s[RtoL] = (R_count + L_count)/2+1;
            s[RtoL+1] = (R_count + L_count)/2;
            }else{
              s[RtoL] = (R_count + L_count)/2;
            s[RtoL+1] = (R_count + L_count)/2+1;
            }
          }
        }
        R_count = 0;
        L_count = 0;
      }
    }

  }
  for (int i=0; i<S.size(); i++){
    cout << s[i];
    if(i!=S.size()-1){
      cout << " ";
    }
  }
}
