#include <iostream>

using namespace std;

long long ceil(long long a, long long b);
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

  
    long long m,n, a;
    cin >> m >> n >> a;
    cout << ceil(m,a) * ceil(n,a) << '\n';
    
}

long long ceil(long long a, long long b){
    return a % b == 0 ? a/b : a/b+1;
}