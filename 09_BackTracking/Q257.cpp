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
Q257.) Sudoku Solver

INPUT:
1

3 0 6 5 0 8 4 0 0
5 2 0 0 0 0 0 0 0
0 8 7 0 0 0 0 3 1
0 0 3 0 1 0 0 8 0
9 0 0 8 6 3 0 0 5
0 5 0 0 9 0 6 0 0
1 3 0 0 0 0 2 5 0
0 0 0 0 0 0 0 7 4
0 0 5 2 0 6 3 0 0

OUTPUT:
Case #1:
3 1 6 5 7 8 4 9 2
5 2 9 1 3 4 7 6 8
4 8 7 6 2 9 5 3 1
2 6 3 4 1 5 9 8 7
9 7 4 8 6 3 1 2 5
8 5 1 7 9 2 6 4 3
1 3 8 9 4 7 2 5 6
6 9 2 3 5 1 8 7 4
7 4 5 2 8 6 3 1 9

*/

// UNASSIGNED is used for empty cells in sudoku grid
#define UNASSIGNED 0

// N is used for the size of Sudoku grid.
// Size will be NxN
#define N 9

// } Driver Code Ends

class Solution
{
public:
    // This function searches the grid to find an entry that is still unassigned.
    // If found, the reference parameters row, col will be set the location
    // that is unassigned, and true is returned.
    // If no unassigned entries remain, false is returned.
    bool FindUnassignedLocation(int grid[N][N], int &row, int &col)
    {
        for (row = 0; row < N; row++)
        {
            for (col = 0; col < N; col++)
            {
                if (grid[row][col] == UNASSIGNED)
                {
                    return true;
                }
            }
        }
        return false;
    }

    // Function to print grids of the Sudoku.
    void printGrid(int grid[N][N])
    {
        for (int row = 0; row < N; row++)
        {
            for (int col = 0; col < N; col++)
            {
                cout << grid[row][col] << " ";
            }
            cout << endl;
        }
    }

    // Function to return a boolean which indicates whether an assigned
    // entry in the specified row matches the given number.
    bool UsedInRow(int grid[N][N], int row, int num)
    {
        for (int col = 0; col < N; col++)
        {
            if (grid[row][col] == num)
            {
                return true;
            }
        }
        return false;
    }

    // Function to return a boolean which indicates whether an assigned
    // entry in the specified column matches the given number.
    bool UsedInCol(int grid[N][N], int col, int num)
    {
        for (int row = 0; row < N; row++)
        {
            if (grid[row][col] == num)
            {
                return true;
            }
        }
        return false;
    }

    // Function to return a boolean which indicates whether an assigned
    // entry within the specified 3x3 box matches the given number.
    bool UsedInBox(int grid[N][N], int boxStartRow, int boxStartCol, int num)
    {
        for (int row = 0; row < 3; row++)
        {
            for (int col = 0; col < 3; col++)
            {
                if (grid[row + boxStartRow][col + boxStartCol] == num)
                {
                    return true;
                }
            }
        }
        return false;
    }

    // Function to return a boolean which indicates whether it will be
    // legal to assign num to the given row, column location.
    bool isSafe(int grid[N][N], int row, int col, int num)
    {
        // checking if 'num' is not already placed in
        // current row, current column and current 3x3 box.
        return !UsedInRow(grid, row, num) &&
               !UsedInCol(grid, col, num) &&
               !UsedInBox(grid, row - row % 3,
                          col - col % 3, num) &&
               grid[row][col] == UNASSIGNED;
    }

    // Function to find a solved Sudoku.
    bool SolveSudoku(int grid[N][N])
    {
        int row, col;

        // if there is no unassigned location, we are done.
        if (!FindUnassignedLocation(grid, row, col))
        {
            return true;
        }

        // considering digits from 1 to 9
        for (int num = 1; num <= 9; num++)
        {
            if (isSafe(grid, row, col, num))
            {
                // making tentative assignment
                grid[row][col] = num;

                // if success, return true
                if (SolveSudoku(grid))
                {
                    return true;
                }

                // failure, unmake & try again
                grid[row][col] = UNASSIGNED;
            }
        }
        // this triggers backtracking
        return false;
    }
};

void solve()
{
    int grid[N][N];

    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            cin >> grid[i][j];

    Solution ob;

    if (ob.SolveSudoku(grid) == true)
        ob.printGrid(grid);
    else
        cout << "No solution exists";

    cout << endl;
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