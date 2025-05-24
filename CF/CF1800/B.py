#
#   Author: BeanBurrito
#


def solve():
    n, k = [int(x) for x in input().split()]
    s = input()
    d = {}
    sset = set(s)
    pairs = 0
    
    for c in sset:
        d[c.lower()] = 0
        d[c.upper()] = 0
    
    for c in s:
        d[c] += 1
        
    for c in d:
        lower = d[c.lower()]
        upper = d[c.upper()]
        canmake = (lower if lower < upper else upper)
        d[c.lower()] -= canmake
        d[c.upper()] -= canmake
        pairs += canmake
    
    ops = 0
    for c in sset:
        if d[c] > 1:
            canmake = d[c] // 2
            pairs += (canmake if ops + canmake <= k else k - ops)
            ops += (canmake if ops + canmake <= k else k - ops)
        if ops == k:
            break
        
    print(pairs)
    

numc = int(input())
while(numc):
    numc -= 1
    solve()