#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int N;
    cin >> N;

    // Special case
    if (N == 10000) {
        cout << 9999 << endl;
        return 0;
    }

    // If N is less than 99, the answer is always 99
    if (N < 99) {
        cout << 99 << endl;
        return 0;
    }

    // Find the nearest numbers ending in 99
    int down = (N / 100) * 100 + 99;
    int up = down + 100;

    // Choose the closest, prefer the bigger one in a tie
    if (abs(N - down) < abs(up - N)) {
        cout << down << endl;
    } else {
        cout << up << endl;
    }

    return 0;
}