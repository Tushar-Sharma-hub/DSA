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

//In dijikstra approach we will just run the dijikstra algo from every city and count the number of cities reachable 
//within the threshold distance and return the city with minimum count. If there are multiple such cities, 
//return the city with the greatest number.
class Solution {
public:

    int dijkstra(int src,
                 vector<vector<pair<int,int>>>& adj,
                 int n,
                 int threshold) {

        vector<int> dist(n, INT_MAX);

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        dist[src] = 0;
        pq.push({0, src});

        while(!pq.empty()){

            auto [d, node] = pq.top();
            pq.pop();

            if(d > dist[node])
                continue;

            for(auto [neighbor, weight] : adj[node]){

                if(dist[node] + weight < dist[neighbor]){

                    dist[neighbor] = dist[node] + weight;

                    pq.push({
                        dist[neighbor],
                        neighbor
                    });
                }
            }
        }

        // Count cities within threshold
        int count = 0;

        for(int i = 0; i < n; i++){
            if(i != src && dist[i] <= threshold)
                count++;
        }

        return count;
    }


    int findTheCity(int n,
                    vector<vector<int>>& edges,
                    int distanceThreshold) {

        // Build adjacency list
        vector<vector<pair<int,int>>> adj(n);

        for(auto &e : edges){

            int u = e[0];
            int v = e[1];
            int wt = e[2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        int minCount = INT_MAX;
        int ans = -1;

        // Dijkstra from every city
        for(int src = 0; src < n; src++){

            int count = dijkstra(
                src,
                adj,
                n,
                distanceThreshold
            );

            if(count <= minCount){
                minCount = count;
                ans = src;
            }
        }

        return ans;
    }
};