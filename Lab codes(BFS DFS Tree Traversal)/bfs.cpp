// code from codespeedy.com
#include<bits/stdc++.h>
using namespace std;

vector<int> adj[5];
bool visit[5];


void edge(int u, int v)
{
    adj[u].push_back(v);
    //adj[v].push_back(u);    //----> for undirected graph
}


void bfs( int startNode)
{
    queue<int>q;
    q.push(startNode);
    visit[startNode] = true;

    while( !q.empty())
    {
        int u = q.front();
        cout<<u<<" ";
        q.pop();

        for(int i=0 ; i<adj[u].size(); i++)
        {
            if(!visit[adj[u][i]])
            {
                q.push(adj[u][i]);
                visit[adj[u][i]] = true;
            }
        }
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

    bfs(0);

    return 0;
}
