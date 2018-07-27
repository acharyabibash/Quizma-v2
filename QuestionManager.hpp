#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#define SIZE_OF_ANS 4

namespace Quizma {

	class QuestionManager
	{

	public:
		std::string category;
		std::string quest;
		std::string ans[SIZE_OF_ANS];
		std::string correct_ans;

	public:
		QuestionManager() {}
		~QuestionManager() { }

		QuestionManager(std::string, std::string, std::string answer[]);
		void setValue(std::string, std::string, std::string answer[]);
		friend std::ostream &operator<<(std::ostream &, const QuestionManager &);
	};

}