# Advanced Sorting Theory

- Divide-and-conquer: split the array into halves, sort each half, and merge the results into a fully sorted list.
- Merge sort: recursively sort left and right halves, then merge them in linear time, guaranteeing `O(n log n)` complexity.
- Quick sort: choose a pivot, partition elements around it, and recursively sort the partitions, typically fast on average but worst-case `O(n^2)` without good pivot selection.
- Heap sort: build a heap structure and repeatedly extract the top element to produce a sorted sequence in `O(n log n)` time.
- Choosing algorithms: prefer advanced sorts for larger datasets, and use stable vs unstable sorting depending on whether equal elements must preserve original order.
