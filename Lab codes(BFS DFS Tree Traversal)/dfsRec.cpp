#include<bits/stdc++.h>
using namespace std;

vector<int> adj[5];
bool visit[5];

void edge(int u, int v)
{
    adj[u].push_back(v);
}

void dfs( int node)
{
    //if(visit[node]) return;
    visit[node] = true;
    cout<<node<<" ";

    for(int i=0 ; i<adj[node].size() ; i++){
        if(!visit[adj[node][i]]) dfs(adj[node][i]);
    }

}
int main()
{

    for(int i=0 ; i<5 ; i++)
    {
        visit[i] = false;
    }


    edge(0, 2);
    edge(0, 1);
    edge(1, 3);
    edge(2, 0);
    edge(2, 3);
    edge(2, 4);

    dfs(0);

    return 0;
}
