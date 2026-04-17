#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while(t--){
        int end;
        cin >> end;
        int it = 0;
        int ret = 0;
        while(end--){
            int curr;
            cin >> curr;
            ret+= ++it >= curr;
        }

        cout << ret << '\n';
    }


}