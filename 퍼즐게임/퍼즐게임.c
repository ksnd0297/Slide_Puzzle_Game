#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#pragma warning(disable : 4996)

void printScreen();
int printPuzzle(int*);
int checkPuzzle(int*);
int inputKey(int*);
int init(int*);

int main() {
	int puzzle[25];
	char input;

	printScreen();
	init(puzzle);

	while (1) {
		scanf("%c", &input);
		switch (input) {
		case '1':
			while (1) {
				printPuzzle(puzzle);
				if (checkPuzzle(puzzle)) {
					printf("성공 !\n");
					break;
				}
				if (inputKey(puzzle)) break;
			}
		case '0':
			printf("게임을 종료합니다. \n");
			return 0;
		}
	}

}

void printScreen() {
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 1, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 2);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 5, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 5);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 5, 'P', 'u', 'z', 'z', 'l', 'e', ' ', 'G', 'a', 'm', 'e', 5);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 5, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 5);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 3, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 4);
	printf("1. 게임 시작 \n");
	printf("0. 게임 종료 \n");
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

int inputKey(int puzzle) {

}

int init(int* puzzle) {
	srand((unsigned int)time(NULL)); // 매번 실행마다 다른 랜덤값 생성
	int sour, dest; //랜덤 생성을 위한 숫자 
	int temp; // puzzle[sour] 과 puzzle[dest]의 위치를 바꾸기 위한 임시 공간

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
	puzzle[0] = puzzle[24]; // 0의 위치 초기화
	puzzle[24] = 0;

}