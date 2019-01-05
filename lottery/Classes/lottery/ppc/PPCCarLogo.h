#ifndef __PPC_CAR_LOGO_H__
#define __PPC_CAR_LOGO_H__

#include "cocos2d.h"
#include "PPCEnum.h"
#include "PPCRes.h"

USING_NS_CC;

//	��������������logo
class PPCCarLogo: public Node
{
public:
	PPCCarLogo();
	~PPCCarLogo();
	CREATE_FUNC(PPCCarLogo);

	/*
	**	@brief	��ʼ������logo
	**	@eType	����
	**	@eSize	�ߴ�
	*/
	void initCarLogoWithType(EPPCCarLogoType eType);

	//	����
	void resetPPCCarLogo();

	//	��������logo�Ƿ����
	void setHighLight(bool bIsHighLight);

	//	���������Ƿ�ɼ�
	void setCarVisible(bool bIsCarVisible);

	//	�������logo����
	EPPCCarLogoType getCarLogoType();

	//	����logo��ID
	CC_SYNTHESIZE(int, m_nLogoID, LogoID);

	//	����logo
	Sprite* m_pImgCarLogo;

private:
	bool init();
	void initData();

	//	�Զ�����λ��
	void autoPosition();

	//	����logo����
	Sprite* m_pImgBG;


	//	����logo��͸������
	Sprite* m_pImgMask;

	//	����logo�����⻷
	Sprite* m_pHighLight;

	//	����
	Sprite* m_pImgCar;

	//	����logo����
	EPPCCarLogoType m_eCarLogoType;

};

#endif  // __PPC_CAR_LOGO_H__