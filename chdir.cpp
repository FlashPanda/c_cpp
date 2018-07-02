#include <unistd.h>
#include <stdio.h>

int main () {
	char curDir[256] = {0};
	getcwd (curDir, 256);
	printf ("当前工作目录：%s\n", curDir);
	
	chdir ("/tmp");
	
	getcwd (curDir, 256);
	printf ("切换之后的工作目录：%s\n", curDir);
}
