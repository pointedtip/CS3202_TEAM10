#pragma once

#include "Program.h"
#include "..\Parser\Token.h"

Program::Program() {}

TNode Program::program = TNode::ConstructProgramTNode("");
map<int, TNode*> Program::stmtNumberMap = map<int, TNode*>();

TNode& Program::GetASTRootNode() {
	return program;
}

TNode& Program::GetStmtFromNumber(int stmtNum) {
	return *(stmtNumberMap[stmtNum]);
}

int Program::GetNumOfStmts() {
	return stmtNumberMap.size();
}

void Program::InsertStmt(TNode* stmt, int stmtNum) {
	stmtNumberMap[stmtNum] = stmt;
}

void Program::ClearData() { // leaky method
	Program::program = TNode::ConstructProgramTNode("");
	Program::stmtNumberMap = map<int, TNode*>();
}