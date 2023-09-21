#include<stdio.h>
#define TRUE 1
#define FALSE 0

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
	int is_thread; // 스레드이면 1, 스레드가 아니면 0
}TreeNode;

TreeNode n1 = { 4, NULL, NULL, 0 };
TreeNode n2 = { 5, NULL, NULL ,0 };
TreeNode n3 = { 3, &n1, &n2 ,0 };
TreeNode n4 = { 6, NULL, NULL,0 };
TreeNode n5 = { 2,&n3, &n4 ,0 };
TreeNode n6 = { 8, NULL, NULL,0 };
TreeNode n7 = { 10, NULL, NULL,0 };
TreeNode n8 = { 11, NULL, NULL ,0 };
TreeNode n9 = { 9, &n7, &n8 ,0 };
TreeNode n10 = { 7, &n6, &n9 ,0 };
TreeNode n11 = { 1, &n5, &n10 ,0 };
TreeNode* root = &n11;

TreeNode* find_successor(TreeNode* p)
{
	TreeNode* q = p->right;
	if (q == NULL || p->is_thread == TRUE)
		return q;
	while (q->left != NULL)
		q = q->left;
	return q;
}

void thread_inorder(TreeNode* t)
{
	TreeNode* q;
	q = t;
	while (q->left)
		q = q->left;
	do {
		printf("%d ", q->data);
		q = find_successor(q);
	} while (q);
}

TreeNode* parent(TreeNode* child)
{
	TreeNode* q;
	q = child;
	while (q->left)
		q = q->left;
	if (q->right->left == q) {
		q = q->right;
		printf("%d\n", q->data);
	}
	else {
		q = q->right->left;
		printf("%d\n", q->data);
	}
}

int main(void)
{
	n1.right = &n3;
	n1.is_thread = 1;
	n2.right = &n5;
	n2.is_thread = 1;
	n4.right = &n11;
	n4.is_thread = 1;
	n6.right = &n10;
	n6.is_thread = 1;
	n7.right = &n9;
	n7.is_thread = 1;

	printf("1.중위 순회 결과\n");
	thread_inorder(root);
	printf("\n\n");
	printf("2. Node 4의 부모: ");
	parent(&n1);
	printf("3. Node 5의 부모: ");
	parent(&n2);
	printf("4. Node 6의 부모: ");
	parent(&n4);

	return 0;
}
