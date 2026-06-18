#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
       int n;
       cin >> n;

       priority_queue<int> maxHeap;
       vector<int> arr(n);

       for(int i = 0; i < n; i++){
        int c;
        cin >> c;
        arr[i] = c;
        maxHeap.push(c);
       }

       for(int i = 0; i < n/2; i++){
        maxHeap.pop();
       }

       int median = maxHeap.top();

       long long counter = 0;

       int balance = 0;
       
       int l = 0;
       bool found = false;
       for(int i = 0; i < n; i++){

            if(arr[i] < median){
                balance-=1;
            }
            else if(arr[i] > median){
                balance+=1;
            }
            else if(!found){
                found = true;
            }
            else{
                if(balance < 0) balance++;
                else balance--;
            }

            if(balance == 0 && found){
                counter+=1;
                found = false;
            }
            
       }

       cout << counter << '\n';


    }

    return 0;
}
