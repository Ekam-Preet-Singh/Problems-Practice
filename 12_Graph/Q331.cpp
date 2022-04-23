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
Q331.) Detect Cycle in Directed Graph using BFS/DFS Algo

INPUT:
3

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

OUTPUT:
Case #1: 1
Case #2: 0
Case #3: 0

*/

/*
BFS (Topological Sort)
If we can't sort it means it has a cycle

class Solution
{
public:
    vector<int> topologicalSort(int n, vector<int> adj[])
    {
        queue<int> q;
        vector<int> inDegree(n, 0);
        for (int i = 0; i < n; i++)
        {
            for (auto it : adj[i])
            {
                inDegree[it]++;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (inDegree[i] == 0)
            {
                q.push(i);
            }
        }
        vector<int> topo;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for (auto it : adj[node])
            {
                inDegree[it]--;
                if (inDegree[it] == 0)
                {
                    q.push(it);
                }
            }
        }
        return topo;
    }
    bool isCyclic(int V, vector<int> adj[])
    {
        vector<int> topo = topologicalSort(V, adj);
        if (topo.size() == V)
            return false;
        return true;
    }
};
*/

// DFS
class Solution
{
private:
    bool isCyclicUtil(int v, vector<bool> &visited, vector<bool> &recStack, vector<int> adj[])
    {
        // if the current vertex is not visited.
        if (visited[v] == false)
        {
            // marking the current node as visited and part of recursion stack.
            visited[v] = true;
            recStack[v] = true;

            // calling function recursively for all the vertices
            // adjacent to this vertex.
            for (int i = 0; i < (int)adj[v].size(); ++i)
            {
                if (!visited[adj[v][i]] && isCyclicUtil(adj[v][i], visited, recStack, adj))
                {
                    return true;
                }
                else if (recStack[adj[v][i]])
                {
                    return true;
                }
            }
        }
        // removing the vertex from recursion stack.
        recStack[v] = false;
        return false;
    }

public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[])
    {
        // marking all vertices as not visited and not a part of recursion stack
        vector<bool> visited(V, false);
        vector<bool> recStack(V, false);

        // calling the recursive helper function to detect cycle in
        // different DFS trees.
        for (int i = 0; i < V; i++)
        {
            if (isCyclicUtil(i, visited, recStack, adj))
            {
                return true;
            }
        }

        return false;
    }
};

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
    }

    Solution obj;
    cout << obj.isCyclic(V, adj) << "\n";
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