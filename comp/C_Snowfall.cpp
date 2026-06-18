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
        vector<int> arr(n);
        vector<int> ret(n);
        
        long long tmp = n;
        

        for(int i = 0; i < n; i++){
            cin >> arr[i];
            ret[i] = -1;
        }
        int sixes = 0;
        for(int i = 0; i < n; i++){
            if(arr[i] % 6 == 0){
                ret[sixes] = arr[i];
                sixes++;
                arr[i] = -7;
            }
        }

        
        for(int i = 0; i < n; i++){
            if(arr[i] % 3 == 0){
                ret[sixes] = arr[i];
                sixes+=1;
                arr[i] = -7;
            }
        }

        for(int i = 0; i < n; i++){
            if(arr[i] & 1 && arr[i] > 0){
                ret[sixes] = arr[i];
                sixes+=1;
                arr[i] = -7;
            }
        }

        sixes = 0;

        for(int i = 0; i < n; i++){
            while(sixes < n && ret[sixes] != -1)sixes++;
            if(arr[i] == -7) continue;
                ret[sixes++] = arr[i];
        }
        

        for(int i = 0; i < n; i++){
            cout << ret[i];
            if(i < n-1){
                cout << " ";
            }
        }
        cout << '\n';

        
    }

    return 0;
}
