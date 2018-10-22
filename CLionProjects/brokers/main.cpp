#include <iostream>
#include <vector>

using namespace std;


void heapify(vector<long> &a, int i) {
    int l = 2 * i;
    int r = 2 * i + 1;
    int smalest = 0;
    if (l < a.size() && a[l] < a[i]){
        smalest = l;
    } else{
        smalest = i;
    }
    if (r<a.size() && a[r]<a[smalest]){
        smalest = r;
    }
    if (smalest != i){
        long c = a[i];
        a[i] = a[smalest];
        a[smalest] = c;
        heapify(a, smalest);
    }
}

void bildMinHeap(vector<long> &a){
    for (int i = (a.size()-1)/2; i >=0 ; --i) {
        heapify(a,i);
    }
}
long extractMin(vector<long> &a){
    long min = a[0];
    a[0] = a[a.size()-1];
    a.pop_back();
    heapify(a,0);
    return min;
}
void insert(vector<long> &a, long value){
    a.push_back(value);
    int i = a.size()-1;
    while (i > 1 && a[i/2] > a[i]){
        long c = a[i/2];
        a[i/2] = a[i];
        a[i] = c;
        i = i/2;
    }
}
int main() {
    int n;
    cin >> n;
    vector<long> c;
    int x;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        c.push_back(x);
    }
    bildMinHeap(c);

    double t = 0;
    while (c.size()!=1){
        long y = extractMin(c);
        long z = extractMin(c);
        t += (double)(z+y)/100;
        insert(c,y+z);
    }
    printf("%.2lf", t);
    return 0;
}