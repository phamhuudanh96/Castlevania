#include "../Framework/define.h"
#include "../pugixml/pugixml.hpp"
#include "../Object/BaseObject.h"

using namespace pugi;

map<string, string> GetObjectProperties(xml_node node);
BaseObject* GetWall(xml_node item, int mapHeight);
BaseObject* GetStair(xml_node item, int mapHeight);
BaseObject* GetObjectByType(xml_node item, eID type, int mapHeight);
list<BaseObject*>* GetListObjectFromFile(const string path);