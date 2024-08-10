Notes on solutions/approaches to problems

# A
If the largest number appears an odd amount of times, Alice wins because she can pick it. Bob is then forced to pick another instance of that number, and they will alternate until all instances of that number are exhausted. Since there is an odd count of them, and Alice picked first, she will also get the last one and win.

If the largest number appears an even amount of times, Alice cannot pick it right away or she will lose. So, we examine the next highest number. If it has an odd frequency, she wins because if Bob also picks it, she can continue picking it until Bob eventually must pick the first instance of the highest number, and Alice will win. If the second highest number also has an even frequency, she must look at the third highest value.

So, as long as there is at least one element that has an odd frequency, Alice wins. If all elements have an even frequency, Alice loses.

# B
If x is the maximum prefix, it means that the rest of the array after index x must be non-positive. Similarly, the section of the array before y must be non-positive for y to be the maximum suffix. 

Also, `a[x]` and `a[y]` must both be 1. Otherwise, `a[x-1]` or `a[y+1]` would have been a greater prefix/suffix.

Starting with `a[x]`, we construct towards the right, alternating between -1 and 1. This fulfills the requirement established at the start of this problem's notes.
 - The reason we don't just use all -1 is because we would need a lot of 1s to get the prefix/suffix back up. Otherwise the end of the array would be the maximum prefix/suffix with value -1.

At this point, we just need to fill the middle: `[y+1, x-1]`
 - Suffix and prefix both have value 1 or 0, wich is either already the maximum or tied for it
 - So, if we fill in the middle with 1s, x and y will be the maximums as desired

# C
Elements that appear once in the original array will be counted only once, since they can never be the MAD of any array.

After one operation, the array is sorted and remains sorted thereafter. 

Any element appearing once in the array after one operation will be counted one last time, it cannot be a MAD in any future array.

Beginning with the third operation, the array will shift to the right by 1 index each operation. So, the number of times each element will be counted from this point onwards is the number of elements to the right of it, plus 1.

# D

# E

# F

# G