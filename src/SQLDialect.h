#ifndef HATTRICKBENCH_SQLDIALECT_H
#define HATTRICKBENCH_SQLDIALECT_H
#include <vector>
#include <string.h>
#include <string>
#include <string_view>
#include "UserInput.h"
using namespace std;

class SQLDialect{
	public:
        static vector<vector<string>> bulkLoadStmt;
        static vector<vector<string>> createIndexStmt;
        static vector<vector<string>> dropSchemaStmt;
        static vector<vector<string>> createSchemaStmt;
        static vector<string> init;
        static vector<vector<string>> deleteTuplesStmt;
        static vector<string> createFreshnessTableStmt;
        static vector<string> deleteFreshnessTableStmt;
        static vector<string> populateFreshnessTableStmt;
        static const vector<string> analyticalQueries;

        static constexpr std::string_view pgTransactionalQueries[3] = {
                // New order transaction's commands
                "SELECT HAT.NEWORDER(?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?);",
                // Payment transaction
                "SELECT HAT.PAYMENT(?,?,?,?,?,?);",
                // Count orders transaction's commands
                "SELECT * FROM HAT.COUNTORDERS(?,?,?);"
        };

        static const vector<vector<std::string_view>> transactionalQueries; // for stored procedures
        static vector<string> transactionalCommands;     // for prepared statements
	static vector<string> freshnessCommands;
	static vector<string> isolation;
};
#endif //HATTRICKBENCH_SQLDIALECT_H
