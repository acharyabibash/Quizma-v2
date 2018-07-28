#include "QuestionVector.hpp"

namespace Quizma
{
	QuestionVector::QuestionVector()
	{
		rng.seed(this->seed);
		question_answer_vector = q1.loadQuestion();
		//std::shuffle(sports_question_vector.begin(), sports_question_vector.end(), rng);
		//std::shuffle(math_question_vector.begin(), math_question_vector.end(), rng);
	}

	void QuestionVector::displayQuestions()
	{
		for (decltype(question_answer_vector.size()) i = 0; i < question_answer_vector.size(); i++) {
			std::cout << question_answer_vector.at(i) << std::endl;
		}
	}

	void QuestionVector::armQuestions()
	{
		for (decltype(question_answer_vector.size()) i = 0; i < question_answer_vector.size(); i++)
		{
			if (question_answer_vector.at(i).category == "Sports")
			{
				sports_question_vector.push_back(question_answer_vector.at(i));
			}
			else if (question_answer_vector.at(i).category == "Math")
			{
				math_question_vector.push_back(question_answer_vector.at(i));
			} 
			else if (this->question_answer_vector.at(i).category == "English")
			{
				english_question_vector.push_back(question_answer_vector.at(i));
			}

		}
	}

	std::vector<QuestionManager> QuestionVector::passSportsQuestions()
	{
		std::shuffle(sports_question_vector.begin(), sports_question_vector.end(), rng);
		return sports_question_vector;
	}

	std::vector<QuestionManager> QuestionVector::passMathQuestions()
	{
		std::shuffle(math_question_vector.begin(), math_question_vector.end(), rng);
		return math_question_vector;
	}
	std::vector<QuestionManager> QuestionVector::passEnglishQuestions()
	{
		std::shuffle(english_question_vector.begin(), english_question_vector.end(), rng);
		return english_question_vector;
	}
}
