/**
 * @file main.cpp
 * @author Miqueas (Sozhia) García González (coding4canary@gmail.com)
 * @brief Pattern search based on FSA (finite-state automata)
 * @version 0.1
 * @date 2020-11-08
 * COLLEGE: Universidad de la Laguna
 * DEGREE: Computer Science
 * SUBJECT: Computabilidad & Algoritmia
 * REFERENCE: https://github.com/garamira/CyA-P06-Patterns
 * 
 */

#include "automata.cpp"

int main(int argc, char** argv) {
  std::string f_output, f_input, pattern;
  std::vector<std::string> words;
  if (argc == 2 && strcmp(argv[1], "--help")==0) {
		PrintHelp();
		exit(1);
	}
  if (argc != 4) {
		PrintHelp();
		exit(1);
	}
  f_output = argv[3];
  f_input = argv[2];
  pattern = argv[1];
  Automata automata1;

  automata1.GenerateFSATable(pattern.size(),pattern);
  automata1.LoadData(words, f_input);
  automata1.PrintData(f_output, words);
  automata1.~Automata();
}