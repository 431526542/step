#include "Initialize.h"
#include"Common.h"

void Initialize()
{
	//ī������ �ֱ�
	//�����̵� 1~10,j,q,k ��13��
	for (int i = 0; i <= 12; ++i)
	{
		cards[i].mark = Spade;
		cards[i].number = i + 1;
	}
	//���̾� 1~10,j,q,k ��13��
	for (int i = 13; i <= 25; ++i)
	{
		cards[i].mark = Dia;
		cards[i].number = i - 12;
	}
	//��Ʈ 1~10, j, q, k ��13��
	for (int i = 26; i <= 38; ++i)
	{
		cards[i].mark = Heart;
		cards[i].number = i - 25;
	}
	//Ŭ�ι� 1~10, j, q, k ��13��
	for (int i = 39; i <= 51; ++i)
	{
		cards[i].mark = Clover;
		cards[i].number = i - 38;
	}
}
