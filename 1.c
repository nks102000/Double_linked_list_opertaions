//1905622 - NITISH KUMAR SONTHALIA
//Double Linked list
#include<stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

void creat_list(struct node ** ,struct node ** ,int n);
void display_list_start(struct node ** );
void display_list_end(struct node ** );
void add_first_node(struct node ** ,int n);
void add_last_node(struct node ** ,int n);
void add_node(struct node ** ,int n,int p);
void del_node_with_data(struct node ** ,int n);
void del_node_at_position(struct node ** ,int p);
void rev(struct node **st,struct node **end);
void rev_nodes(struct node **st,struct node **end);


int main(){
    struct node *start = NULL;

    struct node *end = NULL;
    int t;

    int f=1;

    while(f){
    printf("\n MENU ");
    printf("\n 1. ADD An Element ");
    printf("\n 2. Display The List From Start ");
    printf("\n 3. Display The List From End ");
    printf("\n 4. Add First Node ");
    printf("\n 5. Add Last Node ");
    printf("\n 6. Add Node At Position ");
    printf("\n 7. Deletion of Node With Data ");
    printf("\n 8. Deletion of Node At Position ");
    printf("\n 9. Reverse ");
    printf("\n 10. Reverse Nodes ");
    printf("\n 11. EXIT ");
    scanf("%d",&t);
    int e,p;

    switch (t)
    {

    case 1:
        printf("\n Enter The Element To Be Entered: ");
        scanf("%d",&e);
        creat_list(&start,&end,e);
        break;

    case 2:
        display_list_start(&start);
        display_list_end(&end);
        break;

    case 3:
        display_list_end(&end);
        break;

    case 4:
        printf("\n Enter The Element To Be Entered: ");
        scanf("%d",&e);
        add_first_node(&start,e);
        break;

    case 5:
        printf("\n Enter The Element To Be Entered: ");
        scanf("%d",&e);
        add_last_node(&end,e);
        break;
    
    case 6:
        printf("\n Enter The Element To Be Entered: ");
        scanf("%d",&e);
        printf("\n Enter The Position To Be Entered: ");
        scanf("%d",&p);
        add_node(&start,e,p);
        break;

    case 7:
        printf("\n Enter The Element Data: ");
        scanf("%d",&p);
        del_node_with_data(&start,p);
        break;

    case 8:
        printf("\n Enter The Element Position: ");
        scanf("%d",&p);
        del_node_at_position(&start,p);
        break;

    case 9:
        rev(&start,&end);
        break;

    case 10:
        rev_nodes(&start,&end);
        break;

    case 11:
        f=0;
        break;

    default:
        break;
    }
    }
}

void creat_list(struct node **st,struct node **end ,int n){
    struct node *temp;

    struct node *new1 = (struct node *)malloc(sizeof(struct node ));

    new1->data=n;

    new1->next=NULL;

    new1->prev=NULL;

    if(*st==NULL){
        *st=new1;
        *end=new1;
        return;
    }
    else{
        temp=*st;
        while(temp->next!=NULL){
            temp= temp->next;
        }
        temp->next = new1;
        new1->prev=temp;
        *end=new1;
    }
}

void display_list_start(struct node **st){

    if (*st == NULL){ 
      printf("\n Empty List"); 
      return ;
    }

    struct node*temp=*st;
    printf("Elements in LIST are:");

    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

void display_list_end(struct node ** end){
    if (*end == NULL){ 
      printf("\n Empty List"); 
      return ;
    }

    struct node*temp=*end;
    printf("Elements in LIST are:");

    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->prev;
    }
}

void add_first_node(struct node **st ,int n){

    struct node *ptr = (struct node*)malloc(sizeof(struct node));

    struct node *temp=*st;

    ptr->data = n;
    ptr->next=*st;
    ptr->prev=NULL;
    temp->prev=ptr;
    *st=ptr;
}

void add_last_node(struct node **end ,int n){
    struct node *ptr = (struct node*)malloc(sizeof(struct node));

    struct node *temp=*end;

    ptr->data = n;
    ptr->next=NULL;
    ptr->prev=temp;
    temp->next=ptr;
    *end=ptr;
}

void add_node(struct node **st ,int n,int p){

    if (*st == NULL){ 
      printf("\n Empty List"); 
      return ;
    }

    struct node *ptr = (struct node*)malloc(sizeof(struct node));

    ptr->data=n;	

    int i;

    struct node *temp=*st;

    printf("\n Enter 1 for entering before the given position and 2 for entering after given position");

    int e;

    scanf("%d",&e);

    if(e==1){
    if(p==1)
    {
        ptr->next=*st;
        temp->prev=ptr;
        ptr->prev=NULL;
        *st=ptr;
    }
    else{
   	for(i=1;i<p-1;i++){
    	temp=temp->next;
    }
    ptr->next=temp->next;
    temp->next->prev=ptr;
    ptr->prev=temp;
    temp->next=ptr;
    }
    }
    if(e==2){
        p=p+1;
   	for(i=1;i<p-1;i++){
    	temp=temp->next;
    }
    ptr->next=temp->next;
    temp->next->prev=ptr;
    ptr->prev=temp;
    temp->next=ptr;
    }
}
void del_node_with_data(struct node **st ,int n){

    struct node *t;

    t=*st;

    while (t->data!=n)
    {
        t=t->next;
    }
    t->prev->next=t->next;
    t->next->prev=t->prev;
    free(t);
}

void del_node_at_position(struct node **st, int p) 
{

   if (*st == NULL){ 
      printf("\n Empty List"); 
      return ;
    }

   struct node *temp = *st; 
    int i;
    for(i=1;i<p;i++){
    	temp=temp->next;
    }

    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    free(temp);

}

void rev(struct node **st,struct node **end){
    struct node *t1;
    struct node *t2;
    int p;
    t1=*st;
    t2=*end;
    while(t1!=t2 && t1->prev!=t2){
        p=t1->data;
        t1->data=t2->data;
        t2->data=p;
        t1=t1->next;
        t2=t2->prev;
    }
    display_list_start(st);
    display_list_end(end);
}

void rev_nodes(struct node **st,struct node **end){
    struct node *t2,*t1,*p;
    p=NULL;
    t1=*st;
    while(t1!=NULL){
        t2=t1->next;
        t1->prev=t2;
        t1->next=p;
        p=t1;
        t1=t2;
    }
    *st=p;
    display_list_start(st);
    display_list_end(end);
}