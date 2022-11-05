#include<stdio.h>
#include<stdlib.h>

typedef int ElementType;


struct SingleNode{
    ElementType data;
    struct SingleNode *next;
    };

typedef struct SingleNode *Set;


void initSet(Set S,int ms)
{
    S->next=NULL;
}

int insertSet(Set S,ElementType item)
{

    struct SingleNode *p;
    struct SingleNode *tp=malloc(sizeof(struct SingleNode));
    if(!tp)
    {

        printf("动态空间用完！\n");
        return 0;
    }
    tp->data=item;
    p=S->next;
    while(p!=NULL)
    {
        if(p->data==item)
        {
            return 0;
        }else
        {
        p=p->next;
        }
    }
    tp->next=S->next;
    S->next=tp;
    return 1;
}

void showSet(Set S)
{
    struct SingleNode *p=S->next;
    while(p){
        printf("%d\t",p->data);
        p=p->next;
    }
    printf("已经show\n");
}


int deleteSet(Set S,ElementType item)
{
    Set p=S;
    Set tp;
    while(p->next!=NULL)
    {
        if(p->next->data==item)
        {
            tp=p->next;
            p->next=p->next->next;
            free(tp);
            return 1;
        }
        p=p->next;
    }
    return 0;

}


int findSet(Set S,ElementType item)
{

    struct SingleNode *p=S->next;
    while(p)
    {
        if(p->data==item)
        {

            return 1;
        }
        p=p->next;
    }
    return 0;
}

int isEmpty(Set S)
{

    return S->next==NULL;
}

int lengthSet(Set S)
{

    struct SingleNode *p=S;
    int len=0;
    while(p->next!=NULL)
    {
        len++;
        p=p->next;

    }
    return len;
}

Set UnionSet(Set S1,Set S2)
{
    Set S=malloc(sizeof(struct SingleNode));
    initSet(S,1);
    struct SingleNode* ps1=S1->next,*ps2=S2->next;

    while(ps1){
        insertSet(S,ps1->data);
        ps1=ps1->next;
    }
    while(ps2){
        insertSet(S,ps2->data);
        ps2=ps2->next;
    }
    return S;

}
Set interseSet(Set S1,Set S2)
{
    Set S=malloc(sizeof (struct SingleNode));
    initSet(S,1);
    struct SingleNode *ps1=S1->next,*ps2=S2->next;
    while(ps1){
        if(findSet(S2,ps1->data)){
            insertSet(S,ps1->data);
        }
        ps1=ps1->next;
    }
    return S;
}

Set differenceSet(Set S1,Set S2)
{
    Set S=malloc(sizeof(struct SingleNode));
    initSet(S,1);
    struct SingleNode *ps1=S1->next;
    while(ps1)
    {
        if(!findSet(S2,ps1->data)){
            insertSet(S,ps1->data);
        }
        ps1=ps1->next;
    }

    return S;
}

void clearSet(Set S){
    Set p=S;
    while(p->next!=NULL){
        Set tp=p->next;
        p->next=p->next->next;
        free(tp);
    }

}
int main()
{
    struct SingleNode s1,*ps1=&s1,s2,*ps2=&s2;
    struct SingleNode *s,*ss,*sss;
    initSet(ps1,1);
    initSet(ps2,1);
    insertSet(ps2,3);
    insertSet(ps2,56);
    insertSet(ps2,5);
    insertSet(ps2,90);
    insertSet(ps2,7);

    printf("insert data %d\n",insertSet(ps1,3));
    printf("insert data %d\n",insertSet(ps1,4));
    printf("insert data %d\n",insertSet(ps1,5));
    printf("insert data %d\n",insertSet(ps1,2));
    printf("insert data %d\n",insertSet(ps1,3));
    showSet(ps1);
    showSet(ps2);

//    printf("delete data %d\n", deleteSet(ps1,4));
//    printf("delete data %d\n", deleteSet(ps1,33));
//    showSet(ps1);
//
//    printf("find set    %d\n",findSet(ps1,4));
//    printf("find set    %d\n",findSet(ps1,5));
//
//    printf("is empty    %d\n",isEmpty(ps1));
//
//    printf("Set Length  %d\n",lengthSet(ps1));


//并集
    s=UnionSet(ps1,ps2);
    showSet(s);
//交集
    ss=interseSet(ps1,ps2);
    showSet(ss);

//差集
    sss=differenceSet(ps1,ps2);
    showSet(sss);


//清除

    clearSet(ps1);
    showSet(ps1);






    return 0;
}
