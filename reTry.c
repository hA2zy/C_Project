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

//초기화 reTry

//void reTry() {
//	for (int i = 0; i < 10; i++) {
//		m_card[i] = 0;
//		e_card[i] = 0;
//	}
//	for (int j = 0; j < 52; j++) {
//		deck[j] = 0;
//	}
//	m_idx = 0;
//	e_idx = 0;
//	eScor = 0;
//	mScor = 0;
//}
