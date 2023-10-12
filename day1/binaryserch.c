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
//    printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
//    printf("| i   : 노드 추가       |\n");
//    printf("| d   : 노드 삭제       |\n");
//    printf("| P   : 레벨별 출력     |\n");
//    printf("| c   : 종료            |\n");
//    printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n\n");
//    printf("메뉴 입력: ");
//    char menu;
//    scanf_s("%c", &menu);
//    element snum;
//    switch (menu)
//    {
//    case 's':
//        printf("검색할 값 입력: ");
//        scanf_s("%d", &snum);
//        insert_max_heap(heap, &snum);
//        break;
//    case 'd':
//        break;
//    case 'P':
//        break;
//    case 'c':
//    default:
//        printf("옳바른 메뉴를 입력해주세요!");
//        break;
//    }
//    return 0;
//}