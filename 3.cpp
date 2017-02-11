#include <iostream>
#include <deque>
#include <climits>
#include <vector>
using namespace std;

struct Tree{
	char data;
	Tree *left;
	Tree *right;  
	Tree *parent;  
};

struct Tree *newTreeNode(int data){
	Tree *node = new Tree;
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	node->parent = NULL;

	return node;
}

struct Tree* insertTreeNode(struct Tree *node, int data){
	static Tree *p;
	Tree *retNode;

	//if(node != NULL) p = node;

	if(node == NULL)  {
	    retNode = newTreeNode(data);
	    retNode->parent = p;
	    return retNode;
	}
	if(data <= node->data ) { 
	    p = node;
	    node->left = insertTreeNode(node->left,data);
	} 
	else {
	    p = node;
	    node->right = insertTreeNode(node->right,data);
	} 
	return node;
}

void printTreeInOrder(struct Tree *node){
	
	if(node == NULL) return;

	printTreeInOrder(node->left);
	cout << node->data << " ";
	printTreeInOrder(node->right);
}

void printTreePostOrder(struct Tree *node){
	
	if(node == NULL) return;

	printTreePostOrder(node->left);
	printTreePostOrder(node->right);
	cout << node->data << " ";
}

/* Tree Minimum */
Tree* minTree(struct Tree *node){
	if(node == NULL) return NULL;
	while(node->left) 
	    node = node -> left;
	return node;
}

/* Tree Maximum */
Tree* maxTree(struct Tree *node){
	while(node->right) 
	    node = node -> right;
	return node;
}


/* In Order Successor - a node which has the next higher key */ 
Tree *succesorInOrder(struct Tree *node){
	/* if the node has right child, seccessor is Tree-Minimum */
	if(node->right != NULL) return minTree(node->right);

	Tree *y = node->parent;
	while(y != NULL && node == y->right) {
	    node = y;
	    y = y->parent;
	}
	return y;
}

/* In Order Predecessor - a node which has the next lower key */
Tree *predecessorInOrder(struct Tree *node){
	/* if the node has left child, predecessor is Tree-Maximum */
	if(node->left != NULL) return maxTree(node->left);

	Tree *y = node->parent;
	/* if it does not have a left child, 
	predecessor is its first left ancestor */
	while(y != NULL && node == y->left) {
	    node = y;
	    y = y->parent;
	}
	return y;
}

Tree* lookUp(struct Tree *node, char key){
	if(node == NULL) return node;

	if(node->data == key) return node;
	else {
	    if(node->data < key)
		return lookUp(node->right, key) ;
	    else
		return lookUp(node->left, key);
	}
}


int main(int argc, char **argv){
	
	char ch, ch1, ch2;
	Tree *found;
	Tree *succ;
	Tree *pred;
	Tree *ancestor;
	char charArr[9] 
	    = {'A','B','C','D','E','F','G','H','I'};

	Tree *root = newTreeNode('F');
	insertTreeNode(root,'B');
	insertTreeNode(root,'A');
	insertTreeNode(root,'D');
	insertTreeNode(root,'C');  
	insertTreeNode(root,'E');
	insertTreeNode(root,'G');
	insertTreeNode(root,'I');
	insertTreeNode(root,'H');

	cout << "Inorder" << endl << endl;

	ch = 'B';
	found = lookUp(root,ch);
	if(found) {
	    succ = succesorInOrder(found);
	    if(succ)
		cout << "In Order Successor of " << ch << " is "
		     << succesorInOrder(found)->data << endl;
	    else 
		cout << "In Order Successor of " << ch << " is None\n";
	}

	ch = 'E';
	found = lookUp(root,ch);
	if(found) {
	    succ = succesorInOrder(found);
	    if(succ)
		cout << "In Order Successor of " << ch << " is "
			 << succesorInOrder(found)->data << endl;
	    else 
		cout << "In Order Successor of " << ch << " is None\n";
	}

	ch = 'I';
	found = lookUp(root,ch);
	if(found) {
	    succ = succesorInOrder(found);
	    if(succ)
		cout << "In Order Successor of " << ch << " is "
			 << succesorInOrder(found)->data << endl;
	    else 
		cout << "In Order Successor of " << ch << " is None\n";
	}

	ch = 'B';
	found = lookUp(root,ch);
	if(found) {
	    pred = predecessorInOrder(found);
	    if(pred)
		cout << "In Order Predecessor of " << ch << " is "
			 << predecessorInOrder(found)->data << endl;
	    else 
		cout << "In Order Predecessor of " << ch << " is None\n";
	}

	ch = 'E';
	found = lookUp(root,ch);
	if(found) {
	    pred = predecessorInOrder(found);
	    if(pred)
		cout << "In Order Predecessor of " << ch << " is "
			 << predecessorInOrder(found)->data << endl;
	    else 
		cout << "In Order Predecessor of " << ch << " is None\n";
	}

	ch = 'I';
	found = lookUp(root,ch);
	if(found) {
	    pred = predecessorInOrder(found);
	    if(pred)
		cout << "In Order Predecessor of " << ch << " is "
			 << predecessorInOrder(found)->data << endl;
	    else 
		cout << "In Order Predecessor of " << ch << " is None\n";
	}
	

	/* print tree in postorder*/
	cout << endl << endl << "Postorder \n";
	printTreePostOrder(root);
	cout << endl;
}
