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
    // Function to check if the indices (i, j)
    // are valid indices in a Matrix or not
    bool issafe(int m, int n, int i, int j)
    {

        // Cases for invalid cells
        if (i < 0)
        {
            return false;
        }
        else if (j < 0)
        {
            return false;
        }
        else if (i >= m)
        {
            return false;
        }
        else if (j >= n)
        {
            return false;
        }
        else
        {
            // Return true if valid
            return true;
        }
    }

    // Function to find indices of cells
    // of a matrix from which traversal
    // leads to out of the matrix
    pair<int, int> endPoints(vector<vector<int>> arr)
    {
        int m = arr.size();    // row
        int n = arr[0].size(); // col
        // Starting from cell (0, 0),
        // traverse in right direction
        int i = 0;
        int j = 0;
        int current_i = 0;
        int current_j = 0;

        char current_d = 'r';

        // Stores direction changes
        map<char, char> rcd = {{'l', 'u'}, {'u', 'r'}, {'r', 'd'}, {'d', 'l'}};

        // Iterate until the current cell
        // exceeds beyond the matrix
        while (issafe(m, n, i, j))
        {

            // Current index
            current_i = i;
            current_j = j;

            // If the current cell is 1
            if (arr[i][j] == 1)
            {

                char move_in = rcd[current_d];

                // Update arr[i][j] = 0
                arr[i][j] = 0;

                // Update indices according
                // to the direction
                if (move_in == 'u')
                {
                    i -= 1;
                }
                else if (move_in == 'd')
                {
                    i += 1;
                }
                else if (move_in == 'l')
                {
                    j -= 1;
                }
                else if (move_in == 'r')
                {
                    j += 1;
                }

                current_d = move_in;
            }

            // Otherwise
            else
            {
                // Update indices according
                // to the direction
                if (current_d == 'u')
                {
                    i -= 1;
                }
                else if (current_d == 'd')
                {
                    i += 1;
                }
                else if (current_d == 'l')
                {
                    j -= 1;
                }
                else if (current_d == 'r')
                {
                    j += 1;
                }
            }
        }
        // The exit coordinates
        return {current_i, current_j};
    }
};

void solve()
{
    int row, col;
    cin >> row >> col;
    vector<vector<int>> matrix(row, vector<int>(col));

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> matrix[i][j];
        }
    }
    Solution obj;
    pair<int, int> p = obj.endPoints(matrix);

    cout << "(" << p.first << ", " << p.second << ")" << endl;
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