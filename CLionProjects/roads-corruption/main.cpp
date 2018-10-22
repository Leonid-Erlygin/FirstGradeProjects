#include <iostream>
#include <vector>
#include <set>

using namespace std;

class edge {
public:
    int weght;
    int toVertex;

    edge(int x, int y) {
        weght = x;
        toVertex = y;
    }
};

void heapify(vector<edge> &a, int i) {
    int l = 2 * i;
    int r = 2 * i + 1;
    int smalest = 0;
    if (l < a.size() && a[l].weght > a[i].weght) {
        smalest = l;
    } else {
        smalest = i;
    }
    if (r < a.size() && a[r].weght > a[smalest].weght) {
        smalest = r;
    }
    if (smalest != i) {
        edge c = a[i];
        a[i] = a[smalest];
        a[smalest] = c;
        heapify(a, smalest);
    }
}

void bildMaxHeap(vector<edge> &a) {
    for (int i = (a.size() - 1) / 2; i >= 0; --i) {
        heapify(a, i);
    }
}

edge extractMax(vector<edge> &a) {
    edge min = a[0];
    a[0] = a[a.size() - 1];
    a.pop_back();
    heapify(a, 0);
    return min;
}

void insert(vector<edge> &a, int value, int v) {//селать кучу масимальной
    edge t(value, v);
    a.push_back(t);
    int i = a.size() - 1;
    while (i > 0 && a[i / 2].weght < a[i].weght) {
        edge c = a[i / 2];
        a[i / 2] = a[i];
        a[i] = c;
        i = i / 2;
    }
}

int main() {
    int n, x;
    cin >> n;
    vector<vector<int>> a;
    vector<int> p;
    a.push_back(p);
    for (int i = 1; i <= n; ++i) {
        vector<int> t;
        a.push_back(t);
        a[i].push_back(0);
        for (int j = 0; j < n; ++j) {
            cin >> x;
            a[i].push_back(x);
        }
    }
    set<int> tree;
    vector<edge> heap;
    tree.insert(1);
    for (int k = 2; k <= n; ++k) {
        if (a[1][k] != 0) {
            insert(heap, a[1][k], k);
        }
    }
    int sum = 0;
    while (heap.size()!=1) {//протестить случай когда в куче один элемент
        edge o = extractMax(heap);
        if (tree.count(o.toVertex) != 1) {
            tree.insert(o.toVertex);
            for (int k = 1; k <= n; ++k) {
                if (a[o.toVertex][k] != 0) {
                    insert(heap, a[o.toVertex][k], k);
                }
            }
            sum += o.weght;
        }
    }
    /*edge o = extractMax(heap);
    sum+=o.weght;*/
    cout << sum;
    return 0;
}