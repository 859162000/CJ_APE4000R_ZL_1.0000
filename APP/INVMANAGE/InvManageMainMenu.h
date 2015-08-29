/*! \file    InvManageMainMenu.h
   \brief    awe4000r��Ʊ��������˵�
   \author   Yu Yan 
   \version  1.0
   \date     2008-01-31
 */

#ifndef INVMANAGE_MENU_H
#define INVMANAGE_MENU_H

//#include "InvManageFunc.h"
#include "CMainFrame.h"
#include "MultiBtnCommonWin.h"
#include "CaLabel.h"
#include "CaButton.h"
#include"pos_debug.h"
#include "g_def.h"
#include <string>
using namespace std;

#define	INV_DIST_QUERY_L1	1	//����ѯ����
#define	INV_WLLQFP_L1		2	//������ȡ��Ʊ����
#define	INV_RET_QUERY_L1	3	//��Ʊ���߲�ѯ����
#define	INV_BLK_WASTE_L1	4	//�հ׷�Ʊ���Ͻ���
#define	INV_USEWST_QUERY_L1	5	//�ѿ���Ʊ���ϲ�ѯ����
#define	INV_STUB_QUERY_L1	6	//��Ʊ�����ѯ����
#define	INV_DETAIL_NO_L1	7	//���ݺ���β�ѯ��Ʊ��ϸ����
#define	INV_DISTRIBUTE_L1	8	//��Ʊ�ַ�����(������ֻ��ַ�)
#define	INV_RETREAT_L1		9	//��Ʊ�˻ؽ���(�ֻ�����Ʊ��ƱԴ���˻ر�˰��)

#define	INV_WASTE_BTN_L0	1	//��Ʊ����������
#define	INV_DETAIL_BTN_L0	2	//��Ʊ��ϸ��ѯ������

/**
 *@class CInvManageMenu 
 *@brief ��Ʊ��������˵�
 */
class CInvManageMenu : public CMultiBtnCommonWin
{
public:
	UINT8 m_InvWin_level1;//��Ʊ��������һ��ѡ���־
	UINT8 m_InvWin_level0;//��Ʊ���������㼶ѡ���־,���generalMtlBtn�������
public:
	/*!
	@brief ���캯��
	*/
	CInvManageMenu();

	/*!
	@brief �鹹����
	*/
	~CInvManageMenu();

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
	@brief ��ֽ	
	@return  1: SUCCESS; 0: FAILURE
	*/
	UINT8 ForwardKeyProc();

private:

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
	@brief ��ť3��Ӧ����	
	@param[in] iEvent �¼����
	@param[in] pEventData �¼�����
	@param[in] iDataLen �¼����ݳ���
	*/
	void OnButton3(int iEvent, unsigned char * pEventData, int iDataLen);

	/*!
	@brief ��ť4��Ӧ����	
	@param[in] iEvent �¼����
	@param[in] pEventData �¼�����
	@param[in] iDataLen �¼����ݳ���
	*/
	void OnButton4(int iEvent, unsigned char * pEventData, int iDataLen);
	
	/*!
	@brief ��ť5��Ӧ����	
	@param[in] iEvent �¼����
	@param[in] pEventData �¼�����
	@param[in] iDataLen �¼����ݳ���
	*/
	void OnButton5(int iEvent, unsigned char * pEventData, int iDataLen); 

	/*!
	@brief ��ť6��Ӧ����	
	@param[in] iEvent �¼����
	@param[in] pEventData �¼�����
	@param[in] iDataLen �¼����ݳ���
	*/
	void OnButton6(int iEvent, unsigned char * pEventData, int iDataLen);

	/*!
	@brief ��ť7��Ӧ����	
	@param[in] iEvent �¼����
	@param[in] pEventData �¼�����
	@param[in] iDataLen �¼����ݳ���
	*/
	void OnButton7(int iEvent, unsigned char * pEventData, int iDataLen);

		/*!
	@brief ��ť6��Ӧ����	
	@param[in] iEvent �¼����
	@param[in] pEventData �¼�����
	@param[in] iDataLen �¼����ݳ���
	*/
	void OnButton8(int iEvent, unsigned char * pEventData, int iDataLen);

			/*!
	@brief ��ť6��Ӧ����	
	@param[in] iEvent �¼����
	@param[in] pEventData �¼�����
	@param[in] iDataLen �¼����ݳ���
	*/
//	void OnButton9(int iEvent, unsigned char * pEventData, int iDataLen);

	/*!
	@brief ��ť6��Ӧ����	
	@param[in] iEvent �¼����
	@param[in] pEventData �¼�����
	@param[in] iDataLen �¼����ݳ���
	*/
// 	void OnButton10(int iEvent, unsigned char * pEventData, int iDataLen);



};


#endif
