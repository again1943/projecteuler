/*
We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once. For example, 2143 is a 4-digit pandigital and is also prime.

What is the largest n-digit pandigital prime that exists?

http://projecteuler.net/problem=41
*/

/*
solution:
since the n-digit number is a prime number and it makes use of all the digits from 1 to n
sum = n*(1+n)/2, if sum % 3 == 0, then it can't be prime, so, n = 8,9,5,6 can be excluded
so max n-digit pandigital prime must be with n = 7
*/

#include <cstdio>

bool is_pandigital(int p, int n)
{
    int m; 
    int digits[10] = {0,0,0,0,0,0,0,0,0,0};  
    while (p > 0) {
        m = p%10;
        if (m > n || m == 0 || digits[m] != 0) {
            return false;
        }
        digits[m] = 1;
        p /= 10;
    }
    return true;
}
/*
    stdin, prime list from 2 on ...(2,3,5,7...)
*/
int main()
{
    int p; 
    int m = 0;
    while (scanf("%d",&p) != -1 && p < 10000000) {
        if (p < 1000000) {
            continue;
        } 
        if (is_pandigital(p,7)) {
            m = p;
        }
    }
    printf("%d\n",m);
    return 0;
}
