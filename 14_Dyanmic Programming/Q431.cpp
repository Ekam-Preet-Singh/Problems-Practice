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
Q431.) Largest area rectangular sub-matrix with equal number of 1’s and 0’s [ IMP ]

INPUT:
2

4 4
0 0 1 1
0 1 1 0
1 1 1 0
1 0 0 1

2 4
0 0 1 1
0 1 1 1

OUTPUT:
Case #1:
(Top, Left): (0, 0)
(Bottom, Right): (3, 1)
Area: 8 sq.units
Case #2:
(Top, Left): (0, 0)
(Bottom, Right): (1, 2)
Area: 6 sq.units

*/

#define MAX_ROW 10
#define MAX_COL 10

// This function basically finds largest 0
// sum subarray in arr[0..n-1]. If 0 sum
// does't exist, then it returns false. Else
// it returns true and sets starting and
// ending indexes as start and end.
bool subArrWithSumZero(int arr[], int &start, int &end, int n)
{
    // to store cumulative sum
    int sum[n];

    // Initialize all elements of sum[] to 0
    memset(sum, 0, sizeof(sum));

    // map to store the indexes of sum
    unordered_map<int, int> um;

    // build up the cumulative sum[] array
    sum[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        sum[i] = sum[i - 1] + arr[i];
    }

    // to store the maximum length subarray
    // with sum equal to 0
    int maxLen = 0;

    // traverse to the sum[] array
    for (int i = 0; i < n; i++)
    {
        // if true, then there is a subarray
        // with sum equal to 0 from the
        // beginning up to index 'i'
        if (sum[i] == 0)
        {
            // update the required variables
            start = 0;
            end = i;
            maxLen = (i + 1);
        }

        // else if true, then sum[i] has not
        // seen before in 'um'
        else if (um.find(sum[i]) == um.end())
        {
            um[sum[i]] = i;
        }

        // sum[i] has been seen before in the
        // unordered_map 'um'
        else
        {
            // if previous subarray length is smaller
            // than the current subarray length, then
            // update the required variables
            if (maxLen < (i - um[sum[i]]))
            {
                maxLen = (i - um[sum[i]]);
                start = um[sum[i]] + 1;
                end = i;
            }
        }
    }

    // if true, then there is no
    // subarray with sum equal to 0
    if (maxLen == 0)
    {
        return false;
    }

    // else return true
    return true;
}

// function to find largest area rectangular
// submatrix with equal number of 1's and 0's
void maxAreaRectWithSumZero(int mat[MAX_ROW][MAX_COL],
                            int row, int col)
{
    // to store intermediate values
    int temp[row], startRow, endRow;

    // to store the final outputs
    int finalLeft, finalRight, finalTop, finalBottom;
    finalLeft = finalRight = finalTop = finalBottom = -1;
    int maxArea = 0;

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
            // consider value '1' as '1' and
            // value '0' as '-1'
            for (int i = 0; i < row; i++)
            {
                temp[i] += mat[i][right] ? 1 : -1;
            }

            // Find largest subarray with 0 sum in
            // temp[]. The subArrWithSumZero() function
            // also sets values of finalTop, finalBottom,
            // finalLeft and finalRight if there exists
            // a subarray with sum 0 in temp
            if (subArrWithSumZero(temp, startRow, endRow, row))
            {
                int area = (right - left + 1) * (endRow - startRow + 1);

                // Compare current 'area' with previous area
                // and accordingly update final values
                if (maxArea < area)
                {
                    finalTop = startRow;
                    finalBottom = endRow;
                    finalLeft = left;
                    finalRight = right;
                    maxArea = area;
                }
            }
        }
    }

    // if true then there is no rectangular submatrix
    // with equal number of 1's and 0's
    if (maxArea == 0)
    {
        cout << "No such rectangular submatrix exists:";
    }

    // displaying the top left and bottom right boundaries
    // with the area of the rectangular submatrix
    else
    {
        cout << "(Top, Left): "
             << "(" << finalTop << ", " << finalLeft
             << ")" << endl;

        cout << "(Bottom, Right): "
             << "(" << finalBottom << ", " << finalRight
             << ")" << endl;

        cout << "Area: " << maxArea << " sq.units";
    }
}
void solve()
{
    int mat[MAX_ROW][MAX_COL] = {{0, 0, 1, 1},
                                 {0, 1, 1, 1}};
    int row = 2, col = 4;
    maxAreaRectWithSumZero(mat, row, col);
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