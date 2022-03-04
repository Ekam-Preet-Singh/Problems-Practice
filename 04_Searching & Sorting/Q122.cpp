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
Q122.) Find the inversion count

INPUT:
2

5
2 4 1 3 5

5
2 3 4 5 6

OUTPUT:
Case #1: 3
Case #2: 0

*/

class Solution
{
public:
    // Counter to keep the count of inversions.
    ll my_counter = 0;

    // p: initial point in the array, say left index
    // q: mid point
    // r: higher range
    // Function to sort and merge two parts of array.
    void merge(ll a[], ll p, ll q, ll r)
    {
        ll l = q - p + 1;
        ll a1[l];

        ll l2 = r - q;

        ll a2[l2];

        // Storing elements present in left half in the array a1.
        for (ll i = 0; i < l; i++)
        {
            a1[i] = a[i + p];
        }
        // Storing elements present in right half in the array a2.
        for (ll i = 0; i < l2; i++)
        {
            a2[i] = a[q + i + 1];
        }

        ll left = 0, right = 0, k = p;

        // Using two pointers over the two arrays which helps in storing the
        // smaller element and thus merging the array.
        while (left < l && right < l2)
        {
            // Comparing element of the arrays a1 and a2 at pointers left and
            // right and accordingly storing the smaller element and updating
            // the pointers.
            if (a1[left] <= a2[right])
            {
                a[k] = a1[left];
                left++;
            }
            else
            {
                a[k] = a2[right];
                right++;
                // Adding the inversions which is the number of elements which
                // are smaller than a2[right] in the a1 array.
                my_counter += (l - left);
            }
            k++;
        }
        // Storing  the remaining elements of left subarray(if there are any)
        // in the array a1.
        while (left < l)
        {
            a[k++] = a1[left++];
        }
        // Storing the remaining elements of right subarray(if there are any)
        // in the array a2.
        while (right < l2)
        {

            a[k++] = a2[right++];
        }
    }

    // Function to mergesort the array, which uses divide and conquer algorithm
    // on left and right halves of array for mergesort operation.
    void mergeSort(ll a[], ll p, ll r)
    {
        if (p < r)
        {
            ll q = (p + r) / 2;
            // Calling recursive function to sort left half of the array.
            mergeSort(a, p, q);

            // Calling recursive function to sort right half of the array.
            mergeSort(a, q + 1, r);

            // Calling merge function which sorts and merges both halves
            // of the array obtained after calling both recursive function.
            merge(a, p, q, r);
        }
    }

    // Function to count inversions in the array.
    ll inversionCount(ll arr[], ll N)
    {
        mergeSort(arr, 0, N - 1);
        ll res = my_counter;
        my_counter = 0;
        // returning the count of inversions in the array.
        return res;
    }
};

void solve()
{
    ll N;
    cin >> N;

    ll A[N];
    for (ll i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    Solution obj;
    cout << obj.inversionCount(A, N) << endl;
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