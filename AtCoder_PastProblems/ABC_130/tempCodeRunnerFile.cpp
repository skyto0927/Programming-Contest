while(sum>=K){
            cout << l << " " << r << endl;
            sum -= A[l];
            l++;
            ans += N-r+1;
        }