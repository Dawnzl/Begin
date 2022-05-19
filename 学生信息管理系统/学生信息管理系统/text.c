#define _CRT_SECURE_NO_WARNINGS 1
#include"system2.h"

int main()
{
	struct user us[10];
	int input = 0;
	do
	{
		Loginp(us);//登录

		scanf("%d", &input);

		switch (input)
		{
		case 1:
			make();//创建学生信息
			break;
		case 2:
			add();//增加学生信息
			break;
		case 3:
			look();//浏览学生信息
			break;
		case 4:
			revise();//修改学生信息
			break;
		case 5:
			fine();//查找学生信息
			break;
		case 6:
			del();//删除学生信息
			break;
		case 7:
			analyse();//输入课程名称分析成绩
			break;
		case 8:
			sort();//排序(学号、姓名、成绩等)
			break;
		case 0:
			Out(us);
			printf("欢迎再次使用本系统!\n");
			break;
		default:
			printf("选择有误\n");
			break;
		}

	} while (input);
	return 0;
}