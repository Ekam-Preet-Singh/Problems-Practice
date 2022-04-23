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
Q339.) Dijkstra algo

INPUT:
2

2 1
0 1 9
0

4 5
0 1 9
0 2 1
0 3 1
1 3 3
2 3 2
0

OUTPUT:
Case #1: 0 9
Case #2: 0 4 1 1

*/

class Solution
{
public:
    // Function to find the vertex with minimum distance value, from the set
    // of vertices not yet included in shortest path tree.
    int minDistance(vector<int> &dist, bool sptSet[], int V)
    {
        // initializing minimum value.
        int min = INT_MAX, min_index;

        for (int v = 0; v < V; v++)
        {
            if (sptSet[v] == false && dist[v] <= min)
            {
                min = dist[v], min_index = v;
            }
        }

        return min_index;
    }

    // Function to find the shortest distance of all the vertices
    // from the source vertex S.
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // creating Adjacency matrix from Adjacency list.
        vector<vector<int>> adj_mat(V, vector<int>(V, 0));
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < adj[i].size(); j++)
            {
                adj_mat[i][adj[i][j][0]] = adj[i][j][1];
            }
        }

        // dist[] is output list. dist[i] will hold the
        // shortest distance from source to i.
        vector<int> dist(V);

        // sptSet[i] will true if vertex i is included in shortest
        // path tree or shortest distance from src to i is finalized.
        bool sptSet[V];

        // initializing all distances as INFINITE and stpSet[] as false.
        for (int i = 0; i < V; i++)
        {
            dist[i] = INT_MAX, sptSet[i] = false;
        }

        // distance of source vertex from itself is always 0.
        dist[S] = 0;

        // iterating over all vertices.
        for (int count = 0; count < V - 1; count++)
        {
            // picking the minimum distance vertex from the set of vertices
            // not yet processed and marking the picked vertex as processed.
            int u = minDistance(dist, sptSet, V);
            sptSet[u] = true;

            // updating dist[] value of adjacent vertices of the picked vertex.
            for (int v = 0; v < V; v++)
            {
                // updating dist[v] only if it's not in sptSet, there is an
                // edge from u to v, and total weight of path from source to
                // v through u is smaller than current value of dist[v].
                if (!sptSet[v] && adj_mat[u][v] && dist[u] != INT_MAX && dist[u] + adj_mat[u][v] < dist[v])
                {
                    dist[v] = dist[u] + adj_mat[u][v];
                }
            }
        }
        // returning the list.
        return dist;
    }
};

void solve()
{
    int V, E;
    cin >> V >> E;
    vector<vector<int>> adj[V];
    int i = 0;
    while (i++ < E)
    {
        int u, v, w;
        cin >> u >> v >> w;
        vector<int> t1, t2;
        t1.push_back(v);
        t1.push_back(w);
        adj[u].push_back(t1);
        t2.push_back(u);
        t2.push_back(w);
        adj[v].push_back(t2);
    }
    int S;
    cin >> S;

    Solution obj;
    vector<int> res = obj.dijkstra(V, adj, S);

    for (int i = 0; i < V; i++)
        cout << res[i] << " ";
    cout << endl;
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