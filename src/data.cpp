#include <QDebug>
#include <QTime>
#include "data.h"

#define DEBUG (0)

CBingoData::CBingoData()
{
#if DEBUG
	qDebug() << __func__;
#endif

	m_iPosition = 0;
	InitData();
	ShuffleData();
	CheckData();
}

CBingoData::~CBingoData()
{
#if DEBUG
	qDebug() << __func__;
#endif
}

void CBingoData::InitData()
{
#if DEBUG
	qDebug() << __func__;
#endif

	for (int i = 0;i < DATA_SIZE;i++) {
		m_iData[i] = i + 1;
	}
}

void CBingoData::ShuffleData()
{
#if DEBUG
	qDebug() << __func__;
#endif

	QTime time = QTime::currentTime();
	qsrand((uint)time.msec());

	for (int i = 0;i < (DATA_SIZE - 1);i++) {
		int temp;
		int random;
		random = qrand() % (DATA_SIZE - i);
		temp = m_iData[random + i];
		m_iData[random + i] = m_iData[i];
		m_iData[i] = temp;
	}
}

void CBingoData::CheckData()
{
	for (int i = 0;i < DATA_SIZE;i++) {
		if (m_iData[i] < 1 || m_iData[i] > DATA_SIZE) {
			qDebug() << "Data Error!!!!";
		}
	}
}

int CBingoData::GetData(int pos)
{
	int data = m_iData[pos];
	m_iPosition++;
	
	return data;
}

int CBingoData::GetPosition()
{
	return m_iPosition;
}

bool CBingoData::IsDataEnd()
{
	bool bRet = false;
	if (m_iPosition >= DATA_SIZE) {
		bRet = true;
	}

	return bRet;
}

int* CBingoData::GetDataPointer()
{
	return m_iData;
}

int CBingoData::GetDataSize()
{
	return DATA_SIZE;
}
