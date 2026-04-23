#include <iostream>
using namespace std;
#include <cmath>

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;

    int exp = 21;

    string ret = "";
    bool leading = true;
    while(exp--){
        
        char c = ((n >> exp) & 1) + '0';
        if(c == '1'){
            leading = false;
        }
        if(!leading){
         ret+=c;   
        }
        
    }

    cout << ret << '\n';

}