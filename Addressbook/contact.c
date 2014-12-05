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

void deleteContact(ContactPointer * theContact, int targetIndex) {
    ContactPointer temporaryContactPointer = malloc(sizeof(Contact));
    temporaryContactPointer = *theContact;
    ContactPointer previousContactPointer = malloc(sizeof(Contact));
    ContactPointer nextContactPointer = malloc(sizeof(Contact));
    
    for (int x=0; x<targetIndex; x++) {
        temporaryContactPointer = temporaryContactPointer->nextPointer;
    }
    
    
    // if at head
    if (!temporaryContactPointer->previousPointer && temporaryContactPointer->nextPointer) {
        nextContactPointer = temporaryContactPointer->nextPointer;
        temporaryContactPointer->nextPointer = NULL;
        nextContactPointer->previousPointer = NULL;
        *theContact = nextContactPointer;
        
    }
    // if at tail
    if (!temporaryContactPointer->nextPointer && temporaryContactPointer->previousPointer ) {
        previousContactPointer  = temporaryContactPointer->previousPointer;
        previousContactPointer->nextPointer = NULL;
        temporaryContactPointer->previousPointer = NULL;
    }
    // if in the middle
    if (temporaryContactPointer->nextPointer && temporaryContactPointer->previousPointer) {
        nextContactPointer = temporaryContactPointer->nextPointer;
        previousContactPointer  = temporaryContactPointer->previousPointer;
        previousContactPointer->nextPointer = nextContactPointer;
        nextContactPointer->previousPointer = previousContactPointer;
        
    }
    
}


void printContacts(ContactPointer * theContact) {
    ContactPointer temporaryContactPointer = *theContact;
    
    if (temporaryContactPointer == NULL)
        printf("List is empty\n");
    else {
        printf("List is \n");
        while (temporaryContactPointer) {
            printf("%s <-> ", temporaryContactPointer->firstName);
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

void printContact(ContactPointer * theContact, int targetIndex) {
    ContactPointer stalkContactPointer = *theContact;
    for (int x=0; x<targetIndex; x++) {
        stalkContactPointer = stalkContactPointer->nextPointer;
    }
    printf("Printing Contact: %s %s %s %s \n", stalkContactPointer->firstName, stalkContactPointer->lastName, stalkContactPointer->email, stalkContactPointer->phone);
}

void printField(ContactPointer * theContact, int targetIndex, char *field) {
    ContactPointer stalkContactPointer = *theContact;
    for (int x=0; x<targetIndex; x++) {
        stalkContactPointer = stalkContactPointer->nextPointer;
    }
    if (strcmp(field, "lastName") == 0)
        printf("%s\n",stalkContactPointer->lastName);
    else if (strcmp(field, "firstName") == 0)
        printf("%s\n",stalkContactPointer->firstName);
    else if (strcmp(field, "email") == 0)
        printf("%s\n",stalkContactPointer->email);
    else if (strcmp(field, "phone") == 0)
        printf("%s\n",stalkContactPointer->phone);
}

void saveFile(ContactPointer * theContact, char const * fileName) {
    ContactPointer currentContactPointer = *theContact;
    FILE * filePointer; // file pointer
    char buffer[256]; // buffer
    filePointer = fopen(fileName, "w"); //open for writing
    while (currentContactPointer) {
        strcpy(buffer, currentContactPointer->lastName);
        strcat(buffer, ",");
        strcat(buffer, currentContactPointer->firstName);
        strcat(buffer, ",");
        strcat(buffer, currentContactPointer->email);
        strcat(buffer, ",");
        strcat(buffer, currentContactPointer->phone);
        fprintf(filePointer, "%s\n", buffer);
        
        currentContactPointer = currentContactPointer->nextPointer;
    }
    fclose(filePointer);
}

void loadFile(ContactPointer * theContact, char const * fileName) {
    
    FILE * filePointer;
    char buffer[256];
    int i=0;

    
    if (!(filePointer = fopen(fileName, "r"))) {
        printf("Can't open file!\n");
        return;
    }
    *theContact = NULL;
    
    
    while (fgets(buffer, sizeof (buffer), filePointer)) {
        buffer[strlen(buffer)-1] = '\0';
        addContact(theContact, i, buffer);
    }
}