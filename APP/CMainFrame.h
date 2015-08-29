/* Generated by Together */

#ifndef CMAINFRAME_H
#define CMAINFRAME_H
#include "PosFrame.h"

//__SYS_PLATFORM 0:平推 1:卷式
#define __SYS_PLATFORM 0

typedef enum _WINDOW{ 
					SYSTEM=0, 
					LOGIN_WIN,
					SYSTEM_MAIN_MENU,
					PRODUCT_SALE_MAIN_MENU,
					PRODUCT_SALE_WIN,
					INV_MANAGE_MENU,
					INV_STUB_PRN_WIN,
					INV_SEG_MENU,
					GENERAL_INV_INPUT_WIN,
					GENERAL_INV_LABEL_WIN,
					GENERAL_INV_MTLBTN_WIN,
//					//InvManage end
//
//					//Maintenance
					MAINTENANCE_MENU,
					CLEAR_DEPOT_WIN,
					SELF_TEST_MENU,
					CHANGE_DATETIME_WIN,
					DOWNLOAD_MAC_WIN,
					UPDATE_MACHINE_INFO_WIN,
//					//Maintenance end
//
//					//Report
					REPORT_MAIN_MENU,
					BASIC_REPORT_MENU,
					FISCAL_REPORT_MENU,
					MACHINE_INFO_WIN,
					CORP_INFO_WIN,
					INV_KIND_INFO_WIN,
					TAX_INFO_WIN,
					TIME_SUM_DATE_WIN,
					TIME_SUM_INFO_WIN,
					VOL_SUM_INFO_WIN,
					VOL_SUM_NO_WIN,
					SYS_LOG_DATE_WIN,
					COMMERCE_REPORT_MENU,
					DAY_SALE_SUM_WIN,
					MONTH_SALE_SUM_WIN,	
					MONTH_SALE_SHOW_WIN,
					ISSUE_SUM_DATE_WIN,
                    INV_CHECK_OLD_PRN_WIN,
//					//Report end
//
//					//added by ZL
					ERR_UP_INV_WIN, 
					PROGRAM_CTRL_MAIN_MENU,
					DEPT_EDIT_WIN,
					OPERATOR_EDIT_WIN,
					SYSTEM_ARG_MENU,
					SYS_ARG_EDIT_WIN,
//					DATA_TRANS_WIN,
//					APDU_TEST_WIN,
					CLIENT_EDIT_WIN,
					SYSTEM_UPGRADE_WIN,
					DATA_IO_MENU,
//					MAX_MONEY_EDIT_WIN,
					INPUT_CORP_WIN,
//					TEMPLATE_TRANS_MENU,
//					NET_MANAGE_MENU,
//					NETWORKING_SET_WIN,
//					NET_SERVER_SET_WIN,
//					NET_WLEN_CARD_WIN,
					PASSWD_EDIT_WIN,
//					WIRELESS_VIEW_WIN,
//					WIRELESS_INFO_WIN,
					SELF_DEF_WIN,
//					NETMODEL_EDIT_WIN,
				//	ADSLINFO_SET_WIN,
					SYSTEM_MESSAGE_WIN, //通知信息
					INIT_EDIT_WIN,  //初始化编辑
					//added end

					FISCAL_MAIN_MENU,
					INFO_UPDATE_MENU,
					MEDIUM_DECLARE_MENU,
					NET_DECLARE_MENU,
					CHANGE_DISK_PSW_WIN,

					//net module window
					ADSLINFO_SET_WIN,
					APN_ACCPOINT_SET_WIN,
					LOCAL_NETWORK_MENU,
					M2M_MANAGE_MENU,
					NET_3G_WLEN_MENU,
					NET_3GWLEN_SET_WIN,
					NET_IP_MODEL_WIN,
					NET_MANAGE_MENU,
					NETMODEL_EDIT_WIN,
					NET_MODE_SET_MENU,
					NET_SERVER_SET_WIN,
					NET_SERV_MENU,
					NET_WLEN_CARD_WIN,
					NETWORKING_SET_WIN,
					NETWORKING_SHOW_WIN,
					NETWORK_SET_MENU,
					VPN_INFO_SET_WIN,
					WIRELESS_VIEW_WIN,
					WIRELESS_INFO_WIN,
					NET_AUTO_DIAL_SET_WIN,
					ZHQ_MANAGE_MENU,
					ZHQ_BTL_SET_WIN,
					ZHQ_FTP_SET_WIN,
					ZHQ_IPADDR_SET_WIN,
					ZHQ_SERVERIP_SET_WIN,
					FPBL_WIN,
					HQLXSJ_WIN
					
					//net module window end

} WINDOW_ID;    //新增拼音窗口

typedef enum _Menu{ZHENG_SHU_FP_TIANKAI_INDEX = 1,FU_SHU_FP_TIANKAI_INDEX,YI_KAI_FP_CHAXUN_INDEX,YI_KAI_FP_ZUOFEI_INDEX,
		WEI_KAI_FP_ZUOFEI_INDEX,YI_GOU_FP_TUI_HUI_INDEX,FP_KU_CUN_CHA_XUN_INDEX,YUE_DU_ZI_LIAO_TONG_JI_INDEX,NIAN_DU_ZI_LIAO_TONG_JI_INDEX,
		LING_YONG_CUN_YUE_DU_BAO_BIAO_INDEX,FP_ZI_LIAO_CHA_XUN_INDEX,JSK_ZHUANG_TAI_CHA_XUN_INDEX,IC_ZHUANG_TAI_CHA_XUN_INDEX
}Menu_ID;

class CMainFrame : public CPosFrame {
public:
	virtual int ProcEvent(int iEvent, unsigned char *pEventData, int iDataLen);
	virtual CaWindow *GetWin(int id);
	virtual bool Create();
	virtual const char* GetWinName(int id);
	virtual CaWindow *CreateWin(int id);
	virtual void ChangeWin( int id);
//	virtual void ChangeWin( CaWindow *win);
//	virtual void ChangeWin( int id);
	virtual CaWindow *IsWinExist(int id);
public:    

    virtual ~CMainFrame();    
    CMainFrame();
};
#endif //CMAINFRAME_H



