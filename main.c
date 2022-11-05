#include <stdio.h>
#include <stdlib.h>
typedef int ElementType;
int len;

struct SequSet{
ElementType *set;
int len;//集合当前长度
int MaxSize;//set数组长度
};

typedef struct SequSet *Set;

void initSet(Set S,int ms)
{

    if(ms<10) S->MaxSize=10;
    else S->MaxSize=ms;
    S->set=calloc(S->MaxSize,sizeof(ElementType));
    if(!S->set){
        printf("动态空间分配不足！\n");
        exit(1);
    }
    else{
        printf("分配成功！\n");
    }
    S->len=0;
}

int  insertSet(Set S,ElementType item)
{

    int i;
    for(i=0;i<S->len;i++)
    {

        if(S->set[i]==item)
        {
            return 0;
        }
    }
    if(S->len==S->MaxSize-1)
    {

        S->set=realloc(S->set,2*sizeof(ElementType)*S->MaxSize);
        if(!S->set)
        {

            printf("内存分配不足");
            return 0;
        }
        S->MaxSize=2*S->MaxSize;
    }
    S->set[S->len]=item;
    S->len++;
    return 1;
}

void showSet(Set S)
{

    for(int i=0;i<S->len;i++)
    {

        printf("%d\t",S->set[i]);
    }
    printf("\n");
}


//删除元素 （我
void deleteSet1(Set S,ElementType item)
{

    for(int i=0;i<S->len-1;i++)
    {

        if(item==S->set[i])
        {

            for(int j=i+1;j<S->len;j++)
            {

                S->set[j-1]=S->set[j];
            }
            S->len--;
            break;
        }
    }
    if(S->set[S->len-1]==item)
    {
        S->len--;
    }
}

//删除元素 （书

int deleteSet(Set S,ElementType item)
{
    int i;
    for(i=0;i<S->len;i++)
    {

        if(S->set[i]==item)break;
    }
    if(i<S->len){
        S->set[i]=S->set[S->len-1];
        S->len--;
        if(S->MaxSize>10&&S->len<S->MaxSize*3.5/10){
            S->set=realloc(S->set,sizeof(ElementType)*(S->MaxSize/2));
            S->MaxSize=S->MaxSize/2;
        }
        return 1;
    }
    else {
            printf("元素不存在!\n");
        return 0;
    }

}

int findSet(Set S,ElementType *item,ElementType *index)
{
    int i=0;
    S->set[S->len]=*item;
    while(S->set[i]!=*item)i++;
    if(S->len>i){
        *item=S->set[i];
        *index=i;
        return 1;
    }
    else {
        return 0;
    }

}

int inSet(Set S,ElementType item)
{
    int i;

    for(i=0;i<S->len;i++){
        if(item==S->set[i]){
            return 1;
        }
    }
    return 0;
}

int isEmpty(Set S)
{

    if(S->len==0)
    {

        return 1;
    }
    else{
        return 0;
    }
}

int lengthSet(Set S)
{

    return S->len;
}

Set unionSet(Set S1,Set S2)
{
    Set S=malloc(sizeof(struct SequSet));
    initSet(S,S1->len);
    for(int i=0;i<S1->len;i++)
    {

        insertSet(S,S1->set[i]);
    }
    S->len=S1->len;
    for(int i=0;i<S2->len;i++)
    {
        insertSet(S,S2->set[i]);
    }
    return S;

}

Set interseSet(Set S1,Set S2){
        int len;
        len=S1->len<S2->len?S1->len:S2->len;
        Set S;
        initSet(S,len);
        for(int i=0;i<S1->len;i++)
        {

            if(inSet(S2,S1->set[i])){
                insertSet(S,S1->set[i]);
            }
        }

        return S;
}

Set differenceSet(Set S1,Set S2)
{

    int len;
    len=S1->len;
    Set S;
    initSet(S,len);
    for(int i=0;i<S1->len;i++)
    {

        if(!inSet(S2,S1->set[i])){
            insertSet(S,S1->set[i]);
        }
    }return S;
}

void clearSet(Set S)
{

    if(S->set!=NULL)
    {

        free(S->set);
        S->set=NULL;
        S->len=S->MaxSize=0;
    }
}

int main()
{
//    struct SequSet s,*newS=&s;
//    initSet(newS,11);
//
//    //添加元素
//    insertSet(newS,4);
//    insertSet(newS,6);
//    insertSet(newS,5);
//    insertSet(newS,7);
//    insertSet(newS,2);
//    insertSet(newS,6);
//    showSet(newS);

    //删除元素
//    printf("%d\n",deleteSet(newS,5));
//    showSet(newS);


    //查找元素
//    int data,index;
//    printf("请输入要查找的元素：\n");
//    scanf("%d",&data);
//    if(findSet(newS,&data,&index))
//    {
//        printf("*item=%d;index=%d",data,index);
//    }
//    else{
//        printf("查找失败\n");
//    }


    //查看元素是否在集合内
//
//    if(inSet(newS,4)){
//        printf("元素在集合内\n");
//    }
//    else{
//        printf("元素不在集合内\n");
//    }

     //判断集合是否为空

//    if(isEmpty(newS))
//    {
//
//        printf("空集！\n");
//    }
//    else{
//        printf("不是空集\n");
//    }

    //求元素的个数
//    printf("元素个数是%d\n",lengthSet(newS));


    //求两个集合并集
    struct SequSet s1,s2,*ps1=&s1,*ps2=&s2;
    initSet(ps1,10);
    initSet(ps2,3);
    insertSet(ps1,12);
    insertSet(ps1,13);
    insertSet(ps1,2);
    insertSet(ps1,3);
    insertSet(ps1,8);
    showSet(ps1);
    insertSet(ps2,34);
    insertSet(ps2,3);
    insertSet(ps2,64);
    insertSet(ps2,12);
    showSet(ps2);


//并集
    Set S=malloc(sizeof(struct SequSet));
    S=unionSet(ps1,ps2);
    showSet(S);
//交集
    Set SS=malloc(sizeof(struct SequSet));
    SS=interseSet(ps1,ps2);
    showSet(S);
    //差集
    Set SSS=malloc(sizeof(struct SequSet));
    SSS=differenceSet(ps1,ps2);
    showSet(SSS);

    clearSet(ps1);
    showSet(ps1);


    return 0;
}
