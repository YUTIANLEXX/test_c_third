#include "contact.h"

void InitContact(struct Contact* ps)
{
	ps->data = (struct PeoInfo*)malloc(DEFAULT_SZ * sizeof(struct PeoInfo));
	if (ps->data == NULL)
	{
		return;
	}
	ps->size = 0;
	ps->capacity = DEFAULT_SZ;
}

void CheckCapacity(struct Contact *ps)
{
	if (ps->size == ps->capacity)
	{
		//����
		struct PeoInfo *ptr = realloc(ps->data, (ps->capacity + 2)*sizeof(PeoInfo));
		if (ptr != NULL)
		{
			ps->data = ptr;
			ps->capacity += 2;
			printf("���ݳɹ�\n");
		}
		else
		{
			printf("����ʧ��\n");
		}
	}
}

void AddContact(struct Contact* ps)
{
        //��鵱ǰͨѶ¼������
	   //1.������ˣ����ӿռ�
	   //2.���û����ɶ�²���
	    CheckCapacity(ps);
		//��������
		printf("����������>:");
		scanf("%s", ps->data[ps->size].name);
		printf("����������>:");
		scanf("%d", &(ps->data[ps->size].age));
		printf("�������Ա�>:");
		scanf("%s", ps->data[ps->size].sex);
		printf("������绰>:");
		scanf("%s", ps->data[ps->size].tele);
		printf("������סַ>:");
		scanf("%s", ps->data[ps->size].addr);

		ps->size++;
		printf("���ӳɹ�\n");
}

void ShowContact(const struct Contact* ps)
{
	if (ps->size == 0)
	{
		printf("ͨѶ¼Ϊ��\n");
	}
	else
	{
		int i = 0;
		printf("%20s\t%4s\t%5s\t%12s\t%20s\n", "����", "����", "�Ա�", "�绰", "סַ");
		for (i = 0; i < ps->size; i++)
		{
			printf("%20s\t%4d\t%5s\t%12s\t%20s\n",
				ps->data[i].name,
				ps->data[i].age,
				ps->data[i].sex,
				ps->data[i].tele,
				ps->data[i].addr);
		}
	}
}

static int FindByName(const struct Contact* ps, char name[MAX_NAME])
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (0 == strcmp(ps->data[i].name, name))
		{
			return i;
		}
	}
	return -1;          //�Ҳ���
}

void DelContact(struct Contact* ps)
{
	char name[MAX_NAME];
	int pos = 0;
	printf("������Ҫɾ���˵�����>:");
	scanf("%s", name);
	//1.������Ҫɾ�����˵�λ��
	pos = FindByName(ps, name);        //�ҵ�������������Ԫ�ص��±꣬�Ҳ�������-1
	//2.ɾ��
	if (-1 == pos)
	{
		printf("Ҫɾ�����˲�����\n");
	}
	else
	{
		//ɾ������
		int j = 0;
		for (j = pos; j <ps->size - 1; j++)
		{
			ps->data[j] = ps->data[j + 1];
		}
		ps->size--;
		printf("ɾ���ɹ�\n");
	}
}

void SearchContact(const struct Contact* ps)
{
	char name[MAX_NAME];
	int pos = 0;
	printf("������Ҫ�����˵�����>:");
	scanf("%s", name);
	pos = FindByName(ps, name);
	if (-1 == pos)
	{
		printf("Ҫ���ҵ��˲�����\n");
	}
	else
	{
		printf("%20s\t%4s\t%5s\t%12s\t%20s\n", "����", "����", "�Ա�", "�绰", "סַ");
		printf("%20s\t%4d\t%5s\t%12s\t%20s\n",
			ps->data[pos].name,
			ps->data[pos].age,
			ps->data[pos].sex,
			ps->data[pos].tele,
			ps->data[pos].addr);
	}
}

void ModifyContact(struct Contact* ps)
{
	char name[MAX_NAME];
	int pos = 0;
	printf("������Ҫ�޸��˵�����>:");
	scanf("%s", &name);
	pos = FindByName(ps, name);
	if (-1 == pos)
	{
		printf("Ҫ�޸��˵���Ϣ������\n");
	}
	else
	{
		printf("����������>:");
		scanf("%s", ps->data[pos].name);
		printf("����������>:");
		scanf("%d", &(ps->data[pos].age));
		printf("�������Ա�>:");
		scanf("%s", ps->data[pos].sex);
		printf("������绰>:");
		scanf("%s", ps->data[pos].tele);
		printf("������סַ>:");
		scanf("%s", ps->data[pos].addr);

		printf("�޸����\n");
	}
}

void SortContact(struct Contact* ps)
{
	if (ps->size <= 0)
	{
		printf("ͨѶ¼��û����ϵ�ˣ������Ӻ�����!\n");
	}
	int i = 0;
	int j = 0;
	for (i = 0; i < ps->size - 1; i++)
	{
		for (j = 0; j < ps->size - 1; j++)
		{
			if ((strcmp(ps->data[j].name, ps->data[j + 1].name)) > 0)
			{
				struct PeoInfo tmp;
				tmp = ps->data[j];
				ps->data[j] = ps->data[j + 1];
				ps->data[j + 1] = tmp;
			}
		}
	}
	printf("����ɹ���\n");

}

void DestoryContact(struct Contact* ps)
{
	free(ps->data);
	ps->data = NULL;
}