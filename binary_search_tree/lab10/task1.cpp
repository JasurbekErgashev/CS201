#include <iostream>
 
using namespace std;
 
struct binaryTreeNode
{
    int data;
    binaryTreeNode* left, * right;
    binaryTreeNode(int data)
    {
        left = right = NULL;
        this->data = data;
    }
};
class BSTree
{
public:
    BSTree()
    {
        root = NULL;
    }
    void insert(int insertItem)
    {
        binaryTreeNode* current;
        binaryTreeNode* trailCurrent = NULL;
        binaryTreeNode* newNode;
        newNode = new binaryTreeNode(insertItem);
        if (root == NULL)
            root = newNode;
        else
        {
            current = root;
            while (current != NULL)
            {
                trailCurrent = current;
                if (current->data == insertItem)
                {
                    cout << "The insert item is already in the list - \n";
                    cout << "duplicates are not allowed." << insertItem << endl;
                    return;
                }
                else if (current->data > insertItem)
                    current = current->left;
                else
                    current = current->right;
 
            }
            if (trailCurrent->data > insertItem)
                trailCurrent->left = newNode;
            else
                trailCurrent->right = newNode;
 
        }
    }
    void inorder()
    {
        printInorder(root);
    }
    void printInorder(struct binaryTreeNode* node)
    {
        if (node == NULL)
            return;
        printInorder(node->left);
        cout << node->data << " ";
        printInorder(node->right);
    }
    int calculateHeight() {
        return height(root);
    }
    bool search(const int& searchItem) {
        binaryTreeNode* current;
        bool found = false;
        if (root == NULL)
            cout << "Cannot search the empty tree." << endl;
        else
        {
            current = root;
            while (current != NULL && !found)
            {
                if (current->data == searchItem)
                    found = true;
                else if (current->data > searchItem)
                    current = current->left;
                else
                    current = current->right;
            }
        }
        return found;
    }
    BSTree(const BSTree& otherTree) {
        if (otherTree.root == NULL)
            root = NULL;
        else
            copyTree(root, otherTree.root);
    };
    void destroyTree() {
        destroy(root);
    };
    ~BSTree() {
        destroy(root);
    };
   
private:
    binaryTreeNode* root;
    int height(binaryTreeNode* p) const {
        if (p == NULL)
            return 0;
        else
            return 1 + max(height(p->left), height(p->right));
    };
    int max(int x, int y) const {
        if (x >= y)
            return x;
        else
            return y;
    };
    void copyTree(binaryTreeNode*& copiedTreeRoot, binaryTreeNode* otherTreeRoot) {
        if (otherTreeRoot == NULL)
            copiedTreeRoot = NULL;
        else {
            copiedTreeRoot = new binaryTreeNode(otherTreeRoot->data);
            copyTree(copiedTreeRoot->left, otherTreeRoot->left);
            copyTree(copiedTreeRoot->right, otherTreeRoot->right);
        }
    };
    void destroy(binaryTreeNode*& p) {
        if (p != NULL) {
            destroy(p->left);
            destroy(p->right);
            cout << "About to delete " << p->data << endl;
            delete p;
            p = NULL;
        }
    };
};
int main()
{
    BSTree obj;
    obj.insert(20);
    obj.insert(10);
    obj.insert(3);
    obj.insert(13);
    obj.insert(40);
    obj.insert(23);
    obj.insert(53);
    obj.insert(31);
    obj.insert(47);
    BSTree obj2(obj);
    obj.insert(45);
    cout << endl << "The height of first tree is " << obj.calculateHeight() << endl;
    cout << endl << "The height of copied tree is " << obj2.calculateHeight() << endl;
    cout << "\n\ninorder traversal for first tree is " << endl;
    obj.inorder();
    cout << "\n\n\ninorder traversal for the copied tree is " << endl;
    obj2.inorder();
    cout << endl;
 
    cout << "\n\n\nTo test the destructor: \n\n";
 
    BSTree* ptrTree = new BSTree;
    (*ptrTree).insert(20);
    (*ptrTree).insert(10);
    (*ptrTree).insert(3);
    (*ptrTree).insert(13);
    (*ptrTree).insert(40);
    (*ptrTree).insert(23);
    (*ptrTree).insert(53);
    (*ptrTree).insert(31);
    (*ptrTree).insert(47);
    delete ptrTree;
 
    cout << "\nFinished \n\n\n";
}
