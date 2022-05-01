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
Q433.) Maximum profit by buying and selling a share at most k times

INPUT:
3

2 6
10 22 5 75 65 80

3 4
20 580 420 900

1 5
100 90 80 50 25

OUTPUT:
Case #1: 87
Case #2: 1040
Case #3: 0

*/

class Solution
{
public:
    int maxProfit(int K, int N, int A[])
    {
        // table to store results of subproblems profit[t][i] stores maximum
        // profit using atmost t transactions up to day i (including day i)
        int profit[K + 1][N + 1];

        // For day 0, you can't earn money irrespective of how many times you
        // trade
        for (int i = 0; i <= K; i++)
        {
            profit[i][0] = 0;
        }

        // profit is 0 if we don't do any transation (i.e. k =0)
        for (int j = 0; j <= N; j++)
        {
            profit[0][j] = 0;
        }

        // fill the table in bottom-up fashion
        for (int i = 1; i <= K; i++)
        {
            int prevDiff = INT_MIN;
            for (int j = 1; j < N; j++)
            {
                prevDiff = max(prevDiff, profit[i - 1][j - 1] - A[j - 1]);
                profit[i][j] = max(profit[i][j - 1], A[j] + prevDiff);
            }
        }

        return profit[K][N - 1];
    }
};

void solve()
{
    int N, K;
    cin >> K;
    cin >> N;
    int A[N];
    for (int i = 0; i < N; i++)
        cin >> A[i];

    Solution ob;
    cout << ob.maxProfit(K, N, A) << endl;
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