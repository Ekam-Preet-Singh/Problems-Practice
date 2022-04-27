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
Q405.) Minimum cost to fill given weight in a bag

INPUT:
2

5 5
20 10 4 50 100

5 5
-1 -1 4 3 -1

OUTPUT:
Case #1: 14
Case #2: -1

*/

class Solution
{

public:
    int minimumCost(int cost[], int N, int W)
    {

        int INF = 999999999;

        // val[] and wt[] arrays
        // val[] array to store cost of 'i' kg packet of orange
        // wt[] array weight of packet of orange
        vector<int> val, wt;

        // traverse the original cost[] array and skip
        // unavailable packets and make val[] and wt[]
        // array. size variable tells the available number
        // of distinct weighted packets
        int size = 0;
        for (int i = 0; i < N; i++)
        {
            if (cost[i] != -1)
            {
                val.push_back(cost[i]);
                wt.push_back(i + 1);
                size++;
            }
        }

        N = size;
        int min_cost[N + 1][W + 1];

        // fill 0th row with infinity
        for (int i = 0; i <= W; i++)
        {
            min_cost[0][i] = INF;
        }

        // fill 0'th column with 0
        for (int i = 1; i <= N; i++)
        {
            min_cost[i][0] = 0;
        }

        // now check for each weight one by one and fill the
        // matrix according to the condition
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= W; j++)
            {
                // wt[i-1]>j means capacity of bag is
                // less then weight of item
                if (wt[i - 1] > j)
                {
                    min_cost[i][j] = min_cost[i - 1][j];
                }

                // here we check we get minimum cost either
                // by including it or excluding it
                else
                {
                    min_cost[i][j] = min(min_cost[i - 1][j], min_cost[i][j - wt[i - 1]] + val[i - 1]);
                }
            }
        }

        // exactly weight W can not be made by given weights
        return (min_cost[N][W] == INF) ? -1 : min_cost[N][W];
    }
};

void solve()
{
    int n, w;
    cin >> n >> w;

    int a[n];

    for (int i = 0; i < n; i++)
        cin >> a[i];

    Solution ob;
    cout << ob.minimumCost(a, n, w) << "\n";
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