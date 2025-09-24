Notes on solutions/approaches to problems

# A: Letter Home

Let's call the leftmost position in `X` (which is `x[0]`), "endpoint A", and the rightmost position in `X` (which is `x[n-1]`), "endpoint B".

The most efficient path is one of the following:
- start, endpoint A, endpoint B
- start, endpoint B, endpoint A

So, we can just take the minimum of the two:
- `|s-a[0]| + a[n-1] - a[0]`
- `|s-a[n-1]| + a[n-1] - a[0]`

# B: Above the Clouds

Clearly, the first letter of `s` must belong to string `a`, and the last letter of `s` must belong to string `c`.

Aside from that, `b` can be any substring of the middle `n-2` characters. Our strategy will be to have `b` be one character. If another instance of this character exists anywhere in `s`, the answer is YES.

Use a map to count the number of occurrences of each letter. Iterate over index `i`, from `1` to `n-2` (0-indexing, inclusive). If for any character `s[i]`, the frequency of `s[i]` is at least 2, the answer is YES, since we can choose `b = s[i]`, and `b` exists in `a` or `c`.

If no character `s[i]` within that range has frequency at least 2, the answer is NO. 

# C: Those Who Are With Us

Since we can only perform one operation, the maximum value present in the matrix can be decreased by at most 1. If the maximum value in the initial matrix is `mx`, the question is, will the maximum value present in the FINAL matrix be `mx` or `mx-1`.

For the answer to be `mx-1`, we need to be able to "hit" all instances of `mx` with one operation. We can do this if there exists a position `(r, c)` such that all instances of `mx` are on the `rth` row or the `cth` column. If no such position exists, we cannot hit all instances of `mx`, so the answer will be `mx`.

We will pre-process a few things:
- count the number of instances of `mx` in the entire grid, call this `m`
- for each row, record how many instances of `mx` are in this row, call this `rcnt`
- for each column, record how many instances of `mx` are in this column, call this `ccnt`

Now, we can iterate over every position `(r, c)` in the grid, checking the `rcnt[r]` and `ccnt[c]`.

If `rcnt[r] + ccnt[c] = m`, it means we are covering all instances of `mx` and the answer is `mx-1`. However, there is an edge case.

If `a[r][c] = mx`, `(r, c)` is double counted, as it is included in both `rcnt[r]` and `ccnt[c]`. So, in order to cover all `mx` (making the answer `mx-1`):
- if `a[r][c] = mx`, `(r, c)`, we need `rcnt[r] + ccnt[c] = m + 1`
- else, we need `rcnt[r] + ccnt[c] = m`.

If we cannot cover all `mx` instances with any position on the grid, the answer is `mx`.

# D: 1709

Conditions:
- Condition 1: `a` is sorted in ascending order
- Condition 2: `b` is sorted in ascending order
- Condition 3: `a[i] < b[i]` for all `i` in `[0, n)`

Strategy:
- Step 1: bubble sort array `a`
- Step 2: bubble sort array `b`
- Step 3: for `i` in `[0, n)`, if `a[i] > b[i]`, swap `a[i], b[i]`

## Proof of correctness:
- After step 1, condition 1 is clearly met
- After step 2, condition 2 is clearly met (and does not affect condition 1)
- After step 3, condition 3 is clearly met

How do we know that step 3 didn't affect conditions 1 and 2? More specifically, if we swap `a[i], b[i]`, how we do we know that:
- `a[i-1] < b[i]`

We know:
- `b[i-1] < b[i]`
- `a[i-1] < b[i-1]`
- so `a[i-1] < b[i]`

Similarly we can prove that `a[i] < b[i+1]:
- `a[i] < a[i+1]`
- `a[i+1] < b[i+1]`
- so `a[i] < b[i+1]`

## Proof that we do not exceed 1709 operations:

Bubble sorting an array of length `n` takes at most `n * (n-1) / 2` adjacent swaps (the only swap we can do within an array). Why?
- The worst case scenario is the array is sorted in descending order. The rightmost (numerically least) element needs to move `n-1` positions to the left. The element that is now on the right (the numerically second least) needs to move `n-2` positions to the left.
- We need to make `(n-1) + (n-2) + ... + 1` swaps, or `n * (n-1) / 2`.

We need to do this for both `a` and `b` so we need to do `n * (n-1)` operations. `n <= 40`, so `n * (n-1) = 40 * 39 = 1560`.

In step 3, we clearly do at most `n` operations, one for each index. So in total we will do at most 1600 operations.

# E: Sponsor of Your Problems

The numbers `l, r` can be broken down into 4 sections:
- Leading zeros
  - if a digit is a leading zero for both numbers, this digit should be ignored
- digit in `l` and digit in `r` are equal
  - answer increases by 2 (the digit we pick will be equal to both)
- digit in `l` precedes digit in `r`
  - answer increases by 1 (the digit we pick will match either `l` or `r`)
- digit in `l` is `9` and digit in `r` is `0`
  - answer increases by 1 (the digit we pick will be either `9` or `0`)

We will traverse these sections in order, once we leave a section, we will not return to it.

# F: Yamakasi

binary search

# G: Gangsta

# H: Ice Baby
