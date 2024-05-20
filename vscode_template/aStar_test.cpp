#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int ROW = 10;
const int COL = 10;
const int ZXDJ = 10;	//ֱ�ߴ���
const int XXDJ = 14;	//б�ߴ���
enum Dir { p_up, p_down, p_left, p_right, p_lup, p_ldown, p_rup, p_rdown };
struct Mypoint
{
	int row;
	int col;
	int f, g, h;
	bool operator==(const Mypoint& pos)
	{
		return (pos.row == row && pos.col == col);
	}
	void GetH(const Mypoint& Begpos, const Mypoint& Endpos)
	{
		int x = abs(Begpos.col - Endpos.col);//����ˮƽ���
		int y = abs(Begpos.row - Endpos.row);//���㴹ֱ���
		h = x + y;//�����ܵĲ��
	}
	inline void GetF()
	{
		f = g + h;//����f
	}
};

//���ṹ�洢�ڵ�
struct TreeNode
{
	Mypoint pos;//��ǰ������
	TreeNode* pParent;//��ǰ��ĸ��ڵ�
	vector<TreeNode*> pChild;	//�洢��ǰ������к��ӽڵ�
	//���캯��
	TreeNode(const Mypoint& pos)
	{
		this->pos = pos;
		pParent = nullptr;
	}
};

//�ж�ĳ�����ܷ���
bool CanWalk(int map[ROW][COL], bool vis[ROW][COL], const Mypoint& pos)
{
	//���Խ�磬������
	if (pos.row < 0 || pos.col < 0 || pos.row >= ROW || pos.col >= COL)
	{
		return false;
	}
	//�����ǽ��������
	if (map[pos.row][pos.col])
	{
		return false;
	}
	//����Ѿ��߹���������
	if (vis[pos.row][pos.col])
	{
		return false;
	}
	return true;//��������
}

int main()
{
	//��ͼ��1��ʾǽ��0��ʾ·��
	int map[ROW][COL] =
	{
		{0,0,0,0,1,0,0,0,0,0},
		{0,0,0,0,1,0,0,0,0,0},
		{0,0,0,1,1,0,1,0,0,0},
		{0,0,0,0,1,0,1,0,0,0},
		{0,0,0,0,1,0,1,0,0,0},
		{0,0,1,0,1,0,0,0,0,0},
		{0,0,0,0,1,0,0,0,0,0},
		{0,0,0,0,0,0,1,0,0,0},
		{0,0,0,0,1,1,0,0,0,0},
		{0,0,0,0,1,0,0,0,0,0},
	};

	//��ʼ����յ�
	Mypoint Begpos = { 1,1 };
	Mypoint Endpos = { 6,6 };

	//�����û���߹�
	bool vis[ROW][COL] = { false };

	//���������������ڵ�
	TreeNode* pRoot = new TreeNode(Begpos);

	vector<TreeNode*> buff;	//�洢���ӽڵ������

	TreeNode* pCurrent = pRoot;	//��¼��ǰ��
	TreeNode* pTemp = nullptr;	//��̽�ڵ�,������̽��һ��λ�õĵ�

	bool isFindEnd = false;//�յ���

	//��ʼѰ·
	while (1)
	{
		//1. ĳ����˸��������α��� ����g����
		for (int i = 0; i < 8; ++i)
		{
			//ȷ����̽�������
			pTemp = new TreeNode(pCurrent->pos);
			//�˸����������̽��
			switch (i)
			{
				//ֱ�ߴ���
			case p_up://��
				pTemp->pos.row--;
				pTemp->pos.g += ZXDJ;
				break;
			case p_down://��
				pTemp->pos.row++;
				pTemp->pos.g += ZXDJ;
				break;
			case p_left://��
				pTemp->pos.col--;
				pTemp->pos.g += ZXDJ;
				break;
			case p_right://��
				pTemp->pos.col++;
				pTemp->pos.g += ZXDJ;
				break;
				//б�ߴ���
			case p_lup://����
				pTemp->pos.row--;
				pTemp->pos.col--;
				pTemp->pos.g += XXDJ;
				break;
			case p_ldown://����
				pTemp->pos.row++;
				pTemp->pos.col--;
				pTemp->pos.g += XXDJ;
				break;
			case p_rup://����
				pTemp->pos.row--;
				pTemp->pos.col++;
				pTemp->pos.g += XXDJ;
				break;
			case p_rdown://����
				pTemp->pos.row++;
				pTemp->pos.col++;
				pTemp->pos.g += XXDJ;
				break;
			}
			//�ж������ܲ����ߣ����ߵļ���h��f ����  �洢��buff����
			if (CanWalk(map, vis, pTemp->pos))
			{	//����
				//�������
				pTemp->pos.GetH(pTemp->pos, Endpos);//����h����
				pTemp->pos.GetF();//�õ�����f���ۣ�f=g+h 
				//�����ߵ�������������
				pCurrent->pChild.push_back(pTemp);//pTemp��ʾ�ľ�����һ�����ߵĵ�
				pTemp->pParent = pCurrent;//���ӹ�ϵȷ��
				//��������
				buff.push_back(pTemp);
				//���������߹�
				vis[pTemp->pos.row][pTemp->pos.col] = true;
			}
			else
			{
				//��������ɾ��pTemp������������һ������ĵ�
				delete pTemp;
				pTemp = nullptr;
			}
		}
		/*
		������˸�������ҵ���С���۵㣬�����ƶ���Ȼ��ɾ��
		*/
		auto itMin =  min_element(buff.begin(), buff.end(), [&](TreeNode* p1, TreeNode* p2)
			{
				return p1->pos.f < p2->pos.f;
			});
		
		//��ǰ���ƶ��������С���۵�
		pCurrent = *itMin;
		//ɾ����С���۽ڵ�
		buff.erase(itMin);

		//��û�е����յ�
		if (pCurrent->pos == Endpos)
		{
			isFindEnd = true;
			break;
		}
		//û���յ㣬��Ȼһֱɾ���ڵ㣬��buffΪ��
		if (buff.size() == 0)
		{
			break;
		}
	}

	if (isFindEnd)
	{
		cout << "�ҵ��յ���!\n";
		while (pCurrent)
		{
			cout << "(" << pCurrent->pos.row << "," << pCurrent->pos.col << ")";
			pCurrent = pCurrent->pParent;
		}
	}
	else
	{
		cout << "û���ҵ��յ�!\n";

	}
	system("pause");
	return 0;
}
