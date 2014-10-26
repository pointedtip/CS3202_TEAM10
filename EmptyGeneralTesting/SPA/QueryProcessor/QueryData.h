#pragma once
#include <string>
#include <vector>
#include "Grammar.h"

/*
Class for storing query string data, accessed by QueryValidator and QueryEvaluator
*/
class QueryData
{
private:
	static std::vector<Declaration> declarations;
	static std::vector<SelectClause> selectClauses;	
	static std::vector<SuchThatClause> suchThatClauses;
	static std::vector<PatternClause> patternClauses;
	static std::vector<WithClause> withClauses;

public:
	void InsertDeclaration(Synonym);
	void InsertSelect(Synonym);
	void InsertPattern(Synonym, Argument, Argument);
	void InsertSuchThat(Relationship, Argument, Argument);
	void InsertWith(std::string, std::string);

	std::vector<Declaration> GetDeclarations();
	std::vector<SelectClause> GetSelects();	
	std::vector<SuchThatClause> GetSuchThats();
	std::vector<PatternClause> GetPatterns();
	std::vector<WithClause> GetWiths();

	static bool IsSynonymExist(std::string, SynonymType);
	static bool IsSynonymExist(std::string, SynonymType*);
	static bool IsSynonymExist(std::string, std::vector<SynonymType>);
};