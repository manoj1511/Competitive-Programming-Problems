#include<iostream>
#include<map>
#include<queue>

using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int num)
    {
        data = num;
        left = NULL;
        right = NULL;
    }
};

void preorder(Node *root)
{
    if (root == NULL) return;
    cout << root -> data << " ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(Node *root)
{
    if (root == NULL) return;
    inorder(root->left);
    cout << root -> data << " ";
    inorder(root->right);
}

void postorder(Node* root)
{
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root -> data << " ";
}

void insert(Node* root, int num)
{
    if(root -> data == num)
    {
        cout << "number already present"<< endl; return;
    }
    else if(root -> data > num)
    {
        if(root -> left == NULL)
        {
            root -> left =  new Node(num);
        }
        else
        {
            insert(root->left, num);
        }
    }
    else
    {
        if(root -> right == NULL)
        {
            root -> right =  new Node(num);
        }
        else
        {
            insert(root->right, num);
        }
    }
}

Node* findMin(Node* root)
{
    while(root != NULL && root->left != NULL)
    {
        root = root -> left;
    }
    return root;
}

Node* deleteNode(Node *root,int num)
{
    if(root == NULL) return root;
    else if(root->data > num) root -> left = deleteNode(root->left, num);
    else if(root->data < num) root -> right = deleteNode(root->right, num);
    else
    {
        if(root -> left == NULL && root -> right == NULL)
        {
            delete root;
            root = NULL;
        }
        else if(root -> right == NULL)
        {
            Node *temp = root;
            root = root -> left;
            delete temp;
        }
        else if(root -> left == NULL)
        {
            Node *temp = root;
            root = root -> right;
            delete temp;
        }
        else
        {
            Node *temp = findMin(root->right);
            root -> data = temp -> data;
            root -> right = deleteNode(root -> right, temp -> data);
        }
    }
    return root;
}

int heightTree(Node* root)
{
    if(root == NULL) return 0;
    else
    {
        int lheight = heightTree(root -> left);
        int rheight = heightTree(root -> right);
        return max(rheight, lheight)+1;
    }
}

map<int, int> widthTree(Node *root)
{
    map<int,int> width;
    if(root == NULL) return width;

    int result = 0;
    queue<Node*> q;
    q.push(root);
    
    int level = 0;
    while(q.empty() == false)
    {
        int count = q.size();
        width[level] = count;
        
        while(count--)
        {
            Node* temp = q.front();
            q.pop();
            if(temp -> left != NULL) q.push(temp -> left);
            if(temp -> right != NULL) q.push(temp -> right);
        }
            
        level++;
    }
    return width;
}

int main()
{
    // Create a BST
    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(3);
    root->left->right = new Node(7);
    root->right->left = new Node(13);
    root->right->right = new Node(17);
    
    // Perform Operations
    cout << "preorder : "; preorder(root); cout << endl;
    cout << "inorder : "; inorder(root); cout << endl;
    cout << "postorder : "; postorder(root); cout << endl;
    insert(root, 12);
    cout << "inorder after inserting 12 : "; inorder(root); cout << endl;
    root = deleteNode(root, 15);
    cout << "inorder after deleting 15 : "; inorder(root); cout << endl;
    cout << "height of the binary tree is : " << heightTree(root) << endl;
    cout << "inorder : "; inorder(root); cout << endl;
    map <int, int> width = widthTree(root);
    cout << "Width at each level" << endl;
    for(auto itr = width.begin(); itr!=width.end(); itr++)
    {
        cout << itr -> first << " : " << itr -> second << endl;
    }   
    return 0;
}
