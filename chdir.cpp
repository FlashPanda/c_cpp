#include <unistd.h>

int main () {
	printf ("当前工作目录：%s\n", getcwd (NULL, NULL));
	
	chdir ("/tmp");
	
	printf ("切换之后的工作目录：%s\n", getcwd (NULL, NULL));
}