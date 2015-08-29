/*! \file    GeneralInvInputWin.cpp
   \brief    awe4000r��Ʊ���������빫�ý���
   \author   zcy
   \version  1.0
   \date     2014-6-3
 */
#include "GeneralInvInputWin.h"
#include "InvManageMainMenu.h"
#include "InvVolFunc.h" 
#include "CGlobalArg.h"
#include "SaleData.h"
#include "InvManageFunc.h"
#include "SysMacDef.h"

#include "CMainFrame.h"
#include "CaMsgBox.h"
#include "CaProgressBar.h"
#include <string.h>
#include "stdlib.h"

#include "LOGCTRL.h"
//#define NO_POS_DEBUG
#include "pos_debug.h"

CGInvInputWin::CGInvInputWin():CaWindow()
{
	m_invCode ="";
	m_invStartNo = 0;
	m_invEndNo = 0;
	m_invNum = 0;
	m_nFlag=0;
	m_pInvHead = &m_Invhead;
	m_level1 = 0;
	m_InvWin_level2 = 0;
}

int CGInvInputWin::Create(int iX,int iY,int iW,int iH)
{
	char title[OBJ_TITLE_MAX_LEN + 1];
    int titleLen = 0;
	int curH;
	m_pFrame->RegsiterWin(this,GENERAL_INV_INPUT_WIN);    
	CaWindow::Create(iX,iY,iW,iH); // creat a window

	curH = SCREEN_TOP_OFFSET;
	m_iBtnW = (SCREEN_W/2 - 0) ; //�ؼ��Ŀ��
	m_iColW = m_iBtnW + 0;        //�ؼ����п�

	//����һ��Label  ��һ��
	m_pLabel = new CaLabel(false,CaObject::ALIGN_CENTER);
	m_pLabel->Create(0, curH, SCREEN_W, LINE_H);
	m_pLabel->SetTitle(title_array[0], strlen(title_array[0]));

	//����һ��Input  �ڶ���
	strcpy(title, "��Ʊ���룺");
	titleLen = strlen(title) * CHAR_W + 1;
	m_pInput1=new CaInput(CaObject::ON_LEFT,titleLen);
	curH += LINE_H;
	m_pInput1->Create(0,curH,SCREEN_W,LINE_H);
	m_pInput1->SetTitle(title_array[1], strlen(title_array[1]));	
	m_pInput1->SetMaxLen(12);
	m_pInput1->m_InputType = m_pInput1->aINT; //�������ֻ��������ֵ
	m_pInput1->OnObject = S_OnInput1;

	strcpy(title, "��ʼ���룺");
	titleLen = strlen(title) * CHAR_W + 1;
	m_pInput2=new CaInput(CaObject::ON_LEFT,titleLen);
	curH += LINE_H;
	m_pInput2->Create(0,curH,SCREEN_W,LINE_H);
	m_pInput2->SetTitle(title_array[2], strlen(title_array[2]));
	m_pInput2->SetMaxLen(8);
    m_pInput2->OnObject = S_OnInput2;
	m_pInput2->m_InputType = m_pInput2->aINT; //�������ֻ��������ֵ

	strcpy(title, "��Ʊ������");
	titleLen = strlen(title) * CHAR_W + 1;
	m_pInput3=new CaInput(CaObject::ON_LEFT,titleLen);
	curH += LINE_H;
	m_pInput3->Create(0,curH,SCREEN_W,LINE_H);
	m_pInput3->SetTitle(title_array[3], strlen(title_array[3]));
	m_pInput3->SetMaxLen(4);
    m_pInput3->OnObject = S_OnInput3;
	m_pInput3->m_InputType = m_pInput3->aINT; //�������ֻ��������ֵ

	m_iBtnW = (SCREEN_W - 40)/2 - 4; //Button�Ŀ��
 	m_iColW = (SCREEN_W - 40)/2; //Button���п�
	INT32 left_offset = SCREEN_LEFT_OFFSET+8;
	INT32 leftoffset_btn = left_offset + 14;
	
	strcpy(title, "ȷ��");
	m_pBtn1 = new CaButton();
	curH += LINE_H;
	m_pBtn1->Create(leftoffset_btn,curH,m_iBtnW,WORD_H); 
	m_pBtn1->SetTitleAlign(CaObject::ALIGN_CENTER);
	m_pBtn1->SetTitle(title, strlen(title));
	m_pBtn1->BoxType(CaObject::BOX_NO);
	m_pBtn1->OnObject = S_OnButton1;
	
	strcpy(title, "����");
	m_pBtn2 = new CaButton();
	m_pBtn2->Create(leftoffset_btn+m_iColW,curH,m_iBtnW,WORD_H);
	m_pBtn2->SetTitleAlign(CaObject::ALIGN_CENTER);
	m_pBtn2->SetTitle(title, strlen(title));
	m_pBtn2->BoxType(CaObject::BOX_NO);
	m_pBtn2->OnObject = S_OnButton2;	

	OnActive = S_OnActive;
	this->End();
	return 1;
}

void CGInvInputWin::S_OnActive(CaWindow *obj)
{
	((CGInvInputWin *)obj)->DoActive();
}

void CGInvInputWin::DoActive()
{
	DBG_PRINT(("����CGInvInputWin::DoActive����"));

	m_level1 = ((CInvManageMenu*)m_pFrame->GetWin(INV_MANAGE_MENU))->m_InvWin_level1;
	DBG_PRINT(("m_level1 = %u",m_level1));

	m_pInput1->Clear();
	m_pInput2->Clear();
	m_pInput3->Clear();

	DBG_PRINT(("m_code = %s",g_globalArg->m_curInvVol->m_code.c_str()));
	DBG_PRINT(("m_nFlag= %u",m_nFlag));
	string strErr("");
	UINT8 ret=SUCCESS;
	if (0 == g_globalArg->m_curInvVol->m_curInvNo) //���ⷴ������
	{
		ret = SALE_GetCurInv(g_globalArg->m_curInvVol,strErr);
		if (ret ==FAILURE)
		{
			g_globalArg->m_curInvVol->m_curInvNo = 0;
			strErr = "";
		}
	}

	switch ( m_level1 )
	{
		case INV_WLLQFP_L1:
			{
				InvWllqfpShow();//������ȡ��Ʊ��Ļ��ʾ
				break;
			}
		case INV_RET_QUERY_L1:
			{
				InvRetQueryShow();//��Ʊ���߲�ѯ��Ļ��ʾ
				break;
			}
		case INV_USEWST_QUERY_L1:
			{
				InvUsewstQueryShow();//�ѿ���Ʊ���ϲ�ѯ��Ļ��ʾ
				break;
			}
		case INV_STUB_QUERY_L1:
			{
				InvStubQueryShow();//��Ʊ�����ѯ��Ļ��ʾ
				break;
			}
		case INV_DETAIL_NO_L1:
			{
				InvDetailNoQueryShow();//����Ʊ�����ѯ��Ʊ��ϸ��Ļ��ʾ
				break;
			}
		case INV_DISTRIBUTE_L1:
			{
				InvDistributeShow();//��Ʊ�ַ���Ļ��ʾ
				break;
			}
		case INV_RETREAT_L1:
			{
				InvRetreatShow();//��Ʊ�˻���Ļ��ʾ
				break;
			}
		default:
			break;
	}
	ChangeTitle();
	
	ReFresh();
	DBG_PRINT(("�˳�CGInvInputWin::DoActive����"));
}

void CGInvInputWin::InvWllqfpShow()
{
	sprintf(title_array[0], "������ȡ��Ʊ");
	sprintf(title_array[1], "��Ʊ���룺");
	sprintf(title_array[2], "��ʼ���룺");
	sprintf(title_array[3], "��Ʊ������");
	m_pLabel->SetTitleAlign(CaObject::ALIGN_CENTER);
	m_pInput1->SetMaxLen(12);
	m_pInput2->SetMaxLen(8);
	m_pInput3->SetMaxLen(4);
	m_pInput3->Visible(true); //�ɼ�

	m_pInput1->SetContentBuf((UINT8*)g_globalArg->m_curInvVol->m_code.c_str(), g_globalArg->m_curInvVol->m_code.length());
	return;
}

void CGInvInputWin::InvRetQueryShow()
{
	string strErr("");
	UINT8 ret=SUCCESS;
	UINT8 uFlag = 0;
	if (0 == g_globalArg->m_curInvVol->m_curInvNo) //���ⷴ������
	{
		ret = SALE_GetCurInv(g_globalArg->m_curInvVol,strErr);
		if (ret ==FAILURE)
		{
			if (strErr.length()>OBJ_TITLE_MAX_LEN)
			{
				strErr = strErr.substr(0,OBJ_TITLE_MAX_LEN);
			}
			sprintf(title_array[0], strErr.c_str()); //��ʾ������Ϣ
			uFlag = 1;
		} 	
	}
	if (0 == uFlag)
	{
		sprintf(title_array[0], "��ǰ��Ʊ����: %08u", g_globalArg->m_curInvVol->m_curInvNo);
	}
	sprintf(title_array[1], "��Ʊ���룺");
	sprintf(title_array[2], "��Ʊ���룺");
	sprintf(title_array[3], "");

	m_pLabel->SetTitleAlign(CaObject::ALIGN_LEFT);
	m_pInput1->SetMaxLen(12);
	m_pInput2->SetMaxLen(8);
	m_pInput3->SetMaxLen(4);
	m_pInput3->Visible(false); //���ɼ�

	m_pInput1->SetContentBuf((UINT8*)g_globalArg->m_curInvVol->m_code.c_str(), g_globalArg->m_curInvVol->m_code.length());
	if (1 == g_globalArg->m_curInvVol->m_curInvNo % DEFAULTE_VOL_NUM)//ÿ���һ��ʱ�����û�����
	{
		CaMsgBox::ShowMsg("��ȷ��ֽ�ʷ�Ʊ���뵱ǰ��Ʊ�Ŷ�Ӧ!");
	}
	return;			
}

void CGInvInputWin::InvUsewstQueryShow()
{
	sprintf(title_array[0], "�ѿ���Ʊ����");
	sprintf(title_array[1], "��Ʊ���룺");
	sprintf(title_array[2], "��Ʊ���룺");
	sprintf(title_array[3], "");
	m_pLabel->SetTitleAlign(CaObject::ALIGN_CENTER);
	m_pInput1->SetMaxLen(12);
	m_pInput2->SetMaxLen(8);
	m_pInput3->SetMaxLen(4);
	m_pInput3->Visible(false); //���ɼ�

	m_pInput1->SetContentBuf((UINT8*)g_globalArg->m_curInvVol->m_code.c_str(), g_globalArg->m_curInvVol->m_code.length());
	return;
}

void CGInvInputWin::InvStubQueryShow()
{
	sprintf(title_array[0], "��Ʊ�����ѯ");
	sprintf(title_array[1], "��Ʊ���룺");
	sprintf(title_array[2], "��ʼ���룺");
	sprintf(title_array[3], "��ֹ���룺");
	m_pLabel->SetTitleAlign(CaObject::ALIGN_CENTER);
	m_pInput1->SetMaxLen(12);
	m_pInput2->SetMaxLen(8);
	m_pInput3->SetMaxLen(8);
	m_pInput3->Visible(true); //�ɼ�

	m_pInput1->SetContentBuf((UINT8*)g_globalArg->m_curInvVol->m_code.c_str(), g_globalArg->m_curInvVol->m_code.length());
	return;
}

void CGInvInputWin::InvDetailNoQueryShow()
{
	if (m_nFlag ==0)
	{
		sprintf(title_array[0], "��Ʊ��ϸ��ѯ");		
	}
	else
	{
		sprintf(title_array[0], "��Ʊ����");
	}	
	sprintf(title_array[1], "��Ʊ���룺");
	sprintf(title_array[2], "��Ʊ���룺");
	sprintf(title_array[3], "");
	m_pLabel->SetTitleAlign(CaObject::ALIGN_CENTER);
	m_pInput1->SetMaxLen(12);
	m_pInput2->SetMaxLen(8);
	m_pInput3->SetMaxLen(4);
	m_pInput3->Visible(false); //���ɼ�
	m_pInput1->SetContentBuf((UINT8*)g_globalArg->m_curInvVol->m_code.c_str(), g_globalArg->m_curInvVol->m_code.length());
	return;
}

void CGInvInputWin::InvDistributeShow()
{
	sprintf(title_array[0], "��Ʊ�ַ�");
	sprintf(title_array[1], "��Ʊ���룺");
	sprintf(title_array[2], "��ʼ���룺");
	sprintf(title_array[3], "��Ʊ������");
	m_pLabel->SetTitleAlign(CaObject::ALIGN_CENTER);
	m_pInput1->SetMaxLen(12);
	m_pInput2->SetMaxLen(8);
	m_pInput3->SetMaxLen(4);
	m_pInput3->Visible(true); //�ɼ�

	m_pInput1->SetContentBuf((UINT8*)g_globalArg->m_curInvVol->m_code.c_str(), g_globalArg->m_curInvVol->m_code.length());
	return;
}

void CGInvInputWin::InvRetreatShow()
{
	sprintf(title_array[0], "��Ʊ�˻�");
	sprintf(title_array[1], "��Ʊ���룺");
	sprintf(title_array[2], "��ʼ���룺");
	sprintf(title_array[3], "��Ʊ������");
	m_pLabel->SetTitleAlign(CaObject::ALIGN_CENTER);
	m_pInput1->SetMaxLen(12);
	m_pInput2->SetMaxLen(8);
	m_pInput3->SetMaxLen(4);
	m_pInput3->Visible(true); //�ɼ�
	
	m_pInput1->SetContentBuf((UINT8*)g_globalArg->m_curInvVol->m_code.c_str(), g_globalArg->m_curInvVol->m_code.length());
	return;
}

UINT8 CGInvInputWin::ChangeTitle()
{
	m_pLabel->SetTitle(title_array[0], strlen(title_array[0]));
	m_pInput1->SetTitle(title_array[1], strlen(title_array[1]));
	m_pInput2->SetTitle(title_array[2], strlen(title_array[2]));
	m_pInput3->SetTitle(title_array[3], strlen(title_array[3]));
	return SUCCESS;
}


int CGInvInputWin::ProcEvent(int iEvent,unsigned char *pEventData, int iDataLen)
{
	switch(iEvent)
	{	   
	case RETURN_MAIN_MENU:
		{
			switch ( m_level1 )
			{
			case INV_WLLQFP_L1:
				{
					ChangeWin(INV_MANAGE_MENU);	
					break;
				}
			case INV_RET_QUERY_L1:
				{
					ChangeWin(INV_MANAGE_MENU);	
					break;
				}
			case INV_USEWST_QUERY_L1:
				{
					ChangeWin(GENERAL_INV_MTLBTN_WIN);	
					break;
				}
			case INV_STUB_QUERY_L1:
				{
					ChangeWin(INV_MANAGE_MENU);	
					break;
				}
			case INV_DETAIL_NO_L1:
				{
					DBG_PRINT(("m_nFlag= %u",m_nFlag));
					if (m_nFlag ==0)
					{
						ChangeWin(INV_MANAGE_MENU);	 //���ط�Ʊ�������	
					}
					else
					{
						ChangeWin(FISCAL_MAIN_MENU);//��Ʊ����ʱ����˰�ع������
					}
					break;
				}
			case INV_DISTRIBUTE_L1:
				{
					ChangeWin(INV_SEG_MENU);	
					break;
				}
			case INV_RETREAT_L1:
				{
					ChangeWin(INV_SEG_MENU);	
					break;
				}
			default:
				break;
			}
		return SUCCESS;
		break;
		}			
	
	default: 
		break;		
	}
   return CaWindow::ProcEvent(iEvent,pEventData,iDataLen);
}


int CGInvInputWin::ReFresh()
{
	ReFreshTitle();
	CaGroup::ReFresh();
	if(m_pCurObj != NULL )
	{
 		m_pCurObj->SetFocusIn();
	}
	LCDRedraw();

	return 1;
}

void CGInvInputWin::S_OnInput1(CaObject *obj,int iEvent, unsigned char * pEventData, int iDataLen)
{
	CGInvInputWin *win=(CGInvInputWin *)obj->GetdWin();
	win->OnInput1(iEvent,pEventData,iDataLen);
}
void CGInvInputWin::S_OnInput2(CaObject *obj,int iEvent, unsigned char * pEventData, int iDataLen)
{
	CGInvInputWin *win=(CGInvInputWin *)obj->GetdWin();
	win->OnInput2(iEvent,pEventData,iDataLen);
}
void CGInvInputWin::S_OnInput3(CaObject *obj,int iEvent, unsigned char * pEventData, int iDataLen)
{
	CGInvInputWin *win=(CGInvInputWin *)obj->GetdWin();
	win->OnInput3(iEvent,pEventData,iDataLen);
}

void CGInvInputWin::S_OnButton1(CaObject *obj,int iEvent, unsigned char * pEventData, int iDataLen)
{
	CGInvInputWin *win=(CGInvInputWin *)obj->GetdWin();
	win->OnButton1(iEvent,pEventData,iDataLen);
}
void CGInvInputWin::S_OnButton2(CaObject *obj,int iEvent, unsigned char * pEventData, int iDataLen)
{
	CGInvInputWin *win=(CGInvInputWin *)obj->GetdWin();
	win->OnButton2(iEvent,pEventData,iDataLen);
}

void CGInvInputWin::OnInput1(int iEvent, unsigned char * pEventData, int iDataLen)
{
	OnDownKey(); //�л����㵽��һ���ؼ�
	return;	

}
void CGInvInputWin::OnInput2(int iEvent, unsigned char * pEventData, int iDataLen)
{
	OnDownKey(); //�л����㵽��һ���ؼ�
	return;	
}
void CGInvInputWin::OnInput3(int iEvent, unsigned char * pEventData, int iDataLen)
{
	OnDownKey(); //�л����㵽��һ���ؼ�
	return;	
}

void CGInvInputWin::OnButton1(int iEvent, unsigned char * pEventData, int iDataLen)
{
	switch ( m_level1 )
	{
	case INV_WLLQFP_L1:
		{
			InvWllqfpBtn1();
			break;
		}
	case INV_RET_QUERY_L1:
		{
			InvReturnQueryBtn1();
			break;
		}
	case INV_USEWST_QUERY_L1:
		{
			InvUsewstQueryBtn1();
			break;
		}
	case INV_STUB_QUERY_L1:
		{
			InvStubQueryBtn1();
			break;
		}
	case INV_DETAIL_NO_L1:
		{
			InvDetailNoQueryBtn1();
			break;
		}
	case INV_DISTRIBUTE_L1:
		{
			InvDistributeBtn1();
			break;
		}
	case INV_RETREAT_L1:
		{
			InvRetreatBtn1();
			break;
		}
	default:
		break;
	}	
}

void CGInvInputWin::OnButton2(int iEvent, unsigned char * pEventData, int iDataLen)
{
	switch ( m_level1 )
	{
	case INV_WLLQFP_L1:
		{
			ChangeWin(INV_MANAGE_MENU);	
			break;
		}
	case INV_RET_QUERY_L1:
		{
			ChangeWin(INV_MANAGE_MENU);	
			break;
		}
	case INV_USEWST_QUERY_L1:
		{
			ChangeWin(GENERAL_INV_MTLBTN_WIN);	
			break;
		}
	case INV_STUB_QUERY_L1:
		{
			ChangeWin(INV_MANAGE_MENU);	
			break;
		}
	case INV_DETAIL_NO_L1:
		{
			DBG_PRINT(("m_nFlag= %u",m_nFlag));
			if (m_nFlag ==0)
			{
				ChangeWin(INV_MANAGE_MENU);	 //���ط�Ʊ�������	
			}
			else
			{
				ChangeWin(FISCAL_MAIN_MENU);
			}
			break;
		}
	case INV_DISTRIBUTE_L1:
		{
			ChangeWin(INV_SEG_MENU);	
			break;
		}
	case INV_RETREAT_L1:
		{
			ChangeWin(INV_SEG_MENU);	
			break;
		}
	default:
		break;
	}	
}
//������ȡ��Ʊ��Ӧ��Buttton1����	
void CGInvInputWin::InvWllqfpBtn1()
{
	string strErr("");
	UINT8 ret=SUCCESS;
	//��鷢Ʊ����ͷ�Ʊ���� ����
	if (CheckInputValid() == FAILURE) 
	{
		return ;
	}
	
	CaMsgBox msgBox("�Ƿ�������ȡ��Ʊ��", CaMsgBox::MB_YESNO);
	msgBox.ShowBox();
	if ( msgBox.m_iStatus != OK_PRESSED )
	{
		return; 
	}

	CaProgressBar proBar("");
	proBar.SetText("������ȡ��Ʊ��...");
	proBar.Show();
	
	ret= INV_NetInvVol( m_invCode, m_invStartNo, m_invNum, strErr);
	if (ret != SUCCESS)
	{
		CaMsgBox::ShowMsg(strErr);
		return ;
	}
	CaMsgBox::ShowMsg("������ȡ��Ʊ�ɹ�");	
	ChangeWin(INV_MANAGE_MENU);	
	return;
}

//��Ʊ���߲�ѯ��Ӧ��Buttton1����
void CGInvInputWin::InvReturnQueryBtn1()
{
	UINT8 ret =SUCCESS;
	ret =CheckInputValid();
	if ( ret != SUCCESS) 
	{
		return ;
	}			
	ret = INVM_CheckIsNoDB(m_invCode, m_invStartNo, m_pInvHead);
	
	DBG_PRINT(("ret= %u",ret));
	if(ret != SUCCESS)
	{
		INVM_ErrMsgBox(ret);
		return ;
	}
	m_InvWin_level2 = INV_RETURN_L2;
	ChangeWin(GENERAL_INV_LABEL_WIN);//�л�����Ʊ���ߴ���
	return;
}

//�ѿ���Ʊ���ϲ�ѯ��Ӧ��Buttton1����	
void CGInvInputWin::InvUsewstQueryBtn1()
{
	UINT8 ret = CheckInputValid();
	if ( ret != SUCCESS) 
	{
		return ;
	}
	ret = INVM_CheckIsNoDB(m_invCode, m_invStartNo, m_pInvHead);
	DBG_PRINT(("ret= %u",ret));
	if(ret != SUCCESS)
	{
		INVM_ErrMsgBox(ret);
		return ;
	}

	m_InvWin_level2 = INV_USEWST_L2;
	ChangeWin(GENERAL_INV_LABEL_WIN);	 //�ѿ���Ʊ���Ͻ���
	
	return;
}

//��Ʊ�����ѯ��Ӧ��Buttton1����	
void CGInvInputWin::InvStubQueryBtn1()
{
	UINT8 ret = CheckInputValid();
	if(ret != SUCCESS)
	{
		return ;
	}
	m_InvWin_level2 = INV_StubPrn_L2;
	ChangeWin(INV_STUB_PRN_WIN);	 //�����ӡ����	
	return;
}

//����Ʊ�����ѯ��Ʊ��ϸ��Ӧ��Buttton1����
void CGInvInputWin::InvDetailNoQueryBtn1()
{
	UINT8 ret = 0;
	ret = CheckInputValid();
	if(ret != SUCCESS)
	{
		return ;
	}
	DBG_PRINT(("m_nFlag= %u",m_nFlag));
	ret = INVM_InvDetailNOQuery(m_invCode, m_invStartNo, m_nFlag);
	if(ret != SUCCESS)
	{
		return ;
	}
	//ChangeWin(INV_MANAGE_MENU);	
}

//��Ʊ�ַ���Ӧ��Buttton1����
void CGInvInputWin::InvDistributeBtn1()
{
	string strErr("");
	
	//��鷢Ʊ����ͷ�Ʊ���� ����
	if (CheckInputValid() == FAILURE) 
	{
		return ;
	}
	
	CaMsgBox::ShowMsg("�뱣������˰���豸ͬʱ���ӿ��");
	
	UINT8 ret=SUCCESS;
	UINT8 uJZlx=2;//��˰�̽���
	
	ret= INV_MediumType(uJZlx);
    if (ret != SUCCESS)
	{
		return ;
	}
	
	CaProgressBar proBar("");
	proBar.SetText("��Ʊ�ַ���...");
	proBar.Show();
	
	ret= INV_HostToInvVol(uJZlx, m_invCode, m_invStartNo, m_invNum, strErr);
	if (ret != SUCCESS)
	{
		CaMsgBox::ShowMsg(strErr);
		return ;
	}
	
	CaMsgBox::ShowMsg("��Ʊ�ַ��ɹ�");
	ChangeWin(INV_SEG_MENU);
}

//��Ʊ�˻ض�Ӧ��Buttton1����
void CGInvInputWin::InvRetreatBtn1()
{
	string strErr("");
	UINT8 ret = SUCCESS;
	
	//��鷢Ʊ����ͷ�Ʊ���� ����
	if (CheckInputValid() == FAILURE) 
	{
		return ;
	}
	
	CaMsgBox msgBox("�Ƿ��˻ط�Ʊ��", CaMsgBox::MB_YESNO);
	msgBox.ShowBox();
	if (msgBox.m_iStatus != OK_PRESSED)
	{
		return; 
	}
	
    UINT8 uJZlx=2;//��˰�̽���
	
	ret= INV_MediumType(uJZlx);
    if (ret != SUCCESS)
	{
		return ;
	}
	
	CaProgressBar proBar("");
	proBar.SetText("��Ʊ�˻���...");
    proBar.Show();
	
	ret= INV_RetToInvVol(uJZlx, m_invCode, m_invStartNo, m_invNum, strErr);
	if (ret != SUCCESS)
	{
		CaMsgBox::ShowMsg(strErr);
		return ;
	}
	CaMsgBox::ShowMsg("��Ʊ�˻سɹ�");
	ChangeWin(INV_SEG_MENU);	
}

UINT8 CGInvInputWin::CheckInputValid( )
{
	//��Input1�ļ��
	if(m_pInput1->IsEmpty())
	{ 
		CaMsgBox::ShowMsg("�����뷢Ʊ����");
		m_pInput1->SetFocus();
		this->ReFresh();
		return FAILURE;
	}
	
	size_t nLen = strlen((char*)(m_pInput1->m_contentBuf));
	DBG_PRINT(("nLen = %d",nLen));
	
	if (nLen != 2*INV_TYPE_CODE_LEN) 
	{
		CaMsgBox::ShowMsg("��Ʊ����Ƿ�");
		m_pInput1->SetFocus();
		this->ReFresh();
		return FAILURE;
	}
	else if (0 == atoi((INT8 *)m_pInput1->m_contentBuf)) 
	{
		DBG_PRINT(("��Ʊ����Ƿ�"));
		CaMsgBox::ShowMsg("��Ʊ����Ƿ�");
		m_pInput1->SetFocus();
		this->ReFresh();
		return FAILURE;
	}	
    m_invCode = (INT8 *)(m_pInput1->m_contentBuf);
	
	
	//��Input2�ļ��
	if(m_pInput2->IsEmpty())
	{
		if ((INV_WLLQFP_L1 == m_level1) || (INV_DISTRIBUTE_L1 == m_level1)
			|| (INV_STUB_QUERY_L1 == m_level1) || (INV_RETREAT_L1 == m_level1))
		{		
			CaMsgBox::ShowMsg("�����뷢Ʊ��ʼ����");
		}
		else
		{		
			CaMsgBox::ShowMsg("�����뷢Ʊ����");
		}
		m_pInput2->SetFocus();
		this->ReFresh();
		return FAILURE;
	}
	//��ȡ��Ʊ�����
	m_invStartNo = atoi((INT8 *)m_pInput2->m_contentBuf);
	if(m_invStartNo == 0)
	{
		if ((INV_WLLQFP_L1 == m_level1) || (INV_DISTRIBUTE_L1 == m_level1)
			|| (INV_STUB_QUERY_L1 == m_level1) || (INV_RETREAT_L1 == m_level1))
		{		
			CaMsgBox::ShowMsg("��Ʊ��ʼ���벻��Ϊ��");
		}
		else
		{		
			CaMsgBox::ShowMsg("��Ʊ���벻��Ϊ��");
		}
		m_pInput2->SetFocus();
		this->ReFresh();
		return FAILURE;
	}
	
	//��Input3�ļ��
	if ((INV_WLLQFP_L1 == m_level1) || (INV_DISTRIBUTE_L1 == m_level1) || (INV_RETREAT_L1 == m_level1))
	{
		if(m_pInput3->IsEmpty())
		{ 
			CaMsgBox::ShowMsg("�����뷢Ʊ����");
			m_pInput3->SetFocus();
			this->ReFresh();
			return FAILURE;
		}
		m_invNum = atoi((INT8 *)m_pInput3->m_contentBuf);	
		if(m_invNum == 0)
		{
			CaMsgBox::ShowMsg("��Ʊ��������Ϊ��");
			m_pInput3->SetFocus();
			this->ReFresh();
			return FAILURE;
		}
	}
	if ( INV_STUB_QUERY_L1 == m_level1 )
	{
		if(m_pInput3->IsEmpty())
		{ 
			CaMsgBox::ShowMsg("�����뷢Ʊ��ֹ����");
			m_pInput3->SetFocus();
			this->ReFresh();
			return FAILURE;
		}
		m_invEndNo = atoi((INT8 *)m_pInput3->m_contentBuf);	
		if(m_invEndNo == 0)
		{
			CaMsgBox::ShowMsg("��Ʊ��ֹ���벻��Ϊ��");
			m_pInput3->SetFocus();
			this->ReFresh();
			return FAILURE;
		}
		//�ж��������ʼ�źͽ�����
		if (m_invStartNo>m_invEndNo) 
		{
			CaMsgBox::ShowMsg("��Ʊ��ʼ������ڽ�ֹ����");
			m_pInput2->SetFocus();
			this->ReFresh();
			return FAILURE;
		}
		//����Ƿ��з��������ķ�Ʊ���
		UINT32 nTmpNum = 0;
		DBG_PRINT(("g_globalArg->m_curInvVol->m_code = %s", g_globalArg->m_curInvVol->m_code.c_str()));
		DBG_PRINT(("m_invStartNo = %u, m_invEndNo = %u", m_invStartNo, m_invEndNo));
		UINT8 ret = INVM_GetInvNum(m_invCode, m_invStartNo, m_invEndNo, nTmpNum);
		if (ret==FAILURE)
		{
			CaMsgBox::ShowMsg("��ѯ���ݿ�ʧ��");
			return FAILURE;		
		}
		else if((ret==SUCCESS)&&(nTmpNum == 0))
		{
			CaMsgBox::ShowMsg("��ƥ��ķ�Ʊ���");
			return FAILURE;		
		}
	}
	this->ReFresh();
	return SUCCESS;
}

