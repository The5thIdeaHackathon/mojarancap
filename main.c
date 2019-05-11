//¸ðÀÚ¶õÄ¸_lifestyle_program
#define _CRT_SECURE_NO_WARNINGS
#define Season t->tm_mon
#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <time.h>

int main()
{
	FILE *pf = NULL;
	const char f_name[128] = "C:\\Users\\orioncra\\Downloads\\final3.txt";
	char buffer[256] = { 0 };
	char feel_n = '0', season;
	int p_s = 0, p_e = 0;
	time_t timer;
	struct tm *t;
	timer = time(NULL);
	t = localtime(&timer);
	char rand_t = (char)(t->tm_sec % 3) + 49;

	//season check
	if (Season >= 2 && 4 >= Season)
	{
		season = 'a';
	}
	else if (Season >= 5 && 7 >= Season)
	{
		season = 'b';
	}
	else if (Season >= 8 && 10 >= Season)
	{
		season = 'c';
	}
	else
	{
		season = 'd';
	}

	printf("%c %c", rand_t, season);
	scanf("%c", &feel_n);
	if (feel_n >= '1' && feel_n <= '4')
	{
		if ((pf = fopen(f_name, "r")) == NULL)
		{
			fprintf(stderr, "file_open failed", f_name);
			exit(1);
		}

		while (fgets(buffer, 256, pf))
		{
			//printf("%d %d", strchr(buffer, feel_n), strchr(buffer, season));
			//system("pause");
			if (p_s == 1)
			{
				if (p_e == 1)
				{
					if (strchr(buffer, rand_t + 1))
					{
						break;
					}
					else
					{
						printf("%s", buffer);
					}
				}
				if (strchr(buffer, rand_t))
				{
					p_e = 1;
				}
			}
			if (strchr(buffer, feel_n) && strchr(buffer, season))
			{
				p_s = 1;
			}
		}
	
	fclose(pf);
	}
	system("pause");
	return 0;
}