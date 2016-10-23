#include <stdio.h>
#include <errno.h>

int main(int argc, char* argv[]){

	if(argc == 1){
		printf("please chose file\n");
		return 0;
	}
	
	FILE *fp;
	fp = fopen(argv[1],"r");
	if(fp == NULL){

		char* errmsg;
		
		switch(errno){
			case 2:
				errmsg = "no such file or directory";
				break;
			default:
				errmsg = "failed open file";
				break;
		}

		errmsg = "";
		perror(errmsg);
		//printf("error no:%d %s\n",errno,errmsg);
		return 1;	//異常終了
	}

	
/*
	char s[256];

	while(fgets(s,256,fp) != NULL){
		//printf("%s",s);

		int i;
		for(i = 0; s[i] != '\0'; i++){
			printf("%d\n",s[i]);
		}
	}
	
	*/


	char* line = NULL;
	size_t linecap = 0;
	ssize_t linelen;

	while((linelen = getline(&line, &linecap,fp)) != -1){	//読み込み失敗は　-1
		
		int i;
		for(i = 0; line[i] != '\0'; i++){
			printf("%d\n",line[i]);
		}
	}


	fclose(fp);

	return 0;

}
