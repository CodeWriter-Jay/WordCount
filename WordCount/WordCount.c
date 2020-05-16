#include<stdio.h>
#include<string.h>

int main(int args, char* argv[])
{
	if (args < 3)
	{
		printf("传入参数不够！请在命令行下执行本程序或重试！传参示例\"WordCount.exe -c test.txt\"");
		return 0;
	}
	else if (args > 3)
	{
		printf("传入参数过多！请重试！传参示例\"WordCount.exe -c test.txt\"");
		return 0;
	}
	char path[100] = "test.txt";
	FILE* fp;
	errno_t err;
	int i = 0;
	char tmp;
	int len = strlen(argv[2]);
	strcpy_s(path, len + 1, argv[2]);

	if (!(err = fopen_s(&fp, path, "r")))
	{
		if (strcmp(argv[1], "-c") == 0)
		{
			while (1)
			{
				tmp = fgetc(fp);
				if (tmp != EOF)
				{
					i++;
				}
				else
				{
					printf("\n字符数：%d\n", i);
					break;
				}
			}
		}
		else if (strcmp(argv[1], "-w") == 0)
		{
			while (1)
			{
				tmp = fgetc(fp);
				if (tmp != EOF)
				{
					if (tmp == ',' || tmp == '\n' || tmp == ' ')
					{
						i++;
					}
				}
				else
				{
					i++;
					printf("\n单词数：%d\n", i);
					break;
				}
			}
		}
		else
		{
			printf("控制参数错误！请重试！");
		}
	}
	else
	{
		printf("文件打开失败！\n");
		return 0;
	}
	return 0;
}