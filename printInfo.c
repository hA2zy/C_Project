#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <time.h>

int m_card[10] = {32, 20, 15}; // ���� ��
int m_idx = 3; // ���� �� �� ��
int e_card[10] = { 11, 12 ,13 }; // ���� ��
int e_idx = 3; // ���� �� �� ��
int deck[52]; //ī�� ���� 1�� �� ����
int eScor;
int mScor;

void printInfo() {
	eScor = 0;
	mScor = 0;
	int press = 0;

	//my deck

	for (int i = 0; i < m_idx; i++) {
		if (mScor < 22) {
			if (m_card[i] % 13 == 0) {
				printf("\t\t\t\tA�� ���Խ��ϴ�. 1Ȥ�� 11�� ������ ���ϼ��� : ");
				mAce:
				scanf("%d", &press);
				if (press == 1) {
					mScor += 1;
				}
				else if (press == 11) {
					mScor += 11;
				}
				else {
					printf("\t\t\t\t�߸� �Է��� �Ǿ����ϴ�.\n �ٽ� �Է��� ���ּ��� : ");
					goto mAce;
				}
			}
			else if (m_card[i] % 13 == 10 || m_card[i] % 13 == 11 || m_card[i] % 13 == 12) {
				mScor += 10;
			}
			else {
				mScor += m_card[i] % 13 + 1;
			}
		}
		else if (mScor >= 22) {
			if (m_card[i] % 13 == 0) {
				printf("\t\t\t\t����� 21�� �Ѿ Ace�� ���� 1���մϴ�.\n");
				mScor += 1;
			}
			else if (m_card[i] % 13 == 10 || m_card[i] % 13 == 11 || m_card[i] % 13 == 12) {
				mScor += 10;
			}
			else {
				mScor += m_card[i];
			}
		}
	}
	printf("\t\t\t\t�ڽ��� �п� �հ� : ");
	for (int i = 0; i < m_idx; i++) {
		int type = m_card[i] / 13;
		if (!type) {
			printf("�� "); // Spacd
		}
		else if (type == 1) {
			printf("�� "); // Diamond
		}
		else if (type == 2) {
			printf("�� "); // Heart
		}
		else if (type == 3) {
			printf("�� "); // Clover
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
			printf("%d", (m_card[i] % 13 + 1)); // �ε����� �ƴ϶� ī�� ���ڴϱ� +1
		}
		printf(" // ");
	}
	printf("%d\n", mScor);

	// enemy deck
	int eCnt = 0;

	for (int i = 1; i < e_idx; i++) {
		if (e_card[i] % 13 == 0) {
			eCnt = 1;
			eScor += 1;
		}
		else if (e_card[i] % 13 == 10 || e_card[i] % 13 == 11 || e_card[i] % 13 == 12) {
			eScor += 10;
		}
		else {
			eScor += e_card[i] % 13 + 1;
		}
	}
	printf("\t\t\t\t���� �п� �հ� : ");
	for (int i = 1; i < e_idx; i++) {
		int type = e_card[i] / 13;
		if (!type) {
			printf("�� "); // Spacd
		}
		else if (type == 1) {
			printf("�� "); // Diamond
		}
		else if (type == 2) {
			printf("�� "); // Heart
		}
		else if (type == 3) {
			printf("�� "); // Clover
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
			printf("%d", (e_card[i] % 13 + 1)); // �ε����� �ƴ϶� ī�� ���ڴϱ� +1
		}
		printf(" // ");
	}

	printf("%d", eScor);
	if (eCnt) printf("�� %d", eScor + 10);
}

void main() {
	printInfo();
	
}