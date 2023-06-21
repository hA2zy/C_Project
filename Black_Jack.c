#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <time.h>

char cmd[99];

int eScor;
int mScor;

int m_card[10]; // ���� ��
int m_idx; // ���� �� �� ��
int e_card[10]; // ���� ��
int e_idx; // ���� �� �� ��

int deck[52] = { 0 };

void drow(/*���翵�� ���� �Լ�*/int pla /*�÷��̾� : 1, ��� : 0*/, int hide /*��밡 �̾��� �� ������ �Ⱥ���*/) {
	int card = 0;
	do {
		srand(time(0)); // ����ȭ
		card = (rand() * 454 % 520) / 10; // ī�� ���� 0 ~ 52 ���� �̱�
	} while (deck[card]); // deck[card] �� 1 �϶�, ���� �� ����
	int type = card / 13;
	deck[card] = 1; // deck[card] �� ����
	if (!hide) {
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
			printf("%d", (card % 13 + 1)); // �ε����� �ƴ϶� ī�� ���ڴϱ� +1
		}
		printf(" ");
	}
	else {
		printf("? ? ");
	}

	if (pla) {
		m_card[m_idx] = card; // ���� ���� ���� deck[card] �߰�
		m_idx++; // ���� ���� �ε����� �Ѿ
	}
	else {
		e_card[e_idx] = card; // ����� ���� ���� deck[card] �߰�
		e_idx++; // ��� ���� �ε����� �Ѿ
	}
	return;
}// �翵���� ���� ��ο�

void reTry(/*���������� ���� �Լ�*/) {
	for (int i = 0; i < 10; i++) {
		m_card[i] = 0;
		e_card[i] = 0;
	}
	for (int j = 0; j < 52; j++) {
		deck[j] = 0;
	}
	m_idx = 0;
	mScor = 0;
	e_idx = 0;
	eScor = 0;
} // ��� ������ �ʱ�ȭ

int result(/*���翵�̰� ���� �Լ�*/) {
	mScor = 0;
	eScor = 0;
	int mCnt = 0, eCnt = 0;
	for (int i = 0; i < m_idx; i++) {
		if (m_card[i] % 13 == 0) {
			mCnt = 1;
			mScor += 1;
		}
		else if (m_card[i] % 13 == 10 || m_card[i] % 13 == 11 || m_card[i] % 13 == 12) {
			mScor += 10;
		}
		else {
			mScor += m_card[i] % 13 + 1;
		}
	}

	for (int i = 0; i < e_idx; i++) {
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
	if (mScor + 10 <= 21 && mCnt) mScor += 10;
	if (eScor + 10 <= 21 && eCnt) eScor += 10;

	int mDist = 21 - mScor;
	int eDist = 21 - eScor;
	if (mDist == eDist) { // �Ÿ��� ���� ���
		return 2;
	}
	else if (mDist >= 0 && eDist >= 0) { // �Ѵ� 21 �� �� ���
		if (mDist < eDist) return 1;// ���� �� ����� ���
		else return 0; // ��밡 �� ����� ���
	}
	else { // �� �� �ϳ��� ���� ��� (�� �� ���� ��쵵 ����ؾߵ�)
		if (mDist < 0 && eDist < 0) {// �� �� ���� ��� (���� ���� ������ ���� ���ǽ��� �ݷ� ���Ÿ� ������)
			if (mDist > eDist) return 1;// ���� �� ����� ���
			else return 0; // ��밡 �� ����� ���
		}
		else { // �� �� �ϳ��� ���� ���
			if (mDist < 0) return 0;// ���� ������ ���� ���
			else return 1; // ��밡 ������ ���� ���
		}
	}
}

void prtInfo(/*���������� ���� �Լ�*/) {
	int press = 0;
	mScor = 0;
	eScor = 0;

	//my deck

	int mCnt = 0;
	for (int i = 0; i < m_idx; i++) {
		if (m_card[i] % 13 == 0) {
			mCnt++;
			mScor += 1;
		}
		else if (m_card[i] % 13 == 10 || m_card[i] % 13 == 11 || m_card[i] % 13 == 12) {
			mScor += 10;
		}
		else {
			mScor += m_card[i] % 13 + 1;
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
	printf("%d", mScor);
	if (mCnt) printf("or %d", mScor + 10);

	// enemy deck
	int eCnt = 0;

	for (int i = 0; i < e_idx; i++) {
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
	printf("\n\t\t\t\t���� �п� �հ� : ");
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

	printf("%d + x ", eScor);
	if (eCnt) printf("or %d + x", eScor + 10);
}

int main(/*�������� ���� �Լ�*/) {
	printf("\t\t\t\t\tRoading...");
start:
	for (int i = 0; i < 30; i++) {
		printf("\n");
		Sleep(18);
	}

	printf("\n\n\n\t\t\t\t\t\t��!����!��\n"); // �⺻ ȭ�� ���
	printf("\t\t\t\t\tPlease type \"start\" or \"exit\"\n\t\t\t\t\tand if you want some help, type \"help\"!");
turn:
	printf("\n\t\t\t\t:  ");
	scanf("%s", &cmd);
	int hard = 0;

	if (!strcmp(cmd, "help")) {
		printf("\t\t\t\t����� ������ ��� �����ϴ�!\n\t\t\t\t��ɾ�� help, drow, see, end�� ������\n");
		printf("\t\t\t\tdrow�� ������ ������ ī�� �� �� �̽��ϴ�.\n\t\t\t\tsee�� �ڽ�, ��� ���� ��Ȳ�� Ȯ���մϴ�. ������ ���� ��µ˴ϴ�.\n");
		printf("\t\t\t\tend�� ���� �����ϴ�.(���� �� ���� �ൿ �Ұ�)\n");
		Sleep(1600);
		goto turn;
	}
	else if (!strcmp(cmd, "start") || !strcmp(cmd, "hard")) { // start ������
		if (!strcmp(cmd, "hard")) {
		hard:
			printf("\t\t\t\tYou really wanna play hard mode?\n\t\t\tY/N\t:  ");
			scanf("%s", &cmd);
			if (!strcmp(cmd, "Y")) {
				printf("\t\t\t\tRespect your opinion.\n");
				hard = 1;
			}
			else if (!strcmp(cmd, "N")) {
				printf("\t\t\t\tWell thought out...\n");
				goto start;
			}
			else {
				printf("\t\t\t\t\tType Error!\n\t\t\t\t\tTry again!\n\n");
				goto hard;
			}
		}
		int end = 0;
		int mStat = 0;
		int eStat = 0;
		printf("\t\t\t\tGame start!\n");

		printf("\t\t\t\tDealer Drow! :: ");
		drow(0, 1);
		printf("/ ");
		if (hard) drow(0, 1);
		else drow(0, 0);
		printf("\n\t\t\t\tMy Drow! :: ");

		if (hard) drow(1, 1);
		else drow(1, 0);
		printf("/ ");
		drow(1, 0);

		while (!end) {
			printf("\n\t\t\t\tYour turn!\n\n\t\t\t\t:  ");
			scanf("%s", &cmd);

		scn:
			if (mStat) {}
			else if (!strcmp(cmd, "die")) mStat = 2;
			else if (!strcmp(cmd, "drow")) {
				if (m_idx >= 7) printf("\t\t\t\t\tYou can't drow any more!\n");
				else {
					printf("\t\t\t\tMy Drow! :: ");
					drow(1, 0);
					printf("\n");
				}
			}
			else if (!strcmp(cmd, "see")) {
				prtInfo();
			}
			else if (!strcmp(cmd, "end")) mStat++;
			else printf("\t\t\t\t\tType Error!\n\t\t\t\t\tTry again!\n\n");
			//emTurn();
			if (!!eStat && !!mStat || mStat == 2) end++;
			else if (mStat) goto scn;
		}

		if (mStat == 2) printf("\t\t\t\t\tYou have been dead!\n"); // ���� ��. ��� ����
		else printf("\t\t\t\t\tEveryone said end!\n");
		printf("\t\t\t\t\tThe winner is");
		Sleep(250);
		printf(".");
		Sleep(250);
		printf(".");
		Sleep(400);
		printf(".");
		Sleep(400);
		printf(".");
		Sleep(500);
		printf(".");
		Sleep(1200);
		if (result() == 0) { // ��� ��
			printf(" Dealer!\n\n\n\t\t\t\t\tYou lose!");
		}
		else if (result() == 1) {
			printf(" Player!\n\n\n\t\t\t\t\tYou win!");
		}
		else {
			printf("No winner");
		}
		Sleep(1500);
		reTry();


		goto start;
	}


	else if (!strcmp(cmd, "exit")) { // exit �� ���
		printf("\n\t\t\t\t\tGood bye! I know you will come back!\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
		Sleep(1200);
	}
	else {
		printf("\t\t\t\t\tType Error!\n\t\t\t\t\tTry again!\n\n");
		goto turn;
	}
	return 0;
}