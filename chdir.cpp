#include <unistd.h>
#include <stdio.h>

int main () {
	char curDir[256] = {0};
	getcwd (curDir, 256);
	printf ("当前工作目录：%s\n", curDir);
	
	int result = chdir ("/tmp");
	printf ("切换的结果是：%d\n", result);
	
	getcwd (curDir, 256);
	printf ("切换之后的工作目录：%s\n", curDir);

	int result1 = chdir ("/tmp/sse/sie/sse/112/");
	printf ("切换的结果是%d\n", result1);

	getcwd (curDir, 256);
	printf ("切换后的目录是：%s\n", curDir);
}
