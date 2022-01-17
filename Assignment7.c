#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int n,front=-1,rear=-1;

void Enqueue();
void Dequeue();
void display();

int main()
{
    printf("Enter Maximum Size of queue: ");
    scanf("%d",&n);
    int arr[100],temp=0;

    while(1)
    {
        printf("\nMenu");
        printf("\n\t1. Enqueue\n\t 2.Dequeue\n\t3.Display\n\t4. Exit\n");
        int choice;
        printf(" Press: ");
        scanf("%d",&choice);
        printf("\n");
        switch (choice)
        {
            case 1:
                Enqueue(arr);
                break;
            case 2:
                Dequeue(arr);
                break;
            case 3:
                display(arr);
                break;
            case 0:
                temp=1;
            
            default:
                break;
        }
        if(temp)
            break;
        
        printf("\nPress ENTER to countinue....");
        getchar();
        getchar();
        printf("========================================\n");

    }
}


void Enqueue(int arr[])
{
    if((rear+1)%n==front)
    {
        printf("\nQueue is Full\n");
        return;
    }
    printf("Enter Data: ");
    int data;
    scanf("%d",&data);
    
    if(front==-1 && rear==-1)
    {
        front=0;
        rear=0;
    }
    else
        rear=(rear+1)%n;
    
    arr[rear]=data;

    printf("Data EnQueued Sucessfully....\n");
    
}


void Dequeue(int arr[])
{
    if(front==-1 && rear==-1)
    {
        printf("\nQueue is Empty\n");
        return;
    }
    if(front==rear)
    {
        front=-1;
        rear=-1;
        return;
    }

    front=(front+1)%n;

    printf("Data DeQueued Sucessfully\n");
}

void display(int arr[])
{
    int i;
    if(front==-1 && rear==-1)
    {
        printf("\nQueue is Empty\n");
        return;
    }
    
    if (rear >= front)
    {
        for (i=front;i<= rear;i++)
            printf("%d ",arr[i]);
    }
    else
    {
        for (i=front;i<n;i++)
            printf("%d ",arr[i]);
 
        for (i=0;i<=rear;i++)
            printf("%d ",arr[i]);
    }
    printf("\n\n");
}
