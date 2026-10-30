class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges,
                     string labels, int k) {

        vector<vector<pair<int, int>>> adj(n);

        for (auto &e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
        }

        const long long INF = LLONG_MAX / 4;

        // dist[node][count] = minimum distance
        // when the current character occurs count times consecutively.
        vector<vector<long long>> dist(
            n, vector<long long>(k + 1, INF)
        );

        // {distance, node, consecutive count}
        using State = tuple<long long, int, int>;

        priority_queue<
            State,
            vector<State>,
            greater<State>
        > pq;

        dist[0][1] = 0;
        pq.push({0, 0, 1});

        while (!pq.empty()) {
            auto [d, u, count] = pq.top();
            pq.pop();

            if (d != dist[u][count])
                continue;

            if (u == n - 1)
                return (int)d;

            for (auto [v, w] : adj[u]) {
                int newCount;

                if (labels[u] == labels[v]) {
                    newCount = count + 1;
                } else {
                    newCount = 1;
                }

                if (newCount > k)
                    continue;

                long long newDist = d + w;

                if (newDist < dist[v][newCount]) {
                    dist[v][newCount] = newDist;
                    pq.push({
                        newDist, v, newCount
                    });
                }
            }
        }

        return -1;
    }
};