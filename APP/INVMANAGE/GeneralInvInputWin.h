/*! \file    GeneralInvInputWin.h
   \brief    awe4000r发票管理档的输入公用界面
   \author   xsr
   \version  1.0
   \date     2008-2-22
 */
#ifndef _GENERAL_INV_INPUT_WIN_H
#define _GENERAL_INV_INPUT_WIN_H

#include "CaWindow.h"
#include "pos_debug.h"
#include "g_def.h"
#include "CaLabel.h"
#include "CaInput.h"
#include "CaButton.h"
#include "CInvHead.h"

#define	INV_RETURN_L2	1	//红票开具
#define	INV_USEWST_L2	2	//已开发票作废
#define	INV_StubPrn_L2	3	//发票存根打印

/**
 *@class CGInvInputWin 
 *@brief 输入公用界面
 */
class CGInvInputWin : public CaWindow
{
public:
	char title_array[4][OBJ_TITLE_MAX_LEN + 1];	/**< 标签的标题*/

	CaLabel *label;					/**< 指向标签的指针 */
	CaInput *m_pInput1;				/**< 指向输入栏的指针 */  
	CaInput *m_pInput2;				/**< 指向输入栏的指针 */
	CaInput *m_pInput3;				/**< 指向输入栏的指针 */  
	CaButton *m_pBtn1;				/**< 指向按钮的指针 */
	CaButton *m_pBtn2;				/**< 指向按钮的指针 */
	
	int m_iBtnW;					/**< 两列时，控件的宽度 */  
	int m_iColW;					/**< 两列时，第二列的横坐标 */  
 
	string m_invCode;               /**< 发票代码 */ 
	UINT32 m_invStartNo;			/**< 发票起始号码 */ 
	UINT32 m_invEndNo;				/**< 发票截止号码 */ 
	UINT32 m_invNum;				/**< 发票张数 */ 
	UINT8  m_nFlag;                 /**< 0:发票查询；1:发票补传,按号码段查询发票明细专用*/

	CInvHead *m_pInvHead, m_Invhead;             /**< 查询发票信息*/

	UINT8 m_level1;					//发票管理界面第一级选择标志在公用Input界面的对应变量
	UINT8 m_InvWin_level2;			//发票管理界面第二级选择标志


public:


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
	@brief 刷新窗口显示	
	@return 1: SUCCESS
	*/
	virtual int ReFresh();

	/*!
	@brief 构造函数	
	*/
	CGInvInputWin();

	/*!
	@brief 输入栏响应函数	
	@param[in] iEvent 事件编号
	@param[in] pEventData 事件内容
	@param[in] iDataLen 事件内容长度
	*/
	void OnInput1(int iEvent, unsigned char * pEventData, int iDataLen);

	/*!
	@brief 输入栏响应函数	
	@param[in] iEvent 事件编号
	@param[in] pEventData 事件内容
	@param[in] iDataLen 事件内容长度
	*/
	void OnInput2(int iEvent, unsigned char * pEventData, int iDataLen);

	/*!
	@brief 输入栏响应函数	
	@param[in] iEvent 事件编号
	@param[in] pEventData 事件内容
	@param[in] iDataLen 事件内容长度
	*/
	void OnInput3(int iEvent, unsigned char * pEventData, int iDataLen);

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
	@brief 更新显示内容的静态函数	 
	*/
	static void S_OnActive(CaWindow *obj);
    
	/*!
	@brief 更新显示内容的函数	 
	*/
	void DoActive(); 

	/*!
	@brief 改变Label 和 Input所关联的title值	
	@return  1: SUCCESS; 0: FAILURE
	*/
	UINT8 ChangeTitle();

	/*!
	@brief 网络领取发票初始屏幕显示
	*/
	void InvWllqfpShow();

	/*!
	@brief 红票开具查询初始屏幕显示
	*/
	void InvRetQueryShow();

	/*!
	@brief 已开发票作废查询初始屏幕显示
	*/
	void InvUsewstQueryShow();

	/*!
	@brief 发票存根查询初始屏幕显示
	*/
	void InvStubQueryShow();

	/*!
	@brief 按发票号码查询发票明细初始屏幕显示
	*/
	void InvDetailNoQueryShow();

	/*!
	@brief 发票分发初始屏幕显示
	*/
	void InvDistributeShow();

	/*!
	@brief 发票退回初始屏幕显示
	*/
	void InvRetreatShow();
	
private:

	/*!
	@brief 输入栏响应的静态函数
	@param[in] obj 控件指针
	@param[in] iEvent 事件编号
	@param[in] pEventData 事件内容
	@param[in] iDataLen 事件内容长度
	*/
	static void S_OnInput1(CaObject *obj,int iEvent, unsigned char * pEventData, int iDataLen);
	
	/*!
	@brief 输入栏响应的静态函数
	@param[in] obj 控件指针
	@param[in] iEvent 事件编号
	@param[in] pEventData 事件内容
	@param[in] iDataLen 事件内容长度
	*/
	static void S_OnInput2(CaObject *obj,int iEvent, unsigned char * pEventData, int iDataLen);
	
	/*!
	@brief 输入栏响应的静态函数
	@param[in] obj 控件指针
	@param[in] iEvent 事件编号
	@param[in] pEventData 事件内容
	@param[in] iDataLen 事件内容长度
	*/
	static void S_OnInput3(CaObject *obj,int iEvent, unsigned char * pEventData, int iDataLen);

	/*!
	@brief 按钮响应的静态函数
	@param[in] obj 控件指针
	@param[in] iEvent 事件编号
	@param[in] pEventData 事件内容
	@param[in] iDataLen 事件内容长度
	*/
	static void S_OnButton1(CaObject *obj,int iEvent, unsigned char * pEventData, int iDataLen);
	
	/*!
	@brief 按钮响应的静态函数
	@param[in] obj 控件指针
	@param[in] iEvent 事件编号
	@param[in] pEventData 事件内容
	@param[in] iDataLen 事件内容长度
	*/
	static void S_OnButton2(CaObject *obj,int iEvent, unsigned char * pEventData, int iDataLen);
   
	/*!
	@brief 检查输入栏接收的值是否有效	
	@return   1  输入有效； 0 输入无效
	*/
	UINT8 CheckInputValid( );

	/*!
	@brief 网络领取发票对应的Buttton1函数	
	@return   1  输入有效； 0 输入无效
	*/
	void InvWllqfpBtn1();

	/*!
	@brief 红票开具查询对应的Buttton1函数	
	@return   1  输入有效； 0 输入无效
	*/
	void InvReturnQueryBtn1();

	/*!
	@brief 已开发票查询对应的Buttton1函数	
	@return   1  输入有效； 0 输入无效
	*/
	void InvUsewstQueryBtn1();

	/*!
	@brief 发票存根查询对应的Buttton1函数	
	@return   1  输入有效； 0 输入无效
	*/
	void InvStubQueryBtn1();

	/*!
	@brief 按发票号码查询发票明细对应的Buttton1函数	
	@return   1  输入有效； 0 输入无效
	*/
	void InvDetailNoQueryBtn1();

	/*!
	@brief 发票分发对应的Buttton1函数	
	@return   1  输入有效； 0 输入无效
	*/
	void InvDistributeBtn1();

	/*!
	@brief 发票退回对应的Buttton1函数	
	@return   1  输入有效； 0 输入无效
	*/
	void InvRetreatBtn1();
};


#endif
