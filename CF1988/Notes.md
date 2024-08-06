Notes on solutions/approaches to problems

# A
If n is 1, we are already done so just print 0.

We can split off $k-1$ 1s each operation. We need to split off $n-1$ 1s to be done.

So, this will require $(n-1)/(k-1)$ operations, rounded up. To round up, we add $denominator-1$ to the numerator.

So the answer is $(n-1+k-2)/(k-1) = (n+k-3)/(k-1)$.
# B

## Step 1
Clearly, it is optimal to remove as many 0s as we can by compressing any streak of 0s into a single 0.

## Step 2
Since we need a majority of 1s in our subarray to convert the subarray into a 1, if we have more 1s than 0s, the answer is yes, otherwise no.

### Why?
There are a couple ways to look at Step 2. The first way is that if we have a majority of 1s, we can just select the whole array. So, having a majority of 1s is definitely sufficient. Is it necessary? Yes, it is.

All 0s are separated by 1s after Step 1. If we do not have a majority of 1s, this means that either we are in one of two cases:
- count of 0s and 1s are equal, meaning string is alternating 0s and 1s starting with 0 and ending with 1 or starting with 1 and ending with 0
  - In this case, the answer is no since we lose a 1 for each 0 we eliminate (101 goes to 1, 10101 goes to 1, etc.)
  - Eventually, we will get down to 01, which cannot be converted to 1
- count of 0s is greater than 1s, meaning string is alternating 0s and 1s, starting and ending with 0s
  - Based on on the above argument, the answer is also no (we'd end up with 00)

So, we definitely need a majority of 1s, and that is always sufficient. So we perform step 1 and then check if the number of 1s is greater than the number of 0s.

# C

## Length
Let b be the number of bits that are 1 in the binary representation of n (also known as the popcount of n). If b=1, the length of the sequence is 1 (the sequence is just the number n, clearly). Otherwise, the length is b+1.

## Sequence
The sequence has b+1 numbers. One of these numbers is n, what are the other b numbers? To find one of them, take the binary representation of n, and flip any bit that is a 1, to a 0, leaving all other bits the same. Clearly, there are b of these. Two consecutive numbers' bitwise OR is also n because each of them is missing one bit, but the bits they are missing are by definiton different ones, so when OR'd together, the result will be n.

To generate these numbers in order, start with switching the highest value bit that is a 1 in the binary representation of n, and work downwards towards the lowest bit that is a 1. Lastly, output n as it is the largest value in the sequence (no bits swapped to 0).

## Example:

Say n = 15, or 0b1111. Popcount of n is 4, so we know our sequence length is 5.

`a[0]` is negating the first 1 in n which would be:  0b0111, or 7.
`a[1]` is negating the second 1 in n which would be: 0b1011, or 11.
`a[2]` is negating the third 1 in n which would be:  0b1101, or 13.
`a[3]` is negating the fourth 1 in n which would be: 0b1110, or 14.
`a[4]` is negating no bits in n, which woudl be n, 15.

So, our sequence is: 7, 11, 13, 14, 15. This example might make it easier to visualize the pattern. 

# D

# E

# F

# G