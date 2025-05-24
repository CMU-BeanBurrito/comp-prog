#
#   Author: BeanBurrito
#

def solve():
    n = int(input())
    s = input().lower()
    
    idx = 0
    
    if s[0] != 'm' or s[n-1] != 'w':
        print("No")
        return
    
    while(idx < n):
        if s[idx] != 'm':
            if s[idx] != 'e':
                print("No")
                return
            break
        idx += 1
        
    while(idx < n):
        if s[idx] != 'e':
            if s[idx] != 'o':
                print("No")
                return
            break
        idx += 1
        
    while(idx < n):
        if s[idx] != 'o':
            if s[idx] != 'w':
                print("No")
                return
            break
        idx += 1
        
    while(idx < n):
        if s[idx] != 'w':
            print("No")
            return
        idx += 1
        
    print("Yes")
        
    
    

numc = int(input())
while(numc):
    numc -= 1
    solve()