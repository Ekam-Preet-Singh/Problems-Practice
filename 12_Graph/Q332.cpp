#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define mod 1000000007
#define inf 1e18
#define endl "\n"
#define pb push_back
#define vi vector<ll>
#define vs vector<string>
#define pii pair<ll, ll>
#define ump unordered_map
#define mp make_pair
#define pq_max priority_queue<ll>
#define pq_min priority_queue<ll, vi, greater<ll>>
#define all(n) n.begin(), n.end()
#define ff first
#define ss second
#define mid(l, r) (l + (r - l) / 2)
#define bitc(n) __builtin_popcount(n)
#define loop(i, a, b) for (int i = (a); i <= (b); i++)
#define looprev(i, a, b) for (int i = (a); i >= (b); i--)
#define iter(container, it) for (__typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define log(args...)                             \
    {                                            \
        string _s = #args;                       \
        replace(_s.begin(), _s.end(), ',', ' '); \
        stringstream _ss(_s);                    \
        istream_iterator<string> _it(_ss);       \
        err(_it, args);                          \
    }
#define logarr(arr, a, b)            \
    for (int z = (a); z <= (b); z++) \
        cout << (arr[z]) << " ";     \
    cout << endl;
template <typename T>
T gcd(T a, T b)
{
    if (a % b)
        return gcd(b, a % b);
    return b;
}
template <typename T>
T lcm(T a, T b) { return (a * (b / gcd(a, b))); }
vs tokenizer(string str, char ch)
{
    std::istringstream var((str));
    vs v;
    string t;
    while (getline((var), t, (ch)))
    {
        v.pb(t);
    }
    return v;
}

void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
    cout << *it << " = " << a << endl;
    err(++it, args...);
}
// typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
// typedef trie<string,null_type,trie_string_access_traits<>,pat_trie_tag,trie_prefix_search_node_update> pbtrie;

void file_i_o()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

/*
Q332.) Detect Cycle in UnDirected Graph using BFS/DFS Algo

INPUT:
4

4 4
0 1
1 2
2 3
3 3

5 4
0 1
0 2
0 3
2 4

3 2
0 1
0 2

5 5
0 4
1 2
1 4
2 3
3 4

OUTPUT:
Case #1: 1
Case #2: 0
Case #3: 0
Case #4: 1

*/

// BFS cycle detection

class Solution
{
public:
    bool BFS(int i, vector<int> &vis, vector<int> adj[])
    {
        queue<pair<int, int>> q;

        q.push({i, -1});
        vis[i] = 1;

        while (!q.empty())
        {
            int node = q.front().first;
            int par = q.front().second;
            q.pop();

            for (auto it : adj[node])
            {
                if (!vis[it])
                {
                    q.push({it, node});
                    vis[it] = 1;
                }
                else if (par != it)
                {
                    return true; // cycle found in this graph component!
                }
            }
        }

        return false; // No cycle in this graph component
    }

    bool isCycle(int V, vector<int> adj[])
    {
        vector<int> vis(V, 0);

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (BFS(i, vis, adj))
                    return true;
            }
        }

        return false;
    }
};

/*
DFS
class Solution
{
public:
    bool isCycleUtil(int u, int par, vector<int> adj[], vector<bool> &vis)
    {
        // marking the current vertex as visited.
        vis[u] = true;

        // iterating on all the adjacent vertices.
        for (auto v : adj[u])
        {
            if (v == par)
            {
                continue;
            }

            // if current vertex is visited, we return true else we
            // call the function recursively to detect the cycle.
            if (vis[v])
            {
                return true;
            }
            if (isCycleUtil(v, u, adj, vis))
            {
                return true;
            }
        }
        return false;
    }

    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[])
    {
        // using a boolean list to mark all the vertices as not visited.
        vector<bool> vis(V, false);

        // iterating over all the vertices.
        for (int i = 0; i < V; i++)
        {
            // if vertex is not visited, we call the function to detect cycle.
            if (!vis[i])
            {
                bool f = isCycleUtil(i, -1, adj, vis);
                // if cycle is found, we return true.
                if (f)
                {
                    return true;
                }
            }
        }
        return false;
    }
};

*/

void solve()
{
    int V, E;
    cin >> V >> E;
    vector<int> adj[V];
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    Solution obj;
    bool ans = obj.isCycle(V, adj);
    if (ans)
        cout << "1\n";
    else
        cout << "0\n";
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    file_i_o();

    ll t = 1;
    ll case_num = 1;
    cin >> t;
    while (t--)
    {
        cout << "Case #" << case_num++ << ": ";
        solve();
    }

    return 0;
}