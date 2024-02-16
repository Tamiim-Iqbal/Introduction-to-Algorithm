// class Solution {
// public:
//     int vis[2000005];
//     vector<int> v[2000005];
//     void dfs(int s)
//     {
//         vis[s] = true;
//         for(int c: v[s])
//         {
//             if(!vis[c])
//             {
//                 dfs(c);
//             }
//         }
//     }
//     bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
//         memset(vis,false,sizeof(vis));
//         for(int i=0; i<edges.size(); i++)
//         {
//             int a = edges[i][0];
//             int b = edges[i][1];
//             v[a].push_back(b);
//             v[b].push_back(a);
//         }
//         dfs(source);
//         return vis[destination];
//     }
    
// };