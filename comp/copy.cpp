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
        long long b = y/x;
       
        bool can = false;
        for(long long i = 1; i < b; i++){
            if(b % i != 0){
                can = true;
                break;
            }
        }
        if(can){
            cout << "YES" << '\n';
        }
        else{
            cout << "NO" << '\n';
        }
    }

    return 0;
}
