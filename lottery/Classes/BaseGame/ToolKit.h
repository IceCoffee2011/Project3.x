#ifndef __TOOL_KIT_H__
#define __TOOL_KIT_H__


#include "cocos2d.h"

USING_NS_CC;
using namespace std;

/*
**	������
*/
class ToolKit
{
public:
	ToolKit();
	~ToolKit();

	//	ת��������
	static void toPortrait();

	//	ת���ɺ���
	static void toLandscape();

	//	�������һ���ǳ�
	static string generateNickname();

	static void showTips(string sTips, float fDuration = 1.0f);

	/*
	**	@brief		�϶������ӽڵ���Ը��ڵ��λ��
	**				��ӡ����Ը��ڵ�λ�õĽڵ����ꡢ�ٷֱȺ���������
	**	@pParent	���ڵ�
	**	@pChild		�ӽڵ�
	*/	
	static void studioUISingle(Node* pParent, Node* pChild);

	/*
	**	@brief		�϶������ӽڵ���Ը��ڵ��λ��
	**				��ӡ����Ը��ڵ�λ�õĽڵ����ꡢ�ٷֱȺ���������
	**	@pParent	���ڵ�
	**	@vChildren	�ӽڵ㼯��
	*/
	static void studioUIMulti(Node* pParent, std::vector<Node*> vChildren);

	/*
	**	@brief		��һ���ַ�����4λ�á�****������
	**	@sString	UTF8������ַ���
	*/	
	static string dealStringOfPrivacy(const string &sString);

	//����״̬��
	static void toDontShowInfo();

	//��ʾ״̬��
	static void toShowInfo();

private:
};

#endif  // __TOOL_KIT_H__