#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	time_t t = 0;
	struct tm *tmp = NULL;
	char buf1[16] = {0};	
	char buf2[64] = {0};
	int buf_len = 0;

	time(&t);
	tmp = localtime(&t);

	buf_len = sizeof(buf1);
	if (strftime(buf1, buf_len, "time and date:%r, %a %b %d, %Y", tmp) == 0)
		printf("buffer length %d is too small\n", buf_len);
	else
		printf("%s\n", buf1);

	buf_len = sizeof(buf2);
	if (strftime(buf2, buf_len, "time and date:%r, %a %b %d, %Y", tmp) == 0)
		printf("buffer length %d is too small\n", buf_len);
	else
		printf("%s\n", buf2);

	exit(0);
}

