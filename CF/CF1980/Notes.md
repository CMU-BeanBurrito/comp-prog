Notes on solutions/approaches to problems

# A: Problem Generator
We need at least m of each character 'A' - 'G'.

Simply count the frequency of each, and add max(0, m-freq) for each character to our answer.

# B: Choosing Cubes
If the cubes with the same value as the favorite (including the favorite) occupy spots [x, y], in the sorted array:
- if k <= x, the answer is NO since we remove no cubes with the fav's value
- if x < k < y, the answer is MAYBE since we remove some, but not all cubes with the fav's value
- if y < k, the answer is YES since we remove all cubes with the fav's value

# C: Sofia and the Lost Operations
There are two conditions that need to be met for the answer to be YES:
- d contains all the numbers we need for the operations
- the final element in d is present in b (since it could not have been overwritten)

The elements we need for the operations are any elements in b that differ from the their counterpart in a: a[i] != b[i] means we need 1 instance of b[i]. We might need multiple instances of b[i].

Compare the counts of elements we need (as described above) vs. the elements we have (array d). If we do not have the elements we need, answer is NO. 

Lastly we check if the final element of d is present in b. If it is, answer is YES, otherwise NO.

# D: GCD-sequence
Construct the array b as described in the problem. If it is already non-decreasing, the answer is YES because we could just remove the first or last element.

Otherwise, there is at least one location where b is decreasing. Call this position x, and gcd(a[x-1], a[x]) > gcd(a[x], a[x+1]). We will try three things (independently):
- remove a[x-1]
- remove a[x]
- remove a[x+1]

Check to see if any of these work (is the new resulting GCD-sequence non-decreasing?). If one does work, the answer is YES. If none of them work, the answer is NO.

# E: Permutation of Rows and Columns
Observe that if numbers x, y were in the same row, no operation will cause them to end up in different rows from each other. Similarly for columns. A full row/column might be moved, or the elements within that row/column might be shuffled, but all elements will be in the same row/column as the other elements in the same/row column initially.

Therefore, we can just compare that the rows and columns of the final matrix contain the same elements as the rows and columns of the initial matrix. 

To check the columns, we make a vector of sets for the initial matrix, and a vector of sets for the final matrix. Each set will contain the elements in a column for its respective matrix. To compare the sets of each matrix quickly, we sort the vector of sets for each matrix and simply iterate over the sets. If any differ, it means some elements went to different columns and the answer is NO.

Repeat the same process for rows. If both the rows' and columns' are idential, the answer is YES, otherwise it is NO.

# F1: Field Division (easy version)
To find the max size of Alice's plot with no fountains, iterate over the fountains, starting from the bottom rows and working up (after sorting by row and column). If a fountain is not the leftmost fountain in that row, skip it. For this row and all future rows, Alice can get x cells where x+1 is the leftmost fountain's column. we have seen so far (in this row and lower rows). The rows in between this fountain and the previous fountain each yield y cells, where y+1 was the previous leftmost fountain's column.

To determine if claiming a fountain increases Alice's plot size, it suffices to determine if Alice can actually claim the cell with the fountain. 3 conditions are necessary and sufficient to determine if a fountain's cell can be claimed by Alice:
- there must be no fountains further left in this row
- there must be no fountains further below in this column
- there must be no fountains further down-left in the field
 - formally, there are no fountains in the subrectangle formed by the bottom left corner of the field and the fountain in question

If a fountain can be claimed, its answer is 1. Otherwise it is 0.

# F2: Field Division (hard version)

# G: Yasya and the Mysterious Tree