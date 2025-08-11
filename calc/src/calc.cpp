// Copyright 2025 Sauvik Roy

#include <cstdlib>
#include <stack>
#include <string>
#include <vector>

#include <iostream>

#include "calc.hpp"
#include "operators.hpp"
#include "tokenize.hpp"
#include "tokens.hpp"

namespace calc {
int comparePrecedence(const Token &token1, const Token &token2) {
  int prec1 = calc::operatorPrecedence.at(token1.second);
  int prec2 = calc::operatorPrecedence.at(token2.second);

  return (prec1 > prec2 ? 1 : (prec1 == prec2 ? 0 : -1));
}

std::stack<Token> infixToPostfix(const std::vector<Token> &tokens) {
  std::stack<Token> postfix;
  std::stack<Token> opStack;

  for (const auto &currToken : tokens) {
    if (currToken.second == Operator::OPERAND) {
      postfix.push(currToken);  // 1. Operand
    } else {
      if (opStack.empty()) {
        opStack.push(currToken);  // 2. Stack is empty
      } else {
        auto &stackTop = opStack.top();
        int priority = calc::comparePrecedence(stackTop, currToken);
        if (currToken.second != Operator::R_PAR &&
            ((stackTop.second == Operator::L_PAR) || priority == 1)) {
          opStack.push(currToken);  // 3. Left Paranthesis on Stack  OR
                                    // 4. Scanned operator has higher precedence
        } else {
          if (currToken.second == Operator::L_PAR) {
            opStack.push(currToken);  // 5. Curr token = Left Paranthesis
          } else if (currToken.second == Operator::R_PAR) {
            while (stackTop.second != Operator::L_PAR) {
              postfix.push(stackTop);   // 6. Curr token = Right Paranthesis
              opStack.pop();
              if (opStack.empty()) {
                break;
              }
              stackTop = opStack.top();
            }
            if (stackTop.second == Operator::L_PAR) {
              opStack.pop();  // 7. Remove Left Paranthesis from Stack
            }
          } else {
            while (priority < 1) {
              postfix.push(
                  stackTop);  // 8. Pop all operators with higher precedence
              opStack.pop();
              if (opStack.empty()) {
                break;
              }
              stackTop = opStack.top();
              if (stackTop.second == Operator::L_PAR) {
                break;
              }
              priority = calc::comparePrecedence(stackTop, currToken);
            }
            opStack.push(currToken);
          }
        }
      }
    }
  }

  while (!opStack.empty()) {
    auto &stackTop = opStack.top();
    postfix.push(stackTop);   // 9. Finally pop the stack
    opStack.pop();
    if (opStack.empty()) {
      break;
    }
    stackTop = opStack.top();
  }

  return postfix;
}

// Function to print elements from bottom to top (and preserve order)
void printStack(std::stack<Token> &s) {
  if (s.empty()) {
    return;
  }
  auto x = s.top();
  s.pop();
  printStack(s);
  std::cout << x.first << " ";
  s.push(x);
}

double evalPostfix(const std::stack<Token> &postfix) {
  std::stack<Token> postfixCopy = postfix;
  std::stack<Token> postfixReverse;
  while (!postfixCopy.empty()) {
    auto token = postfixCopy.top();
    postfixReverse.push(token);
    postfixCopy.pop();
  }

  std::stack<double> evalStack;
  evalStack.push(0);
  while (!postfixReverse.empty()) {
    auto token = postfixReverse.top();
    if (token.second == Operator::OPERAND) {
      double val = std::atof(token.first.c_str());
      evalStack.push(val);
    } else if (token.second == Operator::ADD) {
      double opn1 = evalStack.top();
      evalStack.pop();
      double opn2 = evalStack.top();
      evalStack.pop();
      double val = calc::add(opn2, opn1);
      evalStack.push(val);
    } else if (token.second == Operator::SUBTRACT) {
      double opn1 = evalStack.top();
      evalStack.pop();
      double opn2 = evalStack.top();
      evalStack.pop();
      double val = calc::subtract(opn2, opn1);
      evalStack.push(val);
    } else if (token.second == Operator::MULTIPLY) {
      double opn1 = evalStack.top();
      evalStack.pop();
      double opn2 = evalStack.top();
      evalStack.pop();
      double val = calc::multiply(opn2, opn1);
      evalStack.push(val);
    } else if (token.second == Operator::DIVIDE) {
      double opn1 = evalStack.top();
      evalStack.pop();
      double opn2 = evalStack.top();
      evalStack.pop();
      double val = calc::divide(opn2, opn1);
      evalStack.push(val);
    } else if (token.second == Operator::INVERSE) {
      double opn1 = evalStack.top();
      evalStack.pop();
      double val = calc::inverse(opn1);
      evalStack.push(val);
    } else if (token.second == Operator::NEGATIVE) {
      double opn1 = evalStack.top();
      evalStack.pop();
      double val = calc::negative(opn1);
      evalStack.push(val);
    }
    postfixReverse.pop();
  }
  return evalStack.top();
}

double eval(const std::string &expression) {
  double res = 0.0;
  std::vector<Token> tokens = calc::tokenize(expression);

  std::stack<Token> postfix = calc::infixToPostfix(tokens);
  std::stack<Token> postfixCopy = postfix;
  calc::printStack(postfixCopy);
  res = calc::evalPostfix(postfix);

  return res;
}
}   // namespace calc
