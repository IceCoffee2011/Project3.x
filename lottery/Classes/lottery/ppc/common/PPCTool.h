#ifndef __PPC_TOOL_H__
#define __PPC_TOOL_H__

#include "cocos2d.h"
#include "Define.h"
#include "PPCEnum.h"

USING_NS_CC;
using namespace std;

//	��������������
class PPCTool
{
public:
	PPCTool();
	~PPCTool();
	/*
	**	@brief	����������ת��Ϊ��Ӧ�ĳ���ֵ
	**	@eType	��������
	**	@return	���ض�Ӧ������ֵ
	*/
	static int convertToChipValue(EPPCChipType eType);

	/*
	**	@brief	������ֵת��Ϊ��Ӧ�ĳ�������
	**	@sValue	������ֵ
	**	@return	���ض�Ӧ��������
	*/
	static EPPCChipType convertToChipType(SCORE sValue);

	/*
	**	@brief	���ֻ��˶������������ת��Ϊ�����������������ֵ
	**	@eType	�ֻ��˶������������
	**	@return	���ط����������������ֵ
	*/
	static int convertToServerArea(EPPCCarLogoType eType);

	/*
	**	@brief			�������������������ֵת��Ϊ�ֻ��˶������������
	**	@nServerArea	�������������������
	**	@return			�����ֻ��˶������������
	*/
	static EPPCCarLogoType convertToClientArea(int nServerArea);
private:

};

#endif  // __PPC_TOOL_H__