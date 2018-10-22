#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



int main() {
    long long k = (2147483649);
    int t = (int)(k^2147483648);
    k = k>>31;
    int t1 = (int)k;
    cout<<t<<" "<<t1;
}