#include <iostream>
#include <fstream>
using namespace std;

string codeIt(string Word, int move=5){
	string result="";
	int newChar;
	
	for(int i=0;i<Word.length();i++){
		if(Word[i]==(char)(32)) result+="%";
		else if(Word[i]=='O') result+=(char)(163);
		else if(Word[i]=='R') result+=(char)(161);
		else{
			newChar=(int)Word[i]+move;
			if(newChar>122){
				result+=(char)(newChar-26);
			}
			else result+=(char)(newChar);
		}
	}
	return result;
}

string uncodeIt(string codedWord, int move=5){
	string result="";
	int newChar;
	
	for(int i=0;i<codedWord.length();i++){
		if(codedWord[i]==(char)(37)) result+=(char)(32);
		else if(codedWord[i]==(char)(163)) result+=(char)(79);
		else if(codedWord[i]==(char)(161)) result+=(char)(82);
		else{
			newChar=(int)codedWord[i]-move;
			if(newChar<97){
				result+=(char)(newChar+26);
			}
			else result+=(char)(newChar);
		}
	}
	return result;
}

int main(){
	ifstream urInput("polKitchenWare.txt");
	ifstream engInput("engKitchenWare.txt");
	
	ofstream urOutput("polKitchenWareCoded.txt");
	ofstream engOutput("engKitchenWareCoded.txt");
	
	string engWord;
	string urWord;
	
	while(getline(urInput,urWord) && getline(engInput, engWord)){
		urOutput<<codeIt(urWord)<<'\n';
		engOutput<<codeIt(engWord)<<'\n';
		
		//cout<<codeIt(urWord)<<"	"<<codeIt(engWord)<<'\n';
		//cout<<uncodeIt(codeIt(urWord))<<"	"<<uncodeIt(codeIt(engWord))<<'\n';

	}
	return 0;
}
