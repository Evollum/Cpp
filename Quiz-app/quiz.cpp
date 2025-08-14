#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

struct Question {
    std::string text;
    std::vector<std::string> options;
    int correct;
};

std::vector<Question> loadQuestions(const std::string& filename) {
    std::vector<Question> questions;
    std::ifstream file(filename);
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string part;
        Question q;
        int count = 0;
        while (std::getline(ss, part, '|')) {
            if (count == 0) q.text = part;
            else if (count <= 3) q.options.push_back(part);
            else q.correct = std::stoi(part);
            count++;
        }
        if (count == 5) questions.push_back(q);
    }
    return questions;
}

int main() {
    auto questions = loadQuestions("questions.txt");
    int score = 0;
    int qnum = 1;
    for (const auto& q : questions) {
        std::cout << "Question " << qnum++ << ": " << q.text << std::endl;
        for (size_t i = 0; i < q.options.size(); ++i) {
            std::cout << i+1 << ". " << q.options[i] << std::endl;
        }
        int answer;
        std::cout << "Your answer: ";
        std::cin >> answer;
        if (answer == q.correct) {
            std::cout << "Correct!\n";
            ++score;
        } else {
            std::cout << "Wrong! Correct answer: " << q.options[q.correct-1] << "\n";
        }
        std::cout << std::endl;
    }
    std::cout << "Quiz finished! Your score: " << score << "/" << questions.size() << std::endl;
    return 0;
}
