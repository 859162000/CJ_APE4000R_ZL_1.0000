
#include "APIskjProc.h"

#include "LOGCTRL.h"
//#define NO_POS_DEBUG
#include "pos_debug.h"

#if TYPE_MODE == SKJ_MODE

#include "CGlobalArg.h"
#include "ManageBusinessFunc.h"
#include "InvBusinessFunc.h"
#include "SaleBusinessFunc.h"
#include "DeclareBusinessFunc.h"
#include "DataClassDesign.h"
#include "SKJDataTransformFunc.h"

#define  TJXXCX_MONTHMAX 6

CAPIskjProc::CAPIskjProc()
{
	
}

CAPIskjProc::~CAPIskjProc()
{
	
}

/*!
 ��ȡ˰���豸���		
*/
INT32  CAPIskjProc::GetSksbbh_API(CYWXML_GY &ywxml_gy, string &sksbbh, string &bspbh, string &qtxx, string &strErr)
{
	INT32 ret = SUCCESS;
	
	CManageBusinessFunc managBusFun;

	ret= managBusFun.GetSksbbh(ywxml_gy, sksbbh, bspbh, qtxx, strErr);
	
	if (ret !=SUCCESS)
	{
		return FAILURE;
	}

	return ret;
}

/*!
 ��ȡ˰���豸��Ϣ		
*/
INT32  CAPIskjProc::GetTaxpayerInfo_API(CYWXML_GY &ywxml_gy, CUserInfo &UserInfo, string &strCurTime, string &strErr)
{
	DBG_PRINT(("����CAPIskjProc::GetTaxpayerInfo_API����"));

	INT32 ret = SUCCESS;

	CDataUserInfo dataUserInfo;

	CManageBusinessFunc managBusFun;
	
	ret= managBusFun.GetTaxpayerInfo(ywxml_gy, dataUserInfo, strCurTime, strErr);
	CSKJDataTransformFunc::Data2UserInfo(&dataUserInfo, &UserInfo);
	
	if (ret !=SUCCESS)
	{
		return FAILURE;
	}

	DBG_PRINT(("�˳�CAPIskjProc::GetTaxpayerInfo_API����"));
	
	return ret;
}

/*!
 ��ȡ��˰����Ϣ		
*/
INT32  CAPIskjProc::GetBSPInfo_API(CYWXML_GY &ywxml_gy, CUserInfo &userInfo, string &strErr)
{
	INT32 ret = SUCCESS;

	CDataUserInfo dataUserInfo;
	CManageBusinessFunc managBusFun;

	ret= managBusFun.GetBSPInfo(ywxml_gy, dataUserInfo, strErr);
	CSKJDataTransformFunc::Data2UserInfo(&dataUserInfo, &userInfo);
	
	if (ret !=SUCCESS)
	{
		return FAILURE;
	}

	return ret;
}

/*!
 ��ȡ�������		
*/
INT32  CAPIskjProc::GetJKSJ_API(CYWXML_GY &ywxml_gy, CInvKind &InvKind, string &strErr)
{
	INT32 ret = SUCCESS;

	CDataInvKind dataInvKind;
	CManageBusinessFunc managBusFun;

	ret= managBusFun.GetJKSJ(ywxml_gy, dataInvKind, strErr);
	CSKJDataTransformFunc::Data2InvKind(&dataInvKind, &InvKind);

	if (ret !=SUCCESS)
	{
		return FAILURE;
	}

	return ret;
}

/*!
 ��ȡ˰����Ϣ		
*/
INT32  CAPIskjProc::GetTaxRateInfo_API(CYWXML_GY &ywxml_gy, CTax *pTax, UINT8 &taxNum, string &strErr)
{
	INT32 ret = SUCCESS;

	CDataTax dataTax[MAX_TAX_NUM];
	CManageBusinessFunc managBusFun;
	
	ret= managBusFun.GetTaxRateInfo(ywxml_gy, dataTax, taxNum, strErr);
	for(int i=0; i<taxNum; i++)
	{
		CSKJDataTransformFunc::Data2Tax(&dataTax[i], &pTax[i]);
	}
	
	if (ret !=SUCCESS)
	{
		return FAILURE;
	}

	return ret;
}

/*!
 ��˰�̿�����
*/
INT32  CAPIskjProc::SKPKLBG_API(CYWXML_GY &ywxml_gy, string ykl, string xkl, string &strErr)
{
	INT32 ret = SUCCESS;

	CManageBusinessFunc managBusFun;
	
	ret= managBusFun.SKPKLBG(ywxml_gy, ykl, xkl, strErr);
	
	if (ret !=SUCCESS)
	{
		return FAILURE;
	}

	return ret;
}

/*!
	@brief ���֤�����
*/
INT32 CAPIskjProc::BGZSKL_API(CYWXML_GY &ywxml_gy, string ykl, string xkl, string &strErr)
{
	INT32 ret = SUCCESS;
	
	CManageBusinessFunc managBusFun;
	
	ret= managBusFun.BGZSKLProc(ywxml_gy, ykl, xkl, strErr);
	
	if (ret !=SUCCESS)
	{
		return FAILURE;
	}
	
	return ret;

}

/*!
 ����������Ϣ		
*/
INT32  CAPIskjProc::LXXXUpdatePro_API(CYWXML_GY &ywxml_gy, string &strErr)
{
	INT32 ret = SUCCESS;

	CManageBusinessFunc managBusFun;
	
	ret= managBusFun.LXXXUpdatePro(ywxml_gy, strErr);
	
	if (ret !=SUCCESS)
	{
		return FAILURE;
	}

	return ret;
}


INT32 CAPIskjProc::OnLine(string &strErr)
{
	UINT8 ret = SUCCESS;
	return ret;
}

INT32 CAPIskjProc::SetBaudRate(UINT32 btl, string &strErr)
{
	UINT8 ret = SUCCESS;
	
	return ret;
}

/*!
 �������ά��
*/
INT32  CAPIskjProc::NetParaManage_API(CNetPara *pNetPara, string &strErr)
{
	INT32 ret = SUCCESS;


	return ret;
}


/*!
 ��˰�̷�Ʊ��ѯ����Ʊ����Ϣ��ѯ��
*/
INT32  CAPIskjProc::BSPFPCXPro_API(CYWXML_GY &ywxml_gy, UINT32 &InvCount, CInvVol *pInvVol, string &strErr)
{
	INT32 ret = SUCCESS;

	CDataInvVol dataInvVol[INVVOL_MAX_NUM];
	CInvBusinessFunc invBusFun;
	
	ret= invBusFun.BSPFPCXPro(ywxml_gy, InvCount, dataInvVol, strErr);
	for(int i=0; i<InvCount; i++)
	{
		CSKJDataTransformFunc::Data2InvVol(&dataInvVol[i], &pInvVol[i]);
	}
	
	if (ret !=SUCCESS)
	{
		return FAILURE;
	}

	return ret;
}

/*!
 ��Ʊ�ַ���������
*/
INT32  CAPIskjProc::ZJInvDistribute_API(CYWXML_GY &ywxml_gy, CInvVol *pInvVol, UINT8 strJzlx, string &strErr)
{
	INT32 ret = SUCCESS;

	CDataInvVol dataInvVol;
	CInvBusinessFunc invBusFun;

	CSKJDataTransformFunc::InvVol2Data(pInvVol, &dataInvVol, ywxml_gy.m_fplxdm);
	ret= invBusFun.ZJInvDistribute(ywxml_gy, &dataInvVol, strJzlx, strErr);
	
	if (ret !=SUCCESS)
	{
		return FAILURE;
	}

	return ret;
}

/*!
 ��Ʊ�˻أ��ֻ���
*/

INT32  CAPIskjProc::ZJInvRecover_API(CYWXML_GY &ywxml_gy, CInvVol *pInvVol, UINT8 strJzlx, string &strErr)
{
	INT32 ret = SUCCESS;

	CDataInvVol dataInvVol;
	CInvBusinessFunc invBusFun;
	
	CSKJDataTransformFunc::InvVol2Data(pInvVol, &dataInvVol, ywxml_gy.m_fplxdm);
	ret= invBusFun.ZJInvRecover(ywxml_gy, &dataInvVol, strJzlx, strErr);
	
	if (ret !=SUCCESS)
	{
		return FAILURE;
	}

	return ret;
}

/*!
 ��Ʊ�ջأ�������
*/
INT32  CAPIskjProc::FJInvReturn_API(CYWXML_GY &ywxml_gy, UINT8 strJzlx, string &strErr)
{
	INT32 ret = SUCCESS;

	CInvBusinessFunc invBusFun;
	
	ret= invBusFun.FJInvReturn(ywxml_gy, strJzlx, strErr);
	
	if (ret !=SUCCESS)
	{
		return FAILURE;
	}

	return ret;
}

/*!
 ͳ����Ϣ��ѯ
*/
INT32  CAPIskjProc::TJXXCXPro_API(CYWXML_GY &ywxml_gy, CDataTjxxhz *pTjxxhz, string &strErr)
{
	INT32 ret = SUCCESS;

	CInvBusinessFunc invBusFun;

	INT32 monthcount = TJXXCX_MONTHMAX;
	DBG_PRINT(("ywxml_gy.m_fplxdm : %s", ywxml_gy.m_fplxdm.c_str()));

	ret= invBusFun.TJXXCXPro(ywxml_gy, monthcount, pTjxxhz, strErr);
	
	if (ret !=SUCCESS)
	{
		return FAILURE;
	}

	return ret;
}

/*!
 ���ʹ�Ʊ(��Ʊ����)
*/
INT32  CAPIskjProc::InvReadIn_API(CYWXML_GY &ywxml_gy, UINT8 strJzlx, string &strErr)
{
	INT32 ret = SUCCESS;

	CInvBusinessFunc invBusFun;
	
	ret= invBusFun.InvReadIn(ywxml_gy, strJzlx, strErr);
	
	if (ret !=SUCCESS)
	{
		return FAILURE;
	}

	return ret;
}

/*!
 ������ȡ��Ʊ��������
*/
INT32  CAPIskjProc::WLLQFPPro_API(CYWXML_GY &ywxml_gy, CInvVol *pInvVol, string &strErr)
{
	INT32 ret = SUCCESS;

	CDataInvVol dataInvVol;
	CInvBusinessFunc invBusFun;

	CSKJDataTransformFunc::InvVol2Data(pInvVol, &dataInvVol, ywxml_gy.m_fplxdm);
	ret= invBusFun.WLLQFPPro(ywxml_gy, &dataInvVol, strErr);

	if (ret !=SUCCESS)
	{
		return FAILURE;
	}

	return ret;
}

/*!
 ������ȡ��Ʊ���ȷ�ϣ�������
*/
INT32  CAPIskjProc::WLLQFPJGQRPro_API(CYWXML_GY &ywxml_gy, CInvVol *pInvVol, string &strErr)
{
	INT32 ret = SUCCESS;

	CDataInvVol dataInvVol;
	CInvBusinessFunc invBusFun;
	
	CSKJDataTransformFunc::InvVol2Data(pInvVol, &dataInvVol, ywxml_gy.m_fplxdm);
	ret= invBusFun.WLLQFPJGQRPro(ywxml_gy, &dataInvVol, strErr);
	CSKJDataTransformFunc::Data2InvVol(&dataInvVol, pInvVol);

	if (ret !=SUCCESS)
	{
		return FAILURE;
	}

	return ret;
}

/*!
 ��Ʊ��Ϣ��ѯ����ȡ��ǰƱ�ţ�
*/
INT32  CAPIskjProc::GetCurInvInfo_API(CYWXML_GY &ywxml_gy, CInvVol *pInvVol, string &strErr)
{
	INT32 ret = SUCCESS;

	CDataInvVol dataInvVol;
	CSaleBusinessFunc  saleBusFun;

	ret= saleBusFun.GetCurInvInfo(ywxml_gy, &dataInvVol, strErr);
	dataInvVol.m_fplxdm = ywxml_gy.m_fplxdm;
	CSKJDataTransformFunc::Data2InvVol(&dataInvVol, pInvVol);

	if (ret !=SUCCESS)
	{
		return FAILURE;
	}
	
	return ret;
}

/*!
 ��Ʊ���ߣ�������Ʊ����Ʊ��		
*/
INT32  CAPIskjProc::MakeNormalInv_API(CYWXML_GY &ywxml_gy, CInvHead *pInvHead, string &strErr)
{
	INT32 ret = SUCCESS;

	CDataInvHead dataInvHead;
    CSaleBusinessFunc  saleBusFun;

	CSKJDataTransformFunc::InvHead2Data(pInvHead, &dataInvHead, ywxml_gy.m_fplxdm);
	ret= saleBusFun.MakeNormalInv(ywxml_gy, &dataInvHead, strErr);
	CSKJDataTransformFunc::Data2InvHead(&dataInvHead, pInvHead);

	if (ret !=SUCCESS)
	{
		return FAILURE;
	}
	
	return ret;
}

/*!
 ��Ʊ���ϣ��հ׷�Ʊ���ѿ�Ʊ���ϣ�
*/
INT32  CAPIskjProc::MakeWasteInv_API(CYWXML_GY &ywxml_gy, CInvHead *pInvHead, UINT8 zflx, string &strErr)
{
	INT32 ret = SUCCESS;

	CDataInvHead dataInvHead;
	CSaleBusinessFunc  saleBusFun;

	CSKJDataTransformFunc::InvHead2Data(pInvHead, &dataInvHead, ywxml_gy.m_fplxdm);
	ret= saleBusFun.MakeWasteInv(ywxml_gy, &dataInvHead, zflx, strErr);
	CSKJDataTransformFunc::Data2InvHead(&dataInvHead, pInvHead);

	if (ret !=SUCCESS)
	{
		return FAILURE;
	}
	
	return ret;
}

/*!
 ��Ʊ��ѯ
*/
INT32  CAPIskjProc::GetInvHeadInfo_API(CYWXML_GY &ywxml_gy, UINT8 cxfs, string cxtj, UINT32 &invNum, CInvHead *pInvhead, string &strErr)
{
	INT32 ret = SUCCESS;

	CDataInvHead dataInvHead;
	CSaleBusinessFunc  saleBusFun;

	ret= saleBusFun.GetInvHeadInfo(ywxml_gy, cxfs, cxtj, invNum, &dataInvHead, strErr);
	CSKJDataTransformFunc::Data2InvHead(&dataInvHead, pInvhead, 1);
	
	if (ret !=SUCCESS)
	{
		return FAILURE;
	}
	
	return ret;
}

/*!
 ��Ʊʵʱ�ϴ�
*/
INT32  CAPIskjProc::InvoiceUpload_API(CYWXML_GY &ywxml_gy, string &strErr)
{
	INT32 ret = SUCCESS;

#if TYPE_MODE ==  SKJ_MODE
//	CSaleBusinessFunc  saleBusFun;
//	do 
//	{
//	ret= saleBusFun.InvoiceUpload(ywxml_gy, strErr);
//	} while(ret == SUCCESS);

// 	ret= saleBusFun.InvoiceUpload(ywxml_gy, strErr);
// 	
// 	if (ret !=SUCCESS)
// 	{
// 		return FAILURE;
// 	}
	g_globalArg->m_pthreadNsrsbh = ywxml_gy.m_nsrsbh;
	g_globalArg->m_pthreadSksbbh = ywxml_gy.m_sksbbh;
	g_globalArg->m_pthreadSksbkl = ywxml_gy.m_sksbkl;
	g_globalArg->m_pthreadFplxdm = ywxml_gy.m_fplxdm;
	g_globalArg->m_pthreadJqbh = ywxml_gy.m_jqbh;
	g_globalArg->m_pthreadKpjh = ywxml_gy.m_kpjh;
	g_globalArg->m_pthreadZskl = ywxml_gy.m_zskl;

	if(	g_globalArg->m_pthreadFlag == 0)
	{
		g_globalArg->m_pthreadFlag = 1;
	}
	else
	{
		g_globalArg->m_pthreadFlag = 0;
		strErr = "ֹͣ��Ʊ�ϴ�";
		ret = FAILURE;
	}
	DBG_PRINT(("g_globalArg->m_pthreadFlag = %u", g_globalArg->m_pthreadFlag));
#endif
	return ret;
}

/*!
 ���糭��
*/
INT32  CAPIskjProc::NetDeclareProc_API(CYWXML_GY &ywxml_gy, string &strErr)
{
	INT32 ret = SUCCESS;

	CDeclareBusinessFunc  declareBusFun;
	ret= declareBusFun.NetDeclareProc(ywxml_gy, strErr);
	
	if (ret !=SUCCESS)
	{
		return FAILURE;
	}

	return ret;
}

/*!
 ���ʳ���������ʱ��ʾѡ���˰�̻��߱�˰�̣�
*/
INT32  CAPIskjProc::DeclareProc_API(CYWXML_GY &ywxml_gy, UINT8 jzlx, string &strErr)
{
	INT32 ret = SUCCESS;

	CDeclareBusinessFunc  declareBusFun;
	ret= declareBusFun.DeclareProc(ywxml_gy, jzlx, strErr);
	
	if (ret !=SUCCESS)
	{
		return FAILURE;
	}

	return ret;
}

/*!
 �����忨
*/
INT32  CAPIskjProc::NetUpdateTaxProc_API(CYWXML_GY &ywxml_gy, string &strErr)
{
	INT32 ret = SUCCESS;

	CDeclareBusinessFunc  declareBusFun;
	ret= declareBusFun.NetUpdateTaxProc(ywxml_gy, strErr);
	
	if (ret !=SUCCESS)
	{
		return FAILURE;
	}

	return ret;
}


/*!
 ��˰���忨
*/
INT32  CAPIskjProc::UpdateTaxProc_API(CYWXML_GY &ywxml_gy, string &strErr)
{
	INT32 ret = SUCCESS;

	CDeclareBusinessFunc  declareBusFun;
	ret= declareBusFun.UpdateTaxProc(ywxml_gy, strErr);
	
	if (ret !=SUCCESS)
	{
		return FAILURE;
	}

	return ret;
}

INT32 CAPIskjProc::Fpbl_API(CYWXML_GY &ywxml_gy, UINT32 bsqsrq, UINT32 bszzrq, string &strErr)
{

	INT32 ret = SUCCESS;
	
	CSaleBusinessFunc  saleBusFun;
	ret = saleBusFun.FpblProStart(ywxml_gy, bsqsrq, bszzrq, strErr);
	
	if (ret !=SUCCESS)
	{
		return FAILURE;
	}
	
	return ret;
}

INT32 CAPIskjProc::Hqlxsj_API(CYWXML_GY &ywxml_gy, string &wscfpzs, string &wscfpsj, string &wscfpljje, string &sczs, string &scsjjg, string &strErr)
{
	INT32 ret = SUCCESS;
	UINT32 nfpzs = 0;
	INT64  nfpljje = 0;
	INT8 tmpbuf[32];

	CManageBusinessFunc managBusFun;
	ret = managBusFun.GetOffLineInvInfo(ywxml_gy, nfpzs, wscfpsj, nfpljje, strErr);
	if (ret !=SUCCESS)
	{
		return FAILURE;
	}
	memset(tmpbuf, 0, sizeof(tmpbuf));
	sprintf(tmpbuf, "%u", nfpzs);
	wscfpzs = tmpbuf;
	memset(tmpbuf, 0, sizeof(tmpbuf));
	sprintf(tmpbuf, "%.2f", ((double)(nfpljje)/SUM_EXTENSION));
	wscfpljje = tmpbuf;
	
	return ret;
}

INT32 CAPIskjProc::LibClearDepot(string &strErr)
{
	UINT8 ret = SUCCESS;
	CManageBusinessFunc managBusFun;
	
	ret = managBusFun.ClearMidDepot(strErr);
	
	return ret;
}


// INT32 CAPIskjProc::ServerTest_API(CYWXML_GY &ywxml_gy, string &strErr)
// {
// 
// 	return SUCCESS;
// }


/*!
 ��˰�̷�Ʊ��ѯ����Ʊ����Ϣ��ѯ��
*/
INT32 CAPIskjProc::InvUpFailInfo_API(CYWXML_GY &ywxml_gy, CDataInvServ *pDataInvServ, UINT32 &nCount, string &strErr)
{
	INT32 ret = SUCCESS;

	CSaleBusinessFunc salFunc;
	
	ret= salFunc.GetErrUpInvInfo(ywxml_gy, pDataInvServ, nCount, strErr);
	
	if (ret !=SUCCESS)
	{
		return FAILURE;
	}

	return ret;
}




#endif

