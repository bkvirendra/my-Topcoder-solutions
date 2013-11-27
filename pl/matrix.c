#include <stdio.h>

void accept(int a[10][10], int *r, int *c, char ch);
void display(int a[10][10], int *r, int *c, char ch);
void addition(int a[10][10], int b[10][10], int c[10][10], int rows, int cols);
void multiplication(int a[10][10], int b[10][10], int c[10][10], int rows, int cols);
void transpose(int a[10][10], int c[10][10], int rows, int cols);

void main() {
	int a[10][10], b[10][10], c[10][10], r1, c1, r2, c2, r3, c3, i, j, choice;

	do {

		printf("Please enter your choice:\n");
		printf("1) Accept \n2) Display \n3) Addition \n4) Multiplication \n5) Transpose\n6) Exit\n");
		scanf("%d", &choice);

		switch(choice) {
			case 1:
				accept(a, &r1, &c1, 'A');
				accept(b, &r2, &c2, 'B');
				break;
			case 2:
				display(a, &r1, &c1, 'A');
				display(b, &r2, &c2, 'B');
				break;
			case 3:
				if (r1 == r2 && c1 == c2) {
					r3 = r1;
					c3 = c1;
					addition(a, b, c, r2, c3);
					display(c, &r3, &c3, 'C');
				}
				break;
			case 4:
				if (r1 == c2) {
					r3 = r1;
					c3 = c2;

					multiplication(a, b, c, r1, c2);
					display(c, &r3, &c3, 'C');
				}
				break;
			case 5:
				transpose(a, c, r1, c1);
				display(c, &r1, &c1, 'C');
				break;
		}

	} while (choice!=6);

}

void accept(int a[10][10], int *r, int *c, char ch) {
	int i, j;

	printf("\nPlease enter values (rows, cols) for Matrix %c:\n", ch);
	scanf("%d %d", r, c);

	for(i=0; i<*r; i++) {
		for(j=0; j<*c; j++) {
			printf("Enter (%d %d) th value:\n", i, j);
			scanf("%d", &a[i][j]);
		}
	}

}

void display(int a[10][10], int *r, int *c, char ch) {
	int i, j;

	printf("\nMatrix %c of order (%d, %d):\n", ch, *r, *c);

	for(i = 0; i < *r; i++ ) {
		printf("\n");
		for (j = 0; j < *c; j++) {
			printf("%d\t", a[i][j]);
		}
	}

	printf("\n");
}

void addition(int a[10][10], int b[10][10], int c[10][10], int rows, int cols) {
	int i, j;

	for (i = 0; i < rows; i++) {
		for (j = 0; j < cols; j++) {
			c[i][j] = a[i][j] + b[i][j];
		}
	}

}

void multiplication(int a[10][10], int b[10][10], int c[10][10], int rows, int cols) {
	int i, j, k;

	for(i = 0; i < rows; i++) {
		for (j = 0; j < cols; j++) {
			c[i][j] = 0;

			for(k = 0; k < rows; k++) {
				c[i][j] = c[i][j] + (a[i][k] * b[k][j]);
			}
		}
	}

}

void transpose(int a[10][10], int c[10][10], int rows, int cols) {
	int i, j;

	for(i = 0; i < rows; i++) {
		for(j = 0; j < cols; j++) {
			c[i][j] = a[j][i];
		}
	}

}