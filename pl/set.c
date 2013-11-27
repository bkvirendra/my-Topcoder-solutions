#include <stdio.h>
#define MAX 30

void create_set(int set[]);
void print(int set[]);
void Union(int set1[], int set2[], int set3[]);
int member(int set[], int x);
void intersection(int set1[], int set2[], int set3[]);
void difference(int set1[], int set2[], int set3[]);
void symmetric_difference(int set1[], int set2[], int set3[]);


void main() {
	int set1[MAX], set2[MAX], set3[MAX], op;
	set1[0] = set2[0] = set3[0] = 0;
	do {
		printf("Enter your choice:\n");
		printf("1) Create sets\n2) Print set\n3) Union of set\n4) Intersection of set\n5) Difference\n6) Symmetric difference\n7) Exit\n");
		scanf("%d", &op);
		switch(op) {
			case 1:
				printf("Creating 1st set:\n");
				create_set(set1);
				printf("Creating 2nd set:\n");
				create_set(set2);
				break;
			case 2:
				printf("Printing set 1:\n");
				print(set1);
				printf("Printing set 2:\n");
				print(set2);
				printf("Printing set 3:\n");
				print(set3);
				break;
			case 3:
				Union(set1, set2, set3);
				break;
			case 4:
				intersection(set1, set2, set3);
				break;
			case 5:
				difference(set1, set2, set3);
				break;
			case 6:
				symmetric_difference(set1, set2, set3);
				break;
		}
	} while(op!=7);
}

void create_set(int set[]) {
	int i, n;
	printf("Enter the no. of elements in set:\n");
	scanf("%d", &n);
	set[0] = n;
	for(i=1;i<=n;i++) {
		printf("Enter the %d th element of set\n", i);
		scanf("%d", &set[i]);
	}
}

void print(int set[]) {
	int i, n;
	n = set[0];
	for(i=1;i<=n;i++) {
		printf("%d th element of set:\t %d\n", i, set[i]);
	}
}

void Union(int set1[], int set2[], int set3[]) {
	int i, n;
	n = set1[0];
	for(i=1;i<=n;i++) {
		set3[i] = set1[i];
	}

	set3[0] = n;

	n = set2[0];
	for(i=1;i<=n;i++) {
		if(member(set3, set2[i]) == -1) {
			set3[++set3[0]] = set2[i];
		}
	}
}

int member(int set[], int x) {
	int i, n;
	n = set[0];
	for(i=1;i<=n;i++) {
		if(set[i] == x) {
			return(1);
		}
	}
	return(-1);
}

void intersection(int set1[], int set2[], int set3[]) {
	int i, n;
	set3[0] = 0;
	n = set1[0];

	for(i=1;i<=n;i++) {
		if(member(set2, set1[i]) == 1) {
			set3[++set3[0]] = set1[i];
		}
	}
}

void difference(int set1[], int set2[], int set3[]) {
	int i, n;
	set3[0] = 0;
	n = set1[0];

	for(i=1;i<=n;i++) {
		if(member(set2, set1[i]) == -1) {
			set3[++set3[0]] = set1[i];
		}
	}
}

void symmetric_difference(int set1[], int set2[], int set3[]) {
	int i, n;
	set3[0] = 0;
	n = set1[0];

	for(i=1;i<=n;i++) {
		if(member(set2, set1[i]) == -1) {
			set3[++set3[0]] = set1[i];
		}
	}

	n = set2[0];

	for(i=1;i<=n;i++) {
		if(member(set1, set2[i]) == -1) {
			set3[++set3[0]] = set2[i];
		}
	}

}
