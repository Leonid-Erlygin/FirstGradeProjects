#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> next_pow(int pow, int m) {
    vector<int> a;
    for (int i = 2; i <= m; i++) {
        for (int j = 0; j < pow; ++j) {
            a.push_back(i);
        }
    }
    return a;

}

void fill(vector<int> &a, int m) {
    for (int i = 0; i < m; i++) {
        a[i] = i % m + 1;
    }
}

void print(vector<int> &a, int pow, int m) {
    for (int i = 0; i < pow * m; i++) {
        cout << a[i] << " ";
    }
}

int gcd(int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int main() {
    int n, m;
    cin >> n;
    cin >> m;
    vector<int> b(n);
    int dop;
    int interr = 0;
    int pow;
    for (pow = 1; interr == 0; pow++) {

        fill(b, n);
        vector<int> a = next_pow(pow, m);


        //cout << "\n\n\n";
        for (int i = 0; i < pow * m; i++) {
            for (int j = 0; j < n && a[i] != 1; j++) {
                dop = gcd(a[i], b[j]);
                a[i] /= dop;
                b[j] /= dop;
            }
            /*print(a, pow, m);
            cout << "||";
            print(b, 1, n);
            cout << "    ";
             * */
        }
        //check
        for (int i = 0; i < pow * m; i++)
            if (a[i] != 1)
                interr = 1;

    }

    cout << (pow - 2);
    return 0;
}