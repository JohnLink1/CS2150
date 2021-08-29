//John Link, jwl9vq@virginia.edu,  8/28/2021, xToN
#include <iostream>
using namespace std;

int xton(int a, int b) {
    if(b == 0)
        return 1;
    return xton(a, b - 1) * a;
}

int main () {
    int x;
    int y;
    int ans;
    cin >> x;
    cin >> y;
    ans = xton(x, y);
    cout << ans << endl;
    return 0;
}
