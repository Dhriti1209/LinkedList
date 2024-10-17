#include <stdio.h>
#include <stdlib.h>
struct Node
{
 int data;
 struct Node *next;
}*first=NULL;
void create(int A[],int n)
{
 int i;
 struct Node *t,*last;
 first=(struct Node *)malloc(sizeof(struct Node));
 first->data=A[0];
 first->next=NULL;
 last=first;

 for(i=1;i<n;i++)
 {
 t=(struct Node*)malloc(sizeof(struct Node));
 t->data=A[i];
 t->next=NULL;
 last->next=t;
 last=t;
 }
}
int sum(struct Node *p){
    int s=0;
    while(p!=NULL){
        s+=p->data;
        p=p->next;

    }
    return s;
}
int rsum(struct Node *p){
    if(p==NULL)
    return 0;
    else 
    return rsum(p->next)+p->data;

}
int main()
{
 int A[]={3,5,7,10,25,8,32,2};
 create(A,8);

 
 printf("sum %d\n",sum(first));


 return 0;
}