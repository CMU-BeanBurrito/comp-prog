#
#   Author: BeanBurrito
#


def solve():
    n = int(input())
    s = input()
    
    count = n-1
    
    for i in range(n-2):
        if s[i] == s[i+2]:
            count -= 1
    
    print(count)

t = int(input())
while(t > 0):
    t -= 1
    solve()