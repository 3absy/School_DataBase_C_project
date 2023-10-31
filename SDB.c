#include "STD.h"
#include "SDB.h"
#include<stdio.h>
#include <stdlib.h>
#define Max_DB 10 // Define the maximum size of the database.


student DataBase[Max_DB];// Declare an array to my struct to store the students data in.

uint16 counter=0;// Initialize a counter for the number students in database.
uint16 Index=0;// Initialize an index that keeps track of the student's number whose data is being scanned or printed.
uint8 i;// Declare a counter variable.


// Function to check if the database is full.
bool SDB_IsFull (void)
{
    if(counter==10) return true;
    else return false;
}

// Function to get the number of students in the database.
uint8 SDB_GetUsedSize(void)
{
    return counter;
}

// Function to add a student to the database.
bool SDB_AddEntry(void)
{
    if(SDB_IsFull()) return false;
    else if(counter==0)
    {
        printf("\nPlease enter data of 3 students.\n");// The minimum allowed number of students in database is 3.
        for(i=0; i<3; i++)
        {
            Index++;

there:// If the user enter an already existent ID the code is repeated from here.

            printf("\nEnter the #%d student's ID : ",Index);
            scanf(" %d",&DataBase[i].Student_ID);
            if(SDB_IsIdExist(DataBase[i].Student_ID))
            {
                i=counter; // set i to a value so it does not get affected by i in other functions.
                // If Id already exists enter it again.
                printf("\nID already exists try again.\n");
                goto there;// Go to the place of the word "there" to enter the ID again.
            }

            // If the entered ID is OK enter the rest of the data.
            printf("Enter the #%d student's year : ",Index);
            scanf("%d",&DataBase[i].Student_year);
            printf("Enter the #%d student's course 1 ID : ",Index);
            scanf("%d",&DataBase[i].Course1_ID);
            printf("Enter the #%d student's course 1 grade : ",Index);
            scanf("%d",&DataBase[i].Course1_grade);
            printf("Enter the #%d student's course 2 ID : ",Index);
            scanf("%d",&DataBase[i].Course2_ID);
            printf("Enter the #%d student's course 2 grade : ",Index);
            scanf("%d",&DataBase[i].Course2_grade);
            printf("Enter the #%d student's course 3 ID : ",Index);
            scanf("%d",&DataBase[i].Course3_ID);
            printf("Enter the #%d student's course 3 grade : ",Index);
            scanf("%d",&DataBase[i].Course3_grade);

            counter ++;// Increase number of students by one.
        }
        return true;
    }
    else
    {
        Index++;
        i=counter;// Set i to a value so it does not get affected by i in other functions.

        printf("\nEnter the #%d student's ID : ",Index);
        scanf("%d",&DataBase[i].Student_ID);
        if(SDB_IsIdExist(DataBase[i].Student_ID))
        {
            i=counter;// Set i to a value so it does not get affected by i in other functions.
            DataBase[i].Student_ID=-1;// If the entered Id already exists, delete it.
            Index--;
            return false;
        }
        // If the entered ID is OK enter the rest of the data.
        printf("Enter the #%d student's year : ",Index);
        scanf("%d",&DataBase[i].Student_year);
        printf("Enter the #%d student's course 1 ID : ",Index);
        scanf("%d",&DataBase[i].Course1_ID);
        printf("Enter the #%d student's course 1 grade : ",Index);
        scanf("%d",&DataBase[i].Course1_grade);
        printf("Enter the #%d student's course 2 ID : ",Index);
        scanf("%d",&DataBase[i].Course2_ID);
        printf("Enter the #%d student's course 2 grade : ",Index);
        scanf("%d",&DataBase[i].Course2_grade);
        printf("Enter the #%d student's course 3 ID : ",Index);
        scanf("%d",&DataBase[i].Course3_ID);
        printf("Enter the #%d student's course 3 grade : ",Index);
        scanf("%d",&DataBase[i].Course3_grade);


        counter++;
        return true;
    }

}

// Function to delete a student from the database based on the ID entered by the user.
void SDB_DeletEntry (uint32 id)
{
    for(i=0; i<counter; i++)
    {
        if(DataBase[i].Student_ID==id)
        {

            for(; i<counter; i++)
            {
                DataBase[i]=DataBase[i+1];
            }
            break;
        }
    }
    // Set the deleted data to invalid values.
    DataBase[i].Student_ID=-1;
    DataBase[i].Student_year=-1;
    DataBase[i].Course1_ID=-1;
    DataBase[i].Course1_grade=-1;
    DataBase[i].Course2_ID=-1;
    DataBase[i].Course2_grade=-1;
    DataBase[i].Course3_ID=-1;
    DataBase[i].Course3_grade=-1;

    counter--;// Update counters.
    Index--;
}

// Function to read the data from the database based on entered ID.
bool SDB_ReadEntry (uint32 id)
{
    for(i=0; i<counter; i++)
    {
        // Search for the entered ID and return true if found.
        if(id == DataBase[i].Student_ID)
        {
            return true;
        }
    }

    return false;
}

// Function to get the list of data of all the students in the database.
void SDB_GetList (void)
{
    Index=0;

    for(i=0; i<counter; i++)
    {
        Index++;

        printf("\nThe #%d student's ID : %d.\n\n",Index,DataBase[i].Student_ID);
    }

}

// Function to check if the entered ID exists in the database.
bool SDB_IsIdExist (uint32 id)
{

    for(i=0; i<counter; i++)
    {
        if(id == DataBase[i].Student_ID) return true;
    }

    return false;
}
