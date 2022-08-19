/*** Program to implement all operations on a binary search tree. ***/
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct NODE
{
	int data;
	struct NODE *LEFT;
	struct NODE *RIGHT;
}NODE;

/// Function to check whether an element is present in BST or not ///
/*
    Input  : pointer to the tree / sub - tree.
    Input  : data element to be searched.
    Output : NULL pointer if not found otherwise address of the node containing the data.
*/
NODE* isPresent(NODE* treeToBeSearched, int dataToBeSearched)
{
    NODE *temp = treeToBeSearched;  // used for traversing the tree
    if(treeToBeSearched == NULL)
        return NULL;
    else if(dataToBeSearched == temp->data)
        return temp;
        else if(dataToBeSearched > temp->data)
            treeToBeSearched = isPresent(temp->RIGHT, dataToBeSearched);
            else
                treeToBeSearched = isPresent(temp->LEFT, dataToBeSearched);
}

/// Function to create a new node ///
NODE* newNode(int data)
{
	NODE *temp = (NODE*)malloc(sizeof(NODE));
	temp->data = data;
	temp->LEFT = temp->RIGHT = NULL;
	return temp;
}

/// Function to insert an element in a tree ///
NODE* insertElement(NODE *node, int val)
{
	/// if tree is empty ///
	if(node == NULL)
        return newNode(val);
    /// tree is non empty ///
    if(val < node->data)
        node->LEFT = insertElement(node->LEFT, val);
    else
        node->RIGHT = insertElement(node->RIGHT, val);

    return node;
}

void preorderTraversal(NODE *TREE)
{
	/// if the tree is non-empty ///
	if(TREE != NULL)
	{
		printf("%d\t", TREE->data);
		preorderTraversal(TREE->LEFT);
		preorderTraversal(TREE->RIGHT);
	}
}

void inorderTraversal(NODE *TREE)
{
	/// if the tree is non-empty ///
	if(TREE != NULL)
	{
		inorderTraversal(TREE->LEFT);
		printf("%d\t", TREE->data);
		inorderTraversal(TREE->RIGHT);
	}
}

void postorderTraversal(NODE *TREE)
{
	/// if the tree is non-empty ///
	if(TREE != NULL)
	{
		postorderTraversal(TREE->LEFT);
		postorderTraversal(TREE->RIGHT);
		printf("%d\t", TREE->data);
	}
}

/// Function to find the smallest element in a tree ///
NODE* findSmallestElement(NODE *TREE)
{
	if((TREE == NULL) || (TREE->LEFT == NULL))
		return TREE;
	else
		return findSmallestElement(TREE->LEFT);
}

/// Function to find the largest element in a tree ///
NODE* findLargestElement(NODE *TREE)
{
	if((TREE == NULL) || (TREE->RIGHT == NULL))
		return TREE;
	else
		return findLargestElement(TREE->RIGHT);
}

/// Function to delete an element from the tree ///
NODE* deleteElement(NODE *Tree, int val)
{
    // ptr is the pointer to the node to be deleted
    NODE *ptr = isPresent(Tree, val);

    // if element not found or tree is empty return tree as it is
    if(ptr == NULL)
    {
        printf("The tree is empty or element not found\n");
        return Tree;
    }
    // deletion if only root is present in the tree
    else if(ptr == Tree && ptr->RIGHT == NULL && ptr->LEFT == NULL)
        {
            free(ptr);
            Tree = NULL;
            return Tree;
        }
        // otherwise if element found than its address is in ptr named pointer
        else
        {
            // finding the parent node of the node to be deleted
            NODE *parentPtrOfDelNode = NULL;
            NODE *temp = Tree;
            while(temp != ptr)
            {
                parentPtrOfDelNode = temp;
                if(val > temp->data)
                    temp = temp->RIGHT;
                else
                    temp = temp->LEFT;
            }
            // no child of the node to be deleted is present
            if(ptr->RIGHT == NULL && ptr->LEFT == NULL)
            {
                if(val < parentPtrOfDelNode->data)
                    parentPtrOfDelNode->LEFT = NULL;
                else
                    parentPtrOfDelNode->RIGHT = NULL;
                free(ptr);
                return(Tree);
            }
            // only one child is present of the node to be deleted
            else if(ptr->RIGHT == NULL || ptr->LEFT == NULL)
                {
                    NODE *childPtrOfDelNode;
                    if(ptr->RIGHT == NULL)
                    {
                        childPtrOfDelNode = ptr->LEFT;
                        parentPtrOfDelNode->LEFT = childPtrOfDelNode;
                        free(ptr);
                    }
                    else
                    {
                        childPtrOfDelNode = ptr->RIGHT;
                        parentPtrOfDelNode->RIGHT = childPtrOfDelNode;
                        free(ptr);
                    }
                    return(Tree);
                }
                // both the children of the node to be deleted are present
                else
                {
                    // finding the inorder successor which is the smallest element in the right subtree of the node to be deleted
                    NODE* inorderSuc = findSmallestElement(ptr->RIGHT);
                    if(inorderSuc == ptr->RIGHT)
                    {
                        ptr->data = inorderSuc->data;
                        if((ptr->RIGHT)->RIGHT != NULL)
                        {
                            ptr->RIGHT = (ptr->RIGHT)->RIGHT;
                        }
                        else
                        {
                            ptr->RIGHT = NULL;
                        }
                        free(inorderSuc);
                        return Tree;
                    }
                    else
                    {
                        NODE* temp = ptr->RIGHT;
                        NODE* inorderSucParent = NULL;
                        while(temp != inorderSuc)
                        {
                            inorderSucParent = temp;
                            temp = temp->LEFT;
                        }
                        inorderSucParent->LEFT = NULL;
                        ptr->data = inorderSuc->data;
                        free(inorderSuc);
                        return(Tree);
                    }
                }
        }
        printf("The deleted data is %d.\n", val);
}

int main()
{
    NODE *TREE = NULL;
    char response;
    do
    {
        system("cls");
        int option;
        printf("Program to perform operations on a BST\n");
        printf("Press 1: To insert\nPress 2: To delete\nPress 3: InOrder traversal\nPress 4: PostOrder Traversal\nPress 5: PreOrder Traversal\n");
        scanf("%d", &option);
        switch(option)
        {
        case 1:
            {
                int val;
                printf("Enter the element to inserted:\n");
                scanf("%d", &val);
                TREE = insertElement(TREE, val);
                printf("Tree after insertion is:(inorder traversal)\n");
                inorderTraversal(TREE);
                break;
            }
        case 2:
            {
                int val;
                printf("Enter the element to deleted:\n");
                scanf("%d", &val);
                TREE = deleteElement(TREE, val);
                if(TREE == NULL)
                {
                    printf("Empty Tree.\n");
                }
                else
                {
                    printf("Tree after deletion is:(inorder traversal)\n");
                    inorderTraversal(TREE);
                }
                break;
            }
        case 3:
            {
                if(TREE == NULL)
                    printf("Empty Tree");
                else
                    inorderTraversal(TREE);
                break;
            }
        case 4:
            {
                if(TREE == NULL)
                    printf("Empty Tree");
                else
                    postorderTraversal(TREE);
                break;
            }
        case 5:
            {
                if(TREE == NULL)
                    printf("Empty Tree");
                else
                    preorderTraversal(TREE);
                break;
            }
        default:
            {
                printf("Invalid option\n");
                break;
            }
        }
        printf("\nDo you want to perform another operation? \nPress Y/y: for Yes \nPress N/n: for No\n");
        scanf("\n");
        scanf("%c", &response);
    }while(response == 'y' || response == 'Y');
    return 0;
}
