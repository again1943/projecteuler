#include <cstdio>
#include <cstring>
#include <algorithm>

#define MAXN 128

int data[MAXN][MAXN];
int msum[MAXN][MAXN];

int calc_msum(int n, int m)
{
    int a,b;
    memset(msum,0,sizeof(msum)); 
    msum[0][0] = data[0][0];
    for (a = 1; a < m; a++) {
        msum[0][a] = msum[0][a-1]+data[0][a];
    }
    for (a = 1; a < n; a++) {
        msum[a][0] = msum[a-1][0]+data[a][0];
    }
    for (a = 1; a < n; a++) {
        for (b = 1; b < m; b++) {
            msum[a][b] = std::min(msum[a-1][b],msum[a][b-1])+data[a][b];
        }
    }
    return msum[n-1][m-1];
}
int main()
{
    int n,m,a,b;    
    scanf("%d%d",&n,&m);
    for (a = 0; a < n; a++) {
        for (b = 0; b < m; b++) {
            scanf("%d",&data[a][b]);
        }
    }
    printf("%d\n",calc_msum(n,m));
    return 0;
}
