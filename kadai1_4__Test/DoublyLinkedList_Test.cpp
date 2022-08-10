#include "pch.h"
#include "../kadai1_3/DoublyLinkedList.h"
#include "../kadai1_3/ScoreData.h"
#include <string>

/**
* �e�X�g�p�̃f�[�^�����X�g�擪���烊�X�g�����Ɍ����đ}������֐��D\n
* �擪�_�~�[��������[0,1,2, ... ]�̏��ő}�������D\n
*
* @param[in] TestDoublyLinkedList �o�������X�g
* @param[in] numElement ���X�g�ɑ}������v�f�̐�
*/

using TestDoublyLinkedList = DoublyLinkedList<ScoreData>;

void createListHavingElements(TestDoublyLinkedList& list, int numElement) {

	TestDoublyLinkedList::Iterator it = list.begin();
	for (int i = 0; i < numElement; i++) {

		//�e�X�g�p�̃f�[�^�����X�g�֑}������
		ScoreData scoreData(std::to_string(i), "test" + std::to_string(i));
		ASSERT_TRUE(list.insert(it, scoreData));
	}
}

//=================================== �f�[�^���̎擾 ===================================

/**
*	@brief		���X�g����ł���ꍇ�̃f�[�^���̎擾�e�X�g
*	@details	ID:���X�g-0\n
*				�f�[�^���̎擾�@�\�̃e�X�g�ł�.\n
*				���X�g����ł���ꍇ�̖߂�l���m�F���Ă��܂�.\n
*				�f�[�^����0�ł���ΐ����ł�.\n
*/
TEST(GetDataNumTest, WhenListIsEmpty) {
	TestDoublyLinkedList list;
	EXPECT_EQ(0, list.size());
}

/**
*	@brief		���X�g�����ւ̑}�����s�����ۂ̃f�[�^���̎擾�e�X�g
*	@details	ID:���X�g-1\n
*				�f�[�^���̎擾�@�\�̃e�X�g�ł�.\n
*				���X�g�����ւ̑}�����s�����ۂ̖߂�l���m�F���Ă��܂�.\n
*				�f�[�^����1�ł���ΐ����ł�.\n
*/
TEST(GetDataNumTest, WhenInsertLastIsSucceeded) {
	TestDoublyLinkedList list;
	ScoreData scoreData("1", "test");
	ASSERT_TRUE(list.insert(list.end(), scoreData));
	EXPECT_EQ(1, list.size());
}

/**
*	@brief		���X�g�����ւ̑}�������s�����ۂ̃f�[�^���̎擾�e�X�g
*	@details	ID:���X�g-2\n
*				�f�[�^���̎擾�@�\�̃e�X�g�ł�.\n
*				���X�g�����ւ̑}�������s�����ۂ̖߂�l���m�F���Ă��܂�.\n
*				�f�[�^����0�ł���ΐ����ł�.\n
*/
TEST(GetDataNumTest, WhenInsertLastIsFailed) {
	TestDoublyLinkedList list;
	ScoreData scoreData("1", "test");
	//ASSERT_FALSE(list.insert(list.getLastIterator(), scoreData));	//���������s����ꍇ(�e�X�g�ȗ�)
	EXPECT_EQ(0, list.size());

}

/**
*	@brief		�f�[�^�̑}�����s�����ۂ̃f�[�^���̎擾�e�X�g
*	@details	ID:���X�g-3\n
*				�f�[�^���̎擾�@�\�̃e�X�g�ł�.\n
*				���X�g�ւ̑}�����s�����ۂ̖߂�l���m�F���Ă��܂�.\n
*				�f�[�^���������Ă���ΐ����ł�.\n
*/
TEST(GetDataNumTest, WhenInsertIsSucceeded) {
	TestDoublyLinkedList list;
	createListHavingElements(list, 3);	//�R�̗v�f�������X�g��p�ӂ���
	int sizeBeforeInsert = list.size();

	ScoreData scoreData("1", "test1");
	ASSERT_TRUE(list.insert(list.end(), scoreData));	//�����ɐV�����f�[�^��}��
	EXPECT_EQ(sizeBeforeInsert + 1, list.size());
}

/**
*	@brief		�f�[�^�̑}�������s�����ۂ̃f�[�^���̎擾�e�X�g
*	@details	ID:���X�g-4\n
*				�f�[�^���̎擾�@�\�̃e�X�g�ł�.\n
*				���X�g�ւ̑}�������s�����ۂ̖߂�l���m�F���Ă��܂�.\n
*				�f�[�^���������Ă��Ȃ���ΐ����ł�.\n
*/
TEST(GetDataNumTest, WhenInsertIsFailed) {
	TestDoublyLinkedList list;
	createListHavingElements(list, 3);	//�R�̗v�f�������X�g��p�ӂ���
	int sizeBeforeInsert = list.size();

	ScoreData scoreData("1", "test1");
	//ASSERT_FALSE(list.insert(list.getFirstIterator(), newScoreData));	//���������s����ꍇ(�e�X�g�ȗ�)
	EXPECT_EQ(sizeBeforeInsert, list.size());
}

/**
*	@brief		�f�[�^�̍폜���s�����ۂ̃f�[�^���̎擾�e�X�g
*	@details	ID:���X�g-5\n
*				�f�[�^���̎擾�@�\�̃e�X�g�ł�.\n
*				�f�[�^�̍폜���s�����ۂ̖߂�l���m�F���Ă��܂�.\n
*				�f�[�^���������Ă���ΐ����ł��D\n
*/
TEST(GetDataNumTest, WhenRemoveIsSucceeded) {
	TestDoublyLinkedList list;
	createListHavingElements(list, 3);
	int sizeBeforeInsert = list.size();

	ASSERT_TRUE(list.remove(list.begin()));
	EXPECT_EQ(sizeBeforeInsert - 1, list.size());
}

/**
*	@brief		�f�[�^�̍폜�Ɏ��s�����ۂ̃f�[�^���̎擾�e�X�g
*	@details	ID:���X�g-6\n
*				�f�[�^���̎擾�@�\�̃e�X�g�ł�.\n
*				�f�[�^�̍폜�����s�����ۂ̖߂�l���m�F���Ă��܂�.\n
*				�f�[�^���������Ă��Ȃ���ΐ����ł��D\n
*/
TEST(GetDataNumTest, WhenRemoveIsFailed) {
	TestDoublyLinkedList list;
	createListHavingElements(list, 3);
	int sizeBeforeInsert = list.size();

	//ASSERT_TRUE(list.remove(list.getFirstIterator()));	//���������s����ꍇ(�e�X�g�ȗ�)
	EXPECT_EQ(sizeBeforeInsert, list.size());
}

/**
*	@brief		���X�g����ł���ꍇ�ɁC�f�[�^�̍폜���s�����ۂ̃f�[�^���̎擾�e�X�g
*	@details	ID:���X�g-7\n
*				�f�[�^���̎擾�@�\�̃e�X�g�ł�.\n
*				���X�g����ł���ꍇ�ɁC�f�[�^�̍폜���s�����ۂ̖߂�l���m�F���Ă��܂�.\n
*				�f�[�^����0�ł���ΐ����ł��D\n
*/
TEST(GetDataNumTest, WhenRemoveFromEmptyList) {
	TestDoublyLinkedList list;
	ASSERT_FALSE(list.remove(list.begin()));
	EXPECT_EQ(0, list.size());
}


//=================================== �f�[�^�̑}�� ===================================

/**
*	@brief		���X�g����ł���ꍇ�ɁC���X�g�擪�̃_�~�[����ւ̃f�[�^�}���e�X�g
*	@details	ID:���X�g-9-1\n
*				�f�[�^�̑}���@�\�̃e�X�g�ł�.\n
*				���X�g����ł���ꍇ�ɁC���X�g�擪�̃_�~�[�̌���Ƀf�[�^��}�������ۂ̋������m�F���Ă��܂�.\n
*				�f�[�^�}����C�擪�v�f�̌���������_�~�[�ł���ΐ����ł��D\n
*/
TEST(InsertDataTest, WhenInsertToBackOfFirstIterator) {
	TestDoublyLinkedList list;

	ScoreData scoreData("1", "test");

	ASSERT_TRUE(list.insert(list.begin(), scoreData));

	TestDoublyLinkedList::Iterator itFirstElement = list.begin();	//�擪�v�f���w���C�e���[�^
	++itFirstElement;	//�����_�~�[�ֈړ�
	bool isEqual = (itFirstElement == list.end());
	EXPECT_TRUE(isEqual);
}

/**
*	@brief		���X�g����ł���ꍇ�ɁC���X�g�����̃_�~�[�O���ւ̃f�[�^�}���e�X�g
*	@details	ID:���X�g-9-2\n
*				�f�[�^�̑}���@�\�̃e�X�g�ł�.\n
*				���X�g����ł���ꍇ�ɁC���X�g�����̃_�~�[�̑O���Ƀf�[�^��}�������ۂ̋������m�F���Ă��܂�.\n
*				�f�[�^�}����C�擪�v�f�̌���������_�~�[�ł���ΐ����ł��D\n
*/
TEST(InsertDataTest, WhenInsertToFrontOfLastIterator) {
	TestDoublyLinkedList list;

	ScoreData scoreData("1", "test");
	ASSERT_TRUE(list.insert(list.end(), scoreData));

	TestDoublyLinkedList::Iterator itFirst = list.begin();	//�擪�v�f���w���C�e���[�^
	++itFirst;	//�����_�~�[�ֈړ�
	bool isEqual = (itFirst == list.end());
	EXPECT_TRUE(isEqual);
}

/**
*	@brief		���X�g�ɕ����̗v�f������ꍇ�ɁC�擪�v�f�̑O���ւ̃f�[�^�}���e�X�g
*	@details	ID:���X�g-10\n
*				�f�[�^�̑}���@�\�̃e�X�g�ł�.\n
*				���X�g�ɕ����̗v�f������ꍇ�ɁC�擪�v�f�̑O���փf�[�^�}�������ۂ̋������m�F���Ă��܂�.\n
*				�f�[�^�}����C�}���O�̐擪�v�f�̑O���Ɛ擪�v�f�������ł���ΐ����ł��D\n
*/
TEST(InsertDataTest, WhenInsertToFrontOfElements) {
	TestDoublyLinkedList list;

	createListHavingElements(list, 3);

	TestDoublyLinkedList::Iterator itFirstElement = list.begin();	//�f�[�^�}���O�̐擪�v�f���w���C�e���[�^
	ScoreData newScoreData("100", "newData");
	ASSERT_TRUE(list.insert(list.begin(), newScoreData));
	--itFirstElement;	//�O���ֈړ�

	bool isEqual = (list.begin() == itFirstElement);
	EXPECT_TRUE(isEqual);
}

/**
*	@brief		���X�g�ɕ����̗v�f������ꍇ�ɁC�����v�f�̌���ւ̃f�[�^�}���e�X�g
*	@details	ID:���X�g-11\n
*				�f�[�^�̑}���@�\�̃e�X�g�ł�.\n
*				���X�g�ɕ����̗v�f������ꍇ�ɁC�����v�f�̌���փf�[�^�}�������ۂ̋������m�F���Ă��܂�.\n
*				�f�[�^�}����C�}���O�̖����v�f���w���C�e���[�^��2����������_�~�[�ł���ΐ����ł��D\n
*/
TEST(InsertDataTest, WhenInsertToBackOfElements) {
	TestDoublyLinkedList list;

	createListHavingElements(list, 3);

	TestDoublyLinkedList::Iterator itLastElement = list.end();	//�f�[�^�}���O�̖����v�f���w���C�e���[�^
	--itLastElement;	//�����v�f�ֈړ�

	ScoreData newScoreData("100", "newData");
	ASSERT_TRUE(list.insert(list.end(), newScoreData));
	
	++itLastElement;	//�}����̖����v�f�ֈړ�
	++itLastElement;	//�����_�~�[�ֈړ�
	bool isEqual = (itLastElement == list.end());
	EXPECT_TRUE(isEqual);
}

/**
*	@brief		���X�g�ɕ����̗v�f������ꍇ�ɁC�擪�ł������ł��Ȃ��C�e���[�^��n�����ۂ̃f�[�^�}���e�X�g
*	@details	ID:���X�g-12-1\n
*				�f�[�^�̑}���@�\�̃e�X�g�ł�.\n
*				���X�g�ɕ����̗v�f������ꍇ�ɁC�擪�v�f���w���C�e���[�^��n���ăf�[�^�}�������ۂ̋������m�F���Ă��܂��D\n
*				�f�[�^�}����C�}�������f�[�^�̑O�����擪�v�f���w���C�e���[�^�ł���ΐ����ł��D\n
*/
TEST(InsertDataTest, WhenInsertToFirstElementWithIterator) {
	TestDoublyLinkedList list;

	createListHavingElements(list, 3);

	TestDoublyLinkedList::Iterator itFirstElement = list.begin();	//�}���O�̐擪�v�f���w���C�e���[�^
	
	ScoreData newScoreData("100", "newData");
	ASSERT_TRUE(list.insert(list.begin(), newScoreData));	//�擪�v�f�̑O���֑}��
	--itFirstElement;	//�O���ֈړ�

	bool isEqual = (list.begin() == itFirstElement);
	EXPECT_TRUE(isEqual);
}

/**
*	@brief		���X�g�ɕ����̗v�f������ꍇ�ɁC�擪�ł������ł��Ȃ��C�e���[�^��n�����ۂ̃f�[�^�}���e�X�g
*	@details	ID:���X�g-12-2\n
*				�f�[�^�̑}���@�\�̃e�X�g�ł�.\n
*				���X�g�ɕ����̗v�f������ꍇ�ɁC�����̗v�f���w���C�e���[�^��n���ăf�[�^�}�������ۂ̋������m�F���Ă��܂��D\n
*				�f�[�^�}����C�擪�v�f�̂Q������}���O�̒����̗v�f�ł���ΐ����ł��D\n
*/
TEST(InsertDataTest, WhenInsertToCenterElementWithIterator) {
	TestDoublyLinkedList list;

	createListHavingElements(list, 3);

	TestDoublyLinkedList::Iterator itFirstElement = list.begin();	//�擪�v�f���w���C�e���[�^

	TestDoublyLinkedList::Iterator itCenterElement = list.begin();	//�}���O�̒����̗v�f���w���C�e���[�^
	++itCenterElement;	//�����̗v�f�ֈړ�

	ScoreData newScoreData("100", "newData");
	ASSERT_TRUE(list.insert(itCenterElement, newScoreData));	//�����̗v�f�̑O���֑}��
	
	++itFirstElement;	//�}�������f�[�^�ֈړ�
	++itFirstElement;	//�}���O�̒����̗v�f
	bool isEqual = (itFirstElement == itCenterElement);
	EXPECT_TRUE(isEqual);
}

/**
*	@brief		���X�g�ɕ����̗v�f������ꍇ�ɁC�擪�ł������ł��Ȃ��C�e���[�^��n�����ۂ̃f�[�^�}���e�X�g
*	@details	ID:���X�g-12-3\n
*				�f�[�^�̑}���@�\�̃e�X�g�ł�.\n
*				���X�g�ɕ����̗v�f������ꍇ�ɁC�����v�f���w���C�e���[�^��n���ăf�[�^�}�������ۂ̋������m�F���Ă��܂��D\n
*				�f�[�^�}����C�}���O�̖����v�f�̂Q����������_�~�[�ł���ΐ����ł��D\n
*/
TEST(InsertDataTest, WhenInsertToLastElementWithIterator) {
	TestDoublyLinkedList list;

	createListHavingElements(list, 3);

	TestDoublyLinkedList::Iterator itLastElement = list.end();	//�}���O�̖����v�f���w���C�e���[�^
	--itLastElement;	//�����v�f�ֈړ�

	ScoreData newScoreData("100", "newData");
	ASSERT_TRUE(list.insert(list.end(), newScoreData));

	++itLastElement;	//�}�������f�[�^�ֈړ�
	++itLastElement;	//�����_�~�[�ֈړ�
	bool isEqual = (itLastElement == list.end());
	EXPECT_TRUE(isEqual);
}

/**
*	@brief		���X�g�ɕ����̗v�f������ꍇ�ɁC�擪�ł������ł��Ȃ��R���X�g�C�e���[�^��n�����ۂ̃f�[�^�}���e�X�g
*	@details	ID:���X�g-13-1\n
*				�f�[�^�̑}���@�\�̃e�X�g�ł�.\n
*				���X�g�ɕ����̗v�f������ꍇ�ɁC�擪�v�f���w���R���X�g�C�e���[�^��n���ăf�[�^�}�������ۂ̋������m�F���Ă��܂��D\n
*				�f�[�^�}����C�}�������f�[�^�̑O�����擪�v�f���w���R���X�g�C�e���[�^�ł���ΐ����ł��D\n
*/
TEST(InsertDataTest, WhenInsertToFirstElementWithConstIterator) {
	TestDoublyLinkedList list;

	createListHavingElements(list, 3);

	TestDoublyLinkedList::ConstIterator cItFirstElement = list.cbegin();	//�}���O�̐擪�v�f���w���R���X�g�C�e���[�^

	ScoreData newScoreData("100", "newData");
	ASSERT_TRUE(list.insert(list.cbegin(), newScoreData));	//�擪�v�f�̑O���֑}��
	--cItFirstElement;	//�O���ֈړ�

	bool isEqual = (list.cbegin() == cItFirstElement);
	EXPECT_TRUE(isEqual);
}

/**
*	@brief		���X�g�ɕ����̗v�f������ꍇ�ɁC�擪�ł������ł��Ȃ��R���X�g�C�e���[�^��n�����ۂ̃f�[�^�}���e�X�g
*	@details	ID:���X�g-13-2\n
*				�f�[�^�̑}���@�\�̃e�X�g�ł�.\n
*				���X�g�ɕ����̗v�f������ꍇ�ɁC�����̗v�f���w���R���X�g�C�e���[�^��n���ăf�[�^�}�������ۂ̋������m�F���Ă��܂��D\n
*				�f�[�^�}����C�擪�v�f�̂Q������}���O�̒����̗v�f�ł���ΐ����ł��D\n
*/
TEST(InsertDataTest, WhenInsertToCenterElementWithConstIterator) {
	TestDoublyLinkedList list;

	createListHavingElements(list, 3);

	TestDoublyLinkedList::ConstIterator cItFirstElement = list.cbegin();	//�擪�v�f���w���R���X�g�C�e���[�^

	TestDoublyLinkedList::ConstIterator cItCenterElement = list.cbegin();	//�}���O�̒����̗v�f���w���R���X�g�C�e���[�^
	++cItCenterElement;	//�����̗v�f�ֈړ�

	ScoreData newScoreData("100", "newData");
	ASSERT_TRUE(list.insert(cItCenterElement, newScoreData));	//�����̗v�f�̑O���֑}��

	++cItFirstElement;	//�}�������f�[�^�ֈړ�
	++cItFirstElement;	//�}���O�̒����̗v�f
	bool isEqual = (cItCenterElement == cItFirstElement);
	EXPECT_TRUE(isEqual);
}

/**
*	@brief		���X�g�ɕ����̗v�f������ꍇ�ɁC�擪�ł������ł��Ȃ��R���X�g�C�e���[�^��n�����ۂ̃f�[�^�}���e�X�g
*	@details	ID:���X�g-13-3\n
*				�f�[�^�̑}���@�\�̃e�X�g�ł�.\n
*				���X�g�ɕ����̗v�f������ꍇ�ɁC�����v�f���w���C�e���[�^��n���ăf�[�^�}�������ۂ̋������m�F���Ă��܂��D\n
*				�f�[�^�}����C�}���O�̖����v�f�̂Q����������_�~�[�ł���ΐ����ł��D\n
*/
TEST(InsertDataTest, WhenInsertToLastElementWithConstIterator) {
	TestDoublyLinkedList list;

	createListHavingElements(list, 3);

	TestDoublyLinkedList::ConstIterator cItLastElement = list.cend();	//�}���O�̖����v�f���w���R���X�g�C�e���[�^
	--cItLastElement;	//�����v�f�ֈړ�

	ScoreData newScoreData("100", "newData");
	ASSERT_TRUE(list.insert(list.cend(), newScoreData));

	++cItLastElement;	//�}�������f�[�^�ֈړ�
	++cItLastElement;	//�����_�~�[�ֈړ�
	bool isEqual = (cItLastElement == list.cend());
	EXPECT_TRUE(isEqual);
}
/**
*	@brief		�s���ȃC�e���[�^��n�����ۂ̃f�[�^�}���e�X�g
*	@details	ID:���X�g-14\n
*				�f�[�^�̑}���@�\�̃e�X�g�ł�.\n
*				�s���ȃC�e���[�^��n�����ۂ̋������m�F���Ă��܂��D\n
*				�����N����Ȃ���ΐ����ł��D\n
*/
TEST(InsertDataTest, WhenInsertWithNotAvailableIterator) {
	TestDoublyLinkedList list;
	TestDoublyLinkedList::Iterator it;

	ScoreData scoreData("1", "test");
	EXPECT_FALSE(list.insert(it, scoreData));	//���X�g�ւ̎Q�Ƃ��Ȃ��C�e���[�^��n�����ꍇ

	TestDoublyLinkedList listOther;
	TestDoublyLinkedList::Iterator itOther = listOther.begin();
	EXPECT_FALSE(list.insert(itOther, scoreData));	//�ʂ̃��X�g�̃C�e���[�^��n�����ꍇ
}


//=================================== �f�[�^�̍폜 ===================================

/**
*	@brief		���X�g����ł���ꍇ�ɁC�폜���s�����ۂ̃e�X�g
*	@details	ID:���X�g-16-1\n
*				�f�[�^�̍폜�@�\�̃e�X�g�ł�.\n
*				���X�g����ł���ꍇ�ɁC���X�g�擪�̃_�~�[���폜�����ۂ̋������m�F���Ă��܂�.\n
*				�����N����Ȃ���ΐ����ł��D\n
*/
TEST(RemoveDataTest, WhenRemoveFirstOfEmptyList) {
	TestDoublyLinkedList list;
	TestDoublyLinkedList::Iterator itFirst = list.begin();
	EXPECT_FALSE(list.remove(itFirst));
}

/**
*	@brief		���X�g����ł���ꍇ�ɁC�폜���s�����ۂ̃e�X�g
*	@details	ID:���X�g-16-2\n
*				�f�[�^�̍폜�@�\�̃e�X�g�ł�.\n
*				���X�g����ł���ꍇ�ɁC���X�g�����̃_�~�[���폜�����ۂ̋������m�F���Ă��܂�.\n
*				�����N����Ȃ���ΐ����ł��D\n
*/
TEST(RemoveDataTest, WhenRemoveLastOfEmptyList) {
	TestDoublyLinkedList list;
	TestDoublyLinkedList::Iterator itLast = list.end();
	EXPECT_FALSE(list.remove(itLast));
}

/**
*	@brief		���X�g�ɕ����̗v�f������ꍇ�ɁC���X�g�̐擪�v�f��n���č폜���s�����ۂ̃e�X�g
*	@details	ID:���X�g-17\n
*				�f�[�^�̍폜�@�\�̃e�X�g�ł�.\n
*				���X�g�ɕ����̗v�f������ꍇ�ɁC���X�g�̐擪�v�f��n���č폜�����ۂ̋������m�F���Ă��܂�.\n
*				�f�[�^�폜��C���X�g�̐擪�v�f���폜�O�̒����̗v�f�ł���ΐ����ł��D\n
*/
TEST(RemoveDataTest, WhenRemoveFirstOfListHavingElements) {
	TestDoublyLinkedList list;

	createListHavingElements(list, 3);

	TestDoublyLinkedList::Iterator itCenterElement = list.begin();	//�����̗v�f���w���C�e���[�^
	++itCenterElement;	//�����̗v�f�ֈړ�

	ASSERT_TRUE(list.remove(list.begin()));

	bool isEqual = (list.begin() == itCenterElement);
	EXPECT_TRUE(isEqual);
}

/**
*	@brief		���X�g�ɕ����̗v�f������ꍇ�ɁC���X�g�����̃C�e���[�^��n���č폜���s�����ۂ̃e�X�g
*	@details	ID:���X�g-18\n
*				�f�[�^�̍폜�@�\�̃e�X�g�ł�.\n
*				���X�g�ɕ����̗v�f������ꍇ�ɁC���X�g�����̃C�e���[�^���폜�����ۂ̋������m�F���Ă��܂�.\n
*				�����N����Ȃ���ΐ����ł��D\n
*/
TEST(RemoveDataTest, WhenRemoveLastOfListHavingElements) {
	TestDoublyLinkedList list;

	createListHavingElements(list, 3);

	EXPECT_FALSE(list.remove(list.end()));
}

/**
*	@brief		���X�g�ɕ����̗v�f������ꍇ�ɁC���X�g�擪�ł����X�g�����ł��Ȃ��C�e���[�^��n���č폜���s�����ۂ̃e�X�g
*	@details	ID:���X�g-19\n
*				�f�[�^�̍폜�@�\�̃e�X�g�ł�.\n
*				���X�g�ɕ����̗v�f������ꍇ�ɁC���X�g�擪�ł����X�g�����ł��Ȃ��v�f���폜�����ۂ̋������m�F���Ă��܂�.\n
*				�n�����C�e���[�^���w���v�f���폜����Ă���ΐ����ł��D\n
*/
TEST(RemoveDataTest, WhenRemoveCenterElementOfListHavingElements) {
	TestDoublyLinkedList list;

	createListHavingElements(list, 3);

	TestDoublyLinkedList::Iterator itFirstElement = list.begin();	//�擪�v�f���w���C�e���[�^
	TestDoublyLinkedList::Iterator itCenterElement = list.begin();	//�����̗v�f���w���C�e���[�^
	++itCenterElement;	//�����̗v�f�ֈړ�
	TestDoublyLinkedList::Iterator itLastElement = list.end();	//�����v�f���w���C�e���[�^
	--itLastElement;	//�����v�f�ֈړ�
	
	ASSERT_TRUE(list.remove(itCenterElement));	//�����̗v�f���폜
	
	++itFirstElement;	//�폜�O�ɐ擪�v�f���w���Ă����C�e���[�^������ֈړ�
	bool isEqual = (itFirstElement == itLastElement);	//�����̗v�f���폜����Ă���΁C�擪�v�f�̌���͖����v�f�ɂȂ�͂�
	EXPECT_TRUE(isEqual);
}

/**
*	@brief		�R���X�g�C�e���[�^��n���č폜���s�����ۂ̃e�X�g
*	@details	ID:���X�g-20\n
*				�f�[�^�̍폜�@�\�̃e�X�g�ł�.\n
*				�R���X�g�C�e���[�^���w���v�f���폜�����ۂ̋������m�F���Ă��܂�.\n
*				�n�����R���X�g�C�e���[�^���w���v�f���폜����Ă���ΐ����ł��D\n
*/
TEST(RemoveDataTest, WhenRemoveWithConstIterator) {
	TestDoublyLinkedList list;

	createListHavingElements(list, 3);

	TestDoublyLinkedList::ConstIterator cItFirstElement = list.cbegin();	//�擪�v�f���w���C�e���[�^
	TestDoublyLinkedList::ConstIterator cItCenterElement = list.cbegin();	//�����̗v�f���w���C�e���[�^
	++cItCenterElement;	//�����̗v�f�ֈړ�
	TestDoublyLinkedList::ConstIterator cItLastElement = list.cend();	//�����v�f���w���C�e���[�^
	--cItLastElement;	//�����v�f�ֈړ�

	ASSERT_TRUE(list.remove(cItCenterElement));	//�����̗v�f���폜

	++cItFirstElement;	//�폜�O�ɐ擪�v�f���w���Ă����C�e���[�^������ֈړ�
	bool isEqual = (cItFirstElement == cItLastElement);	//�����̗v�f���폜����Ă���΁C�擪�v�f�̌���͖����v�f�ɂȂ�͂�
	EXPECT_TRUE(isEqual);
}

/**
*	@brief		�s���ȃC�e���[�^��n�����ۂ̃f�[�^�폜�e�X�g
*	@details	ID:���X�g-21\n
*				�f�[�^�̍폜�@�\�̃e�X�g�ł�.\n
*				�s���ȃC�e���[�^��n�����ۂ̋������m�F���Ă��܂��D\n
*				�����N����Ȃ���ΐ����ł��D\n
*/
TEST(RemoveDataTest, WhenRemoveWithNotAvailableIterator) {
	TestDoublyLinkedList list;
	createListHavingElements(list, 1);
	
	TestDoublyLinkedList::Iterator it;
	EXPECT_FALSE(list.remove(it));	//���X�g�ւ̎Q�Ƃ��Ȃ��C�e���[�^��n�����ꍇ

	TestDoublyLinkedList listOther;
	TestDoublyLinkedList::Iterator itOther = listOther.begin();
	EXPECT_FALSE(list.remove(itOther));	//�ʂ̃��X�g�̃C�e���[�^��n�����ꍇ
}


//=================================== �擪�C�e���[�^�̎擾 ===================================

/**
*	@brief		���X�g����ł���ꍇ�ɁC�擪�C�e���[�^���擾�����ۂ̃e�X�g
*	@details	ID:���X�g-23\n
*				�擪�C�e���[�^�̎擾�@�\�̃e�X�g�ł�.\n
*				���X�g����ł���ꍇ�ɁC�擪�C�e���[�^���擾�����ۂ̋������m�F���Ă��܂�.\n
*				���X�g�擪�̃_�~�[���w���C�e���[�^���Ԃ�ΐ����ł��D\n
*/
TEST(GetFirstIteratorTest, WhenGetFirstIteratorFromEmptyList) {
	TestDoublyLinkedList list;
	TestDoublyLinkedList::Iterator itFirst = list.begin();
	
	bool isEqual = (itFirst == list.begin());
	EXPECT_TRUE(isEqual);
}

/**
*	@brief		���X�g�ɗv�f��1����ꍇ�ɁC�擪�C�e���[�^���擾�����ۂ̃e�X�g
*	@details	ID:���X�g-24\n
*				�擪�C�e���[�^�̎擾�@�\�̃e�X�g�ł�.\n
*				���X�g�ɗv�f��1����ꍇ�ɁC�擪�C�e���[�^���擾�����ۂ̋������m�F���Ă��܂�.\n
*				���X�g�̐擪�v�f���w���C�e���[�^���Ԃ�ΐ����ł��D\n
*/
TEST(GetFirstIteratorTest, WhenGetFirstIteratorFromListHavingAElement) {
	TestDoublyLinkedList list;
	createListHavingElements(list, 1);

	TestDoublyLinkedList::Iterator itFirstElement = list.begin();

	bool isEqual = (itFirstElement == list.begin());
	EXPECT_TRUE(isEqual);
}

/**
*	@brief		���X�g��2�ȏ�̗v�f������ꍇ�ɁC�擪�C�e���[�^���擾�����ۂ̃e�X�g
*	@details	ID:���X�g-25\n
*				�擪�C�e���[�^�̎擾�@�\�̃e�X�g�ł�.\n
*				���X�g��2�ȏ�̗v�f������ꍇ�ɁC�擪�C�e���[�^���擾�����ۂ̋������m�F���Ă��܂�.\n
*				���X�g�̐擪�v�f���w���C�e���[�^���Ԃ�ΐ����ł��D\n
*/
TEST(GetFirstIteratorTest, WhenGetFirstIteratorFromListHavingElements) {
	TestDoublyLinkedList list;
	createListHavingElements(list, 3);

	TestDoublyLinkedList::Iterator itFirst = list.begin();

	bool isEqual = (itFirst == list.begin());
	EXPECT_TRUE(isEqual);
}

/**
*	@brief		�f�[�^�}�����s������ɁC�擪�C�e���[�^���擾�����ۂ̃e�X�g
*	@details	ID:���X�g-26-1\n
*				�擪�C�e���[�^�̎擾�@�\�̃e�X�g�ł�.\n
*				�擪�v�f�̌���փf�[�^�}���s������ɁC�擪�C�e���[�^���擾�����ۂ̋������m�F���Ă��܂�.\n
*				���X�g�̐擪�v�f���w���C�e���[�^���Ԃ�ΐ����ł��D\n
*/
TEST(GetFirstIteratorTest, WhenGetFirstIteratorFromListInsertedElementBackOfFirstElement) {
	TestDoublyLinkedList list;
	createListHavingElements(list, 3);

	TestDoublyLinkedList::Iterator itFirstElement = list.begin();	//�}���O�̐擪�v�f���w���C�e���[�^
	TestDoublyLinkedList::Iterator itInsert = list.begin();	//�}���ꏊ���w���C�e���[�^
	++itInsert;

	ScoreData newScoreData("100", "newData");
	ASSERT_TRUE(list.insert(itInsert, newScoreData));

	bool isEqual = (itFirstElement == list.begin());
	EXPECT_TRUE(isEqual);
}

/**
*	@brief		�f�[�^�}�����s������ɁC�擪�C�e���[�^���擾�����ۂ̃e�X�g
*	@details	ID:���X�g-26-2\n
*				�擪�C�e���[�^�̎擾�@�\�̃e�X�g�ł�.\n
*				�����̗v�f�̌���փf�[�^�}���s������ɁC�擪�C�e���[�^���擾�����ۂ̋������m�F���Ă��܂�.\n
*				���X�g�̐擪�v�f���w���C�e���[�^���Ԃ�ΐ����ł��D\n
*/
TEST(GetFirstIteratorTest, WhenGetFirstIteratorFromListInsertedElementBackOfCenterElement) {
	TestDoublyLinkedList list;
	createListHavingElements(list, 3);

	TestDoublyLinkedList::Iterator itFirstElement = list.begin();	//�}���O�̐擪�v�f���w���C�e���[�^
	TestDoublyLinkedList::Iterator itInsert = list.begin();	//�}���ꏊ���w���C�e���[�^
	++itInsert;	//�����̗v�f�ֈړ�
	++itInsert;	//�����v�f�ֈړ�

	ScoreData newScoreData("100", "newData");
	ASSERT_TRUE(list.insert(itInsert, newScoreData));

	bool isEqual = (itFirstElement == list.begin());
	EXPECT_TRUE(isEqual);
}

/**
*	@brief		�f�[�^�}�����s������ɁC�擪�C�e���[�^���擾�����ۂ̃e�X�g
*	@details	ID:���X�g-26-3\n
*				�擪�C�e���[�^�̎擾�@�\�̃e�X�g�ł�.\n
*				�����v�f�̌���փf�[�^�}���s������ɁC�擪�C�e���[�^���擾�����ۂ̋������m�F���Ă��܂�.\n
*				���X�g�̐擪�v�f���w���C�e���[�^���Ԃ�ΐ����ł��D\n
*/
TEST(GetFirstIteratorTest, WhenGetFirstIteratorFromListInsertedElementBackOfLastElement) {
	TestDoublyLinkedList list;
	createListHavingElements(list, 3);

	TestDoublyLinkedList::Iterator itFirstElement = list.begin();	//�}���O�̐擪�v�f���w���C�e���[�^
	TestDoublyLinkedList::Iterator itInsert = list.end();	//�}���ꏊ���w���C�e���[�^

	ScoreData newScoreData("100", "newData");
	ASSERT_TRUE(list.insert(itInsert, newScoreData));

	bool isEqual = (itFirstElement == list.begin());
	EXPECT_TRUE(isEqual);
}

/**
*	@brief		�f�[�^�폜���s������ɁC�擪�C�e���[�^���擾�����ۂ̃e�X�g
*	@details	ID:���X�g-27-1\n
*				�擪�C�e���[�^�̎擾�@�\�̃e�X�g�ł�.\n
*				�擪�v�f�̍폜���s������ɁC�擪�C�e���[�^���擾�����ۂ̋������m�F���Ă��܂�.\n
*				���X�g�̐擪�v�f���w���C�e���[�^���Ԃ�ΐ����ł��D\n
*/
TEST(GetFirstIteratorTest, WhenGetFirstIteratorFromListRemovedFirstElement) {
	TestDoublyLinkedList list;
	createListHavingElements(list, 3);

	TestDoublyLinkedList::Iterator itCenterElement = list.begin();	//�폜�O�̒����̗v�f���w���C�e���[�^
	++itCenterElement;	//�����̗v�f�ֈړ�
	TestDoublyLinkedList::Iterator itRemove = list.begin();	//�폜�ꏊ���w���C�e���[�^

	ASSERT_TRUE(list.remove(itRemove));

	bool isEqual = (itCenterElement == list.begin());	//�擪�v�f���폜����Ă���΁C�폜�O�̒����̗v�f���擪�ɂȂ�͂�
	EXPECT_TRUE(isEqual);
}

/**
*	@brief		�f�[�^�폜���s������ɁC�擪�C�e���[�^���擾�����ۂ̃e�X�g
*	@details	ID:���X�g-27-2\n
*				�擪�C�e���[�^�̎擾�@�\�̃e�X�g�ł�.\n
*				�����̗v�f�̍폜���s������ɁC�擪�C�e���[�^���擾�����ۂ̋������m�F���Ă��܂�.\n
*				���X�g�̐擪�v�f���w���C�e���[�^���Ԃ�ΐ����ł��D\n
*/
TEST(GetFirstIteratorTest, WhenGetFirstIteratorFromListRemovedCenterElement) {
	TestDoublyLinkedList list;
	createListHavingElements(list, 3);

	TestDoublyLinkedList::Iterator itFirstElement = list.begin();	//�폜�O�̐擪�v�f���w���C�e���[�^
	TestDoublyLinkedList::Iterator itRemove = list.begin();	//�폜�ꏊ���w���C�e���[�^
	++itRemove;	//�����̗v�f�ֈړ�

	ASSERT_TRUE(list.remove(itRemove));

	bool isEqual = (itFirstElement == list.begin());
	EXPECT_TRUE(isEqual);
}

/**
*	@brief		�f�[�^�폜���s������ɁC�擪�C�e���[�^���擾�����ۂ̃e�X�g
*	@details	ID:���X�g-27-3\n
*				�擪�C�e���[�^�̎擾�@�\�̃e�X�g�ł�.\n
*				�����v�f�̍폜���s������ɁC�擪�C�e���[�^���擾�����ۂ̋������m�F���Ă��܂�.\n
*				���X�g�̐擪�v�f���w���C�e���[�^���Ԃ�ΐ����ł��D\n
*/
TEST(GetFirstIteratorTest, WhenGetFirstIteratorFromListRemovedLastElement) {
	TestDoublyLinkedList list;
	createListHavingElements(list, 3);

	TestDoublyLinkedList::Iterator itFirst = list.begin();	//�폜�O�̐擪�v�f���w���C�e���[�^
	TestDoublyLinkedList::Iterator itRemove = list.end();	//�폜�ꏊ���w���C�e���[�^
	--itRemove;	//�����v�f�ֈړ�

	ASSERT_TRUE(list.remove(itRemove));

	bool isEqual = (itFirst == list.begin());
	EXPECT_TRUE(isEqual);
}

//=================================== �擪�R���X�g�C�e���[�^�̎擾 ===================================

/**
*	@brief		���X�g����ł���ꍇ�ɁC�擪�R���X�g�C�e���[�^���擾�����ۂ̃e�X�g
*	@details	ID:���X�g-29\n
*				�擪�R���X�g�C�e���[�^�̎擾�@�\�̃e�X�g�ł�.\n
*				���X�g����ł���ꍇ�ɁC�擪�R���X�g�C�e���[�^���擾�����ۂ̋������m�F���Ă��܂�.\n
*				���X�g�擪�̃_�~�[���w���R���X�g�C�e���[�^���Ԃ�ΐ����ł��D\n
*/
TEST(GetFirstConstIteratorTest, WhenGetFirstConstIteratorFromEmptyList) {
	TestDoublyLinkedList list;
	TestDoublyLinkedList::ConstIterator cItFirst = list.cbegin();

	bool isEqual = (cItFirst == list.cbegin());
	EXPECT_TRUE(isEqual);
}

/**
*	@brief		���X�g�ɗv�f��1����ꍇ�ɁC�擪�R���X�g�C�e���[�^���擾�����ۂ̃e�X�g
*	@details	ID:���X�g-30\n
*				�擪�R���X�g�C�e���[�^�̎擾�@�\�̃e�X�g�ł�.\n
*				���X�g�ɗv�f��1����ꍇ�ɁC�擪�R���X�g�C�e���[�^���擾�����ۂ̋������m�F���Ă��܂�.\n
*				���X�g�̐擪�v�f���w���R���X�g�C�e���[�^���Ԃ�ΐ����ł��D\n
*/
TEST(GetFirstConstIteratorTest, WhenGetFirstConstIteratorFromListHavingAElement) {
	TestDoublyLinkedList list;
	createListHavingElements(list, 1);

	TestDoublyLinkedList::ConstIterator cItFirstElement = list.cbegin();

	bool isEqual = (cItFirstElement == list.cbegin());
	EXPECT_TRUE(isEqual);
}

/**
*	@brief		���X�g��2�ȏ�̗v�f������ꍇ�ɁC�擪�R���X�g�C�e���[�^���擾�����ۂ̃e�X�g
*	@details	ID:���X�g-31\n
*				�擪�R���X�g�C�e���[�^�̎擾�@�\�̃e�X�g�ł�.\n
*				���X�g��2�ȏ�̗v�f������ꍇ�ɁC�擪�R���X�g�C�e���[�^���擾�����ۂ̋������m�F���Ă��܂�.\n
*				���X�g�̐擪�v�f���w���R���X�g�C�e���[�^���Ԃ�ΐ����ł��D\n
*/
TEST(GetFirstConstIteratorTest, WhenGetFirstConstIteratorFromListHavingElements) {
	TestDoublyLinkedList list;
	createListHavingElements(list, 3);

	TestDoublyLinkedList::ConstIterator cItFirstElement = list.cbegin();

	bool isEqual = (cItFirstElement == list.cbegin());
	EXPECT_TRUE(isEqual);
}

/**
*	@brief		�f�[�^�}�����s������ɁC�擪�R���X�g�C�e���[�^���擾�����ۂ̃e�X�g
*	@details	ID:���X�g-32-1\n
*				�擪�R���X�g�C�e���[�^�̎擾�@�\�̃e�X�g�ł�.\n
*				�擪�v�f�̌���փf�[�^�}���s������ɁC�擪�R���X�g�C�e���[�^���擾�����ۂ̋������m�F���Ă��܂�.\n
*				���X�g�̐擪�v�f���w���R���X�g�C�e���[�^���Ԃ�ΐ����ł��D\n
*/
TEST(GetFirstConstIteratorTest, WhenGetFirstConstIteratorFromListInsertedElementBackOfFirstElement) {
	TestDoublyLinkedList list;
	createListHavingElements(list, 3);

	TestDoublyLinkedList::ConstIterator cItFirstElement = list.cbegin();	//�}���O�̐擪�v�f���w���R���X�g�C�e���[�^
	TestDoublyLinkedList::ConstIterator cItInsert = list.cbegin();	//�}���ꏊ���w���R���X�g�C�e���[�^
	++cItInsert;	//�����̗v�f�ֈړ�

	ScoreData newScoreData("100", "newData");
	ASSERT_TRUE(list.insert(cItInsert, newScoreData));

	bool isEqual = (cItFirstElement == list.cbegin());
	EXPECT_TRUE(isEqual);
}

/**
*	@brief		�f�[�^�}�����s������ɁC�擪�R���X�g�C�e���[�^���擾�����ۂ̃e�X�g
*	@details	ID:���X�g-32-2\n
*				�擪�R���X�g�C�e���[�^�̎擾�@�\�̃e�X�g�ł�.\n
*				�����̗v�f�̌���փf�[�^�}���s������ɁC�擪�R���X�g�C�e���[�^���擾�����ۂ̋������m�F���Ă��܂�.\n
*				���X�g�̐擪�v�f���w���R���X�g�C�e���[�^���Ԃ�ΐ����ł��D\n
*/
TEST(GetFirstConstIteratorTest, WhenGetFirstConstIteratorFromListInsertedElementBackOfCenterElement) {
	TestDoublyLinkedList list;
	createListHavingElements(list, 3);

	TestDoublyLinkedList::ConstIterator cItFirstElement = list.cbegin();	//�}���O�̐擪�v�f���w���R���X�g�C�e���[�^
	TestDoublyLinkedList::ConstIterator cItInsert = list.cbegin();	//�}���ꏊ���w���R���X�g�C�e���[�^
	++cItInsert;	//�����̗v�f�ֈړ�
	++cItInsert;	//�����v�f�ֈړ�

	ScoreData newScoreData("100", "newData");
	ASSERT_TRUE(list.insert(cItInsert, newScoreData));

	bool isEqual = (cItFirstElement == list.cbegin());
	EXPECT_TRUE(isEqual);
}

/**
*	@brief		�f�[�^�}�����s������ɁC�擪�R���X�g�C�e���[�^���擾�����ۂ̃e�X�g
*	@details	ID:���X�g-32-3\n
*				�擪�R���X�g�C�e���[�^�̎擾�@�\�̃e�X�g�ł�.\n
*				�����v�f�̌���փf�[�^�}���s������ɁC�擪�R���X�g�C�e���[�^���擾�����ۂ̋������m�F���Ă��܂�.\n
*				���X�g�̐擪�v�f���w���R���X�g�C�e���[�^���Ԃ�ΐ����ł��D\n
*/
TEST(GetFirstConstIteratorTest, WhenGetFirstConstIteratorFromListInsertedElementBackOfLastElement) {
	TestDoublyLinkedList list;
	createListHavingElements(list, 3);

	TestDoublyLinkedList::ConstIterator cItFirstElement = list.cbegin();	//�}���O�̐擪�v�f���w���R���X�g�C�e���[�^
	TestDoublyLinkedList::ConstIterator cItInsert = list.cend();	//�}���ꏊ���w���R���X�g�C�e���[�^

	ScoreData newScoreData("100", "newData");
	ASSERT_TRUE(list.insert(cItInsert, newScoreData));

	bool isEqual = (cItFirstElement == list.cbegin());
	EXPECT_TRUE(isEqual);
}

/**
*	@brief		�f�[�^�폜���s������ɁC�擪�R���X�g�C�e���[�^���擾�����ۂ̃e�X�g
*	@details	ID:���X�g-33-1\n
*				�擪�R���X�g�C�e���[�^�̎擾�@�\�̃e�X�g�ł�.\n
*				�擪�v�f�̍폜���s������ɁC�擪�R���X�g�C�e���[�^���擾�����ۂ̋������m�F���Ă��܂�.\n
*				���X�g�̐擪�v�f���w���R���X�g�C�e���[�^���Ԃ�ΐ����ł��D\n
*/
TEST(GetFirstConstIteratorTest, WhenGetFirstConstIteratorFromListRemovedFirstElement) {
	TestDoublyLinkedList list;
	createListHavingElements(list, 3);

	TestDoublyLinkedList::ConstIterator cItCenterElement = list.cbegin();	//�폜�O�̒����̗v�f���w���R���X�g�C�e���[�^
	++cItCenterElement;	//�����̗v�f�ֈړ�
	TestDoublyLinkedList::ConstIterator cItRemove = list.cbegin();	//�폜�ꏊ���w���R���X�g�C�e���[�^

	ASSERT_TRUE(list.remove(cItRemove));

	bool isEqual = (cItCenterElement == list.cbegin());	//�擪�v�f���폜����Ă���΁C�폜�O�̒����̗v�f���擪�ɂȂ�͂�
	EXPECT_TRUE(isEqual);
}

/**
*	@brief		�f�[�^�폜���s������ɁC�擪�R���X�g�C�e���[�^���擾�����ۂ̃e�X�g
*	@details	ID:���X�g-33-2\n
*				�擪�R���X�g�C�e���[�^�̎擾�@�\�̃e�X�g�ł�.\n
*				�����̗v�f�̍폜���s������ɁC�擪�R���X�g�C�e���[�^���擾�����ۂ̋������m�F���Ă��܂�.\n
*				���X�g�̐擪�v�f���w���R���X�g�C�e���[�^���Ԃ�ΐ����ł��D\n
*/
TEST(GetFirstConstIteratorTest, WhenGetFirstConstIteratorFromListRemovedCenterElement) {
	TestDoublyLinkedList list;
	createListHavingElements(list, 3);

	TestDoublyLinkedList::ConstIterator cItFirstElement = list.cbegin();	//�폜�O�̐擪�v�f���w���R���X�g�C�e���[�^
	TestDoublyLinkedList::ConstIterator cItRemove = list.cbegin();	//�폜�ꏊ���w���R���X�g�C�e���[�^
	++cItRemove;	//�����̗v�f�ֈړ�

	ASSERT_TRUE(list.remove(cItRemove));

	bool isEqual = (cItFirstElement == list.cbegin());
	EXPECT_TRUE(isEqual);
}

/**
*	@brief		�f�[�^�폜���s������ɁC�擪�R���X�g�C�e���[�^���擾�����ۂ̃e�X�g
*	@details	ID:���X�g-33-3\n
*				�擪�R���X�g�C�e���[�^�̎擾�@�\�̃e�X�g�ł�.\n
*				�����v�f�̍폜���s������ɁC�擪�R���X�g�C�e���[�^���擾�����ۂ̋������m�F���Ă��܂�.\n
*				���X�g�̐擪�v�f���w���R���X�g�C�e���[�^���Ԃ�ΐ����ł��D\n
*/
TEST(GetFirstConstIteratorTest, WhenGetFirstConstIteratorFromListRemovedLastElement) {
	TestDoublyLinkedList list;
	createListHavingElements(list, 3);

	TestDoublyLinkedList::ConstIterator cItFirstElement = list.cbegin();	//�폜�O�̐擪�v�f���w���R���X�g�C�e���[�^
	TestDoublyLinkedList::ConstIterator cItRemove = list.cend();	//�폜�ꏊ���w���R���X�g�C�e���[�^
	--cItRemove;	//�����v�f�ֈړ�

	ASSERT_TRUE(list.remove(cItRemove));

	bool isEqual = (cItFirstElement == list.cbegin());
	EXPECT_TRUE(isEqual);
}


//=================================== �����C�e���[�^�̎擾 ===================================

/**
*	@brief		���X�g����ł���ꍇ�ɁC�����C�e���[�^���擾�����ۂ̃e�X�g
*	@details	ID:���X�g-35\n
*				�����C�e���[�^�̎擾�@�\�̃e�X�g�ł�.\n
*				���X�g����ł���ꍇ�ɁC�����C�e���[�^���擾�����ۂ̋������m�F���Ă��܂�.\n
*				���X�g�����̃_�~�[���w���C�e���[�^���Ԃ�ΐ����ł��D\n
*/
TEST(GetLastIteratorTest, WhenGetLastIteratorFromEmptyList) {
	TestDoublyLinkedList list;
	TestDoublyLinkedList::Iterator itLast = list.end();

	bool isEqual = (itLast == list.end());
	EXPECT_TRUE(isEqual);
}

/**
*	@brief		���X�g�ɗv�f��1����ꍇ�ɁC�����C�e���[�^���擾�����ۂ̃e�X�g
*	@details	ID:���X�g-36\n
*				�����C�e���[�^�̎擾�@�\�̃e�X�g�ł�.\n
*				���X�g�ɗv�f��1����ꍇ�ɁC�����C�e���[�^���擾�����ۂ̋������m�F���Ă��܂�.\n
*				���X�g�̖����v�f���w���C�e���[�^���Ԃ�ΐ����ł��D\n
*/
TEST(GetLastIteratorTest, WhenGetLastIteratorFromListHavingAElement) {
	TestDoublyLinkedList list;
	createListHavingElements(list, 1);

	TestDoublyLinkedList::Iterator itLastElement = list.end();
	--itLastElement;	//�����v�f�ֈړ�

	ScoreData lastElement("0", "test0");	//�����v�f
	bool isEqual = (*(itLastElement) == lastElement);
	EXPECT_TRUE(isEqual);
}

/**
*	@brief		���X�g��2�ȏ�̗v�f������ꍇ�ɁC�����C�e���[�^���擾�����ۂ̃e�X�g
*	@details	ID:���X�g-37\n
*				�����C�e���[�^�̎擾�@�\�̃e�X�g�ł�.\n
*				���X�g��2�ȏ�̗v�f������ꍇ�ɁC�����C�e���[�^���擾�����ۂ̋������m�F���Ă��܂�.\n
*				���X�g�̖����v�f���w���C�e���[�^���Ԃ�ΐ����ł��D\n
*/
TEST(GetLastIteratorTest, WhenGetLastIteratorFromListHavingElements) {
	TestDoublyLinkedList list;
	createListHavingElements(list, 3);

	TestDoublyLinkedList::Iterator itLastElement = list.end();
	--itLastElement;	//�����v�f�ֈړ�

	ScoreData lastElement("2", "test2");	//�����v�f
	bool isEqual = ((*itLastElement) == lastElement);
	EXPECT_TRUE(isEqual);
}

/**
*	@brief		�f�[�^�}�����s������ɁC�����C�e���[�^���擾�����ۂ̃e�X�g
*	@details	ID:���X�g-38-1\n
*				�����C�e���[�^�̎擾�@�\�̃e�X�g�ł�.\n
*				�擪�v�f�̌���փf�[�^�}���s������ɁC�����C�e���[�^���擾�����ۂ̋������m�F���Ă��܂�.\n
*				���X�g�̖����v�f���w���C�e���[�^���Ԃ�ΐ����ł��D\n
*/
TEST(GetLastIteratorTest, WhenGetLastIteratorFromListInsertedElementBackOfFirstElement) {
	TestDoublyLinkedList list;
	createListHavingElements(list, 3);

	TestDoublyLinkedList::Iterator itLast = list.end();	//�}���O�̖����_�~�[���w���C�e���[�^
	TestDoublyLinkedList::Iterator itInsert = list.begin();	//�}���ꏊ���w���C�e���[�^
	++itInsert;	//����ֈړ�

	ScoreData newScoreData("100", "newData");
	ASSERT_TRUE(list.insert(itInsert, newScoreData));


	bool isEqual = (itLast == list.end());
	EXPECT_TRUE(isEqual);
}

/**
*	@brief		�f�[�^�}�����s������ɁC�����C�e���[�^���擾�����ۂ̃e�X�g
*	@details	ID:���X�g-38-2\n
*				�����C�e���[�^�̎擾�@�\�̃e�X�g�ł�.\n
*				�����̗v�f�̌���փf�[�^�}���s������ɁC�����C�e���[�^���擾�����ۂ̋������m�F���Ă��܂�.\n
*				���X�g�̖����v�f���w���C�e���[�^���Ԃ�ΐ����ł��D\n
*/
TEST(GetLastIteratorTest, WhenGetLastIteratorFromListInsertedElementBackOfCenterElement) {
	TestDoublyLinkedList list;
	createListHavingElements(list, 3);

	TestDoublyLinkedList::Iterator itLast = list.end();	//�}���O�̖����_�~�[���w���C�e���[�^
	TestDoublyLinkedList::Iterator itInsert = list.begin();	//�}���ꏊ���w���C�e���[�^
	++itInsert;	//�����̗v�f�ֈړ�
	++itInsert;	//����ֈړ�

	ScoreData newScoreData("100", "newData");
	ASSERT_TRUE(list.insert(itInsert, newScoreData));

	bool isEqual = (itLast == list.end());
	EXPECT_TRUE(isEqual);
}

/**
*	@brief		�f�[�^�}�����s������ɁC�����C�e���[�^���擾�����ۂ̃e�X�g
*	@details	ID:���X�g-38-3\n
*				�����C�e���[�^�̎擾�@�\�̃e�X�g�ł�.\n
*				�����v�f�̌���փf�[�^�}���s������ɁC�����C�e���[�^���擾�����ۂ̋������m�F���Ă��܂�.\n
*				���X�g�̖����v�f���w���C�e���[�^���Ԃ�ΐ����ł��D\n
*/
TEST(GetLastIteratorTest, WhenGetLastIteratorFromListInsertedElementBackOfLastElement) {
	TestDoublyLinkedList list;
	createListHavingElements(list, 3);

	TestDoublyLinkedList::Iterator itLast = list.end();	//�}���O�̖����_�~�[���w���C�e���[�^
	TestDoublyLinkedList::Iterator itInsert = list.end();	//�}���ꏊ���w���C�e���[�^

	ScoreData newScoreData("100", "newData");
	ASSERT_TRUE(list.insert(itInsert, newScoreData));

	bool isEqual = (itLast == list.end());
	EXPECT_TRUE(isEqual);
}

/**
*	@brief		�f�[�^�폜���s������ɁC�����C�e���[�^���擾�����ۂ̃e�X�g
*	@details	ID:���X�g-39-1\n
*				�����C�e���[�^�̎擾�@�\�̃e�X�g�ł�.\n
*				�擪�v�f�̍폜���s������ɁC�����C�e���[�^���擾�����ۂ̋������m�F���Ă��܂�.\n
*				���X�g�̖����v�f���w���C�e���[�^���Ԃ�ΐ����ł��D\n
*/
TEST(GetLastIteratorTest, WhenGetLastIteratorFromListRemovedFirstElement) {
	TestDoublyLinkedList list;
	createListHavingElements(list, 3);

	TestDoublyLinkedList::Iterator itLast = list.end();	//�폜�O�̖����_�~�[���w���C�e���[�^
	TestDoublyLinkedList::Iterator itRemove = list.begin();	//�폜�ꏊ���w���C�e���[�^

	ASSERT_TRUE(list.remove(itRemove));

	bool isEqual = (itLast == list.end());
	EXPECT_TRUE(isEqual);
}

/**
*	@brief		�f�[�^�폜���s������ɁC�����C�e���[�^���擾�����ۂ̃e�X�g
*	@details	ID:���X�g-39-2\n
*				�����C�e���[�^�̎擾�@�\�̃e�X�g�ł�.\n
*				�����̗v�f�̍폜���s������ɁC�����C�e���[�^���擾�����ۂ̋������m�F���Ă��܂�.\n
*				���X�g�̖����v�f���w���C�e���[�^���Ԃ�ΐ����ł��D\n
*/
TEST(GetLastIteratorTest, WhenGetLastIteratorFromListRemovedCenterElement) {
	TestDoublyLinkedList list;
	createListHavingElements(list, 3);

	TestDoublyLinkedList::Iterator itLast = list.end();	//�폜�O�̖����_�~�[���w���C�e���[�^
	TestDoublyLinkedList::Iterator itRemove = list.begin();	//�폜�ꏊ���w���C�e���[�^
	++itRemove;	//�����̗v�f�ֈړ�

	ASSERT_TRUE(list.remove(itRemove));

	bool isEqual = (itLast == list.end());
	EXPECT_TRUE(isEqual);
}

/**
*	@brief		�f�[�^�폜���s������ɁC�����C�e���[�^���擾�����ۂ̃e�X�g
*	@details	ID:���X�g-39-3\n
*				�����C�e���[�^�̎擾�@�\�̃e�X�g�ł�.\n
*				�����v�f�̍폜���s������ɁC�����C�e���[�^���擾�����ۂ̋������m�F���Ă��܂�.\n
*				���X�g�̖����v�f���w���C�e���[�^���Ԃ�ΐ����ł��D\n
*/
TEST(GetLastIteratorTest, WhenGetLastIteratorFromListRemovedLastElement) {
	TestDoublyLinkedList list;
	createListHavingElements(list, 3);

	TestDoublyLinkedList::Iterator itLast = list.end();	//�폜�O�̖����_�~�[���w���C�e���[�^
	TestDoublyLinkedList::Iterator itRemove = list.end();	//�폜�ꏊ���w���C�e���[�^
	--itRemove;	//�����v�f�ֈړ�

	ASSERT_TRUE(list.remove(itRemove));

	bool isEqual = (itLast == list.end());
	EXPECT_TRUE(isEqual);
}

//=================================== �����R���X�g�C�e���[�^�̎擾 ===================================

/**
*	@brief		���X�g����ł���ꍇ�ɁC�����R���X�g�C�e���[�^���擾�����ۂ̃e�X�g
*	@details	ID:���X�g-41\n
*				�����R���X�g�C�e���[�^�̎擾�@�\�̃e�X�g�ł�.\n
*				���X�g����ł���ꍇ�ɁC�����R���X�g�C�e���[�^���擾�����ۂ̋������m�F���Ă��܂�.\n
*				���X�g�����̃_�~�[���w���R���X�g�C�e���[�^���Ԃ�ΐ����ł��D\n
*/
TEST(GetLastConstIteratorTest, WhenGetLastConstIteratorFromEmptyList) {
	TestDoublyLinkedList list;
	TestDoublyLinkedList::ConstIterator cItLast = list.cend();

	bool isEqual = (cItLast == list.cend());
	EXPECT_TRUE(isEqual);
}

/**
*	@brief		���X�g�ɗv�f��1����ꍇ�ɁC�����R���X�g�C�e���[�^���擾�����ۂ̃e�X�g
*	@details	ID:���X�g-42\n
*				�����R���X�g�C�e���[�^�̎擾�@�\�̃e�X�g�ł�.\n
*				���X�g�ɗv�f��1����ꍇ�ɁC�����R���X�g�C�e���[�^���擾�����ۂ̋������m�F���Ă��܂�.\n
*				���X�g�̖����v�f���w���R���X�g�C�e���[�^���Ԃ�ΐ����ł��D\n
*/
TEST(GetLastConstIteratorTest, WhenGetLastConstIteratorFromListHavingAElement) {
	TestDoublyLinkedList list;
	createListHavingElements(list, 1);

	TestDoublyLinkedList::ConstIterator cItLastElement = list.cend();
	--cItLastElement;

	ScoreData lastElement("0", "test0");	//�����v�f
	bool isEqual = ((*cItLastElement) == lastElement);
	EXPECT_TRUE(isEqual);
}

/**
*	@brief		���X�g��2�ȏ�̗v�f������ꍇ�ɁC�����R���X�g�C�e���[�^���擾�����ۂ̃e�X�g
*	@details	ID:���X�g-43\n
*				�����R���X�g�C�e���[�^�̎擾�@�\�̃e�X�g�ł�.\n
*				���X�g��2�ȏ�̗v�f������ꍇ�ɁC�����R���X�g�C�e���[�^���擾�����ۂ̋������m�F���Ă��܂�.\n
*				���X�g�̖����v�f���w���R���X�g�C�e���[�^���Ԃ�ΐ����ł��D\n
*/
TEST(GetLastConstIteratorTest, WhenGetLastConstIteratorFromListHavingElements) {
	TestDoublyLinkedList list;
	createListHavingElements(list, 3);

	TestDoublyLinkedList::ConstIterator cItLastElement = list.cend();
	--cItLastElement;

	ScoreData lastElement("2", "test2");	//�����v�f
	bool isEqual = ((*cItLastElement) == lastElement);
	EXPECT_TRUE(isEqual);
}

/**
*	@brief		�f�[�^�}�����s������ɁC�����R���X�g�C�e���[�^���擾�����ۂ̃e�X�g
*	@details	ID:���X�g-44-1\n
*				�����R���X�g�C�e���[�^�̎擾�@�\�̃e�X�g�ł�.\n
*				�擪�v�f�̌���փf�[�^�}���s������ɁC�����R���X�g�C�e���[�^���擾�����ۂ̋������m�F���Ă��܂�.\n
*				���X�g�̖����v�f���w���R���X�g�C�e���[�^���Ԃ�ΐ����ł��D\n
*/
TEST(GetLastConstIteratorTest, WhenGetLastConstIteratorFromListInsertedElementBackOfFirstElement) {
	TestDoublyLinkedList list;
	createListHavingElements(list, 3);

	TestDoublyLinkedList::ConstIterator cItLast = list.cend();	//�}���O�̖����_�~�[���w���R���X�g�C�e���[�^
	TestDoublyLinkedList::ConstIterator cItInsert = list.cbegin();	//�}���ꏊ���w���R���X�g�C�e���[�^
	++cItInsert;	//����ֈړ�

	ScoreData newScoreData("100", "newData");
	ASSERT_TRUE(list.insert(cItInsert, newScoreData));

	bool isEqual = (cItLast == list.cend());
	EXPECT_TRUE(isEqual);

}

/**
*	@brief		�f�[�^�}�����s������ɁC�����R���X�g�C�e���[�^���擾�����ۂ̃e�X�g
*	@details	ID:���X�g-44-2\n
*				�����R���X�g�C�e���[�^�̎擾�@�\�̃e�X�g�ł�.\n
*				�����̗v�f�̌���փf�[�^�}���s������ɁC�����R���X�g�C�e���[�^���擾�����ۂ̋������m�F���Ă��܂�.\n
*				���X�g�̖����v�f���w���R���X�g�C�e���[�^���Ԃ�ΐ����ł��D\n
*/
TEST(GetLastConstIteratorTest, WhenGetLastConstIteratorFromListInsertedElementBackOfCenterElement) {
	TestDoublyLinkedList list;
	createListHavingElements(list, 3);

	TestDoublyLinkedList::ConstIterator cItLastElement = list.cend();	//�}���O�̖����_�~�[���w���R���X�g�C�e���[�^
	TestDoublyLinkedList::ConstIterator cItInsert = list.cbegin();	//�}���ꏊ���w���R���X�g�C�e���[�^
	++cItInsert;	//�����̗v�f�ֈړ�
	++cItInsert;	//����ֈړ�

	ScoreData newScoreData("100", "newData");
	ASSERT_TRUE(list.insert(cItInsert, newScoreData));

	bool isEqual = (cItLastElement == list.cend());
	EXPECT_TRUE(isEqual);

}

/**
*	@brief		�f�[�^�}�����s������ɁC�����R���X�g�C�e���[�^���擾�����ۂ̃e�X�g
*	@details	ID:���X�g-44-3\n
*				�����R���X�g�C�e���[�^�̎擾�@�\�̃e�X�g�ł�.\n
*				�����v�f�̌���փf�[�^�}���s������ɁC�����R���X�g�C�e���[�^���擾�����ۂ̋������m�F���Ă��܂�.\n
*				���X�g�̖����v�f���w���R���X�g�C�e���[�^���Ԃ�ΐ����ł��D\n
*/
TEST(GetLastConstIteratorTest, WhenGetLastConstIteratorFromListInsertedElementBackOfLastElement) {
	TestDoublyLinkedList list;
	createListHavingElements(list, 3);

	TestDoublyLinkedList::ConstIterator cItLast = list.cend();	//�}���O�̖����_�~�[���w���R���X�g�C�e���[�^
	TestDoublyLinkedList::ConstIterator cItInsert = list.cend();	//�}���ꏊ���w���R���X�g�C�e���[�^

	ScoreData newScoreData("100", "newData");
	ASSERT_TRUE(list.insert(cItInsert, newScoreData));

	bool isEqual = (cItLast == list.cend());
	EXPECT_TRUE(isEqual);
}

/**
*	@brief		�f�[�^�폜���s������ɁC�����R���X�g�C�e���[�^���擾�����ۂ̃e�X�g
*	@details	ID:���X�g-45-1\n
*				�����R���X�g�C�e���[�^�̎擾�@�\�̃e�X�g�ł�.\n
*				�擪�v�f�̍폜���s������ɁC�����R���X�g�C�e���[�^���擾�����ۂ̋������m�F���Ă��܂�.\n
*				���X�g�̖����v�f���w���R���X�g�C�e���[�^���Ԃ�ΐ����ł��D\n
*/
TEST(GetLastConstIteratorTest, WhenGetLastConstIteratorFromListRemovedFirstElement) {
	TestDoublyLinkedList list;
	createListHavingElements(list, 3);

	TestDoublyLinkedList::ConstIterator cItLast = list.cend();	//�폜�O�̖����_�~�[���w���R���X�g�C�e���[�^
	TestDoublyLinkedList::ConstIterator cItRemove = list.cbegin();	//�폜�ꏊ���w���R���X�g�C�e���[�^

	ASSERT_TRUE(list.remove(cItRemove));

	bool isEqual = (cItLast == list.cend());
	EXPECT_TRUE(isEqual);
}

/**
*	@brief		�f�[�^�폜���s������ɁC�����R���X�g�C�e���[�^���擾�����ۂ̃e�X�g
*	@details	ID:���X�g-45-2\n
*				�����R���X�g�C�e���[�^�̎擾�@�\�̃e�X�g�ł�.\n
*				�����̗v�f�̍폜���s������ɁC�����R���X�g�C�e���[�^���擾�����ۂ̋������m�F���Ă��܂�.\n
*				���X�g�̖����v�f���w���R���X�g�C�e���[�^���Ԃ�ΐ����ł��D\n
*/
TEST(GetLastConstIteratorTest, WhenGetLastConstIteratorFromListRemovedCenterElement) {
	TestDoublyLinkedList list;
	createListHavingElements(list, 3);

	TestDoublyLinkedList::ConstIterator cItLastElement = list.cend();	//�폜�O�̖����_�~�[���w���R���X�g�C�e���[�^
	TestDoublyLinkedList::ConstIterator cItRemove = list.cbegin();	//�폜�ꏊ���w���R���X�g�C�e���[�^
	++cItRemove;	//�����̗v�f�ֈړ�

	ASSERT_TRUE(list.remove(cItRemove));

	bool isEqual = (cItLastElement == list.cend());
	EXPECT_TRUE(isEqual);
}

/**
*	@brief		�f�[�^�폜���s������ɁC�����R���X�g�C�e���[�^���擾�����ۂ̃e�X�g
*	@details	ID:���X�g-45-3\n
*				�����R���X�g�C�e���[�^�̎擾�@�\�̃e�X�g�ł�.\n
*				�����v�f�̍폜���s������ɁC�����R���X�g�C�e���[�^���擾�����ۂ̋������m�F���Ă��܂�.\n
*				���X�g�̖����v�f���w���R���X�g�C�e���[�^���Ԃ�ΐ����ł��D\n
*/
TEST(GetLastConstIteratorTest, WhenGetLastConstIteratorFromListRemovedLastElement) {
	TestDoublyLinkedList list;
	createListHavingElements(list, 3);

	TestDoublyLinkedList::ConstIterator cItLast = list.cend();	//�폜�O�̖����_�~�[���w���R���X�g�C�e���[�^
	TestDoublyLinkedList::ConstIterator cItRemove = list.cend();	//�폜�ꏊ���w���R���X�g�C�e���[�^
	--cItRemove;	//�����v�f�ֈړ�

	ASSERT_TRUE(list.remove(cItRemove));

	bool isEqual = (cItLast == list.cend());
	EXPECT_TRUE(isEqual);
}


//=================================== �C�e���[�^�̎w���v�f�̎擾 ===================================

/**
*	@brief		���X�g�̎Q�Ƃ��Ȃ���Ԃŗv�f���擾�����ۂ̃e�X�g
*	@details	ID:Iterator-0-1\n
*				�C�e���[�^�̎w���v�f�̎擾�@�\�̃e�X�g�ł�.\n
*				���X�g�̎Q�Ƃ��Ȃ���ԂŃC�e���[�^�̗v�f���Q�Ƃ����ۂ̋������m�F���Ă��܂�.\n
*				Assert����������ΐ����ł��D\n
*/
#ifdef _DEBUG
TEST(GetElementOfIteratorTest, WhenIteratorHaveNotReferenceToList) {
	TestDoublyLinkedList::Iterator it;
	EXPECT_DEATH((*it), ".*");
}
#endif

/**
*	@brief		���X�g�̎Q�Ƃ��Ȃ���Ԃŗv�f���擾�����ۂ̃e�X�g
*	@details	ID:Iterator-0-2\n
*				�R���X�g�C�e���[�^�̎w���v�f�̎擾�@�\�̃e�X�g�ł�.\n
*				���X�g�̎Q�Ƃ��Ȃ���ԂŃR���X�g�C�e���[�^�̗v�f���Q�Ƃ����ۂ̋������m�F���Ă��܂�.\n
*				Assert����������ΐ����ł��D\n
*/
#ifdef _DEBUG
TEST(GetElementOfIteratorTest, WhenConstIteratorHaveNotReferenceToList) {
	TestDoublyLinkedList::ConstIterator cIt;
	EXPECT_DEATH((*cIt), ".*");
}
#endif

/**
*	@brief		�C�e���[�^����擾�����v�f�ɑ΂��āC�l�̑���������ۂ̃e�X�g
*	@details	ID:Iterator-1\n
*				�C�e���[�^�̎w���v�f�̎擾�@�\�̃e�X�g�ł�.\n
*				�C�e���[�^����擾�����v�f�ɑ΂��āC�l�̑���������ۂ̋������m�F���Ă��܂�.\n
*				�l���ύX����Ă���ΐ����ł��C\n
*/
TEST(GetElementOfIteratorTest, WhenAssignToElementOfIterator) {
	TestDoublyLinkedList list;
	createListHavingElements(list, 1);

	TestDoublyLinkedList::Iterator it = list.begin();

	ScoreData newScoreData("100", "newData");
	*it = newScoreData;

	bool isEqual = ((*it) == newScoreData);
	EXPECT_TRUE(isEqual);
}

/**
*	@brief		��̃��X�g�̐擪�C�e���[�^�̗v�f���擾�����ۂ̃e�X�g
*	@details	ID:Iterator-3-1\n
*				�C�e���[�^�̎w���v�f�̎擾�@�\�̃e�X�g�ł�.\n
*				��̃��X�g�̐擪�C�e���[�^�̗v�f���擾�����ۂ̋������m�F���Ă��܂�.\n
*				Assert����������ΐ����ł��D\n
*/
#ifdef _DEBUG
TEST(GetElementOfIteratorTest, WhenGetElementOfFirstIteratorOfEmptyList) {
	TestDoublyLinkedList list;
	TestDoublyLinkedList::Iterator itFirst = list.begin();
	EXPECT_DEATH((*itFirst), "Assertion failed.*");
}
#endif

/**
*	@brief		��̃��X�g�̐擪�R���X�g�C�e���[�^�̗v�f���擾�����ۂ̃e�X�g
*	@details	ID:Iterator-3-2\n
*				�C�e���[�^�̎w���v�f�̎擾�@�\�̃e�X�g�ł�.\n
*				��̃��X�g�̐擪�R���X�g�C�e���[�^�̗v�f���擾�����ۂ̋������m�F���Ă��܂�.\n
*				Assert����������ΐ����ł��D\n
*/
#ifdef _DEBUG
TEST(GetElementOfIteratorTest, WhenGetElementOfFirstConstIteratorOfEmptyList) {
	TestDoublyLinkedList list;
	TestDoublyLinkedList::ConstIterator cItFirst = list.cbegin();
	EXPECT_DEATH((*cItFirst), "Assertion failed.*");
}
#endif

/**
*	@brief		�����C�e���[�^�̗v�f���擾�����ۂ̃e�X�g
*	@details	ID:Iterator-4-1\n
*				�C�e���[�^�̎w���v�f�̎擾�@�\�̃e�X�g�ł�.\n
*				�����C�e���[�^�̗v�f���擾�����ۂ̋������m�F���Ă��܂�.\n
*				Assert����������ΐ����ł��D\n
*/
#ifdef _DEBUG
TEST(GetElementOfIteratorTest, WhenGetElementOfLastIteratorOfEmptyList) {
	TestDoublyLinkedList list;
	TestDoublyLinkedList::Iterator itLast = list.end();
	EXPECT_DEATH((*itLast), "Assertion failed.*");
}
#endif

/**
*	@brief		�����R���X�g�C�e���[�^�̗v�f���擾�����ۂ̃e�X�g
*	@details	ID:Iterator-4-2\n
*				�C�e���[�^�̎w���v�f�̎擾�@�\�̃e�X�g�ł�.\n
*				�����R���X�g�C�e���[�^�̗v�f���擾�����ۂ̋������m�F���Ă��܂�.\n
*				Assert����������ΐ����ł��D\n
*/
#ifdef _DEBUG
TEST(GetElementOfIteratorTest, WhenGetElementOfLastConstIteratorOfEmptyList) {
	TestDoublyLinkedList list;
	TestDoublyLinkedList::ConstIterator cItLast = list.cend();
	EXPECT_DEATH((*cItLast), "Assertion failed.*");
}
#endif


//=================================== �C�e���[�^�����X�g�����Ɍ������ĂP�i�߂� ===================================

/**
*	@brief		���X�g�̎Q�Ƃ��Ȃ���ԂŃC�e���[�^�����X�g�����Ɍ������ĂP�i�߂�ۂ̃e�X�g
*	@details	ID:Iterator-5-1\n
*				�C�e���[�^�����X�g�����Ɍ������ĂP�i�߂�@�\�̃e�X�g�ł�.\n
*				���X�g�̎Q�Ƃ��Ȃ���ԂŃC�e���[�^�����X�g�����Ɍ������ĂP�i�߂�ۂ̋������m�F���Ă��܂�.\n
*				Assert����������ΐ����ł��D\n
*/
#ifdef _DEBUG
TEST(IncrementIteratorTest, WhenIncrementIteratorHaveNotReferenceToList) {
	TestDoublyLinkedList::Iterator it;
	EXPECT_DEATH(++it, ".*");
}
#endif

/**
*	@brief		���X�g�̎Q�Ƃ��Ȃ���ԂŃR���X�g�C�e���[�^�����X�g�����Ɍ������ĂP�i�߂�ۂ̃e�X�g
*	@details	ID:Iterator-5-2\n
*				�C�e���[�^�����X�g�����Ɍ������ĂP�i�߂�@�\�̃e�X�g�ł�.\n
*				���X�g�̎Q�Ƃ��Ȃ���ԂŃR���X�g�C�e���[�^�����X�g�����Ɍ������ĂP�i�߂�ۂ̋������m�F���Ă��܂�.\n
*				Assert����������ΐ����ł��D\n
*/
#ifdef _DEBUG
TEST(IncrementIteratorTest, WhenIncrementConstIteratorHaveNotReferenceToList) {
	TestDoublyLinkedList::ConstIterator cIt;
	EXPECT_DEATH(++cIt, ".*");
}
#endif

/**
*	@brief		���X�g����̏�ԂŐ擪�C�e���[�^�����X�g�����Ɍ������ĂP�i�߂�ۂ̃e�X�g
*	@details	ID:Iterator-6-1\n
*				�C�e���[�^�����X�g�����Ɍ������ĂP�i�߂�@�\�̃e�X�g�ł�.\n
*				���X�g����̏�ԂŐ擪�C�e���[�^�����X�g�����Ɍ������ĂP�i�߂�ۂ̋������m�F���Ă��܂�.\n
*				Assert����������ΐ����ł��D\n
*/
#ifdef _DEBUG
TEST(IncrementIteratorTest, WhenIncrementFirstIteratorOfEmptyList) {
	TestDoublyLinkedList list;
	TestDoublyLinkedList::Iterator it = list.begin();
	EXPECT_DEATH(++it, "Assertion failed.*");
}
#endif

/**
*	@brief		���X�g����̏�ԂŐ擪�R���X�g�C�e���[�^�����X�g�����Ɍ������ĂP�i�߂�ۂ̃e�X�g
*	@details	ID:Iterator-6-2\n
*				�C�e���[�^�����X�g�����Ɍ������ĂP�i�߂�@�\�̃e�X�g�ł�.\n
*				���X�g����̏�ԂŐ擪�R���X�g�C�e���[�^�����X�g�����Ɍ������ĂP�i�߂�ۂ̋������m�F���Ă��܂�.\n
*				Assert����������ΐ����ł��D\n
*/
#ifdef _DEBUG
TEST(IncrementIteratorTest, WhenIncrementFirstConstIteratorOfEmptyList) {
	TestDoublyLinkedList list;
	TestDoublyLinkedList::ConstIterator cIt = list.cbegin();
	EXPECT_DEATH(++cIt, "Assertion failed.*");
}
#endif

/**
*	@brief		�����C�e���[�^�������1�i�߂�ۂ̃e�X�g
*	@details	ID:Iterator-7-1\n
*				�C�e���[�^������ւP�i�߂�@�\�̃e�X�g�ł�.\n
*				�����C�e���[�^������ւP�i�߂�ۂ̋������m�F���Ă��܂�.\n
*				Assert����������ΐ����ł��D\n
*/
#ifdef _DEBUG
TEST(IncrementIteratorTest, WhenIncrementLastIterator) {
	TestDoublyLinkedList list;
	TestDoublyLinkedList::Iterator it = list.end();
	EXPECT_DEATH(++it, "Assertion failed.*");
}
#endif

/**
*	@brief		�����R���X�g�C�e���[�^�������1�i�߂�ۂ̃e�X�g
*	@details	ID:Iterator-7-2\n
*				�C�e���[�^������ւP�i�߂�@�\�̃e�X�g�ł�.\n
*				�����R���X�g�C�e���[�^������ւP�i�߂�ۂ̋������m�F���Ă��܂�.\n
*				Assert����������ΐ����ł��D\n
*/
#ifdef _DEBUG
TEST(IncrementIteratorTest, WhenIncrementLastConstIterator) {
	TestDoublyLinkedList list;
	TestDoublyLinkedList::ConstIterator cIt = list.cend();
	EXPECT_DEATH(++cIt, "Assertion failed.*");
}
#endif

/**
*	@brief		2�ȏ�̗v�f�����郊�X�g�ɑ΂��C�C�e���[�^��擪���疖���܂ňړ�����ۂ̃e�X�g
*	@details	ID:Iterator-8-1\n
*				�C�e���[�^�����X�g�����Ɍ������ĂP�i�߂�@�\�̃e�X�g�ł�.\n
*				2�ȏ�̗v�f�����郊�X�g�ɑ΂��C�C�e���[�^��擪���疖���܂ňړ�����ۂ̋������m�F���Ă��܂�.\n
*				���X�g�̊e�v�f�Ɋi�[���ꂽ�l����������ΐ����ł��D\n
*/
TEST(IncrementIteratorTest, WhenIncrementIteratorOnListHaveElements) {
	TestDoublyLinkedList list;
	TestDoublyLinkedList::Iterator it = list.begin();
	
	ScoreData scoreData1("1", "test1");
	ScoreData scoreData2("2", "test2");
	ScoreData scoreData3("3", "test3");
	ScoreData scores[] = { scoreData1,scoreData2,scoreData3 };

	for (int i = 0; i < 3; i++) {
		list.insert(it, scores[i]);
	}

	TestDoublyLinkedList::Iterator itIncrement = list.begin();	//�擪���疖���ֈړ�����C�e���[�^
	TestDoublyLinkedList::Iterator itLast = list.end();

	int i = 0;
	while (itIncrement != itLast) {
		bool isEqual = ((*itIncrement) == scores[i]);
		EXPECT_TRUE(isEqual);
		itIncrement++;
		i++;
	}
}

/**
*	@brief		2�ȏ�̗v�f�����郊�X�g�ɑ΂��C�R���X�g�C�e���[�^��擪���疖���܂ňړ�����ۂ̃e�X�g
*	@details	ID:Iterator-8-2\n
*				�C�e���[�^�����X�g�����Ɍ������ĂP�i�߂�@�\�̃e�X�g�ł�.\n
*				2�ȏ�̗v�f�����郊�X�g�ɑ΂��C�R���X�g�C�e���[�^��擪���疖���܂ňړ�����ۂ̋������m�F���Ă��܂�.\n
*				���X�g�̊e�v�f�Ɋi�[���ꂽ�l����������ΐ����ł��D\n
*/
TEST(IncrementIteratorTest, WhenIncrementConstIteratorOnListHaveElements) {
	TestDoublyLinkedList list;
	TestDoublyLinkedList::Iterator it = list.begin();

	ScoreData scoreData1("1", "test1");
	ScoreData scoreData2("2", "test2");
	ScoreData scoreData3("3", "test3");
	ScoreData scores[] = { scoreData1,scoreData2,scoreData3 };

	for (int i = 0; i < 3; i++) {
		list.insert(it, scores[i]);
	}

	TestDoublyLinkedList::ConstIterator cItIncrement = list.cbegin();	//�擪���疖���ֈړ�����R���X�g�C�e���[�^
	TestDoublyLinkedList::ConstIterator cItLast = list.cend();

	int i = 0;
	while (cItIncrement != cItLast) {
		bool isEqual = ((*cItIncrement) == scores[i]);
		EXPECT_TRUE(isEqual);
		cItIncrement++;
		i++;
	}
}

/**
*	@brief		�O�u�C���N�������g���s�����ۂ̃e�X�g
*	@details	ID:Iterator-9-1\n
*				�C�e���[�^�����X�g�����Ɍ������ĂP�i�߂�@�\�̃e�X�g�ł�.\n
*				�C�e���[�^�ɑ΂��āC�O�u�C���N�������g���s�����ۂ̋������m�F���Ă��܂�.\n
*				�C���N�������g�Ăяo�����ƃC���N�������g���s��ł̗����ŁC�����_�~�[���w���Ă���ΐ����ł��D\n
*/
TEST(IncrementIteratorTest, WhenPrefixIncrementIterator) {
	TestDoublyLinkedList list;
	createListHavingElements(list, 1);

	TestDoublyLinkedList::Iterator itIncrement = list.begin();
	TestDoublyLinkedList::Iterator itLast = list.end();

	bool isEqualWhenIncrement = ((++itIncrement) == itLast);
	bool isEqualAfterIncrement = (itIncrement == itLast);

	EXPECT_TRUE(isEqualWhenIncrement == true && isEqualAfterIncrement == true);
}

/**
*	@brief		�O�u�C���N�������g���s�����ۂ̃e�X�g
*	@details	ID:Iterator-9-2\n
*				�C�e���[�^�����X�g�����Ɍ������ĂP�i�߂�@�\�̃e�X�g�ł�.\n
*				�R���X�g�C�e���[�^�ɑ΂��āC�O�u�C���N�������g���s�����ۂ̋������m�F���Ă��܂�.\n
*				�C���N�������g�Ăяo�����ƃC���N�������g���s��̗����ŁC�����_�~�[���w���Ă���ΐ����ł��D\n
*/
TEST(IncrementIteratorTest, WhenPrefixIncrementConstIterator) {
	TestDoublyLinkedList list;
	createListHavingElements(list, 1);

	TestDoublyLinkedList::ConstIterator cItIncrement = list.cbegin();
	TestDoublyLinkedList::ConstIterator cItLast = list.cend();

	bool isEqualWhenIncrement = ((++cItIncrement) == cItLast);
	bool isEqualAfterIncrement = (cItIncrement == cItLast);

	EXPECT_TRUE(isEqualWhenIncrement == true && isEqualAfterIncrement == true);
}

/**
*	@brief		��u�C���N�������g���s�����ۂ̃e�X�g
*	@details	ID:Iterator-10-1\n
*				�C�e���[�^�����X�g�����Ɍ������ĂP�i�߂�@�\�̃e�X�g�ł�.\n
*				�C�e���[�^�ɑ΂��āC��u�C���N�������g���s�����ۂ̋������m�F���Ă��܂�.\n
*				�C���N�������g�Ăяo�����͐擪�v�f���C�C���N�������g���s��͖����_�~�[���w���Ă���ΐ����ł��D\n
*/
TEST(IncrementIteratorTest, WhenPostfixIncrementIterator) {
	TestDoublyLinkedList list;
	createListHavingElements(list, 1);

	TestDoublyLinkedList::Iterator itIncrement = list.begin();
	TestDoublyLinkedList::Iterator itFirstElement = list.begin();
	TestDoublyLinkedList::Iterator itLast = list.end();

	bool isEqualWhenIncrement = ((itIncrement++) == itFirstElement);
	bool isEqualAfterIncrement = (itIncrement == itLast);

	EXPECT_TRUE(isEqualWhenIncrement == true && isEqualAfterIncrement == true);
}

/**
*	@brief		��u�C���N�������g���s�����ۂ̃e�X�g
*	@details	ID:Iterator-10-2\n
*				�C�e���[�^�����X�g�����Ɍ������ĂP�i�߂�@�\�̃e�X�g�ł�.\n
*				�R���X�g�C�e���[�^�ɑ΂��āC��u�C���N�������g���s�����ۂ̋������m�F���Ă��܂�.\n
*				�C���N�������g�Ăяo�����͐擪�v�f���C�C���N�������g���s��͖����_�~�[���w���Ă���ΐ����ł��D\n
*/
TEST(IncrementIteratorTest, WhenPostfixIncrementConstIterator) {
	TestDoublyLinkedList list;
	createListHavingElements(list, 1);

	TestDoublyLinkedList::ConstIterator cItIncrement = list.cbegin();
	TestDoublyLinkedList::ConstIterator cItFirstElement = list.cbegin();
	TestDoublyLinkedList::ConstIterator cItLast = list.cend();

	bool isEqualWhenIncrement = ((cItIncrement++) == cItFirstElement);
	bool isEqualAfterIncrement = (cItIncrement == cItLast);

	EXPECT_TRUE(isEqualWhenIncrement == true && isEqualAfterIncrement == true);
}

//=================================== �C�e���[�^�����X�g�擪�Ɍ������ĂP�i�߂� ===================================

/**
*	@brief		���X�g�̎Q�Ƃ��Ȃ���ԂŃC�e���[�^�����X�g�擪�Ɍ������ĂP�i�߂�ۂ̃e�X�g
*	@details	ID:Iterator-11-1\n
*				�C�e���[�^�����X�g�擪�Ɍ������ĂP�i�߂�@�\�̃e�X�g�ł�.\n
*				���X�g�̎Q�Ƃ��Ȃ���ԂŃC�e���[�^�����X�g�擪�Ɍ������ĂP�i�߂�ۂ̋������m�F���Ă��܂�.\n
*				Assert����������ΐ����ł��D\n
*/
#ifdef _DEBUG
TEST(DecrementIteratorTest, WhenDecrementIteratorHaveNotReferenceToList) {
	TestDoublyLinkedList::Iterator it;
	EXPECT_DEATH(--it, ".*");
}
#endif

/**
*	@brief		���X�g�̎Q�Ƃ��Ȃ���ԂŃR���X�g�C�e���[�^�����X�g�擪�Ɍ������ĂP�i�߂�ۂ̃e�X�g
*	@details	ID:Iterator-11-2\n
*				�C�e���[�^�����X�g�擪�Ɍ������ĂP�i�߂�@�\�̃e�X�g�ł�.\n
*				���X�g�̎Q�Ƃ��Ȃ���ԂŃR���X�g�C�e���[�^�����X�g�擪�Ɍ������ĂP�i�߂�ۂ̋������m�F���Ă��܂�.\n
*				Assert����������ΐ����ł��D\n
*/
#ifdef _DEBUG
TEST(DecrementIteratorTest, WhenDecrementConstIteratorHaveNotReferenceToList) {
	TestDoublyLinkedList::ConstIterator cIt;
	EXPECT_DEATH(--cIt, ".*");
}
#endif

/**
*	@brief		���X�g����̏�ԂŖ����C�e���[�^�����X�g�擪�Ɍ������ĂP�i�߂�ۂ̃e�X�g
*	@details	ID:Iterator-12-1\n
*				�C�e���[�^�����X�g�擪�Ɍ������ĂP�i�߂�@�\�̃e�X�g�ł�.\n
*				���X�g����̏�ԂŖ����C�e���[�^�����X�g�擪�Ɍ������ĂP�i�߂�ۂ̋������m�F���Ă��܂�.\n
*				Assert����������ΐ����ł��D\n
*/
#ifdef _DEBUG
TEST(DecrementIteratorTest, WhenDecrementLastIteratorOfEmptyList) {
	TestDoublyLinkedList list;
	TestDoublyLinkedList::Iterator it = list.end();
	EXPECT_DEATH(--it, "Assertion failed.*");
}
#endif

/**
*	@brief		���X�g����̏�ԂŖ����R���X�g�C�e���[�^�����X�g�擪�Ɍ������ĂP�i�߂�ۂ̃e�X�g
*	@details	ID:Iterator-12-2\n
*				�C�e���[�^�����X�g�擪�Ɍ������ĂP�i�߂�@�\�̃e�X�g�ł�.\n
*				���X�g����̏�ԂŖ����R���X�g�C�e���[�^�����X�g�擪�Ɍ������ĂP�i�߂�ۂ̋������m�F���Ă��܂�.\n
*				Assert����������ΐ����ł��D\n
*/
#ifdef _DEBUG
TEST(DecrementIteratorTest, WhenDecrementLastConstIteratorOfEmptyList) {
	TestDoublyLinkedList list;
	TestDoublyLinkedList::ConstIterator cIt = list.cend();
	EXPECT_DEATH(--cIt, "Assertion failed.*");
}
#endif

/**
*	@brief		�擪�C�e���[�^��O����1�i�߂�ۂ̃e�X�g
*	@details	ID:Iterator-13-1\n
*				�C�e���[�^��O���ւP�i�߂�@�\�̃e�X�g�ł�.\n
*				�擪�C�e���[�^��O���ւP�i�߂�ۂ̋������m�F���Ă��܂�.\n
*				Assert����������ΐ����ł��D\n
*/
#ifdef _DEBUG
TEST(DecrementIteratorTest, WhenDecrementFirstIterator) {
	TestDoublyLinkedList list;
	TestDoublyLinkedList::Iterator it = list.begin();
	EXPECT_DEATH(--it, "Assertion failed.*");
}
#endif

/**
*	@brief		�擪�R���X�g�C�e���[�^��O����1�i�߂�ۂ̃e�X�g
*	@details	ID:Iterator-13-2\n
*				�C�e���[�^��O���ւP�i�߂�@�\�̃e�X�g�ł�.\n
*				�擪�R���X�g�C�e���[�^��O���ւP�i�߂�ۂ̋������m�F���Ă��܂�.\n
*				Assert����������ΐ����ł��D\n
*/
#ifdef _DEBUG
TEST(DecrementIteratorTest, WhenDecrementFirstConstIterator) {
	TestDoublyLinkedList list;
	TestDoublyLinkedList::ConstIterator cIt = list.cbegin();
	EXPECT_DEATH(--cIt, ".*");
}
#endif

/**
*	@brief		2�ȏ�̗v�f�����郊�X�g�ɑ΂��C�C�e���[�^��������擪�܂ňړ�����ۂ̃e�X�g
*	@details	ID:Iterator-14-1\n
*				�C�e���[�^�����X�g�擪�Ɍ������ĂP�i�߂�@�\�̃e�X�g�ł�.\n
*				2�ȏ�̗v�f�����郊�X�g�ɑ΂��C�C�e���[�^�𖖔�����擪�܂ňړ�����ۂ̋������m�F���Ă��܂�.\n
*				���X�g�̊e�v�f�Ɋi�[���ꂽ�l����������ΐ����ł��D\n
*/
TEST(DecrementIteratorTest, WhenDecrementIteratorOnListHaveElements) {
	TestDoublyLinkedList list;
	TestDoublyLinkedList::Iterator it = list.begin();

	ScoreData scoreData1("1", "test1");
	ScoreData scoreData2("2", "test2");
	ScoreData scoreData3("3", "test3");
	ScoreData scores[] = { scoreData1,scoreData2,scoreData3 };

	for (int i = 0; i < 3; i++) {
		list.insert(it, scores[i]);
	}

	TestDoublyLinkedList::Iterator itDecrement = list.end();	//��������擪�ֈړ�����C�e���[�^

	int i = 2;
	while (i >= 0) {
		itDecrement--;
		bool isEqual = ((*itDecrement) == scores[i]);
		EXPECT_TRUE(isEqual);
		i--;
	}
}

/**
*	@brief		2�ȏ�̗v�f�����郊�X�g�ɑ΂��C�R���X�g�C�e���[�^�𖖔�����擪�܂ňړ�����ۂ̃e�X�g
*	@details	ID:Iterator-14-2\n
*				�C�e���[�^�����X�g�擪�Ɍ������ĂP�i�߂�@�\�̃e�X�g�ł�.\n
*				2�ȏ�̗v�f�����郊�X�g�ɑ΂��C�R���X�g�C�e���[�^�𖖔�����擪�܂ňړ�����ۂ̋������m�F���Ă��܂�.\n
*				���X�g�̊e�v�f�Ɋi�[���ꂽ�l����������ΐ����ł��D\n
*/
TEST(DecrementIteratorTest, WhenDecrementConstIteratorOnListHaveElements) {
	TestDoublyLinkedList list;
	TestDoublyLinkedList::Iterator it = list.begin();

	ScoreData scoreData1("1", "test1");
	ScoreData scoreData2("2", "test2");
	ScoreData scoreData3("3", "test3");
	ScoreData scores[] = { scoreData1,scoreData2,scoreData3 };

	for (int i = 0; i < 3; i++) {
		list.insert(it, scores[i]);
	}

	TestDoublyLinkedList::ConstIterator cItDecrement = list.cend();	//��������擪�ֈړ�����R���X�g�C�e���[�^

	int i = 2;
	while (i >= 0) {
		cItDecrement--;
		bool isEqual = ((*cItDecrement) == scores[i]);
		EXPECT_TRUE(isEqual);
		i--;
	}
}

/**
*	@brief		�O�u�f�N�������g���s�����ۂ̃e�X�g
*	@details	ID:Iterator-15-1\n
*				�C�e���[�^�����X�g�擪�Ɍ������ĂP�i�߂�@�\�̃e�X�g�ł�.\n
*				�C�e���[�^�ɑ΂��āC�O�u�f�N�������g���s�����ۂ̋������m�F���Ă��܂�.\n
*				�f�N�������g�Ăяo�����ƃf�N�������g���s��ł̗����ŁC�擪�v�f���w���Ă���ΐ����ł��D\n
*/
TEST(DecrementIteratorTest, WhenPrefixDecrementIterator) {
	TestDoublyLinkedList list;
	createListHavingElements(list, 1);

	TestDoublyLinkedList::Iterator itDecrement = list.end();
	TestDoublyLinkedList::Iterator itFirstElement = list.begin();

	bool isEqualWhenDecrement = ((--itDecrement) == itFirstElement);
	bool isEqualAfterDecrement = (itDecrement == itFirstElement);

	EXPECT_TRUE(isEqualAfterDecrement == true && isEqualAfterDecrement == true);
}

/**
*	@brief		�O�u�f�N�������g���s�����ۂ̃e�X�g
*	@details	ID:Iterator-15-2\n
*				�C�e���[�^�����X�g�擪�Ɍ������ĂP�i�߂�@�\�̃e�X�g�ł�.\n
*				�R���X�g�C�e���[�^�ɑ΂��āC�O�u�f�N�������g���s�����ۂ̋������m�F���Ă��܂�.\n
*				�f�N�������g�Ăяo�����ƃf�N�������g���s��̗����ŁC�擪�v�f���w���Ă���ΐ����ł��D\n
*/
TEST(DecrementIteratorTest, WhenPrefixDecrementConstIterator) {
	TestDoublyLinkedList list;
	createListHavingElements(list, 1);

	TestDoublyLinkedList::ConstIterator cItDecrement = list.cend();
	TestDoublyLinkedList::ConstIterator cItFirstElement = list.cbegin();

	bool isEqualWhenDecrement = ((--cItDecrement) == cItFirstElement);
	bool isEqualAfterDecrement = (cItDecrement == cItFirstElement);

	EXPECT_TRUE(isEqualAfterDecrement == true && isEqualAfterDecrement == true);
}

/**
*	@brief		��u�f�N�������g���s�����ۂ̃e�X�g
*	@details	ID:Iterator-16-1\n
*				�C�e���[�^�����X�g�擪�Ɍ������ĂP�i�߂�@�\�̃e�X�g�ł�.\n
*				�C�e���[�^�ɑ΂��āC��u�f�N�������g���s�����ۂ̋������m�F���Ă��܂�.\n
*				�f�N�������g�Ăяo�����͖����_�~�[���C�f�N�������g���s��͐擪�v�f���w���Ă���ΐ����ł��D\n
*/
TEST(DecrementIteratorTest, WhenPostfixDecrementIterator) {
	TestDoublyLinkedList list;
	createListHavingElements(list, 1);

	TestDoublyLinkedList::Iterator itDecrement = list.end();
	TestDoublyLinkedList::Iterator itLast = list.end();
	TestDoublyLinkedList::Iterator itFirstElement = list.begin();

	bool isEqualWhenDecrement = ((itDecrement--) == itLast);
	bool isEqualAfterDecrement = (itDecrement == itFirstElement);

	EXPECT_TRUE(isEqualWhenDecrement == true && isEqualAfterDecrement == true);
}

/**
*	@brief		��u�f�N�������g���s�����ۂ̃e�X�g
*	@details	ID:Iterator-16-2\n
*				�C�e���[�^�����X�g�擪�Ɍ������ĂP�i�߂�@�\�̃e�X�g�ł�.\n
*				�R���X�g�C�e���[�^�ɑ΂��āC��u�f�N�������g���s�����ۂ̋������m�F���Ă��܂�.\n
*				�f�N�������g�Ăяo�����͖����_�~�[���C�f�N�������g���s��͐擪�v�f���w���Ă���ΐ����ł��D\n
*/
TEST(DecrementIteratorTest, WhenPostfixDecrementConstIterator) {
	TestDoublyLinkedList list;
	createListHavingElements(list, 1);

	TestDoublyLinkedList::ConstIterator cItDecrement = list.cend();
	TestDoublyLinkedList::ConstIterator cItLast = list.cend();
	TestDoublyLinkedList::ConstIterator cItFirstElement = list.cbegin();

	bool isEqualWhenDecrement = ((cItDecrement--) == cItLast);
	bool isEqualAfterDecrement = (cItDecrement == cItFirstElement);

	EXPECT_TRUE(isEqualWhenDecrement == true && isEqualAfterDecrement == true);
}


//=================================== �C�e���[�^�̃R�s�[���s�� ===================================

/**
*	@brief		�C�e���[�^�̃R�s�[�R���X�g���N�^���Ăяo�����ۂ̃e�X�g
*	@details	ID:Iterator-18-1\n
*				�C�e���[�^�̃R�s�[�@�\�̃e�X�g�ł�.\n
*				�R�s�[�R���X�g���N�^���Ăяo�����ۂ̋������m�F���Ă��܂�.\n
*				�R�s�[�R���X�g���N�g��̒l���R�s�[���Ɠ�������ΐ����ł��D\n
*/
TEST(CopyIteratorTest, WhenCallIteratorCopyConstructor) {
	TestDoublyLinkedList list;
	createListHavingElements(list, 1);

	TestDoublyLinkedList::Iterator itFrom = list.begin();
	TestDoublyLinkedList::Iterator itTo = itFrom;

	bool isEqual = ((*itFrom) == (*itTo));
	EXPECT_TRUE(isEqual);
}

/**
*	@brief		�R���X�g�C�e���[�^�̃R�s�[�R���X�g���N�^���Ăяo�����ۂ̃e�X�g
*	@details	ID:Iterator-18-2\n
*				�C�e���[�^�̃R�s�[�@�\�̃e�X�g�ł�.\n
*				�R�s�[�R���X�g���N�^���Ăяo�����ۂ̋������m�F���Ă��܂�.\n
*				�R�s�[�R���X�g���N�g��̒l���R�s�[���Ɠ�������ΐ����ł��D\n
*/
TEST(CopyIteratorTest, WhenCallConstIteratorCopyConstructor) {
	TestDoublyLinkedList list;
	createListHavingElements(list, 1);

	TestDoublyLinkedList::ConstIterator cItFrom = list.cbegin();
	TestDoublyLinkedList::ConstIterator cItTo = cItFrom;

	bool isEqual = ((*cItFrom) == (*cItTo));
	EXPECT_TRUE(isEqual);
}


//=================================== �C�e���[�^�̑�����s�� ===================================

/**
*	@brief		�C�e���[�^�֑�������ۂ̃e�X�g
*	@details	ID:Iterator-20-1\n
*				�C�e���[�^�̑���@�\�̃e�X�g�ł�.\n
*				�C�e���[�^�֑�������ۂ̋������m�F���Ă��܂�.\n
*				�����̒l���R�s�[���Ɠ�������ΐ����ł��D\n
*/
TEST(AssignIteratorTest, WhenAssignIterator) {
	TestDoublyLinkedList list;
	createListHavingElements(list, 1);

	TestDoublyLinkedList::Iterator itFrom = list.begin();
	TestDoublyLinkedList::Iterator itTo;
	itTo = itFrom;

	bool isEqual = ((*itFrom) == (*itTo));
	EXPECT_TRUE(isEqual);
}

/**
*	@brief		�R���X�g�C�e���[�^�֑�������ۂ̃e�X�g
*	@details	ID:Iterator-20-2\n
*				�C�e���[�^�̑���@�\�̃e�X�g�ł�.\n
*				�R���X�g�C�e���[�^�֑�������ۂ̋������m�F���Ă��܂�.\n
*				�����̒l���R�s�[���Ɠ�������ΐ����ł��D\n
*/
TEST(AssignIteratorTest, WhenAssignConstIterator) {
	TestDoublyLinkedList list;
	createListHavingElements(list, 1);

	TestDoublyLinkedList::ConstIterator itFrom = list.cbegin();
	TestDoublyLinkedList::ConstIterator itTo;
	itTo = itFrom;

	bool isEqual = ((*itFrom) == (*itTo));
	EXPECT_TRUE(isEqual);
}


//=================================== 2�̃C�e���[�^������̂��̂���r ===================================

/**
*	@brief		���X�g����̏�ԂŐ擪�C�e���[�^�Ɩ����C�e���[�^���r�����ۂ̃e�X�g
*	@details	ID:Iterator-21-1\n
*				2�̃C�e���[�^������̂��̂���r����@�\�̃e�X�g�ł�.\n
*				���X�g����̏�ԂŐ擪�C�e���[�^�Ɩ����C�e���[�^���r�����ۂ̋������m�F���Ă��܂�.\n
*				2�̃C�e���[�^����������ΐ����ł��D\n
*/
TEST(CompareTwoIteratorsIsSameTest, WhenCompareFirstAndLastIteratorsOfemptyListIsSame) {
	TestDoublyLinkedList list;
	TestDoublyLinkedList::Iterator itFirst = list.begin();
	TestDoublyLinkedList::Iterator itLast = list.end();

	bool isEqual = (itFirst == itLast);
	EXPECT_TRUE(isEqual);
}

/**
*	@brief		���X�g����̏�ԂŐ擪�R���X�g�C�e���[�^�Ɩ����R���X�g�C�e���[�^���r�����ۂ̃e�X�g
*	@details	ID:Iterator-21-2\n
*				2�̃C�e���[�^������̂��̂���r����@�\�̃e�X�g�ł�.\n
*				���X�g����̏�ԂŐ擪�R���X�g�C�e���[�^�Ɩ����R���X�g�C�e���[�^���r�����ۂ̋������m�F���Ă��܂�.\n
*				2�̃R���X�g�C�e���[�^����������ΐ����ł��D\n
*/
TEST(CompareTwoIteratorsIsSameTest, WhenCompareFirstAndLastConstIteratorsOfemptyListIsSame) {
	TestDoublyLinkedList list;
	TestDoublyLinkedList::ConstIterator cItFirst = list.cbegin();
	TestDoublyLinkedList::ConstIterator cItLast = list.cend();

	bool isEqual = (cItFirst == cItLast);
	EXPECT_TRUE(isEqual);
}

/**
*	@brief		����̃C�e���[�^���r�����ۂ̃e�X�g
*	@details	ID:Iterator-22-1\n
*				2�̃C�e���[�^������̂��̂���r����@�\�̃e�X�g�ł�.\n
*				����̃C�e���[�^���r�����ۂ̋������m�F���Ă��܂�.\n
*				2�̃C�e���[�^����������ΐ����ł��D\n
*/
TEST(CompareTwoIteratorsIsSameTest, WhenCompareSameIteratorsIsSame) {
	TestDoublyLinkedList list;
	createListHavingElements(list, 1);

	TestDoublyLinkedList::Iterator it = list.begin();

	bool isEqual = (it == it);
	EXPECT_TRUE(isEqual);
}

/**
*	@brief		����̃R���X�g�C�e���[�^���r�����ۂ̃e�X�g
*	@details	ID:Iterator-22-2\n
*				2�̃C�e���[�^������̂��̂���r����@�\�̃e�X�g�ł�.\n
*				����̃R���X�g�C�e���[�^���r�����ۂ̋������m�F���Ă��܂�.\n
*				2�̃R���X�g�C�e���[�^����������ΐ����ł��D\n
*/
TEST(CompareTwoIteratorsIsSameTest, WhenCompareSameConstIteratorsIsSame) {
	TestDoublyLinkedList list;
	createListHavingElements(list, 1);

	TestDoublyLinkedList::ConstIterator cIt = list.cbegin();

	bool isEqual = (cIt == cIt);
	EXPECT_TRUE(isEqual);
}

/**
*	@brief		�قȂ�C�e���[�^���r�����ۂ̃e�X�g
*	@details	ID:Iterator-23-1\n
*				2�̃C�e���[�^������̂��̂���r����@�\�̃e�X�g�ł�.\n
*				�قȂ�C�e���[�^���r�����ۂ̋������m�F���Ă��܂�.\n
*				2�̃C�e���[�^���قȂ�ΐ����ł��D\n
*/
TEST(CompareTwoIteratorsIsSameTest, WhenCompareNotSameIteratorsIsSame) {
	TestDoublyLinkedList list;
	createListHavingElements(list, 2);

	TestDoublyLinkedList::Iterator itFirstElement = list.begin();	//�擪�v�f���w���C�e���[�^
	TestDoublyLinkedList::Iterator itCenterElement = list.begin();	//�����̗v�f���w���C�e���[�^
	++itCenterElement;	//�����̗v�f�ֈړ�

	bool isEqual = (itFirstElement == itCenterElement);
	EXPECT_FALSE(isEqual);
}

/**
*	@brief		�قȂ�R���X�g�C�e���[�^���r�����ۂ̃e�X�g
*	@details	ID:Iterator-23-2\n
*				2�̃C�e���[�^������̂��̂���r����@�\�̃e�X�g�ł�.\n
*				�قȂ�R���X�g�C�e���[�^���r�����ۂ̋������m�F���Ă��܂�.\n
*				2�̃R���X�g�C�e���[�^���قȂ�ΐ����ł��D\n
*/
TEST(CompareTwoIteratorsIsSameTest, WhenCompareNotSameConstIteratorsIsSame) {
	TestDoublyLinkedList list;
	createListHavingElements(list, 2);

	TestDoublyLinkedList::ConstIterator cItFirstElement = list.cbegin();		//�擪�v�f���w���R���X�g�C�e���[�^
	TestDoublyLinkedList::ConstIterator cItCenterElement = list.cbegin();	//�����̗v�f���w���R���X�g�C�e���[�^
	++cItCenterElement;	//�����̗v�f�ֈړ�

	bool isEqual = (cItFirstElement == cItCenterElement);
	EXPECT_FALSE(isEqual);
}

//=================================== 2�̃C�e���[�^���قȂ���̂���r ===================================

/**
*	@brief		���X�g����̏�ԂŐ擪�C�e���[�^�Ɩ����C�e���[�^���r�����ۂ̃e�X�g
*	@details	ID:Iterator-24-1\n
*				2�̃C�e���[�^���قȂ���̂���r����@�\�̃e�X�g�ł�.\n
*				���X�g����̏�ԂŐ擪�C�e���[�^�Ɩ����C�e���[�^���r�����ۂ̋������m�F���Ă��܂�.\n
*				2�̃C�e���[�^����������ΐ����ł��D\n
*/
TEST(CompareTwoIteratorsIsNotSameTest, WhenCompareFirstAndLastIteratorsOfemptyListIsNotSame) {
	TestDoublyLinkedList list;
	TestDoublyLinkedList::Iterator itFirst = list.begin();
	TestDoublyLinkedList::Iterator itLast = list.end();

	bool isEqual = (itFirst != itLast);
	EXPECT_FALSE(isEqual);	//�擪�_�~�[�Ɩ����_�~�[���w���Ă��邽�߈قȂ��Ă��܂�
}

/**
*	@brief		���X�g����̏�ԂŐ擪�R���X�g�C�e���[�^�Ɩ����R���X�g�C�e���[�^���r�����ۂ̃e�X�g
*	@details	ID:Iterator-24-2\n
*				2�̃C�e���[�^���قȂ���̂���r����@�\�̃e�X�g�ł�.\n
*				���X�g����̏�ԂŐ擪�R���X�g�C�e���[�^�Ɩ����R���X�g�C�e���[�^���r�����ۂ̋������m�F���Ă��܂�.\n
*				2�̃R���X�g�C�e���[�^����������ΐ����ł��D\n
*/
TEST(CompareTwoIteratorsIsNotSameTest, WhenCompareFirstAndLastConstIteratorsOfemptyListIsNotSame) {
	TestDoublyLinkedList list;
	TestDoublyLinkedList::ConstIterator cItFirst = list.cbegin();
	TestDoublyLinkedList::ConstIterator cItLast = list.cend();

	bool isEqual = (cItFirst != cItLast);
	EXPECT_FALSE(isEqual);	//�擪�_�~�[�Ɩ����_�~�[���w���Ă��邽�߈قȂ��Ă��܂�
}

/**
*	@brief		����̃C�e���[�^���r�����ۂ̃e�X�g
*	@details	ID:Iterator-25-1\n
*				2�̃C�e���[�^���قȂ���̂���r����@�\�̃e�X�g�ł�.\n
*				����̃C�e���[�^���r�����ۂ̋������m�F���Ă��܂�.\n
*				2�̃C�e���[�^����������ΐ����ł��D\n
*/
TEST(CompareTwoIteratorsIsNotSameTest, WhenCompareSameIteratorsIsNotSame) {
	TestDoublyLinkedList list;
	createListHavingElements(list, 1);

	TestDoublyLinkedList::Iterator it = list.begin();

	bool isEqual = (it != it);
	EXPECT_FALSE(isEqual);
}

/**
*	@brief		����̃R���X�g�C�e���[�^���r�����ۂ̃e�X�g
*	@details	ID:Iterator-25-2\n
*				2�̃C�e���[�^���قȂ���̂���r����@�\�̃e�X�g�ł�.\n
*				����̃R���X�g�C�e���[�^���r�����ۂ̋������m�F���Ă��܂�.\n
*				2�̃R���X�g�C�e���[�^����������ΐ����ł��D\n
*/
TEST(CompareTwoIteratorsIsNotSameTest, WhenCompareSameConstIteratorsIsNotSame) {
	TestDoublyLinkedList list;
	createListHavingElements(list, 1);

	TestDoublyLinkedList::ConstIterator cIt = list.cbegin();

	bool isEqual = (cIt != cIt);
	EXPECT_FALSE(isEqual);
}

/**
*	@brief		�قȂ�C�e���[�^���r�����ۂ̃e�X�g
*	@details	ID:Iterator-26-1\n
*				2�̃C�e���[�^���قȂ���̂���r����@�\�̃e�X�g�ł�.\n
*				�قȂ�C�e���[�^���r�����ۂ̋������m�F���Ă��܂�.\n
*				2�̃C�e���[�^���قȂ�ΐ����ł��D\n
*/
TEST(CompareTwoIteratorsIsNotSameTest, WhenCompareNotSameIteratorsIsNotSame) {
	TestDoublyLinkedList list;
	createListHavingElements(list, 2);

	TestDoublyLinkedList::Iterator itFirstElement = list.begin();	//�擪�v�f���w���C�e���[�^
	TestDoublyLinkedList::Iterator itCenterElement = list.begin();	//�����̗v�f���w���C�e���[�^
	++itCenterElement;	//�����̗v�f�ֈړ�

	bool isEqual = (itFirstElement != itCenterElement);
	EXPECT_TRUE(isEqual);
}

/**
*	@brief		�قȂ�R���X�g�C�e���[�^���r�����ۂ̃e�X�g
*	@details	ID:Iterator-26-2\n
*				2�̃C�e���[�^���قȂ���̂���r����@�\�̃e�X�g�ł�.\n
*				�قȂ�R���X�g�C�e���[�^���r�����ۂ̋������m�F���Ă��܂�.\n
*				2�̃R���X�g�C�e���[�^���قȂ�ΐ����ł��D\n
*/
TEST(CompareTwoIteratorsIsSameTest, WhenCompareNotSameConstIteratorsIsNotSame) {
	TestDoublyLinkedList list;
	createListHavingElements(list, 2);

	TestDoublyLinkedList::ConstIterator cItFirstElement = list.cbegin();		//�擪�v�f���w���R���X�g�C�e���[�^
	TestDoublyLinkedList::ConstIterator cItCenterElement = list.cbegin();	//�����̗v�f���w���R���X�g�C�e���[�^
	++cItCenterElement;	//�����̗v�f�ֈړ�

	bool isEqual = (cItFirstElement != cItCenterElement);
	EXPECT_TRUE(isEqual);
}
