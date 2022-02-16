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

class Solution
{
public:
    bool ValidCorner(const vector<vector<int>> &matrix)
    {
        // finding row and column size
        int rows = matrix.size();
        if (rows == 0)
        {
            return false;
        }

        int columns = matrix[0].size();

        // map for storing the index of combination of 2 1's
        unordered_map<int, unordered_set<int>> table;

        // scanning from top to bottom line by line
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < columns - 1; ++j)
            {
                for (int k = j + 1; k < columns; ++k)
                {
                    // if found two 1's in a column
                    if (matrix[i][j] == 1 && matrix[i][k] == 1)
                    {

                        // check if there exists 1's in same
                        // row previously then return true
                        // we don't need to check (j, k) pair
                        // and again (k, j) pair because we always
                        // store pair in ascending order and similarly
                        // check in ascending order, i.e. j always less
                        // than k.
                        if ((table.find(j) != table.end()) && (table[j].find(k) != table[j].end()))
                        {
                            return true;
                        }

                        // store the indexes in hashset
                        table[j].insert(k);
                    }
                }
            }
        }

        return false;
    }
};

void solve()
{
    int row, col;
    cin >> row >> col;

    vector<vector<int>> matrix(row);

    for (int i = 0; i < row; i++)
    {
        matrix[i].assign(col, 0);
        for (int j = 0; j < col; j++)
        {
            cin >> matrix[i][j];
        }
    }
    Solution ob;
    if (ob.ValidCorner(matrix))
        cout << "Yes\n";
    else
        cout << "No\n";
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    file_i_o();

    ll t = 1;
    // ll case_num = 1;
    cin >> t;
    while (t--)
    {
        // cout << "Case #" << case_num++ << ": ";
        solve();
    }

    return 0;
}