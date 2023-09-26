#include<stdio.h>
#include<stdlib.h>

int ArrayTree[16] = { 0,1,2,7,3,6,8,9,4,5,0,0,0,0,10,11 };

void Array_preorder(int i) {
	if (i && ArrayTree[i] != 0) {
		printf("%d ", ArrayTree[i]);
		Array_preorder(2 * i);
		Array_preorder(2 * i + 1);
	}
}

void Array_inorder(int i) {
	if (i && ArrayTree[i] != 0) {
		Array_inorder(2 * i);
		printf("%d ", ArrayTree[i]);
		Array_inorder(2 * i + 1);
	}
}

void Array_postorder(int i) {
	if (i && ArrayTree[i] != 0) {
		Array_postorder(2 * i);
		Array_postorder(2 * i + 1);
		printf("%d ", ArrayTree[i]);
	}
}

typedef struct TreeNode{
	int key;
	struct TreeNode* left, * right;
}TreeNode;

TreeNode* search(TreeNode* node, int key)
{
	while (node != NULL) {
		if (key == node->key) return node;
		else if (key < node->key)
			node = node->left;
		else
			node = node->right;
	}
	return NULL; 	// Ž���� �������� ��� NULL ��ȯ
}


int main(void)
{

	printf("Traversal with Stack\n");
	printf("1. ���� ��ȸ\n");
	Array_preorder(1);
	printf("\n\n");

	printf("2. ���� ��ȸ\n");
	Array_inorder(1);
	printf("\n\n");

	printf("3. ���� ��ȸ\n");
	Array_postorder(1);
	printf("\n\n");

	return 0;
}
