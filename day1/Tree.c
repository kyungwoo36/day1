#include<stdio.h>
#include<stdlib.h>


typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
}TreeNode;

	TreeNode n1 = {4, NULL, NULL};
	TreeNode n2 = {5, NULL, NULL};
	TreeNode n3 = {3, &n1, &n2};
	TreeNode n4 = {6, NULL, NULL};
	TreeNode n5 = {2, &n3, &n4};

	TreeNode n6 = {8, NULL, NULL};
	TreeNode n7 = {10, NULL, NULL};
	TreeNode n8 = {11, NULL, NULL};
	TreeNode n9 = {9, &n7, &n8};
	TreeNode n10 = {7, &n6, &n9};
	TreeNode n11 = {1, &n5, &n10 };
	TreeNode* root = &n11;

void preorder(TreeNode* root) {
	if (root != NULL) {
		printf("%d ", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void inorder(TreeNode* root) {
	if (root != NULL) {
		inorder(root->left);
		printf("%d ", root->data);
		inorder(root->right);
	}
}

void postorder(TreeNode* root) {
	if (root != NULL) {
		postorder(root->left);
		postorder(root->right);
		printf("%d ", root->data);
	}
}

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

int main(void)
{
	printf("Linked Tree\n");
	printf("1. 전위 순회\n");
		preorder(root);
	printf("\n");

	printf("2. 중위 순회\n");
		inorder(root);
	printf("\n");

	printf("3. 후위 순회\n");
		postorder(root);
	printf("\n\n");

	printf("Array Tree\n");
	printf("1. 전위 순회\n");
	Array_preorder(1);
	printf("\n");

	printf("2. 중위 순회\n");
	Array_inorder(1);
	printf("\n");

	printf("3. 후위 순회\n");
	Array_postorder(1);
	printf("\n");

	return 0;
}