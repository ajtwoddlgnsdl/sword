#include "main.h"
int main(){
	init();
	while (1){
		title();
		int menuCode = menu();
		if (menuCode == 0)
			game_easy();
		else if (menuCode == 1)
			game_hard();
		else if (menuCode == 2)
			exit(0);
		system("cls");
	}
}