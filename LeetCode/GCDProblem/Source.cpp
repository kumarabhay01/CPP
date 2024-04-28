#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

vector<int> find_n1_n2(int t, int x, int y) {
    // Check if t is divisible by gcd(x, y)
    int gcd_xy = gcd(x, y);
    if (t % gcd_xy != 0)
        return { -1, -1 };  // Not possible to express t as n1*x + n2*y

    // Solve for n1 and n2 using Bézout's identity
    int n1 = 0, n2 = 0;
    int minV = min(x, y);
    int maxV = max(x, y);
    while (true) {
        if ((t - n1 * minV) % maxV == 0) {
            n2 = (t - n1 * minV) / maxV;
            break;
        }
        n1++;
    }

    return { n1, n2 };
}

int main() {
    int t, x, y;
    cout << "Enter t: ";
    cin >> t;
    cout << "Enter x: ";
    cin >> x;
    cout << "Enter y: ";
    cin >> y;

    vector<int> result = find_n1_n2(t, x, y);
    if (result[0] == -1)
        cout << "Not possible\n";
    else
        cout << "n1: " << result[0] << ", n2: " << result[1] << "\n";

    return 0;
}
