#include<bits/stdc++.h>
using namespace std;

 
struct node
{
    int low,high,maxi;
    struct node *left, *right;
};
 
struct node *newNode(int low, int high)
{
    struct node *temp =  (struct node *)malloc(sizeof(struct node));
    temp->low = low;
    temp->high = high;
    temp->maxi=high;
    temp->left = temp->right = NULL;
    return temp;
}

void inorderTraversal(struct node *root)
{
    if (root != NULL)
    {
        inorderTraversal(root->left);
        cout<<root->low<<":"<<root->high<<":"<<root->maxi<<" ";
        inorderTraversal(root->right);
    }
}

struct node* minValueNode(struct node* node)
{
    struct node* current = node;
 
    while (current->left != NULL)
        current = current->left;
 
    return current;
}
 
//a) insert function
struct node* insert(struct node* node, int low, int high)
{
    if (node == NULL) return newNode(low,high);
    if (low < node->low)
        node->left  = insert(node->left, low, high);
    else
        node->right = insert(node->right,low, high);
	node->maxi=max(node->high, max((node->left==NULL)?0:node->left->maxi, (node->right==NULL)?0:node->right->maxi));
    return node;
}
 
//b) delete function
struct node* deleteNode(struct node* node, int low, int high)
{
    if (node == NULL) return node;
 
    //Key is smaller, go to left subtree
    if (low < node->low)
        node->left = deleteNode(node->left, low, high);
 
    //Key is larger, go to Right subtree
    else if (low > node->low)
        node->right = deleteNode(node->right,low,high);
 
    //Key is equal, delete root
    else if(low==node->low&&high=node->high)
    {
        if (node->left == NULL)
        {
            struct node *temp = node->right;
            free(node);
            return temp;
        }
        else if (node->right == NULL)
        {
            struct node *temp = node->left;
            free(node);
            return temp;
        }
 
        //Delete Inorder Successor
        struct node* temp = minValueNode(node->right);
        node->low = temp->low;
        node->high=temp->high;
        node->maxi=temp->maxi;
        node->right = deleteNode(node->right, temp->low,temp->high);
    }
    node->maxi=max(node->high,max((node->left==NULL)?0:node->left->maxi,
			   					  (node->right==NULL)?0:node->right->maxi));
    return node;
}


bool overlap(int low1, int high1, int low2, int high2)
{
    if (low1 <= high2 && low2 <= high1)
        return true;
    return false;
}
 
//c) search function
void search(struct node* node, int low, int high)
{
    if (node == NULL) return;

    if (overlap(node->low,node->high,low,high)){
    	cout<<node->low<<":"<<node->high<<endl;
    	return;
	}
        
    if (node->left != NULL && node->left->maxi >= low)
        search(node->left,low,high);
    search(node->right,low,high);
}

int main()
{
	int ch,low,high;
	struct node *root = NULL;
	while(true){
		cin>>ch>>low>>high;
		switch(ch){
			case 1:
				root = insert(root, low, high);
				inorderTraversal(root); //print inorder traversal
				break;
			case 2:
				root = deleteNode(root, low, high);
				inorderTraversal(root);
				break;
			case 3:
				search(root, low, high);
				break;
		}
	}
	return 0;
}

