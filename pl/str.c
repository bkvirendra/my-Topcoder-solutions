#include <stdio.h>
#define MAX 100

void accept(char s[]);
void display(char s[]);
int mystrlen(char s[]);
void mystrcpy(char s[], char d[]);
int palindrome(char s[]);
int mystrcmp(char s[], char b[]);
void mysubstring(char source[], char s[]);
void mystrrev(char s[]);
void mystrcat(char s[], char d[]);

void main() {
	char s[MAX], d[MAX];
	int choice, n, r;

	do {
		printf("Please enter your choice:\n");
		printf("1)Accept \n2)Display \n3)String length \n4)String copy \n5)Check palindrome \n6)String cmp \n7)String substring \n8)String reverse \n9)String concat \n10)Exit\n");
		scanf("%d", &choice);

		switch(choice) {
			case 1: // accept
				printf("\nInput src string:\n");
				accept(s);
				printf("\nInput dest string:\n");
				accept(d);
				break;
			case 2: // display
				display(s);
				break;
			case 3: // string len
				n = mystrlen(s);
				printf("String length is %d\n", n);
				break;
			case 4: // copy str
				mystrcpy(s, d);
				printf("\nString copied successfully!\n");
				display(d);
				break;
			case 5: // check palindrome
				r = palindrome(s);
				if (r == 1) {
					printf("\nString is a palindrome!\n");
				} else {
					printf("\nString is not a palindrome!\n");
				}
				break;
			case 6: // str cmp
				r = mystrcmp(s, d);
				if(r == 0) {
					printf("\nStrings are equal!\n");
				} else {
					printf("\nString are not equal!\n");
				}
				break;
			case 7: // substring
				mysubstring(s, d);
				break;
			case 9: // str concat
				mystrcat(s, d);
				printf("\nStr successfully concat!\n");
				display(d);
				break;
		}
	} while(choice!=10);

}

void accept(char s[]) {
	printf("Enter your string:\n");
	scanf("%s", s);
}

void display(char s[]) {
	printf("%s\n", s);
}

int mystrlen(char s[]) {
	int i, n = 0;
	for(i=0;s[i]!='\0';i++) {
		n++;
	}
	return(n);
}

void mystrcpy(char s[], char d[]) {
	int i, n;
	n = mystrlen(s);
	for(i=0;i<n;i++) {
		d[i] = s[i];
	}
	d[i] = '\0';
}

void mystrcat(char s[], char d[]) {
	int l, i, n;
	l = mystrlen(d);

	for(i=0;i<l;i++) {
		d[l + i] = s[i];
	}

	d[l + i] = '\0';
}

int palindrome(char s[]) {
	int i, n;

	n = mystrlen(s) - 1;

	for(i=0;i<n;i++) {
		if(s[i] != s[n]) {
			return(-1);
		}
		n--;
	}
	return(1);
}

int mystrcmp(char s[], char d[]) {
	int i, n, diff;

	for(i=0; s[i]!='\0', d[i]!='\0';i++) {
		if(s[i] != d[i]) {
			return(-1);
		}
	}

	return(0);
}

void mysubstring(char s[], char d[]) {
	int i, j, l1, l2, count = 0;

	l1 = mystrlen(s);
	l2 = mystrlen(d);

	for(i=0;i<(l1 - l2);i++) {
		for(j=0;j<l2;j++) {
			if(s[i + j] != d[j]) {
				break;
			}
		}

		if(j == l2) {
			count++;
		}

	}

	printf("\nThe occurances are %d\n", count);
}