// 207. Course Schedule
// There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. 
// You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

// For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
// Return true if you can finish all courses. Otherwise, return false.
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
    bool canFinish(int numCourses, vector<vector<int>>& v) {
        vector<vector<int>> graph(numCourses);
        for(int i=0;i<v.size();i++){
            graph[v[i][0]].push_back(v[i][1]);
        }
        vector<bool> vis(numCourses,false);
        vector<bool> path(numCourses,false);
        for(int i=0;i<vis.size();i++){
            if(!vis[i]){
                if(isCycle(i,graph,vis,path)) return false;
            }
        }
        return true;
    }
};