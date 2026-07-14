# Sliding Window Theory

- Fixed window: maintain a window of constant size and update the result as the window moves, using the previous window's state.
- Variable window: expand and contract the window to satisfy a condition such as sum, count, or distinct values.
- Window metrics: track the current sum, maximum, minimum, or frequency count inside the window without recomputing from scratch.
- Typical problems: longest substring without repeating characters, smallest subarray with at least a given sum, and maximal sum windows.
- Efficiency: sliding-window algorithms often achieve `O(n)` time by reusing work from overlapping ranges.
