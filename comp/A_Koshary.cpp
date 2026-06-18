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
        long long x,y;
        cin >> x >> y;
        if((x & 1) && (y&1)){
            cout << "NO";
        }
        else{
            cout << "YES";
        }
        cout << '\n';
    }

    return 0;
}
