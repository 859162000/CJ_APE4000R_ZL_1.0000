/*! \file    GeneralInvMtlBtnWin.cpp
   \brief    awe4000r��Ʊ�����Ķఴť���ý���
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
	DBG_PRINT(("����CGInvMtlbtnWin::DoActive����"));

	m_level0 = ((CInvManageMenu*)m_pFrame->GetWin(INV_MANAGE_MENU))->m_InvWin_level0;
	DBG_PRINT(("m_level0 = %u",m_level0));

	if (INV_WASTE_BTN_L0 == m_level0)
	{
		SetTitle(1,"A.�հ�Ʊ����");
		SetTitle(2,"B.�ѿ�Ʊ����");
	}
	/*
	else if (INV_DETAIL_BTN_L0 == m_level0)
	{
		SetTitle(1,"A.����β�ѯ");
		SetTitle(2,"B.ʱ��β�ѯ");
	}
	*/
	DBG_PRINT(("�˳�CGInvMtlbtnWin::DoActive����"));
}
//------------------------------------------------------------------------------------
//�������ƣ��հ�Ʊ����
//�������ܣ�
//�������ߣ�
//------------------------------------------------------------------------------------
void CGInvMtlbtnWin::OnButton1(int iEvent, unsigned char * pEventData, int iDataLen)
{

	if (INV_WASTE_BTN_L0 == m_level0)
	{
		((CInvManageMenu*)m_pFrame->GetWin(INV_MANAGE_MENU))->m_InvWin_level1 = INV_BLK_WASTE_L1;
		ChangeWin(GENERAL_INV_LABEL_WIN);//�л����հ׷�Ʊ���Ͻ���
	}
	/*
	else if (INV_DETAIL_BTN_L0 == m_level0)
	{
		((CInvManageMenu*)m_pFrame->GetWin(INV_MANAGE_MENU))->m_InvWin_level1 = INV_DETAIL_NO_L1;
		ChangeWin(GENERAL_INV_INPUT_WIN);//�л���������β�ѯ��Ʊ��ϸ����
	}
	*/
	return;
}

//------------------------------------------------------------------------------------
//�������ƣ��ѿ�Ʊ����
//�������ܣ�
//�������ߣ�
//------------------------------------------------------------------------------------
void CGInvMtlbtnWin::OnButton2(int iEvent, unsigned char * pEventData, int iDataLen)
{
	if (INV_WASTE_BTN_L0 == m_level0)
	{
		((CInvManageMenu*)m_pFrame->GetWin(INV_MANAGE_MENU))->m_InvWin_level1 = INV_USEWST_QUERY_L1;
		ChangeWin(GENERAL_INV_INPUT_WIN);//�л����ѿ���Ʊ���ϲ�ѯ����
	}
	/*
	else if (INV_DETAIL_BTN_L0 == m_level0)
	{
		CaMsgBox::ShowMsg("�ݲ�֧�ִ˹���");
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

