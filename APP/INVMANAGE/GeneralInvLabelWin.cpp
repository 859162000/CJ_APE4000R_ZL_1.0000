/*! \file    GeneralInvLabelWin.cpp
   \brief    awe4000r发票管理档的信息显示公用界面
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
	
    m_iBtnW = (SCREEN_W/2 - 0) ; //控件的宽度
	m_iColW = m_iBtnW + 0;        //控件的列宽
  
	m_pFrame->RegsiterWin(this,GENERAL_INV_LABEL_WIN);
  
	CaWindow::Create(iX,iY,iW,iH); // creat a window

	//创建一个标签  第一行	
	label[0] = new CaLabel(false,CaObject::ALIGN_LEFT);
	m_curH = SCREEN_TOP_OFFSET;
	label[0]->Create(0,m_curH, SCREEN_W, CHAR_H); //参数是坐标
	label[0]->SetTitle(title_array[0], strlen(title_array[0]));
  
	//创建一个标签  第二行
	label[1] = new CaLabel(false,CaObject::ALIGN_LEFT);
	m_curH += LINE_H;
	label[1]->Create(0,m_curH, SCREEN_W, CHAR_H); //参数是坐标
	label[1]->SetTitle(title_array[1], strlen(title_array[1]));

	//创建一个标签  第三行
	label[2] = new CaLabel(false,CaObject::ALIGN_LEFT);
	m_curH += LINE_H;
	label[2]->Create(0,m_curH, SCREEN_W, CHAR_H);
	label[2]->SetTitle(title_array[2], strlen(title_array[2]));

	//创建一个标签  第四行
	label[3] = new CaLabel(false,CaObject::ALIGN_LEFT);
	m_curH += LINE_H;
	label[3]->Create(0,m_curH, m_iBtnW, CHAR_H);
	label[3]->SetTitle(title_array[3], strlen(title_array[3]));

	//创建一个标签 第四行
	label[4] = new CaLabel(false,CaObject::ALIGN_LEFT);
	label[4]->Create(m_iColW,m_curH, m_iBtnW, CHAR_H);
	label[4]->SetTitle(title_array[4], strlen(title_array[4]));

	m_iBtnW = (SCREEN_W - 40)/2 - 4;	//Button的宽度
 	m_iColW = (SCREEN_W - 40)/2;		//Button的列宽
	INT32 left_offset = SCREEN_LEFT_OFFSET+8;
	INT32 leftoffset_btn = left_offset + 14;
	
	//创建一个Button  第五行
	strcpy(title, "确定");
	m_pBtn1 = new CaButton();
	m_curH += LINE_H;
	m_pBtn1->Create(leftoffset_btn,m_curH,m_iBtnW,WORD_H); 
	m_pBtn1->SetTitleAlign(CaObject::ALIGN_CENTER);
	m_pBtn1->SetTitle(title, strlen(title));
	m_pBtn1->BoxType(CaObject::BOX_NO);
	m_pBtn1->OnObject = S_OnButton1;
	m_pBtn1->Visible(true); //不可见

	//创建一个Button  第五行
	strcpy(title, "返回");
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
	DBG_PRINT((" 进入CGInvLabelWin::DoActive函数!"));

	m_flag1 = ((CInvManageMenu*)m_pFrame->GetWin(INV_MANAGE_MENU))->m_InvWin_level1;
	DBG_PRINT(("m_flag1 = %u",m_flag1));
	m_level2 = ((CGInvInputWin*)m_pFrame->GetWin(GENERAL_INV_INPUT_WIN))->m_InvWin_level2;
	DBG_PRINT(("m_level2 = %u",m_level2));

 	if (INV_DIST_QUERY_L1 == m_flag1 )//库存查询界面
	{		
		m_pageIndex = 1;
		label[0]->SetTitleAlign(CaObject::ALIGN_RIGHT);
		m_iBtnW = (SCREEN_W/2 - 0) ; //控件的宽度
		m_iColW = m_iBtnW + 0;        //控件的列宽
		m_curH = 3 * LINE_H;
		label[3]->Create(0,m_curH, m_iBtnW, CHAR_H);
		label[3]->SetTitle(title_array[3], strlen(title_array[3]));
		label[4]->Create(m_iColW,m_curH, m_iBtnW, CHAR_H);
		label[4]->SetTitle(title_array[4], strlen(title_array[4]));
		label[3]->Visible(true);
		label[4]->Visible(true);
		INVM_GetVolNum(m_pageNum);//获得金税盘中的发票卷数
		QueryShow(m_pInvVol, m_pageIndex);//组织屏幕显示信息
	}
	else if (INV_BLK_WASTE_L1 == m_flag1)//空白发票作废界面
	{
		m_pageIndex = 1;
		m_pageNum = 1;
		label[3]->Visible(false);
		label[4]->Visible(false);
		BlankWasteShow();//组织屏幕显示信息
	}
	else
	{
		switch (m_level2)
		{
		case INV_RETURN_L2://红票开具界面
			{
				m_pLInvHead = ((CGInvInputWin*)m_pFrame->GetWin(GENERAL_INV_INPUT_WIN))->m_pInvHead;
				DBG_ASSERT_EXIT((m_pLInvHead != NULL), (" m_pLInvHead == NULL!"));	
				DBG_PRINT(("m_pLInvHead->m_fphm= %u",m_pLInvHead->m_fphm));
				m_pageIndex = 1;
				m_pageNum = 1;
				label[0]->SetTitleAlign(CaObject::ALIGN_LEFT);
				m_iBtnW = (SCREEN_W/2 - 0) ; //控件的宽度
				m_iColW = m_iBtnW + 0;        //控件的列宽
				m_curH = 3 * LINE_H;
				label[3]->Create(0,m_curH, m_iBtnW+12, CHAR_H);
				label[3]->SetTitle(title_array[3], strlen(title_array[3]));
				label[4]->Create(m_iColW+16,m_curH, m_iBtnW-16, CHAR_H);
				label[4]->SetTitle(title_array[4], strlen(title_array[4]));
				label[3]->Visible(true);
				label[4]->Visible(true);
				ReturnShow(m_pLInvHead);//组织屏幕显示信息
				break;
			}
		case INV_USEWST_L2://已开发票作废
			{
				m_pLInvHead = ((CGInvInputWin*)m_pFrame->GetWin(GENERAL_INV_INPUT_WIN))->m_pInvHead;
				DBG_ASSERT_EXIT((m_pLInvHead != NULL), (" m_pLInvHead == NULL!"));	
				DBG_PRINT(("m_pLInvHead->m_fphm= %u",m_pLInvHead->m_fphm));
				m_pageIndex = 1;
				m_pageNum = 1;
				label[0]->SetTitleAlign(CaObject::ALIGN_CENTER);
				m_iBtnW = (SCREEN_W/2 - 0) ; //控件的宽度
				m_iColW = m_iBtnW + 0;        //控件的列宽
				m_curH = 3 * LINE_H;
				label[3]->Create(0, m_curH, m_iBtnW-24, CHAR_H);
				label[3]->SetTitle(title_array[3], strlen(title_array[3]));
				label[4]->Create(m_iColW-20, m_curH, m_iBtnW+20, CHAR_H);
				label[4]->SetTitle(title_array[4], strlen(title_array[4]));
				label[3]->Visible(true);
				label[4]->Visible(true);
				UsedWasteShow(m_pLInvHead);//组织屏幕显示信息
				break;
			}
		default:
			break;
		}
	}	
	ChangeTitle();
	ReFresh();
	DBG_PRINT(("退出CGInvLabelWin::DoActive函数!"));
}

int CGInvLabelWin::ProcEvent(int iEvent,unsigned char *pEventData, int iDataLen)
{
	if (INV_DIST_QUERY_L1 == m_flag1 )//库存查询
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
	else if (INV_BLK_WASTE_L1 == m_flag1 )//空白发票作废
	{
		switch (iEvent)
		{
		case RETURN_MAIN_MENU:  //return to MtlBtnWin
			ChangeWin(GENERAL_INV_MTLBTN_WIN);			
			return SUCCESS;
			break;
#if (RELEASE_VER == 0)
		case DISCOUNT_KEY:
			DBG_PRINT(("进入DISCOUNT_KEY"));
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
	else if (INV_BLK_WASTE_L1 == m_flag1 )//空白发票作废
	{
		InvBlankWasteBtn1();
	}
	else
	{
		switch (m_level2)
		{
		case INV_RETURN_L2://红票开具
			{
				InvReturnBtn1();
				break;
			}
		case INV_USEWST_L2://已开发票作废
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
	 if (INV_DIST_QUERY_L1 == m_flag1 ) //库存查询
	 {
		 ChangeWin(INV_MANAGE_MENU);			
	 }
	 else if (INV_BLK_WASTE_L1 == m_flag1 )//空白发票作废
	 {
		 ChangeWin(GENERAL_INV_MTLBTN_WIN);
	 }
	 else
	 {
		 ChangeWin(GENERAL_INV_INPUT_WIN);//红票开具,已开发票作废
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
//获取未导入发票卷信息，并修改屏幕显示
//--------------------------------------------------------------------------------------------------------------------
UINT8 CGInvLabelWin::QueryShow(CInvVol *pInvVol, UINT32 nPageIndex)
{
	DBG_ASSERT_EXIT((m_pInvVol != NULL), (" m_pInvVol == NULL!"));
	
	char value[256];
	INT32 errorcode=0;
	memset((void*)value, 0, sizeof(value));

	DBG_PRINT((" nPageIndex == %u", nPageIndex));
	//页码序号超限
	if( (nPageIndex<1) || (nPageIndex>m_pageNum) )
	{
		return FAILURE;
	}

	//查出一个已分发未导入的记录
	pInvVol->m_filter = "where USED_FLAG = 1 and OVER_FLAG = 1 ";
	
	sprintf(value,"and NO > %u ",(nPageIndex - 1));
	pInvVol->m_filter.append(value);
	pInvVol->m_filter.append("limit 1 ");

	pInvVol->Requery();  //查询
	errorcode = pInvVol->LoadOneRecord();
	if (errorcode != SQLITE_OK)
	{
		INVM_ErrMsgBox(QUERY_ERROR);
		return FAILURE;
	}

    //查出对应发票代码
	sprintf(title_array[0], "[页%u/%u]", nPageIndex, m_pageNum);
	sprintf(title_array[1], "发票代码: %s", pInvVol->m_code.c_str());
	sprintf(title_array[2], "购买日期: %u", pInvVol->m_date);
	sprintf(title_array[3], "始号: %08u", pInvVol->m_isno);
	sprintf(title_array[4], "止号: %08u", pInvVol->m_ieno);

	return SUCCESS;
}
//--------------------------------------------------------------------------------------------------------------------
//获取所要开具的红票信息，并修改屏幕显示
//--------------------------------------------------------------------------------------------------------------------
UINT8 CGInvLabelWin::ReturnShow(CInvHead *pInvHead)
{
	DBG_PRINT(("进入CGInvLabelWin::ReturnShow函数"));
	
	TDateTime retDateTime(pInvHead->m_kprq, pInvHead->m_kpsj);
	string strDateTime = retDateTime.FormatString(YYYYMMDDHHMMSS);
	
	double moneySum = ((double)(pInvHead->m_kphjje))/SUM_EXTENSION;
	sprintf(title_array[0], "当前发票号码:%08u", g_globalArg->m_curInvVol->m_curInvNo);
	sprintf(title_array[1], "所退发票号码:%08u", pInvHead->m_fphm);
	sprintf(title_array[2], "开票时间:%s", strDateTime.c_str());
	sprintf(title_array[3], "合计:-%.2lf", moneySum);
	sprintf(title_array[4], "商品行数目:%u", pInvHead->m_sphsl);
	
	DBG_PRINT(("title_array[3] = %s", title_array[3]));
	DBG_PRINT(("title_array[4] = %s", title_array[4]));
	DBG_PRINT(("退出CGInvLabelWin::ReturnShow函数"));
	return SUCCESS;	
}

//--------------------------------------------------------------------------------------------------------------------
//获取所要作废的空白发票信息，并修改屏幕显示
//--------------------------------------------------------------------------------------------------------------------
UINT8 CGInvLabelWin::BlankWasteShow()
{
	string strErr("");
	UINT8 ret =SUCCESS;
	UINT8 uFlag=0;
	if (0 == g_globalArg->m_curInvVol->m_curInvNo) //避免反复读盘
	{
		ret = SALE_GetCurInv(g_globalArg->m_curInvVol, strErr);
		if (ret == FAILURE)
		{
			if (strErr.length()>OBJ_TITLE_MAX_LEN)
			{
				strErr = strErr.substr(0,OBJ_TITLE_MAX_LEN);
			}
			label[0]->SetTitleAlign(CaObject::ALIGN_LEFT);
			sprintf(title_array[0], strErr.c_str()); //错误
			sprintf(title_array[1], "作废发票代码: 空");
			sprintf(title_array[2], "作废发票号码: 空");
			uFlag=1;
		}		
	}	
	if (0 == uFlag)
	{
		label[0]->SetTitleAlign(CaObject::ALIGN_CENTER);
		sprintf(title_array[0], "空白发票作废");
		sprintf(title_array[1], "作废发票代码:%s ", g_globalArg->m_curInvVol->m_code.c_str());
		sprintf(title_array[2], "作废发票号码:%08u", g_globalArg->m_curInvVol->m_curInvNo);	
	}	
	sprintf(title_array[3], "");
	sprintf(title_array[4], "");
	return SUCCESS;
}

//--------------------------------------------------------------------------------------------------------------------
//获取所要作废的已开发票信息，并修改屏幕显示
//--------------------------------------------------------------------------------------------------------------------
UINT8 CGInvLabelWin::UsedWasteShow(CInvHead *pInvHead)
{
	sprintf(title_array[0], "已开发票作废");	
	sprintf(title_array[1], "发票号码: %08d", pInvHead->m_fphm);	
	
	TDateTime tmpDate(pInvHead->m_kprq, pInvHead->m_kpsj);
    string strTmpDate = tmpDate.FormatString(YYYYMMDDHHMMSS);
	sprintf(title_array[2], "开票时间: %s", strTmpDate.c_str());

	switch(pInvHead->m_kplx)
	{
	case NORMAL_INV:
		m_invType = WASTE_NOR;
		sprintf(title_array[3], "类型: 正票");
		break;
	case RET_MANUAL_INV:
	case RET_SPECIAL_INV:
	case RETURN_INV:
		m_invType = WASTE_RET;
		sprintf(title_array[3], "类型: 红票");
		break;
	case WASTE_INV:
	case WASTE_NOR:
	case WASTE_RET:
		sprintf(title_array[3], "类型: 废票");
		break;
	default:;
	}

	if ((pInvHead->m_kplx==RETURN_INV)||(pInvHead->m_kplx==RET_MANUAL_INV)||(pInvHead->m_kplx==RET_SPECIAL_INV)) 
	{
		sprintf(title_array[4], "金额: -%.2lf", (double)(pInvHead->m_kphjje)/100.0);
	}
	else
	{
		sprintf(title_array[4], "金额: %.2lf", (double)(pInvHead->m_kphjje)/100.0);
	}
	
	return SUCCESS;
}

//--------------------------------------------------------------------------------------------------------------------
//红票开具时对应的Button1函数
//--------------------------------------------------------------------------------------------------------------------
void CGInvLabelWin::InvReturnBtn1()
{
	
	if (0==g_globalArg->m_curInvVol->m_curInvNo)
	{
		INVM_ErrMsgBox(INV_ZERO);
		return;	
	}
	
	UINT8 ret=SUCCESS;
	
	//检查是否满足负票条件
	DBG_PRINT(("m_pLInvHead->m_fphm= %u",m_pLInvHead->m_fphm));
	ret=INVM_CheckIsNoRet(m_pLInvHead);
	DBG_PRINT(("ret= %u",ret));
	if (ret !=SUCCESS)
	{
		INVM_ErrMsgBox(ret);
		return ;
	}
	DBG_PRINT(("m_pLInvHead->m_fphm= %u",m_pLInvHead->m_fphm));
	
	ret =INVM_InvRetProc(m_pLInvHead);	//退本机发票,m_pRtInvHead存储着要退发票的信息
	DBG_PRINT(("ret= %u",ret ));
	
	if (ret!=SUCCESS)
	{
		INVM_ErrMsgBox(ret);
		ChangeWin(GENERAL_INV_INPUT_WIN);
	}
	else
	{
		ChangeWin(INV_MANAGE_MENU);	 //返回发票管理界面				
	}
	
	return;
}

//--------------------------------------------------------------------------------------------------------------------
//空白发票作废对应的Button1函数
//--------------------------------------------------------------------------------------------------------------------
void CGInvLabelWin::InvBlankWasteBtn1()
{
	UINT8 ret=SUCCESS;
    //空白作废
	ret =INVM_InvWasteProc(); 
	DBG_PRINT(("ret= %u",ret ));
	
	if (ret != SUCCESS)
	{
		INVM_ErrMsgBox(ret);
		DBG_PRINT(("发票作废失败"));
		return;
	}
	
	CaMsgBox::ShowMsg("发票作废成功");
	DBG_PRINT(("发票作废成功"));
	DoActive();//刷新屏幕显示信息
	return;
}

//--------------------------------------------------------------------------------------------------------------------
//已开发票作废对应的Button1函数
//--------------------------------------------------------------------------------------------------------------------
void CGInvLabelWin::InvUsedWasteBtn1()
{
	UINT8 nRet = 0;
	string strErr("");
	if (g_globalArg->m_operator->m_role == DEMO_ROLE) 
	{
		CaMsgBox::ShowMsg("学习角色不能作废已开票");
		return;
	}
	nRet = CheckCancelValid();
	if (SUCCESS != nRet)
	{
		return;
	}
	
	CaMsgBox msgBox("是否作废?",CaMsgBox::MB_YESNO);
	msgBox.ShowBox();
	if (msgBox.m_iStatus != OK_PRESSED)
	{
		return;
	}
    else
	{
		CaProgressBar proBar("发票作废中.....");
		proBar.Show();
		m_pLInvHead->m_zskl = g_globalArg->m_strZskl;
		
		nRet = INVM_WstInv(m_pLInvHead, strErr);
		if (SUCCESS != nRet)
		{
			CaMsgBox::ShowMsg(strErr);
			ChangeWin(GENERAL_INV_INPUT_WIN);	 //返回INPUT界面
			return;
		}
		else
		{
			CaMsgBox::ShowMsg("发票作废成功");
			ChangeWin(GENERAL_INV_MTLBTN_WIN);	 //返回MultButton界面
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
	
	//若为废票，返回
    if( (WASTE_INV == pInvHead->m_kplx) || (WASTE_NOR == pInvHead->m_kplx)
		|| (WASTE_RET == pInvHead->m_kplx) )
    {
		CaMsgBox::ShowMsg("不能作废废票"); 
		return FAILURE;
    }
	
	//若为已退发票，返回
	memset((void*)val, 0, sizeof(val));
	sprintf(val,"where FPDM = '%s' and FPHM = %u",pInvHead->m_fpdm.c_str(), pInvHead->m_fphm);	
	DBG_PRINT(("val = %s", val));
	CRtInv rtInv;
	rtInv.m_filter = val;
	rtInv.Requery();
	
	DBG_PRINT(("m_pInvHead->m_bzkz = %s", pInvHead->m_bzkz.c_str()));
	if (rtInv.LoadOneRecord() == SQLITE_OK)//一张正票已被冲红则不能作废，但相应的红票可以作废
	{
		CaMsgBox::ShowMsg("该票已开红票"); 
		return FAILURE;
	}
	
	return SUCCESS;
}

