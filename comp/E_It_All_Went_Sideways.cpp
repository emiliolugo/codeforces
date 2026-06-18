#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

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

        vector<long long> arr(n);
        vector<long long> height(n);

        long long mx = 0;

        for (long long i = 0; i < n; i++) {
            cin >> arr[i];
            
            mx = max(mx, i - height[arr[i]-1]);

            for (long long j = arr[i]; j < n; j++) {
                height[j] = i+1;
            }
            
        }

        vector<long long> bl(n);
        long long blocks = 0;

        for (long long i = n - 2; i >= 0; i--) {
            bl[i] = max(0LL, (arr[i] - arr[i + 1] + bl[i + 1]));
            blocks += bl[i];
        }

        cout << blocks + mx << '\n';
        
    }

    return 0;
}
