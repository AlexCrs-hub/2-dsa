#include "head.h"

void initializeSll()
{
    first = NULL;
    last = NULL;
}

void AF(int data)
{
    if(first == NULL)
    {
        first = (NodeT*)malloc(sizeof(NodeT));
        first->next = NULL;
        first->prev = NULL;
        first->data = data;
        last = first;
    }
    else
    {
        NodeT * newElement = (NodeT*)malloc(sizeof(NodeT));
        newElement->data = data;
        newElement->next = first;
        newElement->prev=NULL;
        first = newElement;
    }
}

void AL(int data)
{
    if(first == NULL)
    {
        first = (NodeT*)malloc(sizeof(NodeT));
        first->next = NULL;
        first->prev = NULL;
        first->data = data;
        last = first;
    }
    else
    {
        NodeT * newElement = (NodeT*)malloc(sizeof(NodeT));
        last->next = newElement;
        newElement->next = NULL;
        newElement->prev = last;
        newElement->data = data;
        last = newElement;
    }
}

void DF()
{
    if(first==NULL)
    {
        return;
    }
    NodeT *newElement = first;
    first = first->next;
    free(newElement);
    first->prev=NULL;
}

void DL()
{
    if(first==NULL)
    {
        return;
    }
    if(last!=NULL)
    {
       NodeT *beforeLast = first;
       if(first!=last)
       {
           while(beforeLast->next->next!=NULL)
           {
               beforeLast=beforeLast->next;
           }
           free(last);
           last=beforeLast;
           beforeLast->next=NULL;
           beforeLast->prev=last;
       }
       else
       {
           free(last);
           last=NULL;
           first=NULL;
       }
    }
}

void DE(int data)
{
    NodeT * currentElement = first;
    NodeT * previousElement= first;
    while(currentElement != NULL)
    {
        if(currentElement->data == data)
        {
            if(currentElement == first)
            {
                first = currentElement->next;
                free(currentElement);
                currentElement=first;
                currentElement->prev=NULL;
                previousElement=first;
                previousElement->prev=NULL;
            }
            else if(currentElement == last)
            {
                free(currentElement);
                last=previousElement;
                last->next=NULL;
                currentElement=NULL;
            }
            else
            {
                previousElement->next = currentElement->next;
                free(currentElement);
                currentElement=previousElement->next;
                currentElement->prev = previousElement;
            }
        }
        else
        {
            previousElement = currentElement;
            currentElement = currentElement->next;
        }

    }
}

void print_All(FILE *o)
{
    if(first == NULL)
    {
        fprintf(o,"List is empty!\n");
    }
    else
    {
        NodeT * currentElement = first;
        while(currentElement != NULL)
        {
            fprintf(o,"%d ", currentElement->data);
            currentElement = currentElement->next;
        }
        fprintf(o,"\n");
    }

}

void PRINT_F(int nr,FILE *o)
{
    if(first==NULL)
    {
        fprintf(o,"List is doomed.\n");
    }
    else
    {
        NodeT *currentNode=first;
        for(int i=0;i<nr && currentNode!=NULL;i++)
        {
            fprintf(o,"%d ",currentNode->data);
            currentNode=currentNode->next;
        }
        fprintf(o,"\n");
    }
}

void PRINT_L(int nr,FILE *o)
{
    if(first==NULL)
    {
        fprintf(o,"List is doomed.\n");
    }
    else
    {
        int nrOfElements=0;
         NodeT *currentNode=first;
         while(currentNode!=NULL)
         {
             nrOfElements++;
             currentNode=currentNode->next;
         }
         if(nrOfElements<=nr)
         {
             print_All(o);
         }
         else
         {
             currentNode=first;
             int i=0;
             while(i<nrOfElements-nr)
             {
                 currentNode=currentNode->next;
                 i++;
             }
             while(currentNode!=NULL)
             {
                 fprintf(o,"%d ",currentNode->data);
                 currentNode=currentNode->next;
             }
             fprintf(o,"\n");
         }
    }
}

void DOOM_THE_LIST()
{
    NodeT * currentElement = first;
    while(currentElement != NULL)
    {
        first = first->next;
        free(currentElement);
        currentElement = first;
    }
}

