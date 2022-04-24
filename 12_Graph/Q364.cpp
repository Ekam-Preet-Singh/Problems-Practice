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
Q364.) Paths to travel each nodes using each edge(Seven Bridges)

INPUT:
1

OUTPUT:
Case #1:
2-0 0-1 1-2 2-3
Case #2:
1-0 0-2 2-3 3-1 1-0 0-2

*/

class Graph
{
    // No. of vertices
    int V;

    // A dynamic array of adjacency lists
    list<int> *adj;

public:
    // Constructor and destructor
    Graph(int V)
    {
        this->V = V;
        adj = new list<int>[V];
    }
    ~Graph()
    {
        delete[] adj;
    }

    // functions to add and remove edge
    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // This function removes edge u-v from graph.
    // It removes the edge by replacing adjacent
    // vertex value with -1.
    void rmvEdge(int u, int v)
    {
        // Find v in adjacency list of u and replace
        // it with -1
        list<int>::iterator iv = find(adj[u].begin(), adj[u].end(), v);
        *iv = -1;

        // Find u in adjacency list of v and replace
        // it with -1
        list<int>::iterator iu = find(adj[v].begin(), adj[v].end(), u);
        *iu = -1;
    }

    // Methods to print Eulerian tour
    /* The main function that print Eulerian Trail.
It first finds an odd degree vertex (if there is any)
and then calls printEulerUtil() to print the path */
    void printEulerTour()
    {
        // Find a vertex with odd degree
        int u = 0;

        for (int i = 0; i < V; i++)
            if (adj[i].size() & 1)
            {
                u = i;
                break;
            }

        // Print tour starting from oddv
        printEulerUtil(u);
        cout << endl;
    }
    // Print Euler tour starting from vertex u
    void printEulerUtil(int u)
    {

        // Recur for all the vertices adjacent to
        // this vertex
        list<int>::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
        {
            int v = *i;

            // If edge u-v is not removed and it's a a
            // valid next edge
            if (v != -1 && isValidNextEdge(u, v))
            {
                cout << u << "-" << v << " ";
                rmvEdge(u, v);
                printEulerUtil(v);
            }
        }
    }

    // This function returns count of vertices
    // reachable from v. It does DFS
    // A DFS based function to count reachable
    // vertices from v
    int DFSCount(int v, bool visited[])
    {
        // Mark the current node as visited
        visited[v] = true;
        int count = 1;

        // Recur for all vertices adjacent to this vertex
        list<int>::iterator i;
        for (i = adj[v].begin(); i != adj[v].end(); ++i)
        {
            if (*i != -1 && !visited[*i])
            {
                count += DFSCount(*i, visited);
            }
        }

        return count;
    }

    // Utility function to check if edge u-v
    // is a valid next edge in Eulerian trail or circuit
    // The function to check if edge u-v can be considered
    // as next edge in Euler Tout
    bool isValidNextEdge(int u, int v)
    {

        // The edge u-v is valid in one of the following
        // two cases:

        // 1) If v is the only adjacent vertex of u
        int count = 0; // To store count of adjacent vertices
        list<int>::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
        {
            if (*i != -1)
            {
                count++;
            }
        }
        if (count == 1)
        {
            return true;
        }

        // 2) If there are multiple adjacents, then u-v
        //    is not a bridge
        // Do following steps to check if u-v is a bridge

        // 2.a) count of vertices reachable from u
        bool visited[V];
        memset(visited, false, V);
        int count1 = DFSCount(u, visited);

        // 2.b) Remove edge (u, v) and after removing
        // the edge, count vertices reachable from u
        rmvEdge(u, v);
        memset(visited, false, V);
        int count2 = DFSCount(u, visited);

        // 2.c) Add the edge back to the graph
        addEdge(u, v);

        // 2.d) If count1 is greater, then edge (u, v)
        // is a bridge
        return (count1 > count2) ? false : true;
    }
};

void solve()
{
    Graph g1(4);
    g1.addEdge(0, 1);
    g1.addEdge(0, 2);
    g1.addEdge(1, 2);
    g1.addEdge(2, 3);
    g1.printEulerTour();

    Graph g3(4);
    g3.addEdge(0, 1);
    g3.addEdge(1, 0);
    g3.addEdge(0, 2);
    g3.addEdge(2, 0);
    g3.addEdge(2, 3);
    g3.addEdge(3, 1);

    g3.printEulerTour();
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