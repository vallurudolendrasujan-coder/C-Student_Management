#include <stdio.h>
#include <string.h>

struct Student {
    int id;
    char name[50];
    int age;
};

struct Student s[100];
int count = 0;

void addStudent() {
    printf("\nEnter student ID: ");
    scanf("%d", &s[count].id);

    printf("Enter student Name (no spaces allowed): ");
    scanf("%s", s[count].name);

    printf("Enter student Age: ");
    scanf("%d", &s[count].age);

    count++;
    printf("Student added successfully....\n");
}

void viewStudents() {
    if(count == 0) {
        printf("No students found.\n");
        return;
    }

    printf("\nID\tName\tAge\n");
    for(int i=0;i<count;i++) {
        printf("%d\t%s\t%d\n", s[i].id, s[i].name, s[i].age);
    }
}

void updateStudent() {
    int id, found=0;

    printf("Enter student ID to update: ");
    scanf("%d",&id);

    for(int i=0;i<count;i++) {
        if(s[i].id == id) {
            printf("Enter new Name: ");
            scanf("%s", s[i].name);

            printf("Enter new Age: ");
            scanf("%d", &s[i].age);

            printf("Student updated successfully.\n");
            found=1;
            break;
        }
    }

    if(!found)
        printf("Student not found.\n");
}

void deleteStudent() {
    int id, found=0;

    printf("Enter student ID to delete: ");
    scanf("%d",&id);

    for(int i=0;i<count;i++) {
        if(s[i].id == id) {
            for(int j=i;j<count-1;j++) {
                s[j]=s[j+1];
            }
            count--;
            printf("Student deleted successfully.\n");
            found=1;
            break;
        }
    }

    if(!found)
        printf("Student not found.\n");
}

int main() {
    int choice;

    while(1) {
        printf("\n--- Student Management System ---\n");
        printf("1. Add Student\n");
        printf("2. View Students\n");
        printf("3. Update Student\n");
        printf("4. Delete Student\n");
        printf("5. Exit\n");

        printf("Choose an option: ");
        scanf("%d",&choice);

        switch(choice) {
            case 1: addStudent(); break;
            case 2: viewStudents(); break;
            case 3: updateStudent(); break;
            case 4: deleteStudent(); break;
            case 5: return 0;
            default: printf("Invalid choice\n");
        }
    }
}
