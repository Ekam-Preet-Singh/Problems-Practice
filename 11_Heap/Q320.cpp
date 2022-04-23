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
Q320.) Smallest range in “K” Lists

INPUT:
2

5 3
1 3 5 7 9
0 2 4 6 8
2 3 5 7 11

4 3
1 2 3 4
5 6 7 8
9 10 11 12

OUTPUT:
Case #1: 1 2
Case #2: 4 9

*/

#define N 1000

// A min heap node
struct MinHeapNode
{
    int element; // The element to be stored
    int i;       // index of the list from which the element is taken
    int j;       // index of the next element to be picked from list
};

// A class for Min Heap
class MinHeap
{
    MinHeapNode *harr;
    int heap_size;

public:
    MinHeap(MinHeapNode a[], int size)
    {
        heap_size = size;
        harr = a;
        int i = (heap_size - 1) / 2;
        while (i >= 0)
        {
            MinHeapify(i);
            i--;
        }
    }
    void MinHeapify(int i)
    {
        int l = left(i);
        int r = right(i);
        int smallest = i;
        if (l < heap_size && harr[l].element < harr[i].element)
        {
            smallest = l;
        }
        if (r < heap_size && harr[r].element < harr[smallest].element)
        {
            smallest = r;
        }
        if (smallest != i)
        {
            swap(harr[i], harr[smallest]);
            MinHeapify(smallest);
        }
    }
    int left(int i) { return (2 * i + 1); }
    int right(int i) { return (2 * i + 2); }
    MinHeapNode getMin() { return harr[0]; }
    void replaceMin(MinHeapNode x)
    {
        harr[0] = x;
        MinHeapify(0);
    }
};

class Solution
{
public:
    pair<int, int> findSmallestRange(int arr[][N], int n, int k)
    {
        int range = INT_MAX;
        int min = INT_MAX, max = INT_MIN;
        int start, end;

        MinHeapNode *harr = new MinHeapNode[k];
        for (int i = 0; i < k; i++)
        {
            harr[i].element = arr[i][0];
            harr[i].i = i;
            harr[i].j = 1;

            if (harr[i].element > max)
            {
                max = harr[i].element;
            }
        }

        MinHeap hp(harr, k);
        while (1)
        {
            MinHeapNode root = hp.getMin();
            min = hp.getMin().element;
            if (range > max - min + 1)
            {
                range = max - min + 1;
                start = min;
                end = max;
            }
            if (root.j < n)
            {
                root.element = arr[root.i][root.j];
                root.j += 1;
                if (root.element > max)
                {
                    max = root.element;
                }
            }
            else
            {
                break;
            }
            hp.replaceMin(root);
        }

        pair<int, int> rangee(start, end);
        return rangee;
    }
};

void solve()
{
    int n, k;
    cin >> n >> k;
    int arr[N][N];
    pair<int, int> rangee;
    for (int i = 0; i < k; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    Solution obj;
    rangee = obj.findSmallestRange(arr, n, k);
    cout << rangee.first << " " << rangee.second << "\n";
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