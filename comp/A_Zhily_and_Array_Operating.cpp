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
        vector<long long> arr (n);
        for(int i = 0 ; i < n; i++){
            cin >> arr[i];
        }
        long long total = 0;
        if(arr[n-1] > 0)total++;

        for(int i = n-2; i>=0;i--){
            if(arr[i+1] > 0) arr[i] += arr[i+1];
            if(arr[i] > 0) total++;
        }

        cout << total << '\n';
        
    }

    return 0;
}
