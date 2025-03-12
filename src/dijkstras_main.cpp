#include "dijkstras.h"

int main() {
    string filename = "src/small.txt";
    Graph G;
    file_to_graph(filename, G);

    int dest = 3;
    vector<int> previous(G.numVertices, -1);
    vector<int> distances = dijkstra_shortest_path(G, 0, previous);
    vector<int> path = extract_shortest_path(distances, previous, dest);

    print_path(path, distances[dest]);
}