Notes on solutions/approaches to problems

# A: Penchick and Modern Monument

Official editorial has a very good explanation.

# B: Penchick and Satay Sticks
Claim: Each satay stick will only move by at most one position.

Proof: 
Case 1: Satay stick `i` has no neighbors that differ from stick `i` by 1 length. This stick cannot move at all in this position.
Case 2: Satay stick `i` has 2 neighbors that differ from stick `i` by 1 length. After stick `i` swaps once, it will no longer have any neighbors that differ by length `1` except swapping back (which is pointless).
Case 3: Satay stick `i` has one neighbor that differs from stick `i` by 1 length. After stick `i` swaps with this neighbor, it is now adjacent to the other stick that differs by length 1. We would only make both of these swaps if both of these neighbors were longer than stick `i` or both of the neighbors were shorter than stick `i`. This isn't possible as for both to differ from stick `i` by length 1, one would hae to be longer than `i` by 1 ,the other would have to be shorter than `i` by 1.

In all cases, stick `i` cannot move more than 1 position. So each stick must be within 1 index of its sorted position.

# C: Penchick and BBQ Buns
*1-indexed

If `n` is even, we can just do `1 1 2 2 3 3 ....` as each filling is only used twice, and 1 index apart which is clearly a perfect square.

If `n` is odd, one filling needs to be used at least 3 times since no filling can be used just once. In order for a filling to be used 3 times in a valid fashion, the distances between the 3 positions must be the squares of a Pythagorean triple. For example, `(1, 10, 26)`. These indices are separated by distances `(9, 16, 25)`, which are all perfect squares. The smallest of these is `(9, 16, 25)`, which means that `n > 25` for this to work.

If `n` is odd and `n <= 25`, the answer is `-1` and there is no solution because no Pythagorean triple can be used.

Otherwise, we can just put one particular filling in buns 1, 10, 26. Positions 2-9 can easily be filled by consecutive pairs. 23 and 27 can be another pair. Then 11-22 can be consecutive pairs, 24-25 can be a pair. For numbers greater than 27, just add more consecutive pairs. For example, for `n = 31`, 28-29 is a pair, 30-31 is a pair.

# D: Penchick and Desert Rabbit

# E: Penchick and Chloe's Trees

# F: Penchick and Even Medians