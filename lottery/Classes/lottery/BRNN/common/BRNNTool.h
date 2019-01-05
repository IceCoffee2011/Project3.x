#ifndef __BRNN_TOOL_H__
#define __BRNN_TOOL_H__

#include "cocos2d.h"
#include "Define.h"
#include "BRNNDefine.h"

USING_NS_CC;
using namespace std;

/*
**	@brief	����ţţ��������
*/
class BRNNTool
{
public:
	BRNNTool();
	~BRNNTool();
	/*
	**	@brief	����������ת��Ϊ��Ӧ�ĳ���ֵ
	**	@eType	��������
	**	@return	���ض�Ӧ������ֵ
	*/
	static int convertToChipValue(E_BRNNChipType eType);

	/*
	**	@brief	������ֵת��Ϊ��Ӧ�ĳ�������
	**	@sValue	������ֵ
	**	@return	���ض�Ӧ��������
	*/
	static E_BRNNChipType convertToChipType(SCORE sValue);

	/*
	**	@brief	���ֻ��˶������������ת��Ϊ�����������������ֵ
	**	@eType	�ֻ��˶������������
	**	@return	���ط����������������ֵ
	*/
	static int convertToServerArea(E_BRNNBetAreaType eType);

	/*
	**	@brief			�������������������ֵת��Ϊ�ֻ��˶������������
	**	@nServerArea	�������������������
	**	@return			�����ֻ��˶������������
	*/
	static E_BRNNBetAreaType convertToClientArea(int nServerArea);

private:

};

#endif  // __BRNN_TOOL_H__