#include "../head/duLinkedList.h"
#include <stdlib.h>
#include <stdio.h>

int main(){
    Status InitList_DuL(DuLinkedList *L);
    void DestroyList_DuL(DuLinkedList *L);
    Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q);
    Status InsertAfterList_DuL(DuLNode *p, DuLNode *q);
    Status DeleteList_DuL(DuLNode *p, ElemType *e);
    void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e));
    void visit(ElemType e);
    printf("***********************************************************************************************\n");
    printf("*                                   双向链表ADT                                               *\n");
    printf("***********************************************************************************************\n");
    printf("*                                  1、删除链表                                                *\n");
    printf("*                                  2、插入前节点                                              *\n");
    printf("*                                  3、插入后节点                                              *\n");
    printf("*                                  4、删除节点                                                *\n");
    printf("*                                  5、遍历链表                                                *\n");
    printf("*                                  0、退出程序                                                *\n");
    printf("***********************************************************************************************\n");
    char a;
    DuLNode *L,*head,*pre;
    printf("请选择功能，输入错误退出：\n");
    scanf("%c",&a);
    InitList_DuL(&L);

    if(a>='0'&&a<='5'){
        printf("请初始化链表,输入0结束：\n");
        scanf("%d",&L->data);
        head=L;
        pre=head;
        while(L->data!=0){

            L->next=(struct DuLNode*)malloc(sizeof(struct DuLNode));
            L=L->next;
            scanf("%d",&L->data);
            L->prior=pre;
            pre=pre->next;
            }
        L->next=head;
        head->prior=L;
        if(a=='0')
            printf("程序已退出！\n");
        else
        {
            if(a=='1')
            {
                DestroyList_DuL(&head);
                printf("链表已删除！\n");
            }

            if(a=='2')
            {
                int c;
                DuLNode *p,*q;
                p=head;
                q=(struct DuLNode*)malloc(sizeof(struct DuLNode));
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
                if(p==head)
                    head=q;
                InsertBeforeList_DuL(p, q);
                printf("插入成功！\n");
                TraverseList_DuL(head,visit);}
            }

            if(a=='3')
            {
                int d;
                DuLNode *r,*s;
                r=head;
                s=(struct DuLNode*)malloc(sizeof(struct DuLNode));
                printf("输入插入的位置：\n");
                scanf("%d",&d);
                while(r->data!=d){
                    r=r->next;
                    if(r->data==0){
                        printf("未找到该节点！\n");
                        break;}
                }
                if(r->data!=0){
                printf("输入插入节点的值：\n");
                scanf("%d",&s->data);
                InsertAfterList_DuL(r, s);
                printf("插入成功！\n");
                TraverseList_DuL(head,visit);}

            }

            if(a=='4')
            {
                int f;
                DuLNode *e,*t;
                t=head;
                e=(struct DuLNode*)malloc(sizeof(struct DuLNode));
                printf("要删除的节点在哪个节点之后？：\n");
                scanf("%d",&f);
                while(t->data!=f){
                    t=t->next;
                    if(t->data==0){
                        printf("未找到该节点！\n");
                        break;}
                }
                DeleteList_DuL(t, e);
                TraverseList_DuL(head,visit);

            }

            if(a=='5')
            {
                TraverseList_DuL(head
                                 ,visit);

            }
        }
    }else
            printf("输入错误，程序已退出！\n");


}
