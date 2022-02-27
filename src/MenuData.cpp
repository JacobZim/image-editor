#include "MenuData.h"
#include <iostream>
#include <vector>
#include <string>



MenuData::MenuData() {}
void MenuData::addAction( const std::string& name, ActionFunctionType function, const std::string& description) {
    mNames.push_back( name );
    mNamesToFunction[ name ] = function;
    mNamesToDescription[ name ] = description;
}
const std::vector<std::string>& MenuData::getNames() const {
    return mNames;
}
ActionFunctionType MenuData::getFunction( const std::string& name) {
    if( keyInActMap(name, mNamesToFunction) ) {
        return mNamesToFunction[ name ];
    } else {
        return 0;
    }
}
const std::string& MenuData::getDescription(const std::string& name ) {
    if( keyInDesMap( name, mNamesToDescription )) {
        return mNamesToDescription[ name ];
    } else {
        static std::string nothing;
        return nothing;
    }
}
/* these function I added on my own. I thought it'd make things easier
and ehh it kind of made things more readable ig ^\_0w0_/^ */
bool MenuData::keyInDesMap( const std::string& name, std::map<std::string,std::string>& map ) {
    return map.count( name );
}
bool MenuData::keyInActMap( const std::string& name, std::map<std::string, ActionFunctionType>& map ) {
    return map.count( name );
}