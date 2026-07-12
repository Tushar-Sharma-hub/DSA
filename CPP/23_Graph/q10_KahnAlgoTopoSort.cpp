// 210. Course Schedule II
// There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. 
// You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.
// For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
// Return the ordering of courses you should take to finish all courses. If there are many valid answers, 
// return any of them. If it is impossible to finish all courses, return an empty array.


//Using kahn's algorithm for topological sorting. In this approach, we first calculate the indegree of each node in the graph.
// Then we add all the nodes with indegree 0 to a queue. We then process the nodes in the queue one by one, 
//adding them to the answer vector and reducing the indegree of their neighbors. 
//If any neighbor's indegree becomes 0, we add it to the queue
//T.C= O(V+E) S.C=O(V+E)
class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& v) {
        vector<vector<int>> adj(n);
        for(int i=0;i<v.size();i++){
            adj[v[i][1]].push_back(v[i][0]);
        }
        vector<int> indeg(n,0);
        for(int i=0;i<n;i++){
            for(int nb:adj[i]){
                indeg[nb]++;
            }
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indeg[i]==0) q.push(i);
        }
        vector<int> ans;
        while(q.size()!=0){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(int nb:adj[node]){
                indeg[nb]--;
                if(indeg[nb]==0) q.push(nb);
            }
        }
        if(ans.size() != n)
            return {};
        return ans;
    }
};