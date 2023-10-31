#include <stdio.h>
#include <stdlib.h>
#include "SDB.h"
#include "STD.h"

// Function to handle the main application logic.
void SDB_APP ()
{
    while(1)
    {
        int32 choice;
        // Display a menu for user choices.

        printf("1.To add entry, enter 1.\n2.To get used size in database, enter 2.\n3.To read student data, enter 3.\n");
        printf("4.To get the list of all student IDs, enter 4.\n5.To check if ID exists, enter 5.\n6.To delete student data, enter 6.\n");
        printf("7.To check is database is full, enter 7.\n8. To clear the screen enter 8.\n9. To Exit, enter 0.\n");
        printf("\nChoose the desired operation : ");
        scanf("%d",&choice);

        // Call the SDB_action function based on the user's choice.
        SDB_action(choice);
    }
}

// Function to do what the user chose.
void SDB_action (uint8 choice)
{
    int32 ID;

    switch (choice)
    {
    case 0:
        // Exit the program.
        system("cls");// To clear the screen.
        exit(0);
        break;


    case 1:
        // Add a new student to the database and say if it was successful or not, if not say why.
        if (SDB_AddEntry()) printf("\nData is entered successfully.\n\n");
        else
        {
            if(SDB_IsFull()) printf("\nDatabase is full.\n\n");
            else printf("\nId already exists.\n\n");
        }
        break;


    case 2:
        // Display the number of students in the database.
        printf("\nNumber of students : %d.\n\n",SDB_GetUsedSize());
        break;


    case 3:
        if(counter==0)
        {
            printf("\nThere are no students yet.\n\n");
            break;
        }
        // The user enter the ID he wants to know it's holder's data.
        printf("\nEnter the ID :");
        scanf("%d",&ID);

        if (SDB_ReadEntry(ID))
        {
            //Print the holder's data.
            printf("\nThe student's ID : %d.\n",DataBase[i].Student_ID);
            printf("The student's year : %d.\n",DataBase[i].Student_year);
            printf("The student's course 1 ID : %d.\n",DataBase[i].Course1_ID);
            printf("The student's course 1 grade : %d.\n",DataBase[i].Course1_grade);
            printf("The student's course 2 ID : %d.\n",DataBase[i].Course2_ID);
            printf("The student's course 2 grade : %d.\n",DataBase[i].Course2_grade);
            printf("The student's course 3 ID : %d.\n",DataBase[i].Course3_ID);
            printf("The student's course 3 grade : %d.\n\n",DataBase[i].Course3_grade);

        }
        else printf("\nID does not exist.\n\n");
        break;


    case 4:
        if(counter==0) printf("\nThere are no students yet.\n\n");
        else SDB_GetList(); // Display all student's data.
        break;


    case 5:
        if(counter==0)
        {
            printf("\nThere are no students yet.\n\n");
            break;
        }
        printf("\nEnter the ID : ");
        scanf("%d",&ID);
        // Check if the entered ID exists in the database.
        if(SDB_IsIdExist(ID)) printf("\nID exists.\n\n");
        else printf("\nID does not exist.\n\n");
        break;


    case 6:
        if(counter==0) printf("\nThere are no students.\n\n");
        else if(counter==3) printf("\nMinimum number of students reached.\n\n");
        else
        {
            printf("\nEnter the ID : ");
            scanf("%d",&ID);

            if(SDB_IsIdExist(ID))// Check if the entered ID exists.
            {
                // Delete the data of student holding this ID.
                SDB_DeletEntry(ID);
                printf("\nStudent holding the ID has been deleted.\n\n");
            }
            else
            {
                printf("\nID does not exist.\n\n");
            }
        }
        break;


    case 7:
        // Check if the database is full.
        if(SDB_IsFull()) printf("\nDatabase is full.\n\n");
        else printf("\nDatabase is not full.\n\n");
        break;


    case 8:
        system("cls"); // To clear the screen.
        break;


    default:
        // The user entered a number not in the list of options.
        printf("\nInvalid entry.\n\n");
        break;
    }
}
