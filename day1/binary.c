//2+3+4*5-6/7+9
#include <stdio.h>
//#include<math.h>

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
}TreeNode;

TreeNode n1 = { 4,NULL,NULL };
TreeNode n2 = { 5,NULL,NULL };
TreeNode n3 = { '*',&n1,&n2 };
TreeNode n4 = { 3,NULL,NULL };
TreeNode n5 = { '+',&n4,&n3 };
TreeNode n6 = { 2,NULL,NULL };
TreeNode n7 = { '+',&n6,&n5 };
TreeNode n8 = { 6,NULL,NULL };
TreeNode n9 = { 7,NULL,NULL };
TreeNode n10 = { '/',&n8,&n9 };
TreeNode n11 = { '-',&n7,&n10 };
TreeNode n12 = { 9,NULL,NULL };
TreeNode n13 = { '+',&n11,&n12 };
TreeNode* tex = &n13;

double evaluate(TreeNode* root)
{
	if (root == NULL)
		return 0;
	if (root->left == NULL && root->right == NULL)
		return root->data;
	else {
		double op1 = evaluate(root->left);
		double op2 = evaluate(root->right);
		double rel;
		switch (root->data) {
		case '+':
			rel = op1 + op2;
			break;
		case '-':
			rel = op1 - op2;
			break;
		case '*':
			rel = op1 * op2;
			break;
		case '/':
			rel = op1 / op2;
			break;
		}
		printf("%.2lf %c %.2lf = %.2lf\n", op1, root->data, op2, rel);
		return rel;
	}
	return 0;
}

int total_count(TreeNode* node)
{
	int count = 0;
	if (node != NULL)
		count = 1 + total_count(node->left) +
		total_count(node->right);
	return count;
}


int main(void)
{
	printf("수식의 값은 %.2lf입니다.\n\n", evaluate(tex));
	printf("총 노드의 수는 %d개 입니다.\n", total_count(tex));

	return 0;
}