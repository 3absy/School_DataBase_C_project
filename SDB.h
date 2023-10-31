#ifndef SDB_H_INCLUDED
#define SDB_H_INCLUDED
#include "STD.h"

// Functions declarations
void SDB_APP ();
void SDB_action (uint8 choice);
bool SDB_IsFull ();
uint8 SDB_GetUsedSize();
bool SDB_AddEntry();
void SDB_DeletEntry (uint32 id);
bool SDB_ReadEntry (uint32 id);
void SDB_GetList (void);
bool SDB_IsIdExist (uint32 id);



// Define a struct to represent a student.
typedef struct SimpleDb
{
    uint32 Student_ID;
    uint32 Student_year;
    uint32 Course1_ID;
    uint32 Course1_grade;
    uint32 Course2_ID;
    uint32 Course2_grade;
    uint32 Course3_ID;
    uint32 Course3_grade;

} student;


// External variables
extern student DataBase[];
extern uint8 i;
extern uint16 counter;
extern uint16 Index;


#endif // SDB_H_INCLUDED
