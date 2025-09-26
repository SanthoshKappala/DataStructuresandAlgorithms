
#include <stdio.h>
#include<stdlib.h>
struct stack{
    int stack_size;
    int *stack_blocks;
    int top_element;
}stac;
int isfull()
{
    return(stac.top_element==stac.stack_size -1);
}
int isempty()
{
    return(stac.top_element==-1);
}
void push()
{
    int element;
    printf("enter the element to push into the stack :");
    scanf("%d",&element);
    if(!isfull())
    {
        stac.top_element++;
        stac.stack_blocks[stac.top_element]=element;
        printf("element is pushed into the stack : %d \n", stac.stack_blocks[stac.top_element]);
    }
    else
    {
        printf("stack is already full :\n");
    }
}
int pop()
{
    int pop_element;
    if(!isempty())
    {
        pop_element=stac.stack_blocks[stac.top_element];
        stac.top_element--;
        printf(" poped element is : %d \n",pop_element);
    }
    else{
        printf("stack is empty :\n");
    }
 
}
void peek()
{
    int stack_top;
    if(!isempty())
    {
        stack_top=stac.stack_blocks[stac.top_element];
    printf(" the stack top element is :%d \n",stack_top);
    }
    else{
        printf("stack is empty");
    }
 
}
int forward()
{
    for(int i=0;i<=stac.top_element;i++)
    {
        printf("%d  ",stac.stack_blocks[i]);
    }
}
int backward()
{
    for(int i=stac.top_element;i>=0;i--)
    {
        printf("%d ",stac.stack_blocks[i]);
    }
}
int main() {
    int choice;
    stac.stack_size=0;
    stac.stack_blocks=0;
    stac.top_element=-1;
    printf("enter the size of the stack :");
    scanf("%d",&stac.stack_size);
    stac.stack_blocks=(int *)malloc(sizeof(int )*stac.stack_size);
    while(1)
    {
    printf("enter the stack operation choice 1)push: 2)pop: 3)peek: 4)travel_forward: 5)back:\n");
    scanf("%d",&choice);
    switch(choice){
        case 1:
                push();
                break;
        case 2:
                pop();
                break;
        case 3:
                peek();
                break;
        case 4:
                forward();
                break;
        case 5:
                backward();
                break;
        default:
        break;
    }
    }
 
    return 0;
}
