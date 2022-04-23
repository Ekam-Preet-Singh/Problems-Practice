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
Q340.) Implement Topological Sort

INPUT:
2

3 4
3 0
1 0
2 0

3 4
3 0
3 2
0 2

OUTPUT:
Case #1: 1
Case #2: 1

*/

class Solution
{
public:
    void topo(vector<int> adj[], int u, bool visited[], stack<int> &s)
    {
        // marking the current vertex as visited.
        visited[u] = true;

        // traversing over the adjacent vertices.
        for (auto v : adj[u])
        {
            // if any vertex is not visited, we call the function recursively.
            if (!visited[v])
            {
                topo(adj, v, visited, s);
            }
        }
        // pushing the current vertex into the stack.
        s.push(u);
    }

    // Function to return list containing vertices in Topological order.
    vector<int> topoSort(int N, vector<int> adj[])
    {
        // using boolean array to mark visited nodes and currently
        // marking all the nodes as false.
        bool visited[N + 1];
        memset(visited, 0, sizeof visited);

        stack<int> s;

        // traversing over all the vertices.
        for (int i = 0; i < N; i++)
        {
            // if the current vertex is not visited, we call the topo function.
            if (!visited[i])
            {
                topo(adj, i, visited, s);
            }
        }

        vector<int> res;
        int i = -1;
        while (!s.empty())
        {
            // pushing elements of stack in list and popping them from stack.
            res.push_back(s.top());
            s.pop();
        }
        // returning the list.
        return res;
    }
};

int check(int V, vector<int> &res, vector<int> adj[])
{

    if (V != res.size())
    {
        return 0;
    }

    vector<int> map(V, -1);
    for (int i = 0; i < V; i++)
    {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++)
    {
        for (int v : adj[i])
        {
            if (map[i] > map[v])
            {
                return 0;
            }
        }
    }
    return 1;
}

void solve()
{
    int N, E;
    cin >> E >> N;
    int u, v;

    vector<int> adj[N];

    for (int i = 0; i < E; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
    }

    Solution obj;
    vector<int> res = obj.topoSort(N, adj);

    cout << check(N, res, adj) << endl;
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