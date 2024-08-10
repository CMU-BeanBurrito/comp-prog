Notes on solutions/approaches to problems

# A

Call an element "eligible" if it's possible for us to make it the last remaining element. 
Then, we are looking for the maximum eligible element.
In order for an element to eligible, there have to be an even amount of elements on each side of it.
Since n is odd, if there are an even amount of elements to the left of an element there are also
an even amount of elements to the right of it.
So, eligible elements are the 0th element, 2nd, 4th, 6th, etc...
Iterate over these and find the largest one.