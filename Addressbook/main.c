//
//  main.c
//  Addressbook
//
//  Created by Isaac on 12/3/14.
//  Copyright (c) 2014 Alberto. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

struct contact {
    char lastName[255];
    char firstName[255];
    char email[255];
    char phone[255];
    
    struct contact *nxtPtr;
    struct contact *prvPtr;
};

typedef struct contact Contact;
typedef Contact *nextPtr;
typedef Contact *prvPtr;



int main(int argc, const char * argv[]) {
    
    char choice;
    
    while(1) {
        printf("Please Enter an option:\n");
        scanf("%s",&choice);
        switch (choice) {
            case 'a':
            case 'A':
                printf("You wanna add\n");
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
