#define ll long long
#define fast ios::sync_with_stdio(false); cin.tie(NULL);
#include <iostream>
#include <map>

using namespace std;

int main(){
    fast;

    int t;
    cin >> t;
    while(t--){
        map<int, int> mp;
        int n;
        cin >> n;
        
        while(n--){
            int curr;
            cin >> curr;
            mp[curr]++;
        }

        int prev_key = -1;
        int poss = 4;
        bool can = false;
        for(auto [key,value]: mp){
            if(key - prev_key > 1){
                poss = 4;
            }

            prev_key = key;

            if(value >= 4){
                can = true;
                break;
            }
            
            if(value >= 2){
                if(poss <= 2){
                    can = true;
                    break;
                }
                poss = 2;
                continue;
            }
            

        }

        cout << (can ? "Yes":"No") << '\n';
    }
   



    return 0;
}