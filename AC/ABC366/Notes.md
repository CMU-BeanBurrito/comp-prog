Notes on solutions/approaches to problems

# A: Election 2
Majority means greater than half of the total. So, see if either Takahashi or Aoki have over half the total votes.

# B: Vertical Writing
Take all the strings into a 2D char array, written normally. Asterisks are required if there is a gap in a column, above which there are characters in other strings. Fill these in adding asterisks to each string such that it is at least the same length as the strings above it.

Now, we need to "rotate" the array. We reading left to right, with each column in the original array being printed on a row. We are also reading from the bottom of the column to the top.

# C: Balls and Bag Query
Use a map to track the quantity of balls with each integer, and keep track of how many integers have at least one ball in the bag. So, when a ball gets added, and its integer currently has 0 balls, this is a new distinct integer, so increment the count. Similarly, if a ball is removed from the bag, and it was the last ball with that integer, decrment the count of distinct integers with balls in the bag.

# D: Cuboid Sum Query (TODO)
Use 3D prefix sum. See REFERENCE.md for information about 3D Prefix Sums.

# E: Manhattan Multifocal Ellipse

# F: Maximum Composition

# G: XOR Neighbors