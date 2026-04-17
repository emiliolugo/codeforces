#include <iostream>


using namespace std;

int gcd(int a, int b);
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while(t--){
        int x,y,z,m;
        cin >>x;
        cin >> y;
        cin >> z;
        cin >> m;

        int xy = x / gcd(x,y) * y;
        int yz = y / gcd(y,z) * z;
        int xz = x / gcd(x,z) * z;
        int xyz = xy / gcd(xy,z) * z;

        int retx = 6 * m / (x) - 3 * m/xy - 3 * m/xz + 2 * m/xyz;

        cout << retx << '\n';

    }
}

int gcd(int a, int b){
    if(a < b) return gcd(b, a);

    int r;
    do{
        int q = a / b;
        r = a - b * q;
        a = b;
        b = r;
    } while(r != 0);

    return a;
}