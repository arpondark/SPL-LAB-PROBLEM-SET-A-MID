#include <stdio.h>

#define max 10
void add(char names[][50], int roll[], float marks[], int *count)   //code by arpon //github.com/arpondark
{
    if (*count < max)
    {
        printf("Enter Name Of the Student: ");
        scanf("%s", &names[*count]);
        printf("Enter Roll Number: ");
        scanf("%d", &roll[*count]);
        printf("Enter the Marks: ");
        scanf("%f", &marks[*count]);
        (*count)++;
    }
    else
    {
        printf("No student fond!!\n");
    }
}

void display(char names[][50], int roll[], float marks[], int count)
{
    for (int i = 0; i < count; i++)
    {
        printf("Name: %s, Roll Number: %d, Marks: %.2f\n", names[i], roll[i], marks[i]);
    }
}

void search(char names[][50], int roll[], float marks[], int count)
{
    int r, found = 0;
    printf("Enter Roll Number To search: ");
    scanf("%d", &r);
    for (int i = 0; i < count; i++)
    {
        if (roll[i] == r)
        {
            printf("Student found: Name: %s, Roll Number: %d, Marks: %.2f\n", names[i], roll[i], marks[i]);
            found = 1;
            break;
        }
    }
    if (!found)
    {
        printf("Student Not found !!!! \n");
    }
}

void avg(float marks[], int count)

{
    float sum = 0;
    for (int i = 0; i < count; i++)
    {
        sum += marks[i];
    }
    printf("Average marks of the class: %.2f\n", sum / count);
}

void hi(char names[][50], int roll[], float marks[], int count)

{
    int index = 0;
    for (int i = 1; i < count; i++)
    {
        if (marks[i] > marks[index])
        {
            index = i;
        }
    }
    printf("Student with highest marks: Name: %s, Roll Number: %d, Marks: %.2f\n", names[index], roll[index], marks[index]);
}
int main()
{
    char names[max][50];
    int roll[max];
    float marks[max];
    int count = 0;
    int choice;

    do
    {
        printf("\n--- Student Management System --- \t\t --Code By ARPON-- \n");
        printf("1. Add Students\n");
        printf("2. Display All Students\n");
        printf("3. Search for a Student\n");
        printf("4. Calculate Average Marks\n");
        printf("5. Find Student with Highest Marks\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            add(names, roll, marks, &count);
            break;
        case 2:
            display(names, roll, marks, count);
            break;
        case 3:
            search(names, roll, marks, count);
            break;
        case 4:
            avg(marks, count);
            break;
        case 5:
            hi(names, roll, marks, count);
            break;
        case 6:
            printf("Exiting the program...\n");
            break;
        default:
            printf("Invalid choice. Please try again.\t\t Code By ARPON\n");
        }
    } while (choice != 6);

    return 0;
}