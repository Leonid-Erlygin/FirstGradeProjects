#include <iostream>
#include <vector>

using namespace std;

class edg {
public:
    int v1;
    int v2;
    int weigth;
    int smokeProgress;
    int speleologsProgress;

    edg(int x, int y, int z, int a, int b) {
        v1 = x;
        v2 = y;
        weigth = z;
        smokeProgress = a;
        speleologsProgress = b;
    }
};

class vertex {
public:
    bool isSmoked;
    bool speleologs;
    int time;

    vertex() {
        isSmoked = false;
        speleologs = false;
        time = -1;

    }
};

bool relax(edg &e, vector<vertex> &v) {
    //начало из v1 в v2
    bool live = false;
    if (v[e.v1].speleologs && !v[e.v2].speleologs && e.speleologsProgress != e.weigth) {
        e.speleologsProgress++;
        live = true;
        if (e.speleologsProgress == e.weigth && !v[e.v2].isSmoked) {
            v[e.v2].speleologs = true;
            v[e.v2].time = v[e.v1].time + e.weigth;
        }
    }
    //начало в другую сторону
    if (v[e.v2].speleologs && !v[e.v1].speleologs && e.speleologsProgress != e.weigth) {
        e.speleologsProgress++;
        live = true;
        if (e.speleologsProgress == e.weigth && !v[e.v1].isSmoked) {
            v[e.v1].speleologs = true;
            v[e.v1].time = v[e.v2].time + e.weigth;
        }
    }
    if (v[e.v1].isSmoked && !v[e.v2].isSmoked) {
        e.smokeProgress++;
        if (e.smokeProgress == e.weigth) {
            v[e.v2].isSmoked = true;
        }
    }
    if (v[e.v2].isSmoked && !v[e.v1].isSmoked) {
        e.smokeProgress++;
        if (e.smokeProgress == e.weigth) {
            v[e.v1].isSmoked = true;
        }
    }
    return live;


}

int main() {
    int n, m, k;
    cin >> n;
    cin >> m;
    cin >> k;
    vector<int> fire(k + 1);
    int x;
    for (int i = 1; i <= k; ++i) {
        cin >> x;
        fire[i] = x;
    }
    vector<edg> edge;
    int y, z;
    for (int j = 0; j < m; ++j) {
        cin >> x;
        cin >> y;
        cin >> z;
        edg t(x, y, z, 0, 0);
        edge.push_back(t);
    }
    vector<vertex> vertices(n + 1);
    for (int l = 1; l <= k; ++l) {
        vertices[fire[l]].isSmoked = true;
    }
    int s, f;
    cin >> s;
    cin >> f;
    vertices[s].time = 0;
    vertices[s].speleologs = true;
    bool someoneAlive = true;
    while (someoneAlive && vertices[f].time == -1) {
        someoneAlive = false;
        for (int i = 0; i < m; ++i) {
            if(relax(edge[i], vertices) == true){
                someoneAlive = true;
            };
        }
    }
    cout << vertices[f].time;
    return 0;
}