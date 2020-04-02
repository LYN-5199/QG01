#include "../head/linkedList.h"
#include <stdlib.h>
#include <stdio.h>

/**
 *  @name        : Status InitList(LinkList *L);
 *	@description : initialize an empty linked list with only the head node without value
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList(LinkedList *L) {
    *L=(LinkedList)malloc(sizeof(LinkedList));
    if(!(*L))
        return ERROR;
    (*L)->next=NULL;
    return SUCCESS;
}

/**
 *  @name        : void DestroyList(LinkedList *L)
 *	@description : destroy a linked list, free all the nodes
 *	@param		 : L(the head node)
 *	@return		 : None
 *  @notice      : None
 */
void DestroyList(LinkedList *L) {
    LinkedList t;
    while((*L)->data!=0){
        t=(*L)->next;
        free(*L);
        *L=t;
    }

}

/**
 *  @name        : Status InsertList(LNode *p, LNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : Status
 *  @notice      : None
 */
Status InsertList(LNode *p, LNode *q) {
    LNode *t;
    if(!p)
        return ERROR;
    t=p->next;
    p->next=q;
    q->next=t;
    return SUCCESS;
}
/**
 *  @name        : Status DeleteList(LNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : Status
 *  @notice      : None
 */
Status DeleteList(LNode *p, ElemType *e) {
    if(!p&&!p->next)
        return ERROR;
    LNode *q;
    q=p->next;
    *e=q->data;
    p->next=q->next;
    free(q);
    return SUCCESS;

}

/**
 *  @name        : void TraverseList(LinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : None
 *  @notice      : None
 */
void TraverseList(LinkedList L, void (*visit)(ElemType e)) {
    LNode *t;
    t=L;
    while(t->data!=0){
        visit(t->data);
        t=t->next;
    }
}
void visit(ElemType e){
    printf("%d  ",e);
}
/**
 *  @name        : Status SearchList(LinkedList L, ElemType e)
 *	@description : find the first node in the linked list according to e
 *	@param		 : L(the head node), e
 *	@return		 : Status
 *  @notice      : None
 */
Status SearchList(LinkedList L, ElemType e) {
    if(!L)
        return ERROR;
    LNode *t;
    t=L;
    while(t){
        if(t->data==e)
            {return SUCCESS;
            break;}
        else
            t=t->next;
    }
    if(!t)
        return ERROR;

}

/**
 *  @name        : Status ReverseList(LinkedList *L)
 *	@description : reverse the linked list
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status ReverseList(LinkedList *L) {
    if(!(*L)&&!(*L)->next)
        return ERROR;
    LNode *a,*b,*c;
    a=*L;
    b=NULL;
    c=a->next;
    while(a->data!=0)
         {a->next=b;
          b=a;
          a=c;
          c=a->next;}
    *L=b;
    return SUCCESS;
}

/**
 *  @name        : Status IsLoopList(LinkedList L)
 *	@description : judge whether the linked list is looped
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status IsLoopList(LinkedList L) {
    LNode *fast,*slow;
    fast=L;
    slow=L;
    while(fast&&fast->next){
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow)
            return SUCCESS;
    }
    return ERROR;
}

/**
 *  @name        : LNode* ReverseEvenList(LinkedList *L)
 *	@description : reverse the nodes which value is an even number in the linked list, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3
 *	@param		 : L(the head node)
 *	@return		 : LNode(the new head node)
 *  @notice      : choose to finish
 */
LNode* ReverseEvenList(LinkedList *L) {
    LNode *p,*q,*t;
    p=*L;
    *L=p->next;
    while(p->data!=0&&p->next->data!=0){
        q=p->next;
        t=p->next->next;
        if(q->next->data!=0&&q->next->next->data!=0){
            p->next=q->next->next;
        }
        else{
            p->next=q->next;
        }
        q->next=p;
        p=t;
    }
    return *L;
}

/**
 *  @name        : LNode* FindMidNode(LinkedList *L)
 *	@description : find the middle node in the linked list
 *	@param		 : L(the head node)
 *	@return		 : LNode
 *  @notice      : choose to finish
 */
LNode* FindMidNode(LinkedList *L) {
    LNode *fast,*slow;
    fast=*L;
    slow=*L;
    while(fast->next->data!=0&&fast->next->next->data!=0){
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}

