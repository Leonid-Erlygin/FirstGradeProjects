#include <iostream>

using namespace std;


int main() {
    int state = 0;
    char prev = '0';
    char current = '0';
    int x1 = 0;
    int x2 = 0;
    int x3 = 0;
    int x4 = 0;
    int in = 0;
    in = scanf("%c", &current);
    //пересмотри все решение
    while (in > 0 && current != '%') {

        if (current == '*' && prev == '(') {
            state = 1;
        } else if (current == '{') {
            state = 2;
        } else if (current == '/' && prev == '/') {
            state = 3;
        } else if (current == '\342') {
            state = 4;
        }

        switch (state) {
            case 1:

                while (current != '%'&&in > 0 && current != ')' || prev != '*') {
                    prev = current;
                    in = scanf("%c", &current);
                }
                if (in > 0)x1++;
                state = 0;
                break;
            case 2:
                while (current != '%'&&in > 0 && current != '}') {
                    in = scanf("%c", &current);
                }
                if (in > 0)x2++;
                state = 0;
                break;
            case 3:
                while (current != '%'&&current != '\n' && in > 0) {
                    in = scanf("%c", &current);
                    if (current == '%')in = -1;
                }
                x3++;
                state = 0;
                break;
            case 4:
                scanf("%c", &current);
                while (current != '%'&&in > 0 && current != '\342') {
                    in = scanf("%c", &current);
                }
                if (in > 0)x4++;
                state = 0;
                break;


        }
        prev = current;
        if (in > 0&&current!='%')in = scanf("%c", &current); else break;
    }
    cout << x1 << " " << x2 << " " << x3 << " " << x4;
    return 0;
}