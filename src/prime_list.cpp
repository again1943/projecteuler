#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdint>
#define MAXN 1000000000

uint32_t is_prime[(MAXN+31)/32];

int main()
{
    long long a,b,c;
    memset(is_prime,255,sizeof(is_prime));
    is_prime[0] ^= 0x3;

    for (a = 0; a < MAXN; a++) {
        if (!(is_prime[a/32]&(1<<(a%32)))) {
            continue;
        }
        for (b = a; (c = a*b) < MAXN; b++) {
            is_prime[c/32] &= ~(1<<(c%32));
        } 
    }
    for (a = 0; a < MAXN; a++) {
        if (is_prime[a/32] & (1<<(a%32))) {
            printf("%lld\n",a);
        }
    }
    return 0;
}
