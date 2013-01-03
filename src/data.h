#ifndef _DATA_H_
#define _DATA_H_

#define DATA_SIZE (75)

class CBingoData {
  public:
	CBingoData();
	~CBingoData();
	int GetData(int pos);
	int GetPosition();
	bool IsDataEnd();
	int* GetDataPointer();
	int GetDataSize();
	
  private:
	void ShuffleData();
	void InitData();
	void CheckData();
	int m_iData[DATA_SIZE];
	int m_iPosition;
};

#endif // _DATA_H_
