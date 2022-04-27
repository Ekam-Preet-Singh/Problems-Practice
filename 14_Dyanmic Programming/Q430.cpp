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
Q430.) Largest rectangular sub-matrix whose sum is 0

INPUT:
2

3 3
1  2  3
-3 -2 -1
1  7  5

4 4
9  7 16  5
1 -6 -7  3
1  8  7  9
7 -2  0 10

OUTPUT:
Case #1:
-6 -7
8 7
-2 0
Case #2:
1 2 3
-3 -2 -1

*/

const int MAX = 100;

// This function basically finds largest 0
// sum subarray in temp[0..n-1]. If 0 sum
// does't exist, then it returns false. Else
// it returns true and sets starting and
// ending indexes as starti and endj.
bool sumZero(int temp[], int *starti, int *endj, int n)
{
    // Map to store the previous sums
    map<int, int> presum;
    int sum = 0; // Initialize sum of elements

    // Initialize length of sub-array with sum 0
    int max_length = 0;

    // Traverse through the given array
    for (int i = 0; i < n; i++)
    {
        // Add current element to sum
        sum += temp[i];

        if (temp[i] == 0 && max_length == 0)
        {
            *starti = i;
            *endj = i;
            max_length = 1;
        }
        if (sum == 0)
        {
            if (max_length < i + 1)
            {
                *starti = 0;
                *endj = i;
            }
            max_length = i + 1;
        }

        // Look for this sum in Hash table
        if (presum.find(sum) != presum.end())
        {
            // store previous max_length so
            // that we can check max_length
            // is updated or not
            int old = max_length;

            // If this sum is seen before,
            // then update max_len
            max_length = max(max_length, i - presum[sum]);

            if (old < max_length)
            {
                // If max_length is updated then
                // enter and update start and end
                // point of array
                *endj = i;
                *starti = presum[sum] + 1;
            }
        }
        else
        {
            // Else insert this sum with
            // index in hash table
            presum[sum] = i;
        }
    }

    // Return true if max_length is non-zero
    return (max_length != 0);
}

// The main function that finds Largest rectangle
// sub-matrix in a[][] whose sum is 0.
void sumZeroMatrix(int a[][MAX], int row, int col)
{
    int temp[row];

    // Variables to store the final output
    int fup = 0, fdown = 0, fleft = 0, fright = 0;
    int sum;
    int up, down;
    int maxl = INT_MIN;

    // Set the left column
    for (int left = 0; left < col; left++)
    {
        // Initialize all elements of temp as 0
        memset(temp, 0, sizeof(temp));

        // Set the right column for the left column
        // set by outer loop
        for (int right = left; right < col; right++)
        {
            // Calculate sum between current left
            // and right for every row 'i'
            for (int i = 0; i < row; i++)
            {
                temp[i] += a[i][right];
            }

            // Find largest subarray with 0 sum in
            // temp[]. The sumZero() function also
            // sets values of start and finish. So
            // 'sum' is sum of rectangle between (start,
            // left) and (finish, right) which is
            // boundary columns strictly as left and right.
            bool sum = sumZero(temp, &up, &down, row);
            int ele = (down - up + 1) * (right - left + 1);

            // Compare no. of elements with previous
            // no. of elements in sub-Matrix.
            // If new sub-matrix has more elements
            // then update maxl and final boundaries
            // like fup, fdown, fleft, fright
            if (sum && ele > maxl)
            {
                fup = up;
                fdown = down;
                fleft = left;
                fright = right;
                maxl = ele;
            }
        }
    }

    // If there is no change in boundaries
    // than check if a[0][0] is 0
    // If it not zero then print
    // that no such zero-sum sub-matrix exists
    if (fup == 0 && fdown == 0 && fleft == 0 && fright == 0 && a[0][0] != 0)
    {
        cout << "No zero-sum sub-matrix exists";
        return;
    }

    // Print final values
    for (int j = fup; j <= fdown; j++)
    {
        for (int i = fleft; i <= fright; i++)
        {
            cout << a[j][i] << " ";
        }
        cout << endl;
    }
}

void solve()
{
    int a[][MAX] = {{9, 7, 16, 5}, {1, -6, -7, 3}, {1, 8, 7, 9}, {7, -2, 0, 10}};
    int row = 4, col = 4;
    sumZeroMatrix(a, row, col);
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