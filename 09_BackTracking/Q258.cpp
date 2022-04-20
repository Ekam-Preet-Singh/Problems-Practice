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
Q258.) m Coloring Problem

INPUT:
2

4
3
5
1 2 2 3 3 4 4 1 1 3

5
1
3
5 1 5 3 4 5

OUTPUT:
Case #1: 1
Case #2: 0

*/

bool isSafe(int v, bool graph[101][101], int color[101], int c, int V)
{
    // checking if the connected nodes to v have same colour as c.
    for (int i = 0; i < V; i++)
    {
        if (graph[v][i] && c == color[i])
        {
            return false;
        }
    }

    // returning true if no connected node has same colour.
    return true;
}

bool graphColoringUtil(bool graph[101][101], int m, int color[101], int v, int V)
{
    // if all vertices have been assigned colour then we return true.
    if (v == V)
    {
        return true;
    }

    for (int c = 1; c <= m; c++)
    {
        // checking if this colour can be given to a particular node.
        if (isSafe(v, graph, color, c, V))
        {
            // assigning colour to the node.
            color[v] = c;

            // calling function recursively and checking if other nodes
            // can be assigned other colours.
            if (graphColoringUtil(graph, m, color, v + 1, V) == true)
            {
                // returning true if the current allocation was successful.
                return true;
            }

            // if not true, we backtrack and remove the colour for that node.
            color[v] = 0;
        }
    }
    // if no colour can be assigned, we return false.
    return false;
}

// Function to determine if graph can be coloured with at most M colours such
// that no two adjacent vertices of graph are coloured with same colour.
bool graphColoring(bool graph[101][101], int m, int n)
{
    int *color = new int[n];
    for (int i = 0; i < n; i++)
    {
        color[i] = 0;
    }

    // checking if colours can be assigned.
    if (graphColoringUtil(graph, m, color, 0, n) == false)
    {
        return false;
    }

    return true;
}

void solve()
{
    int n, m, e;
    cin >> n >> m >> e;
    int i;
    bool graph[101][101];
    for (i = 0; i < n; i++)
    {
        memset(graph[i], 0, sizeof(graph[i]));
    }
    for (i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a - 1][b - 1] = 1;
        graph[b - 1][a - 1] = 1;
    }
    cout << graphColoring(graph, m, n) << endl;
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