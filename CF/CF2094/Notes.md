Notes on solutions/approaches to problems

# A: Trippi Troppi
Iterate over the 3 strings and print out the first character of each.

# B: Bobritto Bandito
Walk the right wave of the plague back as far left as possible (up until 0). If there are more days to backtrack, walk back the left wave as far as needed.

# C: Brr Brrr Patapim

Note: explanation uses 1-indexing.

Read in the grid G. Iterate across G filling in answer according to formula in problem statement: `ans[i+j] = G[i][j]`. This will fill all of `ans` except `ans[1]`.

`ans[1]` is whatever element in `[1, n]` has not been seen yet.

# D: Tung Tung Sahur

Two pointer problem, one for each string.

We will iterate over "clusters" present in each string, a cluster is a maximal segment with one type of chararacter.
e.g. LLLRLLRRRL -> LLL R LL RRR L

If the number of clusters in `p` does not equal the number of clusters in `s`, the answer is `NO`.
Also, the order of the cluster types must be the same. If `p` starts with an `L` cluster, and `s` starts with an `R` cluster, and the answer is `NO`.

Now, we examine the first cluster of `p` and `s`. If the length of the cluster in `p` is `x` and the length of the cluster in `s` is `y`, then `x <= y <= 2x`, as each hit in `p` corresponds to either 1 or 2 sounds in `s`. If `y` is outside this range, these clusters are inconsistent and the answer is `NO`.

If these clusters are consistent, we move to the second cluster in `p` and the second cluster in `s`. If each cluster in `p` is consistent with the corresponding cluster in `s`, the answer is `YES`. If we find any pair of inconsistent clusters, the answer is `NO`.

# E: Boneca Ambalabu

Strategy: Find the initial sum of the array. Then for each element, determine how much the sum will change if we select it as the special element `a[k]`. Then, choose the most positive change to the sum.

How to determine the impact on the sum if we choose a certain element? If we choose element `x` as the special element, at any bit position that `x` has a 1, it will flip that bit position for all elements. So if `u` elements have a 1 at that bit, and `n-u` elements have a 0 at that bit, we will lose `u` times the value of this bit, and gain `n-u` times the value of this bit.

First, for each bit (0 to 29), count how many elements have a 1 at this bit. Then, for each element, use the above process for each bit to calculate how much selecting this element will impact the overall sum. Track the most positive change and add it to the original sum.

# F: Trulimero Trulicina

There may be other ways to do this problem (such as replacing columns with rows or another approach entirely).

There are 2 cases: `k|m`, or it does not.

If `k|m`, and we do this (for example, `n=6, m=6, k=3`):
`1 2 3 1 2 3
1 2 3 1 2 3
1 2 3 1 2 3`

This will not work. To resolve this, each row should be a cyclic shift of the previous row:
`1 2 3 1 2 3
2 3 1 2 3 1
3 1 2 3 1 2`

It's easy to see that there will be no adjacent cells with identical elements.

If `k` does not divide `m`, then we can safely do `1, 2, 3....k ` in order from left to right, top down (the same way one reads or writes across a page).

For example: `n=6, m=4, k=3`
`1 2 3 1
2 3 1 2
3 1 2 3
1 2 3 1
2 3 1 2
3 1 2 3`

It's also easy to see that this is valid.

# G: Chimpanzini Bananini

# H: La Vaca Saturno Saturnita