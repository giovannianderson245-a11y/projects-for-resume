/*
Giovanni Anderson
9-30-25
Lab 8
Phone Book
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct
{
	char firstName[16];
	char lastName[16] ;
	char phoneNumber[13];
}contact;

typedef struct
{
	contact *data;
	size_t   size;
	size_t   capacity; 
}phoneBook;

void pb_init(phoneBook *phoneBook);
void pb_free(phoneBook *phoneBook);
void addContact(phoneBook *phoneBook);
void deleteContact(phoneBook *phoneBook);
void showContact(const phoneBook *phoneBook);
void sortContact(phoneBook *phoneBook, int by_first);
void findContact(phoneBook *phoneBook);
void deleteAllContact(phoneBook *pb);
void randomContact(const phoneBook *pb);
void storeContact(const phoneBook *pb, const char *path);
void retrieveContact(const phoneBook *pb, const char *readPath);

void pb_init(phoneBook *pb)
{
    pb->data = NULL;
    pb->size = 0;
    pb->capacity = 0;
}

void pb_free(phoneBook *pb)
{
    free(pb->data);
    pb->data = NULL;
    pb->size = 0;
    pb->capacity = 0;
}

void addContact(phoneBook *pb)
{
    if (pb->size >= pb->capacity)
    {
        size_t new_capacity = (pb->capacity == 0) ? 4 : pb->capacity * 2;
        contact *new_data = realloc(pb->data, new_capacity * sizeof(contact));
        
        if (new_data == NULL)
        {
            printf("Memory allocation failed\n");
            return;
        }
        
        pb->data = new_data;
        pb->capacity = new_capacity;
    }
    printf("Enter first name: ");
    scanf("%15s", pb->data[pb->size].firstName);
    
    printf("Enter last name: ");
    scanf("%15s", pb->data[pb->size].lastName);
    
    printf("Enter phone number: ");
    scanf("%12s", pb->data[pb->size].phoneNumber);
    
    pb->size++;
    printf("Contact added\n\n");
}

void deleteContact(phoneBook *pb)
{
    if (pb->size == 0)
    {
        printf("Phone book is empty\n\n");
        return;
    }
    char searchFirstName[16];
    char searchLastName[16];
    
    printf("Enter first name of contact to delete: ");
    scanf("%15s", searchFirstName);
    
    printf("Enter last name of contact to delete: ");
    scanf("%15s", searchLastName);
    
    for (size_t i = 0; i < pb->size; i++)
    {
        if (strcmp(pb->data[i].firstName, searchFirstName) == 0 &&
            strcmp(pb->data[i].lastName, searchLastName) == 0)
        {
            for (size_t j = i; j < pb->size - 1; j++)
            {
                pb->data[j] = pb->data[j + 1];
            }
            pb->size--;
            printf("Contact deleted\n\n");
            return;
        }
    }
    printf("Contact not found\n\n");
}

void showContact(const phoneBook *pb)
{
    if (pb->size == 0)
    {
        printf("Phone book is empty!\n\n");
        return;
    }
    printf("\nList of contacts:\n");
    for (size_t i = 0; i < pb->size; i++)
    {
        printf("Contact %zu:\n", i + 1);
        printf("  First Name: %s\n", pb->data[i].firstName);
        printf("  Last Name: %s\n", pb->data[i].lastName);
        printf("  Phone: %s\n\n", pb->data[i].phoneNumber);
    }
}

void sortContact(phoneBook *pb, int by_first)
{
	for(size_t i = 0; i < pb->size - 1; i++){
		for(size_t j = 0; j < pb->size - i - 1; j++){
			const char *a = by_first ? pb->data[j].firstName : pb->data[j].lastName;
			const char *b = by_first ? pb->data[j+1].firstName : pb->data[j+1].lastName;
			if(strcasecmp(a, b) > 0){
				contact temp = pb->data[j];
				pb->data[j] = pb->data[j+1];
				pb->data[j+1] = temp;
				
			}
		}
	}
	puts("Contacts sorted alphabetically.");
}

void findContact(phoneBook *pb) {
    char findFirstName[16];
    char findLastName[16];
    
    printf("Enter first name of contact you are looking for: ");
    scanf("%15s", findFirstName);
    
    printf("Enter last name of contact you are looking for: ");
    scanf("%15s", findLastName);
    
	for (size_t i = 0; i < pb->size; i++) {
        if (strcmp(pb->data[i].firstName, findFirstName) == 0 && 
            strcmp(pb->data[i].lastName, findLastName) == 0) {
            printf("  Phone number: %s\n", pb->data[i].phoneNumber);
            return;
        }
    }
 }
    
void deleteAllContact(phoneBook *pb)
{
	if (pb->size == 0)
    {
        printf("Phone book is empty\n\n");
        return;
    }
    pb->size = 0;
    printf("All contacts deleted\n\n");
}

void randomContact(const phoneBook *pb)
{
	srand(time(NULL));
	if (pb->size == 0)
    {
        printf("Phone book is empty!\n\n");
        return;
    }
    int rng = rand() % pb->size;
    printf("\nCalling random number...\n");
        printf("  First Name: %s\n", pb->data[rng].firstName);
        printf("  Last Name: %s\n", pb->data[rng].lastName);
        printf("  Phone: %s\n\n", pb->data[rng].phoneNumber);
    }

void storeContact(const phoneBook *pb, const char *path)
{
	const char *filename =(path && *path) ? path : "contacts.txt";
	FILE *pF = fopen(filename, "w");
	
	if (pb->size == 0)
    {
        printf("Phone book is empty!\n\n");
        return;
    }
    fprintf(pF,"\nList of contacts:\n");
    for (size_t i = 0; i < pb->size; i++)
    {
        fprintf(pF,"Contact %zu:\n", i + 1);
        fprintf(pF,"  First Name: %s\n", pb->data[i].firstName);
        fprintf(pF,"  Last Name: %s\n", pb->data[i].lastName);
        fprintf(pF,"  Phone: %s\n\n", pb->data[i].phoneNumber);
    }
    fclose(pF);
    return;
}

void retrieveContact(const phoneBook *pb, const char *readPath)
{
	const char *readfile =(readPath && *readPath) ? readPath : "contacts.txt";
	FILE *rF = fopen(readfile, "r");
	char buffer[300];
	
	if(rF == NULL)
	{
		printf("File not found");
	}
	else
	{
		while(fgets(buffer, 300, rF) != NULL)
		{
			printf("%s", buffer);
		}
	}
	fclose(rF);
    return;
}

int main(void)
{
	phoneBook phoneBook;
	pb_init(&phoneBook);
	int choice = 0;
	
	do
	{
		printf("1. Add contact\n2. Delete contact\n3. Show phone book\n4. Sort phone book\n5. Find contact\n6. Delete all contacts\n7. Call random number\n8. Save contacts to file\n9. Load contacts from file\n10. Exit\n");
		scanf("%d", &choice);
		switch(choice)
		{
		case 1:
			addContact(&phoneBook);
			break;
		
		case 2:
			deleteContact(&phoneBook);
			break;
		
		case 3:
			showContact(&phoneBook);
			break;
		
		case 4:
			{
				int sortChoice;
	            printf("Sort by (1) First Name or (2) Last Name? ");
	            scanf("%d", &sortChoice);
	            sortContact(&phoneBook, sortChoice == 1);
            }
			break;
		
		case 5:
			findContact(&phoneBook);
			break;
		
		case 6:
			deleteAllContact(&phoneBook);
			break;	
		
		case 7:
			randomContact(&phoneBook);
			break;	
		
		case 8:
			{
				char path[50];
				printf("Enter name of the file you want to save to: ");
				scanf("%49s", path);
				storeContact(&phoneBook, path);
				break;
		}
		
		case 9:
			{
				char readPath[50];
				printf("Enter name of the file you want to load: ");
				scanf("%49s", readPath);
				retrieveContact(&phoneBook, readPath);
				break;
		}
			
		case 10:
            printf("Exiting...\n");
            break;
            
		default:
			puts("Invalid Choice.\n\n");
		}
	}while(choice != 10);
	pb_free(&phoneBook);
	return 0;
}