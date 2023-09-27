#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode{
	int key;
	struct TreeNode* left, * right;
}TreeNode;

TreeNode n1 = { 25,NULL,NULL };
TreeNode n2 = { 16,NULL ,&n1 };
TreeNode n3 = { 42,NULL ,NULL };
TreeNode n4 = { 46,&n3,NULL };
TreeNode n5 = { 55,NULL ,NULL };
TreeNode n6 = { 53, &n4,&n5 };
TreeNode n7 = { 41,&n2, &n6 };

TreeNode n8 = { 62,NULL ,NULL };
TreeNode n9 = { 64,NULL ,NULL };
TreeNode n10 = { 63,&n8,&n9 };
TreeNode n11 = { 70,NULL ,NULL };
TreeNode n12 = { 65,&n10,&n11 };
TreeNode n13 = { 74,&n12,NULL };
TreeNode n14 = { 60,&n7,&n13 };
TreeNode* root = &n14;

TreeNode* search(TreeNode* node, int key)
{
	int i;
	while (node != NULL) {
		if (key == node->key) {
			i++;
			return node;
		}
		else if (key < node->key)
			node = node->left;
		else
			node = node->right;
	}
	return NULL; 	// 탐색에 실패했을 경우 NULL 반환
}


int main(void)
{
	//char input;
	//switch (input)
	//{
	//case 's':
	//case 'i':
	//case 'd':
	//case 't':
	//case 'I':
	//case 'D':
	//default:
	//	break;
	//}

	search(root, 25);

	return 0;
}
