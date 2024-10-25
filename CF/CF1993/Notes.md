Notes on solutions/approaches to problems

# A: Question Marks
? answers are definitely wrong and will not add to our answer.

Count frequency of each of the other answers (A, B, C, D).

For each of these, we could have gotten up to n of them correct, so each adds min(freq, n) to our answer.

# B: Parity and Sum
If all elements are the same parity, answer is 0.

Otherwise, we have some evens and some odds. We cannot change the parity of odd numbers, so our goal is to convert all numbers to odd.

We observe that if we use an odd number o to convert an even number e, and o < e, then we end up with o+e and e. So, we need to use another operations to convert e to o+e+e.
So, our "working odd" increases by e every time we convert an even number e.

Since that scenario requires an extra operation, we have 2 avenues to consider:
- Spend 2 operations to convert the largest even immediately. This will ensure that all other evens require 1 operation to convert.
- Attempt to to convert the evens in ascending order, in the hopes that by accumulating the even values into our odd number, we never have to spend 2 operations on any even.

So, our answer is num(evens) if the second strategy is successful, or num(evens)+1 otherwise.

We try the 2nd strategy, using the largest odd and converting the evens in ascending order while increasing our odd with their value. If we encounter an even that is greater than our odd, the answer is num(evens)+1.

Otherwise, it is num(evens).

# C: Light Switches
Clearly, if any two switches' installation times differ by `(2i+1)*k`, the answer is -1. This is because these two switches are completely desynced, as one will turn on right as the other turns off, forever.

We can see that a full cycle for any switch takes 2k time. Our strategy is to keep track of the contiguous window of time that all previously seen switches will be on, modulo 2k (sort of).

Initially, this window is infinite since we have seen no switches - so all of them are vacuously on at all times. Call this segment `[l, r]`, initialize to any segment that can capture the whole period. I used `[0, 3*k]`.

For each switch, we find its installation time modulo 2k, call this il. Therefore this switch is on from `[il, il+k-1]`. Note that `il+k-1` may exceed `2k`, this is ok and `[l, r]` will be within `[0, 2k-1]` after integrating at most 2 switches.

To find the intersection of the segments, we first see if they overlap. If they do, our job is easy: `l = max(l, il), r = min(r, ir)`.

If they are disjoint, it could be due to modulo wrapping and there is actually an overlap. Decrement the greater segment (`[l, r] or [il, ir]`) by `2k`. If they are still disjoint, there is no solution (-1).

Otherwise, we now have an overlap and can do `l = max(l, il), r = min(r, ir)`.

Once we are done iterating over each switch, we have `[l, r]`. Clearly, l is the earliest time in this window. The question is, how many cycles have elapsed - however many cycles it took for the last switch to be installed.

Find the last switch to be installed (maximum value in the input array) and round down to the nearest multiple of `2k`, call it `p`. This switch was installed at time `p + q`. If `l < q`, this switch was not installed yet when the window of this cycle happened. So, go to the next cycle (`p+2k+l`).

How do we know that `l < q <= r` cannot be true? If this switch was installed at time q, its segment would be `[q, q+k-1]`. So its overlap with `[l, r]` would be `[q, r]`.

# D: Med-imize


# E: Xor-Grid Problem

# F1: Dyn-scripted Robot (Easy Version)

# F2: Dyn-scripted Robot (Hard Version)
