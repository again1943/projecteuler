#include <cstdio>
#include <cstring>
#include <algorithm>

#define MAXN 128

int triangle[MAXN][MAXN];
int sum[MAXN][MAXN];

int calc_triangle(int n)
{
    int a,b;
    memset(sum,0,sizeof(sum));
    sum[0][0] = triangle[0][0];
    for (a = 1; a < n; a++) {
        sum[a][0] = sum[a-1][0]+triangle[a][0];    
        sum[a][a] = sum[a-1][a-1]+triangle[a][a];
        for (b = 1; b < a; b++) {
            sum[a][b] = std::max(sum[a-1][b-1],sum[a-1][b])+triangle[a][b];
        }
    }
    for (a = b = 0; b < n; b++) {
        a = std::max(a,sum[n-1][b]);
    } 
    return a;
}

int main()
{
    int n,m,k;
    scanf("%d",&k);
    for (n = 0; n < k; n++) {
        for (m = 0; m <= n; m++) {
            scanf("%d",&triangle[n][m]);
        }
    }
    printf("%d\n",calc_triangle(n));
    return 0;
}
