class Solution {
public://KNK


    // Function to find the closest meeting node between node1 and node2
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        // Get the total number of nodes
        int numNodes = edges.size();
        // Graph storage using adjacency list
        vector<vector<int>> graph(numNodes);
        // Constructing the adjacency list for the graph
        for (int i = 0; i < numNodes; ++i) {
            if (edges[i] != -1) {
                graph[i].push_back(edges[i]);
            }
        }
        // Define infinity as a large number
        const int infinity = 1 << 30;
        // Pair for holding distance and node information
        using DistNodePair = pair<int, int>;

        // Lambda function for Dijkstra's algorithm to find the shortest path
        // from a starting node to all other nodes
        auto dijkstra = [&](int startNode) {
            // Initialize distances to infinity
            vector<int> distances(numNodes, infinity);
            // Distance to the start node is 0
            distances[startNode] = 0;
            // Min-heap priority queue to select the node with the smallest distance
            priority_queue<DistNodePair, vector<DistNodePair>, greater<DistNodePair>> pq;
            // Push the start node onto the queue
            pq.emplace(0, startNode);
            // Perform the algorithm until the queue is empty
            while (!pq.empty()) {
                // Get the top pair in the queue
                auto pair = pq.top();
                pq.pop();
                int currentNode = pair.second;
                // Update distances for adjacent nodes
                for (int neighbor : graph[currentNode]) {
                    if (distances[neighbor] > distances[currentNode] + 1) {
                        distances[neighbor] = distances[currentNode] + 1;
                        pq.emplace(distances[neighbor], neighbor);
                    }
                }
            }
            // Return the calculated distances
            return distances;
        };

        // Get distances from node1 and node2 to all other nodes using Dijkstra's
        vector<int> distancesFromNode1 = dijkstra(node1);
        vector<int> distancesFromNode2 = dijkstra(node2);

        // Variables to store the result and the minimum distance found
        int closestNode = -1;
        int minDistance = infinity;

        // Look for the node that minimizes the maximum distance 
        // from both node1 and node2
        for (int i = 0; i < numNodes; ++i) {
            int maxDist = max(distancesFromNode1[i], distancesFromNode2[i]);
            if (maxDist < minDistance) {
                minDistance = maxDist;
                closestNode = i;
            }
        }
        // Return the index of the closest meeting node
        return closestNode;
    }
};