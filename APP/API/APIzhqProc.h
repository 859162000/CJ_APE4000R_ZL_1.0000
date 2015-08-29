/****************************************************************************
�ļ���           ��APIzhqBase.h
����             ��awe4000rҵ�����̳�Ѫ��
��ʼ����         ��
����             �� 
****************************************************************************/

#ifndef API_ZHQ_PROC_H
#define API_ZHQ_PROC_H

#include "APIBase.h"

#if TYPE_MODE == ZHQ_MODE

#include "CBusinessSerialProc.h"
#include "CNetPara.h"

class CAPIzhqProc : public CAPIBase
{
private:

	CBusinessSerialProc m_SerialProc;
public:
	
	CAPIzhqProc();
	~CAPIzhqProc();

	/*!
	@brief ����	
	@param[in] 
	@param[out] strErr   ������Ϣ
	@return  1 SUCCESS�� 0  FAILURE
	*/
	INT32 OnLine(string &strErr);

	/*!
	@brief ���ò�����	
	@param[in] ������
	@param[out] strErr   ������Ϣ
	@return  1 SUCCESS�� 0  FAILURE
	*/
	INT32 SetBaudRate(UINT32 btl, string &strErr);

	/*!
	@brief ��ȡ˰���豸���		
	@param[in] 
	@param[out] strErr   ������Ϣ
	@return  1 SUCCESS�� 0  FAILURE
	*/
	INT32 GetSksbbh_API(CYWXML_GY &ywxml_gy, string &sksbbh, string &bspbh, string &qtxx, string &strErr);
	
	/*!
	@brief ��ȡ˰���豸��Ϣ		
	@param[in] 
	@param[out] strErr   ������Ϣ
	@return  1 SUCCESS�� 0  FAILURE
	*/
	INT32 GetTaxpayerInfo_API(CYWXML_GY &ywxml_gy, CUserInfo &UserInfo, string &strCurTime, string &strErr);
	
	/*!
	@brief ��ȡ��˰����Ϣ		
	@param[in] 
	@param[out] strErr   ������Ϣ
	@return  1 SUCCESS�� 0  FAILURE
	*/
	INT32 GetBSPInfo_API(CYWXML_GY &ywxml_gy, CUserInfo &userInfo, string &strErr);
	
	/*!
	@brief ��ȡ�������		
	@param[in] 
	@param[out] strErr   ������Ϣ
	@return  1 SUCCESS�� 0  FAILURE
	*/
	INT32 GetJKSJ_API(CYWXML_GY &ywxml_gy, CInvKind &InvKind, string &strErr);
	
	/*!
	@brief ��ȡ˰����Ϣ		
	@param[in] pTax ˰��������
	@param[out] strErr   ������Ϣ
	@return  1 SUCCESS�� 0  FAILURE
	*/
	INT32 GetTaxRateInfo_API(CYWXML_GY &ywxml_gy, CTax *pTax, UINT8 &taxNum, string &strErr);
	
	/*!
	@brief ��˰�̿�����
	@param[in] 
	@param[out] strErr   ������Ϣ
	@return  1 SUCCESS�� 0  FAILURE
	*/
	INT32 SKPKLBG_API(CYWXML_GY &ywxml_gy, string ykl, string xkl, string &strErr);
	

	/*!
	@brief ���֤�����
	@param[in] 
	@param[out] strErr   ������Ϣ
	@return  1 SUCCESS�� 0  FAILURE
	*/
	INT32 BGZSKL_API(CYWXML_GY &ywxml_gy, string ykl, string xkl, string &strErr);

	
	/*!
	@brief ����������Ϣ		
	@param[in] 
	@param[out] strErr   ������Ϣ
	@return  1 SUCCESS�� 0  FAILURE
	*/
	INT32 LXXXUpdatePro_API(CYWXML_GY &ywxml_gy, string &strErr);
	

	/*!
	@brief �������ά��
	@param[in] 
	@param[out] strErr   ������Ϣ
	@return  1 SUCCESS�� 0  FAILURE
	*/
 	INT32 NetParaManage_API(CNetPara *pNetPara, string &strErr);

	
	/*!
	@brief ��˰�̷�Ʊ��ѯ����Ʊ����Ϣ��ѯ��
	@param[in] 
	@param[out] strErr   ������Ϣ
	@return  1 SUCCESS�� 0  FAILURE
	*/
	INT32 BSPFPCXPro_API(CYWXML_GY &ywxml_gy, UINT32 &InvCount, CInvVol *pInvVol, string &strErr);
	
	/*!
	@brief ��Ʊ�ַ���������
	@param[in] 
	@param[out] strErr   ������Ϣ
	@return  1 SUCCESS�� 0  FAILURE
	*/
	INT32 ZJInvDistribute_API(CYWXML_GY &ywxml_gy, CInvVol *pInvVol, UINT8 strJzlx, string &strErr);
	
	/*!
	@brief ��Ʊ�ջأ�������
	@param[in] 
	@param[out] strErr   ������Ϣ
	@return  1 SUCCESS�� 0  FAILURE
	*/
	INT32 ZJInvRecover_API(CYWXML_GY &ywxml_gy, CInvVol *pInvVol, UINT8 strJzlx, string &strErr);
	
	/*!
	@brief ��Ʊ�˻أ��ֻ���
	@param[in] 
	@param[out] strErr   ������Ϣ
	@return  1 SUCCESS�� 0  FAILURE
	*/
	INT32 FJInvReturn_API(CYWXML_GY &ywxml_gy, UINT8 strJzlx, string &strErr);
	
	/*!
	@brief ͳ����Ϣ��ѯ
	@param[in] 
	@param[out] strErr   ������Ϣ
	@return  1 SUCCESS�� 0  FAILURE
	*/
	INT32 TJXXCXPro_API(CYWXML_GY &ywxml_gy, CDataTjxxhz *pTjxxhz, string &strErr);

	/*!
	@brief ���ʹ�Ʊ(��Ʊ����)
	@param[in] 
	@param[out] strErr   ������Ϣ
	@return  1 SUCCESS�� 0  FAILURE
	*/
	INT32 InvReadIn_API(CYWXML_GY &ywxml_gy, UINT8 strJzlx, string &strErr);
	
	/*!
	@brief ������ȡ��Ʊ��������
	@param[in] 
	@param[out] strErr   ������Ϣ
	@return  1 SUCCESS�� 0  FAILURE
	*/
	INT32 WLLQFPPro_API(CYWXML_GY &ywxml_gy, CInvVol *pInvVol, string &strErr);
	
	/*!
	@brief ������ȡ��Ʊ���ȷ�ϣ�������
	@param[in] 
	@param[out] strErr   ������Ϣ
	@return  1 SUCCESS�� 0  FAILURE
	*/
	INT32 WLLQFPJGQRPro_API(CYWXML_GY &ywxml_gy, CInvVol *pInvVol, string &strErr);
	
	/*!
	@brief ��Ʊ��Ϣ��ѯ����ȡ��ǰƱ�ţ�
	@param[in] 
	@param[out] pInvVol  ��Ʊ��Ϣ��
	@param[out] strErr   ������Ϣ
	@return  1 SUCCESS�� 0  FAILURE
	*/
	INT32 GetCurInvInfo_API(CYWXML_GY &ywxml_gy, CInvVol *pInvVol, string &strErr);
	
	/*!
	@brief ��Ʊ���ߣ�������Ʊ����Ʊ��		
	@param[in] invhead			��Ʊͷ��Ϣ
	@param[out] taxCode   	˰���루20�ֽڣ�
	@param[out] strErr   		������Ϣ
	@return  1 SUCCESS�� 0  FAILURE
	*/
	INT32 MakeNormalInv_API(CYWXML_GY &ywxml_gy, CInvHead *pInvHead, string &strErr);
	
	/*!
	@brief ��Ʊ���ϣ��հ׷�Ʊ���ѿ�Ʊ���ϣ�
	@param[in] invhead	��Ʊͷ��Ϣ
	@param[in] zflx   ��������	0���հ׷�Ʊ����	1���ѿ���Ʊ����
	@param[out] strErr   		������Ϣ
	@return  1 SUCCESS�� 0  FAILURE
	*/
	INT32 MakeWasteInv_API(CYWXML_GY &ywxml_gy, CInvHead *pInvHead, UINT8 zflx, string &strErr);
	
	/*!
	@brief ��Ʊ��ѯ
	@param[in] cxfs	��ѯ��ʽ
	@param[in] cxtj	��ѯ����
	@param[out] invNum  ��Ʊ����
	@param[in/out] invhead	��Ʊͷ��Ϣ
	@param[out] strErr   		������Ϣ
	@return  1 SUCCESS�� 0  FAILURE
	*/
	INT32 GetInvHeadInfo_API(CYWXML_GY &ywxml_gy, UINT8 cxfs, string cxtj, UINT32 &invNum, CInvHead *pInvhead, string &strErr);
	
	/*!
	@brief ��Ʊʵʱ�ϴ�
	@param[out] strErr   		������Ϣ
	@return  1 SUCCESS�� 0  FAILURE
	*/
	INT32 InvoiceUpload_API(CYWXML_GY &ywxml_gy, string &strErr);
	
	/*!
	@brief ���糭��
	@param[in] 
	@param[out] strErr   ������Ϣ
	@return  1 SUCCESS�� 0  FAILURE
	*/
	INT32 NetDeclareProc_API(CYWXML_GY &ywxml_gy, string &strErr);
	
	/*!
	@brief ���ʳ���������ʱ��ʾѡ���˰�̻��߱�˰�̣�
	@param[in] jzlx �������� 2����˰�� 1����˰�� 
	@param[out] strErr   ������Ϣ
	@return  1 SUCCESS�� 0  FAILURE
	*/
	INT32 DeclareProc_API(CYWXML_GY &ywxml_gy, UINT8 jzlx, string &strErr);
	
	/*!
	@brief �����忨
	@param[in] 
	@param[out] strErr   ������Ϣ
	@return  1 SUCCESS�� 0  FAILURE
	*/
	INT32 NetUpdateTaxProc_API(CYWXML_GY &ywxml_gy, string &strErr);
	
	/*!
	@brief ��˰���忨
	@param[in] 
	@param[out] strErr   ������Ϣ
	@return  1 SUCCESS�� 0  FAILURE
	*/
	INT32 UpdateTaxProc_API(CYWXML_GY &ywxml_gy, string &strErr);

	/*!
	@brief  ��Ʊ��¼
	@param[in] ywxml_gy	��������
	@param[in] bsqsrq	��˰��ʼ����
	@param[in] bszhrq	��˰��ֹ����
	@param[out] strErr	������Ϣ
	*/
	INT32 Fpbl_API(CYWXML_GY &ywxml_gy, UINT32 bsqsrq, UINT32 bszzrq, string &strErr);

	/*!
	@brief  ��ȡ�����������
	@param[out] wscfpzs		δ�ϴ���Ʊ����
	@param[out] wscfpsj		δ�ϴ���Ʊʱ��
	@param[out] wscfpljje	δ�ϴ���Ʊ�ۼƽ��
	@param[out] sczs		�ϴ�����
	@param[out] scsjjg		�ϴ�ʱ����
	@param[out] strErr		������Ϣ
	*/
	INT32 Hqlxsj_API(CYWXML_GY &ywxml_gy, string &wscfpzs, string &wscfpsj, string &wscfpljje, string &sczs, string &scsjjg, string &strErr);

	/*!
	@brief ת�������
	@param[in] 
	@param[out] strErr   ������Ϣ
	@return  1 SUCCESS�� 0  FAILURE
	*/
	INT32 LibClearDepot(string &strErr);

	/*!
	@brief  ��ȡ�ϴ�������Ʊ��Ϣ
	@param[in] ywxml_gy
	@param[out] ErrInvNum		�����ķ�Ʊ����
	@param[out] pInvUpFailInfo	�����ķ�Ʊ��Ϣ
	@param[out] strErr			������Ϣ
	*/
    INT32 InvUpFailInfo_API(CYWXML_GY &ywxml_gy, CDataInvServ *pDataInvServ, UINT32 &nCount, string &strErr);

	/*!
	@brief �������Ӳ���
	@param[in] ywxml_gy
	@param[out] strErr   ������Ϣ
	@return  1 SUCCESS�� 0  FAILURE
	*/
	//INT32 ServerTest_API(CYWXML_GY &ywxml_gy, string &strErr);
};

#endif
#endif


