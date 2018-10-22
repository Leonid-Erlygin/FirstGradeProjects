#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int partition(vector<int> &a, int left, int right) {
    double x = a[right];
    int i = left - 1;
    for (int j = left; j < right; ++j) {
        if (a[j] <= x) {
            i++;
            int c = a[i];
            a[i] = a[j];
            a[j] = c;
        }
    }
    int c = a[i + 1];
    a[i + 1] = a[right];
    a[right] = c;
    return i + 1;
}

void quickSort(vector<int> &a, int left, int right) {
    if (left < right) {
        int q = partition(a, left, right);
        quickSort(a, left, q - 1);
        quickSort(a, q + 1, right);
    }
}

int check(vector<int> &a, int k, int x) {
    int count = 0;
    for (int i = 0; i < a.size(); ++i) {
        count += a[i] / x;
    }
    if (count < k)return -1;
    if (count > k)return 1;
    return 0;

}

int binSearch(vector<int> &a, int k) {
    int left = 1;
    int right = INT32_MAX-1;
    while (right != left) {
        int m = (left + right) / 2;
        if (check(a, k, m) == 1) {
            left = m + 1;
        } else {
            right = m;
        }
    }
    return right;
}

void arrayPrint(vector<int> &a) {
    for (int i = 0; i < a.size() - 1; ++i) {
        cout << a[i] << " ";
    }
    cout << a[a.size() - 1];
}


int main() {
    int n, k;
    vector<int> a;
    cin>>n>>k;
    int x;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        a.push_back(x);
    }

    cout<<binSearch(a,k);
}

