#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define max 100
char infix[max];
char postfix[max];
char stack[max];
int top = -1;
int j=0;

int prec(char elem)
{
    if(elem == '^')/* exponent operator, highest precedence*/
    {
        return 3;
    }
    else if(elem == '*' || elem == '/')
    {
        return 2;
    }
    else if(elem == '+' || elem == '-')          /* lowest precedence */
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
char peek()
{
    return stack[top];
}

int isfull()
{
    if (top == max)
    {
        printf("Stack is full!!\n");
        return 1;
    }else
        
        return 0;
}
int isempty()
{
    if(top == -1)
    {
        return 1;
    }else
        return 0;
}
void push(char data)
{
    if(!isfull())
    {
        stack[++top]= data;
    }
        
}
char pop()
{
    char data;
    if(!isempty())
    {
        data = stack[top];
        top--;
        return data;
    }else
    {
        printf("There is no data stack is empty\n");
        return -1;
    }
}
void insert()
{
    char temp;
    while(!isempty())
    {
        temp = pop();
        postfix[j] = temp;
        j++;
    }
}
void isOperand(int i)
{
    char elem;
    if(isalpha(infix[i]))
    {
        postfix[j] = infix[i];
        j++;
    }
    else if(!isalpha(infix[i]))
    {
        if(prec(infix[i]) == prec(peek()))
        {
            printf("The precedence is same \n");
            insert();
        }
        if(prec(infix[i]) < prec(peek()))
        {
            printf("The precedence of %c is less than %c \n", infix[i], peek());
            insert();
        }
        elem = infix[i];
        push(infix[i]);
        
    }
}
int main()
{
    int len, i=0;
    printf("Enter Infix Expression:: ");
    scanf("%s", infix);
    len = strlen(infix);
    for(i = 0 ; i < len ; i++)
    {
       isOperand(i);
    }
    insert();
    printf("\n");
    printf("postfix expression:: %s\n", postfix);

    return 0;
}
