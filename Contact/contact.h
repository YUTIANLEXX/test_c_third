#include <stdio.h>
#include <string.h>

enum Option
{
	EXIT,     //0
	ADD,      //1
	DEL,      //2
	SEARCH,   //3
	MODIFY,   //4
	SHOW,     //5
	SORT      //6
};


#define MAX 1000

#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADDR 30

struct PeoInfo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
};

struct Contact                     //通讯录类型
{
	struct PeoInfo data[MAX];     //存放信息
	int size;                     //记录当前已有的元素个数
}; 

//声明函数
void InitContact(struct Contact* ps);
void AddContact(struct Contact* ps);
void ShowContact(const struct Contact* ps);
void DelContact(struct Contact* ps);
void SearchContact(const struct Contact* ps);
void ModifyContact(struct Contact* ps);
