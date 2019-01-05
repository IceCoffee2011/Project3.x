//
//  CCCollectionView.h
//  CCCollectionView
//
//  Created by zysun on 14-3-16.
//
//

#ifndef __CCCollectionView__CCCollectionView__
#define __CCCollectionView__CCCollectionView__

#include "cocos2d.h"
#include "extensions/cocos-ext.h"
#include "CCCollectionViewCell.h"

#include <set>
#include <vector>

#include "CCCollectionViewDelegate.h"
#include "CCCollectionViewDataSource.h"

USING_NS_CC;
USING_NS_CC_EXT;

/**
 *  brief ������ͼ
 */
class CollectionView: public ScrollView, public ScrollViewDelegate
{
public:
    CollectionView();
	virtual ~CollectionView();

    /**
     *  brief ����һ���յļ�����ͼ
     *
     *  @return ������ļ�����ͼ
     */
    static CollectionView* create();
    /**
     *  brief ��ָ��������Դ�ͳߴ紴��������ͼ
     *
     *  @param dataSource ָ��������Դ
     *  @param size       ָ���ĳߴ�
     *
     *  @return ������ļ�����ͼ
     */
	static CollectionView* create(CollectionViewDataSource* dataSource, CollectionViewDelegate* delegate, cocos2d::Size size);
    /**
     *  brief ��ָ��������Դ���ߴ����������һ��������ͼ
     *
     *  @param dataSrouce ָ��������Դ
     *  @param size       ָ���ĳߴ�
     *  @param container  ָ��������
     *
     *  @return ������ļ�����ͼ
     */
	static CollectionView* create(CollectionViewDataSource* dataSrouce, CollectionViewDelegate* delegate, cocos2d::Size size, Node *container);
    /**
     *  brief ��ָ���ĳߴ��������ʼ��������ͼ
     *
     *  @param size      ָ���ĳߴ�
     *  @param container ָ��������
     *
     *  @return ��ʼ�����
     */
	bool initWithViewSize(cocos2d::Size size, Node* container = NULL);
    /**
     *  brief Ϊ������ͼָ������Դ
     *
     *  @param source ָ��������Դ
     */
	void setDataSource(CollectionViewDataSource* dataSource);
    /**
     *  brief ��ȡ������ͼ������Դ
     *
     *  @return ������ͼ������Դ
     */
	CollectionViewDataSource* getDataSource() {return _dataSource;}
    /**
     *  brief Ϊ������ͼָ��ί�ж���
     *
     *  @param delegate ָ����ί�ж���
     */
	void setDelegate(CollectionViewDelegate* delegate);
    /**
     *  brief ��ȡ������ͼ��ί�ж���
     *
     *  @return ������ͼ��ί�ж���
     */
	CollectionViewDelegate* getDelegate() {return _delegate;}
    /**
     *  brief ����ָ��λ�õĵ�Ԫ��
     *
     *  @param idx Ҫ���µĵ�Ԫ���λ��
     */
	void updateCellAtIndex(ssize_t idx);
    /**
     *  brief ��ָ��λ�ò��뵥Ԫ��
     *
     *  @param idx ��Ԫ��Ҫ�����λ��
     */
	void insertCellAtIndex(ssize_t idx);
    /**
     *  brief ɾ��ָ��λ�õĵ�Ԫ��
     *
     *  @param idx Ҫɾ���ĵ�Ԫ���λ��
     */
	void removeCellAtIndex(ssize_t idx);
    /**
     *  brief ���¼�������
     */
	void reloadData();
    /**
     *  brief �����ö����л�ȡһ����Ԫ��
     *
     *  @return �����ö�����ȡ���ĵ�Ԫ��
     */
	CollectionViewCell* dequeueCell();
    /**
     *  brief ��ȡָ��λ�õĵ�Ԫ��
     *
     *  @param idx Ҫ��ȡ��λ��
     *
     *  @return ָ��λ�õĵ�Ԫ��
     */
	CollectionViewCell *cellAtIndex(ssize_t idx);
    /**
     *  brief ���ñ���ͼƬ
     *
     *  @param fileName ����ͼƬ������
     */
	void setBackGroundViewWithFile(const char* fileName);
    /**
     *  brief �����Ƿ�����ѡ
     *
     *  @param flag true or false
     */
	void setMultipleSelectEnabled(bool flag);
    /**
     *  brief ��ȡ�Ƿ����˶�ѡ
     *
     *  @return true or false
     */
	
	bool getMultipleSelectEnabled(){return _multipleTouchEnabled;};
    /**
     *  brief ��ȡ���б�ѡ��ĵ�Ԫ����±�
     *
     *  @return ���б�ѡ��ĵ�Ԫ����±�
     */
	std::set<ssize_t>* getSelectedIndices(){return _selectedIndices;};
    
    // Overrides
    virtual void scrollViewDidScroll(ScrollView* view) override;
    virtual void scrollViewDidZoom(ScrollView* view)  override {}
    virtual bool onTouchBegan(Touch *pTouch, Event *pEvent) override;
    virtual void onTouchMoved(Touch *pTouch, Event *pEvent) override;
    virtual void onTouchEnded(Touch *pTouch, Event *pEvent) override;
    virtual void onTouchCancelled(Touch *pTouch, Event *pEvent) override;
private:
    void _updateCellPositions();
    void _updateContentSize();

    long __indexFromOffset(Vec2 offset);
    long _indexFromOffset(Vec2 offset);
    Vec2 __offsetFromIndex(ssize_t index);
    Vec2 _offsetFromIndex(ssize_t index);

    void _moveCellOutOfSight(CollectionViewCell *cell);
    void _setIndexForCell(ssize_t index, CollectionViewCell *cell);
    void _addCellIfNecessary(CollectionViewCell * cell);
    //��ȡ������ĵ�Ԫ����±�
	
	ssize_t _getIndexWithTouchPoint(Vec2 point);
	
	Direction _oldDirection;
	
	//ί�ж���
	CollectionViewDelegate* _delegate;
	//����Դ
	
	CollectionViewDataSource* _dataSource;
	
	//������ͼ
	
	Sprite* _backgroundView;
	
	//����
	ssize_t _row;
	
	//����
	ssize_t _col;
	// ����൥Ԫ�����߽�ļ��
	float _leftSpace;
	
	//���ϲ㵥Ԫ����ϱ߽�ļ��
    float _upSpace;
	
	//��Ԫ��֮���������
    float _verticalSpace;
	
	//��Ԫ��֮���ˮƽ���
    float _horizonalSpace;
	//���ڵ���ĵ�Ԫ��
	
	CollectionViewCell* _touchedCell;
	
	//���еĵ�Ԫ���±�
    std::set<ssize_t>* _indices;
	//���е�Ԫ���λ��
    std::vector<Vec2> _vCellsPositions;
	
	//����ʹ�õĵ�Ԫ��
    Vector<CollectionViewCell*> _cellsUsed;
	
	//���ö����еĵ�Ԫ��
    Vector<CollectionViewCell*> _cellsFreed;
	
	//�Ƿ�����ѡ
    bool _multipleTouchEnabled;
	
	//�ڿ�����ѡ������£��洢���б�ѡ�еĵ�Ԫ��
	std::set<ssize_t>* _selectedIndices;
	
	__Array *_cellsSelected;
	
	bool _isUsedCellsDirty;
};

#endif /* defined(__CCCollectionView__CCCollectionView__) */
