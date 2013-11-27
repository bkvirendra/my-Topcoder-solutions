#include <stdio.h>
#define MAX 30

typedef struct student {
	int roll_no;
	char name[MAX];
	int marks;
} stud;

int accept(stud a[]) {
	int i, n;
	printf("Please enter the no. of records:\n");
	scanf("%d", &n);

	for (i = 1; i <= n; i++) {
		printf("Enter the name, roll_no, marks for student %d\n", i);
		scanf("%s %d %d", a[i].name, &a[i].roll_no, &a[i].marks);
	}

    return(n);
}

void display(stud students[], int n) {
	int i;

	for(i=1; i<=n; i++) {
		printf("\n\nRecord for student no. %d:\n", i);
		printf("Name: %s\n", students[i].name);
		printf("Roll no. %d\n", students[i].roll_no);
		printf("Marks: %d\n\n", students[i].marks);
	}
}

int search(stud students[], int n, int key) {
	int i;
	for(i=1; i<=n; i++) {
		if (key == students[i].roll_no) {
			return(i);
		}
	}
	return(-1);
}

void search_db(stud students[], int n) {
	int key, i;

	printf("Enter the roll no. to be searched:\n");
	scanf("%d", &key);

	i = search(students, n, key);

	if(i != -1) {
		printf("The record was found at position: %d\n", i);
		printf("The details of the records are:\n");
		printf("Record for student no. %d:\n", i);
		printf("Name: %s\n", students[i].name);
		printf("Roll no. %d\n", students[i].roll_no);
		printf("Marks: %d\n", students[i].marks);
	} else {
		printf("\n***Record was not found for Roll no. %d!\n\n", key);
	}

}

void modify_db(stud students[], int n) {
	int key, i;

	printf("Enter the roll no. to be modified:\n");
	scanf("%d", &key);

	i = search(students, n, key);

	if(i != -1) {
		printf("The record was found at position: %d\n", i);
		printf("Enter the new details for the record, (name, roll_no, marks)\n");
		scanf("%s %d %d", students[i].name, &students[i].roll_no, &students[i].marks);
		printf("\nRecord was successfully updated!\n");
	} else {
		printf("\n***Record was not found for Roll no. %d, hence cannot be modified!\n\n", key);
	}
}

void delete_db(stud students[], int *n) {
	int key, i, j;

	printf("Enter the roll no. to be deleted:\n");
	scanf("%d", &key);

	i = search(students, *n, key);

	if(i != -1) {
		printf("The record was found at position: %d\n", i);
		for(j=i;j<*n-1;j++) {
			students[j] = students[j + 1];
		}
		*n = *n - 1;
		printf("\nThe record was successfully deleted!\n");
	} else {
		printf("\n***Record was not found for Roll no. %d, hence cannot be deleted!\n\n", key);
	}
}

void insert_db(stud students[], int *n) {
	int i, pos;
	stud B;

	printf("Enter the position where the record needs to be inserted (1 to %d):\n", *n);
	scanf("%d", &pos);

	if(*n == MAX) {
		printf("database is full!\n");
	} else {
		printf("Enter the new details for the record, (name, roll_no, marks)\n");
		scanf("%s %d %d", B.name, &B.roll_no, &B.marks);

		for(i=*n;i>=pos;i--) {
			students[i + 1] = students[i];
		}
		students[pos] = B;
		*n = *n + 1;

		printf("\nRecord successfully inserted at position %d!\n", pos);
	}
}

void main() {
	stud a[MAX];
	int na, choice = 0;

	do {
		printf("Enter your choice:\n");
		printf("1)Accept \n2)Display \n3)Search DB \n4)Modify DB \n5)Delete from DB \n6)Insert to DB \n7)Exit\n");
		scanf("%d", &choice);
		switch(choice) {
			case 1: // accept
				na = accept(a);
				break;
			case 2: // display
				display(a, na);
				break;
			case 3: // search
				search_db(a, na);
				break;
			case 4: // modify record
				modify_db(a, na);
				break;
			case 5: // delete record
				delete_db(a, &na);
				break;
			case 6: // insert record
				insert_db(a, &na);
				break;
		}
	} while (choice!=7);
	printf("\nExiting...\n");

}
