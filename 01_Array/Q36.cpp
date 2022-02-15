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
Q36.) Median of 2 sorted arrays of different size

INPUT:
3

1 4
900
5 8 10 20

10 9
1 2 3 4 5 6 7 8 9 10
11 12 13 14 15 16 17 18 19

5 6
-5 3 6 12 15
-12 -10 -6 -3 4 10

OUTPUT:
Case #1: 10
Case #2: 10
Case #3: 3

*/

// A utility function to find median of two integers
float MO2(int a, int b)
{
    return (a + b) / 2.0;
}

// A utility function to find median of three integers
float MO3(int a, int b, int c)
{
    return a + b + c - max(a, max(b, c)) - min(a, min(b, c));
}

// A utility function to find a median of four integers
float MO4(int a, int b, int c, int d)
{
    int Max = max(a, max(b, max(c, d)));
    int Min = min(a, min(b, min(c, d)));
    return (a + b + c + d - Max - Min) / 2.0;
}

// Utility function to find median of single array
float medianSingle(int arr[], int n)
{
    if (n == 0)
    {
        return -1;
    }
    else if (n % 2 == 0)
    {
        return (double)(arr[n / 2] + arr[n / 2 - 1]) / 2;
    }
    else
    {
        return arr[n / 2];
    }
}

// This function assumes that N is smaller than or equal to M
// This function returns -1 if both arrays are empty
float findMedianUtil(int A[], int N, int B[], int M)
{
    // If smaller array is empty, return median from second array
    if (N == 0)
    {
        return medianSingle(B, M);
    }

    // If the smaller array has only one element
    else if (N == 1)
    {
        // Case 1: If the larger array also has one element,
        // simply call MO2()
        if (M == 1)
        {
            return MO2(A[0], B[0]);
        }

        // Case 2: If the larger array has odd number of elements,
        // then consider the middle 3 elements of larger array and
        // the only element of smaller array. Take few examples
        // like following
        // A = {9}, B[] = {5, 8, 10, 20, 30} and
        // A[] = {1}, B[] = {5, 8, 10, 20, 30}
        else if (M & 1)
        {
            return MO2(B[M / 2], MO3(A[0], B[M / 2 - 1], B[M / 2 + 1]));
        }

        // Case 3: If the larger array has even number of element,
        // then median will be one of the following 3 elements
        // ... The middle two elements of larger array
        // ... The only element of smaller array
        else
        {
            return MO3(B[M / 2], B[M / 2 - 1], A[0]);
        }
    }

    // If the smaller array has two elements
    else if (N == 2)
    {
        // Case 4: If the larger array also has two elements,
        // simply call MO4()
        if (M == 2)
        {
            return MO4(A[0], A[1], B[0], B[1]);
        }

        // Case 5: If the larger array has odd number of elements,
        // then median will be one of the following 3 elements
        // 1. Middle element of larger array
        // 2. Max of first element of smaller array and element
        //    just before the middle in bigger array
        // 3. Min of second element of smaller array and element
        //    just after the middle in bigger array
        else if (M & 1)
        {
            return MO3(B[M / 2], max(A[0], B[M / 2 - 1]), min(A[1], B[M / 2 + 1]));
        }

        // Case 6: If the larger array has even number of elements,
        // then median will be one of the following 4 elements
        // 1) & 2) The middle two elements of larger array
        // 3) Max of first element of smaller array and element
        //    just before the first middle element in bigger array
        // 4. Min of second element of smaller array and element
        //    just after the second middle in bigger array
        else
        {
            return MO4(B[M / 2], B[M / 2 - 1], max(A[0], B[M / 2 - 2]), min(A[1], B[M / 2 + 1]));
        }
    }

    int idxA = (N - 1) / 2;
    int idxB = (M - 1) / 2;

    /* if A[idxA] <= B[idxB], then median must exist in
       A[idxA....] and B[....idxB] */
    if (A[idxA] <= B[idxB])
    {
        return findMedianUtil(A + idxA, N / 2 + 1, B, M - idxA);
    }
    /* if A[idxA] > B[idxB], then median must exist in
       A[...idxA] and B[idxB....] */
    else
    {
        return findMedianUtil(A, N / 2 + 1, B + idxA, M - idxA);
    }
}

// A wrapper function around findMedianUtil(). This function
// makes sure that smaller array is passed as first argument
// to findMedianUtil
float findMedian(int A[], int N, int B[], int M)
{
    if (N > M)
    {
        return findMedianUtil(B, M, A, N);
    }
    else
    {
        return findMedianUtil(A, N, B, M);
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    int a[n], b[m];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    cout << findMedian(a, n, b, m) << endl;
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