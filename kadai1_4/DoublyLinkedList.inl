#include<cassert>

template<class T>
DoublyLinkedList<T>::Node::Node(Node* preNode, Node* nextNode) {
	this->preNode = preNode;
	this->nextNode = nextNode;
}

template<class T>
DoublyLinkedList<T>::Node::Node(Node* preNode, Node* nextNode, const T& value) {
	this->preNode = preNode;
	this->nextNode = nextNode;
	this->value = value;
}

template<class T>
typename DoublyLinkedList<T>::ConstIterator& DoublyLinkedList<T>::ConstIterator::operator--() {
	assert(this->_ptr);						//���X�g�ւ̎Q�Ƃ��Ȃ��C�e���[�^���f�N�������g���悤�Ƃ����ꍇ	
	assert(this->_ptr->preNode);			//�擪�_�~�[���f�N�������g���悤�Ƃ����ꍇ
	assert(this->_referenceToList->size());	//�Q�Ƃ��Ă��郊�X�g����̏ꍇ
	this->_ptr = this->_ptr->preNode;
	return *this;
}

template<class T>
typename DoublyLinkedList<T>::ConstIterator DoublyLinkedList<T>::ConstIterator::operator--(int) {
	ConstIterator tmp = *this;
	--* this;
	return tmp;
}

template<class T>
typename DoublyLinkedList<T>::ConstIterator& DoublyLinkedList<T>::ConstIterator::operator++() {
	assert(this->_ptr);							//���X�g�ւ̎Q�Ƃ��Ȃ��C�e���[�^���C���N�������g���悤�Ƃ����ꍇ
	assert(this->_ptr->nextNode);				//�����_�~�[���C���N�������g���悤�Ƃ����ꍇ
	assert(this->_referenceToList->size());		//�Q�Ƃ��Ă��郊�X�g����̏ꍇ
	this->_ptr = this->_ptr->nextNode;
	return *this;
}

template<class T>
typename DoublyLinkedList<T>::ConstIterator DoublyLinkedList<T>::ConstIterator::operator++(int) {
	ConstIterator tmp = *this;
	++* this;
	return tmp;
}

template<class T>
const T& DoublyLinkedList<T>::ConstIterator::operator*() const {
	assert(this->_ptr);				//�m�[�h���w���Ă��Ȃ��R���X�g�C�e���[�^�̗v�f���Q�Ƃ��悤�Ƃ����ꍇ
	assert(this->_ptr->preNode);	//�擪�_�~�[�̗v�f���Q�Ƃ��悤�Ƃ����ꍇ
	assert(this->_ptr->nextNode);	//�����_�~�[�̗v�f���Q�Ƃ��悤�Ƃ����ꍇ
	return this->_ptr->value;
}

template<class T>
typename DoublyLinkedList<T>::ConstIterator& DoublyLinkedList<T>::ConstIterator::operator=(const ConstIterator& rhs) {
	this->_referenceToList = rhs._referenceToList;
	this->_ptr = rhs._ptr;
	return *this;
}

template<class T>
bool DoublyLinkedList<T>::ConstIterator::operator==(const ConstIterator& rhs) const {
	return this->_ptr == rhs._ptr;
}

template<class T>
bool DoublyLinkedList<T>::ConstIterator::operator!=(const ConstIterator& rhs) const {
	return this->_ptr != rhs._ptr;
}

template<class T>
T& DoublyLinkedList<T>::Iterator::operator*() {
	assert(this->_ptr);				//�m�[�h���w���Ă��Ȃ��C�e���[�^�̗v�f���Q�Ƃ��悤�Ƃ����ꍇ
	assert(this->_ptr->preNode);	//�擪�_�~�[�̗v�f���Q�Ƃ��悤�Ƃ����ꍇ
	assert(this->_ptr->nextNode);	//�����_�~�[�̗v�f���Q�Ƃ��悤�Ƃ����ꍇ
	return this->_ptr->value;
}

template<class T>
DoublyLinkedList<T>::DoublyLinkedList() {

	//�擪�Ɩ����̃_�~�[���쐬
	this->_dummyFirstNode = new Node(nullptr, nullptr);
	this->_dummyLastNode = new Node(nullptr, nullptr);
	this->_dummyFirstNode->nextNode = this->_dummyLastNode;
	this->_dummyLastNode->preNode = this->_dummyFirstNode;

	this->_size = 0;
}

template<class T>
DoublyLinkedList<T>::~DoublyLinkedList() {
	while (cbegin() != cend()) {
		remove(cbegin());
	}
}

template<class T>
int DoublyLinkedList<T>::size() const {
	return this->_size;
}

template<class T>
bool DoublyLinkedList<T>::insert(ConstIterator cIterator, const T& val) {
	//**********	�f�[�^�̑}���Ɏ��s	**********//

	//���̃��X�g�̃R���X�g�C�e���[�^�����X�g�ւ̎Q�Ƃ��Ȃ��R���X�g�C�e���[�^���n���ꂽ�ꍇ
	if (cIterator._referenceToList != this) {
		return false;
	}

	//********************************************//

	Node* newNode = new Node(cIterator._ptr->preNode, cIterator._ptr, val);
	cIterator._ptr->preNode->nextNode = newNode;
	cIterator._ptr->preNode = newNode;

	_size++;

	return true;
}

template<class T>
bool DoublyLinkedList<T>::remove(ConstIterator cIterator) {

	//**********	�f�[�^�̍폜�Ɏ��s	**********//
	//���̃��X�g�̃R���X�g�C�e���[�^�����X�g�ւ̎Q�Ƃ��Ȃ��R���X�g�C�e���[�^���n���ꂽ�ꍇ

	if (cIterator._referenceToList != this) {
		return false;
	}
	if (cIterator._ptr == this->_dummyFirstNode || cIterator._ptr == this->_dummyLastNode) {
		return false;
	}

	//*******************************************//

	cIterator._ptr->preNode->nextNode = cIterator._ptr->nextNode;
	cIterator._ptr->nextNode->preNode = cIterator._ptr->preNode;

	delete cIterator._ptr;
	--_size;

	return true;
}

template<class T>
typename DoublyLinkedList<T>::ConstIterator DoublyLinkedList<T>::cbegin() const {
	ConstIterator ret(this, _dummyFirstNode->nextNode);
	return ret;
}

template<class T>
typename DoublyLinkedList<T>::ConstIterator DoublyLinkedList<T>::cend() const {
	ConstIterator ret(this,_dummyLastNode);
	return ret;
}
template<class T>
typename DoublyLinkedList<T>::Iterator DoublyLinkedList<T>::begin() {
	Iterator ret(this, _dummyFirstNode->nextNode);
	return ret;
}

template<class T>
typename DoublyLinkedList<T>::Iterator DoublyLinkedList<T>::end() {
	Iterator ret(this,_dummyLastNode);
	return ret;
}

void DoublyLinkedList<int>::quicksort(ConstIterator first, ConstIterator last, bool(*comp)(int a, int b)) {

	//�\�[�g���郊�X�g����̏ꍇ
	if (first == last) {
		return;
	}

	DoublyLinkedList<int>::ConstIterator pivot = first;	//�s�{�b�g(��l)������

	for (auto it = first; it != last; it++) {

		//comp�֐��ɂ��it�̒l��pivot�̒l�̑召�֌W��true�Ȃ�it�����X�g�̐擪(���[)�ɑ}������
		if (comp(*it, *pivot)) {

			insert(first, *it);	//first�̑O��(����)�ɑ}��
			--first;			//first�͏�Ƀ\�[�g��Ԃ̐擪�ɂ���

			ConstIterator itRemove = it;	//�폜�ꏊ���w���C�e���[�^
			--it;							//�C�e���[�g�p�̃C�e���[�^�͎��̃C���N�������g�ō폜�ꏊ�̌���ֈړ��������̂ŁC�폜�ꏊ�̑O���ֈړ�
			remove(itRemove);
		}
	}

	quicksort(first, pivot, comp);	//�s�{�b�g��荶�ɂ����Ԃ��\�[�g
	pivot++;						//�s�{�b�g�͂��łɐ������ʒu�ɂ���̂Ŏ��̃\�[�g��Ԃɂ͊܂߂Ȃ�
	quicksort(pivot, last, comp);	//�s�{�b�g���E�ɂ����Ԃ��\�[�g
}