// 210. Course Schedule II
// There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. 
// You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.
// For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
// Return the ordering of courses you should take to finish all courses. 
// If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.

class Solution {
public:
    bool isCycle(int node,vector<vector<int>>& graph,vector<bool> & vis,vector<bool>& path){    
        vis[node]=true;
        path[node]=true;
        for(int i:graph[node]){
            if(!vis[i]){
                if(isCycle(i,graph,vis,path)) return true;
            }
            else if(path[i]) return true;
        }
        path[node]=false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& graph) {
        vector<bool> vis(numCourses,false);
        vector<bool> path(numCourses,false);
        for(int i=0;i<vis.size();i++){
            if(!vis[i]){
                if(isCycle(i,graph,vis,path)) return false;
            }
        }
        return true;
    }
    void dfs(int node, vector<vector<int>>& adj,vector<bool>& visited,vector<int>& ans) {
        visited[node] = true;
        for (int neighbour : adj[node]) {
            if (!visited[neighbour]) {
                dfs(neighbour, adj, visited, ans);
            }
        }
        ans.push_back(node);
    }
    vector<int> findOrder(int n, vector<vector<int>>& v) {
        vector<vector<int>> graph(n);
        for(int i=0;i<v.size();i++){
            graph[v[i][0]].push_back(v[i][1]);
        }
        if(!canFinish(n,graph)) return {};
        vector<bool> visited(n,false);
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i,graph,visited,ans);
            }
        }
        return ans;
    }
};