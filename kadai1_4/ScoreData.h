#pragma once

#ifndef ScoreData_h
#define ScoreData_h

#include <string>

/**
* @struct	ScoreData
* @brief	�v���C���[�̃X�R�A�Ɩ��O���i�[����\����
*/
struct ScoreData {

	std::string score;
	std::string name;

	/**
	* score,name���󕶎���ŏ���������R���X�g���N�^
	*/
	ScoreData();

	/**
	* score,name�������ŏ���������R���X�g���N�^
	*
	* @param[in] score �v���C���[�̓��_
	* @param[in] name �v���C���[�̖��O
	*/
	ScoreData(std::string score, std::string name);

	/**
	* �Q��ScoreData������(score,name)��������������
	*
	* @return bool	true:lhs��rhs�̃X�R�A�Ɩ��O�����ꂼ�ꓙ����\n
	*				false:lhs��rhs�̃X�R�A�Ɩ��O�̂����ꂩ���قȂ�\n
	*/
	bool operator==(const ScoreData& rhs) const;

	/**
	* �Q��ScoreData������(score,name)���قȂ邩����
	*
	* @return bool	true:lhs��rhs�̃X�R�A�Ɩ��O�̂����ꂩ���قȂ�\n
	*				false:lhs��rhs�̃X�R�A�Ɩ��O�����ꂼ�ꓙ����\n
	*/
	bool operator!=(const ScoreData& rhs) const;
};

#endif