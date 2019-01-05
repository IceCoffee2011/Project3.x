#ifndef __ROL__MENU_H__
#define __ROL__MENU_H__
#include "cocos2d.h"
#include "ui/UILayout.h"


class RolMenu :public cocos2d::ui::Layout{
public:
	//���췽��
	CREATE_FUNC(RolMenu);

	//��Ӳ˵���
	void addMenuItem(cocos2d::MenuItem *item);
	//ɾ������
	void RemoveAllItem();
	//����λ��
	void updatePosition(bool forward);
	//����λ�ã��ж���
	void updatePositionWithAnimation();
	//λ�ý���  �޸�λ��forwardΪ�ƶ�����  ������1/3����1
	//true Ϊ����  false ��
	void rectify(bool forward);
	//��ʼ��
	virtual bool init();
	// ����  ��ʾ����������Ϊ0
	void reset();
	////��Ϸ�б�
	//void loadGame(const cocos2d::ccMenuCallback& callback);
	////��ʼ������
	//void loadRoom(std::int16_t wKindID,const cocos2d::ccMenuCallback& callback);
	
	int32_t getItemTag();
private:
	//���õ�ǰ��ʾ����
	void setIndex(int index);
	//���õ�ǰ��ʾ�˵����������
	float getIndex();
	//���ر�ѡ�е�item
	cocos2d::MenuItem * getCurrentItem();
	//��ѧ����ʽwidth*index/(abs(index)+CALC_A) ,����CALC_AΪ����
	float calcFunction(float index, float width);
	// ��ȡƫ��λ��
	float getItemPosX(float index, float width);
private:
	//�˵��˵����������
	float _index;
	//��һ�β˵����������
	float _lastIndex;

	//�˵����,_children˳���仯���½����鱣��˳��
	cocos2d::Vector<cocos2d::MenuItem *> _items;

	//��������
	virtual bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
	virtual void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);
	virtual void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event);

	//���������ú����������Ҫ��ȷ����һ���˵�����ǰ��
	void actionEndCallBack(float dx);

	//��ǰ��ѡ���item
	cocos2d::MenuItem *_selectedItem;
};
#endif // __ROL__MENU_H__