#pragma once

#ifndef DoublyLinkedList_h
#define DoublyLinkedList_h

/**
* @class	DoubLuLinkedList
* @brief	�e���v���[�g�N���XT��l�Ɏ��o�������X�g
* @tparam	T �o�������X�g�Ɋi�[����l�̌^
*/
template<class T>
class DoublyLinkedList {

private:

	/**
	* @struct	Node
	* @brief	�o�������X�g�̒l��ێ���������\����
	*/
	struct Node {

		Node* preNode;	/** �P�O����Node���w���|�C���^ */
		Node* nextNode; /** �P�����Node���w���|�C���^ */
		T value;		/** ���X�g�Ɋi�[����l */

		/**
		* �O��̃m�[�h���w�肵��Node���쐬����R���X�g���N�^
		*
		* @param[in] preNode	�P�O����Node���w���|�C���^
		* @param[in] nextNode	�P�����Node���w���|�C���^
		*/
		Node(Node* preNode, Node* nextNode);

		/**
		* �O��̃m�[�h�Ɗi�[����l���w�肵��Node���쐬����R���X�g���N�^
		*
		* @param[in] preNode	�P�O����Node���w���|�C���^
		* @param[in] nextNode	�P�����Node���w���|�C���^
		* @param[in] value		�m�[�h�����l
		*/
		Node(Node* preNode, Node* nextNode, const T& value);
	};

public:

	/**
	* @class	ConstIterator
	* @brief	�o�������X�g�̃m�[�h���w���C���i�[�N���X\n
	*			�m�[�h�����l��ύX���邱�Ƃ͂ł��Ȃ�\n
	*/
	class ConstIterator {
	protected:

		friend bool DoublyLinkedList<T>::insert(ConstIterator cIterator, const T& value);	//insert()�Ńm�[�h��ǉ�����ہC_ptr�ւ̃A�N�Z�X���K�v�Ȃ���
		friend bool DoublyLinkedList<T>::remove(ConstIterator cIterator);					//remove()�Ńm�[�h���폜����ہC_ptr�ւ̃A�N�Z�X���K�v�Ȃ���

		const DoublyLinkedList<T>* _referenceToList;	/** ���X�g�ւ̎Q�� */
		Node* _ptr;										/** �C�e���[�^�������I�ɕێ�����Node* */

	public:

		/**
		* ConstIterator���P�O���ɖ߂�(�O�u�f�N�������g)
		*/
		ConstIterator& operator--();

		/**
		* ConstIterator���P�O���ɖ߂�(��u�f�N�������g)
		*/
		ConstIterator operator--(int);

		/**
		* ConstIterator���P����ɐi�߂�(�O�u�C���N�������g)
		*/
		ConstIterator& operator++();

		/**
		* ConstIterator���P����ɐi�߂�(��u�C���N�������g)
		*/
		ConstIterator operator++(int);

		/**
		* ConstIterator�����l���Q�Ƃ���
		*/
		const T& operator*() const;

		/**
		* �f�t�H���g�R���X�g���N�^
		*/
		ConstIterator() :_referenceToList(nullptr), _ptr(nullptr) {}
		
		/**
		* �R�s�[�R���X�g���N�^
		*/
		ConstIterator(const ConstIterator& constIterator) :_referenceToList(constIterator._referenceToList), _ptr(constIterator._ptr) {}

		/**
		* �Q�Ƃ��郊�X�g��Node*����R���X�g�C�e���[�^���쐬����R���X�g���N�^
		*/
		ConstIterator(const DoublyLinkedList<T>* list, Node* node) :_referenceToList(list), _ptr(node) {}

		/**
		* ConstIterator�̑��
		*/
		ConstIterator& operator=(const ConstIterator& rhs);

		/**
		* �Q��ConstIterator��������������
		*
		* @return bool	true:lhs��rhs��������\n
						false:lhs��rhs���قȂ�\n
		*/
		bool operator==(const ConstIterator& rhs) const;

		/**
		* �Q��ConstIterator���قȂ邩����
		*
		* @return bool	true:lhs��rhs���قȂ�\n
						false:lhs��rhs��������\n
		*/
		bool operator!=(const ConstIterator& rhs) const;

	};

	/**
	* @class	ConstIterator
	* @brief	�o�������X�g�̃m�[�h���w���C���i�[�N���X\n
	*			�m�[�h�����l��ύX���邱�Ƃ��ł���\n
	*			�e�N���X�FConstIterator
	*/
	class Iterator :public ConstIterator {
	public:

		/**
		* Iterator�����l���Q�Ƃ���
		*/
		T& operator*();

		/**
		* �f�t�H���g�R���X�g���N�^
		*/
		Iterator() :ConstIterator() {}

		/**
		* �R�s�[�R���X�g���N�^
		*/
		Iterator(const Iterator& iterator) :ConstIterator(iterator) {}

		/**
		* �Q�Ƃ��郊�X�g��Node*����C�e���[�^���쐬����R���X�g���N�^
		*/
		Iterator(DoublyLinkedList<T>* list, Node* node) :ConstIterator(list, node) {}
	};

private:

	Node* _dummyFirstNode;	/** �擪�̃_�~�[�m�[�h���w���|�C���^ */
	Node* _dummyLastNode;	/** �����̃_�~�[�m�[�h���w���|�C���^ */

	int _size;				/** �_�~�[�m�[�h�������m�[�h�̌� */

public:

	/**
	* �擪�Ɩ����̃_�~�[�m�[�h���쐬����R���X�g���N�^
	*/
	DoublyLinkedList();

	/**
	* �f�X�g���N�^
	*/
	~DoublyLinkedList();

	/**
	* @fn		size()	const
	* @return	int		�_�~�[�m�[�h�������m�[�h�̌�
	*/
	int size() const;

	/**
	* @fn			insert(ConstIterator,const T&)
	* @brief		�w�肵���R���X�g�C�e���[�^�̂P�O���Ƀf�[�^��}������
	* @param[in]	cIterator	�}������ꏊ���w���R���X�g�C�e���[�^
	* @param[in]	value		�}������l
	* @return bool	true:����Ƀf�[�^��}�����邱�Ƃ��ł���\n
	*				false:�f�[�^�̑}���Ɏ��s����\n
	*/
	bool insert(ConstIterator cIterator, const T& value);

	/**
	* @fn			insert(ConstIterator,const T&)
	* @brief		�w�肵���R���X�g�C�e���[�^���w���f�[�^���폜����
	* @param[in]	cIterator	�폜����f�[�^���w���R���X�g�C�e���[�^
	* @return bool	true:����Ƀf�[�^���폜���邱�Ƃ��ł���\n
	*				false:�f�[�^�̍폜�Ɏ��s����\n
	*/
	bool remove(ConstIterator cIterator);

	/**
	* @fn		cbegin() const
	* @brief	���X�g�̐擪���w���R���X�g�C�e���[�^��Ԃ�
	* @return	ConstIterator	���X�g����̏ꍇ�͖����_�~�[���w���R���X�g�C�e���[�^\n
	*							���X�g�ɗv�f������ꍇ�͐擪�v�f���w���R���X�g�C�e���[�^\n
	*/
	ConstIterator cbegin() const;

	/**
	* @fn		cbegin() const
	* @brief	���X�g�̖����_�~�[���w���R���X�g�C�e���[�^��Ԃ�
	* @return	ConstIterator	���X�g�̖����_�~�[���w���R���X�g�C�e���[�^\n
	*/
	ConstIterator cend() const;

	/**
	* @fn		begin()
	* @brief	���X�g�̐擪���w���C�e���[�^��Ԃ�
	* @return	Iterator	���X�g����̏ꍇ�͖����_�~�[���w���C�e���[�^\n
	*						���X�g�ɗv�f������ꍇ�͐擪�v�f���w���C�e���[�^\n
	*/
	Iterator begin();

	/**
	* @fn		cend()
	* @brief	���X�g�̖����_�~�[���w���C�e���[�^��Ԃ�
	* @return	Iterator	���X�g�̖����_�~�[���w���C�e���[�^\n
	*/
	Iterator end();

	/**
	* @fn			quicksort(ConstIterator first,ConstIterator last,bool(*comp)(int a,int b))
	* @brief		���[first,last)���N�C�b�N�\�[�g����
	* @param[in]	first					�\�[�g�����Ԃ̎n�_(���g���܂�)
	* @param[in]	last					�\�[�g�����Ԃ̏I�_(���g������)
	* @param[in]	(*comp)(int a,int b)	�\�[�g���s���ۂɗp�����r�֐�\n
	*										true��Ԃ��񐔂������v�f�قǃ��X�g�̐擪�ɋ߂�
	*/
	void quicksort(ConstIterator first, ConstIterator last, bool(*comp)(int a, int b));

};

#include "DoublyLinkedList.inl"

#endif