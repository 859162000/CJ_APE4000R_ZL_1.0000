
/*! \file    GeneralInvMtlBtnWin.h
   \brief    awe4000r发票管理档的多按钮公用界面
   \author   Yu Yan
   \version  1.0
   \date     2008-2-22
 */

#ifndef _GENERAL_INV_MTLBTN_WIN_H
#define _GENERAL_INV_MTLBTN_WIN_H

#include "CMainFrame.h"
#include "MultiBtnCommonWin.h"
// #include "CaLabel.h"
// #include "CaButton.h"
#include"pos_debug.h"
#include "g_def.h"
#include <string>
using namespace std;

/**
 *@class CGInvMtlbtnWin 
 *@brief 发票作废的主菜单
 */
class CGInvMtlbtnWin : public CMultiBtnCommonWin
{
public:

	UINT8 m_level0;				//发票管理界面第零级选择标志在公用MtlBtn界面的对应变量

	/*!
	@brief 构造函数
	*/
	CGInvMtlbtnWin();

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
	@brief 更新显示内容的静态函数	 
	*/
	static void S_OnActive(CaWindow *obj);
    
	/*!
	@brief 更新显示内容的函数	 
	*/
	void DoActive(); 

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

};


#endif
