/**
 * @file automata.h
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
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <string.h>
#include <ctype.h>

class Automata{
 private:
  std::vector<char> states_;
  std::string word_ = "";
  bool handler_;
 public:
  unsigned int pattern_counter_;
  Automata();
  char GetExpectedState(unsigned int state_position);
  void SetExpectedState(unsigned int state_position, char symbol);
  void GenerateFSATable(unsigned int states_number, std::string pattern);
  bool CheckWord(std::string word);
  void LoadData(std::vector<std::string> &holder, std::string finput);
  void PrintData(std::string foutput, std::vector<std::string> words);
  ~Automata();
};