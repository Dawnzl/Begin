#define _CRT_SECURE_NO_WARNINGS 1
#include"system2.h"

int main()
{
	struct user us[10];
	char name[20];
	int input = 0;
	Loginp(us,name);//��¼

	do
	{
		Menu();
		scanf("%d", &input);

		switch (input)
		{
		case 1:
			make();//����ѧ����Ϣ���Ḳ�ǵ�ԭ�ȵ�ѧ����Ϣ��
			break;
		case 2:
			add();//����ѧ����Ϣ
			break;
		case 3:
			look();//���ѧ����Ϣ
			break;
		case 4:
			revise();//�޸�ѧ����Ϣ
			break;
		case 5:
			fine();//����ѧ����Ϣ
			break;
		case 6:
			del();//ɾ��ѧ����Ϣ
			break;
		case 7:
			analyse();//����γ����Ʒ����ɼ�
			break;
		case 8:
			sort();//����(ѧ�š��������ɼ���)
			break;
		case 9:
			deleteMenu();
			break;
		case 0:
			Out(name);
			printf("��ӭ�ٴ�ʹ�ñ�ϵͳ!\n");
			break;
		default:
			printf("ѡ������\n");
			break;
		}

	} while (input);
	return 0;
}