#include <stdio.h>
#include <stdlib.h>


void build(int* a, int* t, int v, int tl, int tr)
{
    if(tl == tr) t[v] = a[tl];
    else
    {
        int tm = (tl + tr)/2;
        build(a, t, 2*v, tl, tm);
        build(a, t, 2*v + 1, tm + 1, tr);
        t[v]=t[2*v] ^ t[2*v + 1];
    }
}

int xor1(int* t, int v, int tl, int tr, int l, int r)
{
    if(l>r) return 0;
    if(l == tl && r == tr) return t[v];
    int tm = (tl + tr) / 2;
    int min = r, max = l;
    if(tm < min) min = tm;
    if(tm+1 > max) max = tm+1;

    return xor1(t, 2*v, tl, tm, l, min) ^ xor1(t, 2*v + 1, tm+1, tr, max, r);
}

void update (int* t, int v, int tl, int tr, int pos, int new_val)
{
    if(tl == tr) t[v] = new_val;
    else{
        int tm = (tl + tr) / 2;
        if(pos <= tm)
        {
            update (t, 2*v, tl, tm, pos, new_val);
        }
        else
        {
            update (t, 2*v+1, tm+1, tr, pos, new_val);
        }
        t[v] = t[2*v] ^ t[2*v + 1];
    }
}

int main()
{
    int N = 0, K = 0;
    scanf("%d", &N);
    scanf("%d", &K);
    int* a = (int*)calloc(sizeof(int), N);
    int* t = (int*)calloc(sizeof(int), 4*N+1);
    int i = 0;
    for(i = 0; i < N; i++)
    {
        scanf("%d", &a[i]);

    }
    build(a, t, 1, 0, N-1);

    int x = 0, l = 0, r = 0, pos = 0, new_val = 0;
    for(i = 0; i < K; i++)
    {
        scanf("%d", &x);
        if(x == 1)
        {
            scanf("%d %d", &l, &r);
            printf("%d\n", xor1(t, 1, 0, N-1, l, r));
        }
        else if(x == 2)
        {
            scanf("%d %d", &pos, &new_val);
            update(t, 1, 0, N-1, pos, new_val);

        }
        else printf("error");
    }
//
    free(t);
    free(a);
    return 0;
}