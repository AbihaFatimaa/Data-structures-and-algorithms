#ifndef BINARYTREEARR_H
#define BINARYTREEARR_H
# include <iostream>
# include <string>
# include <cmath>
using namespace std;
template<class T>
class BinaryTreeArr
{
	private:
		T * data;
		bool* status;
		int height;
		int size;
	public:
		
		BinaryTreeArr(int h)
		{
		    height = h;
		    size = pow(2, height) - 1;
		
		    data = new T[size];
		    status = new bool[size];
		
		    for(int i = 0; i < size; i++)
		    {
		        status[i] = 0;
		    }
		}
		void setRoot(T r)
		{
			if(status[0]==0)
			{
				data[0] = r;
				status[0] = 1;
			}
		}
		T getRoot()
		{
			return data[0];
		}
		void setLeftChild(T p, T n)
		{
			for(int i=0; i<size; i++)
			{
				if(status[i]==1&&data[i]==p)
				{
					if(2*i+1 <size && status[2*i+1] == 0)
					{
						data[2*i+1] = n;
						status[2*i+1] = 1;
						break;
					}
				}
			}
		}
		void setRightChild(T p, T n)
		{
			for(int i=0; i<size; i++)
			{
				if(status[i]==1&&data[i]==p)
				{
					if(2*i+2 <size && status[2*i+2] == 0)
					{
						data[2*i+2] = n;
						status[2*i+2] = 1;
						break;
					}
				}
			}
		}
		T getParent(T n)
		{
		    for(int i = 0; i < size; i++)
		    {
		        if(status[i] == 1 && data[i] == n)
		        {
		            if(i == 0)
		                return T();
		
		            return data[(i-1)/2];
		        }
		    }
		
		    return -1;
		}
		void displayAncestors(T node)
		{
		    int index = -1;
		
		    for(int i = 0; i < size; i++)
		    {
		        if(status[i] == 1 && data[i] == node)
		        {
		            index = i;
		            break;
		        }
		    }
		
		    if(index == -1 || index == 0)
		        return;
		
		    index = (index - 1) / 2;
		
		    while(index >= 0)
		    {
		        cout << data[index] << " ";
		
		        if(index == 0)
		            break;
		
		        index = (index - 1) / 2;
		    }
		}
		void displayDescendents(T node)
		{
		    int index = -1;
		
		    for(int i = 0; i < size; i++)
		    {
		        if(status[i] == 1 && data[i] == node)
		        {
		            index = i;
		            break;
		        }
		    }
		
		    if(index == -1)
		        return;
		
		    displayDescendents(node, index);
		}
		
		void displayDescendents(T node, int i)
		{
		    if(i >= size || status[i] == 0)
		        return;
		
		    int left = 2*i + 1;
		    int right = 2*i + 2;
		
		    if(left < size && status[left] == 1)
		    {
		        cout << data[left] << " ";
		        displayDescendents(data[left], left);
		    }
		
		    if(right < size && status[right] == 1)
		    {
		        cout << data[right] << " ";
		        displayDescendents(data[right], right);
		    }
		}
		
		void preOrder(int i)
		{
			cout<<data[i]<<" ";
			if(2*i+1 <size && status[2*i+1]==1)
			{
				preOrder(2*i+1);
			}
			if(2*i+2<size && status[2*i+2]==1)
			{
				preOrder(2*i+2);
			}
		}
		void preOrder()
		{
			if(status[0]==1)
			{
				preOrder(0);
			}
		}
		void postOrder(int i)
		{
			if(2*i+1<size && status[2*i+1]==1)
			{
				postOrder(2*i+1);
			}
			if(2*i+2<size && status[2*i+2]==1)
			{
				postOrder(2*i+2);
			}
			cout<<data[i]<<" ";
		}
		void postOrder()
		{
			if(status[0]==1)
			{
				postOrder(0);
			}
		}
		void inOrder(int i)
		{
			if(2*i+1<size && status[2*i+1]==1)
			{
				inOrder(2*i+1);
			}
			cout<<data[i]<<" ";
			if(2*i+2<size && status[2*i+2]==1)
			{
				inOrder(2*i+2);
			}
		}
		void inOrder()
		{
			if(status[0]==1)
			{
				inOrder(0);
			}
		}
		int HeightOfTree(int i)
		{
		    if(i >= size || status[i] == 0)
		        return 0;
		
		    int l = HeightOfTree(2*i+1);
		    int r = HeightOfTree(2*i+2);
		
		    if(l > r)
		        return l+1;
		    else
		        return r+1;
		}
		
		int HeightOfTree()
		{
		    return HeightOfTree(0);
		}
		void levelOrderPrint()
		{
		    for(int i=0; i<size; i++)
		    {
		        if(status[i] == 1)
		        {
		            cout << data[i] << " ";
		        }
		    }
		}
		void displayLevel(int levelNo)
		{
		    displayLevel(0, 0, levelNo, 0);
		}
		
		void displayLevel(int start, int level, int target, int index)
		{
		    if(index >= size || status[index] == 0)
		        return;
		
		    if(level == target)
		    {
		        cout << data[index] << " ";
		        return;
		    }
		
		    displayLevel(start, level+1, target, 2*index+1);
		    displayLevel(start, level+1, target, 2*index+2);
		}
		int findLevelOfNode(T node)
		{
		    for(int i = 0; i < size; i++)
		    {
		        if(status[i] == 1 && data[i] == node)
		        {
		            int level = 0;
		
		            while(i > 0)
		            {
		                i = (i - 1) / 2;
		                level++;
		            }
		
		            return level;
		        }
		    }
		
		    return -1;
		}
		void displayParenthesizedView(int ind)
		{
			if(ind>=size || status[ind]==0)
			{
				return;
			}
			int left = ind*2+1;
			int right = ind*2+2;
			bool hasleft = (left<size && status[left]==1);
			bool hasright = (right<size && status[right]==1);
			if(hasleft || hasright)
			{
				cout<<data[ind]<<" ";
			}
			if(hasleft)
			{
				cout<<"(";
				cout<<data[left];
				if(hasleft && !hasright)
				{
					cout<<",)";
				}
				else
					cout<<")";
			}
			displayParenthesizedView(left);
			if (hasright)
			{
				if(hasright && !hasleft)
				{
					cout<<"(,";
				}
				else
				{
					cout<<"(";
				}
				cout<<data[right];
				cout<<")";
			}
			displayParenthesizedView(right);
		}
		void displayParenthesizedView()
		{
			displayParenthesizedView(0);
		}
		void removeNode(int i)
		{
		    if(i >= size || status[i] == 0)
		        return;
		
		    removeNode(2*i+1);
		    removeNode(2*i+2);
		
		    status[i] = 0;
		}
		
		void remove(T n)
		{
		    for(int i=0; i<size; i++)
		    {
		        if(status[i] == 1 && data[i] == n)
		        {
		            removeNode(i);
		            return;
		        }
		    }
		}
		bool isEmpty()
		{
			return status[0]==0;
		}
		T getLeftChild(T parent)
		{
		    for(int i = 0; i < size; i++)
		    {
		        if(status[i] == 1 && data[i] == parent)
		        {
		            int left = 2*i+1;
		
		            if(left < size && status[left] == 1)
		                return data[left];
		
		            return -1;
		        }
		    }
		
		    return T();
		}
		
		T getRightChild(T parent)
		{
		    for(int i = 0; i < size; i++)
		    {
		        if(status[i] == 1 && data[i] == parent)
		        {
		            int right = 2*i+2;
		
		            if(right < size && status[right] == 1)
		                return data[right];
		
		            return T();
		        }
		    }
		
		    return T();
		}
		bool isLeaf(T node)
		{
		    for(int i = 0; i < size; i++)
		    {
		        if(status[i] == 1 && data[i] == node)
		        {
		            int left = 2*i+1;
		            int right = 2*i+2;
		
		            bool hasleft = (left < size && status[left] == 1);
		            bool hasright = (right < size && status[right] == 1);
		
		            return !hasleft && !hasright;
		        }
		    }
		
		    return false;
		}
		T getSibling(T node)
		{
		    for(int i = 1; i < size; i++)
		    {
		        if(status[i] == 1 && data[i] == node)
		        {
		            int parent = (i-1)/2;
		
		            int left = 2*parent+1;
		            int right = 2*parent+2;
		
		            if(i == left && right < size && status[right] == 1)
		                return data[right];
		
		            if(i == right && status[left] == 1)
		                return data[left];
		
		            return T();
		        }
		    }
		
		    return T();
		}
		void updateNode(T oldVal, T newVal)
		{
		    for(int i = 0; i < size; i++)
		    {
		        if(status[i] == 1 && data[i] == oldVal)
		        {
		            data[i] = newVal;
		            return;
		        }
		    }
		}
		~BinaryTreeArr()
		{
	    delete[] data;
	    delete[] status;
		}
		int countNodes()
		{
			int count=0;
			for(int i=0; i<size; i++)
			{
				if(status[i]==1)
				{
					count++;
				}
			}
			return count;
		}
		int countLeaves(int i)
		{
		    if(i >= size || status[i] == 0)
		        return 0;
		
		    int left = 2*i+1;
		    int right = 2*i+2;
		
		    bool hasleft = (left < size && status[left] == 1);
		    bool hasright = (right < size && status[right] == 1);
		
		    if(!hasleft && !hasright)
		        return 1;
		
		    return countLeaves(left) + countLeaves(right);
		}
		
		int countLeaves()
		{
		    return countLeaves(0);
		}
		int countInternalNodes(int i)
		{
		    if(i >= size || status[i] == 0)
		        return 0;
		
		    int left = 2*i+1;
		    int right = 2*i+2;
		
		    bool hasleft = (left < size && status[left] == 1);
		    bool hasright = (right < size && status[right] == 1);
		
		    int count = 0;
		
		    if(hasleft || hasright)
		        count = 1;
		
		    return count + countInternalNodes(left)
		                 + countInternalNodes(right);
		}
		
		int countInternalNodes()
		{
		    return countInternalNodes(0);
		}
		int countNodesWithOneChild(int i)
		{
		    if(i >= size || status[i] == 0)
		        return 0;
		
		    int left = 2*i+1;
		    int right = 2*i+2;
		
		    bool hasleft = (left < size && status[left] == 1);
		    bool hasright = (right < size && status[right] == 1);
		
		    int count = 0;
		
		    if(hasleft != hasright)
		        count = 1;
		
		    return count + countNodesWithOneChild(left)
		                 + countNodesWithOneChild(right);
		}
		
		int countNodesWithOneChild()
		{
		    return countNodesWithOneChild(0);
		}
		void displayLeaves(int i)
		{
		    if(i >= size || status[i] == 0)
		        return;
		
		    int left = 2*i+1;
		    int right = 2*i+2;
		
		    bool hasleft = (left < size && status[left] == 1);
		    bool hasright = (right < size && status[right] == 1);
		
		    if(!hasleft && !hasright)
		    {
		        cout << data[i] << " ";
		        return;
		    }
		
		    displayLeaves(left);
		    displayLeaves(right);
		}
		
		void displayLeaves()
		{
		    displayLeaves(0);
		}
		void reverseLevelOrder()
		{
		    int h = HeightOfTree();
		
		    for(int level = h-1; level >= 0; level--)
		    {
		        displayLevel(level);
		    }
		}
		void spiralOrder()
		{
		    int h = HeightOfTree();
		
		    for(int level = 0; level < h; level++)
		    {
		        displaySpiralLevel(0, 0, level, level % 2 == 0);
		    }
		}
		
		void displaySpiralLevel(int index, int level,
		                        int target, bool leftToRight)
		{
		    if(index >= size || status[index] == 0)
		        return;
		
		    if(level == target)
		    {
		        cout << data[index] << " ";
		        return;
		    }
		
		    if(leftToRight)
		    {
		        displaySpiralLevel(2*index+1, level+1,
		                           target, leftToRight);
		
		        displaySpiralLevel(2*index+2, level+1,
		                           target, leftToRight);
		    }
		    else
		    {
		        displaySpiralLevel(2*index+2, level+1,
		                           target, leftToRight);
		
		        displaySpiralLevel(2*index+1, level+1,
		                           target, leftToRight);
		    }
		}
		void displayPath(T node)
		{
		    int ind = -1;
		
		    for(int i = 0; i < size; i++)
		    {
		        if(status[i] == 1 && data[i] == node)
		        {
		            ind = i;
		            break;
		        }
		    }
		
		    if(ind == -1)
		        return;
		
		    int* arr = new int [size];
		    int count = 0;
		
		    while(ind >= 0)
		    {
		        arr[count] = ind;
		        count++;
		
		        if(ind == 0)
		            break;
		
		        ind = (ind-1)/2;
		    }
		
		    for(int i = count-1; i >= 0; i--)
		    {
		        cout << data[arr[i]] << " ";
		    }
		    delete[]arr;
		}
		
};
#endif