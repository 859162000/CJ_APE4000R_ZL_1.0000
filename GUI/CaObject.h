/* Generated by Together */

#ifndef CAOBJECT_H
#define CAOBJECT_H
#include "LOGCTRL.h"

#ifdef WIN32
#define LCDRedraw()
#endif

#ifdef WIN32

	extern "C"
	{
		extern  int LCD_Init(void);
		extern void LCDClearDisplay(void);
		extern void LCDPutImage(int x0, int y0, int w, int h, char *buf);
		extern int LCDFillRect(int x0, int y0, int w, int h, int color);
		extern void str2image(unsigned char *str, int len, unsigned char *buffer);
		//extern int is_gb(unsigned char *str);
		//extern void LCDClearDisplay(void);
		extern void LCDPutImageRev(int x0, int y0, int w, int h, char *buf);
		extern int LCDFillRectLine(int x0, int y0, int w, int h, int color);
		extern void WB_LCM_BKL_ON(void); 
	}
	#include<string.h>

#else //for linux
#include "lcd_tiny.h"
#include "display.h"
extern "C"
{
void LCDFillRect(int x0, int y0, int w, int h, int color);
void LCDFillRectLine(int x0, int y0, int w, int h, int color);
void LCDPutImage(int x0, int y0, int w, int h, char *buf);
void LCDPutImageRev(int x0, int y0, int w, int h, char *buf);
void LCDRedraw();
}
#endif
//#define GUI_DBG

#include<string.h>
#include"gui_screen_def.h"
#include"gui_enums.h"
	
//组件类型
#define CA_INNER_LABEL -1 //附属于其它组件的标签类型
#define CA_OBJ_BASE 0
#define CA_LABEL 0x10
#define CA_BUTTON 0x20 
#define CA_INPUT 0x30
#define CA_MULTILINE_INPUT 0x40
#define CA_BUTTON_INNER 0x50 

#define CA_GROUP 0xe0
#define CA_SCROLL_GROUP 0xe1
#define CA_BUTTON_LIST 0xe2 
#define CA_MULTILINE_INPUT_WITH_BAR 0xe3
#define CA_INPUT_LIST 0xe4
#define CA_PAGE 0xf0
#define CA_WINDOW 0xf1
#define CA_MULTI_WINDOW 0xf2		
#define CA_MSGBOX 0Xf3
#define CA_PROGRESSBAR 0Xf4
 //add by yuyan
#define CA_LABEL_LIST 0xe5 

class CaGroup;
class CaWindow;
class CaObject {
public:
	typedef enum _BoxType_{
	BOX_NO=0,
		BOX_LEFT_LINE = 1 << 1,
		BOX_RIGHT_LINE= 1 << 2,
		BOX_TOP_LINE =1 << 3,
		BOX_BOTTOM_LINE =1 << 4,
		BOX_ALL=0xf,
	}TBoxType;
	enum{OBJ_TITLE_MAX_LEN=32};
	enum{BUF_OFFSET=2};

#if CHN_FONT_SIZE == 12
	enum{GRID_LINE_H=12};
	enum{IMG_BYTES=12};
#else
	enum{GRID_LINE_H=16};
	enum{IMG_BYTES=16};
#endif

	typedef enum _ALIGN_TYPE_{
			ALIGN_LEFT=0, 
			ALIGN_CENTER,
			ALIGN_RIGHT,
			ALIGN_NULL}ALIGN_TYPE;
	typedef enum _LABEL_POS_{ON_LEFT=0,ON_TOP,ON_INSIDE,ON_NULL}LABEL_POS;
protected:
	int m_iBoxType;
public:
	int BoxType(){return m_iBoxType;};
	void BoxType(int t){m_iBoxType=t;};
public:
    int m_iY;
    int m_iX;
    int m_iH;
    int m_iW;
	
    CaGroup * m_pOwner;
    CaObject * m_pLabel;
	

    int m_PgNum;
    bool m_Visible;

	int m_iType; //组件类型
    bool m_bFocus;
	bool m_bRefreshFlag;
    void(* OnObject) (CaObject *obj,int iEvent, unsigned char * pEventData, int iDataLen);
	
public:
	
	/*!
		@brief 真正创建控件	
		@param iX 左上角横坐标
		@param iY 左上角纵坐标
		@param iW 宽度
		@param iH 高度
		@param pOwner 所属管理控件句柄
		@return <=-1 失败，>=0 成功
	*/
	virtual int Create(int iX,int iY,int iW,int iH);
    virtual int ProcEvent(int iEvent, unsigned char * pEventData, int iDataLen);
    virtual int ReFresh(void)=0;
    virtual int SetFocus(void);
    virtual int SetFocusIn(void);
    virtual int SetTitle(const char * pData, int iLen);
	virtual int GetTitle(char *pData,int &iLen);
	virtual ALIGN_TYPE GetTitleAlign();
	virtual void SetTitleAlign(ALIGN_TYPE altype);
	virtual int ReFreshTitle(void);
	virtual void ClearDisp();
	virtual void DrawBox();
	virtual void Visible(bool v);
	virtual bool Visible()const{return m_Visible;}; 
	virtual bool GetRefreshFlag(){return m_bRefreshFlag;};
	virtual void ClearRefreshFlag(){m_bRefreshFlag=false;};
	virtual bool IsRefreshAble();
	virtual bool IsCurObj();
//	virtual void Hide(void);
	CaObject(int type,bool bfocus,CaGroup *pOwner=NULL );
	CaObject(CaGroup *pOwner);
    CaObject();
    virtual ~CaObject();
	CaWindow *GetdWin();
	
	static int AlignBuf( const char * str, char * buf, int bufSize,int align );
	
#ifdef GUI_DBG
public:
static	void LCDRedraw();
#ifdef WIN32
static	void LCDInit(void);
#endif
//static	void LCDFillRect(int x0, int y0, int w, int h, int color);
//static	void LCDFillRectLine(int x0, int y0, int w, int h, int color);
static	void LCDGetGeometry(void);
//static	void LCDPutImage(int x0, int y0, int w, int h, char *buf);
//static	void LCDPutImageRev(int x0, int y0, int w, int h, char *buf);
static	void putpixel( int x, int y, int c );
//static	void str2image(unsigned char *str, int len, unsigned char *buffer);
#endif

private:
	void OnTest(CaObject *obj,int iEvent, unsigned char * pEventData, int iDataLen);
};

#endif //CAOBJECT_H


