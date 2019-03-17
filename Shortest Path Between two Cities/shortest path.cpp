#include <bits/stdc++.h>

using namespace std;
#define MAX 10005
#define pii pair<int,int>
#define mp(x,y) make_pair(x,y)
#define INF 10000000

vector<pii>adj[MAX];
bool visited[MAX];
long long dist[MAX];
string names[MAX];
int route[MAX];
map<string,int>nametoid;

void init()
{
    string st,en;
    int id=1;
    while(cin>>st)
    {
        if(st=="END")
        {
            cin>>st>>st;
            break;
        }

        int d,u,v;
        cin>>en>>d;
        if(nametoid[st])
        {
            u=nametoid[st];
        }
        else
        {
            nametoid[st]=id;
            u=id;
            id++;
            names[id-1]=st;
        }
        if(nametoid[en])
        {
            v=nametoid[en];
        }
        else
        {
            nametoid[en]=id;
            v=id;
            id++;
            names[id-1]=en;
        }
        adj[u].push_back(mp(v,d));
        adj[v].push_back(mp(u,d));
    }
}

void printpath(int u,int v)
{
    stack<int>s;
    long long ans=dist[v];
    while(1)
    {
        s.push(v);
        if(v==u)
            break;
        v=route[v];
    }
    cout<<"distance: "<<ans<<" km"<<endl<<"route:"<<endl;
    int tmp=u;
    s.pop();
    while(!s.empty())
    {
        int tmp2=s.top();
        cout<<names[tmp]<<" to "<<names[tmp2]<<", "<<dist[tmp2]-dist[tmp]<<" km"<<endl;
        tmp=tmp2;
        s.pop();
    }
}

void bfs(int uu,int vv)
{
    memset(visited,0,sizeof(visited));
    memset(route,-1,sizeof(route));
    for(int i=0;i<MAX;i++)
        dist[i]=INF;
    queue<int>q;
    q.push(uu);
    bool found=false;
    dist[uu]=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=0;i<adj[u].size();i++)
        {
            int v=adj[u][i].first;
            int d=adj[u][i].second;
            if(v==vv)
                found=true;
            if(!visited[v])
            {
                route[v]=u;
                dist[v]=dist[u]+d;
                visited[v]=true;
                q.push(v);
            }
        }
        visited[u]=true;
    }
    if(found)
    {
        printpath(uu,vv);
    }
    else
    {
        cout<<"distance: infinity\nroute:\nnone\n";
    }
}

void dijkstra(int uu,int vv)
{
    memset(route,-1,sizeof(route));
    for(int i=0;i<MAX;i++)
        dist[i]=INF;
    priority_queue<pii,vector<pii>,greater<pii> >pq;
    pq.push(mp(0,uu));;
    dist[uu]=0;
    bool found=false;
    while(!pq.empty())
    {
        int u=pq.top().second;
        pq.pop();
        for(int i=0;i<adj[u].size();i++)
        {
            int v=adj[u][i].first;
            int d=adj[u][i].second;
            if(v==vv)
                found=true;
            if(dist[v]>dist[u]+d)
            {
                route[v]=u;
                dist[v]=dist[u]+d;
                pq.push(mp(dist[v],v));
            }
        }
    }
    if(found)
    {
        printpath(uu,vv);
    }
    else
    {
        cout<<"distance: infinity\nroute:\nnone\n";
    }
}

int main(int argc, char **argv)
{
    if(argc<5)
        return 0;
    string file,type,source,dest;
    type=argv[1];
    file=argv[2];
    source=argv[3];
    dest=argv[4];
    freopen(file.c_str(),"r",stdin);
    init();
    if(type=="find_route")
    {
        dijkstra(nametoid[source],nametoid[dest]);
    }
    else
        bfs(nametoid[source],nametoid[dest]);

    return 0;
}
