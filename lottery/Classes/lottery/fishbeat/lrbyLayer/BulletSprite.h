#ifndef __GAME_BULLET_SPRITE_H__
#define __GAME_BULLET_SPRITE_H__
#include "cocos2d.h"
#include "BulletSprite.h"
#include "FishManager.h"


USING_NS_CC;

class BulletSprite : public cocos2d::Node
{
public:
	BulletSprite();
	~BulletSprite();
	virtual bool init();
	CREATE_FUNC(BulletSprite);

	//inline int getLockFishId() { return (m_pLockFish!=nullptr)? m_pLockFish->getFishId():-1; }
	void setBulletId(int nId);
	int getBulletId();
	Vec2 getBulletPosition();
	void setBulletStatue(int nStatue, int bulletMulriple, Vec2 pt, float fAngle, int nChairID);
	void updateBullet(float dt);
	void setBulletAngle(float angle);
	void setbulletSpeed(float speed);
	void setAndroidChairID(int android_chairid){m_android_chairid = android_chairid;}
	int  getAndroidChairID(){return m_android_chairid;}

	void setLockFish(FishSprite* fish) { m_pLockFish = fish; };

	void removeBullet();
	void runBezier(Vec2 ptCannonm, Vec2 ptStartPos, Vec2 ptEndPos, float fDistance);

	//ת��chairid
	static int ExchangeChairID(const int iChairID);
public:
	Sprite* m_bulletBg;
	int		m_bulletStatue;
	int     m_bulletMulriple;
	float	m_bulletAngle;
	float	m_bulletSpeed;
	Vec2    m_ptSrc;
	


	int		m_nPathCount;		//�ӵ��ƶ��ĵ�ǰ·��ֵ
	FishSprite *m_pLockFish;

	CC_SYNTHESIZE(int, m_LockFishId, LockFishId);
private:
	int m_nBulletId;
	int m_nBulletOfChair;
	int m_android_chairid;
	Vec2	m_startPos;//�ӵ���ʼ��,Ҳ�Ƿ���������λ��
	int m_fireChairId;//�����ӵ���λ��
	

	std::vector<FPoint> m_vecTraceBullet;
};

#endif