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
    printf("*                                    ������ADT                                                *\n");
    printf("***********************************************************************************************\n");
    printf("*                                  1��ɾ������                                                *\n");
    printf("*                                  2������ڵ�                                                *\n");
    printf("*                                  3��ɾ���ڵ�                                                *\n");
    printf("*                                  4��Ѱ�ҽڵ�                                                *\n");
    printf("*                                  5����������                                                *\n");
    printf("*                                  6����ż��ת                                                *\n");
    printf("*                                  7����ת����                                                *\n");
    printf("*                                  8���жϻ���                                                *\n");
    printf("*                                  9��Ѱ���е�                                                *\n");
    printf("*                                  0���˳�����                                                *\n");
    printf("***********************************************************************************************\n");
    printf("��ѡ���ܣ���������˳���\n");
    char a;
    scanf("%c",&a);
    struct LNode *head,*b;
    LinkedList L=NULL;
    InitList(&L);
    if(a>='0'&&a<='9'){
        printf("���ʼ��������0������\n");
        scanf("%d",&L->data);
        head=L;
        while(L->data!=0){

            L->next=(struct LNode*)malloc(sizeof(struct LNode));
            L=L->next;
            scanf("%d",&L->data);

            }
        L=head;
        if(a=='0') printf("�������˳���\n");

        if(a=='1')
            {DestroyList(&L);
            printf("������ɾ����\n");}

        if(a=='2')
            {
                int c;
                LNode *p,*q;
                p=head;
                q=(struct LNode*)malloc(sizeof(struct LNode));
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
                InsertList(p, q);
                printf("����ɹ���\n");
                TraverseList(head, visit);}
                }

        if(a=='3'){
                int d;
                LNode *e,*t;
                t=head;
                e=(struct LNode*)malloc(sizeof(struct LNode));
                printf("����Ҫɾ���Ľڵ㣺\n");
                scanf("%d",&d);
                while(t->data!=d){
                    t=t->next;
                    if(t->data==0){
                        printf("δ�ҵ��ýڵ㣡\n");
                        break;}
                }
                DeleteList(t, e);
                TraverseList(head, visit);
        }
        if(a=='4'){
            int f;
            printf("����Ѱ�ҵĽڵ㣺\n");
            scanf("%d",&f);
            if(SearchList(head, f))
                printf("���ҵ���\n");
            else
                printf("�Ҳ�����\n");
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
                printf("û�гɻ���\n");
            else
                printf("�ɻ���\n");
        }
        if(a=='9'){
            LNode *u;
            u=(struct LNode*)malloc(sizeof(struct LNode));
            u=FindMidNode(&L);
            printf("�е�Ϊ��%d\n",u->data);
        }

    }
    else
        printf("������󣬳������˳���\n");
    system("pause");
}
