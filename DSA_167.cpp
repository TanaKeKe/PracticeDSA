#include<bits/stdc++.h>
using namespace std;
vector<int> adj[100001];
vector<int> res;
int daduyet[100001];
// void DFS(int u){
//     daduyet[u] = 1;
//     //cout << u << " ";
//     res.push_back(adj[u].size());
//     for(int i=0;i<adj[u].size();++i){
//         if(!daduyet[adj[u][i]]){
//             DFS(adj[u][i]);
//         }
//     }
// }

void DFS(int u){
    stack<int> st;
    st.push(u);
    daduyet[u] = 1;
    while(!st.empty()){
        int k = st.top();
        res.push_back(adj[k].size());
        st.pop();
        for(int i=0;i<adj[k].size();++i){
            if(!daduyet[adj[k][i]]){
                st.push(k);
                st.push(adj[k][i]);
                daduyet[adj[k][i]] = 1;
                break;
            }
        }
    }
}
// void BFS(int u){
//     queue<int> q;
//     q.push(u);
//     daduyet[u] = 1;
//     while(!q.empty()){
//         int k = q.front();
//         res.push_back(adj[k].size());
//         q.pop();
//         for(int i = 0;i<adj[k].size();++i){
//             if(!daduyet[adj[k][i]]){
//                 q.push(adj[k][i]);
//                 daduyet[adj[k][i]] = 1;
//             }
//         }
//     }
// }
int main(){
    int t;cin >> t;
    while(t--){
        for(int i=0;i<=100000;++i){
            adj[i].clear();
            daduyet[i] = 0;
        }
        int n,m;
        cin >> n >> m;
        for(int i=1;i<=m;++i){
            int x,y;cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        // for(int i=0;i<=n;++i){
        //     cout << i << ": ";
        //     for(int j = 0;j<adj[i].size();++j) cout << adj[i][j] << " ";
        //         cout << "\n";
        // }
        
        int check = 0;
        int c = 0;
        for(int i=1;i<=n;++i){
            if(!daduyet[i]){
                res.clear();
                DFS(i);
                ++c;
                //cout << "\n";
                 int cnt = res[0];
                 //cout << cnt << "\n";
                for(int j=1;j<res.size();++j){
                    if(res[j]!=cnt){
                        check = 1;
                        break;
                    }
                }
                if(check) break;

            }
        }
        //cout << c;
        if(check == 0) cout << "YES\n";
        else cout << "NO\n";
    }
}