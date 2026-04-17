#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n;
        cin >> k;

        int n1 = n / (k * k * k + k * k + k + 1);

        int ct = 4;
        while(ct--){
            cout << n1 << ' ';
            n1 *= k;
        }
        cout << '\n';
    }
    return 0;
}