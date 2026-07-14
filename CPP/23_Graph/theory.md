# Graph Theory Patterns

## Graph Representation
- Adjacency List: store each node's neighbors in a vector or list so traversal is efficient for sparse graphs.
- Weighted Adjacency List: store `(neighbor, weight)` pairs for graphs with edge costs.
- Adjacency Map: use maps when node labels are not simple integers or when flexible key lookup is needed.

## Traversal Patterns
- BFS: use a queue to visit nodes in increasing distance from the start. This is ideal for shortest paths in unweighted graphs and level-order processing.
- DFS: use recursion or a stack to explore deeply before backtracking. DFS is useful for connected components, path finding, and cycle detection.

## Cycle Detection
- Undirected cycle detection: use DFS and track the parent node. If a visited neighbor is not the parent, there is a cycle.
- Directed cycle detection: use recursion stack or coloring to detect back edges. If you revisit a node currently on the recursion path, a cycle exists.
- Course schedule: model prerequisites as directed edges. If the graph contains a cycle, courses cannot be completed in the required order.

## Topological Sort
- DFS-based order: perform DFS and add nodes to a list after visiting all neighbors; reverse the list to obtain a valid ordering.
- Kahn's algorithm: compute indegrees, enqueue nodes with zero indegree, and remove them while decrementing neighbors' indegrees.
- Course schedule problems: use topological sort to verify that all prerequisites can be satisfied and to produce a valid course ordering.

## Shortest Paths and Dijkstra
- Dijkstra's algorithm: maintain the shortest known distance to each node and relax edges from the closest node using a min-priority queue.
- Pattern: initialize distances with infinity, set the source distance to zero, and pull the smallest-distance node at each step.
- Use case: weighted graphs without negative edges where the goal is a minimum distance from one source.

## Grid and Component Patterns
- Path existence: treat grid cells as graph nodes and use BFS or DFS to determine whether one location reaches another.
- Connected components: use DFS or BFS to mark all nodes in a component, such as counting islands or flood fill regions.
- Multi-source BFS: start from multiple initial nodes at once, useful for problems like rotting oranges where spread happens in parallel.
