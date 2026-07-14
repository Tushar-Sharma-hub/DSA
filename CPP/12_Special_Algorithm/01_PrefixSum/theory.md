# Prefix Sum Theory

- Pattern: compute cumulative sums so queries for subarray totals can be answered quickly.
- Prefix array: `prefix[i]` stores the sum of original elements from the start through index `i`, making range sums constant time.
- Query formula: for a range `[l, r]`, use `prefix[r] - prefix[l-1]` to get the sum without re-adding each element.
- Common use: speed up repeated sum calculations, count subarrays, and support sliding window differences.
- Efficiency: prefix sums reduce repeated computation and allow many range-based queries after a single `O(n)` preprocessing pass.
