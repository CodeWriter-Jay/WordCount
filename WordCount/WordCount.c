#include<stdio.h>
#include<string.h>

void countWord(FILE* fp, char path[]);
void countChar(FILE* fp, char path[]);

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
	FILE* fp;
	errno_t err;

	if (!(err = fopen_s(&fp, argv[2], "r")))
	{
		if (strcmp(argv[1], "-c") == 0)
		{
			countChar(fp, argv[2]);
		}
		else if (strcmp(argv[1], "-w") == 0)
		{
			countWord(fp, argv[2]);
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

void countWord(FILE* fp, char path[])
{
	char tmp;
	char endFlag; //用于判定文件最后一个字符是否为单词分隔符，避免单词数多计算
	int countNum = 0;
	while (1)
	{
		tmp = fgetc(fp);
		if (tmp != EOF)
		{
			if (tmp == ',' || tmp == '\n' || tmp == ' ')
			{
				countNum++;
			}
		}
		else
		{
			if (endFlag != ',' && endFlag != '\n' && endFlag != ' ')  //避免单词数多计算
			{
				countNum++;
			}
			printf("\n单词数：%d\n", countNum);
			break;
		}
		endFlag = tmp;
	}
}

void countChar(FILE* fp, char path[])
{
	char tmp;
	int countNum = 0;
	while (1)
	{
		tmp = fgetc(fp);
		if (tmp != EOF)
		{
			countNum++;
		}
		else
		{
			printf("\n字符数：%d\n", countNum);
			break;
		}
	}
}