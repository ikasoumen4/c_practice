#include <stdio.h>
#include <unistd.h>

enum KEY_ACTION{
        KEY_NULL = 0,       /* NULL */
        CTRL_C = 3,         /* Ctrl-c */
        CTRL_D = 4,         /* Ctrl-d */
        CTRL_F = 6,         /* Ctrl-f */
        CTRL_H = 8,         /* Ctrl-h */
        TAB = 9,            /* Tab */
        CTRL_L = 12,        /* Ctrl+l */
        ENTER = 13,         /* Enter */
        CTRL_Q = 17,        /* Ctrl-q */
        CTRL_S = 19,        /* Ctrl-s */
        CTRL_U = 21,        /* Ctrl-u */
        ESC = 27,           /* Escape */
        BACKSPACE =  127,   /* Backspace */
        /* The following are just soft codes, not really reported by the
 *          * terminal directly. */
        ARROW_LEFT = 1000,
        ARROW_RIGHT,
        ARROW_UP,
        ARROW_DOWN,
        DEL_KEY,
        HOME_KEY,
        END_KEY,
        PAGE_UP,
        PAGE_DOWN
};



int main(int argc, char* argv[]){
	
	printf("%d\n",STDIN_FILENO);
	printf("%d\n",STDOUT_FILENO);
	printf("%d\n",STDERR_FILENO);

	int nread;
	char c;

	while(1){
		//Unicodeだとどうなる？？
		nread = read(STDIN_FILENO,&c,1);
		printf("%c\n",c);

		switch(c){
		case ESC:
			printf("aaaaaaaa\n");
			return ESC;
		default:
			return c;
		}
	}
}

