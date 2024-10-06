#include <iostream>
#include <string.h>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

bool visited[100001];
vector<vector<int> > Graph(100001);
vector<vector<int> > reversedGraph(100001);
vector<int> component;
vector<vector<int> > SCC;




stack<int> order;




void dfsGraph(int u) {
    visited[u] = true;

    for(int v : Graph[u]) {
        if(!visited[v]) {
            dfsGraph(v);
        }
    }
    order.push(u);
}

void dfsReversedGraph(int u) {
    visited[u] = true;
    component.push_back(u);

    for(int v : reversedGraph[u]) {
        if(!visited[v]) {
            dfsReversedGraph(v);
        }
    }
}











int main() {

    int v,e;
    cin>>v>>e;
    
    for(int i=0; i<e; i++) {
        int a,b;
        cin>>a>>b;
        Graph[a].push_back(b);
        reversedGraph[b].push_back(a);
    }



    fill(visited, visited + v + 1, false);
    for(int i=1; i<=v; i++) {
        if(!visited[i]) {
            dfsGraph(i);
        }
    }


    fill(visited, visited + v + 1, false);


    while(!order.empty()) {
        int u = order.top();
        order.pop();


        if(!visited[u]) {
            component.clear();
            dfsReversedGraph(u);
            sort(component.begin(), component.end());
            SCC.push_back(component);
        }
    }


    sort(SCC.begin(), SCC.end());



    cout<<SCC.size()<<'\n';

    for(size_t i=0; i<SCC.size(); i++) {
        for(size_t j = 0; j<SCC[i].size(); j++) {
            cout<<SCC[i][j]<<" ";
        }

        cout<<"-1"<<'\n';
    }


    

}