# Graph Theory Patterns and Intuition

Graphs are the language of relationships. Every graph problem is usually asking one of these questions:
- Can we reach a node from another node?
- What is the cheapest or shortest way to go from A to B?
- Is there a cycle?
- Can we order tasks so dependencies are respected?
- How are the nodes connected into components?
- What is the minimum cost to connect everything?

The key idea is always the same: model the problem as nodes and edges, then use the correct traversal or optimization pattern.

---

## 1) Core Graph Ideas

### Directed vs Undirected
- Undirected graph: edge u - v means both ways are possible.
- Directed graph: edge u -> v means only from u to v.
- If the problem has dependencies, movement rules, or precedence, it is often directed.

### Weighted vs Unweighted
- Unweighted graphs: each edge has cost 1 or equal cost. BFS is usually the right tool.
- Weighted graphs: each edge has a cost. Use Dijkstra, Bellman-Ford, Prim, or Kruskal depending on the task.

### Connected vs Disconnected
- A connected component is a group of nodes reachable from each other.
- In directed graphs, we also talk about strongly connected components (SCCs): every node reaches every other node in the component.

### Cyclic vs Acyclic
- A cycle means we can go around and come back to the same node.
- DAGs (Directed Acyclic Graphs) are extremely important because they make ordering possible.

---

## 2) Graph Representation

### Adjacency List
This is the most common representation for graph problems.
- Each node stores a list of neighbors.
- Best for sparse graphs where V is large and E is relatively small.
- Very efficient for DFS/BFS and dynamic connectivity.

### Adjacency Matrix
- Matrix[i][j] = whether there is an edge from i to j.
- Good when graphs are dense and the number of vertices is small.
- More memory expensive: O(V^2).

### Weighted Adjacency List
- Each neighbor is stored as a pair: (neighbor, weight).
- Used in shortest path problems with costs.

### Adjacency Map
- Useful when node labels are not simple integers, such as strings, names, or custom IDs.
- Internally behaves like a dictionary mapping node -> neighbors.

### Intuition
If you are asked to traverse all reachable nodes, adjacency list is almost always the right structure.
If you need fast edge queries for all pairs, matrix may be simpler.

---

## 3) Traversal: BFS vs DFS

### DFS (Depth First Search)
Use recursion or a stack.
- Explore as deep as possible before backtracking.
- Great for:
  - connected components
  - cycle detection
  - path existence
  - topological sort (DFS version)
  - articulation points / bridges
  - recursive graph structure exploration

DFS pattern:
- mark node visited
- iterate over neighbors
- if unvisited, recurse

### BFS (Breadth First Search)
Use a queue.
- Explores level by level.
- Best for shortest paths in unweighted graphs.
- Works for multi-source spread problems.
- Great for:
  - shortest path in grids
  - nearest distance problems
  - infection / propagation / flooding
  - level-order graph processing

BFS pattern:
- push start node into queue
- mark visited
- pop front node
- process neighbors and push unvisited ones

### Intuition
- BFS gives the minimum number of steps if every edge has equal cost.
- DFS is better when we want to fully explore structure, detect cycles, or build a recursive ordering.

---

## 4) Connected Components and Graph Regions

A connected component is a maximal set of vertices connected to each other.

### Component Pattern
- Start from any unvisited node.
- Run DFS/BFS to mark all reachable nodes.
- Count how many times this happens.

This is the pattern behind:
- number of islands
- flood fill
- component counting
- region detection in grids

### Grid Graphs
A grid is a graph where:
- each cell is a node
- moves are edges between neighboring cells

Typical moves:
- 4-directional: up, down, left, right
- 8-directional: also diagonals

This turns many matrix problems into graph problems.

### Multi-source BFS
Some problems start from multiple sources simultaneously.
Examples:
- rotten oranges
- fire spreading through a grid
- propagation in time steps

Pattern:
- initialize all starting positions in the queue
- process all nodes in layers
- each step expands by one distance unit

This is equivalent to BFS from several starting nodes at once.

---

## 5) Cycle Detection

### Undirected Graph Cycle Detection
Typical pattern:
- do DFS from each node
- keep track of parent
- if a visited neighbor is not the parent, then there is a cycle

Why it works:
- in an undirected graph, a back edge to an already visited node but not the direct parent means we have looped back.

### Directed Graph Cycle Detection
Use:
- recursion stack / state array (visiting / visited)
- or Kahn's algorithm to detect if all nodes were processed

If we revisit a node currently in the recursion stack, we found a cycle.

### Intuition
A cycle means a path starts and ends at the same node without repeating edge restrictions or without a valid topological order.

This is important for:
- prerequisites
- dependency graphs
- scheduling problems
- validating graph structure

---

## 6) Topological Sort and DAGs

A DAG is a directed acyclic graph, meaning no directed cycles.

A topological sort is an ordering of vertices such that for every edge u -> v, u appears before v.

### Why it matters
If tasks depend on each other, a topological order gives a valid order to do them.

Examples:
- course scheduling
- build ordering
- dependency resolution
- event ordering

### DFS Topological Sort
- do DFS on each node
- when finished visiting all neighbors, push node to a stack
- reverse the stack to get the order

### Kahn's Algorithm
- compute in-degree for every node
- push all nodes with zero in-degree into a queue
- remove them and reduce the in-degree of neighbors
- process until all nodes are removed

If the number of processed nodes is less than V, the graph has a cycle.

### Intuition
Think of it as "if A must happen before B, then A should appear earlier in the list."

---

## 7) Shortest Path Patterns

### Unweighted Shortest Path: BFS
If all edges have equal cost, BFS gives the minimum distance.

Use when:
- move cost is 1 per step
- shortest path in grid / maze / ladder / level graph
- minimum number of operations

### Weighted Shortest Path Without Negative Edges: Dijkstra
Dijkstra works on graphs with non-negative weights.

Algorithm pattern:
- initialize all distances to infinity
- source distance = 0
- use min-priority queue
- repeatedly take the smallest known distance
- relax all outgoing edges

If new distance is smaller, update it.

Use when:
- road networks
- minimum cost from one source
- shortest path in positive weighted graphs

### Weighted Graphs With Negative Edges: Bellman-Ford
Bellman-Ford relaxes all edges V - 1 times.

Why V - 1?
- the longest simple path in a graph with V vertices can have at most V - 1 edges.

Use when:
- negative weights are allowed
- we need to detect negative cycles

Negative cycle detection:
- after V - 1 relaxations, run one more pass
- if any edge can still relax, a negative cycle exists

### All-Pairs Shortest Paths: Floyd-Warshall
This computes shortest paths between every pair of nodes.

Core idea:
- let dist[i][j] be the best known path from i to j
- try every intermediate node k
- update:
  dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])

Use when:
- the graph is small enough to store a full matrix
- you want shortest path between all pairs

### Probability / Max-score Variation
Some problems ask for the path with maximum probability, not minimum cost.
- the idea is still relaxation
- but instead of comparing sums with minimum, we compare using maximum probability
- the graph still represents states and transitions, just with a different objective function

### Intuition
Shortest path algorithms are all about updating the best known answer for each node and reusing it to improve others.

---

## 8) Minimum Spanning Tree (MST)

A spanning tree connects all vertices without cycles, using some subset of edges.

A minimum spanning tree minimizes total edge weight.

### Why it matters
If you need to connect all nodes at minimum total cost, this is the target structure.

### Prim's Algorithm
- Start from one node
- keep adding the cheapest edge from the current tree to a new node
- use a priority queue

This is a greedy approach.

### Kruskal's Algorithm
- sort all edges by weight
- add edges if they connect two different components
- use DSU (Union-Find) to check connectivity efficiently

This is also greedy.

### Intuition
The MST is the cheapest way to connect everything while avoiding cycles.

---

## 9) DSU / Union-Find

Disjoint Set Union is used when we need to manage connected components efficiently.

Operations:
- find(x): return the representative of x's component
- union(x, y): merge two components

Optimizations:
- path compression: flatten the tree during find
- union by size or rank: keep trees shallow

### Typical uses
- cycle detection in Kruskal
- connectivity queries
- merging groups of nodes
- checking whether adding an edge would create a cycle

### Intuition
DSU is the perfect tool when the question is about whether two nodes are already connected, or when groups are being merged repeatedly.

---

## 10) Strongly Connected Components (SCC)

In a directed graph, a strongly connected component is a group of vertices where each vertex can reach every other vertex in the group.

### Why this matters
It tells us which parts of a directed graph are mutually reachable.

### Kosaraju's Algorithm
Two-pass DFS strategy:
1. perform DFS on the original graph and push nodes to a stack in finishing order
2. build the reverse graph
3. process nodes in reverse finishing order on the reversed graph

This counts SCCs.

### Tarjan's Algorithm
Single DFS pass with:
- tin[node]: time of first visit
- low[node]: earliest ancestor reachable from node

If low[child] > tin[node], the edge is a bridge in undirected graphs. In SCC logic, this idea also helps identify articulation and cycle structure.

### Intuition
SCCs are the directed-graph equivalent of connected components, but stronger: reachability must work in both directions.

---

## 11) Bridges and Articulation Points

### Bridge
An edge is a bridge if removing it increases the number of connected components.

Bridge detection uses DFS with low-link values.

Condition:
- if low[child] > tin[parent], then the edge parent -> child is a bridge

### Articulation Point
A vertex is an articulation point if removing it disconnects the graph.

Condition:
- if low[child] >= tin[parent], then parent is an articulation point

### Intuition
These are the critical connections or critical vertices that hold the graph together.

These are useful in:
- network robustness
- communication graph analysis
- critical path analysis
- graph connectivity vulnerability

---

## 12) Special Graph Patterns in Problems

### Course Schedule / Dependency Ordering
- convert prerequisites into directed edges
- use topological sort
- if not all nodes can be processed, a cycle exists

### Path Existence / Maze / Reachability
- convert each cell or state to a node
- BFS/DFS explore the graph
- use visited to avoid revisiting

### Islands / Flood Fill / Regions
- each land cell is a node
- neighboring land cells are connected
- DFS/BFS flood all connected cells
- count connected groups

### Rotting Oranges / Infection Spread
- model as a multi-source BFS
- all initially rotten oranges are sources
- each step spreads to neighboring fresh oranges

### Graphs with State
Sometimes a problem is not literally a graph in the input, but we create one.
Examples:
- minimum steps in a puzzle
- shortest path in a state-space graph
- moving through a maze with rules

The key is to define:
- what is a state?
- what is an edge?
- what is the optimization objective?

---

## 13) Pattern Checklist for Graph Problems

Use this quick checklist:

1. Is the graph directed or undirected?
   - directed -> topological sort, SCC, cycle detection

2. Are edges weighted or unweighted?
   - weighted -> Dijkstra, Bellman-Ford, Prim, Kruskal
   - unweighted -> BFS, DFS

3. Do we need minimum steps?
   - BFS

4. Do we need minimum cost with non-negative weights?
   - Dijkstra

5. Are negative weights possible?
   - Bellman-Ford

6. Do we need to connect all nodes with minimum cost?
   - MST: Prim or Kruskal

7. Are we trying to figure out if there are cycles?
   - DFS with parent / recursion stack / Kahn

8. Do we need to count connected regions?
   - DFS/BFS on components

9. Do we need to process order with dependencies?
   - topological sort

10. Are we checking if an edge or vertex is critical?
   - Tarjan low-link values

11. Are we working on a grid?
   - convert to graph and use BFS/DFS

12. Are we merging groups repeatedly?
   - DSU

---

## 14) Common Mistakes and Debugging Intuition

- Forgetting to mark visited nodes causes infinite loops in graphs.
- Using BFS for weighted graphs where costs differ is incorrect unless all edge costs are equal.
- In undirected graphs, always avoid going back to the parent unless specifically allowed.
- In topological sort, the reverse of DFS finishing order gives a valid ordering.
- In Bellman-Ford, do not forget the final negative-cycle check.
- In MST problems, avoid cycles by checking connectivity rather than simply counting edges.
- In grid problems, define the neighbor directions clearly before traversing.

---

## 15) Final Intuition

Graph problems are usually solved by one of four ideas:
- explore structure (DFS/BFS)
- order dependencies (topological sort)
- optimize path cost (Dijkstra / Bellman-Ford / Floyd-Warshall)
- merge and manage connectivity (DSU, MST, SCC, bridges)

The main skill is not memorizing formulas, but identifying the correct abstraction:
- what are the nodes?
- what are the edges?
- what is the objective?
- which traversal or optimization fits the structure?

Once that is clear, most graph problems become pattern-based rather than ad hoc.
