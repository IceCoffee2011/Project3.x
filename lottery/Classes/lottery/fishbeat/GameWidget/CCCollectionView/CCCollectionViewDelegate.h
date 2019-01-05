//
//  CCCollectionViewDelegate.h
//  CCCollectionView
//
//  Created by zysun on 14-3-16.
//
//

#ifndef CCCollectionView_CCCollectionViewDelegate_h
#define CCCollectionView_CCCollectionViewDelegate_h

#include "extensions/GUI/CCScrollView/CCScrollView.h"

class CollectionViewCell;
class CollectionView;

/**
 *  brief ���弯����ͼ��ʽ����Ϊ��Э��
 */
class CollectionViewDelegate: public cocos2d::extension::ScrollViewDelegate
{
public:
    /**
     *  brief ��Ԫ�񱻵��Ҫִ�еķ���
     *
     *  @param collection ������ļ�����ͼ
     *  @param cell       ������ĵ�Ԫ��
     */
    virtual void collectionCellTouched(CollectionView* collection, CollectionViewCell* cell) = 0;
    /**
     *  brief ��Ԫ��ձ����ʱҪִ�еķ���
     *
     *  @param collection ������ļ�����ͼ
     *  @param cell       ������ĵ�Ԫ��
     */
    virtual void collectionCellHighlight(CollectionView* collection, CollectionViewCell* cell){};
    /**
     *  brief ��ָ�����뿪��Ԫ��ʱҪִ�еķ���
     *
     *  @param collection Ҫ�뿪�ļ�����ͼ
     *  @param cell       Ҫ�뿪�ĵ�Ԫ��
     */
    virtual void collectionCellUnhighlight(CollectionView* collection, CollectionViewCell* cell){};
    //�͵�Ԫ����ʽ��ص�Ӧ����delegate��д������Ӧ����dataSource��д��
    //dataSource����Ķ��Ǻ����ݲ���صĽӿ�
    /**
     *  brief �趨��Ԫ��ĳߴ�,Ĭ�Ϸ���{0,0}
     *
     *  @param collection Ҫ�趨�ļ�����ͼ
     *  @param idx        Ҫ�趨�ĵ�Ԫ���±�
     *
     *  @return �趨�ĳߴ�
     */
    virtual cocos2d::Size collectionCellSizeForIndex(CollectionView* collection, ssize_t idx){
        return cellSizeForCollection(collection);
    };
    /**
     *  brief Ϊ������ͼ�����еĵ�Ԫ���趨�ߴ�
     *
     *  @param collection Ҫ�趨�ļ�����ͼ
     *
     *  @return �趨�ĳߴ�
     */
    virtual cocos2d::Size cellSizeForCollection(CollectionView* collection) {
        return cocos2d::Size::ZERO;
    };
    /**
     *  brief ����൥Ԫ�����߽�ļ��
     *
     *  @param collection Ҫ���õļ�����ͼ
     *
     *  @return �趨�ļ��
     */
    virtual float leftSideSpaceForCollection(CollectionView* collection){return 0;}
    /**
     *  brief ���ϲ㵥Ԫ����ϱ߽�ļ��
     *
     *  @param collection Ҫ���õļ�����ͼ
     *
     *  @return �趨�ļ��
     */
    virtual float upSideSpaceForCollection(CollectionView* collection){return 0;}
    /**
     *  brief ��Ԫ�񼴽��������ö���
     *
     *  @param collection ������ͼ
     *  @param cell       �����������ö��еĵ�Ԫ��
     */
    virtual void collectionCellWillRecycle(CollectionView* collection, CollectionViewCell* cell){};

};

#endif
