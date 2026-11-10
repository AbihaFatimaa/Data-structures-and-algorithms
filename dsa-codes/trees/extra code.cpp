# include <iostream>
# include <string>
using namespace std;
int countLeafNodes()
{
    return countLeafNodes(0);
}
int countLeafNodes(int index)
{
    // Base case
    if(index >= size || !status[index])
        return 0;

    int left = 2 * index + 1;
    int right = 2 * index + 2;

    bool hasLeft = (left < size && status[left]);
    bool hasRight = (right < size && status[right]);

    // Current node is a leaf
    if(!hasLeft && !hasRight)
        return 1;

    // Count leaves in both subtrees
    return countLeafNodes(left) + countLeafNodes(right);
}

int countInternalNodes()
{
    return countInternalNodes(0);
}

int countInternalNodes(int index)
{
    // Base case
    if(index >= size || !status[index])
        return 0;

    int left = 2 * index + 1;
    int right = 2 * index + 2;

    bool hasLeft = (left < size && status[left]);
    bool hasRight = (right < size && status[right]);

    int count = 0;

    // Check whether current node is internal
    if(hasLeft || hasRight)
        count = 1;

    return count +
           countInternalNodes(left) +
           countInternalNodes(right);
}

int countOneChildNodes()
{
    return countOneChildNodes(0);
}

int countOneChildNodes(int index)
{
    // Base case
    if(index >= size || !status[index])
        return 0;

    int left = 2 * index + 1;
    int right = 2 * index + 2;

    bool hasLeft = (left < size && status[left]);
    bool hasRight = (right < size && status[right]);

    int count = 0;

    // Exactly one child
    if(hasLeft != hasRight)
        count = 1;

    return count +
           countOneChildNodes(left) +
           countOneChildNodes(right);
}

void findMinMax(int index, int &minimum, int &maximum)
{
    if(index >= size || !status[index])
        return;

    if(data[index] < minimum)
        minimum = data[index];

    if(data[index] > maximum)
        maximum = data[index];

    int left = 2 * index + 1;
    int right = 2 * index + 2;

    findMinMax(left, minimum, maximum);
    findMinMax(right, minimum, maximum);
}
int findMin()
{
    if(size == 0 || !status[0])
        return -1;

    return findMin(0);
}

int findMin(int index)
{
    if(index >= size || !status[index])
        return INT_MAX;

    int left = 2 * index + 1;
    int right = 2 * index + 2;

    int leftMin = findMin(left);
    int rightMin = findMin(right);
   
    int minimum = data[index];

    if(leftMin < minimum)
        minimum = leftMin;

    if(rightMin < minimum)
        minimum = rightMin;

    return minimum;
}
//complete if at right most of tree.
bool isComplete()
{
    bool foundEmpty = false;

    for(int i = 0; i < size; i++)
    {
        if(!status[i])
        {
            foundEmpty = true;
        }
        else if(foundEmpty)
        {
            return false;
        }
    }

    return true;
}

bool isFull()
{
    return isFull(0);
}
//full if onlu 2 or 0 child
bool isFull(int index)
{
    if(index >= size || !status[index])
        return true;

    int left = 2 * index + 1;
    int right = 2 * index + 2;

    bool hasLeft = (left < size && status[left]);
    bool hasRight = (right < size && status[right]);

    if(hasLeft != hasRight)
        return false;

    return isFull(left) && isFull(right);
}

int findLeafDepth(int index, int depth)
{
    if(index >= size || !status[index])
        return -1;

    int left = 2 * index + 1;
    int right = 2 * index + 2;

    bool hasLeft = (left < size && status[left]);
    bool hasRight = (right < size && status[right]);

    if(!hasLeft && !hasRight)
        return depth;

    int result = findLeafDepth(left, depth + 1);

    if(result != -1)
        return result;

    return findLeafDepth(right, depth + 1);
}
bool checkPerfect(int index, int depth, int leafDepth)
{
    if(index >= size || !status[index])
        return true;

    int left = 2 * index + 1;
    int right = 2 * index + 2;

    bool hasLeft = (left < size && status[left]);
    bool hasRight = (right < size && status[right]);

    if(hasLeft != hasRight)
        return false;

    if(!hasLeft && !hasRight)
        return depth == leafDepth;

    return checkPerfect(left, depth + 1, leafDepth) &&
           checkPerfect(right, depth + 1, leafDepth);
}
bool isPerfect()
{
    if(size == 0 || !status[0])
        return true;

    int leafDepth = findLeafDepth(0, 0);

    return checkPerfect(0, 0, leafDepth);
}

int checkBalance(int index)
{
    if(index >= size || !status[index])
        return 0;

    int left = 2 * index + 1;
    int right = 2 * index + 2;

    int leftHeight = checkBalance(left);

    if(leftHeight == -1)
        return -1;

    int rightHeight = checkBalance(right);

    if(rightHeight == -1)
        return -1;

    if(abs(leftHeight - rightHeight) > 1)
        return -1;

    if(leftHeight > rightHeight)
        return leftHeight + 1;
    else
        return rightHeight + 1;
}
bool isBalanced()
{
    return checkBalance(0) != -1;
}

int calculateDiameter(int index)
{
    if(index >= size || !status[index])
        return 0;

    int left = 2 * index + 1;
    int right = 2 * index + 2;

    int leftHeight = calculateDiameter(left);
    int rightHeight = calculateDiameter(right);

    int currentDiameter = leftHeight + rightHeight;

    if(currentDiameter > maxDiameter)
        maxDiameter = currentDiameter;

    if(leftHeight > rightHeight)
        return leftHeight + 1;
    else
        return rightHeight + 1;
}
int diameter()
{
    maxDiameter = 0;

    calculateDiameter(0);

    return maxDiameter;
}