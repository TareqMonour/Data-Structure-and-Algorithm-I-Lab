#include<iostream>
#include<queue>
using namespace std;
int graph[5][5]={0,1,1,1,0,
                1,0,0,0,1,
                1,0,0,1,0,
                1,0,1,0,1,
                0,1,0,1,0};
void bfs(int source)
{
    int color[5]={0};
    int d[5];
    int p[5]={-1};

    color[source]=1;
    d[source]=0;

    queue<int> Q;
    Q.push(source);

    while(!Q.empty())
    {
        int s=Q.front();
        Q.pop();
        cout<<s<<" ";

        for(int i=0;i<5;i++)
        {
            if(graph[s][i]==1&&color[i]==0)
            {
                color[i]=1;
                d[i]=d[s]+1;
                p[i]=s;
                Q.push(i);
            }
        }
        color[s]=2;
    }
    cout<<endl;
    for(int i=0;i<5;i++)
    {
       cout<<"distance = "<<i<<" is ="<<d[i]<<endl;
    }
    cout<<endl;
    for(int i=0;i<5;i++)
    {
       cout<<"parent = "<<i<<" is ="<<p[i]<<endl;
    }
}
int main()
{
    bfs(4);
    return 0;
}
