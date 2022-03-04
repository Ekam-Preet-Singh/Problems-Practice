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
Q124.) Partitioning and Sorting Arrays with Many Repeated Entries

INPUT:
9

5
2 4 1 2 5

5
2 3 4 4 6

5
2 4 1 5 5

6
12 11 13 5 11 7

4
1 3 4 3

4
3 1 2 3

7
3 4 1 6 2 5 4

6
3 5 8 9 11 8

7
4 4 4 4 4 4 4

OUTPUT:
Case #1: 1 2 2 4 5
Case #2: 2 3 4 4 6
Case #3: 1 2 4 5 5
Case #4: 5 7 11 11 12 13
Case #5: 1 3 3 4
Case #6: 1 2 3 3
Case #7: 1 2 3 4 4 5 6
Case #8: 3 5 8 8 9 11
Case #9: 4 4 4 4 4 4 4

*/

void swap(int array[], int position1, int position2)
{
    if (position1 != position2)
    {
        int temp = array[position1];
        array[position1] = array[position2];
        array[position2] = temp;
    }
}

// Bentley-McIlroy's Approach
vector<int> quickSortHelper(vector<int> &arr, int begin, int end)
{
    int low = begin, high = end;
    int leftCount = 0, rightCount = 0;

    int partitioningValue = arr[end];

    while (true)
    {
        while (arr[low] < partitioningValue)
        {
            low++;
        }

        while (arr[high] > partitioningValue)
        {
            if (high == begin)
            {
                break;
            }

            high--;
        }

        if (low == high && arr[low] == partitioningValue)
        {
            swap(arr[begin + leftCount], arr[low]);
            leftCount++;
            low++;
        }

        if (low >= high)
        {
            break;
        }

        swap(arr[low], arr[high]);

        if (arr[low] == partitioningValue)
        {
            swap(arr[begin + leftCount], arr[low]);
            leftCount++;
        }

        if (arr[high] == partitioningValue)
        {
            swap(arr[high], arr[end - rightCount]);
            rightCount++;
        }

        low++;
        high--;
    }

    high = low - 1;

    for (int k = begin; k < begin + leftCount; k++, high--)
    {
        if (high >= begin + leftCount)
        {
            swap(arr[k], arr[high]);
        }
    }
    for (int k = end; k > end - rightCount; k--, low++)
    {
        if (low <= end - rightCount)
        {
            swap(arr[low], arr[k]);
        }
    }

    return {high + 1, low - 1};
}

void quicksort(vector<int> &arr, int begin, int end)
{
    if (end <= begin)
    {
        return;
    }
    vector<int> middlePartition = quickSortHelper(arr, begin, end);
    quicksort(arr, begin, middlePartition[0] - 1);
    quicksort(arr, middlePartition[1] + 1, end);
}

vector<int> sortArray(vector<int> &arr)
{
    quicksort(arr, 0, arr.size() - 1);

    return arr;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a)
        cin >> i;
    sortArray(a);

    for (auto &i : a)
        cout << i << " ";
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
        cout << "Case #" << case_num++ << ": ";
        solve();
    }

    return 0;
}