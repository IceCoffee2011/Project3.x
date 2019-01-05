#include "RolMenu.h"
#include <math.h>

//#define PI  3.14159265358979323846f
//#define PI acos(-1)
//ͼƬ̫С��Ҫ�Ŵ���С
#define MENU_SCALE_ADD 0.2
//�˵�����С���� ��С�ı�����1-MENU_SCALE
#define MENU_SCALE 0.32
//�˵�����б�� ���Ϊ45��
#define MENU_ASLOPE 68.0
//calcFunction(x) Ϊ x/(x+a),����aΪ����
#define CALC_A 1
// ��� ԽС���Խ��
#define SPACE_A 0.5
//��������ʱ��
#define ANIMATION_DURATION  0.3f
//�˵���Ĵ�С����Ļ�ı�������Ȼ����ͨ��setContentSize����
#define CONTENT_SIZE_SCALE (4.0/5)
//�˵������˵����ȵı��� ����һ���˵���ȣ��˵���仯һ��
#define ITEM_SIZE_SCALE (1.0/3.0)

USING_NS_CC;


bool RolMenu::init(){
	if (!ui::Layout::init())
		return false;

	this->setClippingEnabled(true);
	this->setClippingType(Layout::ClippingType::STENCIL);
	_index=0;
	_lastIndex = 0;
	this->ignoreAnchorPointForPosition(false);
	_selectedItem = nullptr;
	auto size = Director::getInstance()->getWinSize();
	this->setContentSize(size*CONTENT_SIZE_SCALE);
	this->setAnchorPoint(Vec2(0.5f, 0.5f));
	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(RolMenu::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(RolMenu::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(RolMenu::onTouchEnded, this);
	getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
	return true;
};

void RolMenu::addMenuItem(cocos2d::MenuItem *item){
	
	item->setPosition(this->getContentSize() / 2);
	this->addChild(item);
	_items.pushBack(item);
	reset();
	int index = (_items.size()-1)/2;
	if (index>0)
	{
		if (index>2)
		{
			index = 2;
		}
		_index = index;
	}
	item->setColor(Color3B(150,150,150));
	//���ϣ����ʼû���ƶ�Ч�����ĳ�updatePosition��������
	updatePositionWithAnimation();
	return;
}

void RolMenu::RemoveAllItem()
{
	_selectedItem = nullptr;
	this->removeAllChildrenWithCleanup(true);
	_items.clear();
}

void RolMenu::updatePosition(bool forward){
	auto menuSize = getContentSize();

	auto index = _index;
	if (index < 0)
		index = 0;
	if (index>_items.size() - 1)
		index = _items.size() - 1;
	if (forward){
		index = (int)(index + 0.4);
	}
	else
		index = (int)(index + 0.6);

	//MenuItem * ItemSel = getCurrentItem();
	for (int i = 0; i < _items.size(); i++){
		MenuItem * Item = _items.at(i);
		Color3B clr = Item->getColor();
		if (index != i)
		{
			if (clr != Color3B(150,150,150))
			{
				Item->setColor(Color3B(150,150,150));
			}
		}
		else
		{
			if (clr != Color3B(255,255,255))
			{
				Item->setColor(Color3B(255,255,255));
			}
		}
		//����λ��
		float x = getItemPosX(i - _index, menuSize.width / 2);   //calcFunction(i - _index, menuSize.width / 2);
		Item->setPosition(Vec2(menuSize.width/2+x, menuSize.height/2));
		//����zOrder,������˳��
		Item->setZOrder(-abs((i - _index) * 100));
		//������������
		Item->setScale(1.0-abs(calcFunction(i - _index, MENU_SCALE))+MENU_SCALE_ADD);
		//������б��Nodeû��setCamera��������OrbitCamera������ʱ����Ϊ0���ﵽЧ��
// 		auto orbit1 = OrbitCamera::create(0, 1, 0, calcFunction(i - _lastIndex, MENU_ASLOPE), calcFunction(i - _lastIndex, MENU_ASLOPE) - calcFunction(i - _index, MENU_ASLOPE), 0, 0);
// 		Item->runAction(orbit1);
	}

	return;
}
void RolMenu::updatePositionWithAnimation(){
	//��ֹͣ���п��ܴ��ڵĶ���
	for (int i = 0; i < _items.size(); i++)
		_items.at(i)->stopAllActions();
	auto menuSize = getContentSize();
	for (int i = 0; i < _items.size(); i++){
		_items.at(i)->setZOrder(-abs((i - _index)*100));
		float x = getItemPosX(i - _index, menuSize.width / 2); //calcFunction(i - _index, menuSize.width / 2); 
		auto moveTo = MoveTo::create(ANIMATION_DURATION, Vec2(menuSize.width / 2 + x, menuSize.height / 2));
		_items.at(i)->runAction(moveTo);
		auto scaleTo = ScaleTo::create(ANIMATION_DURATION, (1 - abs(calcFunction(i - _index, MENU_SCALE))+MENU_SCALE_ADD));
		_items.at(i)->runAction(scaleTo);
// 		auto orbit1 = OrbitCamera::create(ANIMATION_DURATION, 1, 0, calcFunction(i - _lastIndex, MENU_ASLOPE), calcFunction(i - _index, MENU_ASLOPE) - calcFunction(i - _lastIndex, MENU_ASLOPE), 0, 0);
// 		_items.at(i)->runAction(orbit1);
	}
	scheduleOnce(schedule_selector(RolMenu::actionEndCallBack), ANIMATION_DURATION);
	return;
}
void RolMenu::reset(){
	_lastIndex = 0;
	_index = 0;
}
void RolMenu::setIndex(int index){
	_lastIndex = _index;
	this->_index = index;
}
float RolMenu::getIndex(){
	return _index;
}

MenuItem * RolMenu::getCurrentItem(){
	if (_items.size() == 0)
		return nullptr;
	ssize_t index = _index;
	if (index<0 || index>=_items.size())
	{
		return nullptr;
	}
	return _items.at(index);
}


bool RolMenu::onTouchBegan(Touch* touch, Event* event){
	if(!this->isVisible())
		return false;
	//��ֹͣ���п��ܴ��ڵĶ���
	for (int i = 0; i < _items.size(); i++)
		_items.at(i)->stopAllActions();
	if (_selectedItem)
		_selectedItem->unselected();
	auto position = this->convertToNodeSpace(touch->getLocation());
	auto size = this->getContentSize();
	auto rect = Rect(0, 0, size.width, size.height);
	if (rect.containsPoint(position)){
		return true;
	}
	return false;
}

void RolMenu::onTouchEnded(Touch* touch, Event* event){

	//auto size = getContentSize();
	if(!this->isVisible())
		return ;
	auto position = touch->getLocation();
	auto xDelta = position.x - touch->getStartLocation().x;
	rectify(xDelta>0);
	if (_selectedItem)   // �Ƿ���ѡ�е�ѡ��
	{
		log("onTouchEnded");
		auto itemSize = _selectedItem->getContentSize();
		float fWidth =itemSize.width/16;
		if (abs(xDelta)<fWidth)   // �ƶ��Ƿ񳬳���Χ
		{
			auto pos = _selectedItem->convertToNodeSpace(position);
			auto rect = Rect(0, 0, itemSize.width, itemSize.height);
			if (rect.containsPoint(pos))
			{
				if(_selectedItem)
					_selectedItem->activate();
			}			
			else
			{

				int index;
				if (pos.x>0)
				{
				index = getIndex() + (pos.x / itemSize.width );
				}
				else
				{
					if (getIndex() != 0)
					{
						index = getIndex() + (pos.x / itemSize.width );
					}
					else
					{
						if (-pos.x > itemSize.width / 16)
						{
							index = -1;
						}
						else
						{
							index = 0;
						}
					}
				}
				if (index>=0 && index<_items.size())
				{
					setIndex(index);
					updatePositionWithAnimation();
					this->runAction(Sequence::createWithTwoActions(DelayTime::create(0.5), CallFunc::create([&](){
						_items.at(getIndex())->activate();
					})));
				}
			}
		}
	}	
	updatePositionWithAnimation();
	return;
}
void RolMenu::onTouchMoved(Touch* touch, Event* event){

	auto xDelta = touch->getDelta().x;
	auto size = getContentSize();
	_lastIndex = _index;
	_index -= xDelta / (size.width *ITEM_SIZE_SCALE);
	updatePosition(xDelta>0);
	return;
}

void RolMenu::rectify(bool forward){
	auto index = getIndex();
	if (index < 0)
		index = 0;
	if (index>_items.size() - 1)
		index = _items.size() - 1;
	if (forward){
		index = (int)(index + 0.4);
	}
	else
		index = (int)(index + 0.6);
	setIndex((int)index);
}

void RolMenu::actionEndCallBack(float dx){
	if (_selectedItem != nullptr)
	{
		_selectedItem->setColor(Color3B(150,150,150));
	}
	_selectedItem = getCurrentItem();
	if (_selectedItem)
	{
		_selectedItem->selected();
		_selectedItem->setColor(Color3B(255,255,255));
	}
}

float RolMenu::calcFunction(float index, float width){

	return width*index / (abs(index) + CALC_A);
}

float RolMenu::getItemPosX(float index, float width)
{
	return width*index / (SPACE_A+ CALC_A);  // ����
}
int32_t RolMenu::getItemTag()
{
	if (_selectedItem)
	{
		return _selectedItem->getTag();
	}
	return 0;
}

////��Ϸ�б�
//void RolMenu::loadGame(const cocos2d::ccMenuCallback& callback)
//{
//	for(int i=0;i<GameListData::GetInstance()->GetGameKindCount();i++)
//	{
//		tagGameKind* pGameKind = GameListData::GetInstance()->EmunGameKindItem(i);
//		bool ret = false;
//		for (int j=0;j<(sizeof(g_kindID)/sizeof(int));j++)
//		{
//			if(pGameKind->wKindID != g_kindID[j])
//				continue;
//			ret = true;
//		}
//		if(!ret)
//			continue;
//		if(pGameKind!=NULL)
//		{
//			GameItem* item = GameItem::create(pGameKind->wKindID);
//			item->setBtnCallback(sender,selector);
//			if(item!=NULL)
//			{
//				m_ListView->pushBackCustomItem(item);
//			}
//		}
//	}
//}

char * pName[6]={"���鷿","���ַ�","������","�м���","�߼���","�й�����"};
////��ʼ������
//void RolMenu::loadRoom(std::int16_t wKindID,const cocos2d::ccMenuCallback& callback)
//{
//	for(int i=0;i<GameListData::GetInstance()->GetGameKindCount();i++)
//	{
//		tagGameKind* pGameKind = GameListData::GetInstance()->EmunGameKindItem(i);
//		if(pGameKind!=nullptr)
//		{
//			for(int n=0;n<GameListData::GetInstance()->GetGameServerCount();n++)
//			{
//				tagGameServer* pGameServer = GameListData::GetInstance()->EmunGameServerItem(pGameKind->wKindID,n);
//				{
//					if (pGameServer!=nullptr && (pGameServer->wKindID==709 || pGameServer->wKindID==600))
//					{
//						CHAR szServerName[LEN_SERVER*2];
//						for (int x =0;x<6;x++)
//						{
//							ZeroMemory(szServerName,sizeof(szServerName));
//							TChar2Char(pGameServer->szServerName,szServerName,LEN_SERVER*2);
//							if(strcmp(szServerName,pName[x])==0)
//							{
//								auto imgName = StringUtils::format("%d/room_%d.png",pGameServer->wKindID,x);
//								auto item1 = MenuItemImage::create(imgName, "");
//								std::int32_t tag=  (((pGameKind->wKindID&0xFFFF)<<16)|(pGameServer->wServerID&0xFFFF));
//								item1->setTag(tag);
//								item1->setCallback(callback);
//								item1->setScale(0.8f);
//								this->addMenuItem(item1);
//								break;
//							}
//						}
//					}
//					else
//						break;
//				}
//			}
//		}
//		else
//		{
//			continue;
//		}
//	}
//}