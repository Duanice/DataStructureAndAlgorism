#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef int Position;
struct SingleNode
{
    ElementType data;
    struct SingleNode *next;
};

typedef struct SingleNode * List;

void initList(List L,int ms)
{
    L->next=NULL;

}
int insertListByOrder(List L,ElementType item)
{

        struct SingleNode *p;
        struct SingleNode *tp=malloc(sizeof(struct SingleNode));
        initList(tp,1);
        if(!tp){
            printf("动态空间用完!");
            return 0;
        }
        tp->data=item;
        p=L;
        tp->next=p->next;
        p->next=tp;
        return 1;
}

int insertList(List L,ElementType item,int k)
{

    int i=0;
    struct SingleNode *plist=L;
    struct SingleNode *tp=malloc(sizeof(struct SingleNode));
    if(!tp){
        printf("内存分配失败\n!");
        return 0;
    }
    while(plist->next){
        if(i==k){
            break;
        }
        i++;
        plist=plist->next;
    }
    tp->data=item;
    tp->next=plist->next;
    plist->next=tp;
    return 1;
}

void showList(List L){
        List ps=L->next;
        while(ps){
            printf("%d\t",ps->data);
            ps=ps->next;
        }
        printf("已经show了\n");
return;
}
 ElementType getList(List L,Position pos){
        struct SingleNode *p=L->next;
        int i=0;
        while(p){
            if(i==pos-1){
                return p->data;
            }
            i++;
            p=p->next;
        }
        printf("%d th not found\n",pos);
        return 0;

 }


 Position FindList(List L,ElementType item)

 {

     struct SingleNode *p=L->next;
     int i=0;
     while(p)
     {
         i++;
         if(item==p->data){
            return i;
         }
         p=p->next;
     }
     printf("not found\n");
     return -1;
 }

 int modifyList(List L,ElementType item,ElementType newitem)
 {

     struct SingleNode *p=L->next;
     int flag=0;
     while(p)
     {
         if(item==p->data){
            p->data=newitem;
            flag=1;
         }
         p=p->next;
     }
     if(flag==0){
        printf("无可修改元素\n");
     }
     return flag;
 }

 ElementType deleteList(List L,ElementType item)
 {

     struct SingleNode *q,*p=L;

     while(p->next)
     {

         if(p->next->data==item)
         {
             q=p->next;
             p->next=p->next->next;
             free(q);
             return item;
         }
         p=p->next;
     }
     return 0;

 }



 int lengthList(List L)
 {
     int i=0;
     struct SingleNode *p=L->next;
     while(p)
     {

         i++;
         p=p->next;
     }
     return i;
 }

 List sortList(List L)
{

    List p=L->next,q;
    q=malloc(sizeof(struct SingleNode));
    initList(q,1);
    List tq;
    while(p)
    {
        struct SingleNode* r=malloc(sizeof(struct SingleNode));
        initList(r,1);
        if(!r)
        {

            printf("内存分配失败\n");
            return NULL;
        }
        r->data=p->data;

        tq=q;
        while(tq->next&&p->data>(tq->next->data)){
            tq=tq->next;
        }
        r->next=tq->next;
        tq->next=r;
        p=p->next;
    }
    return q;

}

void clearList(List L)
{

    struct SingleNode*p=L,*q;
    while(p->next)
    {
        q=p->next;
        p->next=p->next->next;
        free(q);

    }
}
int main()
{
    struct SingleNode list1,*plist1=&list1;

    //初始化
    initList(plist1,1);

    //插入元素
    for(int i=0;i<12;i++)
    {
        insertList(plist1,12-i,i);
    }
    showList(plist1);

    //得到第pos个元素的值
    printf("第5个元素是%d\n",getList(plist1,5));

    //得到值为item的位置
    printf("%d在第%d个\n",10,FindList(plist1,10));

    //修改值为item的节点值
    modifyList(plist1,6,7);
    showList(plist1);

    //删除某元素
    deleteList(plist1,2);
    showList(plist1);
    //线性表长度
    printf("线性表长%d\n",lengthList(plist1));

    //按照关键字排序
    List ss=sortList(plist1);
    showList(ss);

    //清空链表
    clearList(plist1);
    showList(plist1);

    return 0;
}
