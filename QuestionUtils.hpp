#pragma once
#include "QuestionManager.hpp"
#include "DEFINITIONS.hpp"

#define SIZE_OF_QA_ARRAY ((std::string::size_type)(sizeof(cqa_array) / sizeof(cqa_array[0])))

namespace Quizma
{
	class QuestionUtils {

	private:
		std::ifstream question_file;
		std::string line;
		char delimiter = ':';
		std::string cqa_array[7];
		std::string *qa_pointer = cqa_array;
		std::vector<QuestionManager> cqa_vector;

	public:
		QuestionUtils() {}
		std::vector<QuestionManager> loadQuestion();
	};

}