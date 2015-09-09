/*! \file    GeneralInvLabelWin.cpp
   \brief    awe4000r��Ʊ��������Ϣ��ʾ���ý���
   \author   Yu Yan
   \version  1.0
   \date     2008-2-22
 */

#include "GeneralInvLabelWin.h"
#include "InvManageMainMenu.h"
#include "GeneralInvInputWin.h"
#include "InvManageFunc.h"
#include "CaProgressBar.h"
#include "CaMsgBox.h"
#include "TDateTime.h"

#include "AutoIssueFunc.h"

#include "LOGCTRL.h"
//#define NO_POS_DEBUG
#include "pos_debug.h"
#include <string>

CGInvLabelWin::CGInvLabelWin():CaWindow()
{
	m_pageIndex = 1;
	m_pageNum = 0;
	m_iBtnW = 0;
	m_iColW = 0;
	m_curH = 0;
	m_invType = 0;
	m_pInvVol = &m_Invvol;
	m_pLInvHead = &m_LInvhead;
	DBG_ASSERT_EXIT((m_pInvVol != NULL), (" m_pInvVol == NULL!"));
	DBG_ASSERT_EXIT((m_pLInvHead != NULL), (" m_pLInvHead == NULL!"));	

	m_flag1 = 0;
	m_level2 = 0;
}

CGInvLabelWin::~CGInvLabelWin()
{
	    m_pInvVol = NULL;	
}

int CGInvLabelWin::Create(int iX,int iY,int iW,int iH)
{
	char title[OBJ_TITLE_MAX_LEN + 1];
    int titleLen=0;
	
    m_iBtnW = (SCREEN_W/2 - 0) ; //�ؼ��Ŀ��
	m_iColW = m_iBtnW + 0;        //�ؼ����п�
  
	m_pFrame->RegsiterWin(this,GENERAL_INV_LABEL_WIN);
  
	CaWindow::Create(iX,iY,iW,iH); // creat a window

	//����һ����ǩ  ��һ��	
	label[0] = new CaLabel(false,CaObject::ALIGN_LEFT);
	m_curH = SCREEN_TOP_OFFSET;
	label[0]->Create(0,m_curH, SCREEN_W, CHAR_H); //����������
	label[0]->SetTitle(title_array[0], strlen(title_array[0]));
  
	//����һ����ǩ  �ڶ���
	label[1] = new CaLabel(false,CaObject::ALIGN_LEFT);
	m_curH += LINE_H;
	label[1]->Create(0,m_curH, SCREEN_W, CHAR_H); //����������
	label[1]->SetTitle(title_array[1], strlen(title_array[1]));

	//����һ����ǩ  ������
	label[2] = new CaLabel(false,CaObject::ALIGN_LEFT);
	m_curH += LINE_H;
	label[2]->Create(0,m_curH, SCREEN_W, CHAR_H);
	label[2]->SetTitle(title_array[2], strlen(title_array[2]));

	//����һ����ǩ  ������
	label[3] = new CaLabel(false,CaObject::ALIGN_LEFT);
	m_curH += LINE_H;
	label[3]->Create(0,m_curH, m_iBtnW, CHAR_H);
	label[3]->SetTitle(title_array[3], strlen(title_array[3]));

	//����һ����ǩ ������
	label[4] = new CaLabel(false,CaObject::ALIGN_LEFT);
	label[4]->Create(m_iColW,m_curH, m_iBtnW, CHAR_H);
	label[4]->SetTitle(title_array[4], strlen(title_array[4]));

	m_iBtnW = (SCREEN_W - 40)/2 - 4;	//Button�Ŀ��
 	m_iColW = (SCREEN_W - 40)/2;		//Button���п�
	INT32 left_offset = SCREEN_LEFT_OFFSET+8;
	INT32 leftoffset_btn = left_offset + 14;
	
	//����һ��Button  ������
	strcpy(title, "ȷ��");
	m_pBtn1 = new CaButton();
	m_curH += LINE_H;
	m_pBtn1->Create(leftoffset_btn,m_curH,m_iBtnW,WORD_H); 
	m_pBtn1->SetTitleAlign(CaObject::ALIGN_CENTER);
	m_pBtn1->SetTitle(title, strlen(title));
	m_pBtn1->BoxType(CaObject::BOX_NO);
	m_pBtn1->OnObject = S_OnButton1;
	m_pBtn1->Visible(true); //���ɼ�

	//����һ��Button  ������
	strcpy(title, "����");
	m_pBtn2 = new CaButton();
	m_pBtn2->Create(leftoffset_btn + m_iColW,m_curH,m_iBtnW,WORD_H); 
	m_pBtn2->SetTitleAlign(CaObject::ALIGN_CENTER);
	m_pBtn2->SetTitle(title, strlen(title));
	m_pBtn2->BoxType(CaObject::BOX_NO);
	m_pBtn2->OnObject = S_OnButton2;

	OnActive = S_OnActive;
	
	this->End();  
	return 1;
}

void CGInvLabelWin::S_OnActive(CaWindow *obj)
{
	((CGInvLabelWin *)obj)->DoActive();
}

void CGInvLabelWin::DoActive()
{
	DBG_PRINT((" ����CGInvLabelWin::DoActive����!"));

	m_flag1 = ((CInvManageMenu*)m_pFrame->GetWin(INV_MANAGE_MENU))->m_InvWin_level1;
	DBG_PRINT(("m_flag1 = %u",m_flag1));
	m_level2 = ((CGInvInputWin*)m_pFrame->GetWin(GENERAL_INV_INPUT_WIN))->m_InvWin_level2;
	DBG_PRINT(("m_level2 = %u",m_level2));

 	if (INV_DIST_QUERY_L1 == m_flag1 )//����ѯ����
	{		
		m_pageIndex = 1;
		label[0]->SetTitleAlign(CaObject::ALIGN_RIGHT);
		m_iBtnW = (SCREEN_W/2 - 0) ; //�ؼ��Ŀ��
		m_iColW = m_iBtnW + 0;        //�ؼ����п�
		m_curH = 3 * LINE_H;
		label[3]->Create(0,m_curH, m_iBtnW, CHAR_H);
		label[3]->SetTitle(title_array[3], strlen(title_array[3]));
		label[4]->Create(m_iColW,m_curH, m_iBtnW, CHAR_H);
		label[4]->SetTitle(title_array[4], strlen(title_array[4]));
		label[3]->Visible(true);
		label[4]->Visible(true);
		INVM_GetVolNum(m_pageNum);//��ý�˰���еķ�Ʊ����
		QueryShow(m_pInvVol, m_pageIndex);//��֯��Ļ��ʾ��Ϣ
	}
	else if (INV_BLK_WASTE_L1 == m_flag1)//�հ׷�Ʊ���Ͻ���
	{
		m_pageIndex = 1;
		m_pageNum = 1;
		label[3]->Visible(false);
		label[4]->Visible(false);
		BlankWasteShow();//��֯��Ļ��ʾ��Ϣ
	}
	else
	{
		switch (m_level2)
		{
		case INV_RETURN_L2://��Ʊ���߽���
			{
				m_pLInvHead = ((CGInvInputWin*)m_pFrame->GetWin(GENERAL_INV_INPUT_WIN))->m_pInvHead;
				DBG_ASSERT_EXIT((m_pLInvHead != NULL), (" m_pLInvHead == NULL!"));	
				DBG_PRINT(("m_pLInvHead->m_fphm= %u",m_pLInvHead->m_fphm));
				m_pageIndex = 1;
				m_pageNum = 1;
				label[0]->SetTitleAlign(CaObject::ALIGN_LEFT);
				m_iBtnW = (SCREEN_W/2 - 0) ; //�ؼ��Ŀ��
				m_iColW = m_iBtnW + 0;        //�ؼ����п�
				m_curH = 3 * LINE_H;
				label[3]->Create(0,m_curH, m_iBtnW+12, CHAR_H);
				label[3]->SetTitle(title_array[3], strlen(title_array[3]));
				label[4]->Create(m_iColW+16,m_curH, m_iBtnW-16, CHAR_H);
				label[4]->SetTitle(title_array[4], strlen(title_array[4]));
				label[3]->Visible(true);
				label[4]->Visible(true);
				ReturnShow(m_pLInvHead);//��֯��Ļ��ʾ��Ϣ
				break;
			}
		case INV_USEWST_L2://�ѿ���Ʊ����
			{
				m_pLInvHead = ((CGInvInputWin*)m_pFrame->GetWin(GENERAL_INV_INPUT_WIN))->m_pInvHead;
				DBG_ASSERT_EXIT((m_pLInvHead != NULL), (" m_pLInvHead == NULL!"));	
				DBG_PRINT(("m_pLInvHead->m_fphm= %u",m_pLInvHead->m_fphm));
				m_pageIndex = 1;
				m_pageNum = 1;
				label[0]->SetTitleAlign(CaObject::ALIGN_CENTER);
				m_iBtnW = (SCREEN_W/2 - 0) ; //�ؼ��Ŀ��
				m_iColW = m_iBtnW + 0;        //�ؼ����п�
				m_curH = 3 * LINE_H;
				label[3]->Create(0, m_curH, m_iBtnW-24, CHAR_H);
				label[3]->SetTitle(title_array[3], strlen(title_array[3]));
				label[4]->Create(m_iColW-20, m_curH, m_iBtnW+20, CHAR_H);
				label[4]->SetTitle(title_array[4], strlen(title_array[4]));
				label[3]->Visible(true);
				label[4]->Visible(true);
				UsedWasteShow(m_pLInvHead);//��֯��Ļ��ʾ��Ϣ
				break;
			}
		default:
			break;
		}
	}	
	ChangeTitle();
	ReFresh();
	DBG_PRINT(("�˳�CGInvLabelWin::DoActive����!"));
}

int CGInvLabelWin::ProcEvent(int iEvent,unsigned char *pEventData, int iDataLen)
{
	if (INV_DIST_QUERY_L1 == m_flag1 )//����ѯ
	{	
		switch(iEvent)
		{
		case RETURN_MAIN_MENU:  //return to SYSTEMMENU
			ChangeWin(INV_MANAGE_MENU);					
			return SUCCESS;
			break;

		case PAGEUP_KEY:

			 DBG_PRINT(("PAGEUP_KEY"));
			 if ((m_pageIndex-1)<1)
			 {
				 return FAILURE;
				 //m_pageIndex = m_pageNum +1;
			 }
			 m_pageIndex--;
			 QueryShow(m_pInvVol, m_pageIndex);
			 ChangeTitle();
			 ReFresh();	
			 DBG_PRINT(("PAGEUP_KEY"));
			 return SUCCESS;
			 break;

		case PAGEDOWN_KEY:
			 if ((m_pageIndex+1)>m_pageNum)
			 {
				 return FAILURE;
				//m_pageIndex = 0;
			 }
			 m_pageIndex++;
			 QueryShow(m_pInvVol, m_pageIndex);
			 ChangeTitle();
			 ReFresh();	
			 return SUCCESS;
			 break;

		default: 
			break;		
		}
	}
	else if (INV_BLK_WASTE_L1 == m_flag1 )//�հ׷�Ʊ����
	{
		switch (iEvent)
		{
		case RETURN_MAIN_MENU:  //return to MtlBtnWin
			ChangeWin(GENERAL_INV_MTLBTN_WIN);			
			return SUCCESS;
			break;
#if (RELEASE_VER == 0)
		case DISCOUNT_KEY:
			DBG_PRINT(("����DISCOUNT_KEY"));
			UINT8 nIfInvSum;
			AutoIssue(nIfInvSum);	
			break;
#endif
		default:
			break;
		}
	}
	else
	{
		switch(iEvent)
		{
		case RETURN_MAIN_MENU:  //return to SYSTEMMENU
			ChangeWin(GENERAL_INV_INPUT_WIN);					
			return SUCCESS;
			break;
		default:
			break;
		}
	}
 	  
	return CaWindow::ProcEvent(iEvent,pEventData,iDataLen);
}

int CGInvLabelWin::ReFresh()
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

void CGInvLabelWin::S_OnButton1(CaObject *obj,int iEvent, unsigned char * pEventData, int iDataLen)
{
	CGInvLabelWin *win=(CGInvLabelWin *)obj->GetdWin();
	win->OnButton1(iEvent,pEventData,iDataLen);
} 

void CGInvLabelWin::S_OnButton2(CaObject *obj,int iEvent, unsigned char * pEventData, int iDataLen)
{
	CGInvLabelWin *win=(CGInvLabelWin *)obj->GetdWin();
	win->OnButton2(iEvent,pEventData,iDataLen);
}

void CGInvLabelWin::OnButton1(int iEvent, unsigned char * pEventData, int iDataLen)
{
	
	if (INV_DIST_QUERY_L1 == m_flag1 ) 
	{
		ChangeWin(INV_MANAGE_MENU);			
	}
	else if (INV_BLK_WASTE_L1 == m_flag1 )//�հ׷�Ʊ����
	{
		InvBlankWasteBtn1();
	}
	else
	{
		switch (m_level2)
		{
		case INV_RETURN_L2://��Ʊ����
			{
				InvReturnBtn1();
				break;
			}
		case INV_USEWST_L2://�ѿ���Ʊ����
			{
				InvUsedWasteBtn1();
				break;
			}
		default:
			break;
		}
	}
	return ;  		
}

void CGInvLabelWin::OnButton2(int iEvent, unsigned char * pEventData, int iDataLen)
{
	 if (INV_DIST_QUERY_L1 == m_flag1 ) //����ѯ
	 {
		 ChangeWin(INV_MANAGE_MENU);			
	 }
	 else if (INV_BLK_WASTE_L1 == m_flag1 )//�հ׷�Ʊ����
	 {
		 ChangeWin(GENERAL_INV_MTLBTN_WIN);
	 }
	 else
	 {
		 ChangeWin(GENERAL_INV_INPUT_WIN);//��Ʊ����,�ѿ���Ʊ����
	 }
	 return;
}

UINT8 CGInvLabelWin::ChangeTitle()
{
	label[0]->SetTitle(title_array[0], strlen(title_array[0]));
	label[1]->SetTitle(title_array[1], strlen(title_array[1]));
	label[2]->SetTitle(title_array[2], strlen(title_array[2]));
	label[3]->SetTitle(title_array[3], strlen(title_array[3]));
    label[4]->SetTitle(title_array[4], strlen(title_array[4]));  
	return SUCCESS;
}

//--------------------------------------------------------------------------------------------------------------------
//��ȡδ���뷢Ʊ����Ϣ�����޸���Ļ��ʾ
//--------------------------------------------------------------------------------------------------------------------
UINT8 CGInvLabelWin::QueryShow(CInvVol *pInvVol, UINT32 nPageIndex)
{
	DBG_ASSERT_EXIT((m_pInvVol != NULL), (" m_pInvVol == NULL!"));
	
	char value[256];
	INT32 errorcode=0;
	memset((void*)value, 0, sizeof(value));

	DBG_PRINT((" nPageIndex == %u", nPageIndex));
	//ҳ����ų���
	if( (nPageIndex<1) || (nPageIndex>m_pageNum) )
	{
		return FAILURE;
	}

	//���һ���ѷַ�δ����ļ�¼
	pInvVol->m_filter = "where USED_FLAG = 1 and OVER_FLAG = 1 ";
	
	sprintf(value,"and NO > %u ",(nPageIndex - 1));
	pInvVol->m_filter.append(value);
	pInvVol->m_filter.append("limit 1 ");

	pInvVol->Requery();  //��ѯ
	errorcode = pInvVol->LoadOneRecord();
	if (errorcode != SQLITE_OK)
	{
		INVM_ErrMsgBox(QUERY_ERROR);
		return FAILURE;
	}

    //�����Ӧ��Ʊ����
	sprintf(title_array[0], "[ҳ%u/%u]", nPageIndex, m_pageNum);
	sprintf(title_array[1], "��Ʊ����: %s", pInvVol->m_code.c_str());
	sprintf(title_array[2], "��������: %u", pInvVol->m_date);
	sprintf(title_array[3], "ʼ��: %08u", pInvVol->m_isno);
	sprintf(title_array[4], "ֹ��: %08u", pInvVol->m_ieno);

	return SUCCESS;
}
//--------------------------------------------------------------------------------------------------------------------
//��ȡ��Ҫ���ߵĺ�Ʊ��Ϣ�����޸���Ļ��ʾ
//--------------------------------------------------------------------------------------------------------------------
UINT8 CGInvLabelWin::ReturnShow(CInvHead *pInvHead)
{
	DBG_PRINT(("����CGInvLabelWin::ReturnShow����"));
	
	TDateTime retDateTime(pInvHead->m_kprq, pInvHead->m_kpsj);
	string strDateTime = retDateTime.FormatString(YYYYMMDDHHMMSS);
	
	double moneySum = ((double)(pInvHead->m_kphjje))/SUM_EXTENSION;
	sprintf(title_array[0], "��ǰ��Ʊ����:%08u", g_globalArg->m_curInvVol->m_curInvNo);
	sprintf(title_array[1], "���˷�Ʊ����:%08u", pInvHead->m_fphm);
	sprintf(title_array[2], "��Ʊʱ��:%s", strDateTime.c_str());
	sprintf(title_array[3], "�ϼ�:-%.2lf", moneySum);
	sprintf(title_array[4], "��Ʒ����Ŀ:%u", pInvHead->m_sphsl);
	
	DBG_PRINT(("title_array[3] = %s", title_array[3]));
	DBG_PRINT(("title_array[4] = %s", title_array[4]));
	DBG_PRINT(("�˳�CGInvLabelWin::ReturnShow����"));
	return SUCCESS;	
}

//--------------------------------------------------------------------------------------------------------------------
//��ȡ��Ҫ���ϵĿհ׷�Ʊ��Ϣ�����޸���Ļ��ʾ
//--------------------------------------------------------------------------------------------------------------------
UINT8 CGInvLabelWin::BlankWasteShow()
{
	string strErr("");
	UINT8 ret =SUCCESS;
	UINT8 uFlag=0;
	if (0 == g_globalArg->m_curInvVol->m_curInvNo) //���ⷴ������
	{
		ret = SALE_GetCurInv(g_globalArg->m_curInvVol, strErr);
		if (ret == FAILURE)
		{
			if (strErr.length()>OBJ_TITLE_MAX_LEN)
			{
				strErr = strErr.substr(0,OBJ_TITLE_MAX_LEN);
			}
			label[0]->SetTitleAlign(CaObject::ALIGN_LEFT);
			sprintf(title_array[0], strErr.c_str()); //����
			sprintf(title_array[1], "���Ϸ�Ʊ����: ��");
			sprintf(title_array[2], "���Ϸ�Ʊ����: ��");
			uFlag=1;
		}		
	}	
	if (0 == uFlag)
	{
		label[0]->SetTitleAlign(CaObject::ALIGN_CENTER);
		sprintf(title_array[0], "�հ׷�Ʊ����");
		sprintf(title_array[1], "���Ϸ�Ʊ����:%s ", g_globalArg->m_curInvVol->m_code.c_str());
		sprintf(title_array[2], "���Ϸ�Ʊ����:%08u", g_globalArg->m_curInvVol->m_curInvNo);	
	}	
	sprintf(title_array[3], "");
	sprintf(title_array[4], "");
	return SUCCESS;
}

//--------------------------------------------------------------------------------------------------------------------
//��ȡ��Ҫ���ϵ��ѿ���Ʊ��Ϣ�����޸���Ļ��ʾ
//--------------------------------------------------------------------------------------------------------------------
UINT8 CGInvLabelWin::UsedWasteShow(CInvHead *pInvHead)
{
	sprintf(title_array[0], "�ѿ���Ʊ����");	
	sprintf(title_array[1], "��Ʊ����: %08d", pInvHead->m_fphm);	
	
	TDateTime tmpDate(pInvHead->m_kprq, pInvHead->m_kpsj);
    string strTmpDate = tmpDate.FormatString(YYYYMMDDHHMMSS);
	sprintf(title_array[2], "��Ʊʱ��: %s", strTmpDate.c_str());

	switch(pInvHead->m_kplx)
	{
	case NORMAL_INV:
		m_invType = WASTE_NOR;
		sprintf(title_array[3], "����: ��Ʊ");
		break;
	case RET_MANUAL_INV:
	case RET_SPECIAL_INV:
	case RETURN_INV:
		m_invType = WASTE_RET;
		sprintf(title_array[3], "����: ��Ʊ");
		break;
	case WASTE_INV:
	case WASTE_NOR:
	case WASTE_RET:
		sprintf(title_array[3], "����: ��Ʊ");
		break;
	default:;
	}

	if ((pInvHead->m_kplx==RETURN_INV)||(pInvHead->m_kplx==RET_MANUAL_INV)||(pInvHead->m_kplx==RET_SPECIAL_INV)) 
	{
		sprintf(title_array[4], "���: -%.2lf", (double)(pInvHead->m_kphjje)/100.0);
	}
	else
	{
		sprintf(title_array[4], "���: %.2lf", (double)(pInvHead->m_kphjje)/100.0);
	}
	
	return SUCCESS;
}

//--------------------------------------------------------------------------------------------------------------------
//��Ʊ����ʱ��Ӧ��Button1����
//--------------------------------------------------------------------------------------------------------------------
void CGInvLabelWin::InvReturnBtn1()
{
	
	if (0==g_globalArg->m_curInvVol->m_curInvNo)
	{
		INVM_ErrMsgBox(INV_ZERO);
		return;	
	}
	
	UINT8 ret=SUCCESS;
	
	//����Ƿ����㸺Ʊ����
	DBG_PRINT(("m_pLInvHead->m_fphm= %u",m_pLInvHead->m_fphm));
	ret=INVM_CheckIsNoRet(m_pLInvHead);
	DBG_PRINT(("ret= %u",ret));
	if (ret !=SUCCESS)
	{
		INVM_ErrMsgBox(ret);
		return ;
	}
	DBG_PRINT(("m_pLInvHead->m_fphm= %u",m_pLInvHead->m_fphm));
	
	ret =INVM_InvRetProc(m_pLInvHead);	//�˱�����Ʊ,m_pRtInvHead�洢��Ҫ�˷�Ʊ����Ϣ
	DBG_PRINT(("ret= %u",ret ));
	
	if (ret!=SUCCESS)
	{
		INVM_ErrMsgBox(ret);
		ChangeWin(GENERAL_INV_INPUT_WIN);
	}
	else
	{
		ChangeWin(INV_MANAGE_MENU);	 //���ط�Ʊ�������				
	}
	
	return;
}

//--------------------------------------------------------------------------------------------------------------------
//�հ׷�Ʊ���϶�Ӧ��Button1����
//--------------------------------------------------------------------------------------------------------------------
void CGInvLabelWin::InvBlankWasteBtn1()
{
	UINT8 ret=SUCCESS;
    //�հ�����
	ret =INVM_InvWasteProc(); 
	DBG_PRINT(("ret= %u",ret ));
	
	if (ret != SUCCESS)
	{
		INVM_ErrMsgBox(ret);
		DBG_PRINT(("��Ʊ����ʧ��"));
		return;
	}
	
	CaMsgBox::ShowMsg("��Ʊ���ϳɹ�");
	DBG_PRINT(("��Ʊ���ϳɹ�"));
	DoActive();//ˢ����Ļ��ʾ��Ϣ
	return;
}

//--------------------------------------------------------------------------------------------------------------------
//�ѿ���Ʊ���϶�Ӧ��Button1����
//--------------------------------------------------------------------------------------------------------------------
void CGInvLabelWin::InvUsedWasteBtn1()
{
	UINT8 nRet = 0;
	string strErr("");
	if (g_globalArg->m_operator->m_role == DEMO_ROLE) 
	{
		CaMsgBox::ShowMsg("ѧϰ��ɫ���������ѿ�Ʊ");
		return;
	}
	nRet = CheckCancelValid();
	if (SUCCESS != nRet)
	{
		return;
	}
	
	CaMsgBox msgBox("�Ƿ�����?",CaMsgBox::MB_YESNO);
	msgBox.ShowBox();
	if (msgBox.m_iStatus != OK_PRESSED)
	{
		return;
	}
    else
	{
		CaProgressBar proBar("��Ʊ������.....");
		proBar.Show();
		m_pLInvHead->m_zskl = g_globalArg->m_strZskl;
		
		nRet = INVM_WstInv(m_pLInvHead, strErr);
		if (SUCCESS != nRet)
		{
			CaMsgBox::ShowMsg(strErr);
			ChangeWin(GENERAL_INV_INPUT_WIN);	 //����INPUT����
			return;
		}
		else
		{
			CaMsgBox::ShowMsg("��Ʊ���ϳɹ�");
			ChangeWin(GENERAL_INV_MTLBTN_WIN);	 //����MultButton����
			return;
		}
	}
}

UINT8 CGInvLabelWin::CheckCancelValid(void)
{
	CInvHead *pInvHead = m_pLInvHead; 
	char val[256];
	INT32 errorcode;
	memset((void*)val, 0, sizeof(val));
	
	//��Ϊ��Ʊ������
    if( (WASTE_INV == pInvHead->m_kplx) || (WASTE_NOR == pInvHead->m_kplx)
		|| (WASTE_RET == pInvHead->m_kplx) )
    {
		CaMsgBox::ShowMsg("�������Ϸ�Ʊ"); 
		return FAILURE;
    }
	
	//��Ϊ���˷�Ʊ������
	memset((void*)val, 0, sizeof(val));
	sprintf(val,"where FPDM = '%s' and FPHM = %u",pInvHead->m_fpdm.c_str(), pInvHead->m_fphm);	
	DBG_PRINT(("val = %s", val));
	CRtInv rtInv;
	rtInv.m_filter = val;
	rtInv.Requery();
	
	DBG_PRINT(("m_pInvHead->m_bzkz = %s", pInvHead->m_bzkz.c_str()));
	if (rtInv.LoadOneRecord() == SQLITE_OK)//һ����Ʊ�ѱ�����������ϣ�����Ӧ�ĺ�Ʊ��������
	{
		CaMsgBox::ShowMsg("��Ʊ�ѿ���Ʊ"); 
		return FAILURE;
	}
	
	return SUCCESS;
}

