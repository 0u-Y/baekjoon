#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

const int INF = 1e9;
const int MAX_V = 52;


int capacity[MAX_V][MAX_V], flow[MAX_V][MAX_V];
vector<int> adj[MAX_V];



int change(char c) {
    if('A' <= c && c <= 'Z') return c - 'A';
    else return c - 'a' + 26;
}



int networkFlow(int source, int sink) {
    memset(flow, 0, sizeof(flow));

    int totalFlow = 0;

    while(true) {
        vector<int> parent(MAX_V, -1);
        queue<int> Q;

        parent[source] = source;
        Q.push(source);

        while(!Q.empty() && parent[sink] == -1) {
            int here = Q.front(); Q.pop();

            for(int there : adj[here]) {
                if(capacity[here][there] - flow[here][there] > 0 && parent[there] == -1) {
                    parent[there] = here;
                    Q.push(there);


                    if(there == sink) break;
                }
            }
        }
        if(parent[sink] == -1) break;

        int amount = INF;

        for(int p = sink; p != source; p = parent[p]) {
            amount = min(amount, capacity[parent[p]][p] - flow[parent[p]][p]);
        }

        for(int p = sink; p != source; p = parent[p]) {
            flow[parent[p]][p] += amount;
            flow[p][parent[p]] -= amount;
        }
        totalFlow += amount;
    }

    return totalFlow;

}

int main() {
    int n;
    cin>>n;

    for(int i=0; i<n; i++) {
        char u, v;
        int c;
        cin>>u>>v>>c;

        int from = change(u);
        int to = change(v);

        capacity[from][to] += c;
        capacity[to][from] += c;

        adj[from].push_back(to);
        adj[to].push_back(from);

    }

    int source = change('A');
    int sink = change('Z');

    cout<<networkFlow(source, sink);


}




