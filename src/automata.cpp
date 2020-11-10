/**
 * @file automata.cpp
 * @author Miqueas (Sozhia) García González (coding4canary@gmail.com)
 * @brief Automata definition (finite-state machine)
 * @version 0.1
 * @date 2020-11-08
 * COLLEGE: Universidad de la Laguna
 * DEGREE: Computer Science
 * SUBJECT: Computabilidad & Algoritmia
 * REFERENCE: https://github.com/garamira/CyA-P06-Patterns
 * 
 */
#include "automata.h"
/**
 * @brief Get expected state from pair <char,char>state_[state_position].first()
 * 
 * @param state_position position selector
 * @return expectated char
 */
char Automata::GetExpectedState(unsigned int state_position) {
  return states_[state_position];
}
/**
 * @brief Set expected state from pair <char,char>state_[state_position].first()
 * 
 * @param state_position position selector
 * @param symbol asign expectated char into a state
 */
void Automata::SetExpectedState(unsigned int state_position, char symbol) {
  states_[state_position] = symbol;
}

/**
 * @brief Generate FSA Table using a pattern 
 * 
 * @param states_number number of states to handle
 * @param pattern pattern we are looking for in a string
 */
void Automata::GenerateFSATable(unsigned int states_number, std::string pattern) {
  states_.resize(states_number);
  for (unsigned int aux = 0; aux < states_number; aux++) { // We are gonna handle n states
     SetExpectedState(aux, pattern[aux]); // Fill states_ with parsed pattern
  }
}
/**
 * @brief Check if a word handles a pattern
 * 
 * @param word word to parse
 * @param handler unexpected character
 * @return true if there is a pattern
 * @return false if there is not a pattern
 */
bool Automata::CheckWord(std::string word) {
  handler_ = false;
  unsigned int counter = 0; // incremental character = automata-pattern detector
  bool flag, control;
  for (unsigned int aux = 0; aux < word.size(); aux++) {
    if (isalnum(word[aux])) { // between (a...z) U (A...Z) control
      handler_ = false;
    } else {
      handler_ = true;
      break;
    }
  }
  for (unsigned int aux = 0; aux < word.size(); aux++) {
    if (handler_ == true) 
      break;
    if(flag == true){
      if (word[aux] != states_[counter]) { // pattern failure = reset incremental counter
        flag = false;
        counter = 0;
      }
      if (word[aux] == states_[counter]) { // pattern succes = increment incremental counter
        counter ++;
      }
    } else {
      if (word[aux] == states_[0]) { // pattern beggins
        flag = true;
        counter ++;
      }
    }
    if (counter >= states_.size()) { // once = pattern match
      control = true;
      counter = 0;
      pattern_counter_;
    }
  }
  return control;
}
/**
 * @brief Prints usefull information about the program
 * 
 */
void PrintHelp() {
	std::cout << "This program prints all the patterns detected in input.txt/words into output.txt file \n";
	std::cout << "It requires one string parameters indicating the pattern";
	std::cout << " words and a second and third parameter indicating the intput/output file.\n";
	std::cout << "Usage: ./pattern_search pattern infile.txt outfile.txt" << std::endl;
}
/**
 * @brief Load data from a file
 * 
 * @param holder holds into data vector from input.txt
 * @param finput data file
 */
void Automata::LoadData(std::vector<std::string> &holder, std::string finput) {
  std::ifstream input;
	input.open(finput, std::ios::in);
	if (input.fail()) {
		std::cout << "Cannot open file to load data ... exiting program."  << std::endl;
		exit(1);
	}
	unsigned int counter = 0;
	std::string foo;
	while(!input.eof()) {
		getline(input, foo);
		if (!foo.empty() ) {
			holder.push_back(foo);
			counter ++;
		}
	}
	input.close();
}
/**
 * @brief Print requested data into a file {TRUE,FALSE,ERROR}
 * 
 * @param f_output output data file
 * @param words words to parse and check a patter into them
 */
void Automata::PrintData(std::string f_output, std::vector<std::string> words) {
  std::ofstream output;
  bool foo;
	output.open(f_output,std::ios::out);
	if (output.fail()) {
		std::cout << "Cannot open file to write data ... exiting program."  << std::endl;
		exit(1);
	}
  for (unsigned int aux = 0; aux < words.size(); aux++) {
    foo = CheckWord(words[aux]);
    if (foo) {
      output << "True" << "\n";
    }else if (foo == false && handler_ == false) {
      output << "False" << "\n";
    }else{
      output << "Error" << "\n";
    }
    handler_=false;
  }
  output.close();
}

Automata::Automata() {}
Automata::~Automata() {}
