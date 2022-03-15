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
Q176.) Boundary traversal of a Binary tree

INPUT:
2

1 2 3 4 5 6 7 N N 8 9 N N N N

4 10 N 5 5 N 6 7 N 8 8 N 8 11 N 3 4 N 1 3 N 8 6 N 11 11 N 5 8

OUTPUT:
Case #1: 1 2 4 8 9 6 7 3 
Case #2: 4 10 5 6 8 11 3 5 8 8 6 11 11 

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

class Solution
{
    void printLeaves(struct Node *root, vector<int> &res)
    {
        if (root == NULL)
            return;

        printLeaves(root->left, res);

        // Print it if it is a leaf node
        if (!(root->left) && !(root->right))
            res.push_back(root->data);

        printLeaves(root->right, res);
    }

    // A function to print all left boundary nodes, except a leaf node.
    // Print the nodes in TOP DOWN manner
    void printBoundaryLeft(struct Node *root, vector<int> &res)
    {
        if (root == NULL)
            return;

        if (root->left)
        {

            // to ensure top down order, print the node
            // before calling itself for left subtree
            res.push_back(root->data);
            printBoundaryLeft(root->left, res);
        }
        else if (root->right)
        {
            res.push_back(root->data);
            printBoundaryLeft(root->right, res);
        }
        // do nothing if it is a leaf node, this way we avoid
        // duplicates in output
    }

    // A function to print all right boundary nodes, except a leaf node
    // Print the nodes in BOTTOM UP manner
    void printBoundaryRight(struct Node *root, vector<int> &res)
    {
        if (root == NULL)
            return;

        if (root->right)
        {
            // to ensure bottom up order, first call for right
            // subtree, then print this node
            printBoundaryRight(root->right, res);
            res.push_back(root->data);
        }
        else if (root->left)
        {
            printBoundaryRight(root->left, res);
            res.push_back(root->data);
        }
        // do nothing if it is a leaf node, this way we avoid
        // duplicates in output
    }

    // A function to do boundary traversal of a given binary tree
public:
    vector<int> boundary(struct Node *root)
    {
        vector<int> res;
        if (root == NULL)
        {
            return res;
        }

        res.push_back(root->data);

        // Print the left boundary in top-down manner.
        printBoundaryLeft(root->left, res);

        // Print all leaf nodes
        printLeaves(root->left, res);
        printLeaves(root->right, res);

        // Print the right boundary in bottom-up manner
        printBoundaryRight(root->right, res);
    }
};

void solve()
{
    string s, ch;
    getline(cin, s);
    Node *root = buildTree(s);
    Solution ob;
    vector<int> res = ob.boundary(root);
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