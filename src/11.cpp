#include <cstdio>
#include <algorithm>

#define MAXN 32
int matrix[MAXN][MAXN];

int eval(int a, int b)
{
    int m = 0;
    int t;
    if (a + 4 < 20) {
        t = matrix[a][b]*matrix[a+1][b]*matrix[a+2][b]*matrix[a+3][b];
        m = std::max(t,m);
    } 
    if (b + 4 < 20) {
        t = matrix[a][b]*matrix[a][b+1]*matrix[a][b+2]*matrix[a][b+3]; 
        m = std::max(t,m);
    }
    if (a+4 < 20 && b+4 < 20) {
        t = matrix[a][b]*matrix[a+1][b+1]*matrix[a+2][b+2]*matrix[a+3][b+3]; 
        m = std::max(t,m);
    }
    if (a+4 < 20 && b-4 >= 0) {
        t = matrix[a][b]*matrix[a+1][b-1]*matrix[a+2][b-2]*matrix[a+3][b-3];
        m = std::max(t,m);
    }
    return m;
}
int main()
{
    int a,b;      
    int m = 0;
    for(a = 0; a < 20; a++) {
        for (b = 0; b < 20; b++) {
            scanf("%d",&matrix[a][b]);
        }
    }
    for (a = 0; a < 20; a++) {
        for (b = 0; b < 20; b++) {
            m = std::max(m,eval(a,b));            
        }
    }
    printf("%d\n",m);
}
