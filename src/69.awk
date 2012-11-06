#!/bin/awk
#
#stdin: prime list from 2 on ...(2,3,5,7...)
#
BEGIN {
    p = 1;
}
{
    if (p*$1 <= 1000000) {
        p *= $1;
    }
}
END {
    print p;
}
