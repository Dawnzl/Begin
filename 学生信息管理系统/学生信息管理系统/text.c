#define _CRT_SECURE_NO_WARNINGS 1
#include"system2.h"

int main()
{
	struct user us[10];
	int input = 0;
	do
	{
		Loginp(us);//��¼

		scanf("%d", &input);

		switch (input)
		{
		case 1:
			make();//����ѧ����Ϣ
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
		case 0:
			Out(us);
			printf("��ӭ�ٴ�ʹ�ñ�ϵͳ!\n");
			break;
		default:
			printf("ѡ������\n");
			break;
		}

	} while (input);
	return 0;
}