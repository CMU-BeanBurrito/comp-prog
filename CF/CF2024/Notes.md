Notes on solutions/approaches to problems

# A: Profitable Interest Rate
If a >= b, clearly we can just put all our money in the Profitable account.

Otherwise, each coin we put into the Unprofitable account reduces the Profitable requirement by 2 coins, but we have one less coin to put in the Profitable deposit. So the difference between our available coins and the Profitable deposit requirement decreases by 1.

So, if b >= 2*a, we can't deposit any coins in the Profitable deposit.

Otherwise, we need to use b-a coins to reduce the difference between Profitable deposit's requirement and our available coins from b-a to 0. 

So we will have a-(b-a) coins left, or 2*a-b.

# B: Buying Lemonade

Initially, if we take 1 can from each of the n slots, we will get n cans. 

However, if one of the slots runs out, then on the next "round", we might press its button in the future. However, after we press it once and don't get a can, we know not to press it anymore.

Our strategy is then as follows. Perform the following "round" until we get enough cans:
- call the minimum nonzero number of cans in any slot m
- press the button from all non-empty slots m times or until we have k cans total
- if we need more cans, there is at least one slot that has no cans now. since we don't know which ones are empty, we need to spend one press per machine that became empty this round.
- repeat until we have k cans

We can use a map which will automatically sort the slots by initial cans as well as track how many slots have a certain number of cans. Instead of continually updating how many cans are in each slot, we just keep track of how many cans we've taken from each slot since in each round we take the same number of cans from each slot.

# C: Concatenation of Arrays

The pairs should be sorted by sum of the two elements.

Proof:

First note that inversion within a pair can never be resolved, so they should be ignored.

We have two pairs (a, b) and (c, d). Suppose (a, b) is currently placed in front of (c, d). 

c+d < a+b, WLOG a <= b. We want to show that swapping the order of these pairs is optimal.

- suppose c >= a and c >= b

then d is strictly less than both, 2 inversions
flipping removes 2 inversions
adds at most 2 inversions

- suppose c >= a and c < b


c < b is 1 inversion
d must be < b, another inversion
flipping removes 2 inversions
adds at most 2 inversions

- suppose c < a and c < b

c < a <= b, 2 inversions
flipping it removes 2 inversions
adds at most 2 inversions

In all cases, swapping the pairs at least maintains the number of inversions, and potentially reduces it.

Simply sort the pairs by sum and then output them in that order.

# D:

# E:

# F: 