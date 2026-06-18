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
        long long l = 0;
        long long r = 0;

        while(n--){
            char c;
            cin >> c;
            if(c == '(') l++;
            else r++;
        }

        if (l!=r){
            cout << "NO" << '\n';
        }
        else{
            cout << "YES" << '\n';
        }
        
    }

    return 0;
}
