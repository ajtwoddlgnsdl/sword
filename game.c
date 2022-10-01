#include "game.h"
int keyControl(){
	char key = _getch();
	if (key == 'w' || key == 'W')
		return up;
	else if (key == 'a' || key == 'A')
		return left;
	else if (key == 's' || key == 'S')
		return down;
	else if (key == 'd' || key == 'D')
		return right;
	else if (key == ' ')
		return submit;
}
void title(){
	go(27, 5);
	printf("#########  #     ##     #  #########   ########    ####### \n");
	go(27, 6);
	printf("#          ##   ####   ##  #       #   #      ##   #     ##\n");
	go(27, 7);
	printf("#########   #   #  #   #   #       #   ########    #      #\n");
	go(27, 8);
	printf("        #   ## ##  ## ##   #       #   #     ##    #     ##\n");
	go(27, 9);
	printf("#########    ###    ###    #########   #      ##   ####### \n");
}
int menu(){
	int x = 52, y = 15;
	go(x - 2, y);
	printf("> �������");
	go(x, y + 1);
	printf("�ϵ���(������)");
	go(x, y + 2);
	printf("  ����");
	go(x - 1, y);
	while (1){
		int a = keyControl();
		switch (a){
			case up:{
				if (y > 15){
					go(x - 2, y);
					printf(" ");
					go(x - 2, --y);
					printf(">");
				}
				break;
			}
			case down:{
				if (y < 17){
					go(x - 2, y);
					printf(" ");
					go(x - 2, ++y);
					printf(">");
				}
				break;
			}
			case submit:
				return y - 15;
		}
	}
}
int easy(){
	if (enforce_easy == 0 && breaking == 0){
		int x = 105, y = 5;
		while (1){
			int a = keyControl();
			switch (a){
			case up:{
				if (y > 1){
					if (y == 23){
						go(105, 23);
						printf(" ");
						go(103, 5);
						printf(">");
						x = 105, y = 5;
					}
					else if (y == 5){
						go(103, 5);
						printf(" ");
						go(103, 1);
						printf(">");
						x = 105, y = 1;
					}
				}
				break;
			}
			case down:{
				if (y < 23){
					if (y == 1 && x == 105){
						go(103, 1);
						printf(" ");
						go(103, 5);
						printf(">");
						x = 105, y = 5;
					}
					else if (y == 5){
						go(103, 5);
						printf(" ");
						go(105, 23);
						printf(">");
						x = 107, y = 23;
					}
				}
				break;
			}
			case left:{
				if (x != 3){
					if (y == 1){
						go(103, 1);
						printf(" ");
						go(1, 1);
						printf(">");
						x = 3, y = 1;
					}
					else if (y == 5){
						go(103, 5);
						printf(" ");
						go(1, 1);
						printf(">");
						x = 3, y = 1;
					}
					else if (y == 23){
						go(105, 23);
						printf(" ");
						go(1, 1);
						printf(">");
						x = 3, y = 1;
					}
				}
				break;
			}
			case right:{
				if (x != 105 && x != 107){
					go(1, 1);
					printf(" ");
					go(103, 1);
					printf(">");
					x = 105, y = 1;
				}
				break;
			}
			case submit:
				return y + x;
			}
		}
	}
	else if(enforce_easy > 0 && breaking == 0){
		int x = 105, y = 5;
		if (enforce_easy <= 28){
			go(103, 5);
			printf(">");
		}
		while (1){
			int a = keyControl();
			switch (a){
			case up:{
				if (y > 1 && enforce_easy <= 27){
					if (y == 5){
						go(103, 5);
						printf(" ");
						go(103, 1);
						printf(">");
						x = 105, y = 1;
					}
				}
				break;
			}
			case down:{
				if (y < 23){
					if (y == 1 && x == 105){
						go(103, 1);
						printf(" ");
						go(103, 5);
						printf(">");
						x = 105, y = 5;
					}
				}
				break;
			}
			case left:{
				if (enforce_easy < 2){
					if (x != 3){
						if (y == 1){
							go(103, 1);
							printf(" ");
							go(1, 1);
							printf(">");
							x = 3, y = 1;
						}
						else if (y == 5){
							go(103, 5);
							printf(" ");
							go(1, 1);
							printf(">");
							x = 3, y = 1;
						}
						else if (y == 23){
							go(105, 23);
							printf(" ");
							go(1, 1);
							printf(">");
							x = 3, y = 1;
						}
					}
				}
				else if (enforce_easy >= 19){
					if (x != 4){
						if (y == 1){
							go(103, 1);
							printf(" ");
							go(2, 1);
							printf(">");
							x = 4, y = 1;
						}
						else if (y == 5){
							go(103, 5);
							printf(" ");
							go(2, 1);
							printf(">");
							x = 4, y = 1;
						}
						else if (y == 23){
							go(105, 23);
							printf(" ");
							go(2, 1);
							printf(">");
							x = 4, y = 1;
						}
					}
				}
				break;
			}
			case right:{
				if (x != 105 && x != 107){
					go(2, 1);
					printf(" ");
					go(103, 1);
					printf(">");
					x = 105, y = 1;
				}
				break;
			}

			case submit:{
				if (enforce_easy <= 28){
					return y + x;
				}
			}
			}
		}
	}
	else if (breaking == 1){
		int x = 100, y = 5;
		while (1){
			int a = keyControl();
			switch (a){
			case up:{
				if (y > 1 && enforce_easy <= 25){
					if (y == 5){
						go(98, 5);
						printf(" ");
						go(100, 1);
						printf(">");
						x = 102, y = 1;
					}
				}
				break;
			}
			case down:{
				if (y < 23){
					if (y == 1){
						go(100, 1);
						printf(" ");
						go(98, 5);
						printf(">");
						x = 100, y = 5;
					}
				}
				break;
			}
			case left:{
				if (enforce_easy >= 6){
					if (x == 100 && y == 5) {
						go(98, 5);
						printf(" ");
						go(30, 14);
						printf(">");
						x = 32, y = 14;
					}
				}
				break;
			}
			case right: {
				if (enforce_easy >= 6) {
					if (x == 32 && y == 14) {
						go(30, 14);
						printf(" ");
						go(98, 5);
						printf(">");
						x = 100, y = 5;
					}
				}
				break;
			}
			case submit:
				return y + x;
			}
		}
	}
}
void title_easy(){
	go(3, 1);
	printf("������â����");
	go(3, 5);
	printf("��ȭ���: 300��");
	go(3, 6);
	printf("�ǸŰ���: 0��");
	go(3, 7);
	printf("������: 100%%");
	go(105, 5);
	printf("��ȭ�ϱ�");
	go(107, 23);
	printf("������");
	go(105, 1);
	printf("��������");
	go(3, 22);
	printf("������: ");
	go(3, 23);
	printf("��: ");
	go(50, 17);
	printf("+0 ���� �ܰ�");
	go(103, 5);
	printf(">");
}
int item_easy(){
	system("cls");
	while (1){
		game_money_easy();
		go(30, 3);
		printf("��Ǫ�ƻ�: %d��", Wang_Puasha);
		go(30, 7);
		printf("�ٻ���: %d��", multicolored_sword);
		go(30, 11);
		printf("���佺Ʈ ���: %d��", tempest_gold);
		go(30, 15);
		printf("���� ��Ŀ: %d��", sharp_walker);
		go(30, 19);
		printf("�ǿ����� �ְ�: %d��", Pierrot_Dual_Swords);
		go(68, 3);
		printf("���浵: %d��", Doryongdo);
		go(68, 7);
		printf("�� ���غ��̴� ��: %d��", ��_���غ��̴�_��);
		go(68, 11);
		printf("�޵λ�: %d��", medusa);
		go(68, 15);
		printf("�������� �ҵ�: %d��", Odyssey_Sword);
		go(68, 19);
		printf("������Į: %d��", Mosaic_knife);
		go(3, 22);
		printf("������: ");
		go(3, 23);
		printf("��: ");
		go(107, 23);
		printf("������");
		go(105, 23);
		printf(">");
		int a = keyControl();
		if (a == 5){
			game_easy();
		}
	}
}
int shop_easy_menu(){
	system("cls");
	go(21, 5);
	printf(">");
	while (1){
		game_money_easy();
		go(23, 5);
		printf("+9�� ������: 1,000,000��");
		go(23, 10);
		printf("+13�� ������: 7,000,000��");
		go(23, 15);
		printf("+14�� ������: 10,000,000��");
		go(68, 5);
		printf("���� ������ 1��: 1,000,000��");
		go(68, 10);
		printf("���� ������ 3��: 2,500,000��");
		go(68, 15);
		printf("+15�� ������: 15,000,000��");
		go(3, 22);
		printf("������: ");
		go(3, 23);
		printf("��: ");
		go(107, 23);
		printf("������");
		int menuCode2 = shop_easy();
		switch (menuCode2){
		case 130:{
			game_easy();
		}
		break;
		case 28:{
			if ((((r >= 1 || e >= 1) || w >= 1) || q >= 1)){
				warp = 1;
				r -= 1;
				enforce_easy = 9;
				sword_easy();
			}
		}
		break;
		case 33:{
			if ((((r >= 7 || e >= 1) || w >= 1) || q >= 1)){
				warp = 1;
				r -= 7;
				enforce_easy = 13;
				sword_easy();
			}
		}
		break;
		case 38:{
			if ((((r >= 10 || e >= 1) || w >= 1) || q >= 1)){
				warp = 1;
				r -= 10;
				enforce_easy = 14;
				sword_easy();
			}
		}
		break;
		case 73:{
			if ((((r >= 1 || e >= 1) || w >= 1) || q >= 1)){
				r -= 1;
				right_to_prevent += 1;
			}
		}
		break;
		case 78:{
			if ((((r >= 3 || (t >= 500 && r >= 2) || e >= 1) || w >= 1) || q >= 1)){
				r -= 2;
				t -= 500;
				right_to_prevent += 3;
			}
		}
		break;
		case 83:{
			if ((((r >= 15 || e >= 1) || w >= 1) || q >= 1)){
				warp = 1;
				r -= 15;
				enforce_easy = 15;
				sword_easy();
			}
		}
		break;
		}
	}
}
int shop_easy(){
	int x = 23, y = 5;
	while (1){
		int a = keyControl();
		switch (a){
		case up:{
			if (y > 5 && y != 23){
				go(x - 2, y);
				printf(" ");
				go(x - 2, y - 5);
				printf(">");
				y -= 5;
			}
			else if (x == 107){
				go(x - 2, y);
				printf(" ");
				go(x - 41, y - 8);
				printf(">");
				x -= 39;
				y -= 8;
			}
			break;
		}
		case down:{
			if (y < 15){
				go(x - 2, y);
				printf(" ");
				go(x - 2, y + 5);
				printf(">");
				y += 5;
			}
			else if (x == 23 && y == 15){
				go(x - 2, y);
				printf(" ");
				go(x + 82, y + 8);
				printf(">");
				x += 84;
				y += 8;
			}
			else if (x == 68 && y == 15){
				go(x - 2, y);
				printf(" ");
				go(x + 37, y + 8);
				printf(">");
				x += 39;
				y += 8;
			}
			break;
		}
		case left:{
			if (x == 68){
				go(x - 2, y);
				printf(" ");
				go(x - 47, y);
				printf(">");
				x -= 45;
			}
			break;
		}
		case right:{
			if (x == 23){
				go(x - 2, y);
				printf(" ");
				go(x + 43, y);
				printf(">");
				x += 45;
			}
			break;
		}
		case submit:{
			go(x - 2, y);
			printf(" ");
			go(21, 5);
			printf(">");
			return x + y;
		}
		}
	}
}
int game_money_easy(){
	int i;
	go(11, 22);
	printf("%d��", right_to_prevent);
	go(7, 23);
	for (i = 0; i <= 5; i++){
		while (y < 0 && ((((t > 0 || r > 0) || e > 0) || w > 0) || q > 0)){
			y += 1000;
			t -= 1;
		}
		while (t < 0 && (((r > 0 || e > 0) || w > 0) || q > 0)){
			t += 1000;
			r -= 1;
		}
		while (r < 0 && ((e > 0 || w > 0) || q > 0)){
			r += 1000;
			e -= 1;
		}
		while (e < 0 && (w > 0 || q > 0)){
			e += 1000;
			w -= 1;
		}
		while (w < 0 && q > 0){
			w += 1000;
			q -= 1;
		}
		while (y > 999){
			y -= 1000;
			t += 1;
		}
		while (t > 999){
			t -= 1000;
			r += 1;
		}
		while (r > 999){
			r -= 1000;
			e += 1;
		}
		while (e > 999){
			e -= 1000;
			w += 1;
		}
		while (w > 999){
			w -= 1000;
			q += 1;
		}
		int money1[6] = { q,w,e,r,t,y };
		if (money1[i] != 0){
			if (i == 0){
				printf("%d,%03d,%03d,%03d,%03d,%03d��", money1[0], money1[1], money1[2], money1[3], money1[4], money1[5]);
				break;
			}
			else if (i == 1){
				printf("%d,%03d,%03d,%03d,%03d��    ", money1[1], money1[2], money1[3], money1[4], money1[5]);
				break;
			}
			else if (i == 2){
				printf("%d,%03d,%03d,%03d��        ", money1[2], money1[3], money1[4], money1[5]);
				break;
			}
			else if (i == 3){
				printf("%d,%03d,%03d��            ", money1[3], money1[4], money1[5]);
				break;
			}
			else if (i == 4){
				printf("%d,%03d��                ", money1[4], money1[5]);
				break;
			}
			else if (i == 5){
				printf("%d��                        ", money1[5]);
				break;
			}
		}
		else if (money1[0] == 0 && money1[1] == 0 && money1[2] == 0 && money1[3] == 0 && money1[4] == 0 && money1[5] == 0){
			printf("%d��                        ", money1[5]);
			break;
		}
	}
}
int sword_sell_easy(){
	if (enforce_easy == 1)
		y += 150;
	else if (enforce_easy == 2)
		y += 400;
	else if (enforce_easy == 3)
		y += 600;
	else if (enforce_easy == 4)
		y += 800;
	else if (enforce_easy == 5){
		t += 1;
		y += 600;
	}
	else if (enforce_easy == 6){
		t += 3;
		y += 500;
	}
	else if (enforce_easy == 7){
		t += 6;
		y += 100;
	}
	else if (enforce_easy == 8)
		t += 10;
	else if (enforce_easy == 9)
		t += 20;
	else if (enforce_easy == 10){
		t += 35;
		y += 100;
	}
	else if (enforce_easy == 11)
		t += 160;
	else if (enforce_easy == 12)
		t += 350;
	else if (enforce_easy == 13)
		r += 1;
	else if (enforce_easy == 14)
		r += 3;
	else if (enforce_easy == 15){
		r += 7;
		t += 500;
	}
	else if (enforce_easy == 16){
		r += 14;
		t += 200;
	}
	else if (enforce_easy == 17)
		r += 20;
	else if (enforce_easy == 18)
		r += 30;
	else if (enforce_easy == 19){
		r += 47;
		t += 500;
	}
	else if (enforce_easy == 20){
		r += 68;
		t += 300;
	}
	else if (enforce_easy == 21)
		r += 101;
	else if (enforce_easy == 22)
		r += 160;
	else if (enforce_easy == 23)
		r += 230;
	else if (enforce_easy == 24)
		r += 300;
	else if (enforce_easy == 25)
		r += 400;
	else if (enforce_easy == 26){
		e += 1;
		r += 800;
	}
	else if (enforce_easy == 27){
		e += 2;
		r += 500;
	}
}
int sword_prevent(){
	go(100, 1);
	printf(" ");
	if (enforce_easy <= 12 && right_to_prevent > 0){
		right_to_prevent -= 1;
		breaking = 0;
		sword_easy();
	}
	if (enforce_easy == 13 && right_to_prevent >= 2){
		right_to_prevent -= 2;
		breaking = 0;
		sword_easy();
	}
	if (enforce_easy == 14 && right_to_prevent >= 3){
		right_to_prevent -= 3;
		breaking = 0;
		sword_easy();
	}
	if (enforce_easy == 15 && right_to_prevent >= 4){
		right_to_prevent -= 4;
		breaking = 0;
		sword_easy();
	}
	if (enforce_easy == 16 && right_to_prevent >= 7){
		right_to_prevent -= 7;
		breaking = 0;
		sword_easy();
	}
	if (enforce_easy == 17 && right_to_prevent >= 9){
		right_to_prevent -= 9;
		breaking = 0;
		sword_easy();
	}
	if (enforce_easy == 18 && right_to_prevent >= 10){
		right_to_prevent -= 10;
		breaking = 0;
		sword_easy();
	}
	if (enforce_easy == 19 && right_to_prevent >= 12){
		right_to_prevent -= 12;
		breaking = 0;
		sword_easy();
	}
	if (enforce_easy == 20 && right_to_prevent >= 15){
		right_to_prevent -= 15;
		breaking = 0;
		sword_easy();
	}
	if (enforce_easy == 21 && right_to_prevent >= 17){
		right_to_prevent -= 17;
		breaking = 0;
		sword_easy();
	}
	if (enforce_easy == 22 && right_to_prevent >= 20){
		right_to_prevent -= 20;
		breaking = 0;
		sword_easy();
	}
	if (enforce_easy == 23 && right_to_prevent >= 22){
		right_to_prevent -= 22;
		breaking = 0;
		sword_easy();
	}
	if ((enforce_easy == 24 || enforce_easy == 25) && right_to_prevent >= 23){
		right_to_prevent -= 23;
		breaking = 0;
		sword_easy();
	}
}
int sword_breaking(){
	system("cls");
	if (((enforce_easy == 6 || enforce_easy == 7) || enforce_easy == 8) && sword_piece_add == 0){
		srand((unsigned int)clock(NULL));
		int percent = rand() % 100;
		if (percent < 10){
			go(32, 14);
			printf("�����Һи� ö���� 5�� �ݱ�");
			Iron_sculpture_of_unknown_nationality = 5;
		}
		else if (percent < 20){
			go(32, 14);
			printf("�����Һи� ö���� 4�� �ݱ�");
			Iron_sculpture_of_unknown_nationality = 4;
		}
		else if (percent < 25){
			go(32, 14);
			printf("�����Һи� ö���� 3�� �ݱ�");
			Iron_sculpture_of_unknown_nationality = 3;
		}
		else if (percent < 30){
			go(32, 14);
			printf("�����Һи� ö���� 2�� �ݱ�");
			Iron_sculpture_of_unknown_nationality = 2;
		}
		else if (percent < 80){
			go(32, 14);
			printf("�����Һи� ö���� 1�� �ݱ�");
			Iron_sculpture_of_unknown_nationality = 1;
		}
		else if (percent <= 100){
			go(32, 14);
			printf("�����Һи� ö���� 0�� �ݱ�");
		}
	}
	if (enforce_easy == 9 && sword_piece_add == 0){
		srand((unsigned int)clock(NULL));
		int percent = rand() % 100;
		if (percent < 10){
			go(32, 14);
			printf("Ÿ���� �� �ν����� 5�� �ݱ�");
			tau_Bone_Crumb = 5;
		}
		else if (percent < 20){
			go(32, 14);
			printf("Ÿ���� �� �ν����� 4�� �ݱ�");
			tau_Bone_Crumb = 4;
		}
		else if (percent < 25){
			go(32, 14);
			printf("Ÿ���� �� �ν����� 3�� �ݱ�");
			tau_Bone_Crumb = 3;
		}
		else if (percent < 30){
			go(32, 14);
			printf("Ÿ���� �� �ν����� 2�� �ݱ�");
			tau_Bone_Crumb = 2;
		}
		else if (percent < 80){
			go(32, 14);
			printf("Ÿ���� �� �ν����� 1�� �ݱ�");
			tau_Bone_Crumb = 1;
		}
		else if(percent <= 100){
			go(32, 14);
			printf("Ÿ���� �� �ν����� 0�� �ݱ�");
		}
	}
	if (enforce_easy == 10 && sword_piece_add == 0){
		srand((unsigned int)clock(NULL));
		int percent = rand() % 100;
		if (percent < 10){
			go(32, 14);
			printf("�� �ٷ� �������� 5�� �ݱ�");
			faded_fluorescent_material = 5;
		}
		else if (percent < 20){
			go(32, 14);
			printf("�� �ٷ� �������� 4�� �ݱ�");
			faded_fluorescent_material = 4;
		}
		else if (percent < 25){
			go(32, 14);
			printf("�� �ٷ� �������� 3�� �ݱ�");
			faded_fluorescent_material = 3;
		}
		else if (percent < 30){
			go(32, 14);
			printf("�� �ٷ� �������� 2�� �ݱ�");
			faded_fluorescent_material = 2;
		}
		else if (percent < 80){
			go(32, 14);
			printf("�� �ٷ� �������� 1�� �ݱ�");
			faded_fluorescent_material = 1;
		}
		else if (percent <= 100){
			go(32, 14);
			printf("�� �ٷ� �������� 0�� �ݱ�");
		}
	}
	if ((enforce_easy == 11 || enforce_easy == 12) && sword_piece_add == 0){
		srand((unsigned int)clock(NULL));
		int percent = rand() % 100;
		if (percent < 10){
			go(32, 14);
			printf("�������� ö���� 5�� �ݱ�");
			swiss_iron = 5;
		}
		else if (percent < 20){
			go(32, 14);
			printf("�������� ö���� 4�� �ݱ�");
			swiss_iron = 4;
		}
		else if (percent < 25){
			go(32, 14);
			printf("�������� ö���� 3�� �ݱ�");
			swiss_iron = 3;
		}
		else if (percent < 30){
			go(32, 14);
			printf("�������� ö���� 2�� �ݱ�");
			swiss_iron = 2;
		}
		else if (percent < 80){
			go(32, 14);
			printf("�������� ö���� 1�� �ݱ�");
			swiss_iron = 1;
		}
		else if (percent <= 100){
			go(32, 14);
			printf("�������� ö���� 0�� �ݱ�");
		}
	}
	if (enforce_easy == 13 && sword_piece_add == 0){
		srand((unsigned int)clock(NULL));
		int percent = rand() % 100;
		if (percent < 10){
			go(32, 14);
			printf("�Ҳɸ��� ������ 5�� �ݱ�");
			flame_sword_handle = 5;
		}
		else if (percent < 20){
			go(32, 14);
			printf("�Ҳɸ��� ������ 4�� �ݱ�");
			flame_sword_handle = 4;
		}
		else if (percent < 25){
			go(32, 14);
			printf("�Ҳɸ��� ������ 3�� �ݱ�");
			flame_sword_handle = 3;
		}
		else if (percent < 30){
			go(32, 14);
			printf("�Ҳɸ��� ������ 2�� �ݱ�");
			flame_sword_handle = 2;
		}
		else if (percent < 80){
			go(32, 14);
			printf("�Ҳɸ��� ������ 1�� �ݱ�");
			flame_sword_handle = 1;
		}
		else if (percent <= 100){
			go(32, 14);
			printf("�Ҳɸ��� ������ 0�� �ݱ�");
		}
	}
	if (enforce_easy == 14 && sword_piece_add == 0){
		srand((unsigned int)clock(NULL));
		int percent = rand() % 100;
		if (percent < 10){
			go(32, 14);
			printf("����� ��ȥ 5�� �ݱ�");
			evil_spirit = 5;
		}
		else if (percent < 20){
			go(32, 14);
			printf("����� ��ȥ 4�� �ݱ�");
			evil_spirit = 4;
		}
		else if (percent < 25){
			go(32, 14);
			printf("����� ��ȥ 3�� �ݱ�");
			evil_spirit = 3;
		}
		else if (percent < 30){
			go(32, 14);
			printf("����� ��ȥ 2�� �ݱ�");
			evil_spirit = 2;
		}
		else if (percent < 80){
			go(32, 14);
			printf("����� ��ȥ 1�� �ݱ�");
			evil_spirit = 1;
		}
		else if (percent <= 100){
			go(32, 14);
			printf("����� ��ȥ 0�� �ݱ�");
		}
	}
	if (enforce_easy == 15 && sword_piece_add == 0){
		srand((unsigned int)clock(NULL));
		int percent = rand() % 100;
		if (percent < 10){
			go(32, 14);
			printf("���� ���� 5�� �ݱ�");
			ax_powder = 5;
		}
		else if (percent < 20){
			go(32, 14);
			printf("���� ���� 4�� �ݱ�");
			ax_powder = 4;
		}
		else if (percent < 25){
			go(32, 14);
			printf("���� ���� 3�� �ݱ�");
			ax_powder = 3;
		}
		else if (percent < 30){
			go(32, 14);
			printf("���� ���� 2�� �ݱ�");
			ax_powder = 2;
		}
		else if (percent < 80){
			go(32, 14);
			printf("���� ���� 1�� �ݱ�");
			ax_powder = 1;
		}
		else if (percent <= 100){
			go(32, 14);
			printf("���� ���� 0�� �ݱ�");
		}
	}
	if (enforce_easy == 16 && sword_piece_add == 0){
		srand((unsigned int)clock(NULL));
		int percent = rand() % 100;
		if (percent < 10){
			go(32, 14);
			printf("���� ���� 5�� �ݱ�");
			transparent_material = 5;
		}
		else if (percent < 20){
			go(32, 14);
			printf("���� ���� 4�� �ݱ�");
			transparent_material = 4;
		}
		else if (percent < 25){
			go(32, 14);
			printf("���� ���� 3�� �ݱ�");
			transparent_material = 3;
		}
		else if (percent < 30){
			go(32, 14);
			printf("���� ���� 2�� �ݱ�");
			transparent_material = 2;
		}
		else if (percent < 80){
			go(32, 14);
			printf("���� ���� 1�� �ݱ�");
			transparent_material = 1;
		}
		else if (percent <= 100){
			go(32, 14);
			printf("���� ���� 0�� �ݱ�");
		}
	}
	while (1){
		game_money_easy();
		go(41, 11);
		printf("��ȭ�� �����Ͽ� ���� �ı��Ǿ����ϴ�.");
		if (enforce_easy == 3){
			go(32, 12);
			printf("+3 ����ŷ �ҵ�� ������ �ϳ��� ����Ͽ� �츱 �� �ֽ��ϴ�.");
		}
		if (enforce_easy == 4){
			go(32, 12);
			printf("+4 ��Ÿ�� ���� ������ �ϳ��� ����Ͽ� �츱 �� �ֽ��ϴ�.");
		}
		if (enforce_easy == 5){
			go(32, 12);
			printf("+5 �ñ��� �ҵ�� ������ �ϳ��� ����Ͽ� �츱 �� �ֽ��ϴ�.");
		}
		if (enforce_easy == 6){
			go(32, 12);
			printf("+6 �糯���� ������ �ϳ��� ����Ͽ� �츱 �� �ֽ��ϴ�.");
		}
		if (enforce_easy == 7){
			go(32, 12);
			printf("+7 �������� ����� ������ �ϳ��� ����Ͽ� �츱 �� �ֽ��ϴ�.");
		}
		if (enforce_easy == 8){
			go(32, 12);
			printf("+8 ������ ���� ������ �ϳ��� ����Ͽ� �츱 �� �ֽ��ϴ�.");
		}
		if (enforce_easy == 9){
			go(32, 12);
			printf("+9 Ÿ�� ������� ������ �ϳ��� ����Ͽ� �츱 �� �ֽ��ϴ�.");
		}
		if (enforce_easy == 10){
			go(32, 12);
			printf("+10 �������� ������ �ϳ��� ����Ͽ� �츱 �� �ֽ��ϴ�.");
		}
		if (enforce_easy == 11){
			go(32, 12);
			printf("+11 �ǹ��� ���� ������ �ϳ��� ����Ͽ� �츱 �� �ֽ��ϴ�.");
		}
		if (enforce_easy == 12){
			go(32, 12);
			printf("+12 ȭ���� �ְ��� ������ �ϳ��� ����Ͽ� �츱 �� �ֽ��ϴ�.");
		}
		if (enforce_easy == 13){
			go(32, 12);
			printf("+13 �Ҳ� ������ ������ �ΰ��� ����Ͽ� �츱 �� �ֽ��ϴ�.");
		}
		if (enforce_easy == 14){
			go(32, 12);
			printf("+14 ���� �����ǽ��� ������ ������ ����Ͽ� �츱 �� �ֽ��ϴ�.");
		}
		if (enforce_easy == 15){
			go(32, 12);
			printf("+15 ���� ��Ʋ ������ ������ �װ��� ����Ͽ� �츱 �� �ֽ��ϴ�.");
		}
		if (enforce_easy == 16){
			go(32, 12);
			printf("+16 ���� ���� ������ �ϰ����� ����Ͽ� �츱 �� �ֽ��ϴ�.");
		}
		if (enforce_easy == 17){
			go(32, 12);
			printf("+17 ������ ����� ������ ��ȩ���� ����Ͽ� �츱 �� �ֽ��ϴ�.");
		}
		if (enforce_easy == 18){
			go(32, 12);
			printf("+18 ���̴� �ҵ�� ������ ������ ����Ͽ� �츱 �� �ֽ��ϴ�.");
		}
		if (enforce_easy == 19){
			go(32, 12);
			printf("+19 ��Ǫ�ƻ��� ������ ���ΰ��� ����Ͽ� �츱 �� �ֽ��ϴ�.");
		}
		if (enforce_easy == 20){
			go(32, 12);
			printf("+20 �ٻ����� ������ ���ټ����� ����Ͽ� �츱 �� �ֽ��ϴ�.");
		}
		if (enforce_easy == 21){
			go(32, 12);
			printf("+21 ���佺Ʈ ���� ������ ���ϰ����� ����Ͽ� �츱 �� �ֽ��ϴ�.");
		}
		if (enforce_easy == 22){
			go(32, 12);
			printf("+22 ���� ��Ŀ�� ������ �������� ����Ͽ� �츱 �� �ֽ��ϴ�.");
		}
		if (enforce_easy == 23){
			go(32, 12);
			printf("+23 �ǿ����� �ְ��� ������ �����ΰ��� ����Ͽ� �츱 �� �ֽ��ϴ�.");
		}
		if (enforce_easy == 24){
			go(32, 12);
			printf("+24 ���浵�� ������ ���������� ����Ͽ� �츱 �� �ֽ��ϴ�.");
		}
		if (enforce_easy == 25){
			go(32, 12);
			printf("+25 �� ���غ��̴� ���� ������ ���������� ����Ͽ� �츱 �� �ֽ��ϴ�.");
		}
		if (enforce_easy >= 26)
			printf("���� �ǻ츱 �� �����ϴ�.");
		go(30, 14);
		printf(" ");
		if (enforce_easy <= 25){
			go(102, 1);
			printf("�� �ǻ츮��");
		}
		go(100, 5);
		printf("��ȭ �����ϱ�");
		go(98, 5);
		printf(">");
		go(3, 22);
		printf("������: ");
		go(3, 23);
		printf("��: ");
		if (((enforce_easy == 6 || enforce_easy == 7) || enforce_easy == 8) && (Iron_sculpture_of_unknown_nationality == 0 && sword_piece_add == 1)){
			go(32, 14);
			printf("�����Һи� ö���� 0�� �ݱ�");
		}
		if ((enforce_easy == 9 && tau_Bone_Crumb == 0) && sword_piece_add == 1){
			go(32, 14);
			printf("Ÿ���� �� �ν����� 0�� �ݱ�");
		}
		if ((enforce_easy == 10 && faded_fluorescent_material == 0) && sword_piece_add == 1){
			go(32, 14);
			printf("�� �ٷ� �������� 0�� �ݱ�");
		}
		if (((enforce_easy == 11 || enforce_easy == 12) && swiss_iron == 0) && sword_piece_add == 1){
			go(32, 14);
			printf("�������� ö���� 0�� �ݱ�");
		}
		if ((enforce_easy == 13 && flame_sword_handle == 0) && sword_piece_add == 1){
			go(32, 14);
			printf("�Ҳɸ��� ������ 0�� �ݱ�");
		}
		if ((enforce_easy == 14 && evil_spirit == 0) && sword_piece_add == 1){
			go(32, 14);
			printf("����� ��ȥ 0�� �ݱ�");
		}
		if ((enforce_easy == 15 && ax_powder == 0) && sword_piece_add == 1){
			go(32, 14);
			printf("���� ���� 0�� �ݱ�");
		}
		if ((enforce_easy == 16 && transparent_material == 0) && sword_piece_add == 1){
			go(32, 14);
			printf("���� ���� 0�� �ݱ�");
		}
		if (sword_piece_add == 1)
			sword_piece_add = 0;
		int menuCode1 = easy();
		if (menuCode1 == 103)
			sword_prevent();
		else if (menuCode1 == 105){
			enforce_easy = 0;
			breaking = 0;
			game_easy();
		}
		else if (menuCode1 == 46){
			sword_piece();
		}
	}
}
int sword_piece(){
	if (Iron_sculpture_of_unknown_nationality == 1){
		Iron_sculpture_of_unknown_nationality_add += 1;
		Iron_sculpture_of_unknown_nationality = 0;
		sword_piece_add = 1;
	}
	else if (Iron_sculpture_of_unknown_nationality == 2){
		Iron_sculpture_of_unknown_nationality_add += 2;
		Iron_sculpture_of_unknown_nationality = 0;
		sword_piece_add = 1;
	}
	else if (Iron_sculpture_of_unknown_nationality == 3){
		Iron_sculpture_of_unknown_nationality_add += 3;
		Iron_sculpture_of_unknown_nationality = 0;
		sword_piece_add = 1;
	}
	else if (Iron_sculpture_of_unknown_nationality == 4){
		Iron_sculpture_of_unknown_nationality_add += 4;
		Iron_sculpture_of_unknown_nationality = 0;
		sword_piece_add = 1;
	}
	else if (Iron_sculpture_of_unknown_nationality == 5){
		Iron_sculpture_of_unknown_nationality_add += 5;
		Iron_sculpture_of_unknown_nationality = 0;
		sword_piece_add = 1;
	}
	else if (Iron_sculpture_of_unknown_nationality == 0)
		sword_piece_add = 1;
	if (tau_Bone_Crumb == 1){
		tau_Bone_Crumb_add += 1;
		tau_Bone_Crumb = 0;
		sword_piece_add = 1;
	}
	else if (tau_Bone_Crumb == 2){
		tau_Bone_Crumb_add += 2;
		tau_Bone_Crumb = 0;
		sword_piece_add = 1;
	}
	else if (tau_Bone_Crumb == 3){
		tau_Bone_Crumb_add += 3;
		tau_Bone_Crumb = 0;
		sword_piece_add = 1;
	}
	else if (tau_Bone_Crumb == 4){
		tau_Bone_Crumb_add += 4;
		tau_Bone_Crumb = 0;
		sword_piece_add = 1;
	}
	else if (tau_Bone_Crumb == 5){
		tau_Bone_Crumb_add += 5;
		tau_Bone_Crumb = 0;
		sword_piece_add = 1;
	}
	else if (tau_Bone_Crumb == 0)
		sword_piece_add = 1;
	if (faded_fluorescent_material == 1){
		faded_fluorescent_material_add += 1;
		faded_fluorescent_material = 0;
		sword_piece_add = 1;
	}
	else if (faded_fluorescent_material == 2){
		faded_fluorescent_material_add += 2;
		faded_fluorescent_material = 0;
		sword_piece_add = 1;
	}
	else if (faded_fluorescent_material == 3){
		faded_fluorescent_material_add += 3;
		faded_fluorescent_material = 0;
		sword_piece_add = 1;
	}
	else if (faded_fluorescent_material == 4){
		faded_fluorescent_material_add += 4;
		faded_fluorescent_material = 0;
		sword_piece_add = 1;
	}
	else if (faded_fluorescent_material == 5){
		faded_fluorescent_material_add += 5;
		faded_fluorescent_material = 0;
		sword_piece_add = 1;
	}
	else if (faded_fluorescent_material == 0)
		sword_piece_add = 1;
	if (swiss_iron == 1){
		swiss_iron_add += 1;
		swiss_iron = 0;
		sword_piece_add = 1;
	}
	else if (swiss_iron == 2){
		swiss_iron_add += 2;
		swiss_iron = 0;
		sword_piece_add = 1;
	}
	else if (swiss_iron == 3){
		swiss_iron_add += 3;
		swiss_iron = 0;
		sword_piece_add = 1;
	}
	else if (swiss_iron == 4){
		swiss_iron_add += 4;
		swiss_iron = 0;
		sword_piece_add = 1;
	}
	else if (swiss_iron == 5)
	{
		swiss_iron_add += 5;
		swiss_iron = 0;
		sword_piece_add = 1;
	}
	else if (swiss_iron == 0)
		sword_piece_add = 1;
	if (flame_sword_handle == 1){
		flame_sword_handle_add += 1;
		flame_sword_handle = 0;
		sword_piece_add = 1;
	}
	else if (flame_sword_handle == 2){
		flame_sword_handle_add += 2;
		flame_sword_handle = 0;
		sword_piece_add = 1;
	}
	else if (flame_sword_handle == 3){
		flame_sword_handle_add += 3;
		flame_sword_handle = 0;
		sword_piece_add = 1;
	}
	else if (flame_sword_handle == 4){
		flame_sword_handle_add += 4;
		flame_sword_handle = 0;
		sword_piece_add = 1;
	}
	else if (flame_sword_handle == 5){
		flame_sword_handle_add += 5;
		flame_sword_handle = 0;
		sword_piece_add = 1;
	}
	else if (flame_sword_handle == 0)
		sword_piece_add = 1;
	if (evil_spirit == 1){
		evil_spirit_add += 1;
		evil_spirit = 0;
		sword_piece_add = 1;
	}
	else if (evil_spirit == 2){
		evil_spirit_add += 2;
		evil_spirit = 0;
		sword_piece_add = 1;
	}
	else if (evil_spirit == 3){
		evil_spirit_add += 3;
		evil_spirit = 0;
		sword_piece_add = 1;
	}
	else if (evil_spirit == 4){
		evil_spirit_add += 4;
		evil_spirit = 0;
		sword_piece_add = 1;
	}
	else if (evil_spirit == 5){
		evil_spirit_add += 5;
		evil_spirit = 0;
		sword_piece_add = 1;
	}
	else if (evil_spirit == 0)
		sword_piece_add = 1;
	if (ax_powder == 1){
		ax_powder_add += 1;
		ax_powder = 0;
		sword_piece_add = 1;
	}
	else if (ax_powder == 2){
		ax_powder_add += 2;
		ax_powder = 0;
		sword_piece_add = 1;
	}
	else if (ax_powder == 3){
		ax_powder_add += 3;
		ax_powder = 0;
		sword_piece_add = 1;
	}
	else if (ax_powder == 4){
		ax_powder_add += 4;
		ax_powder = 0;
		sword_piece_add = 1;
	}
	else if (ax_powder == 5){
		ax_powder_add += 5;
		ax_powder = 0;
		sword_piece_add = 1;
	}
	else if (ax_powder == 0)
		sword_piece_add = 1;
	if (transparent_material == 1){
		transparent_material_add += 1;
		transparent_material = 0;
		sword_piece_add = 1;
	}
	else if (transparent_material == 2){
		transparent_material_add += 2;
		transparent_material = 0;
		sword_piece_add = 1;
	}
	else if (transparent_material == 3){
		transparent_material_add += 3;
		transparent_material = 0;
		sword_piece_add = 1;
	}
	else if (transparent_material == 4){
		transparent_material_add += 4;
		transparent_material = 0;
		sword_piece_add = 1;
	}
	else if (transparent_material == 5){
		transparent_material_add += 5;
		transparent_material = 0;
		sword_piece_add = 1;
	}
	else if (transparent_material == 0)
		sword_piece_add = 1;
	sword_breaking();
}
int sword_easy(){
	system("cls");
	while (1){
		game_money_easy();
		if (enforce_easy < 2){
			go(3, 1);
			printf("���ռҰ���");
		}
		if (enforce_easy >= 19){
			go(4, 1);
			printf("�����ϱ�");
		}
		go(3, 5);
		printf("��ȭ���: ");
		go(3, 6);
		printf("�ǸŰ���: ");
		if (enforce_easy <= 28){
			go(105, 5);
			printf("��ȭ�ϱ�");
		}
		if (enforce_easy <= 27){
			go(105, 1);
			printf("�Ǹ��ϱ�");
		}
		go(3, 22);
		printf("������: ");
		go(3, 23);
		printf("��: ");
		go(103, 5);
		printf(" ");
		if (enforce_easy < 2){
			go(50, 17);
			printf("+1 ������ �ܰ�");
			go(13, 5);
			printf("300��");
			go(13, 6);
			printf("150��");
			go(3, 7);
			printf("������: 100%%");
		}
		if (enforce_easy == 9 && warp == 1){
			go(50, 17);
			printf("+9 Ÿ�� ������");
			go(13, 5);
			printf("5,000��");
			go(13, 6);
			printf("20,000��");
			go(3, 7);
			printf("������: 80%%");
			warp = 0;
		}
		if (enforce_easy == 13 && warp == 1){
			go(50, 17);
			printf("+13 �Ҳ� ����");
			go(13, 5);
			printf("55,000��");
			go(13, 6);
			printf("1,000,000��");
			go(3, 7);
			printf("������: 70%%");
			warp = 0;
		}
		if (enforce_easy == 14 && warp == 1){
			go(50, 17);
			printf("+14 ���� �����ǽ�");
			go(13, 5);
			printf("100,000��");
			go(13, 6);
			printf("3,000,000��");
			go(3, 7);
			printf("������: 65%%");
			warp = 0;
		}
		if (enforce_easy == 15 && warp == 1){
			go(50, 17);
			printf("+15 ���� ��Ʋ ����");
			go(13, 5);
			printf("180,000��");
			go(13, 6);
			printf("7,500,000��");
			go(3, 7);
			printf("������: 60%%");
			warp = 0;
		}
		if (enforce_easy == 16 && warp == 1){
			go(50, 17);
			printf("+16 ���� ��");
			go(13, 5);
			printf("300,000��");
			go(13, 6);
			printf("14,200,000��");
			go(3, 7);
			printf("������: 60%%");
			warp = 0;
		}
		if (enforce_easy == 19 && warp == 1){
			go(50, 17);
			printf("+19 ��Ǫ�ƻ�");
			go(13, 5);
			printf("800,000��");
			go(13, 6);
			printf("47,500,000��");
			go(3, 7);
			printf("������: 50%%");
			warp = 0;
		}
		if (enforce_easy == 3){
			go(50, 17);
			printf("+3 ����ŷ �ҵ�");
			go(13, 5);
			printf("500��");
			go(13, 6);
			printf("600��");
			go(3, 7);
			printf("������: 95%% ");
		}
		if (enforce_easy == 4){
			go(50, 17);
			printf("+4 ��Ÿ�� ��");
			go(13, 5);
			printf("1,000��");
			go(13, 6);
			printf("800��");
			go(3, 7);
			printf("������: 95%%");
		}
		if (enforce_easy == 5){
			go(50, 17);
			printf("+5 �ñ��� �ҵ�");
			go(13, 5);
			printf("1,500��");
			go(13, 6);
			printf("1,600��");
			go(3, 7);
			printf("������: 90%%");
		}
		if (enforce_easy == 6){
			go(50, 17);
			printf("+6 �糯 ��");
			go(13, 5);
			printf("2,000��");
			go(13, 6);
			printf("3,500��");
			go(3, 7);
			printf("������: 90%%");
		}
		if (enforce_easy == 7){
			go(50, 17);
			printf("+7 �������� ���");
			go(13, 5);
			printf("2,000��");
			go(13, 6);
			printf("6,100��");
			go(3, 7);
			printf("������: 90%%");
		}
		if (enforce_easy == 8){
			go(50, 17);
			printf("+8 ������ ��");
			go(13, 5);
			printf("3,000��");
			go(13, 6);
			printf("10,000��");
			go(3, 7);
			printf("������: 85%%");
		}
		if (enforce_easy == 9){
			go(50, 17);
			printf("+9 Ÿ�� ������");
			go(13, 5);
			printf("5,000��");
			go(13, 6);
			printf("20,000��");
			go(3, 7);
			printf("������: 80%%");
		}
		if (enforce_easy == 10){
			go(50, 17);
			printf("+10 ������");
			go(13, 5);
			printf("10,900��");
			go(13, 6);
			printf("35,100��");
			go(3, 7);
			printf("������: 80%%");
		}
		if (enforce_easy == 11){
			go(50, 17);
			printf("+11 �ǹ��� ��");
			go(13, 5);
			printf("20,000��");
			go(13, 6);
			printf("160,000��");
			go(3, 7);
			printf("������: 75%%");
		}
		if (enforce_easy == 12){
			go(50, 17);
			printf("+12 ȭ���� �ְ�");
			go(13, 5);
			printf("35,000��");
			go(13, 6);
			printf("350,000��");
			go(3, 7);
			printf("������: 70%%");
		}
		if (enforce_easy == 13){
			go(50, 17);
			printf("+13 �Ҳ� ����");
			go(13, 5);
			printf("55,000��");
			go(13, 6);
			printf("1,000,000��");
			go(3, 7);
			printf("������: 70%%");
		}
		if (enforce_easy == 14){
			go(50, 17);
			printf("+14 ���� �����ǽ�");
			go(13, 5);
			printf("100,000��");
			go(13, 6);
			printf("3,000,000��");
			go(3, 7);
			printf("������: 65%%");
		}
		if (enforce_easy == 15){
			go(50, 17);
			printf("+15 ���� ��Ʋ ����");
			go(13, 5);
			printf("180,000��");
			go(13, 6);
			printf("7,500,000��");
			go(3, 7);
			printf("������: 60%%");
		}
		if (enforce_easy == 16){
			go(50, 17);
			printf("+16 ���� ��");
			go(13, 5);
			printf("300,000��");
			go(13, 6);
			printf("14,200,000��");
			go(3, 7);
			printf("������: 60%%");
		}
		if (enforce_easy == 17){
			go(50, 17);
			printf("+17 ������ ���");
			go(13, 5);
			printf("300,000��");
			go(13, 6);
			printf("20,000,000��");
			go(3, 7);
			printf("������: 55%%");
		}
		if (enforce_easy == 18){
			go(50, 17);
			printf("+18 ���̴� �ҵ�");
			go(13, 5);
			printf("500,000��");
			go(13, 6);
			printf("30,000,000��");
			go(3, 7);
			printf("������: 50%%");
		}
		if (enforce_easy == 19){
			go(50, 17);
			printf("+19 ��Ǫ�ƻ�");
			go(13, 5);
			printf("800,000��");
			go(13, 6);
			printf("47,500,000��");
			go(3, 7);
			printf("������: 50%%");
		}
		if (enforce_easy == 20){
			go(50, 17);
			printf("+20 �ٻ���");
			go(13, 5);
			printf("1,500,000��");
			go(13, 6);
			printf("68,300,000��");
			go(3, 7);
			printf("������: 45%%");
		}
		if (enforce_easy == 21){
			go(50, 17);
			printf("+21 ���佺Ʈ ���");
			go(13, 5);
			printf("��Ǫ�ƻ� 1�ڷ�");
			go(13, 6);
			printf("101,000,000��");
			go(3, 7);
			printf("������: 40%%");
		}
		if (enforce_easy == 22){
			go(50, 17);
			printf("+22 ���� ��Ŀ");
			go(13, 5);
			printf("���佺Ʈ ��� 2�ڷ�");
			go(13, 6);
			printf("160,000,000��");
			go(3, 7);
			printf("������: 40%%");
		}
		if (enforce_easy == 23){
			go(50, 17);
			printf("+23 �ǿ����� �ְ�");
			go(13, 5);
			printf("����� ��ȥ 8��");
			go(13, 6);
			printf("230,000,000��");
			go(3, 7);
			printf("������: 40%%");
		}
		if (enforce_easy == 24){
			go(50, 17);
			printf("+24 ���浵");
			go(13, 5);
			printf("���� ��Ŀ 1�ڷ�");
			go(13, 6);
			printf("300,000,000��");
			go(3, 7);
			printf("������: 40%%");
		}
		if (enforce_easy == 25){
			go(50, 17);
			printf("+25 �� ���غ��̴� ��");
			go(13, 5);
			printf("���� ���� 15��");
			go(13, 6);
			printf("400,000,000��");
			go(3, 7);
			printf("������: 35%%");
		}
		int menuCode1 = easy();
		if (menuCode1 == 4)
			union_();
		else if (menuCode1 == 106){
			sword_sell_easy();
			enforce_easy = 0;
			game_easy();
		}
		else if (menuCode1 == 110)
			sword_enforce();
		else if (menuCode1 == 5){
			keep();
			enforce_easy = 0;
			game_easy();
		}
	}
}
int keep(){
	if (enforce_easy == 19)
		Wang_Puasha += 1;
	if (enforce_easy == 20)
		multicolored_sword += 1;
	if (enforce_easy == 21)
		tempest_gold += 1;
	if (enforce_easy == 22)
		sharp_walker += 1;
	if (enforce_easy == 23)
		Pierrot_Dual_Swords += 1;
	if (enforce_easy == 24)
		Doryongdo += 1;
	if (enforce_easy == 25)
		��_���غ��̴�_�� += 1;
	if (enforce_easy == 26)
		medusa += 1;
	if (enforce_easy == 27)
		Odyssey_Sword += 1;
	if (enforce_easy == 28)
		Mosaic_knife += 1;
}
int sword_enforce(){
	if (enforce_easy == 1 && (((((y >= 300 || t >= 1) || r >= 1) || e >= 1) || w >= 1) || q >= 1)){
		go(50, 17);
		printf("+2 �߰��� �ܰ�");
		go(13, 5);
		printf("500��");
		go(13, 6);
		printf("400��");
		go(3, 1);
		printf("          ");
		enforce_easy += 1;
		y -= 300;
	}
	else if (enforce_easy == 2 && (((((y >= 500 || t >= 1) || r >= 1) || e >= 1) || w >= 1) || q >= 1) ){
		go(50, 17);
		printf("+3 ����ŷ �ҵ�");
		go(13, 5);
		printf("500��");
		go(13, 6);
		printf("600��");
		go(3, 7);
		printf("������: 95%% ");
		enforce_easy += 1;
		y -= 500;
	}
	else if (enforce_easy == 3 && (((((y >= 500 || t >= 1) || r >= 1) || e >= 1) || w >= 1) || q >= 1)){
		srand((unsigned int)clock(NULL));
		int percent = rand() % 100;
		if (percent < 95){
			go(62, 17);
			printf("  ");
			go(50, 17);
			printf("+4 ��Ÿ�� ��");
			go(13, 5);
			printf("1,000��");
			go(13, 6);
			printf("800��");
			go(3, 7);
			printf("������: 95%%");
			enforce_easy += 1;
		}
		else{
			breaking += 1;
			y -= 500;
			sword_breaking();
		}
		y -= 500;
	}
	else if (enforce_easy == 4 && ((((t >= 1 || r >= 1) || e >= 1) || w >= 1) || q >= 1)){
		srand((unsigned int)clock(NULL));
		int percent = rand() % 100;
		if (percent < 95){
			go(50, 17);
			printf("+5 �ñ��� �ҵ�");
			go(13, 5);
			printf("1,500��");
			go(13, 6);
			printf("1,600��");
			go(3, 7);
			printf("������: 90%%");
			enforce_easy += 1;
		}
		else{
			breaking += 1;
			t -= 1;
			sword_breaking();
		}
		t -= 1;
	}
	else if (enforce_easy == 5 && ((((t >= 2 || (y >= 500 && t >= 1) || r >= 1) || e >= 1) || w >= 1) || q >= 1)){
		srand((unsigned int)clock(NULL));
		int percent = rand() % 100;
		if (percent < 90){
			go(60, 17);
			printf("    ");
			go(50, 17);
			printf("+6 �糯 ��");
			go(13, 5);
			printf("2,000��");
			go(13, 6);
			printf("3,500��");
			go(3, 7);
			printf("������: 90%%");
			enforce_easy += 1;
		}
		else{
			breaking += 1;
			y -= 500;
			t -= 1;
			sword_breaking();
		}
		t -= 1;
		y -= 500;
	}
	else if (enforce_easy == 6 && ((((t >= 2 || r >= 1) || e >= 1) || w >= 1) || q >= 1)){
		srand((unsigned int)clock(NULL));
		int percent = rand() % 100;
		if (percent < 90){
			go(50, 17);
			printf("+7 �������� ���");
			go(13, 5);
			printf("2,000��");
			go(13, 6);
			printf("6,100��");
			go(3, 7);
			printf("������: 90%%");
			enforce_easy += 1;
		}
		else{
			t -= 2;
			breaking += 1;
			sword_breaking();
		}
		t -= 2;
	}
	else if (enforce_easy == 7 && ((((t >= 2 || r >= 1) || e >= 1) || w >= 1) || q >= 1)){
		srand((unsigned int)clock(NULL));
		int percent = rand() % 100;
		if (percent < 90){
			go(62, 17);
			printf("    ");
			go(50, 17);
			printf("+8 ������ ��");
			go(13, 5);
			printf("3,000��");
			go(13, 6);
			printf("10,000��");
			go(3, 7);
			printf("������: 85%%");
			enforce_easy += 1;
		}
		else{
			t -= 2;
			breaking += 1;
			sword_breaking();
		}
		t -= 2;
	}
	else if (enforce_easy == 8 && ((((t >= 3 || r >= 1) || e >= 1) || w >= 1) || q >= 1)){
	srand((unsigned int)clock(NULL));
	int percent = rand() % 100;
	if (percent < 85){
		go(50, 17);
		printf("+9 Ÿ�� ������");
		go(13, 5);
		printf("5,000��");
		go(13, 6);
		printf("20,000��");
		go(3, 7);
		printf("������: 80%%");
		enforce_easy += 1;
	}
	else{
		t -= 3;
		breaking += 1;
		sword_breaking();
	}
	t -= 3;
	}
	else if (enforce_easy == 9 && ((((t >= 5 || r >= 1) || e >= 1) || w >= 1) || q >= 1)){
	srand((unsigned int)clock(NULL));
	int percent = rand() % 100;
	if (percent < 80){
		go(60, 17);
		printf("    ");
		go(50, 17);
		printf("+10 ������");
		go(13, 5);
		printf("10,900��");
		go(13, 6);
		printf("35,100��");
		go(3, 7);
		printf("������: 80%%");
		enforce_easy += 1;
	}
	else{
		t -= 5;
		breaking += 1;
		sword_breaking();
	}
	t -= 5;
	}
	else if (enforce_easy == 10 && ((((t >= 10 || (y >= 900 && t >= 10) || r >= 1) || e >= 1) || w >= 1) || q >= 1)){
	srand((unsigned int)clock(NULL));
	int percent = rand() % 100;
	if (percent < 80){
		go(50, 17);
		printf("+11 �ǹ��� ��");
		go(13, 5);
		printf("20,000��");
		go(13, 6);
		printf("160,000��");
		go(3, 7);
		printf("������: 75%%");
		enforce_easy += 1;
	}
	else{
		y -= 900;
		t -= 10;
		breaking += 1;
		sword_breaking();
	}
	y -= 900;
	t -= 10;
	}
	else if (enforce_easy == 11 && ((((t >= 20 || r >= 1) || e >= 1) || w >= 1) || q >= 1)){
	srand((unsigned int)clock(NULL));
	int percent = rand() % 100;
	if (percent < 75){
		go(50, 17);
		printf("+12 ȭ���� �ְ�");
		go(13, 5);
		printf("35,000��");
		go(13, 6);
		printf("350,000��");
		go(3, 7);
		printf("������: 70%%");
		enforce_easy += 1;
	}
	else{
		t -= 20;
		breaking += 1;
		sword_breaking();
	}
	t -= 20;
	}
	else if (enforce_easy == 12 && ((((t >= 35 || r >= 1) || e >= 1) || w >= 1) || q >= 1)){
	srand((unsigned int)clock(NULL));
	int percent = rand() % 100;
	if (percent < 70){
		go(63, 17);
		printf("    ");
		go(50, 17);
		printf("+13 �Ҳ� ����");
		go(13, 5);
		printf("55,000��");
		go(13, 6);
		printf("1,000,000��");
		go(3, 7);
		printf("������: 70%%");
		enforce_easy += 1;
	}
	else{
		t -= 35;
		breaking += 1;
		sword_breaking();
	}
	t -= 35;
	}
	else if (enforce_easy == 13 && ((((t >= 55 || r >= 1) || e >= 1) || w >= 1) || q >= 1)){
	srand((unsigned int)clock(NULL));
	int percent = rand() % 100;
	if (percent < 70){
		go(50, 17);
		printf("+14 ���� �����ǽ�");
		go(13, 5);
		printf("100,000��");
		go(13, 6);
		printf("3,000,000��");
		go(3, 7);
		printf("������: 65%%");
		enforce_easy += 1;
	}
	else{
		t -= 55;
		breaking += 1;
		sword_breaking();
	}
	t -= 55;
	}
	else if (enforce_easy == 14 && ((((t >= 100 || r >= 1) || e >= 1) || w >= 1) || q >= 1)){
	srand((unsigned int)clock(NULL));
	int percent = rand() % 100;
	if (percent < 65){
		go(50, 17);
		printf("+15 ���� ��Ʋ ����");
		go(13, 5);
		printf("180,000��");
		go(13, 6);
		printf("7,500,000��");
		go(3, 7);
		printf("������: 60%%");
		enforce_easy += 1;
	}
	else{
		t -= 100;
		breaking += 1;
		sword_breaking();
	}
	t -= 100;
	}
	else if (enforce_easy == 15 && ((((t >= 180 || r >= 1) || e >= 1) || w >= 1) || q >= 1)){
	srand((unsigned int)clock(NULL));
	int percent = rand() % 100;
	if (percent < 60){
		go(61, 17);
		printf("       ");
		go(50, 17);
		printf("+16 ���� ��");
		go(13, 5);
		printf("300,000��");
		go(13, 6);
		printf("14,200,000��");
		go(3, 7);
		printf("������: 60%%");
		enforce_easy += 1;
	}
	else{
		t -= 180;
		breaking += 1;
		sword_breaking();
	}
	t -= 180;
	}
	else if (enforce_easy == 16 && ((((t >= 300 || r >= 1) || e >= 1) || w >= 1) || q >= 1)){
	srand((unsigned int)clock(NULL));
	int percent = rand() % 100;
	if (percent < 60){
		go(50, 17);
		printf("+17 ������ ���");
		go(13, 5);
		printf("300,000��");
		go(13, 6);
		printf("20,000,000��");
		go(3, 7);
		printf("������: 55%%");
		enforce_easy += 1;
	}
	else{
		t -= 300;
		breaking += 1;
		sword_breaking();
	}
	t -= 300;
	}
	else if (enforce_easy == 17 && ((((t >= 300 || r >= 1) || e >= 1) || w >= 1) || q >= 1)){
	srand((unsigned int)clock(NULL));
	int percent = rand() % 100;
	if (percent < 55){
		go(50, 17);
		printf("+18 ���̴� �ҵ�");
		go(13, 5);
		printf("500,000��");
		go(13, 6);
		printf("30,000,000��");
		go(3, 7);
		printf("������: 50%%");
		enforce_easy += 1;
	}
	else{
		t -= 300;
		breaking += 1;
		sword_breaking();
	}
	t -= 300;
	}
	else if (enforce_easy == 18 && ((((t >= 500 || r >= 1) || e >= 1) || w >= 1) || q >= 1)){
	srand((unsigned int)clock(NULL));
	int percent = rand() % 100;
	if (percent < 50){
		go(62, 17);
		printf("   ");
		go(50, 17);
		printf("+19 ��Ǫ�ƻ�");
		go(13, 5);
		printf("800,000��");
		go(13, 6);
		printf("47,500,000��");
		go(3, 7);
		printf("������: 50%%");
		enforce_easy += 1;
	}
	else{
		t -= 500;
		breaking += 1;
		sword_breaking();
	}
	t -= 500;
	}
	else if (enforce_easy == 19 && ((((t >= 800 || r >= 1) || e >= 1) || w >= 1) || q >= 1)){
	srand((unsigned int)clock(NULL));
	int percent = rand() % 100;
	if (percent < 50){
		go(60, 17);
		printf("  ");
		go(50, 17);
		printf("+20 �ٻ���");
		go(13, 5);
		printf("1,500,000��");
		go(13, 6);
		printf("68,300,000��");
		go(3, 7);
		printf("������: 45%%");
		enforce_easy += 1;
	}
	else{
		t -= 800;
		breaking += 1;
		sword_breaking();
	}
	t -= 800;
	}
	else if (enforce_easy == 20 && (((r >= 2 || (t >= 500 && r >= 1) || e >= 1) || w >= 1) || q >= 1)){
	srand((unsigned int)clock(NULL));
	int percent = rand() % 100;
	if (percent < 45){
		go(50, 17);
		printf("+21 ���佺Ʈ ���");
		go(13, 5);
		printf("��Ǫ�ƻ� 1�ڷ�");
		go(13, 6);
		printf("101,000,000��");
		go(3, 7);
		printf("������: 40%%");
		enforce_easy += 1;
	}
	else{
		r -= 1;
		t -= 500;
		breaking += 1;
		sword_breaking();
	}
	r -= 1;
	t -= 500;
	}
	else if (enforce_easy == 21 && Wang_Puasha >= 1){
	srand((unsigned int)clock(NULL));
	int percent = rand() % 100;
	if (percent < 40){
		go(63, 17);
		printf("    ");
		go(50, 17);
		printf("+22 ���� ��Ŀ");
		go(13, 5);
		printf("���佺Ʈ ��� 2�ڷ�");
		go(13, 6);
		printf("160,000,000��");
		go(3, 7);
		printf("������: 40%%");
		enforce_easy += 1;
	}
	else{
		Wang_Puasha -= 1;
		breaking += 1;
		sword_breaking();
	}
	Wang_Puasha -= 1;
	}
	else if (enforce_easy == 22 && tempest_gold >= 2){
	srand((unsigned int)clock(NULL));
	int percent = rand() % 100;
	if (percent < 40){
		go(50, 17);
		printf("+23 �ǿ����� �ְ�");
		go(28, 5);
		printf("    ");
		go(13, 5);
		printf("����� ��ȥ 8��");
		go(13, 6);
		printf("230,000,000��");
		go(3, 7);
		printf("������: 40%%");
		enforce_easy += 1;
	}
	else{
		tempest_gold -= 2;
		breaking += 1;
		sword_breaking();
	}
	tempest_gold -= 2;
	}
	else if (enforce_easy == 23 && evil_spirit_add >= 8){
	srand((unsigned int)clock(NULL));
	int percent = rand() % 100;
	if (percent < 40){
		go(60, 17);
		printf("       ");
		go(50, 17);
		printf("+24 ���浵");
		go(13, 5);
		printf("���� ��Ŀ 1�ڷ�");
		go(13, 6);
		printf("300,000,000��");
		go(3, 7);
		printf("������: 40%%");
		enforce_easy += 1;
	}
	else{
		evil_spirit_add -= 8;
		breaking += 1;
		sword_breaking();
	}
	evil_spirit_add -= 8;
	}
	else if (enforce_easy == 24 && sharp_walker >= 1){
	srand((unsigned int)clock(NULL));
	int percent = rand() % 100;
	if (percent < 40){
		go(50, 17);
		printf("+25 �� ���غ��̴� ��");
		go(27, 5);
		printf("  ");
		go(13, 5);
		printf("���� ���� 15��");
		go(13, 6);
		printf("400,000,000��");
		go(3, 7);
		printf("������: 35%%");
		enforce_easy += 1;
	}
	else{
		sharp_walker -= 1;
		breaking += 1;
		sword_breaking();
	}
	sharp_walker -= 1;
	}
	else if (enforce_easy == 25 && ax_powder_add >= 15){
	srand((unsigned int)clock(NULL));
	int percent = rand() % 100;
	if (percent < 35){
		go(60, 17);
		printf("          ");
		go(50, 17);
		printf("+26 �޵λ�");
		go(24, 5);
		printf("      ");
		go(13, 5);
		printf("5,000,000��");
		go(13, 6);
		printf("1,800,000,000��");
		go(3, 7);
		printf("������: 50%%");
		enforce_easy += 1;
	}
	else{
		ax_powder_add -= 15;
		breaking += 1;
		sword_breaking();
	}
	ax_powder_add -= 15;
	}
	else if (enforce_easy == 26 && (((r >= 5 || e >= 1) || w >= 1) || q >= 1)){
		srand((unsigned int)clock(NULL));
		int percent = rand() % 100;
		if (percent < 50){
			go(50, 17);
			printf("+27 �������� �ҵ�");
			go(13, 5);
			printf("���� ���� 2��");
			go(13, 6);
			printf("2,500,000,000��");
			go(3, 7);
			printf("������: 40%%");
			enforce_easy += 1;
		}
		else{
			r -= 5;
			breaking += 1;
			sword_breaking();
		}
		r -= 5;
	}
	else if (enforce_easy == 27 && transparent_material_add >= 2){
	srand((unsigned int)clock(NULL));
	int percent = rand() % 100;
	if (percent < 40){
		go(62, 17);
		printf("     ");
		go(50, 17);
		printf("+28 ������Į");
		go(17, 5);
		printf("         ");
		go(13, 5);
		printf("����");
		go(23, 5);
		printf("     ");
		go(13, 6);
		printf("�� �� ����");
		go(3, 7);
		printf("������: 15%%");
		enforce_easy += 1;
	}
	else{
		transparent_material_add -= 2;
		breaking += 1;
		sword_breaking();
	}
	transparent_material_add -= 2;
	}
	else if (enforce_easy == 28){
	srand((unsigned int)clock(NULL));
	int percent = rand() % 100;
	if (percent < 15){
		go(50, 17);
		printf("+29 ȭ���� �ޱ� ��");
		go(13, 5);
		printf("Unknown");
		go(20, 5);
		printf("    ");
		go(13, 6);
		printf("Unknown");
		go(3, 7);
		printf("������: Unknown%%");
		enforce_easy += 1;
	}
	else{
		breaking += 1;
		sword_breaking();
	}
	}
}
int union_(){
	system("cls");
	while (1){
		game_money_easy();
		go(3, 1);
		printf("����â����");
		go(15, 3);
		printf("�����Һи� ö���� 5�� -> ���� ������ 1��");
		go(15, 7);
		printf("Ÿ���� �� �ν����� 3�� -> ���� ������ 1��");
		go(15, 11);
		printf("�� �ٷ� �������� 2�� -> �Ҳ� ���� 1��");
		go(15, 15);
		printf("�������� ö���� 3�� -> ���� ������ 2��");
		go(15, 19);
		printf("�Ҳɸ��� ������ 2�� -> ���� �� 1��");
		go(68, 3);
		printf("����� ��ȥ 4�� -> ���� ������ 4��");
		go(68, 7);
		printf("����� ��ȥ 6�� -> ��Ǫ�ƻ� 1��");
		go(68, 11);
		printf("���� ���� 6�� -> ���� ������ 10��");
		go(68, 15);
		printf("���� ���� 3�� -> ���� ������ 9��");
		go(3, 22);
		printf("������: ");
		go(3, 23);
		printf("��: ");
		go(107, 23);
		printf("������");
		go(1, 1);
		printf(">");
		int menuCode2 = union_menu();
		switch (menuCode2){
		case 4:
			japtem();
		case 18:{
			if (Iron_sculpture_of_unknown_nationality_add >= 5){
				Iron_sculpture_of_unknown_nationality_add -= 5;
				right_to_prevent += 1;
			}
			return union_();
		}
		case 22:{
			if (tau_Bone_Crumb_add >= 3){
				tau_Bone_Crumb_add -= 3;
				right_to_prevent += 1;
			}
			return union_();
		}
		case 26:{
			if (faded_fluorescent_material_add >= 2){
				faded_fluorescent_material_add -= 3;
				warp = 1;
				enforce_easy = 13;
				sword_easy();
			}
		}
		case 30:{
			if (swiss_iron_add >= 3){
				swiss_iron_add -= 3;
				right_to_prevent += 2;
			}
			return union_();
		}
		case 34:{
			if (flame_sword_handle_add >= 2){
				flame_sword_handle_add -= 2;
				warp = 1;
				enforce_easy = 16;
				sword_easy();
			}
		}
		case 71:{
			if (evil_spirit_add >= 4){
				evil_spirit_add -= 4;
				right_to_prevent += 4;
			}
			return union_();
		}
		case 75:{
			if (evil_spirit_add >= 6){
				evil_spirit_add -= 6;
				warp = 1;
				enforce_easy = 19;
				sword_easy();
			}
		}
		case 79:{
			if (ax_powder_add >= 6){
				ax_powder_add -= 6;
				right_to_prevent += 10;
			}
			return union_();
		}
		case 83:{
			if (transparent_material_add >= 3){
				transparent_material_add -= 3;
				right_to_prevent += 9;
			}
			return union_();
		}
		case 130:{
			sword_easy();
		}
		}
	}
}
int japtem(){
	system("cls");
	while (1){
		game_money_easy();
		go(27, 4);
		printf("�����Һи� ö����: %d��", Iron_sculpture_of_unknown_nationality_add);
		go(27, 8);
		printf("Ÿ���� �� �ν�����: %d��", tau_Bone_Crumb_add);
		go(27, 12);
		printf("�� �ٷ� ��������: %d��", faded_fluorescent_material_add);
		go(27, 16);
		printf("�������� ö����: %d��", swiss_iron_add);
		go(68, 4);
		printf("�Ҳɸ��� ������: %d��", flame_sword_handle_add);
		go(68, 8);
		printf("����� ��ȥ: %d��", evil_spirit_add);
		go(68, 12);
		printf("���� ����: %d��", ax_powder_add);
		go(68, 16);
		printf("������: %d��", transparent_material_add);
		go(3, 22);
		printf("������: ");
		go(3, 23);
		printf("��: ");
		go(107, 23);
		printf("������");
		go(105, 23);
		printf(">");
		int a = keyControl();
		if (a == 5)
			union_();
	}
}
int union_menu(){
	int x = 3, y = 1;
	while (1){
		int a = keyControl();
		switch (a){
		case up:{
			if (y > 3 && x < 69){
				go(x - 2, y);
				printf(" ");
				go(x - 2, y - 4);
				printf(">");
				y -= 4;
			}
			else if (y == 3 && x == 15){
				go(x - 2, y);
				printf(" ");
				go(x - 14, y - 2);
				printf(">");
				x -= 12;
				y -= 2;
			}
			else if (y == 23 && x == 107){
				go(x - 2, y);
				printf(" ");
				go(x - 41, y - 8);
				printf(">");
				x -= 39;
				y -= 8;
			}
			break;
		}
		case down:{
			if (y < 19 && x == 15){
				go(x - 2, y);
				printf(" ");
				go(x - 2, y + 4);
				printf(">");
				y += 4;
			}
			else if (y < 15 && x == 68){
				go(x - 2, y);
				printf(" ");
				go(x - 2, y + 4);
				printf(">");
				y += 4;
			}
			else if (y == 1 && x == 3){
				go(x - 2, y);
				printf(" ");
				go(x + 10, y + 2);
				printf(">");
				x += 12;
				y += 2;
			}
			else if (y == 15 && x == 68){
				go(x - 2, y);
				printf(" ");
				go(x + 37, y + 8);
				printf(">");
				x += 39;
				y += 8;
			}
			break;
		}
		case left:{
			if (x == 68){
				go(x - 2, y);
				printf(" ");
				go(x - 55, y);
				printf(">");
				x -= 53;
			}
			break;
		}
		case right:{
			if (x == 15 && y < 16){
				go(x - 2, y);
				printf(" ");
				go(x + 51, y);
				printf(">");
				x += 53;
			}
			break;
		}
		case submit:
			return x + y;
		}
	}
}
int game_easy(){
	system("cls");
	while (1){
		game_money_easy();
		title_easy();
		int menuCode1 = easy();
		if (menuCode1 == 4)
			item_easy();
		else if (menuCode1 == 106)
			shop_easy_menu();
		else if (menuCode1 == 110){
			y -= 300;
			enforce_easy += 1;
			sword_easy();
		}
		else if (menuCode1 == 130)
			main();
		system("cls");
	}
}
int hard()
{
	int x = 3, y = 1;
	while (1)
	{
		int a = keyControl();
		switch (a)
		{
		case up:
		{
			if (y > 1)
			{
				if (y == 23)
				{
					go(105, 23);
					printf(" ");
					go(103, 5);
					printf(">");
					x = 105, y = 5;
				}
				else if (y == 5)
				{
					go(103, 5);
					printf(" ");
					go(103, 1);
					printf(">");
					x = 105, y = 1;
				}
			}
			break;
		}

		case down:
		{
			if (y < 23)
			{
				if (y == 1 && x == 105)
				{
					go(103, 1);
					printf(" ");
					go(103, 5);
					printf(">");
					x = 105, y = 5;
				}
				else if (y == 5)
				{
					go(103, 5);
					printf(" ");
					go(105, 23);
					printf(">");
					x = 107, y = 23;
				}
			}
			break;
		}

		case left:
		{
			if (x != 3)
			{
				if (y == 1)
				{
					go(103, 1);
					printf(" ");
					go(1, 1);
					printf(">");
					x = 3, y = 1;
				}
				else if (y == 5)
				{
					go(103, 5);
					printf(" ");
					go(1, 1);
					printf(">");
					x = 3, y = 1;
				}
				else if (y == 23)
				{
					go(105, 23);
					printf(" ");
					go(1, 1);
					printf(">");
					x = 3, y = 1;
				}
			}
			break;
		}

		case right:
		{
			if (x != 105 && x != 107)
			{
				go(1, 1);
				printf(" ");
				go(103, 1);
				printf(">");
				x = 105, y = 1;
			}
			break;
		}

		case submit:
		{
			return y + x;
		}
		}
	}
}

void title_hard()
{
	go(3, 1);
	printf("������â����");
	go(3, 5);
	printf("��ȭ���: ");
	go(3, 6);
	printf("�ǸŰ���: ");
	go(105, 5);
	printf("��ȭ�ϱ�");
	go(107, 23);
	printf("������");
	go(105, 1);
	printf("��������");
	go(3, 22);
	printf("������: ");
	go(3, 23);
	printf("��: ");
	go(1, 1);
	printf(">");
}

int game_hard()
{
	system("cls");

	while (1)
	{
		title_hard();
		int menuCode1 = hard();
		if (menuCode1 == 4)//������â����
		{
			main();
		}
		else if (menuCode1 == 106)//��������
		{
			main();
		}
		else if (menuCode1 == 110)//�� ��ȭ�ϱ�
		{
			main();
		}
		else if (menuCode1 == 130)//������
		{
			main();
		}
		system("cls");
	}
}