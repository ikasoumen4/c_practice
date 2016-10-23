#include <stdio.h>
#include <string.h>
#include <errno.h>

typedef struct {
	char* name;
	int age;
}Human;

void test(Human* human){

	printf("test\n");
	printf("%s\n",(*human).name);

}


int main(){

	char* str = "test";
	char* copy_str;
	copy_str = strdup(str);

	printf("%s\n",copy_str);

	printf("%d\n",ENOENT);
	perror("そのようなファイルディレクトリは存在しません。");

	Human human = {
		"yasuhisa",
		31
	};
	test(&human);
	printf("%s:%d\n",human.name,human.age);
}
