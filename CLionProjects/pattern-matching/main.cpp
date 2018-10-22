#include <iostream>
#include <string>

using namespace std;

bool subCheck(int x, string sourse, string chunk) {
    for (int i = 0; i < chunk.size(); ++i) {
        if (chunk[i] != '?' && chunk[i] != sourse[i+x]) {
            return false;
        }
    }
    return true;
}

bool check(string &sourse, string &chunk) {
    if (sourse.size() < chunk.size())
        return false;
    int x = 0;
    while (x + chunk.size() <= sourse.size() && !subCheck(x, sourse, chunk)) {
        x++;
    }
    if (x + chunk.size() > sourse.size()) {
        return subCheck(x - 1, sourse, chunk);
    }
    sourse = sourse.substr(x + chunk.size(), sourse.size());
    return true;

}

int main() {
    string sourse, pattern, chunk;
    cin >> sourse;
    cin >> pattern;
    int x;
    bool flag = true;
    x = pattern.find('*');
    while (x != -1) {
        chunk = pattern.substr(0, x);
        pattern = pattern.substr(x+1,pattern.size());
        if (!check(sourse, chunk))flag = false;
        x = pattern.find('*');
    }
    if (!check(sourse, pattern))flag = false;
    if (!flag) {
        cout << "NO";
    } else{
        cout<<"YES";
    }
    return 0;
    /*ABRACADABRA
      ABRA*ABRA   */
}