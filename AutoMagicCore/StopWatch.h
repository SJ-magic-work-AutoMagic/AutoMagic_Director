#pragma once

/************************************************************
************************************************************/

/**************************************************
-	�O��A�N�Z�X����w�莞�� �o�߂��Ă��邩�ǂ�����m�邽�߂�class
-	����A�N�Z�X��true
-	Reset�@�\����
-	�������ԂɘA���ŃA�N�Z�X�����ꍇ�́A�O��̌���(�o�߂������ǂ���)�����̂܂ܕԂ�
**************************************************/
class STOP_WATCH{
private:
	bool b_1stAccess;
	
	int t_Last_Access_ms;
	int TIMEOUT_ms;
	
	FILE *fp;
	
	bool b_IsTimePassed;
	
public:
	STOP_WATCH(int _TIMEOUT_ms);
	~STOP_WATCH();
	
	bool IsTimePassed(int now_ms);
	void Reset();
	void start(int now_ms, int _TIMEOUT_ms = -1);
};



