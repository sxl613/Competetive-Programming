#include<bits/stdc++.h>

struct Node {
    int data;
    Node* left;
    Node* right;
};


Node* buildCartesianTreeWrapper(int root, int arr[], int lchild[], int rchild[]){
    if (root == -1)
        return NULL;
    Node* temp = new Node;
    temp->data = arr[root];
    temp->left = buildCartesianTreeWrapper(lchild[root], arr, lchild, rchild);
    temp->right = buildCartesianTreeWrapper(rchild[root], arr, lchild, rchild);
    return temp;
}


Node* buildMinCartesianTree(int arr[], int n){
    int parent[n], lchild[n], rchild[n];
    memset(parent, -1, sizeof(parent));
    memset(lchild, -1, sizeof(lchild));
    memset(rchild, -1, sizeof(rchild));
    int root = 0, last;
    for (int i=1; i < n; i++)
    {
        last = i-1;
        while(arr[i] <= arr[last] && last != root)
        {
            last = parent[last];
        }
        if (arr[last] >= arr[i])
        {
            lchild[i] = root;
            parent[root] = i;
            root = i;
        }
        else if (rchild[last] == -1) // means there is space to put in the current element
        {
            rchild[last] = i;
            parent[i] = last;
        }
        else
        {
            parent[rchild[last]] = i;
            lchild[i] = rchild[last];
            parent[i] = last;
            rchild[last] = i;
        }
    }
    parent[root] = -1;
    return buildCartesianTreeWrapper(root, arr, lchild, rchild);
}

Node* buildMaxCartesianTree(int arr[], int n){
    int parent[n], lchild[n], rchild[n];
    memset(parent, -1, sizeof(parent));
    memset(lchild, -1, sizeof(lchild));
    memset(rchild, -1, sizeof(rchild));
    int root = 0, last;
    for (int i=1; i < n; i++)
    {
        last = i-1;
        while(arr[i] >= arr[last] && last != root)
        {
            last = parent[last];
        }
        if (arr[last] <= arr[i])
        {
            lchild[i] = root;
            parent[root] = i;
            root = i;
        }
        else if (rchild[last] == -1) // means there is space to put in the current element
        {
            rchild[last] = i;
            parent[i] = last;
        }
        else
        {
            parent[rchild[last]] = i;
            lchild[i] = rchild[last];
            parent[i] = last;
            rchild[last] = i;
        }
    }
    parent[root] = -1;
    return buildCartesianTreeWrapper(root, arr, lchild, rchild);
}

/*
    Returns the size of a tree rooted at root.
*/
int subtreeSize(Node* root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + subtreeSize(root->left) + subtreeSize(root->right);
}

/*
    Given an array of length n finds the maximum number obtained by taking the sum of a subarray reduced to the minimum element. 
    For example, given {5, 4, 3, 1, 2, 1, 1}, 
                the subarray {5, 4, 3, 1} reduces to {1, 1, 1, 1} giving a sum of 4
                the subarray {5, 4, 3} reduces to {3, 3, 3} giving a sum of 9.
    Uses a cartesian tree with the minimum elements at the top of the tree.
*/
int subarrayMaximum(Node* root, int n)
{
    if (root == NULL)
    {
        return 0;
    }
    int l = subtreeSize(root->left);
    int r  = subtreeSize(root->right);
    int left = subarrayMaximum(root->left, l);
    int right = subarrayMaximum(root->right, r);
    return std::max(std::max(left, right), n*(root->data));
}

int main()
{
    int n;
    std::cin >> n;
    int* arr = new int[n];
    for (int i=0; i < n; i++)
    {
        std::cin >> arr[i];
    }
 
    Node *root = buildMinCartesianTree(arr, n);
    printf("%d\n", subarrayMaximum(root, n));
    return(0);
}
