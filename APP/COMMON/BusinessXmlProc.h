/****************************************************************************
文件名           ：BusinessBase.h
功能             ：awe4000r业务流程抽血类
起始日期         ：
作者             ： 
****************************************************************************/

#ifndef BUSINESS_XML_PROC_H
#define BUSINESS_XML_PROC_H

#include "BusinessBase.h"

#if BUSINESS_TYPE_MODE == BUSINESS_XML_MODE

class CBusinessXmlProc : public CBusinessBase
{
public:

	CBusinessXmlProc();
	~CBusinessXmlProc();

	//税控设备编号查询
	INT32 SKSBBH_Business(CYWXML_GY &ywxml_gy, string &sksbbh, string &bspbh, string &qtxx, string &strErr);
	
	//报税盘编号查询
//	INT32 BSPBH_Business(CYWXML_GY &ywxml_gy, string &bspbh, string &strErr);
	
	//税控设备信息查询
	INT32 SKPXXCX_Business(CYWXML_GY &ywxml_gy, CDataUserInfo *pUserInfo, string &strCurTime, string &strErr);
	
	//税控设备其他信息查询
	INT32 SKSBQTYXXCX_Business(CYWXML_GY &ywxml_gy, UINT8 xxlx, string &sksbxx, string &strErr);
	
	//报税盘信息查询
	INT32 BSPXXCX_Business(CYWXML_GY &ywxml_gy, CDataUserInfo *pUserInfo, string &strErr);
	
	//监控数据查询
	INT32 JKSJCX_Business(CYWXML_GY &ywxml_gy, CDataInvKind *pInvKind, string &strErr);
	
	//授权税率查询
	INT32 SQSLCX_Business(CYWXML_GY &ywxml_gy, CDataTax *pTax, UINT8 &taxNum, string &strErr);
	
	//购票信息查询
	INT32 GPXXCX_Business(CYWXML_GY &ywxml_gy, CDataInvVol *pInvVol, string &strErr);
	
	//购票信息写盘
	INT32 GPXXXP_Business(CYWXML_GY &ywxml_gy, string gpxxmw, string &strErr);
	
	//购票信息写盘解锁
	INT32 GPXXXPJS_Business(CYWXML_GY &ywxml_gy, string wslpjsxx, string &strErr);
	
	//口令变更
	INT32 KLBG_Business(CYWXML_GY &ywxml_gy, string oldPwd, string newPwd, string &strErr);
	
	//发票开具
	INT32 FPKJ_Business(CYWXML_GY &ywxml_gy, CDataInvHead *pInvhead, string &strErr);
	
	//发票作废
	INT32 FPZF_Business(CYWXML_GY &ywxml_gy, CDataInvHead *pInvhead, UINT8 zflx, string &strErr);
	
	//发票查询
	INT32 FPCX_Business(CYWXML_GY &ywxml_gy, UINT8 cxfs, string cxtj, UINT32 &invNum, CDataInvHead *pInvhead, string &strErr);
	
	//税控设备报税盘组合操作
	INT32 SKPBSP_Business(CYWXML_GY &ywxml_gy, UINT8 czlx, string qtxx,string &strErr);
	
	//发票段信息查询(报税盘发票查询)
	INT32 BSPFPCX_Business(CYWXML_GY &ywxml_gy, UINT32 &invNum, CDataInvVol *pInvVol, string &strErr);
	
	//发票分发
	INT32 BSPFPFF_Business(CYWXML_GY &ywxml_gy, UINT8 jzlx, CDataInvVol *pInvVol, string &strErr);
	
	//发票收回
	INT32 BSPFPSH_Business(CYWXML_GY &ywxml_gy, UINT8 jzlx, CDataInvVol *pInvVol, string &strErr);
	
	//数据抄报
	INT32 SJCB_Business(CYWXML_GY &ywxml_gy, UINT8 jzlx, string &strSQ, string &strFphz, string &strErr);
	
	//监控回传
	INT32 JKHC_Business(CYWXML_GY &ywxml_gy, string strFpjkmw, string &strErr);
	
	//发票统计信息查询
	INT32 TJXXCX_Business(CYWXML_GY &ywxml_gy, INT32 &monthcount, CDataTjxxhz *pTjxxhz, string &strErr);
	
	//离线信息写盘
	INT32 LXXXXP_Business(CYWXML_GY &ywxml_gy, string lxxxmw, string &strErr);
	
	//发票实时上传
	INT32 FPSC_Business(CYWXML_GY &ywxml_gy, UINT8 czlx, UINT32 &fpzx, string &strInvInfo, string &strErr);
	
	//发票更新
	INT32 FPGX_Business(CYWXML_GY &ywxml_gy, string scqrbw, string &strErr);
	
	//发票读入
	INT32 FPDR_Business(CYWXML_GY &ywxml_gy, UINT8 jzlx, string &strErr);
	
	//分机退回
	INT32 FJTH_Business(CYWXML_GY &ywxml_gy, UINT8 jzlx, string &strErr);
	
	//变更证书口令
	INT32 BGZSKL_Business(CYWXML_GY &ywxml_gy, string oldPwd, string newPwd, string &strErr);

	//3.1发票上传
	INT32 NETFPSC_Business(CYWXML_GY &ywxml_gy, const string &Fpmx, UINT32 Fpzs, string &Slxlh, string &strErr);
	
	//3.2发票上传结果获取
	INT32 FPSCJGHQ_Business(CYWXML_GY &ywxml_gy, string qtxx, string &Mxjgmw, string &strErr);
	
	//3.3网络抄报
	INT32 WLCB_Business(CYWXML_GY &ywxml_gy, string Sq, string Fphzsj, string Qtxx, string &strErr);
	
	//3.4清零解锁
	INT32 QLJS_Business(CYWXML_GY &ywxml_gy, string Qtxx,string &Fpjkmw, string &strErr);
	
	//3.5清零解锁结果确认
	INT32 QLJSJGQR_Business(CYWXML_GY &ywxml_gy, string Qtxx, string &strErr);
	
	//3.6离线信息上传
	INT32 NETLXXXSC_Business(CYWXML_GY &ywxml_gy, CDataInvKind *invkind, string strQtxx, string &strLzkzxx, string &strErr);
	
	//3.7网络领取发票
	INT32 WLLQFP_Business(CYWXML_GY &ywxml_gy, CDataInvVol *pInvvol, string strQtxx, string &strErr);
	
	//3.8网络领取发票结果确认
	INT32 WLLQFPJGQR_Business(CYWXML_GY &ywxml_gy, CDataInvVol *pInvvol, string strQtxx, string &strErr);
	
	//发票补录
	INT32 FPBL_Business(CYWXML_GY &ywxml_gy, UINT32 SDate, UINT32 EDate, string &strErr);
	
public:
	//更新未上传发票信息
	INT32 UpdateUploadInv(CYWXML_GY &ywxml_gy);

	//安全通道连接测试
	INT32 SSLConnectTest(CYWXML_GY &ywxml_gy, string &strErr);

	//获取离线相关数据
	INT32 OffInvInfo_Business(CYWXML_GY &ywxml_gy, UINT32 &wscfpzs, string &wscfpsj, INT64 &wscfpljje, string &strErr);

	//2.29.获取上传出错发票信息
	INT32 GetErrUpInvInfo(CYWXML_GY &ywxml_gy, CDataInvServ *pDataInvServ, UINT32 &nCount, string &strErr);	
};

#endif
#endif


