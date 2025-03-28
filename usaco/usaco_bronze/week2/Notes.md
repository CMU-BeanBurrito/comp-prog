Notes on solutions/approaches to problems

# Stuck in a Rut

General strategy:
- Analyze each pair of cows
- Track every cow's grass consumption

The key is to compare cows that are "closer" to each first.
The reason for this is that cows whose paths will cross earlier will influence the interactions that the other cow has with cows that are further away.

For example:
- Suppose cow A and cow B are very close by. Their paths intersect after only one or two hours
- There is cow C very far away. If cow B did not exist, cow A and cow C would have their paths intersect after many hours. cow B and cow C's paths never intersect.

In this example, suppose that cow A will reach the intersection first, and cow C will stop here since cow A already ate the grass. However, in reality, cow C will get infinite grass since it cow A's path was already intercepted by cow B.

Therefore, if we analyzed cows A and C first, we would come to the incorrect conclusion that cow C would be stopped by cow A. When we analyze cows A and B, we would see that cow A gets stopped and update cow A's grass accordingly, but we would have to check every other cow that A's path would have crossed (e.g. cow C) and update their values as well.

This quickly becomes untenable as we have to iterate over every pair, and for each pair, we may have to check all previous pairs. There are n^2 pairs, so this total runtime would be n^4.

However, if we check the pairs in ascending order of how long it takes for the two cows' paths intersect, we will know that no cow's path will have to be retroactively extended. Over time, cows' grass will be monotonically decreasing as paths are intercepted by more distant cows. 

To determine this order, we calculate how long it will take the two cows to reach the intersection of their paths (if one exists), and sort the pairs in ascending order of this time.

First, define an "intersection point" between two cows/paths as the following: In the absence of all other cows, the intersection point is the point where the two cows' paths would cross. Paths are still considred to "intersect" even if one or both cows do not reach the intersection point.

Conversely, we'll define paths "meet" as the actual meeting of the paths at the intersection point. The cows do not have to arrive at the intersection point at the same time, but they must both reach it at some point. Meeting is a subset of intersecting.

When we analyze a pair, consider the following cases:
- paths do not have an intersection point. neither meeting nor intersecting
 - more specifically, paths are parallel, or they are divergent (e.g. cow A is going north, cow B is going east, but cow B started further south than cow A)
- cows reach the intersection point at different times, the one that reaches it second stops there. meeting and intersecting
- cows reach the intersection point at the same time, sharing the grass and continuing on afterwards. meeting and intersecting
- cows paths' would intersect in the absence of other cows, but at least one of the cow's paths was cut short but a third cow. intersecting but not meeting
