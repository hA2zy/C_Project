#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <time.h>

int m_card[10]; // 나의 패
int m_idx; // 나의 패 장 수
int e_card[10]; // 적의 패
int e_idx; // 적의 패 장 수
int deck[52] = { 0 }; //카드 사용시 1로 값 변경
int eScor;
int mScor;

void pritInfo() {
	int pre = 0; // Ace의 점수를 정할 수 있게 해주는 변수
	for (int i = 0; i < m_idx; i++) {
		if (!(m_card[i] % 13)) {
			if (mScor < 22) {
				printf("A가 나왔습니다. 1혹은 11을 더할지 정하세요 : ");
				scanf("%d", &pre);
				if (pre == 1) {
					mScor += 1;
				}
				else if (pre == 11) {
					mScor += 11;
				}
				else {
					printf("잘못된 '값' 입니다!!!");
				}
			}
			else {
				mScor += 1;
			}
		}
		else {
			mScor += m_card[i];
		}
	}
	for (int i = 0; i < m_idx; i++) {
		int card = 0;
		int type = card / 13;
		if (!type) {
			printf("♠ "); // Spacd
		}
		else if (type == 1) {
			printf("◆ "); // Diamond
		}
		else if (type == 2) {
			printf("♥ "); // Heart
		}
		else if (type == 3) {
			printf("♣ "); // Clover
		}

		if (card % 13 == 0) {
			printf("A "); // Ace
		}
		else if (card % 13 == 10) {
			printf("J "); // Jack
		}
		else if (card % 13 == 11) {
			printf("Q "); // Queen
		}
		else if (card % 13 == 12) {
			printf("K "); // King
		}
		else {
			printf("%d", (card % 13 + 1)); // 인덱스가 아니라 카드 숫자니까 +1
		}

		printf(" // ");
	}
	printf("합계 : %d", mScor);

	for (int i = 1; i < e_idx; i++) {
		if (!(e_card[i] % 13)) {
			if (eScor < 22) {
				eScor += 11;
			}
			else {
				eScor += 1;
			}
		}
		else {
			eScor += e_card[i];
		}
	}
	for (int i = 1; i < e_idx; i++) {
		int card = 0;
		int type = card / 13;
		if (!type) {
			printf("♠ "); // Spacd
		}
		else if (type == 1) {
			printf("◆ "); // Diamond
		}
		else if (type == 2) {
			printf("♥ "); // Heart
		}
		else if (type == 3) {
			printf("♣ "); // Clover
		}

		if (card % 13 == 0) {
			printf("A "); // Ace
		}
		else if (card % 13 == 10) {
			printf("J "); // Jack
		}
		else if (card % 13 == 11) {
			printf("Q "); // Queen
		}
		else if (card % 13 == 12) {
			printf("K "); // King
		}
		else {
			printf("%d", (card % 13 + 1)); // 인덱스가 아니라 카드 숫자니까 +1
		}

		printf(" // ");
	}
	printf("합계 : %d", eScor);
}