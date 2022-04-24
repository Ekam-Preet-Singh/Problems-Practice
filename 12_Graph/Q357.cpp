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
Q357.) Longest path in a Directed Acyclic Graph

INPUT:
1

OUTPUT:
Case #1:
Following are longest distances from source vertex 1
INF 0 2 9 8 10

*/

#define NINF INT_MIN
// Graph is represented using adjacency list. Every
// node of adjacency list contains vertex number of
// the vertex to which edge connects. It also
// contains weight of the edge
class AdjListNode
{
    int v;
    int weight;

public:
    AdjListNode(int _v, int _w)
    {
        v = _v;
        weight = _w;
    }
    int getV() { return v; }
    int getWeight() { return weight; }
};

// Class to represent a graph using adjacency list
// representation
class Graph
{
    int V; // No. of vertices'

    // Pointer to an array containing adjacency lists
    list<AdjListNode> *adj;

    // A function used by longestPath
    // A recursive function used by longestPath. See below
    // link for details
    // https:// www.geeksforgeeks.org/topological-sorting/
    void topologicalSortUtil(int v, bool visited[], stack<int> &Stack)
    {
        // Mark the current node as visited
        visited[v] = true;

        // Recur for all the vertices adjacent to this vertex
        list<AdjListNode>::iterator i;
        for (i = adj[v].begin(); i != adj[v].end(); ++i)
        {
            AdjListNode node = *i;
            if (!visited[node.getV()])
            {
                topologicalSortUtil(node.getV(), visited, Stack);
            }
        }

        // Push current vertex to stack which stores topological
        // sort
        Stack.push(v);
    }

public:
    Graph(int V) // Constructor
    {
        this->V = V;
        adj = new list<AdjListNode>[V];
    }
    ~Graph() // Destructor
    {
        delete[] adj;
    }

    // function to add an edge to graph
    void addEdge(int u, int v, int weight)
    {
        AdjListNode node(v, weight);
        adj[u].push_back(node); // Add v to u's list
    }

    // Finds longest distances from given source vertex
    // The function to find longest distances from a given vertex.
    // It uses recursive topologicalSortUtil() to get topological
    // sorting.
    void longestPath(int s)
    {
        stack<int> Stack;
        int dist[V];

        // Mark all the vertices as not visited
        bool *visited = new bool[V];
        for (int i = 0; i < V; i++)
        {
            visited[i] = false;
        }

        // Call the recursive helper function to store Topological
        // Sort starting from all vertices one by one
        for (int i = 0; i < V; i++)
        {
            if (visited[i] == false)
            {
                topologicalSortUtil(i, visited, Stack);
            }
        }

        // Initialize distances to all vertices as infinite and
        // distance to source as 0
        for (int i = 0; i < V; i++)
        {
            dist[i] = NINF;
        }
        dist[s] = 0;
        // Process vertices in topological order
        while (Stack.empty() == false)
        {
            // Get the next vertex from topological order
            int u = Stack.top();
            Stack.pop();

            // Update distances of all adjacent vertices
            list<AdjListNode>::iterator i;
            if (dist[u] != NINF)
            {
                for (i = adj[u].begin(); i != adj[u].end(); ++i)
                {

                    if (dist[i->getV()] < dist[u] + i->getWeight())
                    {
                        dist[i->getV()] = dist[u] + i->getWeight();
                    }
                }
            }
        }

        // Print the calculated longest distances
        for (int i = 0; i < V; i++)
        {
            (dist[i] == NINF) ? cout << "INF " : cout << dist[i] << " ";
        }

        delete[] visited;
    }
};

void solve()
{
    // Create a graph given in the above diagram.
    // Here vertex numbers are 0, 1, 2, 3, 4, 5 with
    // following mappings:
    // 0=r, 1=s, 2=t, 3=x, 4=y, 5=z
    Graph g(6);
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 3, 6);
    g.addEdge(1, 2, 2);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(2, 3, 7);
    g.addEdge(3, 5, 1);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);

    int s = 1;
    cout << "Following are longest distances from source vertex " << s << " \n";
    g.longestPath(s);
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
        cout << "Case #" << case_num++ << ":\n";
        solve();
    }

    return 0;
}