#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

const int SIZE = 7;

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

    }
};
 
    int main() {
// Creates a vector of graph edges/weights
vector<Edge> edges = {
// (x, y, w) —> edge from x to y having weight w
{0,1,12},{0,2,8},{0,3,21},{2,3,6},{2,6,2},{5,6,6},{4,5,9},{2,4,4},{2,5,5}
};
// Creates graph
Graph graph(edges);
// Prints adjacency list representation of graph
graph.printGraph();
return 0;
}
   