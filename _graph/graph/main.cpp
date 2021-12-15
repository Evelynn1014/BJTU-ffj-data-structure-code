#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector<bool> vis;
vector<vector<int> > adj;
int j =0,k=0,l=0;
queue<int>Q;

//bool find_edge(int u, int v) {
//    for (int i = 0; i < adj[u].size(); ++i) {
//        if (adj[u][i] == v) {
//            return true;
//        }
//    }
//    return false;
//}

void dfs(int u, int v) {
    if (vis[u]) return;
    vis[u] = true;
    for (int i = 0; i < adj[u].size(); ++i) {

        if (adj[u][i] == v){
            j++;
        }
        dfs(adj[u][i],v);
    }
}

void bfs(int u, int v) {

    while (!Q.empty()) Q.pop();
    Q.push(u);
    vis[u] = true;
    int p = 0;
    while (!Q.empty()) {
        u = Q.front ();
        Q.pop();
        for (int  i = 0; i < adj[u].size(); ++i) {
            if(!vis[adj[u][i]]) {
                Q.push(adj[u][i]);
                vis[adj[u][i]] = true;

               // k++;
            }
            if(adj[u][i] == v){
                l++;
            }
        }
    }
}

bool findK(int u, int v, int m) {
    if (u == v && m == 0) return true;
    {
        vis[u] = true;
        for (int i = 0; i < adj[u].size(); ++i) {
            k = adj[u][i];
            if (!vis[k])
                if (findK(k, v, m - 1)) return true; //剩余路径长度减一
        }
        vis[u] = 0;
    }
    return false; //没找到
}

int main() {
    cin >> n >> m;

    vis.resize(n + 1, false);
    adj.resize(n + 1);

    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

//7.23,7.22
/*
    cout<<"OKAY! enter the u,v"<<endl;
    int u, v;
    cin >> u >> v;
    dfs(u,v);
    for(int o = 0; o < vis.size();++o)
    vis[o] = false;
    bfs(u,v);
    if(j!=0) {
        cout<<"7.22 found <u,v>"<<endl;
    }else{
        cout<<"7.22 not found <u,v>"<<endl;
    }
    if(l!=0) {
        cout<<"7.23 found <u,v>"<<endl;
    }else{
         cout<<"7.23 not found <u,v>"<<endl;
        }


    */


    int u, v, k;
    cin >> u >> v >>k;
//7.27
if(findK(u, v, k)){
    cout<<"7.27 found <u,v> in k"<<endl;
}else{
    cout<<"7.27 did not found <u,v> in k"<<endl;
}
    return 0;
}