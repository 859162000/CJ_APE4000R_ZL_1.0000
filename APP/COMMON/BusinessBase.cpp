

#include "BusinessBase.h"
#include "BusinessJSKProc.h"
#include "BusinessXmlProc.h"
#include "VersionConfig.h"

#include "LOGCTRL.h"
//#define NO_POS_DEBUG
#include "pos_debug.h"


#if BUSINESS_TYPE_MODE == BUSINESS_JSK_MODE
#include "JSKInfoDef.h"
//#include "SKJYWXmlBase.h"
static CBusinessJSKProc busJSKProc;
#endif
#if BUSINESS_TYPE_MODE == BUSINESS_XML_MODE
static CBusinessXmlProc busXmlProc;
#endif

CBusinessBase *g_pBusBase = NULL;


#if SKJ_PTHREAD_KPMUTEX_OPEN == 2
pthread_mutex_t *g_skjkpmutex = new pthread_mutex_t;
pthread_mutexattr_t skjmattr;
int skjret = pthread_mutexattr_init(&skjmattr);
int skjret1 = pthread_mutexattr_settype(&skjmattr, PTHREAD_MUTEX_RECURSIVE_NP);
int skjret2 = pthread_mutex_init(g_skjkpmutex, &skjmattr);
int skjret3 = pthread_mutexattr_destroy(&skjmattr);
//static pthread_mutex_t	g_skjkpmutex = PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP;
#endif


void CBusinessBase::MutexLock(void)
{
#if SKJ_PTHREAD_KPMUTEX_OPEN == 2
	DBG_ASSERT_EXIT((g_skjkpmutex != NULL), (" g_skjkpmutex == NULL!"));
	
	//while (pthread_mutex_trylock(g_skjkpmutex) == EBUSY)
	while (pthread_mutex_lock(g_skjkpmutex) != 0)
	{
		DBG_PRINT(("===FPKJ MUTEX LOCK ERROR"));
		//CommonSleep(800);
	}
	DBG_PRINT(("*******************SKJ Mutex Lock******************"));
#endif
}


void CBusinessBase::MutexUnlock(void)
{
#if SKJ_PTHREAD_KPMUTEX_OPEN == 2
	DBG_ASSERT_EXIT((g_skjkpmutex != NULL), (" g_skjkpmutex == NULL!"));
	
	int ret = 0;	
	DBG_PRINT(("*******************SKJ Mutex Unlock****************"));
	ret = pthread_mutex_unlock(g_skjkpmutex);
	if (ret != 0)
	{
		DBG_PRINT(("===FPKJ MUTEX UNLOCK %d====", ret));
	}
#endif
}


void CBusinessBase::InitBusiness()
{
#if BUSINESS_TYPE_MODE == BUSINESS_JSK_MODE
	g_pBusBase = &busJSKProc;
#endif
#if BUSINESS_TYPE_MODE == BUSINESS_XML_MODE
	g_pBusBase = &busXmlProc;
#endif
}

INT32 CBusinessBase::ErrParse(INT32 retCode, string &retMsg)
{
#if BUSINESS_TYPE_MODE == BUSINESS_JSK_MODE
	if(retCode == JSK_SUCCESS)
		return SUCCESS;
#endif
#if BUSINESS_TYPE_MODE == BUSINESS_XML_MODE
	if(retCode == XML_SUCCESS)
		return SUCCESS;
#endif
	
	if( (retCode == JSK_FAILURE) || (retCode == XML_FAILURE) )
	{
		return FAILURE;
	}

	if(retMsg.length() > MAX_ERR_MSG_LEN)
		retMsg.erase(MAX_ERR_MSG_LEN, retMsg.length()-MAX_ERR_MSG_LEN);

	INT8 tmpBuf[512];
	memset(tmpBuf, 0, sizeof(tmpBuf));
	sprintf(tmpBuf, "%d:%s", retCode, retMsg.c_str());
	retMsg = tmpBuf;
	DBG_PRINT(("retMsg = %s", retMsg.c_str()));

	return FAILURE;
}



