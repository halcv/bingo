#ifndef _MAIN_WINDOW_H_
#define _MAIN_WINDOW_H_

#include <QObject>
#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QTimer>
#include "data.h"

class CMainWindow : public QMainWindow {
	Q_OBJECT;

  public:
	CMainWindow();
	~CMainWindow();

  private slots:
	void StartButtonClicked();
	void DispAnimation();
	
  private:
	void CreateParentWindow();
	void CreateChildWidget();
	void CreateConnect();
	void UpdateLabel(int data);
	
	QLabel m_lblArray[75];
	QLabel m_lblNumber;
	QPushButton m_btnStart;
	CBingoData m_BingoData;
	QTimer m_Timer;
	int m_iAnimationPos;
	int* m_pAnimationData;
	int m_iAnimationCnt;
};

#endif // _MAIN_WINDOW_H_
