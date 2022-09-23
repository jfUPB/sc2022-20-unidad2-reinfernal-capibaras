#include "eventList.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

EventList *CreateEventList(void)
{
    EventList *eventList = malloc(sizeof(EventList));
    eventList ->isEmpty = 1;
    eventList ->head = NULL;
    eventList ->last = NULL;
    return eventList;

}

void DestroyEventList(EventList *this)
{
    free(this); //pipe me obligó
}

Event *SearchEvent(EventList *this, char *name)
{

}

void AddEvent(EventList *this, Event *event)
{
    if(this->isEmpty == 1)
    {
        this->isEmpty = 0;
        this->head = event;
        this->last = event; 
    }
    else
    {
        this->last->next = event;
        this->last = event;        
    }
    
}

void RemoveEvent(EventList *this, char *name)
{
    Event *phead = this->head;
    printf("nametec: %c\n", *name);
    printf("namehead: %c\n", *this->head->eventName);
    if(*name == *this->head->eventName)
    {
        printf("borr1\n");
        this->head = this->head->next;
        DestroyEvent(phead);
    }
    else if (*name == *this->last->eventName)
    {
        //printf("ultev\n");
        while (this->head->next != NULL)
        {
            if(this->head->next->next == NULL)
            {
                this->last = this->head->next;
                this->head->next = NULL;
                break;
            }
            this->head = this->head->next;
        }
        DestroyEvent(this->last);

        this->head = phead; 
    }
    else 
    {
        printf("entra\n");
        while (this->head->next != NULL)
        {
            if(*name == *this->head->next->eventName)
            {
                this->head->next = this->head->next->next;
                break;
            }
            this->head = this->head->next;
        }
        DestroyEvent(this->head->next->next);

        this->head = phead; 
    }

}

void ListEvents(EventList *this)
{
    Event *phead = this->head;

    if(this->isEmpty == 1)
    {
        printf("empty\n");
    }
    else 
    {
        printf("%s\n",this->head->eventName);
        while (this->head->next != NULL)
        {
            this->head = this->head->next;
            printf("%s\n",this->head->eventName); 
        }
        this->head = phead;
    }
}
