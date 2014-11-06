#include <utility>
#include <vector>

using namespace std;

class Follows {
public:
	// Default constructor
	Follows();

    // API for final Follows
    // stashed away for now, will be used when <TNode> API is well tested
    /*
	TNode GetFollowsBefore(TNode stmtAfter);
	TNode GetFollowsAfter(TNode stmtBefore);
	vector<TNode> GetFollowsTBefore(TNode stmtAfter);
	vector<TNode> GetFollowsTAfter(TNode stmtBefore);
	vector<TNode> GetFollowsTBefore(TNode::Type type);
	vector<TNode> GetFollowsTAfter(TNode::Type type);
    */

	// API for development
    // Return objects are of int types instead of <TNode> types
	void SetFollows(int stmtBefore, int stmtAfter);
	bool IsFollows(int stmtBefore, int stmtAfter);
	int GetFollowsBefore(int stmtAfter);
	int GetFollowsAfter(int stmtBefore);
	
	bool IsFollowsT(int stmtBefore, int stmtAfter);
	vector<int> GetFollowsTBefore(int stmtAfter);
	vector<int> GetFollowsTAfter(int stmtBefore);
	bool HasAnyFollows();

	// helper methods for testing
	int SizeOfFollows();

private:
	vector<pair<int, int>> followsTable;	// List of Follows(s1, s2) relationships
	
	bool AlreadyInserted(pair<int, int> newPair);
	// insert other private methods here

};