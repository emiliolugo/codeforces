#include <iostream>
#include<vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int q;
        cin >> q;

        std::vector<int> a(n);
        std::vector<int> b(n);

        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++) cin >> b[i];

        for(int i = n-1; i >= 0; --i){
            if(a[i] < b[i]) a[i] = b[i];
            if(i < n-1 && a[i] < a[i+1]) a[i] = a[i+1];
        }

        std::vector<int> prefix(n+1);

        prefix[0] = 0;

        for(int i = 1; i < n+1; ++i){
            prefix[i] = prefix[i-1] + a[i-1];
        }



        while(q--){
            int l,r;
            cin >> l;
            --l;
            cin >> r;
            int ret = prefix[r] - prefix[l];
            cout << ret <<  ' ';
        }
        cout << '\n';
    }
    return 0;

}