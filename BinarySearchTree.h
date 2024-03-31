class BinarySearchTree {
private:
    struct Node {
        int key;
        Node* left;
        Node* right;
        Node(const int k) : key(k), left(nullptr), right(nullptr) {}
    };

    Node* root;
    void deleteTree(Node* root);
public:
    BinarySearchTree();
    BinarySearchTree(const BinarySearchTree& other);
    ~BinarySearchTree();
    BinarySearchTree& operator=(const BinarySearchTree& other);
};
