#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#pragma warning(disable : 4996)

int point = 24; // �� ó�� 0�� ��ġ

void printScreen() {
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 1, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 2);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 5, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 5);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 5, 'P', 'u', 'z', 'z', 'l', 'e', ' ', 'G', 'a', 'm', 'e', 5);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 5, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 5);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 3, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 4);
	printf("1. ���� ���� \n");
	printf("0. ���� ���� \n");
}

int printPuzzle(int* puzzle) {
	system("cls");
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 1, 6, 6, 22, 6, 6, 22, 6, 6, 22, 6, 6, 22, 6, 6, 2);
	for (int i = 0; i < 5; i++) printf("%c%2d%c%2d%c%2d%c%2d%c%2d%c\n", 5, puzzle[i * 5 + 0], 5, puzzle[i * 5 + 1], 5, puzzle[i * 5 + 2], 5, puzzle[i * 5 + 3], 5, puzzle[i * 5 + 4], 5);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 3, 6, 6, 21, 6, 6, 21, 6, 6, 21, 6, 6, 21, 6, 6, 4);
}

int checkPuzzle(int* puzzle) {
	for (int i = 0; i < 24; i++) {
		if (puzzle[i] != i) return 0;
	}
	return 1;
}

int inputKey(int* puzzle) {
	char key;
	int temp;

	while (1) {
		printf("�Է� (0) ���� :");
		key = _getch();
		switch (key) {
		case 72:
			if (point > 4) {
				temp = puzzle[point];
				puzzle[point] = puzzle[point - 5];
				puzzle[point - 5] = temp;
				point -= 5;
			}
			return 0;
		case 75:
			if (point % 5 != 0) {
				temp = puzzle[point];
				puzzle[point] = puzzle[point - 1];
				puzzle[point - 1] = temp;
				point -= 1;
			}
			return 0;
		case 77:
			if (point % 5 != 4) {
				temp = puzzle[point];
				puzzle[point] = puzzle[point + 1];
				puzzle[point + 1] = temp;
				point += 1;
			}
			return 0;
		case 80:
			if (point < 20) {
				temp = puzzle[point];
				puzzle[point] = puzzle[point + 5];
				puzzle[point + 5] = temp;
				point += 5;
			}
			return 0;
		case '0':
			return 1;
		default:
			printf("����Ű�� ���� �ּ��� ! (���� : 0)\n");
		}
	}
}

int init(int* puzzle) {
	srand((unsigned int)time(NULL)); // �Ź� ���ึ�� �ٸ� ������ ����
	int sour, dest; //���� ������ ���� ���� 
	int temp; // puzzle[sour] �� puzzle[dest]�� ��ġ�� �ٲٱ� ���� �ӽ� ����

	for (int i = 0; i < 25; i++) puzzle[i] = i;
	for (int i = 0; i < 100; i++) {
		sour = rand() % 25;
		dest = rand() % 25;

		if (puzzle[sour] != 0 && puzzle[dest] != 0) {
			temp = puzzle[sour];
			puzzle[sour] = puzzle[dest];
			puzzle[dest] = temp;
		}
	}
	puzzle[0] = puzzle[24]; // 0�� ��ġ �ʱ�ȭ
	puzzle[24] = 0; // ������ ��ġ 0 ����
}

int main() {
	int puzzle[25];
	char input;

	printScreen();
	init(puzzle);

	while (1) {
		input = _getch();
		switch (input) {
		case '1':
			while (1) {
				printPuzzle(puzzle);
				if (checkPuzzle(puzzle)) {
					system("cls");
					printf("���� !\n");
					break;
				}
				if (inputKey(puzzle)) break;
			}
		case '0':
			printf("������ �����մϴ�. \n");
			return 0;
		}
	}

}