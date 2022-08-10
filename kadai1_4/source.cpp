#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>

#include "DoublyLinkedList.h"
#include "ScoreData.h"

bool comp(int a, int b) {
	return a < b;
}

int main() {
	//std::string fileName = "Scores.txt";
	//std::ifstream fileInput(fileName);

	//DoublyLinkedList<ScoreData> list;
	//DoublyLinkedList<ScoreData>::Iterator itInsert = list.begin();

	//while (!fileInput.eof()) {

	//	ScoreData scoreData;
	//	fileInput >> scoreData.score >> scoreData.name;
	//	list.insert(itInsert, scoreData);
	//}

	//for (auto i = list.begin(); i != list.end(); i++) {
	//	std::cout << (*i).score << "," << (*i).name << std::endl;
	//}

	DoublyLinkedList<int> list;
	list.insert(list.end(), 4);
	list.insert(list.end(), 1);
	list.insert(list.end(), 5);
	list.insert(list.end(), 3);
	list.insert(list.end(), 2);

	list.quicksort(list.begin(), list.end(), comp);

	for (const auto& element : list) {
		std::cout << element << std::endl;
	}


	return 0;
}