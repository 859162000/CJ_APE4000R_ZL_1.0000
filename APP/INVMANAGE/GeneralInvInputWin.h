/*! \file    GeneralInvInputWin.h
   \brief    awe4000r��Ʊ���������빫�ý���
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

#define	INV_RETURN_L2	1	//��Ʊ����
#define	INV_USEWST_L2	2	//�ѿ���Ʊ����
#define	INV_StubPrn_L2	3	//��Ʊ�����ӡ

/**
 *@class CGInvInputWin 
 *@brief ���빫�ý���
 */
class CGInvInputWin : public CaWindow
{
public:
	char title_array[4][OBJ_TITLE_MAX_LEN + 1];	/**< ��ǩ�ı���*/

	CaLabel *label;					/**< ָ���ǩ��ָ�� */
	CaInput *m_pInput1;				/**< ָ����������ָ�� */  
	CaInput *m_pInput2;				/**< ָ����������ָ�� */
	CaInput *m_pInput3;				/**< ָ����������ָ�� */  
	CaButton *m_pBtn1;				/**< ָ��ť��ָ�� */
	CaButton *m_pBtn2;				/**< ָ��ť��ָ�� */
	
	int m_iBtnW;					/**< ����ʱ���ؼ��Ŀ�� */  
	int m_iColW;					/**< ����ʱ���ڶ��еĺ����� */  
 
	string m_invCode;               /**< ��Ʊ���� */ 
	UINT32 m_invStartNo;			/**< ��Ʊ��ʼ���� */ 
	UINT32 m_invEndNo;				/**< ��Ʊ��ֹ���� */ 
	UINT32 m_invNum;				/**< ��Ʊ���� */ 
	UINT8  m_nFlag;                 /**< 0:��Ʊ��ѯ��1:��Ʊ����,������β�ѯ��Ʊ��ϸר��*/

	CInvHead *m_pInvHead, m_Invhead;             /**< ��ѯ��Ʊ��Ϣ*/

	UINT8 m_level1;					//��Ʊ��������һ��ѡ���־�ڹ���Input����Ķ�Ӧ����
	UINT8 m_InvWin_level2;			//��Ʊ�������ڶ���ѡ���־


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
	@brief ���캯��	
	*/
	CGInvInputWin();

	/*!
	@brief ��������Ӧ����	
	@param[in] iEvent �¼����
	@param[in] pEventData �¼�����
	@param[in] iDataLen �¼����ݳ���
	*/
	void OnInput1(int iEvent, unsigned char * pEventData, int iDataLen);

	/*!
	@brief ��������Ӧ����	
	@param[in] iEvent �¼����
	@param[in] pEventData �¼�����
	@param[in] iDataLen �¼����ݳ���
	*/
	void OnInput2(int iEvent, unsigned char * pEventData, int iDataLen);

	/*!
	@brief ��������Ӧ����	
	@param[in] iEvent �¼����
	@param[in] pEventData �¼�����
	@param[in] iDataLen �¼����ݳ���
	*/
	void OnInput3(int iEvent, unsigned char * pEventData, int iDataLen);

	/*!
	@brief ��ť��Ӧ����	
	@param[in] iEvent �¼����
	@param[in] pEventData �¼�����
	@param[in] iDataLen �¼����ݳ���
	*/
	void OnButton1(int iEvent, unsigned char * pEventData, int iDataLen);

	/*!
	@brief ��ť��Ӧ����	
	@param[in] iEvent �¼����
	@param[in] pEventData �¼�����
	@param[in] iDataLen �¼����ݳ���
	*/
	void OnButton2(int iEvent, unsigned char * pEventData, int iDataLen);
	
	/*!
	@brief ������ʾ���ݵľ�̬����	 
	*/
	static void S_OnActive(CaWindow *obj);
    
	/*!
	@brief ������ʾ���ݵĺ���	 
	*/
	void DoActive(); 

	/*!
	@brief �ı�Label �� Input��������titleֵ	
	@return  1: SUCCESS; 0: FAILURE
	*/
	UINT8 ChangeTitle();

	/*!
	@brief ������ȡ��Ʊ��ʼ��Ļ��ʾ
	*/
	void InvWllqfpShow();

	/*!
	@brief ��Ʊ���߲�ѯ��ʼ��Ļ��ʾ
	*/
	void InvRetQueryShow();

	/*!
	@brief �ѿ���Ʊ���ϲ�ѯ��ʼ��Ļ��ʾ
	*/
	void InvUsewstQueryShow();

	/*!
	@brief ��Ʊ�����ѯ��ʼ��Ļ��ʾ
	*/
	void InvStubQueryShow();

	/*!
	@brief ����Ʊ�����ѯ��Ʊ��ϸ��ʼ��Ļ��ʾ
	*/
	void InvDetailNoQueryShow();

	/*!
	@brief ��Ʊ�ַ���ʼ��Ļ��ʾ
	*/
	void InvDistributeShow();

	/*!
	@brief ��Ʊ�˻س�ʼ��Ļ��ʾ
	*/
	void InvRetreatShow();
	
private:

	/*!
	@brief ��������Ӧ�ľ�̬����
	@param[in] obj �ؼ�ָ��
	@param[in] iEvent �¼����
	@param[in] pEventData �¼�����
	@param[in] iDataLen �¼����ݳ���
	*/
	static void S_OnInput1(CaObject *obj,int iEvent, unsigned char * pEventData, int iDataLen);
	
	/*!
	@brief ��������Ӧ�ľ�̬����
	@param[in] obj �ؼ�ָ��
	@param[in] iEvent �¼����
	@param[in] pEventData �¼�����
	@param[in] iDataLen �¼����ݳ���
	*/
	static void S_OnInput2(CaObject *obj,int iEvent, unsigned char * pEventData, int iDataLen);
	
	/*!
	@brief ��������Ӧ�ľ�̬����
	@param[in] obj �ؼ�ָ��
	@param[in] iEvent �¼����
	@param[in] pEventData �¼�����
	@param[in] iDataLen �¼����ݳ���
	*/
	static void S_OnInput3(CaObject *obj,int iEvent, unsigned char * pEventData, int iDataLen);

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
   
	/*!
	@brief ������������յ�ֵ�Ƿ���Ч	
	@return   1  ������Ч�� 0 ������Ч
	*/
	UINT8 CheckInputValid( );

	/*!
	@brief ������ȡ��Ʊ��Ӧ��Buttton1����	
	@return   1  ������Ч�� 0 ������Ч
	*/
	void InvWllqfpBtn1();

	/*!
	@brief ��Ʊ���߲�ѯ��Ӧ��Buttton1����	
	@return   1  ������Ч�� 0 ������Ч
	*/
	void InvReturnQueryBtn1();

	/*!
	@brief �ѿ���Ʊ��ѯ��Ӧ��Buttton1����	
	@return   1  ������Ч�� 0 ������Ч
	*/
	void InvUsewstQueryBtn1();

	/*!
	@brief ��Ʊ�����ѯ��Ӧ��Buttton1����	
	@return   1  ������Ч�� 0 ������Ч
	*/
	void InvStubQueryBtn1();

	/*!
	@brief ����Ʊ�����ѯ��Ʊ��ϸ��Ӧ��Buttton1����	
	@return   1  ������Ч�� 0 ������Ч
	*/
	void InvDetailNoQueryBtn1();

	/*!
	@brief ��Ʊ�ַ���Ӧ��Buttton1����	
	@return   1  ������Ч�� 0 ������Ч
	*/
	void InvDistributeBtn1();

	/*!
	@brief ��Ʊ�˻ض�Ӧ��Buttton1����	
	@return   1  ������Ч�� 0 ������Ч
	*/
	void InvRetreatBtn1();
};


#endif
