#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SHOW_STU 1
#define ADD_STU  2
#define DEL_STU  3
#define SEAR_STU 4
#define SAVE_STU 5
#define QUIT_STU 6

#define NO_ERROR  0
#define SEX_ERROR 1
#define AGE_ERROR 2
#define ID_ERROR  3

typedef struct
{
	char msg[100];
	int id;
}Error;

typedef struct Student
{
	char stu_name[10];     // ѧ������
	char stu_sex[10];      // ѧ���Ա�
	int stu_age;           // ѧ������
	int stu_id;            // ѧ��ѧ��
	struct Student *next;
}Node;

typedef struct
{
	Node *head;
}List;

static void menu_show(void)
{
	printf("\nThere are some options, Please select a option.(You must input a number!)\n");
	printf("***************************************************************************\n");
	printf("1 : Show all student\n");
	printf("2 : Add a student\n");
	printf("3 : Delete a student by stu_id\n");
	printf("4 : Search a student by stu_id\n");
	printf("5 : Save all student\n");
	printf("6 : Quit student mangement system\n");
	printf("***************************************************************************\n");
}

static int student_information_check(const List *p_list, const Node *node, Error *err)
{
	int repetition = stu_id_constraint
	if ()
	{

	}
	else if (9999 < node->stu_id || node->stu_id < 1000)
	{
		err->id = ID_ERROR;
		strcpy(err->msg, "%%ѧ��ѧ�Ų��Ϸ�(��Ч���䷶Χ:1000~9999)");
		return -1;
	}
	else if (0 != strcmp("��", node->stu_sex) && 0 != strcmp("Ů", node->stu_sex))
	{
		err->id = SEX_ERROR;
		strcpy(err->msg, "%%ѧ���Ա𲻺Ϸ�(��Ч�Ա�:�� �� Ů)");
		return -1;
	}
	else if (50 < node->stu_age || node->stu_age <= 0)
	{
		err->id = AGE_ERROR;
		strcpy(err->msg, "%%ѧ�����䲻�Ϸ�(��Ч���䷶Χ:1~50)");
		return -1;
	}
	else
	{
		err->id = NO_ERROR;
	}
	return 0;
}

static void student_information_show(List *p_list)
{
	if (NULL == p_list->head)
	{
		printf("There is not any student. Maybe you can add a student.\n");
	}
	else
	{
		printf("ѧ��      ����      �Ա�      ����      \n");
		int stu_num = 0;
		Node *last;
		for(last = p_list->head; last; last = last->next)
		{
			char age_txt[10] = {0};
			sprintf(age_txt, "%d", last->stu_age);
			char id_txt[10] = {0};
			sprintf(id_txt, "%d", last->stu_id);

			int stu_id_len = strlen(id_txt);
			int stu_name_len = strlen(last->stu_name);
			int stu_age_len = strlen(age_txt);
			char record[50] = {0};
			
			strcat(record, id_txt);
			for (int i = 0; i < 10 - stu_id_len; i++)
			{
				strcat(record, " ");
			}
			strcat(record, last->stu_name);
			for (int i = 0; i < 10 - stu_name_len; i++)
			{
				strcat(record, " ");
			}
			strcat(record, last->stu_sex);
			for (int i = 0; i < 8; i++)
			{
				strcat(record, " ");
			}
			strcat(record, age_txt);
			for (int i = 0; i < 10 - stu_age_len; i++)
			{
				strcat(record, " ");
			}
			printf("%s\n", record);
			stu_num++;
		}
		printf("Total Student:%d\n", stu_num);
	}
}

static void student_information_add(List *p_list)
{
	printf("Now you can add a student information.\n");
	printf("Tips:there are some attributes that like stu_id, stu_name, stu_sex and stu_age with student.\n\
Of course, the attribute has some limitation.\n");
	printf("stu_id range 1000 to 9999.\n");
	printf("stu_name character max (4 Chinese or 9 English).\n");
	printf("stu_sex range �� or Ů.\n");
	printf("stu_age range 1 to 50.\n");
	Node *p = malloc(sizeof(Node));
	Error err;
	memset(&err, 0, sizeof(err));
	p->next = NULL;

	printf("stu_id(ѧ��ѧ��):");
	scanf("%d", &(p->stu_id));
	printf("stu_name(ѧ������):");
	scanf("%s", p->stu_name);
	printf("stu_sex(ѧ���Ա�):");
	scanf("%s", p->stu_sex);
	printf("stu_age(ѧ������):");
	scanf("%d", &(p->stu_age));

	p->stu_name[9] = '\0';
	p->stu_sex[9] = '\0';
	while(student_information_check(p_list, p, &err) < 0)
	{ 
		if (NO_ERROR != err.id)
		{
			printf("%s\n", err.msg);
			if (ID_ERROR == err.id)
			{
				printf("ѧ��ѧ��:");
				scanf("%d", &(p->stu_id));
				continue;
			}
			else if (SEX_ERROR == err.id)
			{
				printf("ѧ���Ա�:");
				scanf("%s", p->stu_sex);
				continue;
			}
			else if (AGE_ERROR == err.id)
			{
				printf("ѧ������:");
				scanf("%d", &(p->stu_age));
				continue;
			}
		}
	}
	printf("Adding a student successful.\n");
	Node *last = p_list->head;
	if (last != NULL)  // �жϵ�һ������Ƿ����
	{
		while (last->next != NULL)
		{
			last = last->next;
		}
		last->next = p;
	}
	else
	{
		p_list->head = p;
	}
}

static void student_information_del(List *p_list, int stu_id)
{
	Node *p, *q;
	int is_found = 0;
	for (q = NULL, p = p_list->head; p != NULL; q = p, p = p->next)
	{
		if (stu_id == p->stu_id)
		{
			if (q != NULL) // �ж��Ƿ�Ϊͷ�ڵ�
			{
				q->next = p->next;
			}
			else
			{
				p_list->head = p->next;
			}
			free(p);
			is_found = 1;
			break;
		}
	}
	if (is_found)
	{
		printf("Delete successful.\n");
	}
	else
	{
		printf("Delete failure.\n");
	}
}

static void student_information_save(const List *p_list, const char *filename)
{
	Node *last;
	char stu_info[100] = { 0 };
	FILE *file_handle = fopen(filename, "a");
	if(NULL != file_handle)
	{ 
		for (last = p_list->head; last != NULL; last = last->next)
		{
			sprintf(stu_info, "{\"stu_id\":%d,\"stu_name\":\"%s\",\"stu_sex\":\"%s\",\"stu_age\":%d}\n",
				last->stu_id, last->stu_name, last->stu_sex, last->stu_age);
			fwrite(stu_info, sizeof(char), strlen(stu_info), file_handle);
		}
		fclose(file_handle);
	}
	printf("Save all student Successful.\n");
}

static void student_mamgement_system_quit(List *p_list)
{
	Node *temp;
	while (p_list->head != NULL)
	{
		temp = p_list->head;   //�ӵ�һ����㿪ʼ�ͷ�
		p_list->head = temp->next;
		free(temp);
	}
}

static int student_information_search_by_stu_id(List *p_list, int stu_id)
{
	int is_found = 0;
	Node *last;
	char stu_info[100] = {0};
	for (last = p_list->head; last != NULL; last = last->next)
	{
		if (stu_id == last->stu_id)
		{
			sprintf(stu_info, "{\"stu_id\":%d,\"stu_name\":\"%s\",\"stu_sex\":\"%s\",\"stu_age\":%d}", 
				last->stu_id, last->stu_name, last->stu_sex, last->stu_age);
			is_found = 1;
			break;
		}
	}
	if (is_found)
	{
		printf("Found a student: %s.\n", stu_info);
	}
	else
	{
		printf("Not Found.\n");
	}
	return 0;
}

static int function_select(int option, List *p_list)
{
	int stu_id = 0;
	int result = 0;
	char filename[300] = { 0 };
	switch (option)
	{
		case SHOW_STU:
			student_information_show(p_list);
			break;
		case ADD_STU:
			student_information_add(p_list);
			break;
		case DEL_STU:
			printf("Please input a student's id:");
			scanf("%d", &stu_id);
			student_information_del(p_list, stu_id);
			break;
		case SEAR_STU:
			printf("Please input a student's id:");
			scanf("%d", &stu_id);
			student_information_search_by_stu_id(p_list, stu_id);
			break;
		case SAVE_STU:
			printf("Please input file name that you want to save:");
			scanf("%s", filename);
			student_information_save(p_list, filename);
			break;
		case QUIT_STU:
			student_mamgement_system_quit(p_list);
			result = 1;
			break;
		default:
			break;
	}
	return result;
}

int main(int argc, const char *argv[])
{
	List list;
	list.head = NULL;

	printf("Welcome to Student Mangement System(Version 1.0).\n\n");
Loop:
	menu_show();
	
	int option = 0;
	printf("Pick a Num:");
	scanf("%d", &option);
	while (option != SHOW_STU && option != ADD_STU && option != DEL_STU && 
		option != SEAR_STU && option != QUIT_STU && option != SAVE_STU)
	{
		printf("Error: Please valid number.\n");
		printf("Pick a Num:");
		scanf("%d", &option);
	}
	if (function_select(option, &list) > 0)
	{
		printf("Free link List memory and Quit program.\n");
	}
	else
	{
		goto Loop;
	}
	
	return 0;
}