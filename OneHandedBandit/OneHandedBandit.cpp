#include <stdio.h>
#include <random>

int main()
{
	int bet; // ставка
	int first, second, third;
	char choice;

	printf("Rules:\n777 - x3\n3 same - x2\n2 same - x1\n7 - x1\n2x7 - x2\nnothing - lose :(\n\nYour bet: ");
	scanf_s("%d", &bet);

	if (bet <= 0) {
		printf("We are in the serious place ^_^");
		return 0;
	}

	while (true) {
		first = (rand() % (9 - 1 + 1) + 1); // Да, странно. Всё для понимания формулы)
		second = (rand() % (9 - 1 + 1) + 1); // И опять
		third = (rand() % (9 - 1 + 1) + 1); // И снова

		printf("_|%d - %d - %d|_\n", first, second, third);

		if (first == 7 && second == 7 && third == 7) { // 777
			bet *= 3;
			printf("bet x3. Current bet: %d\n", bet);
		}
		else if ((first == second) && (second == third)) { // 3 одинаковые
			bet *= 2;
			printf("bet x2. Current bet: %d\n", bet);
		}
		else if ((first == 7 && second == 7) || (first == 7 && third == 7) || (second == 7 && third == 7)) { // 2 семерки
			bet *= 2;
			printf("bet x2. Current bet: %d\n", bet);
		}
		else if ((first == second) || (first == third) || (second == third)) { // 2 одинаковые
			printf("bet x1. Current bet: %d\n", bet);
		}
		else if (first == 7 || second == 7 || third == 7) { // 1 семерка
			printf("bet x1. Current bet: %d\n", bet);
		}
		else {
			printf("Lose :(\nTry again? (y/n)\n");  // Проигрыш
			getchar();
			choice = 'r';
			scanf_s("%c", &choice); // Ещё раз? (при проигрыше)
			if (choice != 'y') {
				printf("Dont be sad. See u next time\n"); 
				return 0;
			}
			getchar();
			printf("New bet: "); // новая ставка
			scanf_s("%d", &bet); 
			continue;
		}
		getchar();
		choice = 'r';
		printf("Continue? (y/n)\n"); // Продолжить? (после каждого хода)
		scanf_s("%c", &choice);
		if (choice == 'n') {
			printf("Your win: %d\nThx for playing!\n", bet);
			return 0;
		}

	}
}