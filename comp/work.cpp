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
        string top, bottom;

        cin >> top >> bottom;
        
        int total = 0;
        for(int i = 0; i < n; i++){
            if(top[i] == bottom[i]){
                continue;
            }

            if(i == n - 1) {
                total++;
                continue;
            } 
            array<char,2> A = {top[i],bottom[i]};
             array<char,2> B = {top[i+1],bottom[i+1]};
            if(A == B) {
                i++;
                continue;
            }
            else {
                total++;
            }
        }
        cout << total << '\n';
    }
 
    return 0;
}