#ifndef __VERSION_CONFIG_H
#define __VERSION_CONFIG_H


//////////////////////////////////////////////////////////////////////////
//  款机连接设备
//////////////////////////////////////////////////////////////////////////

#define		SKJ_MODE		1		//收款机直连调用接口
#define		ZHQ_MODE		2		//转换器方式调用接口

#define    TYPE_MODE	SKJ_MODE     //连接方式

//////////////////////////////////////////////////////////////////////////
//  款机型号定义
//////////////////////////////////////////////////////////////////////////

#define 	POS_APE3000R	1
#define     POS_APE4000R	2
#define 	POS_APE4020R	3
#define 	POS_APE5020R	4
#define 	POS_APE4000RG	5

#define 	POS_TYPE	POS_APE4000RG     //款机类型

//////////////////////////////////////////////////////////////////////////
//  款机设置
//////////////////////////////////////////////////////////////////////////

#ifndef POS_TYPE
#define POS_TYPE	POS_APE4000R     //款机类型
#endif

// #ifndef TYPE_MODE
// #define TYPE_MODE	ZHQ_MODE     
// #endif

//////////////////////////////////////////////////////////////////////////
//  软件版本定义
//////////////////////////////////////////////////////////////////////////

#define SOFTWARE_VERSION		1.400032	/**< 软件版本号(对应debug版本号：1.110013) */

#define RELEASE_VER				0  /**< 1: 发布版本，0: 测试版本 */


//////////////////////////////////////////////////////////////////////////
//  款机串口定义
//////////////////////////////////////////////////////////////////////////
#if (POS_TYPE == POS_APE4020R)
#define UART				UART2
#define UART_DEV_NAME		UART2_DEV_NAME
#elif(POS_TYPE == POS_APE5020R)
#define UART				UART0
#define UART_DEV_NAME		UART0_DEV_NAME
#else
#define UART				UART3
#define UART_DEV_NAME		UART3_DEV_NAME
#endif

//////////////////////////////////////////////////////////////////////////
//  款机硬件宏定义
//////////////////////////////////////////////////////////////////////////
#define	KEYPAD_TYPE				1	/**< 键盘硬件版本，1: 新版键盘（shift与部类5对调，T9输入法键位调整），0: 老版键盘 */

#if ((POS_TYPE !=POS_APE4000R)&&(POS_TYPE !=POS_APE4000RG))		//非4000R机型KEYPAD_TYPE必须为1 不可更改
#undef KEYPAD_TYPE
#define	KEYPAD_TYPE				1
#endif

//////////////////////////////////////////////////////////////////////////
//  一些业务类型的宏定义
//////////////////////////////////////////////////////////////////////////

#define	CORP_NAME_LEN_TPYE		0	/**< 纳税户名称长度类型 1: 200字节，0: 40字节 */
#define ON_LINE                 0   /**< 1:纯在线开票模式   0：允许离线开票模式 */    

//互斥控制  0-转换器  1-直连XML  2-直连裁剪代码
#define SKJ_PTHREAD_KPMUTEX_OPEN		2


#define PRN_ADDR_TEL            1   /**< 1: 支持打印收款单位地址和电话 0: 不支持*/
#define VOL_INV_PRN             1   /**< 1: 卷票打印  0: 平推票打印*/
#endif
