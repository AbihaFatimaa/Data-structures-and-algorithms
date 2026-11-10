#include <iostream>
#include "../../ds/BinaryTreeArr.h"
using namespace std;

int main()
{
    BinaryTreeArr t(3);

    // 1. Create the tree
    t.setRoot(10);

    t.setLeft(10, 20);
    t.setRight(10, 30);

    t.setLeft(20, 40);
    t.setRight(20, 50);

    t.setLeft(30, 60);
    t.setRight(30, 70);

    // 2. Test traversals
    cout << "Preorder: ";
    t.preOrder();

    cout << "\nInorder: ";
    t.inOrder();

    cout << "\nPostorder: ";
    t.postOrder();

    cout << "\nLevel Order: ";
    t.levelOrderPrint();

    // 3. Test getParent
    cout << "\n\nParent of 50: ";
    cout << t.getParent(50);

    cout << "\nParent of 30: ";
    cout << t.getParent(30);

    cout << "\nParent of root (10): ";
    cout << t.getParent(10);

    // 4. Test getHeight
    cout << "\n\nHeight of tree: ";
    cout << t.getHeight();

    // 5. Test removing a leaf
    cout << "\n\nRemoving node 50...";
    t.remove(50);

    cout << "\nLevel Order: ";
    t.levelOrderPrint();

    cout << "\nHeight: ";
    cout << t.getHeight();

    // 6. Test removing a subtree
    cout << "\n\nRemoving node 20...";
    t.remove(20);

    cout << "\nLevel Order: ";
    t.levelOrderPrint();

    cout << "\nHeight: ";
    cout << t.getHeight();

    // 7. Test removing root
    cout << "\n\nRemoving root 10...";
    t.remove(10);

    cout << "\nLevel Order: ";
    t.levelOrderPrint();

    cout << "\nHeight: ";
    cout << t.getHeight();

    cout << endl;

    return 0;
}