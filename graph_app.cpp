#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

const int SIZE = 5;

struct Edge {
    int src, dest, weight;
};

typedef pair<int,int> Pair;

class Graph {
public:
    vector<vector<Pair>> adjList;

    Graph(const vector<Edge> &edges) {
        adjList.resize(SIZE);
        for (auto &edge : edges) {
            int src = edge.src;
            int dest = edge.dest;
            int weight = edge.weight;

            adjList[src].push_back(make_pair(dest, weight));
            adjList[dest].push_back(make_pair(src, weight)); // undirected
        }
    }

        void printGraph() {
        cout << "Graph's adjacency list:\n";
        for (int i = 0; i < adjList.size(); i++) {
            cout << i << " --> ";
            for (Pair v : adjList[i])
                cout << "(" << v.first << ", " << v.second << ") ";
            cout << endl;
        }
    }

    void DFS(int start){
        vector<bool> visited(SIZE, false);
        stack<int> s;

        s.push(start);

        cout << "DFS Traversal starting from vertex " << start << " : ";

                while (!s.empty()) {
            int node = s.top();
            s.pop();

            if (!visited[node]) {
                visited[node] = true;
                cout << node << " ";

                 for (int i = adjList[node].size() - 1; i >= 0; i--) {
                    int neighbor = adjList[node][i].first;
                    if (!visited[neighbor])
                        s.push(neighbor);
                }
            }
        }
        cout << endl;
     }

      void BFS(int start) {
        vector<bool> visited(SIZE, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        cout << "BFS starting from vertex " << start << ": ";

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            cout << node << " ";

            for (auto &edge : adjList[node]) {
                int neighbor = edge.first;
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        cout << endl;
    }

        void dijkstra(int start) {
        vector<int> dist(SIZE, INT_MAX);
        priority_queue<Pair, vector<Pair>, greater<Pair>> pq;

        dist[start] = 0;
        pq.push({0, start});

        while (!pq.empty()) {
            int current = pq.top().second;
            pq.pop();

            for (auto &edge : adjList[current]) {
                int neighbor = edge.first;
                int weight = edge.second;

                if (dist[current] + weight < dist[neighbor]) {
                    dist[neighbor] = dist[current] + weight;
                    pq.push({dist[neighbor], neighbor});
                }
            }
        }

        cout << "Shortest travel times from station " << start << ":\n";
        for (int i = 0; i < SIZE; i++) {
            cout << "→ To station " << i << " = " << dist[i] << " minutes\n";
        }
        cout << endl;
    }

};

void printTransitNetwork(const Graph &graph, const vector<string> &names) {
    cout << " City Transit Network Topology:\n";
    cout << "=================================\n";

    for (int i = 0; i < (int)graph.adjList.size(); ++i) {
        cout << "From station " << i << " (" << names[i] << "):\n";

        for (auto &edge : graph.adjList[i]) {
            int neighbor = edge.first;
            int weight = edge.second;

            cout << "   → To station " << neighbor 
                 << " (" << names[neighbor] << ") "
                 << " - Travel time: " << weight << " minutes\n";
        }
        cout << endl;
    }
} 
    int main() {

    vector<string> names = {
    "Downtown",
    "Airport",
    "University",
    "Central Park",
    "City Mall"
};


vector<Edge> edges = {
// (x, y, w) —> edge from x to y having weight w
    {0, 1, 15},  // Downtown → Airport
    {0, 2, 10},  // Downtown → University
    {1, 3, 12},  // Airport → Central Park
    {2, 3, 5},   // University → Central Park
    {3, 4, 8}    // Central Park → City Mall
};




// Creates graph
Graph graph(edges);

graph.printGraph();
    cout << endl;

    graph.DFS(0);
    graph.BFS(0);

    cout << endl;
    printTransitNetwork(graph, names);
    graph.dijkstra(0);

return 0;
}
   