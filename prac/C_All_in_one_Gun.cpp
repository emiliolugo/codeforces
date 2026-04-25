#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long t;
    cin >> t;

    while(t--){
        long long n, totalh, k;
        cin >> n >> totalh >> k;
        long long sum = 0;
        
        vector<long long> arr(n);
        vector<long long> small(n);
        vector<long long> big(n);

        for(long long i = 0; i < n; i++){
            cin >> arr[i];
            sum += arr[i];
            if(i == 0) small[i] = arr[i];
            else small[i] = min(arr[i], small[i-1]);
        }
        if(totalh % sum == 0){
            long long mult = totalh/sum;
            cout << mult * n + (mult-1) * k << '\n';
            continue;
        }
        long long h = totalh % sum;
        big[n-1] = arr[n-1];
        for(long long i = n-2; i >= 0; i--){
            big[i] = max(arr[i], big[i+1]);
        }

        long long sec = 0;
        long long curr = 0;
        for(long long i = 0; i < n; i++){
           curr += arr[i];
           
           
           long long poss = curr;
           if(i+1 < n && small[i] < big[i+1]){
            poss -= small[i];
            poss += big[i+1];
           }

           if(poss >= h){
                sec = i+1;
                break;
           }
        }
       
        long long full_iters = totalh/sum;
        long long total = sec + full_iters * n + full_iters * k;
        
        cout << total << '\n';


    }

    


}