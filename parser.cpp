#include "parser.hpp"


using namespace std;

Parser::Parser(){

}

std::string * Parser::split(std::string str){
	str += " ";
	int startPos = 0;
	int index = 0;
	int length = 0;
	//transform(str.begin(), str.end(), str.begin(), ::tolower);

	for(int i = 0; i < str.length(); i++){
		length++;
		if(str[i] == ' ' && index <3){
			strVec[index] = str.substr(startPos,length-1);
			++index;
			startPos = i+1;
			length = 0;
		}
	}
	return strVec;
}

int Parser::parse(){
	string inputLine;
	cout << ">";
	getline(cin, inputLine);
	transform(inputLine.begin(), inputLine.end(), inputLine.begin(), ::tolower);
	std::string * inputs = split(inputLine);

	int action = -1;
	if(commands.isCommand(inputs[0])){
		action = translate(inputs[0]);
	}
	return action;
}

int Parser::translate(string str) const{

	if(regex_match(str, regex("go"))){
	//	cout << "command:go" << endl;
		return GO_C;
	} else if (regex_match(str, regex("pickup"))){
	//	cout << "command:pickup" << endl;
		return PICKUP_C;
	} else if (regex_match(str, regex("examine"))){
	//	cout << "command:examine" << endl;
		return EXAMINE_C;
	} else if (regex_match(str, regex("quit|exit"))){
	//	cout << "command:quit" << endl;
		return QUIT_C;
	} else if (regex_match(str, regex("commands"))){
	//	cout << "command:commands" << endl;
		return COMMANDS_C;
	} else if (regex_match(str, regex("directions|exits"))){
	// 	cout << "command:directions" << endl;
		return DIRECTION_C;
	} else if (regex_match(str, regex("backpack"))){
	//  cout << "command:backpack" << endl;
		return BACKPACK_C;
	} else if (regex_match(str, regex("whereami"))){
	//  cout << "command:whereami" << endl;
		return WHEREAMI_C;
	} else if (regex_match(str, regex("whoami"))){
	//	cout << "command:whoami" << endl;
		return WHOAMI_C;
	} else if (regex_match(str, regex("talk")) && regex_match(getSecondWord(), regex("to"))){
	//	cout << "command:talk to" << endl;
		return TALK_C;
	} else if(regex_match(str, regex("health"))){
	//  cout << "command:health" << endl;
		return HEALTH_C;
	}
	else {
		cout << "Returning -1" << endl;
		return -1;
	}
}

std::string Parser::getSecondWord() const{
	return strVec[1];
}

std::string Parser::getThirdWord() const{
	return strVec[2];
}
