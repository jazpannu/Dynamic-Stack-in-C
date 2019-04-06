struct ArrayStack
{
  int top;
  int capacity;
  int *array;
};
struct ArrayStack* CreateStack(int cap)
{
    struct ArrayStack *stack;
    stack= malloc(sizeof(struct ArrayStack));
    stack->top=-1;
    stack->capacity=cap;
    stack->array= malloc(sizeof(int)*stack->capacity);
    return(stack);
}
 int isfull(struct ArrayStack *stack)
{
    if(stack->top==stack->capacity-1)
     return(1);
    else
     return(0);
}
int isempty(struct ArrayStack *stack)
{
    if(stack->top==-1)
      return(1);
    else
      return(0);
}
void push(struct ArrayStack *stack)
{
   int item;
   if(!isfull(stack))
    {
     printf("Enter item:\n");
     scanf("%d",&item);
     stack->top++;
     stack->array[stack->top]=item;
     printf("\n%d pushed",item);  }
   else
     printf("\nstack is full");
}
int pop(struct ArrayStack *stack)
{
 int item;
 if(!isempty(stack))
 {
   item=stack->array[stack->top];
   stack->top--;
   return(item);
 }
 else return(-1);

}

main()
{
   struct ArrayStack *stack;
   int size,choice,item;
   printf("enter size of stack\n");
   scanf("%d",&size);
   stack = CreateStack(size);
   printf("choose from following:\n");
     printf("1  push\n2  pop\n3  exit\n");
   while(1)
   {

      scanf("%d",&choice);
     switch(choice)
     {
       case 1:
	     push(stack);
	     break;
       case 2:
	    item= pop(stack);
	    if(item==-1)
	      printf("stack is empty\n");
	    else
	     printf("poped value is %d",item);
	     break;
       case 3:
	     exit();
       default:
	    printf("please enter correct option.\n");
     }
    getch();
   }
}