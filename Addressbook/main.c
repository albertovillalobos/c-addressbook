//
//  main.c
//  Addressbook
//
//  Created by Isaac on 12/3/14.
//  Copyright (c) 2014 Alberto. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "contact.h"

int main(int argc, const char * argv[]) {
    ContactPointer headContact; //Contact at the head
    ContactPointer tailContact; //Contact at the tail
    ContactPointer currentContact; //Current contact
    int contactsCounter;
    char choiceAction;
    char choiceIndex;
    char choiceData[255];
    
    while(1) {
        printf("Please Enter an option:\n");
        scanf("%s",&choiceAction);
        switch (choiceAction) {
            case 'a':
            case 'A':
                printf("So you wanna add something, which index at?: \n");
                scanf("%s",&choiceIndex);
                printf("So you wanna add it at index %c, what's its info?\n", choiceIndex);
                scanf("%s",choiceData);
                printf("So you wanna add %s at index %c huh? Ok lemme try...\n",choiceData, choiceIndex);
                addContact(&headContact, 0, choiceData);
                printf("Success!");
                break;
                
            case 'd':
            case 'D':
                printf("You wanna Delete\n");
                break;
                
            case 'g':
            case 'G':
                printf("You wanna Get a contact\n");
                break;
                
            case 'f':
            case 'F':
                printf("You wanna get a field\n");
                break;
                
            case 'n':
            case 'N':
                printf("You want number of contacts\n");
                break;
                
            case 'l':
            case 'L':
                printf("You wanna load a file\n");
                break;
                
            case 's':
            case 'S':
                printf("You wanna save\n");
                break;
            
            case 'q':
            case 'Q':
                printf("Goodbye!\n");
                return 0;
                
            default:
                break;
        }
    }
    return 0;
    
}
