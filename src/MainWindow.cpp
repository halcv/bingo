#include <QDebug>
#include <QApplication>
#include <QDesktopWidget>
#include "MainWindow.h"

#define  DEBUG (0)

CMainWindow::CMainWindow()
{
#if DEBUG
	qDebug() << __func__;
#endif

	CreateParentWindow();
	CreateChildWidget();
	CreateConnect();
	
	show();
}

CMainWindow::~CMainWindow()
{
#if DEBUG
	qDebug() << __func__;
#endif


}

void CMainWindow::CreateParentWindow()
{
#if DEBUG
	qDebug() << __func__;
#endif

	setFixedSize(1300,700);
	QDesktopWidget *desktop = QApplication::desktop();
	move((desktop->width() - width()) / 2,(desktop->height() - height()) / 2);
	setStyleSheet("background-color: #050510;");
}

void CMainWindow::CreateChildWidget()
{
#if DEBUG
	qDebug() << __func__;
#endif
	
	int num = 0;
	for (int i = 0;i < 5;i++) {
		for (int j = 0;j < 15;j++) {
			QString str;
			const int offset_x = 895;
			const int offset_y = 5;
			m_lblArray[num].setParent(this);
			m_lblArray[num].setText(str.setNum(num + 1,10));
			m_lblArray[num].setFont(QFont("Ricty",30,QFont::Bold));
			m_lblArray[num].setStyleSheet("background-color:#00ffff;color:#202020;border-style: outset;border-width: 2px;border-color: #000000");
			m_lblArray[num].setAlignment(Qt::AlignVCenter | Qt::AlignHCenter);
			m_lblArray[num].setGeometry(offset_x + i * 80,offset_y + j * 46,80,46);
			num++;
		}
	}

	m_lblNumber.setParent(this);
	m_lblNumber.setText(tr("？"));
	m_lblNumber.setFont(QFont("Ricty",600));
	m_lblNumber.setStyleSheet("background-color:#b0b000;color:#b00000");
	m_lblNumber.setAlignment(Qt::AlignVCenter | Qt::AlignHCenter);
	m_lblNumber.setGeometry(7,7,885,640);
						
	m_btnStart.setParent(this);
	m_btnStart.setText(tr("スタート"));
	m_btnStart.setFont(QFont("Ricty",30));
	m_btnStart.setStyleSheet("background-color:#00b000;color:#b000b0");
	m_btnStart.setGeometry(330,654,200,40);
}

void CMainWindow::CreateConnect()
{
#if DEBUG
	qDebug() << __func__;
#endif

	QObject::connect(&m_btnStart,SIGNAL(clicked()),this,SLOT(StartButtonClicked()));
	QObject::connect(&m_Timer,SIGNAL(timeout()),this,SLOT(DispAnimation()));
}

void CMainWindow::StartButtonClicked()
{
#if DEBUG
	qDebug() << __func__;
#endif
	
	m_btnStart.setVisible(false);
	
	m_iAnimationPos = 0;
	m_pAnimationData = m_BingoData.GetDataPointer();
	m_iAnimationCnt = 0;
	m_Timer.start(10);
}

void CMainWindow::UpdateLabel(int data)
{
#if DEBUG
	qDebug() << __func__;
#endif

	QString str;
	m_lblNumber.setText(str.setNum(data,10));
	m_lblArray[data - 1].setStyleSheet("background-color:#ff0000;color:#f0f0f0;border-style: outset;border-width: 2px;border-color: #000000");
}

void CMainWindow::DispAnimation()
{
#if DEBUG
	qDebug() << __func__;
#endif

	QString str;
	m_lblNumber.setText(str.setNum(*(m_pAnimationData + m_iAnimationPos),10));
	m_iAnimationPos++;
	if (m_iAnimationPos >= m_BingoData.GetDataSize()) {
		m_iAnimationPos = 0;
	}
	m_iAnimationCnt++;
	if (m_iAnimationCnt > 200) {
		m_Timer.stop();
		int data = m_BingoData.GetData(m_BingoData.GetPosition());
		UpdateLabel(data);
		if (m_BingoData.IsDataEnd()) {
			m_btnStart.setVisible(false);
		} else {
			m_btnStart.setVisible(true);
		}
	}
}
