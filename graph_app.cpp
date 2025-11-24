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
   