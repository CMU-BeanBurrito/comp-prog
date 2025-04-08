Some mistakes I have made in the past. These are things to check for especially when one's logic is correct.

# Integer Overflow
- check to see if any variables can overflow
- make sure overflowing numbers are of type long long, don't forget to multiply by 1LL or add 0LL
- check that print format specifiers are correct (e.g. %lld)
- make sure that inputs are read as the correct type (e.g. int x >> cin x is a bug if x > INT_MAX)

# Read all input
Sometimes, the answer is known before reading all the input. But make sure to read all input before terminating solve().

# Loop Guards
- check all loop guards, especially nested loops

# Runtime Error
- Usually an out of bounds array access (check array indices)
- Can also be a divide by 0 (or mod by 0)