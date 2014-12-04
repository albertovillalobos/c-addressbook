//
//  contact.c
//  Addressbook
//
//  Created by Isaac on 12/3/14.
//  Copyright (c) 2014 Alberto. All rights reserved.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "contact.h"


void addContact(ContactPointer * theContact, int targetIndex, char *data) {
    
  
    // create a new Contact
    ContactPointer newContactPointer = malloc(sizeof(Contact));
    
    // temporary contact
    ContactPointer temporaryContactPointer = malloc(sizeof(Contact));
    temporaryContactPointer = *theContact;
    
    // placeholder to bubble the previous pointer
    ContactPointer previousContactPointer = malloc(sizeof(Contact));
    
    // placeholder to bubble the next pointer
    ContactPointer nextContactPointer = malloc(sizeof(Contact));
    
    
    // our delimiter is a comma
    char delimiter = ',';
    
    // divide data into "tokens" or "chunks" separated by a comma
    data = strtok(data, &delimiter);
    
    // add all fields to our new ContactPointer
    for (int x=0; x<4; x++) {
        switch (x) {
            case 0:
                strcpy(newContactPointer->lastName, data);
                break;
            case 1:
                strcpy(newContactPointer->firstName, data);
                break;
                
            case 2:
                strcpy(newContactPointer->email, data);
                break;
                
            case 3:
                strcpy(newContactPointer->phone, data);
            default:
                break;
        }
        // Move onto the next chunk (token)
        data = strtok(NULL, &delimiter);
        
    }
    char breakpoint = 'b';
    // check if current list if empty
    if (!*theContact) {
        // if it is, then insert it there!
        *theContact = newContactPointer;
    }
    // not empty
    else {
        // inserting at the head
        if (targetIndex==0) {
            newContactPointer->nextPointer = temporaryContactPointer;
            temporaryContactPointer->previousPointer = newContactPointer;
            *theContact = newContactPointer;
            
        }
        // inserting at tail
        else if(getCount(theContact) == targetIndex) {
            for (int i =0; i < targetIndex-1; i = i+1) {
                temporaryContactPointer = temporaryContactPointer->nextPointer;
            }
            temporaryContactPointer->nextPointer = newContactPointer;
            newContactPointer->previousPointer = temporaryContactPointer;
            
        }
        // inserting somewhere in the middle
        else {
            for (int i=0; i < targetIndex; i = i+1) {
                temporaryContactPointer = temporaryContactPointer->nextPointer;
            }
            previousContactPointer = temporaryContactPointer->previousPointer;
            nextContactPointer = temporaryContactPointer;
            newContactPointer->previousPointer = previousContactPointer;
            newContactPointer->nextPointer = nextContactPointer;
            nextContactPointer->previousPointer = newContactPointer;
            previousContactPointer->nextPointer = newContactPointer;
            
        }
    }
}



void printContacts(ContactPointer * theContact) {
    ContactPointer temporaryContactPointer = *theContact;
    
    if (temporaryContactPointer == NULL)
        printf("List is empty\n");
    else {
        printf("List is \n");
        while (temporaryContactPointer) {
            printf("%s -> ", temporaryContactPointer->firstName);
            temporaryContactPointer = temporaryContactPointer->nextPointer;
        }
        printf("NULL\n");
    }
}

int getCount(ContactPointer * theContact) {
    ContactPointer counterContactPointer = *theContact;
    int count = 0;
    if (counterContactPointer == NULL)
        return count;
    else {
        while (counterContactPointer) {
            counterContactPointer = counterContactPointer->nextPointer;
            count = count + 1;
        }
    }
    return count;
    
    
}