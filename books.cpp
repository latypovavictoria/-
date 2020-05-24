#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <Windows.h>
#include <stdlib.h>
typedef struct books book1;
struct books {
	char num[20];
	char ath[60];
	char name[60];
	int q;
	int qs;
};
book1 books[1000];
void delbook(const char* file);
int readb(const char* file) {
	FILE* book = fopen(file, "r+");
	if (!book)
		return -1;
	rewind(book);
	char str[1000];
	int i = 0;
	while (fgets(str,1000, book))
	{
		fscanf(book, "%[^;];%[^;];%[^;];%d;%d", books[i].num, books[i].ath, books[i].name, &books[i].q, &books[i].qs);
		i++;
	}
	return i;
}
int similar(char num[20])
{
	int i;
	int temp = -1;
	for (i = 0; i < readb("books.csv"); i++)
		if (strcmp(num, books[i].num) == 0)
			temp = i;
	return temp;
}
int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	FILE* book;
	struct books elem;
	book = fopen("books.csv", "r");
	char file[5000];
	while (fgets(file, 5000, book) != NULL) {
		printf("%s", file);
	}
	fclose(book);
	char add;
	printf("\nВыберете операцию:\n");
	printf("**********Чтобы добавить, нажмите A**********\n");
	printf("**********Чтобы удалить, нажмите D***********\n");
	printf("**********Чтобы забрать/выдать, нажмите G****\n");
	printf("**********Чтобы выйти, нажмите E*************\n");
	scanf("%c", &add);
	if(add=='A') {
		book = fopen("books.csv", "a+");
		printf("Введите ISBN:");
		fflush(stdin);
		//char num[20];
		scanf("%s",elem.num);
		if (similar(elem.num) != -1)
		{
			printf("Такой ISBN ужу есть!\n");
			fclose(book);
		}
		else {
			printf("Введите автора:");
			scanf("%s", elem.ath);
			printf("Введите название:");
			scanf("%s", elem.name);
			printf("Введите количество:");
			scanf("%d", &elem.q);
			printf("Введите количество доступных книг:");
			scanf("%d", &elem.qs);
			book = fopen("books.csv", "a+");
			fprintf(book, "%s;%s;%s;%d;%d\n", elem.num, elem.ath, elem.name, elem.q, elem.qs);
			fclose(book);
		}
	}
	if (add == 'D') {
		delbook("books.csv");
	}
	if (add == 'G') {
		printf("\nВведите ISBN:");
		scanf("%s", elem.num);
		book = fopen("books.csv", "r");
		rewind(book);
		int getfile = similar(elem.num);
		int getfile1 = readb("books.csv");
		fclose(book);
		if (getfile != -1)
		{
		 printf("Введите автора:");
			scanf("%s",elem.ath);
			printf("Введите название:");
			scanf("%s",elem.name);
			printf("Количество книг:");
			scanf("%d", &elem.q);
			printf("Количество доступных книг:");
			scanf("%d", &elem.qs);
			book = fopen("books.csv", "w");
			int i;
			for (i = 0; i < getfile1; i++)
			{
				if (i != getfile)
					fprintf(book, "%s;%s;%s;%d;%d\n", books[i].num, books[i].ath, books[i].name, books[i].q, books[i].qs);
			}
			int n;
			printf("1-уменьшить; 2-увеличить");
			scanf("%d", &n);
			if (n == 2) {
				if (elem.qs < elem.q)
					fprintf(book, "%s;%s;%s;%d;%d\n", elem.num, elem.ath, elem.name, elem.q, elem.qs + 1);
				else printf("Нечего забирать!");
			}
			else if (n == 1) {
				if (elem.qs > 1)
					fprintf(book, "%s;%s;%s;%d;%d\n", elem.num, elem.ath, elem.name, elem.q, elem.qs - 1);
				else printf("Недостаточно книг");
			}
			fclose(book);
		}
		else
			printf("\nНет такого ISBN!\n ");
	}
	if (add == 'E') {
		exit(0);
	}
}
void delbook(const char* file)
{
	FILE* book;
	char dnum[20];
	printf("Введите ISBN:");
	fflush(stdin);
	scanf("%s",dnum );

	book = fopen(file, "r");
	rewind(book);
	int getfile = similar(dnum);
	int getfile1 = readb(file);
	fclose(book);
	if (getfile != -1)
	{
		book = fopen("books.csv", "w");
		int i;
		for (i = 0; i < getfile1; i++)
		{
			if (i != getfile)
				fprintf(book, "%s;%s;%s;%d;%d\n", books[i].num, books[i].ath, books[i].name, books[i].q, books[i].qs);
		}
		fclose(book);
		printf("\nКнига удалена!");
	}
	else
		printf("\nНет такого ISBN\n");
}
