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
        int n;
        cin >> n;
        if(n & 1){
            cout << "NO" << '\n';
            continue;
        }

        string a;
        string b;

        cin >> a;
        cin >> b;

        long long aopen = 0;
        long long bopen = 0;
        bool can = true;
        
        for(int i = 0; i < n; i++){
            if(a[i] == '(') aopen++;
            
            if(a[i] == ')'){
                if(aopen == 0){
                    if(a[i] == b[i]){
                        can = false;
                        break;
                    }
                    b[i] = ')';
                    a[i] = '(';
                    aopen++;
                }
                else{
                    aopen--;
                }

            }

            if(aopen > n/2){
                if(a[i] == b[i]){
                        can = false;
                        break;
                    }
                    b[i] = '(';
                    a[i] = ')';
                    aopen-=2;
            }

        }

        if(aopen != 0){
            cout << "NO" << '\n';
            continue;
        }

        for(int i = 0; i < n; i++){
            if(b[i] == '(') bopen++;
            else bopen--;
            if(bopen < 0){
                can = false;
                break;
            }
        }
       

        if(bopen) can = false;

        if(!can){
            cout << "NO" << '\n';
        }
        else{
            cout << "YES" << '\n';
        }
        
    }

    return 0;
}
