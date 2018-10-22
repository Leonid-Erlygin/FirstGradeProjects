#include <iostream>
#include <map>
#include <vector>

using namespace std;


void initilaze(vector<vector<int>> &g, int cn) {
    for (int i = 1; i < g.size(); ++i) {
        for (int j = 0; j < g[i].size(); ++j) {
            g[i][j] = 1;
        }
    }
    for (int k = 0; k < g[cn].size(); ++k) {
        g[cn][k] = 0;
    }
}

class edje {
public:
    int v1;
    int v2;
    int c;

    edje(int x, int y, int company) {
        v1 = x;
        v2 = y;
        c = company;
    }
};

void relax(edje e, vector<vector<int>> &g) {
    for (int i = 1; i < g[0].size(); ++i) {
        if (g[e.v1][i] == 0 && e.c != i) {
            g[e.v2][i] = 0;
        }
        if(g[e.v2][i] == 0 && e.c != i){
            g[e.v1][i] = 0;
        }
    }
}

int main() {
    int n, m, c;
    cin >> n;
    cin >> m;
    cin >> c;
    vector<vector<int>> g(n + 1, vector<int>(c + 1));
    vector<edje> e;
    int x, y, z;
    for (int i = 0; i < m; ++i) {
        cin >> x;
        cin >> y;
        cin >> z;
        edje t(x, y, z);
        e.push_back(t);
    }
    int cn, cs;
    cin >> cn;
    cin >> cs;
    initilaze(g, cn);
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < m; ++j) {
            relax(e[j], g);
        }
    }
    int t = 0;
    for (int l = 1; l < c + 1 ; ++l) {
        if(g[cs][l] == 0){
            t++;
        }
    }
    cout<<t<<'\n';
    for (int k = 1; k < c + 1; ++k) {
        if(g[cs][k] == 0){
            cout << k<<" ";
        }
    }
    return 0;
}