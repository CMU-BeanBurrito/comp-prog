Notes on solutions/approaches to problems

# A: False Alarm
When we reach the first closed door, we have no option except to use the button.

When we use the button, we can get through the next `x` doors, regardless of whether they are closed or not.

However, if there are any additional closed doors that are more than `x` spots past the first closed door, we cannot make it to the end.

So, we find the first and last closed doors:
- If there are none, clearly the answer is `YES`
- If the distance between the first and last closed doors is less than `x` (or there is only one closed door), the answer is `YES`
- Otherwise, the answer is `NO`.

Note: why is the answer `NO` if the distance between first and last is exactly `x`? The button's effect lasts `x` seconds, so it will end as we get to the last closed door and we will not be able to get past it.

# B: Shrink
We want to ensure that the maximum number is never at an endpoint (until we get down to just 1 and 2). To do so, we construct the permutation from the middle outwards. Example for 5:

- 5
- 5, 4
- 3, 5, 4
- 3, 5, 4, 2
- 1, 3, 5, 4, 2

We can see that this construction can be simplified to printing all odd numbers from 1 to n in ascending order, then printing all even numbers from n to 2 in descending order (or vice versa).

# C: Cool Partition

# D: Retaliation

# E: Lost Soul

# F: Wildflower

# G: Omg Graph

# H: Incessant Rain