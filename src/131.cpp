#include <map>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdint>
#define MAXN 1000000002

/*
n^3+n^2 * p = k^3

n must be x^3 and p = x^3-y^3
p = (x-y)*(x^2+xy+y^2), only x-y = 1, p is prime
so p in 3a^2+3a+1 from

notice: this piece of code below is not the best solution as mentioned above
*/

std::vector<int> prime_list;

uint64_t bitmap[(MAXN+63)/64];

int main()
{
    int prime;
    memset(bitmap,0,sizeof(bitmap));

    while(scanf("%d",&prime) != -1 && prime < 1000000) {
        prime_list.push_back(prime);
    }
    for (auto a = 1; a <= 1000; a++) {
        auto c = a*a*a;
        bitmap[c/64] |= (static_cast<uint64_t>(1)<< (c%64));
    }
    for (auto a = 1; a <= 1000; a++) {
        auto c = a*a*a;  
        for (auto b = 0; b < prime_list.size() && prime_list[b] < c; b++) {
            auto it = c-prime_list[b];
            if (bitmap[it/64] & (static_cast<uint64_t>(1)<<(it%64))) {
                printf("%d\t%d\n",prime_list[b],it);
            }
        } 
    } 
    return 0; 
}
