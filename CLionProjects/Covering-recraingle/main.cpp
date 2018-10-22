#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class dot {
public:
    int x;
    int y;
    double angle;

    dot() {
        this->x = 0;
        this->y = 0;
        this->angle = 0;
    }

    dot(int x, int y) {
        this->x = x;
        this->y = y;
    }
};

int partition(vector<dot> &a, int left, int right) {
    double x = a[right].angle;
    int i = left - 1;
    for (int j = left; j < right; ++j) {
        if (a[j].angle > x) {
            i++;
            double ang = a[i].angle;
            int x = a[i].x;
            int y = a[i].y;
            a[i].x = a[j].x;
            a[i].y = a[j].y;
            a[i].angle = a[j].angle;
            a[j].x = x;
            a[j].y = y;
            a[j].angle = ang;
        }
    }
    double c = a[i + 1].angle;
    int c1 = a[i + 1].x;
    int c2 = a[i + 1].y;

    a[i + 1].x = a[right].x;
    a[i + 1].y = a[right].y;
    a[i + 1].angle = a[right].angle;
    a[right].angle = c;
    a[right].x = c1;
    a[right].y = c2;
    return i + 1;
}

void quickSort(vector<dot> &a, int left, int right) {
    if (left < right) {
        int q = partition(a, left, right);
        quickSort(a, left, q - 1);
        quickSort(a, q + 1, right);
    }
}

bool isTurnLeft(dot &p1, dot &p2, dot &p0) {
    if (((p1.x - p0.x) * (p2.y - p0.y) - (p1.y - p0.y) * (p2.x - p0.x)) > 0)return true;
    return false;
}

void printDots(vector<dot> &a) {
    for (int i = 0; i < a.size(); ++i) {
        cout << a[i].x << " " << a[i].y << '\n';
    }
}

double modul(double x, double y) {
    return sqrt(x * x + y * y);
}

vector<dot> greaghamScan(vector<dot> &a) {
    vector<dot> s;
    s.push_back(a[0]);
    s.push_back(a[1]);
    s.push_back(a[2]);
    for (int i = 3; i < a.size(); ++i) {
        while (!isTurnLeft(s[s.size() - 1], a[i], s[s.size() - 2])) {
            s.pop_back();
        }
        s.push_back(a[i]);
    }
    return s;
}

double findAngle(dot &a, dot &b) {//возвращает косинус угла между векторами
    double t = (modul(a.x, a.y) * modul(b.x, b.y));
    double k = (a.x * b.x + a.y * b.y);

    return k / t;
}

double max(double x, double y) {
    return x < y ? y : x;
}

int main() {
    vector<dot> a;
    int n;
    cin >> n;
    int y, x;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        cin >> y;
        dot k(x, y);
        a.push_back(k);
    }
    dot min(10001, 10001);
    int i = 0;
    //поиск нижнего
    for (int j = 0; j < a.size(); ++j) {
        if (a[j].y < min.y) {
            min.x = a[j].x;
            min.y = a[j].y;
            i = j;
        }
        if (a[j].y == min.y) {
            if (a[j].x < min.x) {
                min.x = a[j].x;
                min.y = a[j].y;
                i = j;
            }
        }
    }
    a[i].angle = 2;
    for (int l = 0; l < i; ++l) {
        a[l].angle = (a[l].x - min.x) / (modul((a[l].x - min.x), a[l].y - min.y));
    }
    for (int m = i + 1; m < a.size(); ++m) {
        a[m].angle = (a[m].x - min.x) / (modul((a[m].x - min.x), a[m].y - min.y));
    }
    quickSort(a, 0, a.size() - 1);
    vector<dot> s = greaghamScan(a);
    double p = 0;
    for (int t = 0;  t<s.size(); ++t) {
        dot o(s[(t+1)%s.size()].x-s[t].x,s[(t+1)%s.size()].y-s[t].y);
        p+=modul(o.x,o.y);
    }
    printf("%.2lf",p);
    //к этому моменту я уже получил выпуклую оболочку в массиве s
    /*int j, k, l;
    i = 0;
    dot mini(10001, 10001);
    dot mink(-10001, 10001);
    dot minj(-10001, -10001);
    dot minl(10001, 10001);
    for (int i1 = 0; i1 < s.size(); ++i1) {
        if (s[i1].x > mink.x) {
            mink = s[i1];
            k = i1;
        }
        if (s[i1].x < mini.x) {
            mini = s[i1];
            i = i1;
        }
        if (s[i1].y > minj.y) {
            minj = s[i1];
            j = i1;
        }
        if (s[i1].y < minl.y) {
            minl = s[i1];
            l = i1;
        }
    }
    dot left(0, -1);
    dot right(0, 1);
    dot up(-1, 0);
    dot down(1, 0);
    vector<double> ang(4);
    vector<double> p;
    for (int t = 0; t < s.size(); ++t) {

        if (k == j) {
            j = (j + 1) % s.size();
            minj = s[j];
            if (j == i) {
                i = (i + 1) % s.size();
                mini = s[i];
            }
            if (i == l) {
                l = (l + 1) % s.size();
                minl = s[l];
            }

        }
        if(j == i){
            i = (i + 1) % s.size();
            mini = s[i];
            if (i == l) {
                l = (l + 1) % s.size();
                minl = s[l];
            }
            if (l == k) {
                k = (k + 1) % s.size();
                mink = s[k];
            }

        }
        if(i == l){
            l = (l + 1) % s.size();
            minl = s[l];
            if (l == k) {
                k = (k + 1) % s.size();
                mink = s[k];
            }
            if (k == j) {
                j = (j + 1) % s.size();
                minj = s[j];
            }

        }
        if(l == k){
            k = (k + 1) % s.size();
            mink = s[k];
            if (k == j) {
                j = (j + 1) % s.size();
                minj = s[j];
            }
            if (j == i) {
                i = (i + 1) % s.size();
                mini = s[i];
            }

        }



        dot pk1(s[(k + 1) % s.size()].x - mink.x, s[(k + 1) % s.size()].y - mink.y);//вектор pkpk+1
        dot pj1(s[(j + 1) % s.size()].x - minj.x, s[(j + 1) % s.size()].y - minj.y);
        dot pi1(s[(i + 1) % s.size()].x - mini.x, s[(i + 1) % s.size()].y - mini.y);
        dot pl1(s[(l + 1) % s.size()].x - minl.x, s[(l + 1) % s.size()].y - minl.y);
        ang[0] = findAngle(right, pk1);
        ang[1] = findAngle(up, pj1);
        ang[2] = findAngle(left, pi1);
        ang[3] = findAngle(down, pl1);
        double angl = max(max(ang[0], ang[1]), max(ang[2], ang[3]));
        if (ang[0] == angl) {
            right = pk1;

            up.x = -right.y;
            up.y = right.x;

            left.x = -right.x;
            left.y = -right.y;

            down.x = right.y;
            down.y = -right.x;

            dot kj(minj.x - mink.x, minj.y - mink.y);
            dot ji(mini.x - minj.x, mini.y - minj.y);
            dot lk(mink.x - minl.x, mink.y - minl.y);
            p.push_back(2 * (modul(kj.x, kj.y) * findAngle(kj, right) + modul(lk.x, lk.y) * findAngle(lk, right) +
                             modul(ji.x, ji.y) * findAngle(ji, up) + modul(kj.x, kj.y) * findAngle(kj, up)));

            //mink = s[(k + 1) % s.size()];
            //k = (k + 1) % s.size();

        } else if (ang[1] == angl) {
            up = pj1;

            left.x = -up.y;
            left.y = up.x;

            down.x = -left.y;
            down.y = left.x;

            right.x = -down.y;
            right.y = down.x;

            dot ji(mini.x - minj.x, mini.y - minj.y);
            dot kj(minj.x - mink.x, minj.y - mink.y);
            dot il(minl.x - mini.x, minl.y - mini.y);
            p.push_back(2 * (modul(kj.x, kj.y) * findAngle(up, kj) + modul(ji.x, ji.y) * findAngle(up, ji) +
                             modul(il.x, il.y) * findAngle(il, left) + modul(ji.x, ji.y) * findAngle(ji, left)));

            //minj = s[(j + 1) % s.size()];
            //j = (j + 1) % s.size();

        } else if (ang[2] == angl) {
            left = pi1;

            down.x = -left.x;
            down.y = left.y;

            right.x = -down.y;
            right.y = down.x;

            up.x = -right.y;
            up.y = right.x;


            dot ji(mini.x - minj.x, mini.y - minj.y);
            dot il(minl.x - mini.x, minl.y - mini.y);
            dot kj(minj.x - mink.x, minj.y - mink.y);
            p.push_back(2 * (modul(ji.x, ji.y) * findAngle(left, ji) + modul(il.x, il.y) * findAngle(left, il) +
                             modul(ji.x, ji.y) * findAngle(up, ji) + modul(kj.x, kj.y) * findAngle(kj, up)));
            //mini = s[(i + 1) % s.size()];
            //i = (i + 1) % s.size();

        } else if (ang[3] == angl) {
            down = pl1;

            right.x = -down.y;
            right.y = down.x;

            up.x = -right.y;
            up.y = right.x;

            left.x = -up.x;
            left.y = up.y;


            dot lk(mink.x - minl.x, mink.y - minl.y);
            dot il(minl.x - mini.x, minl.y - mini.y);
            dot ji(mini.x - minj.x, mini.y - minj.y);
            double o = 0;
            o = 2 * (modul(lk.x, lk.y) * findAngle(down, lk) + modul(il.x, il.y) * findAngle(down, il) +
                     modul(il.x, il.y) * findAngle(left, il) + modul(ji.x, ji.y) * findAngle(ji, left));
            p.push_back(o);
            //minl = s[(l + 1) % s.size()];
            //l = (l + 1) % s.size();

        }
    }

    double m = 10000;
    for (int b = 0; b < p.size(); ++b) {
        if (p[b] < m)m = p[b];
    }
    printf("%.2lf", m);
    //printDots(s);*/
    return 0;
}




