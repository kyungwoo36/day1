//#include <stdio.h>
//#include <stdlib.h>
//#define MAX_ELEMENT 200
//
//typedef int element;
//typedef struct {
//    element key;
//}Node;
//typedef struct {
//    element heap[MAX_ELEMENT];
//    int heap_size;
//}HeapType;
//
//HeapType* create()
//{
//    return (HeapType*)malloc(sizeof(HeapType));
//}
//
//void insert_max_heap(HeapType* h, Node* item)
//{
//    int i;
//    i = ++(h->heap_size);
//
//    while ((i != 1) && (item->key > h->heap[i / 2])) {
//        h->heap[i] = h->heap[1 / 2];
//        i /= 2;
//    }
//    h->heap[i] = item;
//}
//
//int main(void)
//{
//    HeapType* heap;
//    element heap[MAX_ELEMENT] = { 90, 89, 70, 36, 75, 63, 65, 21, 18, 15 };
//
//    printf("�ѤѤѤѤѤѤѤѤѤѤѤѤ�\n");
//    printf("| i   : ��� �߰�       |\n");
//    printf("| d   : ��� ����       |\n");
//    printf("| P   : ������ ���     |\n");
//    printf("| c   : ����            |\n");
//    printf("�ѤѤѤѤѤѤѤѤѤѤѤѤ�\n\n");
//    printf("�޴� �Է�: ");
//    char menu;
//    scanf_s("%c", &menu);
//    element snum;
//    switch (menu)
//    {
//    case 's':
//        printf("�˻��� �� �Է�: ");
//        scanf_s("%d", &snum);
//        insert_max_heap(heap, &snum);
//        break;
//    case 'd':
//        break;
//    case 'P':
//        break;
//    case 'c':
//    default:
//        printf("�ǹٸ� �޴��� �Է����ּ���!");
//        break;
//    }
//    return 0;
//}