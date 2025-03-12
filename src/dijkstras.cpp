#include "dijstras.h"

struct dist_comp {
    bool operator()(pair<int, int> x, pair<int,int> y) {
        return x.second > y.second;
    }
};

vector<int> dijstra_shortest_path(const Graph& G, int source, vector<int>& previous) {
    vector<int> distances(G.numVertices, INF);
    vector<bool> visited(G.numVertices, false);
    distances[source] = 0;
    previous[source] = -1;
    priority_queue<pair<int, int>, vector<pair<int, int>>, dist_comp> minHeap;
    minHeap.push({source, 0});

    while (!minHeap.empty()) {
        int u = minHeap.top().first;
        minHeap.pop();
        if (visited[u]) continue;
        visited[u] = true;
        for (Edge e: G[u]) {
            int v = e.dst;
            int weight = e.second;
            if (!visited[v] && distances[u] + weight < distances[v]) {
                distances[v] = distances[u] + weight;
                previous[v] = u;
                minHeap.push({v, distances[v]});
            }
        }
    }
    return distances;
}

vector<int> reversePath(stack<int>& p) {
    vector<int> path;
    while (!p.empty()) {
        path.push_back(p.top());
        p.pop();
    }
    return path;
}

vector<int> extract_shortest_path(const vector<int>& /*distances*/, const vector<int>& previous, int destination) {
    stack<int> p;
    p.push(destination);

    for (int prev = previous[destination]; prev != -1; prev = previous[prev]) {
        p.push(prev);
    }

    vector<int> path = reversePath(p);

    return path;
}

void print_path(const vector<int>& v, int total) {
    for (int p : v) {
        cout << p << " ";
    }
    cout << endl;
    cout << "Total cost is " << total << endl;
}
