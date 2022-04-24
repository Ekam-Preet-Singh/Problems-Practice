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
Q362.) Find if there is a path of more thank length from a source

INPUT:
3

4 3 8

0 1 5
1 2 1
2 3 1

9 14 60

0 1 4
0 7 8
1 2 8
1 7 11
2 3 7
2 5 4
2 8 2
3 4 9
3 5 14
4 5 10
5 6 2
6 7 1
6 8 6
7 8 7

9 14 62

0 1 4
0 7 8
1 2 8
1 7 11
2 3 7
2 5 4
2 8 2
3 4 9
3 5 14
4 5 10
5 6 2
6 7 1
6 8 6
7 8 7

OUTPUT:
Case #1: 0
Case #2: 1
Case #3: 0

*/

class Solution
{
public:
    bool path_util(vector<vector<pair<int, int>>> &adj, int par, int n, vector<bool> &visited, int sum, int k)
    {
        if (sum >= k)
        {
            return true;
        }

        if (n == 0)
        {
            return false;
        }

        for (auto elt : adj[par])
        {
            int nbr = elt.first;
            int wt = elt.second;
            if (!visited[nbr])
            {
                visited[nbr] = true;
                sum += wt;
                if (path_util(adj, nbr, n - 1, visited, sum, k))
                {
                    return true;
                }
                sum -= wt;
                visited[nbr] = false;
            }
        }
        return false;
    }

    bool pathMoreThanK(int V, int E, int k, int *a)
    {
        vector<vector<pair<int, int>>> adj(V);
        for (int i = 0; i < E; i++)
        {
            adj[*a].push_back({*(a + 1), *(a + 2)});
            adj[*(a + 1)].push_back({*(a), *(a + 2)});
            a = a + 3;
        }
        vector<bool> visited(V, false);
        int sum = 0;
        visited[0] = true;
        return path_util(adj, 0, V - 1, visited, sum, k);
    }
};

void solve()
{
    int V, E, K;
    cin >> V >> E >> K;
    int a[3 * E + 1];
    for (int i = 0; i < 3 * E; i++)
    {
        cin >> a[i];
    }

    Solution obj;
    if (obj.pathMoreThanK(V, E, K, a))
    {
        cout << 1 << endl;
    }
    else
    {
        cout << 0 << endl;
    }
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