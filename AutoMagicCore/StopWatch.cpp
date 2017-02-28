/************************************************************
************************************************************/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include "am_common.h"
#include "StopWatch.h"


/************************************************************
************************************************************/

/******************************
******************************/
STOP_WATCH::STOP_WATCH(int _TIMEOUT_ms)
: t_Last_Access_ms(0)
, b_1stAccess(true)
, TIMEOUT_ms(_TIMEOUT_ms)
, b_IsTimePassed(true)
{
}

/******************************
******************************/
STOP_WATCH::~STOP_WATCH()
{
}

/******************************
******************************/
bool STOP_WATCH::IsTimePassed(int now_ms)
{
	if(b_1stAccess){
		b_IsTimePassed = true;
		b_1stAccess = false;
		t_Last_Access_ms = now_ms;
		
	}else if( now_ms == t_Last_Access_ms ){
		// �A���ŃA�N�Z�X���A���Ԃ��i��ł��Ȃ��ꍇ.
		// b_IsTimePassed = b_IsTimePassed;
		
	}else if( TIMEOUT_ms < (now_ms - t_Last_Access_ms) ){
		b_IsTimePassed = true;
		t_Last_Access_ms = now_ms;
		
	}else{
		// t_Last_Access_ms; // �o�߂��Ă��Ȃ����͍X�V���Ȃ� : ���ɗ���x�ɏk��ł��܂��̂�.
		
		b_IsTimePassed = false;
	}
	
	return b_IsTimePassed;
}

/******************************
******************************/
void STOP_WATCH::start(int now_ms, int _TIMEOUT_ms)
{
	if(0 < _TIMEOUT_ms) TIMEOUT_ms = _TIMEOUT_ms;
	
	b_1stAccess = false;
	t_Last_Access_ms = now_ms;
	
	b_IsTimePassed = false;
}

/******************************
******************************/
void STOP_WATCH::Reset()
{
	b_1stAccess = true;
}


