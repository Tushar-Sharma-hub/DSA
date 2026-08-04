// 1334. Find the City With the Smallest Number of Neighbors at a Threshold Distance
// There are n cities numbered from 0 to n-1. Given the array edges where edges[i] = [fromi, toi, weighti] 
// represents a bidirectional and weighted edge between cities fromi and toi, and given the integer distanceThreshold.
// Return the city with the smallest number of cities that are reachable through some path and whose distance is
// at most distanceThreshold, If there are multiple such cities, return the city with the greatest number.
// Notice that the distance of a path connecting cities i and j is equal to the sum of the edges' weights along that path.

//Just find all pairs shortest distance using Floyd Warshall algorithm and then count the number of cities reachable from each city within the distance threshold.
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n,vector<int>(n,INT_MAX));
        for(int i=0;i<n;i++){
            dist[i][i]=0;
        }
        for(int i=0;i<edges.size();i++){
            dist[edges[i][0]][edges[i][1]]=edges[i][2];
            dist[edges[i][1]][edges[i][0]]=edges[i][2];
        }
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if(dist[i][k]!=INT_MAX && dist[k][j]!=INT_MAX){
                        dist[i][j] = min(
                            dist[i][j],
                            dist[i][k] + dist[k][j]
                        );
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<dist[i][j]<<" ";
            }
            cout<<endl;
        }
        int min=INT_MAX,ans;
        for(int i=0;i<n;i++){
            int c=0;
            for(int j=0;j<n;j++){
                if(i!=j && dist[i][j]<=distanceThreshold) c++;
            }
            if(min>=c){
                min=c;
                ans=i;
            }
        }
        return ans;
    }
};