#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <vector>
#include <stack>

using namespace std;
enum code {
    HALT = 0,
    SYSCALL = 1,
    ADD = 2,
    ADDI = 3,
    SUB = 4,
    SUBI = 5,
    MUL = 6,
    MULI = 7,
    DIV = 8,
    DIVI = 9,
    LC = 12,
    SHL = 13,
    SHLI = 14,
    SHR = 15,
    SHRI = 16,
    AND = 17,
    ANDI = 18,
    OR = 19,
    ORI = 20,
    XOR = 21,
    XORI = 22,
    NOT = 23,
    MOV = 24,
    ADDD = 32,
    SUBD = 33,
    MULD = 34,
    DIVD = 35,
    ITOD = 36,
    DTOI = 37,
    PUSH = 38,
    POP = 39,
    CALL = 40,
    CALLI = 41,
    RET = 42,
    CMP = 43,
    CMPI = 44,
    CMPD = 45,
    JMP = 46,
    JNE = 47,
    JEQ = 48,
    JLE = 49,
    JL = 50,
    JGE = 51,
    JG = 52,
    LOAD = 64,
    STORE = 65,
    LOAD2 = 66,
    STORE2 = 67,
    LOADR = 68,
    LOADR2 = 69,
    STORER = 70,
    STORER2 = 71
};

void skipSpaces(string &s) {
    int i = 0;
    while (s[i] == ' ' || s[i] == '\t') {
        i++;
    }

    s = s.substr(i, s.length());
    i = s.size() - 1;
    while (s[i] == ' ' || s[i] == '\t') {
        i--;
    }
    s = s.substr(0, i + 1);
}

struct data {
    string s;
    int index;
    string type;
};
typedef union u{
    double d;
    unsigned int i[2];
}u;

data operations[] = {
        {"halt",    0,  "RI"},
        {"syscall", 1,  "RI"},
        {"add",     2,  "RR"},
        {"addi",    3,  "RI"},
        {"sub",     4,  "RR"},
        {"subi",    5,  "RI"},
        {"mul",     6,  "RR"},
        {"muli",    7,  "RI"},
        {"div",     8,  "RR"},
        {"divi",    9,  "RI"},
        {"lc",      12, "RI"},
        {"shl",     13, "RR"},
        {"shli",    14, "RI"},
        {"shr",     15, "RR"},
        {"shri",    16, "RI"},
        {"and",     17, "RR"},
        {"andi",    18, "RI"},
        {"or",      19, "RR"},
        {"ori",     20, "RI"},
        {"xor",     21, "RR"},
        {"xori",    22, "RI"},
        {"not",     23, "RI"},
        {"mov",     24, "RR"},
        {"addd",    32, "RR"},
        {"subd",    33, "RR"},
        {"muld",    34, "RR"},
        {"divd",    35, "RR"},
        {"itod",    36, "RR"},
        {"dtoi",    37, "RR"},
        {"push",    38, "RI"},
        {"pop",     39, "RI"},
        {"call",    40, "RR"},
        {"calli",   41, "RM"},
        {"ret",     42, "RI"},
        {"cmp",     43, "RR"},
        {"cmpi",    44, "RI"},
        {"cmpd",    45, "RR"},
        {"jmp",     46, "RM"},
        {"jne",     47, "RM"},
        {"jeq",     48, "RM"},
        {"jle",     49, "RM"},
        {"jl",      50, "RM"},
        {"jge",     51, "RM"},
        {"jg",      52, "RM"},
        {"load",    64, "RM"},
        {"store",   65, "RM"},
        {"load2",   66, "RM"},
        {"store2",  67, "RM"},
        {"loadr",   68, "RR"},
        {"storer",  69, "RR"},
        {"loadr2",  70, "RM"},
        {"storer2", 71, "RR"}
};
map<string, int> registers{
        {"r0",    0},
        {"r1",    1},
        {"r2",    2},
        {"r3",    3},
        {"r4",    4},
        {"r5",    5},
        {"r6",    6},
        {"r7",    7},
        {"r8",    8},
        {"r9",    9},
        {"r10",   10},
        {"r11",   11},
        {"r12",   12},
        {"r13",   13},
        {"r14",   14},
        {"r15",   15},
        {"flags", 16},

};


void toBinary(long x) {
    stack<long> a;
    int t = 64;
    while (x != 0) {
        a.push(x % 2);
        x = x / 2;
        t--;

    }
    for (int i = 0; i < t; ++i) {
        a.push(0);
    }
    while (!a.empty()) {
        cout << a.top();
        a.pop();
    }
    cout<<'\n';
}

int getCommandNumber(int x) {
    return (x & (255 << 24)) >> 24;
}

void disAssemble(vector<int> &words) {
    //без меток(просто числа)
    map<int, string> name;
    map<int, string> type;
    for (int i = 0; i < sizeof(operations) / sizeof(operations[0]); ++i) {
        name[operations[i].index] = operations[i].s;
        type[operations[i].index] = operations[i].type;
    }

    for (int i = 0; i < words.size(); ++i) {
        int x = words[i];
        int y = getCommandNumber(x);
        if (type[y] == "RM" || type[y] == "RI") {
            int r = (x & (15 << 20)) >> 20;
            int v = x & (1048575);
            string reg = "r" + to_string(r);
            cout << '\t' << name[y] << " " << reg << " " << v << '\n';

        } else {
            int r = (x & (15 << 20)) >> 20;
            int r1 = (x & (15 << 16)) >> 16;
            string reg = "r" + to_string(r) + " r" + to_string(r1);
            int v = x & (65535);
            cout << '\t' << name[y] << " " << reg << " " << v << '\n';
        }


    }


}

int assemble(vector<int> &words) {
    ifstream sourse;
//   /home/leonid/Рабочий стол/
    sourse.open("input.fasm");
    string s;
    //принадлежность типу
    bool error = false;
    int line = 0;
    map<string, int> functions;
    map<string, int> commands;
    map<string, string> type;

    //инициализация массива с коммандами
    for (int i = 0; i < sizeof(operations) / sizeof(operations[0]); ++i) {
        commands[operations[i].s] = operations[i].index;
    }
    for (int j = 0; j < sizeof(operations) / sizeof(operations[0]); ++j) {
        type[operations[j].s] = operations[j].type;
    }
    int k = 0;
    int start = 0;
    while (getline(sourse, s)) {

        if (s.find(';') != -1) {
            s = s.substr(0, s.find(';'));
        }
        skipSpaces(s);

        if (!s.empty()) {
            if (s.find(':') != -1) {
                string s1 = s.substr(0, s.find(":") + 1);
                functions[s1] = k;
                s = s.substr(s.find(":") + 1, s.size());
                if (!s.empty()) {

                    k++;
                }

            } else {
                if (s.find("end") != -1) {
                    skipSpaces(s);
                    string s1 = s.substr(4, s.length());
                    start = functions[s1 + ":"];
                }
                k++;
            }
        }

    }
    sourse.close();
    /*
    *Иницилизирую массив в котором будут машинные слова
    *
    */
    sourse.open("input.fasm");
    k = 0;
    while (getline(sourse, s)) {
        if (s.find(';') != -1) {
            s = s.substr(0, s.find(';'));
        }

        if (s.find(':') != -1) {
            s = s.substr(s.find(":") + 1, s.size());
        }

        if (!s.empty()) {
            skipSpaces(s);
            if (s == "word") {
                words.push_back(-1);
            } else {
                string command = s.substr(0, s.find(' '));
                error = true;
                string tp = type[command];
                if (command == "end") {
                    words.push_back(0);
                }
                if (tp == "RM") {//обработать calli
                    int comand = commands[command];
                    if (command == "calli") {
                        s = s.substr(s.find(' ') + 1, s.size());
                        skipSpaces(s);
                        //пишу из предположения, что команда имеет следующий вид: calli func
                        int x = functions[s + ":"];
                        int t = comand << 24;
                        t = t | x;
                        words.push_back(t);
                    } else {
                        //проверить во всех ли RM есть регистры!
                        if (command == "jg" || command == "jne" || command == "jeq" || command == "jle" ||
                            command == "jl" || command == "jge") {
                            int t = comand << 24;
                            s = s.substr(s.find(' ') + 1, s.size());
                            int x = functions[s + ":"];//считаю, что адрес в памяти задан меткой.
                            t = t | x;
                            words.push_back(t);
                        } else {
                            s = s.substr(s.find(' ') + 1, s.size());
                            skipSpaces(s);
                            int t = comand << 24;
                            int reg = registers[s.substr(0, s.find(' '))] << 20;
                            int x;
                            if (command == "jmp") {//считаю что адрес всегда задан меткой
                                s = s.substr(s.find(' ') + 1, s.size());
                                x = functions[s + ":"];
                            } else {
                                x = atoi(s.substr(s.find(' ') + 1, s.size()).c_str());
                            }
                            t = t | reg;

                            t = t | x;
                            words.push_back(t);
                            error = false;
                        }
                    }
                } else if (type[command] == "RI") {
                    s = s.substr(s.find(' ') + 1, s.size());
                    int t = commands[command] << 24;
                    if (command == "not") {
                        s = s + " ";
                        int reg = registers[s.substr(0, s.find(' '))] << 20;
                        t = t | reg;
                        words.push_back(t);
                    } else {
                        if (command == "lc") {
                            int reg = registers[s.substr(0, s.find(' '))] << 20;
                            s = s.substr(s.find(' ') + 1, s.size());
                            int x;
                            if (functions[s + ":"] != 0) {
                                x = functions[s + ":"];

                            } else {
                                x = atoi(s.c_str());
                            }
                            t = t | x;
                            t = t | reg;
                            words.push_back(t);
                        } else {
                            int reg;
                            if (command == "ret") {
                                reg = 0;
                            } else {
                                reg = registers[s.substr(0, s.find(' '))] << 20;
                            }
                            int x = atoi(s.substr(s.find(' ') + 1, s.size()).c_str());
                            t = t | x;
                            t = t | reg;
                            if (command == "syscall" && x == 0) {
                                t = 0;
                            }
                            words.push_back(t);
                        }
                    }
                    error = false;
                } else if (type[command] == "RR") {
                    s = s.substr(s.find(' ') + 1, s.size());
                    int t = commands[command] << 24;
                    int r1 = registers[s.substr(0, s.find(' '))] << 20;
                    s = s.substr(s.find(' ') + 1, s.size());
                    int r2 = registers[s.substr(0, s.find(' '))] << 16;

                    int x = atoi(s.substr(s.find(' ') + 1, s.size()).c_str());
                    t = t | r1;
                    t = t | r2;
                    t = t | x;
                    words.push_back(t);
                    error = false;
                }
            }
        }

    }
    sourse.close();
    return start;
}

//processing...
void syscall(int x, vector<int> &memory, vector<int> &reg) {
    int v = x & (1048575);
    int r = (x & (15 << 20)) >> 20;
    if (v == 100) {
        cin >> reg[r];
    }
    if (v == 102) {
        printf("%d", reg[r]);
    }
    if (v == 103){
        u u1;
        u1.i[0] = reg[r];
        u1.i[1] = reg[r+1];
        printf("%lg",u1.d);

    }
    if (v == 105) {
        printf("%c", reg[r]);
    }
    if (v == 0) {
        reg[15]++;
        memory[reg[15]] = 0;
    }
}

void add(int x, vector<int> &memory, vector<int> &reg) {
    int r = (x & (15 << 20)) >> 20;
    int r1 = (x & (15 << 16)) >> 16;
    int v = x & (65535);
    reg[r] += (reg[r1] + v);
}

void addi(int x, vector<int> &memory, vector<int> &reg) {
    int r = (x & (15 << 20)) >> 20;
    int v = x & (1048575);
    reg[r] += v;
}

void sub(int x, vector<int> &memory, vector<int> &reg) {
    int r = (x & (15 << 20)) >> 20;
    int r1 = (x & (15 << 16)) >> 16;
    int v = x & (65535);
    reg[r] -= (reg[r1] + v);

}

void subi(int x, vector<int> &memory, vector<int> &reg) {
    int r = (x & (15 << 20)) >> 20;
    int v = x & (1048575);
    reg[r] -= v;

}

void mul(int x, vector<int> &memory, vector<int> &reg) {
    int r = (x & (15 << 20)) >> 20;
    int r1 = (x & (15 << 16)) >> 16;
    int v = x & (65535);
    long rez = (long) reg[r] * (long) (reg[r1] + v);
    reg[r] = (int) (rez);
    reg[r + 1] = (int) (rez >> 32);
}

void muli(int x, vector<int> &memory, vector<int> &reg) {
    int r = (x & (15 << 20)) >> 20;
    int v = x & (1048575);
    long rez = (long) reg[r] * (long) v;
    reg[r] = (int) (rez & 2147483647);
    reg[r + 1] = (int) (rez >> 32);
}

void div(int x, vector<int> &memory, vector<int> &reg) {//учесть случай деления на ноль, подумать о размещении частного
    int r = (x & (15 << 20)) >> 20;
    int r1 = (x & (15 << 16)) >> 16;
    int v = x & (65535);
    long d = (long) reg[r];
    long u = (long) reg[r + 1];
    long t = u << 32;
    d = t | d;
    int p = reg[r1];
    long q = d / p;
    long rem = d % p;
    reg[r] = q;
    reg[r + 1] = rem;

}

void divi(int x, vector<int> &memory, vector<int> &reg) {//учесть случай деления на ноль, подумать о размещении частного
    int r = (x & (15 << 20)) >> 20;
    int r1 = (x & (15 << 16)) >> 16;
    int v = x & (65535);
    long d = (long) reg[r];
    long u = (long) reg[r + 1];
    long t = u << 32;
    d = t | d;
    int p = reg[r1];
    long q = d / p;
    long rem = d % p;
    reg[r] = q;
    reg[r + 1] = rem;

}

void lc(int x, vector<int> &memory, vector<int> &reg) {
    int r = (x & (15 << 20)) >> 20;
    int v = x & (1048575);
    reg[r] = v;
}

void shl(int x, vector<int> &memory, vector<int> &reg) {
    int r = (x & (15 << 20)) >> 20;
    int r1 = (x & (15 << 16)) >> 16;
    reg[r] = reg[r] << reg[r1];
}

void shli(int x, vector<int> &memory, vector<int> &reg) {
    int r = (x & (15 << 20)) >> 20;
    int v = x & (1048575);

    reg[r] = reg[r] << v;

}

void shr(int x, vector<int> &memory, vector<int> &reg) {
    int r = (x & (15 << 20)) >> 20;
    int r1 = (x & (15 << 16)) >> 16;
    reg[r] = reg[r] >> reg[r1];
}

void shri(int x, vector<int> &memory, vector<int> &reg) {
    int r = (x & (15 << 20)) >> 20;
    int v = x & (1048575);
    reg[r] = reg[r] >> v;
}

void and1(int x, vector<int> &memory, vector<int> &reg) {//логические операции
    int r = (x & (15 << 20)) >> 20;
    int r1 = (x & (15 << 16)) >> 16;
    reg[r] = reg[r] & reg[r1];
}

void andi(int x, vector<int> &memory, vector<int> &reg) {
    int r = (x & (15 << 20)) >> 20;
    int v = x & (1048575);
    reg[r] = reg[r] & v;

}

void or1(int x, vector<int> &memory, vector<int> &reg) {//логические операции
    int r = (x & (15 << 20)) >> 20;
    int r1 = (x & (15 << 16)) >> 16;
    reg[r] = reg[r] | reg[r1];
}

void ori(int x, vector<int> &memory, vector<int> &reg) {
    int r = (x & (15 << 20)) >> 20;
    int v = x & (1048575);
    reg[r] = reg[r] | v;
}

void xor1(int x, vector<int> &memory, vector<int> &reg) {//логические операции
    int r = (x & (15 << 20)) >> 20;
    int r1 = (x & (15 << 16)) >> 16;
    //reg[r] = (!reg[r] && reg[r1]) || (reg[r] && !reg[r1]);
    reg[r] = reg[r]^reg[r1];
}

void xori(int x, vector<int> &memory, vector<int> &reg) {
    int r = (x & (15 << 20)) >> 20;
    int v = x & (1048575);
    //reg[r] = (!reg[r] && v) || (reg[r] && !v);
    reg[r] = reg[r]^v;
}

void not1(int x, vector<int> &memory, vector<int> &reg) {
    int r = (x & (15 << 20)) >> 20;
    reg[r] = ~reg[r];
}

void mov(int x, vector<int> &memory, vector<int> &reg) {
    int r = (x & (15 << 20)) >> 20;
    int r1 = (x & (15 << 16)) >> 16;
    int v = x & (65535);
    reg[r] = reg[r1] + v;
}


//реализовать:


void addd(int x, vector<int> &memory, vector<int> &reg) {
    int r = (x & (15 << 20)) >> 20;
    int r1 = (x & (15 << 16)) >> 16;
    u u1;
    u u2;
    u1.i[0] = reg[r];
    u1.i[1] = reg[r+1];
    u2.i[0] = reg[r1];
    u2.i[1] = reg[r1+1];
    double d = u1.d+u2.d;
    u1.d = d;
    reg[r] = u1.i[0];
    reg[r+1] = u1.i[1];

}

void subd(int x, vector<int> &memory, vector<int> &reg) {
    int r = (x & (15 << 20)) >> 20;
    int r1 = (x & (15 << 16)) >> 16;
    u u1;
    u u2;
    u1.i[0] = reg[r];
    u1.i[1] = reg[r+1];
    u2.i[0] = reg[r1];
    u2.i[1] = reg[r1+1];
    double d = u1.d-u2.d;
    u1.d = d;
    reg[r] = u1.i[0];
    reg[r+1] = u1.i[1];
}

void muld(int x, vector<int> &memory, vector<int> &reg) {
    int r = (x & (15 << 20)) >> 20;
    int r1 = (x & (15 << 16)) >> 16;
    u u1;
    u u2;
    u1.i[0] = reg[r];
    u1.i[1] = reg[r+1];
    u2.i[0] = reg[r1];
    u2.i[1] = reg[r1+1];
    double d = u1.d*u2.d;
    u1.d = d;
    reg[r] = u1.i[0];
    reg[r+1] = u1.i[1];
}

void divd(int x, vector<int> &memory, vector<int> &reg) {
    int r = (x & (15 << 20)) >> 20;
    int r1 = (x & (15 << 16)) >> 16;
    u u1;
    u u2;
    u1.i[0] = reg[r];
    u1.i[1] = reg[r+1];
    u2.i[0] = reg[r1];
    u2.i[1] = reg[r1+1];
    double d = u1.d/u2.d;
    u1.d = d;
    reg[r] = u1.i[0];
    reg[r+1] = u1.i[1];
}
//done
void itod(int x, vector<int> &memory, vector<int> &reg) {
    int r = (x & (15 << 20)) >> 20;
    int r1 = (x & (15 << 16)) >> 16;
    double d = double(reg[r1]);
    u u1;
    u1.d = d;
    reg[r] = u1.i[0];
    reg[r+1] = u1.i[1];
}

void dtoi(int x, vector<int> &memory, vector<int> &reg) {
    int r = (x & (15 << 20)) >> 20;
    int r1 = (x & (15 << 16)) >> 16;
    u u2;
    u2.i[0] = reg[r1];
    u2.i[1] = reg[r1+1];
    int t = (int)u2.d;

    reg[r] = t;
}

void cmpd(int x, vector<int> &memory, vector<int> &reg) {
    int r = (x & (15 << 20)) >> 20;
    int r1 = (x & (15 << 16)) >> 16;

    u a;
    u b;
    a.i[0] = reg[r];
    a.i[1] = reg[r+1];
    b.i[0] = reg[r1];
    b.i[1] = reg[r1+1];
    if (a.d >= b.d)reg[16] = 4;
    if (a.d <= b.d)reg[16] = 5;
    if (a.d > b.d)reg[16] = 1;
    if (a.d < b.d)reg[16] = 2;
    if (a.d == b.d)reg[16] = 3;
}
////











void push(int x, vector<int> &memory, vector<int> &reg) {
    int r = (x & (15 << 20)) >> 20;
    int v = x & (1048575);
    reg[14]--;
    memory[reg[14]] = reg[r] + v;

}

void pop(int x, vector<int> &memory, vector<int> &reg) {
    int r = (x & (15 << 20)) >> 20;
    int v = x & (1048575);
    int p = memory[reg[14]];
    reg[r] = p + v;
    reg[14]++;
}

void call(int x, vector<int> &memory, vector<int> &reg) {
    int r = (x & (15 << 20)) >> 20;
    int r1 = (x & (15 << 16)) >> 16;
    int v = x & (65535);

    reg[14]--;
    memory[reg[14]] = reg[15] + 1;

    reg[r] = reg[r1] + v;
    reg[15] = reg[r];
}

void calli(int x, vector<int> &memory, vector<int> &reg) {
    int r = (x & (15 << 20)) >> 20;
    int v = x & (1048575);

    reg[14]--;
    memory[reg[14]] = reg[15] + 1;
    reg[15] = v;
}

void ret(int x, vector<int> &memory, vector<int> &reg) {
    int v = x & (1048575);
    int p = memory[reg[14]];
    for (int i = 0; i <= v; ++i) {
        reg[14]++;
    }
    reg[15] = p;
}

void cmp(int x, vector<int> &memory, vector<int> &reg) {
    int r = (x & (15 << 20)) >> 20;
    int r1 = (x & (15 << 16)) >> 16;
    int a = reg[r];
    int b = reg[r1];
    if (a >= b)reg[16] = 4;
    if (a <= b)reg[16] = 5;
    if (a > b)reg[16] = 1;
    if (a < b)reg[16] = 2;
    if (a == b)reg[16] = 3;
}

void cmpi(int x, vector<int> &memory, vector<int> &reg) {
    int r = (x & (15 << 20)) >> 20;
    int v = x & (1048575);
    int a = reg[r];
    int b = v;
    if (a >= b)reg[16] = 4;
    if (a <= b)reg[16] = 5;
    if (a > b)reg[16] = 1;
    if (a < b)reg[16] = 2;
    if (a == b)reg[16] = 3;
}

void jmp(int x, vector<int> &memory, vector<int> &reg) {
    int v = x & (1048575);
    reg[15] = v;
}

void jne(int x, vector<int> &memory, vector<int> &reg) {
    int v = x & (1048575);
    if (reg[16] != 3 && reg[16] != 4 && reg[16] != 5)reg[15] = v;

}

void jeq(int x, vector<int> &memory, vector<int> &reg) {
    int v = x & (1048575);
    if (reg[16] == 3 || reg[16] == 4 || reg[16] == 5)reg[15] = v;

}

void jle(int x, vector<int> &memory, vector<int> &reg) {
    int v = x & (1048575);
    if (reg[16] == 5 || reg[16] == 3)reg[15] = v;

}

void jl(int x, vector<int> &memory, vector<int> &reg) {
    int v = x & (1048575);
    if (reg[16] == 2)reg[15] = v;

}

void jge(int x, vector<int> &memory, vector<int> &reg) {
    int v = x & (1048575);
    if (reg[16] == 4 || reg[16] == 3)reg[15] = v;

}

void jg(int x, vector<int> &memory, vector<int> &reg) {
    int v = x & (1048575);
    if (reg[16] == 1)reg[15] = v;

}

void load(int x, vector<int> &memory, vector<int> &reg) {
    int r = (x & (15 << 20)) >> 20;
    int v = x & (1048575);
    reg[r] = memory[v];
}

void store(int x, vector<int> &memory, vector<int> &reg) {
    int r = (x & (15 << 20)) >> 20;
    int v = x & (1048575);
    memory[v] = reg[r];
}

void load2(int x, vector<int> &memory, vector<int> &reg) {
    int r = (x & (15 << 20)) >> 20;
    int v = x & (1048575);
    reg[r] = memory[v];
    reg[r + 1] = memory[v + 1];
}

void store2(int x, vector<int> &memory, vector<int> &reg) {
    int r = (x & (15 << 20)) >> 20;
    int v = x & (1048575);
    memory[v] = reg[r];
    memory[v + 1] = reg[r + 1];
}

void loadr(int x, vector<int> &memory, vector<int> &reg) {
    int r = (x & (15 << 20)) >> 20;
    int r1 = (x & (15 << 16)) >> 16;
    int v = x & (65535);
    int t = memory[v + reg[r1]];
    reg[r] = t;
}

void storer(int x, vector<int> &memory, vector<int> &reg) {
    int r = (x & (15 << 20)) >> 20;
    int r1 = (x & (15 << 16)) >> 16;
    int v = x & (65535);
    memory[v + reg[r1]] = reg[r];
}

void loadr2(int x, vector<int> &memory, vector<int> &reg) {
    int r = (x & (15 << 20)) >> 20;
    int r1 = (x & (15 << 16)) >> 16;
    int v = x & (65535);
    reg[r] = memory[v + reg[r1]];
    reg[r + 1] = memory[v + reg[r1] + 1];
}

void storer2(int x, vector<int> &memory, vector<int> &reg) {
    int r = (x & (15 << 20)) >> 20;
    int r1 = (x & (15 << 16)) >> 16;
    int v = x & (65535);
    memory[v + reg[r1]] = reg[r];
    memory[v + reg[r1] + 1] = reg[r + 1];
}

void donothing(int x, vector<int> &memory, vector<int> &reg) {

}

int main() {
    vector<int> words;
    int start = assemble(words);
    //я запишу все машинные команды в исполнимый файл, а затем считаю его
    int x = 15;

    //disAssemble(words);
    map<int, string> command;
    for (int j = 0; j < sizeof(operations) / sizeof(operations[0]); ++j) {
        command[operations[j].index] = operations[j].s;
    }
    vector<int> registers(17);
    vector<int> memory(1048576);
    registers[14] = 1048575;

    void (*fun[72])(int x, vector<int> &, vector<int> &);
    fun[0] = donothing;
    fun[1] = syscall;
    fun[2] = add;
    fun[3] = addi;
    fun[4] = sub;
    fun[5] = subi;
    fun[6] = mul;
    fun[7] = muli;
    fun[8] = div;
    fun[9] = divi;
    fun[12] = lc;
    fun[13] = shl;
    fun[14] = shli;
    fun[15] = shr;
    fun[16] = shri;
    fun[17] = and1;
    fun[18] = andi;
    fun[19] = or1;
    fun[20] = ori;
    fun[21] = xor1;
    fun[22] = xori;
    fun[23] = not1;
    fun[24] = mov;
    fun[32] = addd;
    fun[33] = subd;
    fun[34] = muld;
    fun[35] = divd;
    fun[36] = itod;
    fun[37] = dtoi;
    fun[38] = push;
    fun[39] = pop;
    fun[40] = call;
    fun[41] = calli;
    fun[42] = ret;
    fun[43] = cmp;
    fun[44] = cmpi;
    fun[45] = cmpd;
    fun[46] = jmp;
    fun[47] = jne;
    fun[48] = jeq;
    fun[49] = jle;
    fun[50] = jl;
    fun[51] = jge;
    fun[52] = jg;
    fun[64] = load;
    fun[65] = store;
    fun[66] = load2;
    fun[67] = store2;
    fun[68] = loadr;
    fun[69] = storer;
    fun[70] = loadr2;
    fun[71] = storer2;
    registers[15] = start;//начало исполнения.
    x = registers[15];
    registers[14] = 1048575;
    for (int i = 0; i < words.size(); ++i) {
        memory[i] = words[i];
    }

    int y = memory[x];
    while (y != 0) {
        x = registers[15];
        y = memory[x];
        int com = getCommandNumber(y);
        string s = command[com];
        fun[com](y, memory, registers);
        if (x == registers[15])registers[15]++;
    }

    return 0;
}