# Assignment-5

/*Name : Shubham Gholave
Roll no : SYITA139*/

#include <stdio.h>
#include<stdlib.h>
#include<string.h>
struct node 
{
  int prn,marks;
  char name[20];
  struct node *prev,*next;

};

struct node* inrec(struct node * head)
{ 
int stud;
char naw[20];
struct node *temp,*q;
q=head;

  printf("Enter prn_no :");
  scanf("%d",&head->prn);
  printf("Enter name :");
  scanf("%s",naw);
  strcpy(head->name,naw);
  printf("Enter IE_MARKS :");
  scanf("%d",&head->marks);
head->prev=NULL;
head->next=NULL;
printf("For how many students u have to enter the data : ");
scanf("%d",&stud);
printf("enter the data:\n");
for(int i=0;i<stud;i++)
{
  temp=(struct node *)malloc(sizeof(struct node));
  printf("Enter prn_no :");
  scanf("%d",&temp->prn);
  printf("Enter name :");
  scanf("%s",temp->name);
  printf("Enter IE_MARKS :");
  scanf("%d",&temp->marks);

  temp->next=NULL;
  temp->prev=head;
  head->next=temp;
  head=head->next;
}
return q;
  }

void display(struct node *head)
{ struct node *p;
p=head;
   while(p!=NULL)
  {
    printf("prn_no:%d\n",p->prn);
    printf("Name:%s\n",p->name);
    printf("IE_MARKS:%d\n\n\n",p->marks);
    p=p->next;
  }

}
void del(struct node *head)
{ int po;
printf("Enter prn number to delete the record : ");
scanf("%d",&po);


struct node *p,*q;
p=head;
q=head->next;





while(p->prn!=po)
{
  p=p->next;
  q=q->next;
}
p->prev->next=p->next;
q->prev=p->prev;
free(p);

}
void dels(struct node *head)
{
  struct node *p=head;
  head=head->next;
  //head->next->prev=NULL;
  head->prev=NULL;
  free(p);
  printf("Deleted succesfully\n");
}
void dell(struct node *head)
{
  struct node *p=head;
  while(p!=NULL&&p->next!=NULL)
  {
    p=p->next;

  }
  p->prev->next=NULL;
  free(p);

}

int main(void) {
  int a;
  struct node *head;
  head=(struct node *)malloc(sizeof(struct node));

 
do
{
  printf("1)Insert a record\n2)Delete a prn no between first and last \n3)Delete a prn no present at starting\n4)Display list\n5)Exit\n6)Deleting a prn no at end\n");
  printf("\nEnter ur choice : ");
  scanf("%d",&a);
  switch(a)
  {
    case 1:
    head=inrec(head);
    break;
    case 2:
    del(head);
    break;
    case 3:
    dels(head);
    break;
    case 4:
    display(head);
    break;
    case 6:
    dell(head);
    break;
   
    


  }

}while(a!=5);

}
