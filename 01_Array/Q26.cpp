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
Q26.) Maximum profit by buying and selling a share atmost twice

INPUT:
6

6
10 22 5 75 65 80

7
2 30 15 10 8 25 80

7
100 30 15 10 8 25 80

5
90 80 70 60 50

8
3 3 5 0 0 3 1 4

5
1 2 3 4 5

OUTPUT:
Case #1: 87
Case #2: 100
Case #3: 72
Case #4: 0
Case #5: 6
Case #6: 4

*/

// Function to find the maximum
// profit with two transactions
// on a given list of stock prices
int maxProfit(int price[], int n)
{

    // buy1 - Money lent to buy 1 stock
    // profit1 - Profit after selling
    // the 1st stock buyed.
    // buy2 - Money lent to buy 2 stocks
    // including profit of selling 1st stock
    // profit2 - Profit after selling 2 stocks
    int buy1, profit1, buy2, profit2;

    // Set initial buying values to
    // INT_MAX as we want to minimize it
    buy1 = buy2 = INT_MAX;

    // Set initial selling values to
    // zero as we want to maximize it
    profit1 = profit2 = 0;

    for (int i = 0; i < n; i++)
    {

        // Money lent to buy the stock
        // should be minimum as possible.
        // buy1 tracks the minimum possible
        // stock to buy from 0 to i-1.
        buy1 = min(buy1, price[i]);

        // Profit after selling a stock
        // should be maximum as possible.
        // profit1 tracks maximum possible
        // profit we can make from 0 to i-1.
        profit1 = max(profit1, price[i] - buy1);

        // Now for buying the 2nd stock,
        // we will integrate profit made
        // from selling the 1st stock
        buy2 = min(buy2, price[i] - profit1);

        // Profit after selling a 2 stocks
        // should be maximum as possible.
        // profit2 tracks maximum possible
        // profit we can make from 0 to i-1.
        profit2 = max(profit2, price[i] - buy2);
    }

    return profit2;
}

void solve()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << maxProfit(a, n) << endl;
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