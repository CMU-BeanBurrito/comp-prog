Notes on solutions/approaches to problems

# A: Musical Puzzle

We need to record each pair of adjacent characters. Maintain a set of the 2-length strings we've recorded so far. For each pair, check if we've already recorded it. If not, add it to the set. The answer is the size of the set at the end. 

# B: Restore the Weather

# C: Vlad Building Beautiful Array

Let's track the minimum odd number `o` in the array. If there are none, clearly the answer is YES. Now, let's look for an even number that is less than `o`. If there is an even number `e, e < o`, the answer is NO. Otherwise, the answer is YES.

Why?

Suppose we found an even number `e < o`. Either `e` must be transformed into a positive odd number, or `o` must be transformed into a positive even number. 

If we are trying to transform `e`, then we need to find an odd number that is smaller than it to make it odd but keep it positive. Since `e < o` and `o` is the minimum odd, this is not possible.

If we are trying to transform `o`, then we need to find an odd number than is smaller than `o` to make it even but keep it positive. Since `o` is the minimum odd, this is not possible.

So we've clarified the first two parts of our answer. The third part is: if we do not find any even numbers `e, e < o`, the answer is YES. This means the minimum odd number `o` is less than all even numbers. So, we can transform all these even numbers to positive odd numbers by subtracting `o` from them.

# D: Flipper

# E: Round Dance

Construct an undirected graph using the partner information. Be sure not to have any double edges.

This graph will consist of cycles and bamboos. The cycles are confirmed complete round dances. A bamboo can either be a complete round dances on its own, or linked with any number of other bamboos to create a single round dance.

So the minimum number of round dances is if all bamboos are combined to create 1 round dance: num cycles + 1 (or num cycles if there are no bamboos).

The maximum number of round dances is if each bamboo is treated a single round dance: num connected components (num bamboos + num cycles).

# F: Ira and Flamenco

# G: Ksyusha and Chinchilla