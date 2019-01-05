#ifndef __SGLY_TOOL_H__
#define __SGLY_TOOL_H__

#include "cocos2d.h"
#include "Define.h"

USING_NS_CC;
using namespace std;

/*
**	@brief	ˮ����԰��������
*/
class SGLYTool
{
public:
	SGLYTool();
	~SGLYTool();

	/*
	**	@brief		����һ��ɽ��
	**	@llValue	��������
	**	@return		���
	*/
	static LONGLONG exchangeForGold(LONGLONG llValue);

	/*
	**	@brief		��Ҷһ��ɳ���
	**	@llValue	�������
	**	@return		����
	*/
	static LONGLONG exchangeForChip(LONGLONG llValue);

	static DWORD m_dwExchangeRate;
	static LONGLONG m_llApplyBankerCondition;
private:
	
};


#endif  // __SGLY_TOOL_H__