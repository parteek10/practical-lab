struct Nodet
{
    struct Nodet *lchild;
    struct Nodet *rchild;
    int data;

};

typedef struct Nodet Nodet;
#include"queue.h"
Nodet *root =NULL;
Nodet* alloc()
{
    Nodet *newnode;
    newnode=malloc(sizeof(Nodet));
    newnode->lchild=newnode->rchild=NULL;
    return newnode;

}

void createtree()
{
    Nodet *t,*p;
    int val;
    queue q;
    printf("Enter the value of the root");
    scanf("%d",&val);
    createque(&q,100);
    root=alloc();
    root->data=val;
    enque(&q,root);
    while(!isemptyque(q))
    {
        p=deque(&q);

        printf("Enter the left child of the %d else -1:",p->data);
        scanf("%d",&val);
        if(val!=-1)
        {
            t=alloc();
            t->data=val;
            p->lchild=t;
            enque(&q,t);
        }
        printf("Enter the right child of the %d  else -1:",p->data);
        scanf("%d",&val);
        if(val!=-1)
        {
            t=alloc();
            t->data=val;
            p->rchild=t;
            enque(&q,t);
        }

    }


}



void preorder(Nodet *p)
{

    if(p!=NULL)
    {
        printf("%d ",p->data);

        preorder(p->lchild);
        preorder(p->rchild);
    }
}
void postorder(Nodet *p)
{

    if(p!=NULL)
    {
        postorder(p->lchild);
        postorder(p->rchild);
        printf("%d ",p->data);
    }
}
void inorder(Nodet *p)
{

    if(p!=NULL)
    {
        inorder(p->lchild);
        printf("%d ",p->data);
        inorder(p->rchild);
    }
}
void conversepost(Nodet *p)
{
     if(p!=NULL)
    {
        printf("%d ",p->data);
        conversepost(p->rchild);
        conversepost(p->lchild);
    }

}
void levelorder(Nodet *p)
{

    queue q;
    create(&q,100);
    printf("%d ",p->data);
    enque(&q,p);
    while(!isemptyque(q))
    {
        p=deque(&q);
        if(p->lchild)
        {
            printf("%d ",p->lchild->data);
            enque(&q,p->lchild);
        }
        if(p->rchild)
        {
            printf("%d ",p->rchild->data);
            enque(&q,p->rchild);
        }


    }



}

int main()
{
    createtree();
    levelorder(root);




}
