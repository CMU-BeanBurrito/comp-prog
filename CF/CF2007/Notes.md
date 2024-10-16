Notes on solutions/approaches to problems

# A: Dora's Set
In one operation, we need to remove at least 2 odd numbers, or the even numbers in our operation will have gcd 2.

We leverage the fact that consecutive numbers have gcd 1. So remove x, x+1, x+2, where x is odd.

Still need to prove that x, x+2 are coprime. gcd(x, x+2) must also divide x+2-x, 2. So, the gcd is 1 or 2.
Clearly, it is not 2. So it must be 1.

So, removing x, x+1, x+2 is valid if x is odd. Then, we have the strategy:
- Start at l
- if l is even, move to l+1 and remove l+1, l+2, l+3. skip l+4. remove l+5, l+6, l+7, skip l+8...
- if l is odd, remove l, l+1, l+2, skip l+3. remove l+4, l+5, l+6, skip l+7...

Be sure to handle different cases (l odd, l even, r-l+1 mod 4, etc.)

# B: Index and Maximum Value
The element that is originally the maximum can never be exceeded.
In order for another element to exceed the original maximum value, it must first reach the original maximum value and then be incremented. If this happens, the element that is originally the maximum will also increment. So, we simply track the maximum and increment/decrement it on operations that it is affected by (whenever this value is in [l, r]).

# C: Dora and C++
We can change the difference between two elements x, y by gcd(a, b) according to Bezout's Theorem.

However, when it comes to a mod gcd(a, b) - b mod gcd(a, b), you can only toggle this value to gcd(a, b) minus this value or vice versa. So if a mod gcd(a, b) is 1, b mod gcd(a, b) is 6, and gcd(a, b) is 8, you can only make a mod gcd(a, b) - b mod gcd(a, b) 5 or 3. 

Essentially, if we take all elements mod gcd(a, b), they form some sort of circle. To get the minimum range, we want to create the largest possible gap between two elements. The range is gcd(a, b) minus this gap size. 

# D: Iris and Game on the Tree

# E: Iris and the Tree

# F: Eri and Expanded Sets