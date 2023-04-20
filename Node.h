class Node {
public:
    int key;
    int height;
    Node* left;
    Node* right;

    Node(int k) {
        key = k;
        height = 1;
        left = right = nullptr;
    }

    ~Node() {
        delete left;
        delete right;
    }
};
