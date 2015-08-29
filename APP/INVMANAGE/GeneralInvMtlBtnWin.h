
/*! \file    GeneralInvMtlBtnWin.h
   \brief    awe4000r��Ʊ�����Ķఴť���ý���
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
 *@brief ��Ʊ���ϵ����˵�
 */
class CGInvMtlbtnWin : public CMultiBtnCommonWin
{
public:

	UINT8 m_level0;				//��Ʊ���������㼶ѡ���־�ڹ���MtlBtn����Ķ�Ӧ����

	/*!
	@brief ���캯��
	*/
	CGInvMtlbtnWin();

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

private:

	/*!
	@brief ������ʾ���ݵľ�̬����	 
	*/
	static void S_OnActive(CaWindow *obj);
    
	/*!
	@brief ������ʾ���ݵĺ���	 
	*/
	void DoActive(); 

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

};


#endif
