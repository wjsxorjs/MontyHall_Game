#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

#define _CRT_SECURE_NO_WARNINGS


int main(){
	int sel, prz, non, cng, end;
	float total, prized=0.0, ratio=0.0;
	int lose = 0;
	int now = 0;
	while (1){
		srand(time(NULL));
		printf("Hello!\nThis Program is simple version of calculating ratio of Monty Hall Problem.\nDoes it really have high chance to win if we change our decision?\n");
		printf("How many time do you want to run this program?\n");
		scanf_s("%f",&total);
		getchar();
		while (1){
			prz = ((rand() % 3) + 1);
			while (1){
				sel = ((rand() % 3) + 1);
				if (sel < 1 || sel > 3){ printf("We only have 3 door, you know...\n"); }
				else break;
			}

			if (prz != sel){
				non = (6 - sel - prz);
			}
			else if (prz == sel){
				int random = rand() % 2;
				if (sel == 1){ if (random == 0){ non = 2; } else if (random == 1){ non = 3; } }
				else if (sel == 2){ if (random == 0){ non = 1; } else if (random == 1){ non = 3; } }
				else if (sel == 3){ if (random == 0){ non = 1; } else if (random == 1){ non = 2; } }
			}
			while (1){
				cng = 1;
				if (cng < 1 || cng > 2){ printf("Please, choose in the options\n"); }
				else break;
			}
			if (cng == 1){ sel = 6 - non - sel; }
			if (sel == prz){ prized = prized + 1.0; now++; }
			else if (sel != prz) { now++; lose++; }
			if (now == total){
				ratio = prized / total * 100;
				printf("Prized: %f\nLose: %d\n",prized,lose);
				printf("The ratio is %.3f percentage\n", ratio);
				printf("Do you want to leave?\n1)Y 2)N\n");
				while (1){
					scanf_s("%d", &end);
					if (end < 1 || end > 2){ printf("Please, choose in the options\n"); }
					else break;
				}
				if (end == 1){ printf("Good bye!\n"); break; }
				printf("How many time do you want to run this program?\n");
				scanf_s("%f", &total);
				getchar();
				now = 0;
				prized = 0;
				lose = 0;
			}
		}
		break;
	}

	return 0;
}