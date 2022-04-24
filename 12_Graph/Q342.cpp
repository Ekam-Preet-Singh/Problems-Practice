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
Q342.) Find whether it is possible to finish all tasks or not from given dependencies

INPUT:
2

4
1 0
2 1
3 2

2
1 0

OUTPUT:
Case #1: Yes
Case #2: No

*/

class Solution
{
public:
    // Returns adjacency list representation from a list of pairs
    vector<unordered_set<int>>
    make_graph(int numTasks, vector<pair<int, int>> &prerequisites)
    {
        vector<unordered_set<int>> graph(numTasks);
        for (auto pre : prerequisites)
        {
            graph[pre.second].insert(pre.first);
        }
        return graph;
    }

    // A DFS based function to check if there is a cycle in the directed graph
    bool dfs_cycle(vector<unordered_set<int>> &graph, int node, vector<bool> &onpath, vector<bool> &visited)
    {
        if (visited[node])
        {
            return false;
        }
        onpath[node] = visited[node] = true;
        for (int neigh : graph[node])
        {
            if (onpath[neigh] || dfs_cycle(graph, neigh, onpath, visited))
            {
                return true;
            }
        }
        return onpath[node] = false;
    }

    // Main function to check whether it is possible to finish all tasks or not
    bool isPossible(int N, vector<pair<int, int>> &prerequisites)
    {
        vector<unordered_set<int>> graph = make_graph(N, prerequisites);
        vector<bool> onpath(N, false), visited(N, false);
        for (int i = 0; i < N; i++)
        {
            if (!visited[i] && dfs_cycle(graph, i, onpath, visited))
            {
                return false;
            }
        }
        return true;
    }
};

void solve()
{
    int N, P;
    vector<pair<int, int>> prerequisites;
    cin >> N;
    cin >> P;
    for (int i = 0; i < P; ++i)
    {
        int x, y;
        cin >> x >> y;
        prerequisites.push_back(make_pair(x, y));
    }
    // string s;
    // cin>>s;
    Solution ob;
    if (ob.isPossible(N, prerequisites))
        cout << "Yes";
    else
        cout << "No";
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