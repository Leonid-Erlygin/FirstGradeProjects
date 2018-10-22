#include <iostream>
#include <vector>
#include <cstring>
#include <stack>

using namespace std;

void sum(vector<int>&a){
   a[0] = 6;
}

int main() {
    vector<int>a;
    a.push_back(5);
    void(*fun[5])(vector<int>&);
    fun[0] = sum;
    fun[0](a);
    cout<<a[0];
    return 0;
}

/*
void printMatrix(vector<vector<char>> &a) {
    for (int i = 0; i < a.size(); ++i) {
        for (int j = 0; j < a[i].size(); ++j) {
            putchar(a[i][j]);
        }
        cout << '\n';
    }
}

class element {
public:
    int i;
    int j;
    int color;

    element(int x, int y, int c) {
        i = x;
        j = y;
        color = c;
    }
};

void dfs(vector<vector<char>> &a, int i, int j, int paint, int **b) {//сделать через цикл

    element t0(i, j, paint);
    stack<element> stack;
    stack.push(t0);
    while (!stack.empty()) {

        element x = stack.top();
        stack.pop();
        b[x.i][x.j] = paint;
        if (x.i + 1 < a.size() && a[x.i + 1][x.j] == '+' && b[x.i + 1][x.j] < 0) {
            element y(x.i + 1, x.j, paint);
            stack.push(y);
        }
        if (x.j + 1 < a.size() && a[x.i][x.j + 1] == '+' && b[x.i][x.j + 1] < 0) {
            element y(x.i, x.j + 1, paint);
            stack.push(y);
        }
        if (x.j - 1 >= 0 && a[x.i][x.j - 1] == '+' && b[x.i][x.j - 1] < 0) {
            element y(x.i, x.j - 1, paint);
            stack.push(y);
        }
        if (x.i - 1 >= 0 && a[x.i - 1][x.j] == '+' && b[x.i - 1][x.j] < 0) {
            element y(x.i - 1, x.j, paint);
            stack.push(y);
        }
    }
}

int main() {
    int n, m;
    cin >> n;
    cin >> m;
    vector<vector<char>> a(n);
    for (int i = 0; i < n; ++i) {

        for (int j = 0; j < m; ++j) {
            char c;
            cin >> c;
            a[i].push_back(c);
        }
    }
    int paint = 0;
    int **b = (int **) malloc(n * sizeof(int *));
    for (int l = 0; l < n; ++l) {
        b[l] = (int *) calloc(m, sizeof(int));
    }

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < m; ++i) {
            b[k][i] = -1;
        }
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < m; ++i) {
            if (a[k][i] == '.') {
                b[k][i] = 0;
            } else {
                if (b[k][i] < 0) {
                    paint++;
                    dfs(a, k, i, paint, b);
                }
            }
        }
    }
    /*for (int k = 0; k < n; ++k) {
        for (int i = 0; i < m; ++i) {
            cout << b[k][i] << " ";
        }
        cout << '\n';
    }
    int j = -2;
    for (int y = n - 1; y >= 0; --y) {
        for (int i = m - 1; i >= 0; --i) {
            if (b[y][i] > j)j = b[y][i];
        }
    }
    cout << j;
    //printMatrix(a);
    return 0;
}
*/