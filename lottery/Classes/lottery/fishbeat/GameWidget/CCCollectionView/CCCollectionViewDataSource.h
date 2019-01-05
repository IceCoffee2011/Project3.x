//
//  CCCollectionViewDataSource.h
//  CCCollectionView
//
//  Created by zysun on 14-3-16.
//
//

#ifndef CCCollectionView_CCCollectionViewDataSource_h
#define CCCollectionView_CCCollectionViewDataSource_h

#include "math/CCGeometry.h"

class CollectionViewCell;
class CollectionView;

/**
 *  brief ���弯����ͼ������ԴЭ��
 */
class CollectionViewDataSource
{
public:
    
    /**
     *  brief Ϊ������ͼָ����λ���趨��Ԫ��
     *
     *  @param collection Ҫ�趨��Ԫ��ļ�����ͼ
     *  @param idx        Ҫ�趨��Ԫ����±�
     *
     *  @return Ҫ�趨�ĵ�Ԫ��
     */
    virtual CollectionViewCell* collectionCellAtIndex(CollectionView* collection, ssize_t idx) = 0;
    
    /**
     *  brief Ϊ������ͼ�趨��Ԫ�������
     *
     *  @param collection Ҫ�趨�ļ�����ͼ
     *
     *  @return Ҫ�趨�ĵ�Ԫ������
     */
    virtual ssize_t numberOfCellsInCollection(CollectionView* collection) = 0;
};

#endif
