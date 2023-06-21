#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <time.h>

char cmd[99];

int eScor;
int mScor;

int m_card[10]; // 나의 패
int m_idx; // 나의 패 장 수
int e_card[10]; // 적의 패
int e_idx; // 적의 패 장 수

int deck[52] = { 0 };

void drow(/*오재영이 만든 함수*/int pla /*플레이어 : 1, 상대 : 0*/, int hide /*상대가 뽑았을 때 나한테 안보임*/) {
	int card = 0;
	do {
		srand(time(0)); // 랜덤화
		card = (rand() * 454 % 520) / 10; // 카드 갯수 0 ~ 52 랜덤 뽑기
	} while (deck[card]); // deck[card] 가 1 일때, 뽑힐 때 까지
	int type = card / 13;
	deck[card] = 1; // deck[card] 가 뽑힘
	if (!hide) {
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
		printf(" ");
	}
	else {
		printf("? ? ");
	}

	if (pla) {
		m_card[m_idx] = card; // 나의 현재 패의 deck[card] 추가
		m_idx++; // 나의 다음 인덱스로 넘어감
	}
	else {
		e_card[e_idx] = card; // 상대의 현재 패의 deck[card] 추가
		e_idx++; // 상대 다음 인덱스로 넘어감
	}
	return;
}// 재영쓰가 만든 드로우

void reTry(/*남궁윤교가 만든 함수*/) {
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
} // 모든 변수들 초기화

int result(/*오재영이가 만든 함수*/) {
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
	if (mDist == eDist) { // 거리가 같은 경우
		return 2;
	}
	else if (mDist >= 0 && eDist >= 0) { // 둘다 21 안 인 경우
		if (mDist < eDist) return 1;// 내가 더 가까운 경우
		else return 0; // 상대가 더 가까운 경우
	}
	else { // 둘 중 하나라도 밖인 경우 (둘 다 밖인 경우도 계산해야됨)
		if (mDist < 0 && eDist < 0) {// 둘 다 밖인 경우 (먼저 나온 이유는 밑의 조건식의 반례 제거를 위함임)
			if (mDist > eDist) return 1;// 내가 더 가까운 경우
			else return 0; // 상대가 더 가까운 경우
		}
		else { // 둘 중 하나가 밖인 경우
			if (mDist < 0) return 0;// 내가 밖으로 나간 경우
			else return 1; // 상대가 밖으로 나간 경우
		}
	}
}

void prtInfo(/*남궁윤교가 만든 함수*/) {
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
	printf("\t\t\t\t자신의 패와 합계 : ");
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
	printf("\n\t\t\t\t적의 패와 합계 : ");
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

	printf("%d + x ", eScor);
	if (eCnt) printf("or %d + x", eScor + 10);
}

int main(/*강현욱이 만든 함수*/) {
	printf("\t\t\t\t\tRoading...");
start:
	for (int i = 0; i < 30; i++) {
		printf("\n");
		Sleep(18);
	}

	printf("\n\n\n\t\t\t\t\t\t★!블랙잭!★\n"); // 기본 화면 출력
	printf("\t\t\t\t\tPlease type \"start\" or \"exit\"\n\t\t\t\t\tand if you want some help, type \"help\"!");
turn:
	printf("\n\t\t\t\t:  ");
	scanf("%s", &cmd);
	int hard = 0;

	if (!strcmp(cmd, "help")) {
		printf("\t\t\t\t평범한 블랙잭의 룰과 같습니다!\n\t\t\t\t명령어는 help, drow, see, end가 있으며\n");
		printf("\t\t\t\tdrow는 덱에서 무작위 카드 한 장 뽑습니다.\n\t\t\t\tsee는 자신, 상대 패의 상황을 확인합니다. 점수도 같이 출력됩니다.\n");
		printf("\t\t\t\tend는 손을 놓습니다.(다음 턴 부터 행동 불가)\n");
		Sleep(1600);
		goto turn;
	}
	else if (!strcmp(cmd, "start") || !strcmp(cmd, "hard")) { // start 쳤을시
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

		if (mStat == 2) printf("\t\t\t\t\tYou have been dead!\n"); // 게임 끝. 모두 정리
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
		if (result() == 0) { // 상대 승
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


	else if (!strcmp(cmd, "exit")) { // exit 일 경우
		printf("\n\t\t\t\t\tGood bye! I know you will come back!\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
		Sleep(1200);
	}
	else {
		printf("\t\t\t\t\tType Error!\n\t\t\t\t\tTry again!\n\n");
		goto turn;
	}
	return 0;
}