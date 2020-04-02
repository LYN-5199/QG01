#include <stdio.h>
#include <stdlib.h>
#include "../head/linkedList.h"

int main(){
    Status InitList(LinkedList *L);
    void DestroyList(LinkedList *L);
    Status InsertList(LNode *p, LNode *q);
    Status DeleteList(LNode *p, ElemType *e);
    void TraverseList(LinkedList L, void (*visit)(ElemType e));
    void visit(ElemType e);
    Status SearchList(LinkedList L, ElemType e);
    Status ReverseList(LinkedList *L);
    Status IsLoopList(LinkedList L);
    LNode* ReverseEvenList(LinkedList *L);
    LNode* FindMidNode(LinkedList *L);
    printf("***********************************************************************************************\n");
    printf("*                                    单链表ADT                                                *\n");
    printf("***********************************************************************************************\n");
    printf("*                                  1、删除链表                                                *\n");
    printf("*                                  2、插入节点                                                *\n");
    printf("*                                  3、删除节点                                                *\n");
    printf("*                                  4、寻找节点                                                *\n");
    printf("*                                  5、遍历链表                                                *\n");
    printf("*                                  6、单偶反转                                                *\n");
    printf("*                                  7、反转链表                                                *\n");
    printf("*                                  8、判断环形                                                *\n");
    printf("*                                  9、寻找中点                                                *\n");
    printf("*                                  0、退出程序                                                *\n");
    printf("***********************************************************************************************\n");
    printf("请选择功能，输入错误退出：\n");
    char a;
    scanf("%c",&a);
    struct LNode *head,*b;
    LinkedList L=NULL;
    InitList(&L);
    if(a>='0'&&a<='9'){
        printf("请初始化链表，按0结束：\n");
        scanf("%d",&L->data);
        head=L;
        while(L->data!=0){

            L->next=(struct LNode*)malloc(sizeof(struct LNode));
            L=L->next;
            scanf("%d",&L->data);

            }
        L=head;
        if(a=='0') printf("程序已退出！\n");

        if(a=='1')
            {DestroyList(&L);
            printf("链表已删除！\n");}

        if(a=='2')
            {
                int c;
                LNode *p,*q;
                p=head;
                q=(struct LNode*)malloc(sizeof(struct LNode));
                printf("输入插入的位置：\n");
                scanf("%d",&c);
                while(p->data!=c){
                    p=p->next;
                    if(p->data==0){
                        printf("未找到该节点！\n");
                        break;}
                }
                if(p->data!=0){
                printf("输入插入节点的值：\n");
                scanf("%d",&q->data);
                InsertList(p, q);
                printf("插入成功！\n");
                TraverseList(head, visit);}
                }

        if(a=='3'){
                int d;
                LNode *e,*t;
                t=head;
                e=(struct LNode*)malloc(sizeof(struct LNode));
                printf("输入要删除的节点：\n");
                scanf("%d",&d);
                while(t->data!=d){
                    t=t->next;
                    if(t->data==0){
                        printf("未找到该节点！\n");
                        break;}
                }
                DeleteList(t, e);
                TraverseList(head, visit);
        }
        if(a=='4'){
            int f;
            printf("输入寻找的节点：\n");
            scanf("%d",&f);
            if(SearchList(head, f))
                printf("已找到！\n");
            else
                printf("找不到！\n");
        }
        if(a=='5'){
            TraverseList(L, visit);
        }
        if(a=='6'){
            head=ReverseEvenList(&L);
            TraverseList(head, visit);
        }
        if(a=='7'){
            ReverseList(&L);
            TraverseList(L, visit);
        }
        if(a=='8'){
            if(IsLoopList(head))
                printf("没有成环！\n");
            else
                printf("成环！\n");
        }
        if(a=='9'){
            LNode *u;
            u=(struct LNode*)malloc(sizeof(struct LNode));
            u=FindMidNode(&L);
            printf("中点为：%d\n",u->data);
        }

    }
    else
        printf("输入错误，程序已退出！\n");
    system("pause");
}
