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
    while(t--){
        long long n;
        cin >> n;

        vector<int> arr(2*n);
        vector<int> seen;
        vector<int> maxlen;

        for(int i = 0; i < 2*n;i++){
            cin >> arr[i];
        }
        
        long long maxlength = 0;
        int l = 0, r = 0;
        int mex = 0;
        for(int i = 0; i < 2*n;i++){
            l= i, r = i;
            while(l >= 0 && r < 2*n && arr[l] == arr[r]){
                if(r- l + 1 > maxlength){
                    int mid = (l + r) / 2;
                    maxlen.assign(arr.begin() + l, arr.begin()+mid);
                    maxlength = r- l + 1;
                }
                l--;
                r++;
            }
            l= i, r = i+1;
            while(l >= 0 && r < 2*n && arr[l] == arr[r]){
                if(r- l + 1 > maxlength){
                    int mid = (l + r) / 2;
                     maxlen.assign(arr.begin() + l, arr.begin()+mid);
                     maxlength = r- l + 1;
                }
                l--;
                r++;
            }
        }  
        int ml = maxlen.size();

        

        sort(maxlen.begin(), maxlen.end());

        for(int i =1; i < ml;i++){
            cout << maxlen[i] << " ";
        }
        for(int i =1; i < ml;i++){
                cout << maxlen[i] << " \n";
            }
        

        if(ml == 0 || maxlen[0] >= 1){
            cout << 1 << " \n";
            continue;
        }
        
        for(int i =1; i < ml;i++){
            if(maxlen[i] >= maxlen[i-1]+1){
                cout << maxlen[i-1] << " \n";
                break;
            }
        }

    }

    return 0;
}
