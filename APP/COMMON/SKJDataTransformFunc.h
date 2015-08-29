#ifndef SKJ_DATA_TRANSFORM_FUNC_H
#define SKJ_DATA_TRANSFORM_FUNC_H

#include "IncludeMe.h"
#include "DataClassDesign.h"
#include "CInvHead.h"
#include "CUserInfo.h"
#include "CInvKind.h"
#include "CInvVol.h"
#include "CTax.h"
#include "CNetPara.h"

class CSKJDataTransformFunc
{
public:

	CSKJDataTransformFunc();
	~CSKJDataTransformFunc();

	static void UserInfo2Data(CUserInfo *pUserInfo, CDataUserInfo *pDataUserInfo);
	static void Data2UserInfo(CDataUserInfo *pDataUserInfo, CUserInfo *pUserInfo);
	
	static void InvKind2Data(CInvKind *pInvKind, CDataInvKind *pDataInvKind);
	static void Data2InvKind(CDataInvKind *pDataInvKind, CInvKind *pInvKind);
	
	static void Tax2Data(CTax *pTax, CDataTax *pDataTax);
	static void Data2Tax(CDataTax *pDataTax, CTax *pTax);
	
	static void InvVol2Data(CInvVol *pInvVol, CDataInvVol *pDataInvVol, string fplxdm);
	static void Data2InvVol(CDataInvVol *pDataInvVol, CInvVol *pInvVol);
	
	static void InvHead2Data(CInvHead *pInvHead, CDataInvHead *pDataInvHead, string fplxdm);
	static void Data2InvHead(CDataInvHead *pDataInvHead, CInvHead *pInvHead, UINT8 flag=0);
	
	static void NetPara2Data(CNetPara *pNetPara, CDataNetPara *pDataNetPara);
	static void Data2NetPara(CDataNetPara *pDataNetPara, CNetPara *pNetPara);
	
};

#endif

