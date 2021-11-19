#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>


struct ListNode {
    int val;
    struct ListNode* next;
}; 

struct ListNode* fun(struct ListNode* pHead, int x)
{
    struct ListNode* lessHead, * lessTail, * greaterHead, * greaterTail;
    lessTail = lessHead = (struct ListNode*)malloc(sizeof(struct ListNode));
    greaterTail = greaterHead = (struct ListNode*)malloc(sizeof(struct ListNode));

    struct ListNode* cur = pHead;
    while (cur)
    {
        if (cur->val < x)
        {
            lessTail->next = cur;
            lessTail = cur;
        }
        else
        {
            greaterTail->next = cur;
            greaterTail = cur;
        }

        cur = cur->next;
    }

    struct ListNode* newhead = lessHead->next;
    lessTail->next = greaterHead->next;
    greaterTail->next = NULL;
    free(lessHead);
    free(greaterHead);

    return newhead;
}

void print(struct ListNode* p)
{
    struct ListNode* cur = p;
    while (cur)
    {
        printf("%d->", cur->val);
        cur = cur->next;
    }
    printf("NULL\n");
}

int main()
{
    struct ListNode p1 = { 7, NULL };
    struct ListNode p2 = { 9, NULL };
    struct ListNode p3 = { 3, NULL };//3 1 2 7 9 4 7
    struct ListNode p4 = { 4, NULL };
    struct ListNode p5 = { 1, NULL };
    struct ListNode p6 = { 2, NULL };
    struct ListNode p7 = { 7, NULL };
    p1.next = &p2;
    p2.next = &p3;
    p3.next = &p4;
    p4.next = &p5;
    p5.next = &p6;
    p6.next = &p7;
    struct ListNode* ret = fun(&p1, 4);
    print(ret);
}
