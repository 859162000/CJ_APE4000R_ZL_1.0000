/*! \file    GeneralInvMtlBtnWin.cpp
   \brief    awe4000r发票管理档的多按钮公用界面
   \author   Yu Yan
   \version  1.0
   \date     2008-2-22
 */
#include "GeneralInvMtlBtnWin.h"
#include "InvManageMainMenu.h"
#include "CaMsgBox.h"
//#include "CaProgressBar.h"
//#include "CGlobalArg.h"

CGInvMtlbtnWin::CGInvMtlbtnWin():CMultiBtnCommonWin(2)
{
	m_level0 = 0;
}

int CGInvMtlbtnWin::Create(int iX,int iY,int iW,int iH)
{
	m_pFrame->RegsiterWin(this,GENERAL_INV_MTLBTN_WIN);    
    
	CMultiBtnCommonWin::Adjustm_iH(1);
	CMultiBtnCommonWin::Create(iX, iY, iW, iH);
	
	SetTitle(1,"");
	SetTitle(2,"");

	OnActive = S_OnActive;
	this->End();
	return 1;
}

void CGInvMtlbtnWin::S_OnActive(CaWindow *obj)
{
	((CGInvMtlbtnWin *)obj)->DoActive();
}

void CGInvMtlbtnWin::DoActive()
{
	DBG_PRINT(("进入CGInvMtlbtnWin::DoActive函数"));

	m_level0 = ((CInvManageMenu*)m_pFrame->GetWin(INV_MANAGE_MENU))->m_InvWin_level0;
	DBG_PRINT(("m_level0 = %u",m_level0));

	if (INV_WASTE_BTN_L0 == m_level0)
	{
		SetTitle(1,"A.空白票作废");
		SetTitle(2,"B.已开票作废");
	}
	/*
	else if (INV_DETAIL_BTN_L0 == m_level0)
	{
		SetTitle(1,"A.号码段查询");
		SetTitle(2,"B.时间段查询");
	}
	*/
	DBG_PRINT(("退出CGInvMtlbtnWin::DoActive函数"));
}
//------------------------------------------------------------------------------------
//函数名称：空白票作废
//函数功能：
//函数作者：
//------------------------------------------------------------------------------------
void CGInvMtlbtnWin::OnButton1(int iEvent, unsigned char * pEventData, int iDataLen)
{

	if (INV_WASTE_BTN_L0 == m_level0)
	{
		((CInvManageMenu*)m_pFrame->GetWin(INV_MANAGE_MENU))->m_InvWin_level1 = INV_BLK_WASTE_L1;
		ChangeWin(GENERAL_INV_LABEL_WIN);//切换到空白发票作废界面
	}
	/*
	else if (INV_DETAIL_BTN_L0 == m_level0)
	{
		((CInvManageMenu*)m_pFrame->GetWin(INV_MANAGE_MENU))->m_InvWin_level1 = INV_DETAIL_NO_L1;
		ChangeWin(GENERAL_INV_INPUT_WIN);//切换到按号码段查询发票明细界面
	}
	*/
	return;
}

//------------------------------------------------------------------------------------
//函数名称：已开票作废
//函数功能：
//函数作者：
//------------------------------------------------------------------------------------
void CGInvMtlbtnWin::OnButton2(int iEvent, unsigned char * pEventData, int iDataLen)
{
	if (INV_WASTE_BTN_L0 == m_level0)
	{
		((CInvManageMenu*)m_pFrame->GetWin(INV_MANAGE_MENU))->m_InvWin_level1 = INV_USEWST_QUERY_L1;
		ChangeWin(GENERAL_INV_INPUT_WIN);//切换到已开发票作废查询界面
	}
	/*
	else if (INV_DETAIL_BTN_L0 == m_level0)
	{
		CaMsgBox::ShowMsg("暂不支持此功能");
	}
	*/
	return;
}


int CGInvMtlbtnWin::ProcEvent(int iEvent,unsigned char *pEventData, int iDataLen)
{
	switch(iEvent) 
	{
		case RETURN_MAIN_MENU:
			ChangeWin(INV_MANAGE_MENU);
			return SUCCESS;
			break;

		default: 
			break;
	}
	return CMultiBtnCommonWin::ProcEvent(iEvent,pEventData,iDataLen);
}

