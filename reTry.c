#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <time.h>

int m_card[10]; // ���� ��
int m_idx; // ���� �� �� ��
int e_card[10]; // ���� ��
int e_idx; // ���� �� �� ��
int deck[52] = { 0 }; //ī�� ���� 1�� �� ����
int eScor;
int mScor;

//�ʱ�ȭ reTry

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
