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


// Add a contact, pass the contact pointer, desired index, and comma
// separated values in a string
void addContact(ContactPointer * theContact, int index, char *data) {

    
    ContactPointer currentContactPointer = *theContact;
    ContactPointer previousContactPointer;
    ContactPointer nextContactPointer;
  
    ContactPointer newContactPointer = malloc(sizeof(Contact));
    char delimiter = ',';
    data = strtok(data, &delimiter);
    for (int x=0; data!=NULL; x++) {
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
    }
}

