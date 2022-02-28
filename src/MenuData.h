#ifndef _MENUDATA_H_
#define _MENUDATA_H_
#include <vector>
#include <map>
#include <string>
#include "ActionData.h"


typedef void (*ActionFunctionType)(ActionData& action_data);


class MenuData {
public:
    MenuData();
    void addAction( const std::string& name, ActionFunctionType func, const std::string& description );
    const std::vector<std::string>& getNames() const;
    ActionFunctionType getFunction( const std::string& name );
    const std::string& getDescription( const std::string& name);
    /*my own technically unnessesary methods*/
    bool keyInDesMap( const std::string& name, std::map<std::string,std::string>& map );
    bool keyInActMap( const std::string& name, std::map<std::string, ActionFunctionType>& map );
protected:
    std::vector<std::string> mNames;
    std::map<std::string, ActionFunctionType> mNamesToFunction;
    std::map<std::string, std::string> mNamesToDescription;
private:
};


#endif