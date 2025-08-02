#include<bits/stdc++.h>
using namespace std;
int main()
{
    /// undirected graph

    freopen("input.txt", "r", stdin);

    int V, E; cin >> V >> E;
    int Graph[V][V];
    memset(Graph, 0, sizeof(Graph));

    for(int i=1; i<=E; i++)
    {
        int from, to; cin >> from >> to;
        Graph[from][to] = 1;
        Graph[to][from] = 1;
    }

    for(int i=0; i<V; i++)
    {
        for(int j=0; j<V; j++)
        {
            cout << Graph[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
