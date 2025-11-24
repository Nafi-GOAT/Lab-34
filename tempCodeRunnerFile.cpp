#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

const int SIZE = 9;

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
};
 
    int main() {

vector<Edge> edges = {
// (x, y, w) —> edge from x to y having weight w
   {0,1,8}, {0,2,21},
    {1,2,6}, {1,3,5}, {1,4,4},
    {2,7,11}, {2,8,8},
    {3,4,9},
    {5,6,10},
    {5,7,15}, {5,8,5},
    {6,7,3}, {6,8,7},
    {7,8,2}
};

// Creates graph
Graph graph(edges);

graph.printGraph();
    cout << endl;

    graph.DFS(0);
    graph.BFS(0);

return 0;
}
   