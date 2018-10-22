#include <iostream>
#include <cmath>
#include <vector>

using namespace std;


bool isPrime(int x,vector<bool>&a) {
    return a[x];
}

int main() {
    int m, n;
    cin >> m;
    cin >> n;
    vector<bool> a(20000001, true);
    a[1] = false;
    for (int k = 2; k * k <= 20000001; k++) {

        if (a[k] == true)
            for (int l = k * k; l <= 20000001; l += k) {
                a[l] = false;
            }
    }


    int count = 1;
    for (int i = 3; i <= n + 1; ++i) {
        if (isPrime(i,a))count++;
    }
    int r = n + 1;
    int l = 2;
    if (count == m || count < m) {
        if (count == m) { cout << 2; }
        else {
            while (isPrime(r++,a)) {
                count++;
            }
            if (count != m)cout << -1;
        }
    } else {

        while (count != m && l <= 20000000) {
            r++;
            if (isPrime(r,a))count++;
            if (isPrime(l,a))count--;
            l++;

        }
        if (count != m) { cout << -1; }
        else {
            cout << l;
        }
    }
    return 0;
}