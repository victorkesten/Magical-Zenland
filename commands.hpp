//Commands class.
class Commands{
	const std::string commandList[13] = {"health","go","examine","pickup","commands","quit","exit", "directions", "backpack", "whereami", "whoami", "talk", "exits"};
public:
	Commands(){}

	std::string returnCommandList() const{
		std::string returnList = "";
		for(std::string command : commandList){
			returnList+= command;
		}
		return returnList;
	}

	bool isCommand(std::string str) const{
		for(auto command : commandList){
			if(str == command){
				return true;
			}
		}
		return false;
	}
};