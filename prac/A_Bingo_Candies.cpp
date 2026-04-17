#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;              // number of test cases
    while (t--) {
        int n;
        cin >> n;
        int sq = n*n;
        int mx = n*(n-1)+1;

        std::vector<int> arr(n*n);
        char yes = 1;
        while(sq--){
            int i;
            cin >> i;
            --i;
            
            if(++arr[i] == mx){
                cout << "NO" << "\n";
                while(sq--) { int dummy; cin >> dummy; }
                yes = 0;
                break;
            }
        }
        
        if(yes){
           cout << "YES" << "\n"; 
        }
        
    }
    return 0;
}