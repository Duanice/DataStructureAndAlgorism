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
            printf("��̬�ռ�����!");
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
        printf("�ڴ����ʧ��\n!");
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
        printf("�Ѿ�show��\n");
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
        printf("�޿��޸�Ԫ��\n");
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

            printf("�ڴ����ʧ��\n");
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

    //��ʼ��
    initList(plist1,1);

    //����Ԫ��
    for(int i=0;i<12;i++)
    {
        insertList(plist1,12-i,i);
    }
    showList(plist1);

    //�õ���pos��Ԫ�ص�ֵ
    printf("��5��Ԫ����%d\n",getList(plist1,5));

    //�õ�ֵΪitem��λ��
    printf("%d�ڵ�%d��\n",10,FindList(plist1,10));

    //�޸�ֵΪitem�Ľڵ�ֵ
    modifyList(plist1,6,7);
    showList(plist1);

    //ɾ��ĳԪ��
    deleteList(plist1,2);
    showList(plist1);
    //���Ա���
    printf("���Ա�%d\n",lengthList(plist1));

    //���չؼ�������
    List ss=sortList(plist1);
    showList(ss);

    //�������
    clearList(plist1);
    showList(plist1);

    return 0;
}
