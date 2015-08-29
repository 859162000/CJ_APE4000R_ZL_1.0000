#ifndef __CINV_HEAD_H
#define __CINV_HEAD_H

#include "CTable.h"
#include "CDB.h"
#include "CInvDet.h"
#include "SysMacDef.h"

/**
 *@class CInvHead 
 *@brief ��Ʊ������Ϣ��
 *@brief 
 */
class CInvHead : public CTable
{
public:
    
	/*!
	@brief ���캯��	
	@attention   ���ע��
	*/ 
	CInvHead();

    /*!
	@brief ��������	
	*/
	~CInvHead();

	/*!
	@brief ��ȡָ�����ڵ����ݿ�����
	@attention ����ǰ���Ƚ�pHead��ָ�����ռ��ͷš�
	@attention ��ѯ���������ݿ�����д������Ա������.����Ҫ�ȵ���Requery().
	@return SQLITE_OK:�ɹ���SQLITE_DONE��δ�ҵ�ƥ����������ֵ��ʧ�ܣ�
	*/
	INT32 Load();

	/*!
	@brief �洢���ݵ����ݿ⣨INV_HEAD��INV_DET����
	@attention ����֮ǰ��INV_DET�����������Ѿ����ɣ��ҽڵ��ѱ���ֵ��
	@return sqlite3 errorcode
	*/
	INT32 Save();

	/*!
	@brief �ж��Ƿ�����������ڼ�¼̫��ʱ���Ƿ�ɾ�����ּ�¼
	@param[in] nCount ��ʵ�ʴ洢�ļ�¼����
	@param[in] strRefDate �ϴ��걨���ݵĽ�ֹ����
	@param[out] nDelDate ʵ��Ҫɾ����¼�Ľ�ֹ����
	@return  0 ʧ�ܣ�  1 �ɹ�
	*/
	INT32 CheckRoll(INT32 nCount, UINT32 strRefDate, UINT32 &nDelDate);

	/*!
	@brief ɾ�����ּ�¼
	@param[in] nDelDate ʵ��Ҫɾ����¼�Ľ�ֹ����
	@return  0 ʧ�ܣ�  1 �ɹ�
	*/
	INT8 DeleteRecord(UINT32 nDelDate);

	/*!
	@brief ��������
	@param[in] nDelDate ʵ��Ҫɾ����¼�Ľ�ֹ����
	@param[in] strRefDate �ϴ��걨���ݵĽ�ֹ����
	@return  0 ʧ�ܣ�  1 �ɹ�
	*/
	INT32 Roll(UINT32 nDelDate,  UINT32 strRefDate);


    /*!
	@brief ͳ��ĳ�޶������¸���Ʊ���͵Ŀ�Ʊ����
	@param[out] norInv ��Ʊ����
	@param[out] recInv ��Ʊ����
	@param[out] canInv ��Ʊ����
	@return  SQLITE_OK �ɹ������������ݿ�����������
	@attention ��m_filter�����޶�����
	*/
	INT32 GetInvoiceSum(UINT32 &norInv, UINT32 &recInv, UINT32 &canInv);

	/*!
	@brief ͳ��INV_HEAD���洢�ķ�Ʊ��
	@return  >=0: ��Ʊ��; -1: ͳ��ʧ��
	@attention ��m_filter�����޶�����
	*/
	INT32 GetInvHeadNum();
	UINT32 GetInvNumByDate();
 
//-------��������
    /*!
	@brief �����½ڵ�
	@param[in]  pNew  �½ڵ��ָ��
	@return 1  �ɹ��� 0  ʧ��
	*/
	INT32 InsertNode(CInvDet *pNew);

    /*!
	@brief ��������	
	@attention  ����ÿ���ڵ㣬���ڵ��Խ��������һ���ֶε�ֵ
	*/
	INT32 ShowList();

	/*!
	@brief ɾ���ڵ�	
	@param[in]  pCode  ��ɾ���ڵ����Ʒ����
	@attention  ɾ�����������ĵ�һ���ڵ�
	@return 1  �ɹ��� 0  ʧ��
	*/
	INT32 DelNode(string &pCode);

	/*!
	@brief ɾ���ڵ�	
	@param[in]  dpNo  ��ɾ���ڵ�Ĳ����
	@attention  ɾ�����������ĵ�һ���ڵ�
	@return 1  �ɹ��� 0  ʧ��
	*/
//	INT32 DelNode(UINT8 dpNo);

	/*!
	@brief ɾ�����һ���ڵ�	
	@return SUCCESS  �ɹ��� FAILURE  ʧ��
	*/
	INT32 DelLastNode();

	/*!
	@brief ɾ���������ͷ������ռ�	
	@return 1  �ɹ��� 0  ʧ��
	*/
	INT32 DelList();

	/*!
	@brief �����ڵ�	
	@param[in]  pCode  ��ɾ���ڵ����Ʒ����
	@return ��NULL  �������Ľڵ�ָ�룬 NULL ʧ��
	*/
	CInvDet* SearchNode(string &pCode);

	/*!
	@brief �����ڵ�	
	@param[in]  dpNo  ��ɾ���ڵ�Ĳ����
	@return ��NULL  �������Ľڵ�ָ�룬 NULL ʧ��
	*/
//	CInvDet* SearchNode(UINT8 dpNo);


	UINT32 m_no; 			/**< ������ */
	string m_fpdm;			/**< ��Ʊ���� */
	UINT32 m_fphm;			/**< ��Ʊ���� */
	UINT32 m_kprq;			/**< ��Ʊ���� */
	UINT32 m_kpsj;			/**< ��Ʊʱ�� */
	UINT8  m_kplx;			/**< ��Ʊ����(�����ϡ���Ʊ) */
	INT64  m_kphjje;		/**< ��Ʊ�ϼƽ��(��˰) */
	INT64  m_kpse;		    /**< ��Ʊ˰�� */
	string m_yfpdm;			/**< ԭ��Ʊ���� */
	UINT32 m_yfphm;			/**< ԭ��Ʊ���� */
	string m_fkdw;			/**< ���λ */
	string m_fkdwsh;        /**< ���λ˰�� */
	string m_sky;			/**< �տ�Ա */
	UINT32 m_sphsl;			/**< ��Ʒ������ */
	string  m_fwm;			/**< ��α˰���� */
	UINT8 m_fplb;		     /**< ��Ʊ���(��Ʊ41 ) */
	UINT8  m_scbz;			/**< �ϴ���־ */
	string m_bzkz;          /**< ��ע��չ (0--δ����죬1--�ѱ����)*/

	INT64 m_kpje;			/**< ��Ʊ������˰�� */

    string m_fpsyh;           /**< ��Ʊ������*/
	string m_casign;			/**< CAǩ��*/
	
	string m_backup1;		/**< ����1 */
	string m_backup2;		/**< ����2 */
//	string m_backup3;		/**< ����3 */

//�������ݿ�
	string m_zskl;			//֤�����
	float  m_sl;			/**< ˰�� */
	UINT32 m_dycs;			/**< ��ӡ���� */
	string m_skr;			/**< �տ��� */
	UINT8  m_zfbz;			/**<  ���ϱ�־*/
	UINT32 m_zfrq;			/**<  ��������*/
	UINT32 m_zfsj;			/**<  ����ʱ��*/
	string  m_hczt;          /**< ����־*/ 
	string m_hyfl;			/**< ��ҵ���� */

    CInvDet *pHead;			/**< ��Ʒ��ϸ����ͷ */
	CInvDet *pEnd;			/**< ��Ʒ��ϸ����β�� */
	CInvDet m_InvDet;		/**< ��Ʒ��ϸ�ӱ� */
	CInvDet *m_pInvDet;		/**< ��Ʒ��ϸ�ӱ�ָ�� */
	string m_xfmc;      /**< �������� */
	string m_xfsh;      /**< ����˰�� */
};

#endif