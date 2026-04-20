#include <iostream>
#include <queue>
#include <iomanip>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, l;
    cin >> n >> l;

    std::priority_queue<int> pq;

    while(n--){
        int curr;
        cin >> curr;
        pq.push(-1 * curr);

    }

    int curr = -pq.top();
    double maxdist = curr;
    pq.pop();
    int next;
    while(!pq.empty()){
        next = -pq.top();
        pq.pop();
        long double currdist = (long double)(next-curr) / 2.0;
        maxdist = currdist > maxdist ? currdist: maxdist;
        curr = next;
    }

    maxdist = max(maxdist, (double)(l-curr));
      cout << fixed << setprecision(10) << maxdist << '\n';
}