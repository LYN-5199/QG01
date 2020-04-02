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
    printf("*                                   ˫������ADT                                               *\n");
    printf("***********************************************************************************************\n");
    printf("*                                  1��ɾ������                                                *\n");
    printf("*                                  2������ǰ�ڵ�                                              *\n");
    printf("*                                  3�������ڵ�                                              *\n");
    printf("*                                  4��ɾ���ڵ�                                                *\n");
    printf("*                                  5����������                                                *\n");
    printf("*                                  0���˳�����                                                *\n");
    printf("***********************************************************************************************\n");
    char a;
    DuLNode *L,*head,*pre;
    printf("��ѡ���ܣ���������˳���\n");
    scanf("%c",&a);
    InitList_DuL(&L);

    if(a>='0'&&a<='5'){
        printf("���ʼ������,����0������\n");
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
            printf("�������˳���\n");
        else
        {
            if(a=='1')
            {
                DestroyList_DuL(&head);
                printf("������ɾ����\n");
            }

            if(a=='2')
            {
                int c;
                DuLNode *p,*q;
                p=head;
                q=(struct DuLNode*)malloc(sizeof(struct DuLNode));
                printf("��������λ�ã�\n");
                scanf("%d",&c);
                while(p->data!=c){
                    p=p->next;
                    if(p->data==0){
                        printf("δ�ҵ��ýڵ㣡\n");
                        break;}
                }
                if(p->data!=0){
                printf("�������ڵ��ֵ��\n");
                scanf("%d",&q->data);
                if(p==head)
                    head=q;
                InsertBeforeList_DuL(p, q);
                printf("����ɹ���\n");
                TraverseList_DuL(head,visit);}
            }

            if(a=='3')
            {
                int d;
                DuLNode *r,*s;
                r=head;
                s=(struct DuLNode*)malloc(sizeof(struct DuLNode));
                printf("��������λ�ã�\n");
                scanf("%d",&d);
                while(r->data!=d){
                    r=r->next;
                    if(r->data==0){
                        printf("δ�ҵ��ýڵ㣡\n");
                        break;}
                }
                if(r->data!=0){
                printf("�������ڵ��ֵ��\n");
                scanf("%d",&s->data);
                InsertAfterList_DuL(r, s);
                printf("����ɹ���\n");
                TraverseList_DuL(head,visit);}

            }

            if(a=='4')
            {
                int f;
                DuLNode *e,*t;
                t=head;
                e=(struct DuLNode*)malloc(sizeof(struct DuLNode));
                printf("Ҫɾ���Ľڵ����ĸ��ڵ�֮�󣿣�\n");
                scanf("%d",&f);
                while(t->data!=f){
                    t=t->next;
                    if(t->data==0){
                        printf("δ�ҵ��ýڵ㣡\n");
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
            printf("������󣬳������˳���\n");


}
