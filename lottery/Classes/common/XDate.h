#ifndef XDATE_H 
#define XDATE_H  
#include "stdio.h"
#include "stdlib.h"

#include "GlobalDef.h"
#include "GlobalUnits.h"
#include "cocos2d.h"
#include "time.h"
using namespace cocos2d;
using namespace std;

#ifndef MAKELONG
typedef DWORD DWORD_PTR;

#define MAKEWORD(a, b)      ((WORD)(((BYTE)(((DWORD_PTR)(a)) & 0xff)) | ((WORD)((BYTE)(((DWORD_PTR)(b)) & 0xff))) << 8))
#define MAKELONG(a, b)      ((LONG)(((WORD)(((DWORD_PTR)(a)) & 0xffff)) | ((DWORD)((WORD)(((DWORD_PTR)(b)) & 0xffff))) << 16))
#define LOWORD(l)           ((WORD)(((DWORD_PTR)(l)) & 0xffff))
#define HIWORD(l)           ((WORD)((((DWORD_PTR)(l)) >> 16) & 0xffff))
#define LOBYTE(w)           ((BYTE)(((DWORD_PTR)(w)) & 0xff))
#define HIBYTE(w)           ((BYTE)((((DWORD_PTR)(w)) >> 8) & 0xff))

#endif // !MAKELONG



extern const int START_YEAR; 
extern const int END_YEAR ; 

class xDate 
{ 
private: 
   int    m_iYear, m_iMonth, m_iDay; 
   void    l_InitData(); 
   //�����1901��1��1�չ�iSpanDays������������    
   static void   l_CalcLunarDate(int &iYear, int &iMonth ,int &iDay,int iSpanDays); 
   //���㹫��iYear��iMonth��iDay�ն�Ӧ�Ľ��� 0-24��0���ǽ��� 
   static int   l_GetLunarHolDay(int iYear, int iMonth, int iDay); 
public:  
   //=====================================================================================// 
   xDate(int iYear, int iMonth, int iDay);  
   xDate(); 
   //=====================================================================================// 

   int GetYear(){return m_iYear;}  
   int GetMonth(){return m_iMonth;} 
   int GetDay(){return m_iDay;}  
    
   //=====================================================================================// 
   void GetDate(int &iYear, int &iMonth, int &iDay);  
   bool SetDate(int iYear , int iMonth , int iDay); 
   //=====================================================================================// 
   //�ж�iYear�ǲ�������  
    static bool IsLeapYear(int iYear)  {return !(iYear%4)&&(iYear%100) || !(iYear%400);}  
    
   //����iYear,iMonth,iDay��Ӧ�����ڼ� 1��1��1�� --- 65535��12��31��  
   static int WeekDay(int iYear, int iMonth, int iDay); 
    
   //����iYear��iMonth�µ����� 1��1�� --- 65535��12��  
   static int MonthDays(int iYear, int iMonth);  
    
   //��������iLunarYer������iLunarMonth�µ����������iLunarMonthΪ���£� 
   //����Ϊ�ڶ���iLunarMonth�µ��������������Ϊ0  
   // 1901��1��---2050��12��  
   static int LunarMonthDays(int iLunarYear, int iLunarMonth);  
    
   //��������iLunarYear��������� 
   // 1901��1��---2050��12��  
   static int LunarYearDays(int iLunarYear);  
    
   //��������iLunarYear��������·ݣ���û�з���0  
   // 1901��1��---2050��12�� 
   static int GetLeapMonth(int iLunarYear);  
    
   //��iYear���ʽ������ɼ��귨��ʾ���ַ���  
   static void FormatLunarYear(int  iYear, char *pBuffer);  

   //��iMonth��ʽ���������ַ���  
   static void FormatMonth(int iMonth, char *pBuffer, bool bLunar = true);  
    
   //��iDay��ʽ���������ַ���  
   static void FormatLunarDay(int  iDay, char *pBuffer); 
    
   //���㹫���������ڼ���������  1��1��1�� --- 65535��12��31��  
   static int CalcDateDiff(int iEndYear, int iEndMonth, int iEndDay,int iStartYear = START_YEAR,int iStartMonth =1, int iStartDay =1);  
    
   //���㹫��iYear��iMonth��iDay�ն�Ӧ����������,���ض�Ӧ���������� 0-24 
   //1901��1��1��---2050��12��31��  
   static int GetLunarDate(int iYear, int iMonth, int iDay,int &iLunarYear, int &iLunarMonth, int &iLunarDay); 
};  

#endif //XDATE_H 