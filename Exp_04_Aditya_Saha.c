#include<stdio.h> 
#include<stdlib.h>
typedef struct queue//definition of structure
{
  int Roll;
  char *Name;  
  struct queue *next;
}queue;

  
int main()
{
  int choice1, sub_ch , *queue_arr, *stack_arr, front, rear, Top , Size, x , i;//declaration of int type variables and pointers

  queue *REAR, *FRONT, *p;//declaration of queue type pointers

  front=-1;
  rear=-1;

  Top=-1;//Top used for additional stack using array

  REAR=NULL;
  FRONT=NULL;
  

  char ch, control, character, *arr;//declaration of char type variables 
 
  control='y';//storing y initilally

  //prototype of functions
  int main_menu(int *);
  int sub_menu1(int *);
  int insert_arr(int *,int *,int *,int ,int );
  int delete_arr(int *,int *,int *,int ,int *);
  int display_arr(int * ,int  ,int ,int);
  int insert_sll(queue * ,queue **,queue **);
  int delete_sll(queue * ,queue **,queue **);
  int display_sll(queue * ,queue *);
    
  while(1)
  {
    lebel:
    system("clear");
    
    
    main_menu(&choice1);//calling function to display original menu list

    switch(choice1)
    {
       case 1://dynamic allocation of memory for queue using array
       queue_arr=(int*)calloc(10,sizeof(int));
     
       Size=10;//maximum number element that can be stored in the queue using array

       ch='y';
         
       while(1)
       {
          sub_menu1(&sub_ch);//calling function to display sub_menu list
         
          switch(sub_ch)
          {
            case 1: 
            printf("\nEnter element to be inserted to the queue:");
            scanf("%d",&x);//taking input of elements to be inserted

            insert_arr(queue_arr, &front, &rear,Size, x);//calling function to insert element in the queue using array

            if(((rear+1)%Size)!=front)
            {
              printf("\nElement %d has been inserted in the queue",x);
            }
            break;
            
            case 2:delete_arr(queue_arr,&front,&rear,Size,&x);//calling function to delete element from the queue using array

            if(front!=Size-1 && rear!=Size-1) //condition checking  for queue underflow      
            {
              printf("\nLast Deleted element is %d", x);
            } 
            break;

            case 3:i=front;//initialising i to Top
 
            stack_arr=(int*)calloc(10,sizeof(int));//dynamically allocating memory for reversed stack array  

            while(i!=rear)
            {
               
               Top=Top+1;//top incremented
               *(stack_arr+Top)=*(queue_arr+i);//value inserted in the stack
               i=(i+1)%Size;
            }
            Top=Top+1;//top incremented
            *(stack_arr+rear)=*(queue_arr+i);//value inserted in the stack

            printf("\nThe reversed queue is:\n");


            i=Top;
            while(i>=0)
            {
              printf("\n%d ",*(stack_arr+i));//printing the stack
              i=i-1;
            }

            free(stack_arr);
            break;
            case 4:

            display_arr(queue_arr,front, rear,  Size);//calling function to display the original stack

            break;

            case 5:goto lebel;
            break;
             
            default: printf("\nInvalid choice!!");
          }
         
          getchar();

          printf("\n\n press y to continue:");//asking user whether he wants to continue thwn to press y 

          ch=getchar();   
          if(ch!='y')//checking whether user pressed any other character other than y
          {
            break;//then break from the loop structure
          }
            
       }
       break;

       case 2:ch='y';//case 2 queue using linked list
         
       while(1)
       {
          sub_menu2(&sub_ch);//calling function to display sub_menu list
         
          switch(sub_ch)
          {
            case 1: 
            p=(queue*)malloc(sizeof(queue));//allocating memory in p for the node of queue type

            p->Name=(char*)malloc(50*sizeof(char));//allocating array dynamically

            printf("\nEnter the name : ");

            character='a';

            i=0;

            getchar();
            while(character!='\n')
            {
              character=getchar();//taking name input character by character

              if(character=='\n')
              {
                 *(p->Name+i)='\0';
              }
              else
              {
                 *(p->Name+i)=character;
              }
              
              i=i+1;
           }
 
            
           printf("\nEnter the roll :");

           scanf("%d",&p->Roll);//taking input of roll no.
           p->next=NULL;
           
           insert_sll(p , &REAR, &FRONT);//calling function to push the node in the queue

           printf("\nRoll |%d| is inserted in the queue....",p->Roll);
 
           break;
 
           case 2: delete_sll( p ,&REAR ,&FRONT);//calling function to delete node from the queue

           break;

           case 3:display_sll(REAR ,FRONT);//calling function to display 
           break;
           
           case 4: goto lebel;

           break;
             
           default: printf("\nInvalid choice!!");
          
          }
          
          getchar();

          printf("\n\n press y to continue:");//asking user whether he wants to continue thwn to press y 

          ch=getchar();   
          if(ch!='y')//checking whether user pressed any other character other than y
          {
            printf("\nOperations on unordered list is discontinued");
            break;//then break from the loop structure
          }
            
       }
 
       break;
 
       case 3: printf("\nTerminating code.....");

       return(1);
          
           
    }
  }
  return(1);
}
int main_menu(int *choice1)
{

  printf("\t\tThe main menu of operations are listed below ");//showing menu

  printf("\n1.Queue operations using array.\n2.Queue operations using linked list.\n3.EXIT");

  printf("\n\nEnter choice:");
  scanf("%d",&*choice1);//taking choice of user as input
  return(1);
}

int sub_menu1(int *sub_ch)
{
   printf("\n1.Insert \n2.Delete\n3.Reverse the Queue\n4.Display\n5.Back");

   printf("\n\nEnter the choice:");
   scanf("%d",&*sub_ch);//taking choice of user as input
   return(1);
}
int sub_menu2(int *sub_ch)
{
   printf("\n1.Insert \n2.Delete\n3.Display\n4.Back");

   printf("\n\nEnter the choice:");
   scanf("%d",&*sub_ch);//taking choice of user as input
   return(1);
}
  
int insert_arr(int *queue_arr,int *front,int *rear,int Size,int x)
{
   
     
   if(*front==-1 && *rear==-1)//condition check when queue is empty
   {
      *front=0;
      *rear=0;
      *(queue_arr+*rear)=x;//first elements is inserted
     
   }
   else if(((*rear+1)%Size)==*front)
   {
     printf("\nQueue overflow");
   }
   else
   {
     *rear=(*rear+1)%Size;//rear incremented
     *(queue_arr+*rear)=x;//value inserted in the queue
   }
   return(1);
}
  
int delete_arr(int *queue_arr,int *front,int *rear,int Size,int *x)
{
  
   if(*front==-1 && *rear==-1) //condition checking for queue underflow      
   {
     printf("\nQueue Underflow!!");
   }
   else if(*front==*rear)//condition check when only one element is left in the queue
   {
     //then we update both rear and front to -1
     *x=*(queue_arr+*front);
     *front=-1;
     *rear=-1;
   }
   else
   {
     *x=*(queue_arr+*front);
     *front=(*front+1)%Size;//front incremented
    
   }
   return(1);
}

  
int display_arr(int *queue_arr,int front,int rear,int Size)
{
   int i; //variable declaration

   i=front;   
   if(front==-1 && rear==-1) //condition checking  for queue underflow      
   {
     printf("\nQueue Underflow!!");
   }
   else
   {
      printf("\nElements present in the queue: \n");
      while(i!=rear)
      {
         printf("%d ,",*(queue_arr+i));//printing the queue
         i=(i+1)%Size;
      }
      printf("%d ",*(queue_arr+rear));
   }
   return(1);
}


int insert_sll(queue *p ,queue **REAR ,queue **FRONT)
{
   queue *q;//queue type pointer declaration
	
   if(*REAR==NULL && *FRONT==NULL)//CONDITION checking if their is no node inserted yet 
   {
      *REAR=p;//then inserting the first node
      *FRONT=p;
      
   }
   else
   {
      q=*REAR;
      q->next=p;//inserting the new node
      *REAR=p;//updating REAR
   }
  
   return(1);
	
}


int delete_sll(queue *p ,queue **REAR ,queue **FRONT)
{
   queue *q;//queue type pointer declaration

   q=*REAR;

   if((*REAR==NULL && *FRONT==NULL)||(*FRONT==q->next))//CONDITION checking if their is no node inserted yet 
   {
       printf("\nQueue underflow......");
   }
   else
   {
      q=*FRONT;
      p=*FRONT;
      *FRONT=q->next;//deleting node by updating the front

      printf("\n\nRoll |%d| is deleted from the queue....",p->Roll);

      free(p);
   }

   return(1);
}



int display_sll(queue *REAR ,queue *FRONT)
{
   queue *p;//declaration of stack type pointer 

   
   if((REAR==NULL && FRONT==NULL)||(FRONT==REAR->next))//CONDITION checking if their is no node inserted yet 
   {
       printf("\nQueue underflow......");
   }
   else
   {
      p=FRONT;//p pointing the node pointed by top

      printf("\nElements of queue are:\n");
      while(p!=REAR)
      {
	 printf("\n |%d| %s",p->Roll,p->Name);//printing the nodes in the stack
       
	 p=p->next;//updating p
      }
      printf("\n |%d| %s",p->Roll,p->Name);
   }

   return(1);
}

