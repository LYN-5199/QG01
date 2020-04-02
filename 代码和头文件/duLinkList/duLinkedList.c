#include "../head/duLinkedList.h"
#include <stdlib.h>
#include <stdio.h>

/**
 *  @name        : Status InitList_DuL(DuLinkedList *L)
 *	@description : initialize an empty linked list with only the head node
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList_DuL(DuLinkedList *L) {
    *L=(DuLinkedList)malloc(sizeof(DuLinkedList));
    if(!(*L))
        return ERROR;
    (*L)->next=NULL;
    (*L)->prior=NULL;
    return SUCCESS;
}

/**
 *  @name        : void DestroyList_DuL(DuLinkedList *L)
 *	@description : destroy a linked list
 *	@param		 : L(the head node)
 *	@return		 : status
 *  @notice      : None
 */
void DestroyList_DuL(DuLinkedList *L) {
    DuLNode *t;
    if((*L)->data!=0){
        t=(*L)->next;
        free(*L);
        *L=t;
        if(t->data!=0)
            t->prior=NULL;
    }

}

/**
 *  @name        : Status InsertBeforeList_DuL(DuLNode *p, LNode *q)
 *	@description : insert node q before node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q) {
    if(!p)
        return ERROR;
    if(p->prior->data!=0){
    p->prior->next=q;
    q->prior=p->prior;}
    q->next=p;
    p->prior=q;
    return SUCCESS;

}

/**
 *  @name        : Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertAfterList_DuL(DuLNode *p, DuLNode *q) {
    if(!p)
        return ERROR;
    if(p->next->data!=0){
        p->next->prior=q;
        q->next=p->next;
    }
    q->prior=p;
    p->next=q;
    return SUCCESS;

}

/**
 *  @name        : Status DeleteList_DuL(DuLNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : status
 *  @notice      : None
 */
Status DeleteList_DuL(DuLNode *p, ElemType *e) {
    if(!p&&!p->next)
        return ERROR;
    DuLNode *t;
    t=p->next;
    *e=t->data;
    t->next->prior=p;
    p->next=t->next;
    return SUCCESS;

}

/**
 *  @name        : void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : Status
 *  @notice      : None
 */
void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e)) {
    DuLNode *t;
    t=L;
    while(t->data!=0){
        (*visit)(t->data);
        t=t->next;
    }

}

void visit(ElemType e){
    printf("%d  ",e);
}
