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
	eScor = 0;
	int Acnt = 0;
	mScor = 0;
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
			else if (mScor >= 22) {
				mScor += 1;
			}
			else if (m_card[i] == 'J' || m_card[i] == 'j') {
				mScor += 10;
			}
			else if (m_card[i] == 'Q' || m_card[i] == 'q') {
				mScor += 10;
			}
			else if (m_card[i] == 'K' || m_card[i] == 'k') {
				mScor += 10;
			}
			else {
				mScor += m_card[i];
			}
		}
		printf("나의 패와 합계 : ");
		for (int i = 0; i < m_idx; i++) {
			int type = m_card[i] / 13;
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

			if (m_card[i] % 13 == 0) {
				printf("A "); // Ace
			}
			else if (m_card[i] % 13 == 10) {
				printf("J "); // Jack
			}
			else if (m_card[i] % 13 == 11) {
				printf("Q "); // Queen
			}
			else if (m_card[i] % 13 == 12) {
				printf("K "); // King
			}
			else {
				printf("%d", (m_card[i] % 13 + 1)); // 인덱스가 아니라 카드 숫자니까 +1
			}

			printf(" // ");
		}
		printf("합계 : %d\n", mScor);

		for (int i = 1; i < e_idx; i++) {
			if (!(e_card[i] % 13)) {
				eScor += 1;
				Acnt++;
			}
			else if (m_card[i] == 'J' || m_card[i] == 'j') {
				eScor += 10;
			}
			else if (m_card[i] == 'Q' || m_card[i] == 'q') {
				eScor += 10;
			}
			else if (m_card[i] == 'K' || m_card[i] == 'k') {
				eScor += 10;
			}
			else {
				eScor += e_card[i];
			}
			printf("적의 패와 합계 : ");
			for (int i = 1; i < e_idx; i++) {
				int type = e_card[i] / 13;
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

				if (e_card[i] % 13 == 0) {
					printf("A "); // Ace
				}
				else if (e_card[i] % 13 == 10) {
					printf("J "); // Jack
				}
				else if (e_card[i] % 13 == 11) {
					printf("Q "); // Queen
				}
				else if (e_card[i] % 13 == 12) {
					printf("K "); // King
				}
				else {
					printf("%d", (e_card[i] % 13 + 1)); // 인덱스가 아니라 카드 숫자니까 +1
				}

				printf(" // ");
			}
			printf("합계 : %d", eScor);
			if (Acnt == 1) printf("와 %d", eScor + 10);
			printf("\n");

		}
	}
}