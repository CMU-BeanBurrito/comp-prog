Notes on solutions/approaches to problems

# A: Wonderful Sticks
Since the stick lengths are distinct, we know there is exactly one stick with length 1, exactly one stick with length 2, etc. up to `n`.

Work backwards:
If the last requirement is `<`, then the last stick must be the shortest (length 1).
If the second to last requirement is `<`, then the second to last stick must be the shortest of the remaining ones (length 2).

Track the shortest and longest of the remaining sticks. If we work backwards, the stick we choose for that spot will always be the shortest or the longest.

# B: Wonderful Gloves
If the answer is `x`, and we pick `x-1` gloves, there is a chance we only have a matching pair for `k-1` different colors.

We can reframe this as we picked all our gloves except one hand for each of `n-k+1` colors. For example, say `n = 5, k = 3`.
For 2 colors, we picked all the gloves (left and right). For the remaining 3 colors, we picked all the same hand for that color. Not necessarily the same hand for all 3 colors. For example, all left for color 3, all right for color 4, all left for color 5.

So, sort the colors based on the lesser hand count for that color, formally: `min(l[i], r[i])`. Now, for the lowest `n-k+1` pairs, we sum their minimum hand count. This is the fewest possible number of unpicked gloves remaining before we have pairs of `k` colors. So, we have picked every other glove, subtract this sum from the total sum of all gloves. Then add 1 since any glove we pick now will get us pairs of `k` colors.

# C: Wonderful City

# D: Wonderful Lightbulbs

# E: Wonderful Teddy Bears

# F: Wonderful Impostors

# G: Wonderful Guessing Game

# H: Wonderful XOR Problem