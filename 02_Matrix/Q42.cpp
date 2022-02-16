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
Q42.) Maximum size rectangle

INPUT:
2

4 4
0 1 1 0
1 1 1 1
1 1 1 1
1 1 0 0

2 5
1 1 1 1 1
0 1 0 0 0

OUTPUT:
Case #1: 8
Case #2: 5

*/

#define MAX 1000

class Solution
{
public:
    int mhist(int row[], int m1)
    {
        // Create an empty stack.
        // The stack holds indexes of
        // hist[] array/ The bars stored
        // in stack are always
        // in increasing order of their heights.
        stack<int> result;

        int top_val; // Top of stack

        int max_area = 0; // Initialize max area in current
        // row (or histogram)

        int area = 0; // Initialize area with current top

        // Run through all bars of given histogram (or row)
        int i = 0;
        while (i < m1)
        {
            // If this bar is higher than the bar on top stack,
            // push it to stack
            if (result.empty() || row[result.top()] <= row[i])
            {
                result.push(i++);
            }
            else
            {
                // If this bar is lower than top of stack, then
                // calculate area of rectangle with stack top as
                // the smallest (or minimum height) bar. 'i' is
                // 'right index' for the top and element before
                // top in stack is 'left index'
                top_val = row[result.top()];
                result.pop();
                area = top_val * i;

                if (!result.empty())
                {
                    area = top_val * (i - result.top() - 1);
                }
                max_area = max(area, max_area);
            }
        }
        // Now pop the remaining bars from stack and calculate
        // area with every popped bar as the smallest bar
        while (!result.empty())
        {
            top_val = row[result.top()];
            result.pop();
            area = top_val * i;
            if (!result.empty())
            {
                area = top_val * (i - result.top() - 1);
            }
            max_area = max(area, max_area);
        }
        return max_area;
    }
    // Returns area of the largest rectangle with all 1s in
    // M[][]
    int maxRectangle(int M[MAX][MAX], int n, int m)
    {
        // Calculate area for first row and initialize it as
        // result
        int res = mhist(M[0], m);
        // iterate over row to find maximum rectangular area
        // considering each row as histogram
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                // if M[i][j] is 1 then add M[i -1][j]
                if (M[i][j])
                {
                    M[i][j] += M[i - 1][j];
                }
            }
            // Update result if area with current row (as last
            // row) of rectangle) is more
            res = max(res, mhist(M[i], m));
        }
        return res;
    }
    int maxArea(int M[MAX][MAX], int n, int m)
    {
        return maxRectangle(M, n, m);
    }
};

void solve()
{
    int M[MAX][MAX];
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> M[i][j];
        }
    }
    Solution obj;
    cout << obj.maxArea(M, n, m) << endl;
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