#pragma once
#include "cocos2d.h"

USING_NS_CC;


class FreeCell : public Node
{
public:
	static FreeCell* FreeCellWith(int type,bool isGet);
	bool initFreeCellWith(int type,bool isGet);
	void setCellIdx(int idx,bool isGet);
	void chooseFree(Object *obj);
	void setPesent(Object* obj);
	FreeCell(void);
	~FreeCell(void);

	void setMenuEnable(Object* obj);

private:

	int m_nType;
	bool m_nIsget;
	/**����ѡ���Ϊ�ڼ���ͼƬ**/
	int m_choose;
	Sprite *pSprite;
	Sprite *pChoose;

	LabelTTF *m_titile;
	LabelTTF *m_text;

	/**������**/
	ProgressTimer *pJinDuTiao;
	Sprite *pJinDuTiao0;
	Sprite *pJinDuTiao1;
	//��ȡ��
	LabelTTF *pTextWaring;
	/**���� ��ʾ���ؽ���**/
	LabelTTF *pTTF;

	/**csmj**/
	int m_csmj_per;
	/**pdk**/
	int m_pdk_per;
	/**phz**/
	int m_phz_per;
	/**sdh**/
	int m_sdh_per;

	MenuItemSprite *m_pMenuButton;
	
};