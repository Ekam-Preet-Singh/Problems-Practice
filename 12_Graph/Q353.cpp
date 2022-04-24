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
Q353.) Find bridge in a graph

INPUT:
3

5
1 0
0 2
2 1
0 3
3 4

4
0 1
1 2
2 3

7
0 1
1 2
2 0
1 3
1 4
1 6
3 5
4 5

OUTPUT:
Case #1:
Bridges in first graph
3 4
0 3
Case #2:
Bridges in second graph
2 3
1 2
0 1
Case #3:
Bridges in third graph
1 6

*/

#define NIL -1

// A class that represents an undirected graph
class Graph
{
    int V;          // No. of vertices
    list<int> *adj; // A dynamic array of adjacency lists
    // A recursive function that finds and prints bridges using
    // DFS traversal
    // u --> The vertex to be visited next
    // visited[] --> keeps track of visited vertices
    // disc[] --> Stores discovery times of visited vertices
    // parent[] --> Stores parent vertices in DFS tree
    void bridgeUtil(int u, bool visited[], int disc[], int low[], int parent[])
    {
        // A static variable is used for simplicity, we can
        // avoid use of static variable by passing a pointer.
        static int time = 0;

        // Mark the current node as visited
        visited[u] = true;

        // Initialize discovery time and low value
        disc[u] = low[u] = ++time;

        // Go through all vertices adjacent to this
        list<int>::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
        {
            int v = *i; // v is current adjacent of u

            // If v is not visited yet, then recur for it
            if (!visited[v])
            {
                parent[v] = u;
                bridgeUtil(v, visited, disc, low, parent);

                // Check if the subtree rooted with v has a
                // connection to one of the ancestors of u
                low[u] = min(low[u], low[v]);

                // If the lowest vertex reachable from subtree
                // under v is  below u in DFS tree, then u-v
                // is a bridge
                if (low[v] > disc[u])
                {
                    cout << u << " " << v << endl;
                }
            }

            // Update low value of u for parent function calls.
            else if (v != parent[u])
            {
                low[u] = min(low[u], disc[v]);
            }
        }
    }

public:
    Graph(int V) // Constructor
    {
        this->V = V;
        adj = new list<int>[V];
    }
    void addEdge(int v, int w) // to add an edge to graph
    {
        adj[v].push_back(w);
        adj[w].push_back(v); // Note: the graph is undirected
    }
    // prints all bridges
    // DFS based function to find all bridges. It uses recursive
    // function bridgeUtil()
    void bridge()
    {
        // Mark all the vertices as not visited
        bool *visited = new bool[V];
        int *disc = new int[V];
        int *low = new int[V];
        int *parent = new int[V];

        // Initialize parent and visited arrays
        for (int i = 0; i < V; i++)
        {
            parent[i] = NIL;
            visited[i] = false;
        }

        // Call the recursive helper function to find Bridges
        // in DFS tree rooted with vertex 'i'
        for (int i = 0; i < V; i++)
        {
            if (visited[i] == false)
            {
                bridgeUtil(i, visited, disc, low, parent);
            }
        }
    }
};

void solve()
{
    cout << "\nBridges in first graph \n";
    Graph g1(5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(2, 1);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);
    g1.bridge();

    cout << "\nBridges in second graph \n";
    Graph g2(4);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    g2.addEdge(2, 3);
    g2.bridge();

    cout << "\nBridges in third graph \n";
    Graph g3(7);
    g3.addEdge(0, 1);
    g3.addEdge(1, 2);
    g3.addEdge(2, 0);
    g3.addEdge(1, 3);
    g3.addEdge(1, 4);
    g3.addEdge(1, 6);
    g3.addEdge(3, 5);
    g3.addEdge(4, 5);
    g3.bridge();
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