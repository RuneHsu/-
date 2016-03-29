// Convert a sub binary search tree to a sorted double linked list
// Source: http://zhedahht.blog.163.com/blog/static/254111742007127104759245/
// Date: 2016-03-28
/***************************************************************************
 * 我们可以中序遍历整棵树。按照这个方式遍历树，比较小的结点先访问。
 * 如果我们每访问一个结点，假设之前访问过的结点已经调整成一个排序双向链表，
 * 我们再把调整当前结点的指针将其链接到链表的末尾。当所有结点都访问过之后，
 * 整棵树也就转换成一个排序双向链表了。
 **************************************************************************/
// Covert a sub binary-search-tree into a sorted double-linked list  
// Input: pNode -           the head of the sub tree  
//        pLastNodeInList - the tail of the double-linked list 

struct BSTreeNode // a node in the binary search tree
    {
        int          m_nValue; // value of node
        BSTreeNode  *m_pLeft;  // left child of node
        BSTreeNode  *m_pRight; // right child of node
    };
    
void ConvertNode(BSTreeNode* pNode, BSTreeNode*& pLastNodeInList)  
{  
      if(pNode == NULL)  
            return;  
                                                  
      BSTreeNode *pCurrent = pNode;  
                                                  
      // Convert the left sub-tree  
      if (pCurrent->m_pLeft != NULL)  
            ConvertNode(pCurrent->m_pLeft, pLastNodeInList);    // Find the least node in the left sub-tree
                                                  
      // Put the current node into the double-linked list  
      pCurrent->m_pLeft = pLastNodeInList;                      // put the current least node into the list
      if(pLastNodeInList != NULL)                               // and put the parent of the least node into list
            pLastNodeInList->m_pRight = pCurrent;  
                                                  
      pLastNodeInList = pCurrent;                               // put the pointer to the last position of the list
                                                  
      // Convert the right sub-tree  
      if (pCurrent->m_pRight != NULL)  
            ConvertNode(pCurrent->m_pRight, pLastNodeInList);  
}  
                                                  
// Covert a binary search tree into a sorted double-linked list  
// Input: pHeadOfTree - the head of tree  
// Output: the head of sorted double-linked list  
BSTreeNode* Convert_Solution1(BSTreeNode* pHeadOfTree)  
{  
      BSTreeNode *pLastNodeInList = NULL;  
      ConvertNode(pHeadOfTree, pLastNodeInList);  
                                                  
      // Get the head of the double-linked list  
      BSTreeNode *pHeadOfList = pLastNodeInList;  
      while(pHeadOfList && pHeadOfList->m_pLeft)        
            pHeadOfList = pHeadOfList->m_pLeft;  
                                                  
      return pHeadOfList;  
}  
