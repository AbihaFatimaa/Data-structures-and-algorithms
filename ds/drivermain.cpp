#include <iostream>
#include <string>
#include <cmath>
using namespace std;

#include "BinaryTreeArr.h"

int main()
{
    BinaryTreeArr<int> tree(4);

    // Creating tree

    tree.setRoot(10);

    tree.setLeftChild(10, 20);
    tree.setRightChild(10, 30);

    tree.setLeftChild(20, 40);
    tree.setRightChild(20, 50);

    tree.setLeftChild(30, 60);
    tree.setRightChild(30, 70);

    tree.setLeftChild(40, 80);
    tree.setRightChild(40, 90);

    // Traversals

    cout << "\nPreorder: ";
    tree.preOrder();

    cout << "\nInorder: ";
    tree.inOrder();

    cout << "\nPostorder: ";
    tree.postOrder();

    cout << "\nLevel Order: ";
    tree.levelOrderPrint();

    cout << "\nReverse Level Order: ";
    tree.reverseLevelOrder();

    cout << "\nSpiral Order: ";
    tree.spiralOrder();

    // Basic operations

    cout << "\n\nRoot: " << tree.getRoot();

    cout << "\nParent of 50: " << tree.getParent(50);

    cout << "\nLeft child of 20: " << tree.getLeftChild(20);

    cout << "\nRight child of 20: " << tree.getRightChild(20);

    cout << "\nSibling of 40: " << tree.getSibling(40);

    cout << "\nIs 80 a leaf? ";
    cout << tree.isLeaf(80);

    // Height and levels

    cout << "\n\nHeight: " << tree.HeightOfTree();

    cout << "\nLevel of 50: " << tree.findLevelOfNode(50);

    cout << "\nNodes at level 2: ";
    tree.displayLevel(2);

    // Ancestors and descendants

    cout << "\n\nAncestors of 90: ";
    tree.displayAncestors(90);

    cout << "\nDescendants of 20: ";
    tree.displayDescendents(20);

    cout << "\nPath to 90: ";
    tree.displayPath(90);

    // Counting

    cout << "\n\nTotal nodes: " << tree.countNodes();

    cout << "\nLeaf nodes: " << tree.countLeaves();

    cout << "\nInternal nodes: " << tree.countInternalNodes();

    cout << "\nNodes with one child: "
         << tree.countNodesWithOneChild();

    // Display leaves

    cout << "\n\nLeaves: ";
    tree.displayLeaves();

    // Update node

    tree.updateNode(50, 55);

    cout << "\n\nAfter updating 50 to 55: ";
    tree.levelOrderPrint();

    // Remove subtree

    tree.remove(20);

    cout << "\n\nAfter removing subtree rooted at 20: ";
    tree.levelOrderPrint();

    cout << "\nTotal nodes after removal: "
         << tree.countNodes();

    cout << endl;

    return 0;
}