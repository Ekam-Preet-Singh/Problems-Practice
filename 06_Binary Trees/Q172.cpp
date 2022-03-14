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
Q172.) Bottom View of a tree

INPUT:
4

58 31 68 9 56 63 N 5 10 42 57 61 67 3

10 20 30 40 60 N N

5 5 N 4 10 N 8 5 N 8 8 N 6

1 3 2

OUTPUT:
Case #1: 3 5 9 61 63 67 
Case #2: 40 20 60 30 
Case #3: 8 5 6 
Case #4: 3 1 2 

*/

#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node *left;
    Node *right;
};

// Utility function to create a new Tree Node
Node *newNode(int val)
{
    Node *temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

// Function to Build Tree
Node *buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size())
    {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N")
        {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

// Function to return a list containing the bottom view of the given tree.

class Solution
{
public:
    vector<int> bottomView(Node *root)
    {
        vector<int> res;
        if (root == NULL)
        {
            return res;
        }

        // initializing a variable 'hd' with 0 for the root element.
        int hd = 0;

        // TreeMap which stores key value pair sorted on key value.
        map<int, int> m;
        map<Node *, int> mh;

        // Queue to store tree nodes in level order traversal.
        queue<Node *> q;

        // assigning initialized horizontal distance value to
        // root node and adding it to the queue.
        mh[root] = hd;
        q.push(root);

        while (!q.empty())
        {
            Node *temp = q.front();
            q.pop();

            // extracting the horizontal distance value from dequeued tree node.
            hd = mh[temp];

            // putting the dequeued tree node to TreeMap having key as
            // horizontal distance. Every time we find a node having same
            // horizontal distance we need to replace the data in the map.
            m[hd] = temp->data;

            // if the dequeued node has a left child, adding it to
            // the queue with a horizontal distance hd-1.
            if (temp->left != NULL)
            {
                mh[temp->left] = hd - 1;
                q.push(temp->left);
            }

            // if the dequeued node has a right child adding it to
            // the queue with a horizontal distance hd+1.
            if (temp->right != NULL)
            {
                mh[temp->right] = hd + 1;
                q.push(temp->right);
            }
        }

        // traversing the map elements and storing nodes in the list.
        for (map<int, int>::iterator i = m.begin(); i != m.end(); ++i)
            res.push_back(i->second);

        // returning the output list.
        return res;
    }
};

void solve()
{
    string s, ch;
    getline(cin, s);
    Node *root = buildTree(s);
    Solution ob;
    vector<int> res = ob.bottomView(root);
    for (int i : res)
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
    // cin >> t;
    while (t--)
    {
        cout << "Case #" << case_num++ << ": ";
        solve();
    }

    return 0;
}