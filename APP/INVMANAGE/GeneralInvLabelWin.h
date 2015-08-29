/*! \file    GeneralInvLabelWin.h
   \brief    awe4000r��Ʊ��������Ϣ��ʾ���ý���
   \author   Yu Yan
   \version  1.0
   \date     2008-2-22
 */

#ifndef _GENERAL_INV_LABEL_WIN_H
#define _GENERAL_INV_LABEL_WIN_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#ifdef WIN32
#include <conio.h>
#endif

#include "IncludeMe.h"
#include "CaWindow.h"
#include "LOGCTRL.h"
#include "pos_debug.h"
#include "g_def.h"
#include "CaLabel.h"
#include "CMainFrame.h"
#include "CaInput.h"
#include "CaButton.h"

#include "CInvVol.h"
#include "CInvHead.h"
#include "SysMacDef.h"

/**
 *@class CGInvLabelWin 
 *@brief ��Ʊ�����ķַ���ѯ����
 */
class CGInvLabelWin : public CaWindow
{
public:
	char title_array[5][OBJ_TITLE_MAX_LEN + 1];	/**< ��ǩ�ı���*/

	CaLabel *label[5];							/**< ָ���ǩ��ָ�� */
	
	CaButton *m_pBtn1, *m_pBtn2;				/**< ָ��ť��ָ�� */
	        	
	int m_iBtnW;								/**< ����ʱ���ؼ��Ŀ�� */  
	int m_iColW;								/**< ����ʱ���ڶ��еĺ����� */  
	int m_curH;

	UINT32 m_pageIndex;							/**< ��ǰҳ��*/
	UINT32 m_pageNum;							/**< ��ҳ����*/
	CInvVol *m_pInvVol, m_Invvol;				/**< ��Ʊ������Ϣ*/
	CInvHead *m_pLInvHead, m_LInvhead;          /**< ��ѯ��Ʊ��Ϣ*/
	UINT8  m_invType;							/**< ��Ʊ����,�ѿ���Ʊ����ר�� */


	UINT8 m_flag1;				//��Ʊ��������һ��ѡ���־�ڹ���Label����Ķ�Ӧ����
	UINT8 m_level2;				//��Ʊ�������ڶ���ѡ���־�ڹ���Label����Ķ�Ӧ����

private:

	/*!
	@brief ��ť��Ӧ�ľ�̬����
	@param[in] obj �ؼ�ָ��
	@param[in] iEvent �¼����
	@param[in] pEventData �¼�����
	@param[in] iDataLen �¼����ݳ���
	*/
	static void S_OnButton1(CaObject *obj,int iEvent, unsigned char * pEventData, int iDataLen);
	
	/*!
	@brief ��ť��Ӧ�ľ�̬����
	@param[in] obj �ؼ�ָ��
	@param[in] iEvent �¼����
	@param[in] pEventData �¼�����
	@param[in] iDataLen �¼����ݳ���
	*/
	static void S_OnButton2(CaObject *obj,int iEvent, unsigned char * pEventData, int iDataLen);

public:

	/*!
	@brief ��������	
	@param iX ���ϽǺ�����
	@param iY ���Ͻ�������
	@param iW ���
	@param iH �߶�
	@return 1 ���ɹ���������ʧ��
	*/
	int Create(int iX,int iY,int iW,int iH);

	/*!
	@brief �����¼�	
	@param[in] iEvent �¼����
	@param[in] pEventData �¼�����
	@param[in] iDataLen �¼����ݳ���
	@return   1  �Ѵ��� 0 �޷�����
	*/
	int ProcEvent(int iEvent,unsigned char *pEventData, int iDataLen);

	/*!
	@brief ˢ�´�����ʾ	
	@return 1: SUCCESS
	*/
	virtual int ReFresh();

	/*!
	@brief ��ť1��Ӧ����	
	@param[in] iEvent �¼����
	@param[in] pEventData �¼�����
	@param[in] iDataLen �¼����ݳ���
	*/
	void OnButton1(int iEvent, unsigned char * pEventData, int iDataLen);

	/*!
	@brief ��ť2��Ӧ����	
	@param[in] iEvent �¼����
	@param[in] pEventData �¼�����
	@param[in] iDataLen �¼����ݳ���
	*/
	void OnButton2(int iEvent, unsigned char * pEventData, int iDataLen);

	/*!
	@brief ���캯��	
	*/
	CGInvLabelWin();

	/*!
	@brief ��������	
	*/
	virtual ~CGInvLabelWin();
    
	/*!
	@brief ������ʾ���ݵľ�̬����	 
	*/
	static void S_OnActive(CaWindow *obj);
    
	/*!
	@brief ������ʾ���ݵĺ���	 
	*/
	void DoActive(); 

	
	/*!
	@brief �ı�Label��������titleֵ	
	@return  1: SUCCESS; 0: FAILURE
	*/
	UINT8 ChangeTitle();

	/*!
	@brief ��ȡδ���뷢Ʊ����Ϣ�����޸���Ļ��ʾ
	@param[in] pInvVol ��Ʊ���¼��ָ��
	@param[in] nPageIndex  ������Ļ��ʾ��ҳ���
	@return  1: SUCCESS; 0: FAILURE
	*/
	UINT8 QueryShow(CInvVol *pInvVol, UINT32 nPageIndex);

	/*!
	@brief ��Ʊ�˻�ʱ����Ļ��ʾ
	@param[in] invHead    ���˷�Ʊ
	@return  1: SUCCESS; 0: FAILURE
	*/
	UINT8 ReturnShow(CInvHead *pInvHead);

	/*!
	@brief �հ׷�Ʊ����ʱ����Ļ��ʾ
	@return  1: SUCCESS; 0: FAILURE
	*/
	UINT8 BlankWasteShow();

	/*!
	@brief �ѿ���Ʊ����ʱ����Ļ��ʾ
	@return  1: SUCCESS; 0: FAILURE
	*/
	UINT8 UsedWasteShow(CInvHead *pInvHead);

	/*!
	@brief ��Ʊ�˻ض�Ӧ��Buttton1����
	@return
	*/
	void InvReturnBtn1();

	/*!
	@brief �հ׷�Ʊ���϶�Ӧ��Buttton1����
	@return
	*/
	void InvBlankWasteBtn1();

	/*!
	@brief �ѿ���Ʊ���϶�Ӧ��Buttton1����
	@return
	*/
	void InvUsedWasteBtn1();
	/*!
	@brief ����ѿ���Ʊ�ܷ�����
	@return  1: SUCCESS; ����: �������
	*/
	UINT8 CheckCancelValid();
};

#endif
