#include<stdio.h>
#include<stdlib.h>

typedef struct list
{
    int data;
    struct list *link;
    struct list *p;
}node;
node *head=NULL;
int count();
node *create_node(int elem)
{
    node*new=(node *)malloc(sizeof(node));
    if(new==NULL)
    {
        printf("Can't allocate memory\n ");
        exit(2);
    }
    new->data=elem;
    new->link=NULL;
    new->p=NULL;
    return new;
    
}

void insert_front(int elem)
{
    node *new=create_node(elem);
    node *ptr=head;
    if(head==NULL)
    {
        head=new;
        new->link=head;
        return;
    }
    while(ptr->link!=head)
    {
        ptr=ptr->link;
    }
    ptr->link=new;
    new->p=ptr;
    new->link=head;
    head=new;
}

void insert_last(int elem)
{
    node *new=create_node(elem);
    node *ptr=head;
    if(head==NULL)
    {
        head=new;
        new->link=head;
        return;
    }
    while(ptr->link!=head)
    {
        ptr=ptr->link;
    }
    ptr->link=new;
    new->link=head;
}

void insert_pos(int elem,int pos)
{
    node *ptr=head;
    node *new=create_node(elem);
    if(head==NULL)
    {
        head=new;
        new->link=head;
        return;
    }
    if(pos<0 || pos>node_count())
    {
        printf("invalid posisn\n");
        return;
    }
    if(pos==1)
    {
        insert_front(elem);
        return;
    }
    int i=1;
    while(i<pos-1)
    {
        ptr=ptr->link;
        i++;
    }
    new->link=ptr->link;
    ptr->link=new;
}

void delete_front()
{
    printf("\n\nDeleting from front\n\n");
    if(head==NULL)
    {
        printf("List is empty\n");
        return;
    }
    node *temp=head;
    node *prev=NULL;
    while(temp->link!=head)
    {
        
        temp=temp->link;
    }
    prev=head;
    temp->link=prev->link;
    head=prev->link;
    printf("%d is deleted\n",prev->data);
    free(prev);
}
void delete_end()
{
    printf("\n\nDelete from end\n\n");
    if(head==NULL)
    {
        printf("List is empty\n");
        return;
    }
    node *temp=head;
    node *prev=NULL;
    while(temp->link!=head)
    {
        prev=temp;
        temp=temp->link;
    }
    prev->link=head;
    printf("%d is deleted\n",temp->data);
    free(temp);
}

void delete_pos(int pos)
{
    if(head==NULL)
    {
        printf("list is empty\n");
        return;
    }
    if(pos<0 || pos>node_count())
    {
        printf("invalid posisn\n");
        return;
    }
    if(pos==1)
    {
        delete_front();
        return;
    }
    node *ptr=head;
    node *prev=NULL;
    int i=1;
    while(i<=pos-1)
    {
        prev=ptr;
        ptr=ptr->link;
        i++;
    }
    prev->link=ptr->link;
    printf("deleted = %d\n",ptr->data);
    free(ptr);
}
int node_count()
{
    int c=1;
    node *ptr=head;
    while(ptr->link!=head)
    {
        c++;
        ptr=ptr->link;
    }
    return c;
}
display()
{
    node *temp=head;
    int count=1;
    if(head==NULL)
    {
        printf("list is empty\n");
        exit(2);
    }
    while(temp->link!=head)
    {
        printf("%d\t",temp->data);
        temp=temp->link;
        count++;
    }
    printf("%d\t",temp->data);
    printf("\n");
    printf("NO of nodes =%d\n",count);
}
int main()
{
    insert_front(12);
    insert_front(11);
    insert_last(13);
    insert_last(14);
    display();
    insert_pos(13,3);
    display();
    delete_pos(2);
    display();
    
}

