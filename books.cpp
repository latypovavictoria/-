
#define _CRT_SECURE_NO_WARNINGS
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <malloc.h>
#include <locale.h>
#include <ctime>
typedef struct books book1;
struct books {
	char num[20];
	char ath[60];
	char name[60];
	int q;
	int qs;
};
book1 books[1000];
typedef struct students students1;
 struct students {
	char booknum[20];
	char surname[30];
	char name[30];
	char patr[40];
	char fac[5];
	char depart[40];
};
students1 students[1000];
struct stbooks {
	char time[20];
};
stbooks stdbooks[100];
void bookf(FILE *book);
int readb(const char* file);
int readb1(const char* file);
int similar(char num[20]);
void delbook1(const char* filename);
int similar1(char num[20]);
int similar2(char booknum[15]);
int similar3(char booknum[15]);
void studentsf(FILE* stdents);
void delstudent(const char* filename);
int readb3(const char* file);
int readb4(const char* file);
int similarst(char surname[40])
{
	int i;
	int temp = -1;
	for (i = 0; i < readb1("students.csv"); i++)
		if (strcmp(surname, students[i].surname) == 0)
			temp = i;
	return temp;
}
void searchst1(const char* filename) {
	char surname[60];
	int i = 0;
	char file[5000];
	FILE* stdents;
	printf("Введите фамилию:");
	scanf("%s", surname);
	fflush(stdin);
	stdents = fopen(filename, "r+");
	{rewind(stdents);
	while (fgets(file, 5000, stdents))
	{
		fscanf(stdents, "%[^;];%[^;];%[^;];%[^;];%[^;];[^;];[^;]", students[i].booknum, students[i].surname, students[i].name, students[i].patr, students[i].fac, students[i].depart);
		i++;
	}
	int n = 0;
	int k[61];
	int j = 0;
	for (; j <= i; j++)
	{
		if (strcmp(surname, students[j].surname) == 0)
			k[j] = j;
		else
			k[j] = -1;
	}
	fclose(stdents);
	for (j = 0; j <= i; j++) {
		if (k[j] != -1)
		{
			printf("%s;%s;%s;%s;%s;%s\n", students[j].booknum, students[j].surname, students[j].name, students[j].patr, students[j].fac, students[j].depart);
			n = 1;
		}
	}
	if (n == 0)
	{
		printf("Нет студентов с такой фамилией!\n");
	}
	}
}
void searchb(const char* filename) {
	char num[20];
	int i = 0;
	char file[5000];
	FILE* stubooks;
	printf("Введите ISBN:");
	scanf("%s", num);
	fflush(stdin);
	stubooks = fopen(filename, "r+");
	{rewind(stubooks);
	while (fgets(file, 5000, stubooks))
	{
		fscanf(stubooks, "%[^;];%[^;];%[^;]", books[i].num, students[i].booknum, stdbooks[i].time);
		i++;
	}
	int n = 0;
	int k[21];
	int j = 0;
	for (; j <= i; j++)
	{
		if (strcmp(num, books[j].num) == 0)
			k[j] = j;
		else
			k[j] = -1;
	}
	fclose(stubooks);
	for (j = 0; j <= i; j++) {
		if (k[j] != -1)
		{
			printf("%s;%s;%s\n", books[j].num, students[j].booknum, stdbooks[j].time);
			n = 1;
		}
	}
	if (n == 0)
	{
		printf("Нет книг с таким ISBN!\n");
	}
	}
}
char state;
char status;
char c[2];
int m;
int count = 0;
int Mainstudents();
int Mainbook();
char* writestr(char str[]);
char* writestr(char str[]) {
	int c, i = 0;
	while ((c = getchar()) != EOF && c != '\n') {
		str[i++] = c;
	}
	str[i] = '\0';
	return str;
}

int Mainbook() {
	printf("**********Книжное меню**********\n\n");
	printf("(1) Добавить новую книгу\n");
	printf("(2) Удалить книгу\n");
	printf("(3) Редактировать информацию по книге\n");
	printf("(4) Выдача/сдача книг\n");
	printf("(5) Просмотреть информацию по книгам\n");
	printf("(0) Выйти\n");
	FILE* book;
	book = fopen("books.csv", "r");
	bookf(book);
	fclose(book);
	return 1;
}

int Mainstudents() {
	printf("\n***********Студентчeское меню***********\n\n");
	printf("(1) Добавить нового студента\n");
	printf("(2) Удалить студента\n");
	printf("(3) Редактировать информацию по студенту\n");
	printf("(4) Поиск студентов\n");
	printf("(5) Выдача книг/сдача\n");
	printf("(6) Сохранение файла\n");
	printf("(7) Восстановление данных\n");
	printf("(0) Выйти\n");
	FILE* stdents;
		stdents = fopen("students.csv", "r");
		studentsf(stdents);
		fclose(stdents);
		return 2;
}
int readb(const char* file) {
	FILE* book = fopen(file, "r+");
	if (!book)
		return -1;
	rewind(book);
	char str[1000];
	int i = 0;
	while (fgets(str, 1000, book))
	{
		fscanf(book, "%[^;];%[^;];%[^;];%d;%d", books[i].num, books[i].ath, books[i].name, &books[i].q, &books[i].qs);
		i++;
	}
	return i;
}
int readb1(const char* file) {
	FILE* stdents = fopen(file, "r+");
	if (!stdents)
		return -1;
	rewind(stdents);
	char str[1000];
	int i = 0;
	while (fgets(str, 1000, stdents)) {
		fscanf(stdents, "%[^;];%[^;];%[^;];%[^;];%[^;];%[^;]", students[i].booknum, students[i].surname, students[i].name, students[i].patr, students[i].fac, students[i].depart);
		i++;
	}
	return i;
}
int similar(char num[20])
{
	int i;
	int temp = -1;
	for (i = 0; i < readb("books.csv"); ++i)
		if (strcmp(num, books[i].num) == 0)
			temp = i;
	return temp;
}
int similar1(char num[20])
{
	int i, j;
	int temp = -1;
	for (i = 0; i < readb4("student_books.csv"); i++)
		if (strcmp(num, books[i].num) == 0)
			temp = i;
	temp = i;
	return temp;
}
int similar2(char booknum[15])
{
	int i;
	int temp = -1;
	for (i = 0; i < readb1("students.csv"); i++)
		if (strcmp(booknum, students[i].booknum) == 0)
			temp = i;
	return temp;
}
int similar3(char booknum[15])
{
	int i, j;
	int temp = -1;
	for (i = 0; i < readb3("student_books.csv"); i++)
		if (strcmp(booknum, students[i].booknum) == 0)
			temp = i;
	return temp;
}
int readb3(const char* file) {
	FILE* stubooks = fopen(file, "r+");
	if (!stubooks)
		return -1;
	rewind(stubooks);
	char str[1000];
	int i = 0;
	while (fgets(str, 1000, stubooks)) {
		fscanf(stubooks, "%[^;];%[^;];%[^;]", books[i].num, students[i].booknum, stdbooks[i].time);
		i++;
	}
	return i;
}
int readb4(const char* file) {
	FILE* stubooks = fopen(file, "r+");
	if (!stubooks)
		return -1;
	rewind(stubooks);
	char str[1000];
	int i = 0;
	while (fgets(str, 1000, stubooks)) {
		fscanf(stubooks, "%[^;];%[^;];%[^;]", books[i].num, students[i].booknum, stdbooks[i].time);
		i++;
	}
	return i;
}
void bookf(FILE* book) {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	FILE* studbooks;
	struct books elem;
	book = fopen("books.csv", "r");
	char file[5000];
	while (fgets(file, 5000, book) != NULL) {
		printf("%s", file);
	}
	fclose(book);
	int add;
	printf("Ваш выбор:");
	scanf("%d", &add);
	if (add == 1) {
		book = fopen("books.csv", "a+");
		printf("Введите ISBN:");
		fflush(stdin);
		scanf("%s", elem.num);
		if (similar(elem.num) == 0)
		{
			printf("Такой ISBN уже есть!\n");
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
			studbooks = fopen("student_books.csv", "a+");
			if (elem.qs != elem.q) {
				fprintf(book, "%s;%s;%s;%d;%d\n", elem.num, elem.ath, elem.name, elem.q, elem.qs);
				fprintf(studbooks, "%s\n", elem.num);
			} else fprintf(book, "%s;%s;%s;%d;%d\n", elem.num, elem.ath, elem.name, elem.q, elem.qs);
			fclose(book);
			fclose(studbooks);
		}
	}
	if (add == 2) {
		FILE* stubooks = fopen("student_books.csv", "r");
		char dnum[20];
		printf("Введите ISBN:");
		scanf("%s", &dnum);
		if (similar1(dnum) == 0) {
			printf("Эта книга занята!");
		}
		else delbook1("books.csv");
		fclose(stubooks);
	}
	if (add == 3) {
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
			scanf("%s", elem.ath);
			printf("Введите название:");
			scanf("%s", elem.name);
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
				fprintf(book, "%s;%s;%s;%d;%d\n", elem.num, elem.ath, elem.name, elem.q, elem.qs);
			}
			fclose(book);
		}
		else
			printf("\nНет такого ISBN!\n ");
	}
	if (add == 4) {
		struct students elem1;
		struct stbooks elem2;
		FILE* book, * studbook, * stdents;
		printf("\nВведите ISBN:");
		scanf("%s", elem.num);
		printf("Введите номер зачетки:");
		scanf("%s", elem1.booknum);
		book = fopen("books.csv", "r");
		stdents = fopen("students.csv", "r");
		rewind(book);
		rewind(stdents);
		int getfile = similar(elem.num);
		int getfile2 = similar2(elem1.booknum);
		int getfile1 = readb("books.csv");
		int getfile12 = readb1("students.csv");
		fclose(book);
		fclose(stdents);
		if (getfile !=-1 && getfile2 != -1)
		{
			printf("Введите автора:");
			scanf("%s", elem.ath);
			printf("Введите название:");
			scanf("%s", elem.name);
			printf("Количество книг:");
			scanf("%d", &elem.q);
			printf("Количество доступных книг:");
			scanf("%d", &elem.qs);
			book = fopen("books.csv", "w");
			stdents = fopen("students.csv", "r");
			studbook = fopen("student_books.csv", "a+");
			int i, j;
			for (i = 0; i < getfile1; i++)
			{
				for (j = 0; j < getfile12; j++)
					if (i != getfile && j != getfile2)
						fprintf(book, "%s;%s;%s;%d;%d\n", books[i].num, books[i].ath, books[i].name, books[i].q, books[i].qs);
				fprintf(studbook, "%s;%s;%s\n", books[i].num, students[j].booknum, elem2.time);
			}
			int n;
			printf("1-выдать; 2-забрать:");
			scanf("%d", &n);
			if (n == 2) {
				if (elem.qs < elem.q) {
					fprintf(book, "%s;%s;%s;%d;%d\n", elem.num, elem.ath, elem.name, elem.q, elem.qs + 1);
					fprintf(studbook, "%s;%s;%s\n", elem.num, elem1.booknum, elem2.time);
				}
				else printf("Нечего забирать!");
			}
			else if (n == 1) {
				if (elem.qs > 1) {
					printf("Введите дату сдачи:");
					scanf("%s", elem2.time);
					fprintf(book, "%s;%s;%s;%d;%d\n", elem.num, elem.ath, elem.name, elem.q, elem.qs - 1);
					fprintf(studbook, "%s;%s;%s\n", elem.num, elem1.booknum, elem2.time);
				}
				else {
					printf("Недостаточно книг\n");
					printf("Книга будет сдана: %s", elem2.time);
				}
				fclose(book);
			}
		
			else
				printf("\nНет таких ISBN или зачетки!\n ");
		}
	}
	if (add == 5) {
		searchb("student_books.csv");
	}
	if (add == 0) {
		exit(0);
	}
	 }
void studentsf(FILE* stdents) {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	struct students elem;
	FILE* stubooks;
	char file[5000];
	stdents = fopen("students.csv", "r");
	while ((fgets(file, 5000, stdents)) != NULL) {
		printf("\n%s\n", file);
	}
	fclose(stdents);
	int add;
		printf("\nВыберете операцию:");
		scanf("%d", &add);
			if (add == 1) {
				printf("\nВведите номер зачетки:");
				scanf("%s", elem.booknum);
				if (similar2(elem.booknum) != -1)
				{
					printf("Такая зачетка уже есть!\n");
					fclose(stdents);
				}
				else {
					printf("Введите фамилию:");
					scanf("%s", elem.surname);
					printf("Введите имя:");
					scanf("%s", elem.name);
					printf("Введите отчество:");
					scanf("%s", elem.patr);
					printf("Введите факультет:");
					scanf("%s", elem.fac);
					printf("Введите кафедру:");
					scanf("%s", elem.depart);
					stdents = fopen("students.csv", "a+");
					fprintf(stdents, "%s;%s;%s;%s;%s;%s\n", elem.booknum, elem.surname, elem.name, elem.patr, elem.fac, elem.depart);
				}
			}
			if (add == 2) {
				FILE* stubooks=fopen("student_books.csv","r");
				char dbooknum[15];
				printf("Введите номер зачетки:");
				scanf("%s", dbooknum);
				if (similar3(dbooknum)!= -1) {
					printf("У этого студента еще остались книги!");
				}
				else delstudent("students.csv");
				fclose(stubooks);
			}
			if (add == 3) {
				printf("\nВведите номер зачетки:");
				scanf("%s", elem.booknum);
				stdents = fopen("students.csv", "r");
				rewind(stdents);
				int getfile = similar2(elem.booknum);
				int getfile1 = readb1("students.csv");
				fclose(stdents);
				if (getfile != -1)
				{
					printf("Введите фамилию:");
					scanf("%s", elem.surname);
					printf("Введите имя:");
					scanf("%s", elem.name);
					printf("Введите отчество:");
					scanf("%s", &elem.patr);
					printf("Введите факультет:");
					scanf("%s", &elem.fac);
					printf("Введите кафедру:");
					scanf("%s", elem.depart);
					stdents = fopen("students.csv", "w");
					int i;
					for (i = 0; i < getfile1; i++)
					{
						if (i != getfile)
							fprintf(stdents, "%s;%s;%s;%s;%s;%s\n", students[i].booknum, students[i].surname, students[i].name, students[i].patr, students[i].fac, students[i].depart);
						fprintf(stdents, "%s;%s;%s;%s;%s;%s\n", elem.booknum, elem.surname, elem.name, elem.patr, elem.fac, elem.depart);
					}
					fclose(stdents);
				}
				else
					printf("\nНет такой зачетки!\n ");
			}
			if (add == 4) {
				searchst1("students.csv");
			}
			if (add == 5) {
				struct books elem1;
				struct stbooks elem2;
				FILE* book, * studbook;
				printf("\nВведите ISBN:");
				scanf("%s", elem1.num);
				printf("Введите номер зачетки:");
				scanf("%s", elem.booknum);
				book = fopen("books.csv", "r");
				stdents = fopen("students.csv", "r");
				rewind(book);
				rewind(stdents);
				int getfile = similar(elem1.num);
				int getfile2 = similar2(elem.booknum);
				int getfile1 = readb("books.csv");
				int getfile12 = readb1("students.csv");
				fclose(book);
				fclose(stdents);
				if (getfile != -1 && getfile2 != -1)
				{
					printf("Введите автора:");
					scanf("%s", elem1.ath);
					printf("Введите название:");
					scanf("%s", elem1.name);
					printf("Количество книг:");
					scanf("%d", &elem1.q);
					printf("Количество доступных книг:");
					scanf("%d", &elem1.qs);
					book = fopen("books.csv", "w");
					stdents = fopen("students.csv", "r");
					studbook = fopen("student_books.csv", "a+");
					int i, j;
					for (i = 0; i < getfile1; i++)
					{
						for (j = 0; j < getfile12; j++)
							if (i != getfile && j != getfile2)
								fprintf(book, "%s;%s;%s;%d;%d\n", books[i].num, books[i].ath, books[i].name, books[i].q, books[i].qs);
						fprintf(studbook, "%s;%s;%s\n", books[i].num, students[j].booknum, elem2.time);
					}
					int n;
					printf("1-выдать; 2-забрать:");
					scanf("%d", &n);
					if (n == 2) {
						if (elem1.qs < elem1.q) {
							fprintf(book, "%s;%s;%s;%d;%d\n", elem1.num, elem1.ath, elem1.name, elem1.q, elem1.qs + 1);
							fprintf(studbook, "%s;%s;%s\n", books[i].num, students[j].booknum, elem2.time);
						}
						else printf("Нечего забирать!");
					}
					else if (n == 1) {
						printf("Введите дату сдачи:");
						scanf("%s", elem2.time);
						if (elem1.qs > 1) {
							fprintf(book, "%s;%s;%s;%d;%d\n", elem1.num, elem1.ath, elem1.name, elem1.q, elem1.qs - 1);
							fprintf(studbook, "%s;%s;%s\n", elem1.num, elem.booknum, elem2.time);
						}
						else {
							printf("Недостаточно книг\n");
							printf("Книга будет сдана: %s", elem2.time);
						}
						fclose(book);
					}
					else
						printf("\nНет таких ISBN или зачетки!\n ");
				}
			}
			if (add == 6) {
				int i=0;
				stdents = fopen("students.csv", "r+");
					rewind(stdents);
					char file[5000];
					while (fgets(file, 5000, stdents))
					{
						fscanf(stdents, "%[^;];%[^;];%[^;];%[^;];%[^;];[^;];%[^\n]", students[i].booknum, students[i].surname, students[i].name, students[i].patr, students[i].fac, students[i].depart);
						i++;
					}
				while (!feof(stdents)) {
					if (fgetc(stdents) == '\n')
						i++;
				}
				i++;
				struct tm* time1;
				time_t timer=time(NULL);
				time1 = localtime(&timer);
				char strtime[250] = { 0 };
				strftime(strtime, 250, "students_%d.%m.%Y_%H.%M.%S.csv", time1);
				stdents = fopen(strtime, "w");
				for (int j = 0; j < (i - 1); j++) {
					fprintf(stdents, "%s;%s;%s;%s;%s;%s\n", students[j].booknum, students[j].surname, students[j].name, students[j].patr, students[j].fac, students[j].depart);
				}
				printf("Сохранено!");
				fclose(stdents);
			}
			if (add == 7) {
				FILE* stdents2 = fopen("students.csv", "w");
				printf("Введите название файла для восстановления:");
				char filename[40];
				scanf("%s", filename);
				stdents = fopen(filename, "r");
				int temp = 0;
				while ((temp = fgetc(stdents)) != EOF) {
					fputc(temp, stdents2);
				}
				printf("Данные восстановлены!");
			}
			if (add == 0) {
				exit(0);
			}
		}
	


int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	FILE* users;
	users = fopen("users.csv", "r+");
	char data[100];
	char book1[5];
	char studs[5];
	char login[100];
	char passwd[100];
	int arr = 0;
	printf("Введите логин: ");
	writestr(login);
	while (fgets(data, 100, users)) {
		char cpy[100];
		char* temp;
		strcpy(cpy, data);
		temp = strtok(cpy, ";");
		if (strcmp(login, temp) == 0) {
			printf("Введите пароль: ");
			arr++;
			temp = strtok(NULL, ";");
			writestr(passwd);
			if (strcmp(passwd, temp) != 0) {
				printf("Пароль неверный, попробуйте еще раз: ");
				return 0;
			}
			else {
				temp = strtok(NULL, ";");
				strcpy(book1, temp);
				temp = strtok(NULL, ";");
				strcpy(studs, temp);
				break;
			}


		}
	}if (arr == 0) {
		printf("Данного пользователя нет\n\nПопробуйте еще раз!\n\n");
		return 0;
	}


	while (status != '0') {
		system("cls");
		if (count != 0) {
			writestr(c);
		}
		if (book1[0] == '1' && studs[0] == '1') {
			printf("************Главное меню************\n");
			printf("(1) Меню книг\n");
			printf("(2) Меню студентов\n");
			printf("(0) Выйти\n");
			printf(" Ваш Выбор: ");
			status = getc(stdin);
			while (true) {
				if (status == '1') {
					system("cls");
					m = Mainbook();
					break;
				}
				else if (status == '2') {
					system("cls");
					m = Mainstudents();
					break;
				}
				else if (status == '0') {
					printf("\n");
					return 0;

				}
				else {
					printf("\nВведите другую цифру: ");
					status = getc(stdin);
				}
			}
		}
		else if (book1[0] == '1' && studs[0] != '1') {
			m = 1;
		}
		else if (book1[0] != '1' && studs[0] == '1') {
			m = 2;
		}
		if (count != 0) {
			count = 0;
			state = NULL;
		}

		while (state != '0') {
			if (m == 1) {
				if (count != 0 || (book1[0] != '1' || studs[0] != '1')) {
					Mainbook();
					state = getc(stdin);
				}
			}
			if (m == 2) {
				if (count != 0 || (book1[0] != '1' || studs[0] != '1')) {
					Mainstudents();
					state = getc(stdin);
				}
			}
		}
	}
}
void delstudent(const char* filename)
{
	char dbooknum[15];
	int i = 0;
	char file[5000];
	FILE* stdents;
	printf("Введите номер зачетки:");
	fflush(stdin);
	scanf("%s", dbooknum);
	stdents = fopen(filename, "r+");
		rewind(stdents);
		while (fgets(file, 5000, stdents))
		{
			fscanf(stdents, "%[^;];%[^;];%[^;];%[^;];%[^;];%[^;]\n", students[i].booknum, students[i].surname, students[i].name, students[i].patr, students[i].fac, students[i].depart);
			++i;
		}
	int k = -1;
	int j = 0;
	for (j; j < i; j++)
	{
		if (strcmp(dbooknum, students[j].booknum) == 0)
			k = j;
	}
	fclose(stdents);
	if (k == -1)
	{
		printf("Нет такого студента!\n");
	}
	else {
		 stdents= fopen(filename, "w");
		rewind(stdents);
		for (j = 0; j < i - 1; ++j) {
			if (j != k) {
				fprintf(stdents, "%s;%s;%s;%s;%s;%s\n", students[j].booknum,students[j].surname,students[j].name,students[j].patr,students[j].fac,students[j].depart);
			}
		}
		fclose(stdents);
		printf("Студент удален!\n");
	}
}
void delbook1(const char* filename) {

	char dnum[15];
	int i = 0;
	char file[5000];
	FILE* book;
	printf("Введите номер ISBN:");
	fflush(stdin);
	scanf("%s", &dnum);
	book = fopen(filename, "r+");
	rewind(book);
	while (fgets(file, 5000, book))
	{
		fscanf(book, "%[^;];%[^;];%[^;];%d;%d\n", books[i].num, books[i].ath, books[i].name, &books[i].q, &books[i].qs);
		++i;
	}
	int k = -1;
	int j = 0;
	for (j; j < i; j++)
	{
		if (strcmp(dnum, books[j].num) == 0)
			k = j;
	}
	fclose(book);
	if (k != 0)
	{
		printf("Нет такого ISBN!\n");
	}
	else {
		book = fopen(filename, "w");
		rewind(book);
		for (j = 0; j < i - 1; ++j) {
			if (j != k) {
				fprintf(book, "%s;%s;%s;%d;%d\n", books[j].num, books[j].ath, books[j].name, books[j].q, books[j].qs);
			}
		}
		fclose(book);
		printf("Книга удалена!\n");
	}
}
