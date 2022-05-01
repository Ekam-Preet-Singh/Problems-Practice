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
Q432.) Maximum sum rectangle in a 2D matrix

INPUT:
2

4 5
1 2 -1 -4 -20
-8 -3 4 2 1
3 8 10 1 3
-4 -1 1 7 -6

2 2
-1 -2
-3 -4

OUTPUT:
Case #1: 29
Case #2: -1

*/

class Solution
{
public:
    // Implementation of Kadane's algorithm for
    // 1D array. The function returns the maximum
    // sum and stores starting and ending indexes
    // of the maximum sum subarray at addresses
    // pointed by start and finish pointers
    // respectively.
    int kadane(int *arr, int *start, int *finish, int n)
    {
        // initialize sum, maxSum and
        int sum = 0, maxSum = INT_MIN, i;

        // Just some initial value to check
        // for all negative values case
        *finish = -1;

        // local variable
        int local_start = 0;

        for (i = 0; i < n; ++i)
        {
            sum += arr[i];
            if (sum < 0)
            {
                sum = 0;
                local_start = i + 1;
            }
            else if (sum > maxSum)
            {
                maxSum = sum;
                *start = local_start;
                *finish = i;
            }
        }

        // There is at-least one
        // non-negative number
        if (*finish != -1)
        {
            return maxSum;
        }

        // Special Case: When all numbers
        // in arr[] are negative
        maxSum = arr[0];
        *start = *finish = 0;

        // Find the maximum element in array
        for (i = 1; i < n; i++)
        {
            if (arr[i] > maxSum)
            {
                maxSum = arr[i];
                *start = *finish = i;
            }
        }
        return maxSum;
    }
    int maximumSumRectangle(int R, int C, vector<vector<int>> M)
    {
        int maxSum = INT_MIN, finalLeft, finalRight, finalTop, finalBottom;
        int left, right, i;
        int temp[R], sum, start, finish;
        for (left = 0; left < C; ++left)
        {
            memset(temp, 0, sizeof(temp));
            for (right = left; right < C; ++right)
            {
                for (i = 0; i < R; ++i)
                {
                    temp[i] += M[i][right];
                }
                sum = kadane(temp, &start, &finish, R);
                if (sum > maxSum)
                {
                    maxSum = sum;
                    finalLeft = left;
                    finalRight = right;
                    finalTop = start;
                    finalBottom = finish;
                }
            }
        }
        return maxSum;
    }
};

void solve()
{
    int N, M;
    cin >> N >> M;
    vector<vector<int>> v(N, vector<int>(M));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> v[i][j];
    Solution ob;
    cout << ob.maximumSumRectangle(N, M, v) << "\n";
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