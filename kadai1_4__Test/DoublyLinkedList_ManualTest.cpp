#include "pch.h"
#include "../kadai1_3/DoublyLinkedList.h"
#include "../kadai1_3/ScoreData.h"

using TestDoublyLinkedList = DoublyLinkedList<ScoreData>;

//=================================== �f�[�^���̎擾 ===================================

//#define TT_TEST_GET_DATA_NUM_WHEN_CONST
/**
*	@brief		�f�[�^���̎擾�@�\�ɂ��āAconst�̃��\�b�h�ł��邩�̃e�X�g
*	@details	ID:���X�g-8(�蓮)\n
*				�f�[�^���̎擾�@�\�̃e�X�g�ł�.\n
*				const�̃��\�b�h�ł��邩���m�F���Ă��܂�.\n
*				�L���ɂ��ăR���p�C�����ʂ�ΐ����ł�.\n
*				TT_TEST_GET_DATA_NUM_WHEN_CONST�}�N�����`����ƗL���ɂȂ�܂�.\n
*/
TEST(GetDataNumManualTest, WhenListIsConst)
{
#if defined TT_TEST_GET_DATA_NUM_WHEN_CONST
	const TestDoublyLinkedList list;
	EXPECT_EQ(0, list.size());
#endif //TT_TEST_GET_DATA_NUM_WHEN_CONST
	SUCCEED();
}

//=================================== �f�[�^�̑}�� ===================================

//#define TT_TEST_INSERT_WHEN_CONST
/**
*	@brief		���X�g�ւ̃f�[�^�}���ɂ��āA��const���ۏႳ��Ă��邩�̃e�X�g
*	@details	ID:���X�g-15(�蓮)\n
*				���X�g�擪�̃_�~�[����ւ̃f�[�^�ǉ��e�X�g�ł�.\n
*				��const���ۏႳ��Ă��邩���m�F���Ă��܂�.\n
*				�L���ɂ��ăR���p�C���G���[�ɂȂ�ΐ����ł�.\n
*				TT_TEST_INSERT_WHEN_CONST�}�N�����`����ƗL���ɂȂ�܂�.\n
*/
TEST(InsertDataManualTest, WhenInsertToConstList)
{
#if defined TT_TEST_INSERT_WHEN_CONST
	const TestDoublyLinkedList list;
	TestDoublyLinkedList::ConstIterator it = list.cbegin();
	ScoreData scoredata("1", "test");
	list.insert(it, scoredata);//�����ŃG���[
#endif //TT_TEST_INSERT_WHEN_CONST
	SUCCEED();
}

//=================================== �f�[�^�̍폜 ===================================

//#define TT_TEST_REMOVE_WHEN_CONST
/**
*	@brief		���X�g�̃f�[�^�폜�ɂ��āA��const���ۏႳ��Ă��邩�̃e�X�g
*	@details	ID:���X�g-22(�蓮)\n
*				���X�g�̃f�[�^�폜�e�X�g�ł�.\n
*				��const���ۏႳ��Ă��邩���m�F���Ă��܂�.\n
*				�L���ɂ��ăR���p�C���G���[�ɂȂ�ΐ����ł�.\n
*				TT_TEST_REMOVE_WHEN_CONST�}�N�����`����ƗL���ɂȂ�܂�.\n
*/
TEST(RemoveDataManualTest, WhenRemoveFromConstList)
{
#if defined TT_TEST_REMOVE_WHEN_CONST
	const TestDoublyLinkedList list;
	TestDoublyLinkedList::ConstIterator it = list.cbegin();
	list.remove(it);//�����ŃG���[

#endif //TT_TEST_REMOVE_WHEN_CONST
	SUCCEED();
}

//=================================== �擪�C�e���[�^�̎擾 ===================================

//#define TT_TEST_GET_FIRST_ITERATOR_WHEN_CONST
/**
*	@brief		���X�g�擪�̔�const�C�e���[�^�̎擾�ɂ��āA��const���ۏႳ��Ă��邩�̃e�X�g
*	@details	ID:���X�g-28(�蓮)\n
*				���X�g�̐擪�C�e���[�^�擾�̃e�X�g�ł�.\n
*				��const���ۏႳ��Ă��邩���m�F���Ă��܂�.\n
*				�L���ɂ��ăR���p�C���G���[�ɂȂ�ΐ����ł�.\n
*				TT_TEST_GET_FIRST_ITERATOR_WHEN_CONST�}�N�����`����ƗL���ɂȂ�܂�.\n
*/
TEST(GetFistIteratorManualTest, WhenGetFirstIteratorFromConstList)
{
#if defined TT_TEST_GET_FIRST_ITERATOR_WHEN_CONST
	const TestDoublyLinkedList list;
	TestDoublyLinkedList::Iterator it = list.cbegin();	//�����ŃG���[

#endif //TT_TEST_GET_FIRST_ITERATOR_WHEN_CONST
	SUCCEED();
}

//=================================== �擪�R���X�g�C�e���[�^�̎擾 ===================================

//#define TT_TEST_GET_FIRST_CONST_ITERATOR_WHEN_CONST
/**
*	@brief		���X�g�擪�̃R���X�g�C�e���[�^�̎擾�ɂ��āAconst�̃��\�b�h�ł��邩�̃e�X�g
*	@details	ID:���X�g-34(�蓮)\n
*				���X�g�̐擪�R���X�g�C�e���[�^�擾�̃e�X�g�ł�.\n
*				const�̃��\�b�h�ł��邩���m�F���Ă��܂�.\n
*				�L���ɂ��ăR���p�C�����ʂ�ΐ����ł�.\n
*				TT_TEST_GET_FIRST_CONST_ITERATOR_WHEN_CONST�}�N�����`����ƗL���ɂȂ�܂�.\n
*/
TEST(GetFistConstIteratorManualTest, WhenGetFirstConstIteratorFromConstList)
{
#if defined TT_TEST_GET_FIRST_CONST_ITERATOR_WHEN_CONST
	const TestDoublyLinkedList list;
	TestDoublyLinkedList::ConstIterator it = list.cbegin();

#endif //TT_TEST_GET_FIRST_CONST_ITERATOR_WHEN_CONST
	SUCCEED();
}

//=================================== �����C�e���[�^�̎擾 ===================================

//#define TT_TEST_GET_LAST_ITERATOR_WHEN_CONST
/**
*	@brief		���X�g�����̔�const�C�e���[�^�̎擾�ɂ��āA��const���ۏႳ��Ă��邩�̃e�X�g
*	@details	ID:���X�g-40(�蓮)\n
*				���X�g�̖����C�e���[�^�擾�̃e�X�g�ł�.\n
*				��const���ۏႳ��Ă��邩���m�F���Ă��܂�.\n
*				�L���ɂ��ăR���p�C���G���[�ɂȂ�ΐ����ł�.\n
*				TT_TEST_GET_LAST_ITERATOR_WHEN_CONST�}�N�����`����ƗL���ɂȂ�܂�.\n
*/
TEST(GetLastIteratorManualTest, WhenGetLastIteratorFromConstList)
{
#if defined TT_TEST_GET_LAST_ITERATOR_WHEN_CONST
	const TestDoublyLinkedList list;
	TestDoublyLinkedList::Iterator it = list.end();	//�����ŃG���[

#endif //TT_TEST_GET_LAST_ITERATOR_WHEN_CONST
	SUCCEED();
}

//=================================== �����R���X�g�C�e���[�^�̎擾 ===================================

//#define TT_TEST_GET_LAST_CONST_ITERATOR_WHEN_CONST
/**
*	@brief		���X�g�����̃R���X�g�C�e���[�^�̎擾�ɂ��āAconst�̃��\�b�h�ł��邩�̃e�X�g
*	@details	ID:���X�g-46(�蓮)\n
*				���X�g�̖����R���X�g�C�e���[�^�擾�̃e�X�g�ł�.\n
*				const�̃��\�b�h�ł��邩���m�F���Ă��܂�.\n
*				�L���ɂ��ăR���p�C�����ʂ�ΐ����ł�.\n
*				TT_TEST_GET_LAST_CONST_ITERATOR_WHEN_CONST�}�N�����`����ƗL���ɂȂ�܂�.\n
*/
TEST(GetLastConstIteratorManualTest, WhenGetLastConstIteratorFromConstList)
{
#if defined TT_TEST_GET_LAST_CONST_ITERATOR_WHEN_CONST
	const TestDoublyLinkedList list;
	TestDoublyLinkedList::ConstIterator it = list.cend();

#endif //TT_TEST_GET_LAST_CONST_ITERATOR_WHEN_CONST
	SUCCEED();
}


//=================================== �C�e���[�^�̎w���v�f�̎擾 ===================================

//#define TT_TEST_ASSIGN_TO_ELEMENT_OF_ITERATOR_WHEN_CONST
/**
*	@brief		�R���X�g�C�e���[�^����擾�����v�f�ɑ΂��āC�l�̑���������ۂ̃e�X�g
*	@details	ID:Iterator-2(�蓮)\n
*				�C�e���[�^�̎w���v�f�̎擾�@�\�̃e�X�g�ł�.\n
*				�R���X�g�C�e���[�^����擾�����v�f�ɑ΂��āC�l�̑���������ۂ̋������m�F���Ă��܂�.\n
*				�L���ɂ��ăR���p�C���G���[�ɂȂ�ΐ����ł�.\n
*				TT_TEST_ASSIGN_TO_ELEMENT_OF_ITERATOR_WHEN_CONST�}�N�����`����ƗL���ɂȂ�܂�.\n
*/
TEST(GetElementOfIteratorManualTest, WhenAssignToElementOfConstIterator)
{
#if defined TT_TEST_ASSIGN_TO_ELEMENT_OF_ITERATOR_WHEN_CONST
	TestDoublyLinkedList list;
	ScoreData scoreData("1", "test1");

	TestDoublyLinkedList::ConstIterator it = list.cbegin();

	ScoreData newScoreData("100", "newData");
	*it = newScoreData;	//�����ŃG���[

#endif //TT_TEST_ASSIGN_TO_ELEMENT_OF_ITERATOR_WHEN_CONST
	SUCCEED();
}

//=================================== �C�e���[�^�̃R�s�[���s�� ===================================

//#define TT_TEST_COPY_TO_ITERATOR_FROM_CONST_ITERATOR
/**
*	@brief		�R���X�g�C�e���[�^����C�e���[�^�փR�s�[���쐬����ۂ̃e�X�g
*	@details	ID:Iterator-17(�蓮)\n
*				�C�e���[�^�̃R�s�[�@�\�̃e�X�g�ł�.\n
*				�R���X�g�C�e���[�^����C�e���[�^�փR�s�[���쐬����ۂ̋������m�F���Ă��܂�.\n
*				�L���ɂ��ăR���p�C���G���[�ɂȂ�ΐ����ł�.\n
*				TT_TEST_COPY_TO_ITERATOR_FROM_CONST_ITERATOR�}�N�����`����ƗL���ɂȂ�܂�.\n
*/
TEST(CopyIteratorTest, WhenCopyToIteratorFromConstIterator)
{
#if defined TT_TEST_COPY_TO_ITERATOR_FROM_CONST_ITERATOR
	TestDoublyLinkedList::ConstIterator cIt;
	TestDoublyLinkedList::Iterator it = cIt;	//�����ŃG���[

#endif //TT_TEST_COPY_TO_ITERATOR_FROM_CONST_ITERATOR
	SUCCEED();
}


//=================================== �C�e���[�^�̑�����s�� ===================================

//#define TT_TEST_ASSIGN_CONSTITERATOR_TO_ITERATOR
/**
*	@brief		�C�e���[�^�փR���X�g�C�e���[�^��������ۂ̃e�X�g
*	@details	ID:Iterator-19(�蓮)\n
*				�C�e���[�^�̑���@�\�̃e�X�g�ł�.\n
*				�C�e���[�^�փR���X�g�C�e���[�^��������ۂ̋������m�F���Ă��܂�.\n
*				�L���ɂ��ăR���p�C���G���[�ɂȂ�ΐ����ł�.\n
*				TT_TEST_ASSIGN_CONSTITERATOR_TO_ITERATOR�}�N�����`����ƗL���ɂȂ�܂�.\n
*/
TEST(AssignIteratorTest, WhenAssignConstIteratorToIterator)
{
#if defined TT_TEST_ASSIGN_CONSTITERATOR_TO_ITERATOR
	TestDoublyLinkedList::ConstIterator cIt;
	TestDoublyLinkedList::Iterator it;

	it = cIt;	//�����ŃG���[

#endif //TT_TEST_ASSIGN_CONSTITERATOR_TO_ITERATOR
	SUCCEED();
}

