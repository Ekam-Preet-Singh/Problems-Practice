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
Q69.) Search a Word in a 2D Grid of characters.

INPUT:
3

3 3
a b c
d e f
g h i
abc

6 1
c
b
a
c
e
a
ead

3 4
a b a b
a b e b
e b e b
abe

OUTPUT:
Case #1:
0 0 
Case #2:
-1
Case #3:
0 0 
0 2 
1 0 

*/

class Solution
{
public:
    // This function searches in all 8-direction from point
    // (row, col) in grid[][]
    bool search2D(vector<vector<char>> grid, int row, int col, string word, vector<int> x, vector<int> y)
    {
        int R = grid.size();
        int C = grid[0].size();
        // If first character of word doesn't match with
        // given starting point in grid.
        if (grid[row][col] != word[0])
        {
            return false;
        }

        int len = word.size();

        // Search word in all 8 directions starting from (row,col)
        for (int dir = 0; dir < 8; dir++)
        {
            // Initialize starting point for current direction
            int k, rd = row + x[dir], cd = col + y[dir];

            // First character is already checked, match remaining
            // characters
            for (k = 1; k < len; k++)
            {
                // If out of bound break
                if (rd >= R || rd < 0 || cd >= C || cd < 0)
                {
                    break;
                }

                // If not matched,  break
                if (grid[rd][cd] != word[k])
                {
                    break;
                }

                //  Moving in particular direction
                rd += x[dir], cd += y[dir];
            }

            // If all character matched, then value of must
            // be equal to length of word
            if (k == len)
            {
                return true;
            }
        }
        return false;
    }
    vector<vector<int>> searchWord(vector<vector<char>> grid, string word)
    {
        int row = grid.size();
        int col = grid[0].size();
        vector<int> x = {-1, -1, -1, 0, 0, 1, 1, 1};
        vector<int> y = {-1, 0, 1, -1, 1, -1, 0, 1};
        vector<vector<int>> ans;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (search2D(grid, i, j, word, x, y))
                {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
};

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m, 'x'));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];
    }
    string word;
    cin >> word;
    Solution obj;
    vector<vector<int>> ans = obj.searchWord(grid, word);
    for (auto i : ans)
    {
        for (auto j : i)
            cout << j << " ";
        cout << "\n";
    }
    if (ans.size() == 0)
    {
        cout << "-1\n";
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
        cout << "Case #" << case_num++ << ":\n";
        solve();
    }

    return 0;
}