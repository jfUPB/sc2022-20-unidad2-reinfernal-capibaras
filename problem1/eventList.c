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
    if(this->head->eventName == name)
    {
        this->head = this->head->next;
        DestroyEvent(this->head);
    }
    else if (this->last->eventName == name)
    {
        while (this->head->next != NULL)
        {
            if(this->head->next->next == NULL)
            {
                this->last = this->head->next;
                this->head->next = NULL;
            }
            this->head = this->head->next;
        }
        DestroyEvent(this->last);
    }
    {

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
