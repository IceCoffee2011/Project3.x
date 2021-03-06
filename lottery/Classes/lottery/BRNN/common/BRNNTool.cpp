#include "BRNNTool.h"

BRNNTool::BRNNTool()
{
}

BRNNTool::~BRNNTool()
{
}

//	将筹码类型转换为对应的筹码值
int BRNNTool::convertToChipValue(E_BRNNChipType eType)
{
	if (eType < E_BRNNChip_1 && eType >=E_BRNNChip_NULL)
	{
		return -1;
	}
	int nValue[E_BRNNChip_NULL] =
	{
		1,
		5,
		10,
		50,
		100,
		200,
		500,
		1000
	};

	return nValue[eType];
}

E_BRNNChipType BRNNTool::convertToChipType(SCORE sValue)
{
	E_BRNNChipType eType = E_BRNNChip_NULL;
	switch ((int)sValue)
	{
	case 1:
		eType = E_BRNNChip_1;
		break;
	case 5:
		eType = E_BRNNChip_5;
		break;
	case 10:
		eType = E_BRNNChip_10;
		break;
	case 50:
		eType = E_BRNNChip_50;
		break;
	case 100:
		eType = E_BRNNChip_100;
		break;
	case 200:
		eType = E_BRNNChip_200;
		break;
	case 500:
		eType = E_BRNNChip_500;
		break;
	case 1000:
		eType = E_BRNNChip_1k;
		break;
	default:
		break;
	}

	return eType;
}

//	将区域类型转换为服务器设定的区域数值
int BRNNTool::convertToServerArea(E_BRNNBetAreaType eType)
{
	int nResult = eType + 1;
	return nResult;
}

E_BRNNBetAreaType BRNNTool::convertToClientArea(int nServerArea)
{
	E_BRNNBetAreaType nResult = E_BRNNBetAreaType(nServerArea - 1);
	return nResult;
}
