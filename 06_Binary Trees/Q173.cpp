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
Q173.) Zig-Zag traversal of a binary tree

INPUT:
5

58 31 68 9 56 63 N 5 10 42 57 61 67 3

10 20 30 40 60 N N

5 5 N 4 10 N 8 5 N 8 8 N 6

3 2 1

7 9 7 8 8 6 N 10 9 N N N N N N

OUTPUT:
Case #1: 58 68 31 9 56 63 67 61 57 42 10 5 3 
Case #2: 10 30 20 40 60 
Case #3: 5 5 4 10 5 8 8 8 6 
Case #4: 3 1 2 
Case #5: 7 7 9 8 8 6 9 10 

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
public:
    // Function to store the zig zag order traversal of tree in a list.
    vector<int> zigZagTraversal(Node *root)
    {
        vector<int> res;

        // if root is null, we return the list.
        if (!root)
        {
            return res;
        }

        // declaring two stacks to store the current and new level.
        stack<struct Node *> currentlevel;
        stack<struct Node *> nextlevel;

        // pushing the root in currentlevel stack.
        currentlevel.push(root);
        bool lefttoright = true;

        while (!currentlevel.empty())
        {
            // storing the top element of currentlevel stack in temp and popping it.
            Node *temp = currentlevel.top();
            currentlevel.pop();

            // if temp is not null, we store the data at temp in list.
            if (temp)
            {
                res.push_back(temp->data);

                // if lefttoright is true then it stores nodes from left to right
                // else from right to left in nextlevel stack.
                if (lefttoright)
                {
                    if (temp->left)
                    {
                        nextlevel.push(temp->left);
                    }
                    if (temp->right)
                    {
                        nextlevel.push(temp->right);
                    }
                }
                else
                {
                    if (temp->right)
                    {
                        nextlevel.push(temp->right);
                    }
                    if (temp->left)
                    {
                        nextlevel.push(temp->left);
                    }
                }
            }

            // if currentlevel stack is empty lefttoright is flipped to change
            // the order of storing the nodes and both stacks are swapped.
            if (currentlevel.empty())
            {
                lefttoright = !lefttoright;
                swap(currentlevel, nextlevel);
            }
        }
        // returning the list.
        return res;
    }
};

void solve()
{
    string s, ch;
    getline(cin, s);

    Node *root = buildTree(s);

    vector<int> ans;
    Solution ob;
    ans = ob.zigZagTraversal(root);

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";

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