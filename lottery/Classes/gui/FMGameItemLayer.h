#ifndef __ROTA__TE_MENU_H__
#define __ROTA__TE_MENU_H__
#include "cocos2d.h"
#include <vector>

USING_NS_CC;

class GameItemLayer :public Layer
{
public:
    //���췽��
    CREATE_FUNC(GameItemLayer);
    //��Ӳ˵���
    void addMenuItem(MenuItem *item);
    //����λ��
    void updatePosition();
    //����λ�ã��ж���
    void updatePositionWithAnimation();
    //λ�ý���  �޸ĽǶ� forwardΪ�ƶ�����  ������1/3����1
    //true Ϊ����  false ��
    void rectify(bool forward);
    //��ʼ��
    virtual bool init();
    //����  ��������ת�Ƕ���Ϊ0
    void reset();
	void setEnabled(bool flag);
private:
    //���ýǶ� ����
    void setAngle(float angle);
    float getAngle();
    //���õ�λ�Ƕ� ����
    void setUnitAngle(float angle);
    float getUnitAngle();
    //��������ת���Ƕ�,ת������Ϊ  �ƶ����Menu.width����_unitAngle
    float disToAngle(float dis);
    //���ر�ѡ�е�item
    MenuItem * getCurrentItem();
private:
    //�˵��Ѿ���ת�Ƕ� ����
    float _angle;
    //�˵����,_children˳���仯���½����鱣��˳��
    std::vector<MenuItem *> _items;
    //��λ�Ƕ� ����
    float _unitAngle;
    //��������
    virtual bool onTouchBegan(Touch* touch, Event* event);
    virtual void onTouchEnded(Touch* touch, Event* event);   
    virtual void onTouchMoved(Touch* touch, Event* event);
   
	//���������ú���
    void actionEndCallBack(float dx);
    //��ǰ��ѡ���item
    MenuItem *_selectedItem;
    //��������ʱ��
     float animationDuration;
	 bool inFlag;
};
#endif
 
