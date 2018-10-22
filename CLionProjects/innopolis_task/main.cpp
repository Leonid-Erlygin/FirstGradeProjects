#include <iostream>
#include <vector>


using namespace std;


vector<vector<int>> res;

vector<int> insert(int pos, int val, vector<int> &a) {
    vector<int>t(val);
    for (int i = 0; i <pos-1; ++i) {
        t[i] = a[i];
    }
    t[pos-1] = val;
    for (int j = pos; j <val; ++j) {
        t[j] = a[j-1];
    }
    return t;
}

void f(int n) {
    if (n == 1) {
        vector<int> t;
        t.push_back(1);
        res.push_back(t);
        return;
    }
    f(n - 1);
    long x = res.size();
    for (int i = 0; i < x; ++i) {
        for (int j = 1; j <=n; ++j) {
            vector<int> a = res.back();
            res.insert(res.begin(),insert(j,n,a));
        }
        res.pop_back();
    }
}

int main() {

    string year, month, day;
    /*cin >> year;
    cin >> month;
    cin >> day;*/
    f(7);
    for (int i = 0; i <res.size(); ++i) {
        for (int j = 0; j <7; ++j) {
            cout<<res[i][j];

        }
        cout<<'\n';
    }

    return 0;
}