#include <iostream>
#include <fstream>

/*
bool stringCompare(char *a, char *b) {//a>b->true
    if (strlen(a) > strlen(b)) {
        for (int i = 0; i < strlen(b); ++i) {
            if (a[i] > b[i]) {
                return true;
            }
            if (b[i] > a[i]) {
                return false;
            }
        }
    } else {
        for (int i = 0; i < strlen(a); ++i) {
            if (a[i] > b[i]) {
                return true;
            }
            if (b[i] > a[i]) {
                return false;
            }
        }
    }
    return true;
}
*/
using namespace std;

void merge(int k) {
    string s1, s2;
    ofstream sourse;
    sourse.open("input.txt");
    ifstream a, b;
    //home/leonid/Рабочий стол/
    a.open("a.txt");
    //home/leonid/Рабочий стол/
    b.open("b.txt");

    while (getline(a, s1) && getline(b, s2)) {//Пересмотри метод слияния
        int x = k;
        int y = k;
        while (1) {
            if (s2 < s1) {
                if(s2!="")sourse << s2 << '\n';
                y--;
                if (y == 0)break;
                getline(b, s2);

            } else {
                if(s1!="")sourse << s1 << '\n';
                x--;
                if (x == 0)break;
                getline(a, s1);
            }
        }
        if (x == 0) {
            sourse << s2 << '\n';
            y--;
            while (y > 0) {

                getline(b, s2);
                sourse << s2 << '\n';
                y--;
            }
        }
        if (y == 0 && x != 0) {
            sourse << s1 << '\n';
            x--;
            while (x > 0) {
                getline(a, s1);
                sourse << s1 << '\n';
                x--;
            }
        }

    }
    if (!s1.empty())sourse << s1 << '\n';
    while (getline(a, s1)) {

        sourse << s1 << '\n';
    }
    while (getline(b, s2)) {
        sourse << s2 << '\n';
    }
    a.close();
    b.close();
}

int parce(int k) {

    FILE *sourse;
    FILE *a;
    FILE *b;
    string s;
    int c = 10000;
    //home/leonid/Рабочий стол/
    sourse = fopen("input.txt", "r");
    a = fopen("a.txt", "w");
    b = fopen("b.txt", "w");
    int i = 0;
    char *s1 = (char *) malloc(sizeof(char) * c);
    while (fgets(s1, c, sourse)) {
        if ((i / k) % 2 == 0) {
            fputs(s1, a);
        } else {
            fputs(s1, b);
        }
        i++;
    }
    fclose(sourse);
    fclose(a);
    fclose(b);
    free(s1);
    merge(k);
    return i;
}

using namespace std;

int main() {


    int g = parce(1);
    int y = 2;
    while (y<g){
        parce(y);
        y*=2;
    }
    FILE* sourse;
    FILE* o;
    sourse = fopen("input.txt","r");

    //home/leonid/Рабочий стол/
    o = fopen("output.txt","w");

    char *c = (char *)malloc(sizeof(char)*5);
    while (fgets(c,5,sourse)!=NULL) {
        fputs(c,o);
    }
    fclose(o);
    fclose(sourse);
    free(c);
    return 0;
}