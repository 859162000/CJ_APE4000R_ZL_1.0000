/*! \file    CommerceReportMenu.h
   \brief    awe4000r报表打印的商业统计菜单
   \author   Yu Yan
   \version  1.0
   \date     2008-4-1
 */


#ifndef COMMERCE_REPORT_MENU_H
#define COMMERCE_REPORT_MENU_H
#include "MultiBtnCommonWin.h"
//#include "LOGCTRL.h"
// #include "pos_debug.h"
#include "g_def.h"
#include "CaLabel.h"
#include "CMainFrame.h"
#include "CaButton.h"
#include <string>

using namespace std;

/**
 *@class CCommerceReportMenu 
 *@brief 报表打印的基本信息菜单
 */
class CCommerceReportMenu : public CMultiBtnCommonWin
{
public:

	/*!
	@brief 构造函数	
	*/
	CCommerceReportMenu();

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

private:

	/*!
	@brief 按钮响应函数	
	@param[in] iEvent 事件编号
	@param[in] pEventData 事件内容
	@param[in] iDataLen 事件内容长度
	*/
	void OnButton1(int iEvent, unsigned char * pEventData, int iDataLen);

	/*!
	@brief 按钮响应函数	
	@param[in] iEvent 事件编号
	@param[in] pEventData 事件内容
	@param[in] iDataLen 事件内容长度
	*/
	void OnButton2(int iEvent, unsigned char * pEventData, int iDataLen);

	/*!
	@brief 按钮响应函数	
	@param[in] iEvent 事件编号
	@param[in] pEventData 事件内容
	@param[in] iDataLen 事件内容长度
	*/
	void OnButton3(int iEvent, unsigned char * pEventData, int iDataLen);
	
	/*!
	@brief 按钮响应函数	
	@param[in] iEvent 事件编号
	@param[in] pEventData 事件内容
	@param[in] iDataLen 事件内容长度
	*/
// 	void OnButton4(int iEvent, unsigned char * pEventData, int iDataLen);
	
	/*!
	@brief 按钮响应函数	
	@param[in] iEvent 事件编号
	@param[in] pEventData 事件内容
	@param[in] iDataLen 事件内容长度
	*/
// 	void OnButton5(int iEvent, unsigned char * pEventData, int iDataLen);
	
	/*!
	@brief 按钮响应函数	
	@param[in] iEvent 事件编号
	@param[in] pEventData 事件内容
	@param[in] iDataLen 事件内容长度
	*/
// 	void OnButton6(int iEvent, unsigned char * pEventData, int iDataLen);

	/*!
	@brief 按钮响应函数	
	@param[in] iEvent 事件编号
	@param[in] pEventData 事件内容
	@param[in] iDataLen 事件内容长度
	*/
//	void OnButton7(int iEvent, unsigned char * pEventData, int iDataLen);

	/*!
	@brief 按钮响应函数	
	@param[in] iEvent 事件编号
	@param[in] pEventData 事件内容
	@param[in] iDataLen 事件内容长度
	*/
//	void OnButton8(int iEvent, unsigned char * pEventData, int iDataLen);

	/*!
	@brief 按钮响应函数	
	@param[in] iEvent 事件编号
	@param[in] pEventData 事件内容
	@param[in] iDataLen 事件内容长度
	*/
//	void OnButton9(int iEvent, unsigned char * pEventData, int iDataLen);

public:

	/*!
	@brief 打印全部客户信息
	@return  1: SUCCESS; 0: FAILURE
	*/
	UINT8 PrnClient();

	/*!
	@brief 打印全部部类信息
	@return  1: SUCCESS; 0: FAILURE
	*/
	UINT8 PrnDept();

	/*!
	@brief 打印全部操作员信息
	@return  1: SUCCESS; 0: FAILURE
	*/
	UINT8 PrnOperator();

};

#endif