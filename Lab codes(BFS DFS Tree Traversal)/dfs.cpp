// code from codespeedy.com
#include<bits/stdc++.h>
using namespace std;

vector<int> adj[5];
bool visit[5];

void edge(int u, int v)
{
    adj[u].push_back(v);
}

void dfs( int startNode)
{
    stack<int>stk;
    stk.push(startNode);
    visit[startNode] = true;

    while( !stk.empty())
    {
        int u = stk.top();
        cout<<u<<" ";
        stk.pop();

        for(int i=0 ; i<adj[u].size(); i++)
        {
            if(!visit[adj[u][i]])
            {
                stk.push(adj[u][i]);
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

    dfs(0);

    return 0;
}
