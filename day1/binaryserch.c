#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct TreeNode {
    element key;
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
    return NULL;
}

TreeNode* new_node(int item)
{
    TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

TreeNode* insert_node(TreeNode* node, int key)
{
    if (node == NULL) return new_node(key);
    if (key < node->key)
        node->left = insert_node(node->left, key);
    else if (key > node->key)
        node->right = insert_node(node->right, key);

    return node;
}

TreeNode* min_value_node(TreeNode* node)
{
    TreeNode* current = node;

    while (current->left != NULL)
        current = current->left;

    return current;
}

TreeNode* delete_node(TreeNode* root, int key)
{
    if (root == NULL) return root;

    if (key < root->key)
        root->left = delete_node(root->left, key);
    else if (key > root->key)
        root->right = delete_node(root->right, key);
    else {
        if (root->left == NULL) {
            TreeNode* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            TreeNode* temp = root->left;
            free(root);
            return temp;
        }

        TreeNode* temp = min_value_node(root->right);

        root->key = temp->key;
        root->right = delete_node(root->right, temp->key);
    }
    return root;
}

void inorder(TreeNode* root) {
    if (root) {
        inorder(root->left);
        printf("[%d] ", root->key);
        inorder(root->right);
    }
}

int main(void)
{
    printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤ�\n");
    printf("| s    : �˻�              |\n");
    printf("| i    : ��� �߰�         |\n");
    printf("| d    : ��� ����         |\n");
    printf("| t    : ���� ��ȸ         |\n");
    printf("| l    : ��� �߰�(�ݺ�)   |\n");
    printf("| D    : ��� ����(�ݺ�)   |\n");
    printf("| c    : ����              |\n");
    printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤ�\n\n");
    TreeNode* root = NULL;
    TreeNode* tmp = NULL;

    root = insert_node(root, 60);
    root = insert_node(root, 41);
    root = insert_node(root, 16);
    root = insert_node(root, 25);
    root = insert_node(root, 53);
    root = insert_node(root, 46);
    root = insert_node(root, 42);
    root = insert_node(root, 55);
    root = insert_node(root, 74);
    root = insert_node(root, 65);
    root = insert_node(root, 63);
    root = insert_node(root, 62);
    root = insert_node(root, 64);
    root = insert_node(root, 70);

    printf("���� Ž�� Ʈ�� ���� ��ȸ ���\n");
    inorder(root);
    printf("\n\n");
    printf("�޴� �Է�: ");
    char menu;
    scanf_s("%c", &menu);
    int snum=0;
    switch (menu)
    {
    case 's':
        printf("�˻��� �� �Է�: ");
        scanf_s("%d", snum);
        search(root, snum);
        break;
    case 'i':
        break;
    case 'd':
        break;
    case 't':
        break;
    case 'l':
        break;
    case 'D':
        break;
    case 'c':
    default:
        printf("�ǹٸ� �޴��� �Է����ּ���!");
        break;
    }
    return 0;
}