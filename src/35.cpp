#include <cstdio>
#include <cstring>
#include <cstdint>
#include <set>
#include <deque>
#include <algorithm>

#define MAXN 1000000

uint8_t is_prime[MAXN];
int loop_list[4] = {1,3,7,9};
int prime_list[MAXN];

bool is_circular_prime(int n)
{
    int p;
    std::deque<int> digits;
    std::set<int> circular_map;
    if (n == 2 || n == 5) {
        return true;
    }
    while (n > 0) {
        p = n%10;
        if (p % 2 == 0 || p % 5 == 0) {
            return false;
        }
        digits.push_back(n%10);
        n /= 10;
    }
    std::reverse(digits.begin(),digits.end());
    while(true) {
        p = 0;
        for (size_t m = 0; m < digits.size(); m++) {
            p = p*10 + digits[m];
        }
        if (circular_map.find(p) != circular_map.end()) {
            break;
        }
        circular_map.insert(p);
        if (!is_prime[p]) {
            return false;
        }
        p = digits.front();
        digits.pop_front();
        digits.push_back(p);
    } 
    return true;
}

int main()
{
    int n,a,p,count;
    memset(is_prime,0,sizeof(is_prime));
    p = 0;
    while (scanf("%d",&n) != -1 && n < MAXN) {
        is_prime[n] = 1;
        prime_list[p++] = n;
    }
    count = 0;
    for (a = 0; a < p; a++) {
        if (is_circular_prime(prime_list[a])) {
            count +=1;
            printf("%d\n",prime_list[a]);
        }
    }
    printf("circular prime count:%d\n",count);
}

