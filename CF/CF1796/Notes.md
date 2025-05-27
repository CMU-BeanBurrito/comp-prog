Notes on solutions/approaches to problems

# A: Typical Interview Problem

# B: Asterisk-Minor Template

If the first character of `a` is the same as the first character of `b`, call this character `[c]`. Then the template can just be `[c]*`.

Similarly, if the last character of `a` is the same as the last character of `b` are the same, we can just do `*[c]`.

Otherwise, we need there to be some common substring with length at least 2. If there are none, it means that we will have some number (possibly 0) of substrings with length 1. If we have `x` of them, we would need `x+1` asterisks: `\*[c]\*[c]\*[c]\*`. Then, this template is not asterisk-minor. So, if there is no common substring of length 2 or more, there is no solution.

If there is such a substring, we can do `\*[c1][c2]\*`.

# C: Maximum Set

It's fairly easy to see that we can get the first answer by repeatedly doubling `l` until it exceeds `r`. For example, if `l = 4, r = 100` as given in the test case, the answer is `5`, since we can do `4, 8, 16, 32, 64`. So, we did `5-1` multiplications by 2.

However, in our multiplications, we can try multiplying by `3` once, in place of one of the multiplications by 2. For example, `4, 8, 16, 32, 96` is also valid.

What other multiplications do we have to worry about? It turns out we only need to worry about is `x` 2s, or `x-1` 2s and one 3.

This is because if we replaced two 2s with two 3s, the last number would be more than doubled, so it would be beyond the acceptable range. Similarly, if we do a 5 in place of a 2. 

So, we can easily find `x`, which is the first answer. 

Then, we need to find how many numbers `i` exist such that:
-  `i * 2^x <= r`
- `i * 2^(x-1) * 3 > r`

and how many numbers `j` such that: 
- `j * 2^(x-1) * 3 <= r`

Mutually exclude `i` and `j` to avoid doublecounting.

Every number `i` contributes one set, as there is only one way we can construct a maximal set starting with that element: `i, 2i, 4i, ... , (2^x)*i`.

Every number `j` contributes `x` sets, as there are `x-1` choices on when to multiply by 3, and we can also not multiply by 3 at all. Essentially, `x` choose `x-1`, which is `x`.

Every other number contributes 0 sets.
# D: Maximum Subarray

# E: Colored Subgraphs

# F: Strange Triples