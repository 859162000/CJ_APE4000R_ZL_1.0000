/*! \file    InvManageMainMenu.h
   \brief    awe4000r发票管理的主菜单
   \author   Yu Yan 
   \version  1.0
   \date     2008-01-31
 */

#ifndef INVMANAGE_MENU_H
#define INVMANAGE_MENU_H

//#include "InvManageFunc.h"
#include "CMainFrame.h"
#include "MultiBtnCommonWin.h"
#include "CaLabel.h"
#include "CaButton.h"
#include"pos_debug.h"
#include "g_def.h"
#include <string>
using namespace std;

#define	INV_DIST_QUERY_L1	1	//库存查询界面
#define	INV_WLLQFP_L1		2	//网络领取发票界面
#define	INV_RET_QUERY_L1	3	//红票开具查询界面
#define	INV_BLK_WASTE_L1	4	//空白发票作废界面
#define	INV_USEWST_QUERY_L1	5	//已开发票作废查询界面
#define	INV_STUB_QUERY_L1	6	//发票存根查询界面
#define	INV_DETAIL_NO_L1	7	//根据号码段查询发票明细界面
#define	INV_DISTRIBUTE_L1	8	//发票分发界面(主机向分机分发)
#define	INV_RETREAT_L1		9	//发票退回界面(分机将发票由票源区退回报税区)

#define	INV_WASTE_BTN_L0	1	//发票作废主界面
#define	INV_DETAIL_BTN_L0	2	//发票明细查询主界面

/**
 *@class CInvManageMenu 
 *@brief 发票管理的主菜单
 */
class CInvManageMenu : public CMultiBtnCommonWin
{
public:
	UINT8 m_InvWin_level1;//发票管理界面第一级选择标志
	UINT8 m_InvWin_level0;//发票管理界面第零级选择标志,针对generalMtlBtn界面设计
public:
	/*!
	@brief 构造函数
	*/
	CInvManageMenu();

	/*!
	@brief 虚构函数
	*/
	~CInvManageMenu();

	/*!
	@brief 创建窗体	
	@param iX 左上角横坐标
	@param iY 左上角纵坐标
	@param iW 宽度
	@param iH 高度
	@return 1 ：成功；其它：失败
	*/
	int Create(int iX,int iY,int iW,int iH);

	/*!
	@brief 处理事件	
	@param[in] iEvent 事件编号
	@param[in] pEventData 事件内容
	@param[in] iDataLen 事件内容长度
	@return   1  已处理； 0 无法处理
	*/
	int ProcEvent(int iEvent,unsigned char *pEventData, int iDataLen);

	/*!
	@brief 进纸	
	@return  1: SUCCESS; 0: FAILURE
	*/
	UINT8 ForwardKeyProc();

private:

	/*!
	@brief 按钮1响应函数	
	@param[in] iEvent 事件编号
	@param[in] pEventData 事件内容
	@param[in] iDataLen 事件内容长度
	*/
	void OnButton1(int iEvent, unsigned char * pEventData, int iDataLen);

	/*!
	@brief 按钮2响应函数	
	@param[in] iEvent 事件编号
	@param[in] pEventData 事件内容
	@param[in] iDataLen 事件内容长度
	*/
	void OnButton2(int iEvent, unsigned char * pEventData, int iDataLen);

	/*!
	@brief 按钮3响应函数	
	@param[in] iEvent 事件编号
	@param[in] pEventData 事件内容
	@param[in] iDataLen 事件内容长度
	*/
	void OnButton3(int iEvent, unsigned char * pEventData, int iDataLen);

	/*!
	@brief 按钮4响应函数	
	@param[in] iEvent 事件编号
	@param[in] pEventData 事件内容
	@param[in] iDataLen 事件内容长度
	*/
	void OnButton4(int iEvent, unsigned char * pEventData, int iDataLen);
	
	/*!
	@brief 按钮5响应函数	
	@param[in] iEvent 事件编号
	@param[in] pEventData 事件内容
	@param[in] iDataLen 事件内容长度
	*/
	void OnButton5(int iEvent, unsigned char * pEventData, int iDataLen); 

	/*!
	@brief 按钮6响应函数	
	@param[in] iEvent 事件编号
	@param[in] pEventData 事件内容
	@param[in] iDataLen 事件内容长度
	*/
	void OnButton6(int iEvent, unsigned char * pEventData, int iDataLen);

	/*!
	@brief 按钮7响应函数	
	@param[in] iEvent 事件编号
	@param[in] pEventData 事件内容
	@param[in] iDataLen 事件内容长度
	*/
	void OnButton7(int iEvent, unsigned char * pEventData, int iDataLen);

		/*!
	@brief 按钮6响应函数	
	@param[in] iEvent 事件编号
	@param[in] pEventData 事件内容
	@param[in] iDataLen 事件内容长度
	*/
	void OnButton8(int iEvent, unsigned char * pEventData, int iDataLen);

			/*!
	@brief 按钮6响应函数	
	@param[in] iEvent 事件编号
	@param[in] pEventData 事件内容
	@param[in] iDataLen 事件内容长度
	*/
//	void OnButton9(int iEvent, unsigned char * pEventData, int iDataLen);

	/*!
	@brief 按钮6响应函数	
	@param[in] iEvent 事件编号
	@param[in] pEventData 事件内容
	@param[in] iDataLen 事件内容长度
	*/
// 	void OnButton10(int iEvent, unsigned char * pEventData, int iDataLen);



};


#endif
