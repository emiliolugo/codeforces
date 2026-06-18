#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#include <unordered_set>

void solve() {
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        vector<long long> arr (n);
        
        long long big = -1;
        for(int i = 0 ; i < n; i++){
            cin >> arr[i];
            big = max(big,arr[i]);
        }
        sort(arr.begin(),arr.end());
        

        long long sum = big;
        if(big == 0) {
            cout << n << '\n';
            continue;
        }


        vector<bool> mex(big + 2, false);
        mex[big] = true;
        long long currmex = 0;

        for (int i = 0; i < n - 1; i++) {
            sum += big;
            mex[arr[i]] = true;
            while (mex[currmex]) currmex++;
            sum += currmex;
        }

        cout << sum << '\n';
        

            
    }

    return 0;
}
