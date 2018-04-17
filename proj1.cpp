/* Jesslyn Zamora
 * Assignment 01
 * Section 05
 * The project runs very efficiently and may take around 10 seconds or less depending on the size of the file.
*/

#include <iostream>
#include <iomanip>
#include <cctype>
#include <map>
#include <string>

using namespace std;

int main()
{

  	const int top = 10;       //the most used 10 characters, numbers and words
  	int word_tracker = 0;     //keeps track of the position of the word that is inserted
  	int num_tracker = 0;      //keeps track of the position of the number that is inserted
  	char input;               //is the character that is being read
  	string inp;
  	string inp1;

	map<char,int>CharMap;             //store the character and when it occurs
  	map<char,int>::iterator CharIt;   //pointer to track the pair in CharMap

  	map<string,int>WordMap;             //store the string and when it occurs
  	map<string,int>::iterator WordIt;   //pointer to track the pair

  	map<string,int>NumMap;              //store the string and when it occure
  	map<string,int>::iterator NumIt;    //pointer to track the pair

  	map<string,int>word_order;              //tracks where the word was inserted
  	map<string,int>::iterator order_word;   //pointer that points to the word mapping

 	map<string,int>num_order;               //tracks where the number was inserted
  	map<string,int>::iterator order_num;    //pointer that points to the number mapping;

	//take a look as to what the next character is, doesn't read it in
  	input = cin.peek();

	do 
	{
		//start of the alphabetic case
       		if(isalpha(input))
		{
        		inp = "";       //initialize the string to be blank

		//if the word has a capital letter then get the input
		//increment the counter if the input exists
		//if not then create a new pair with the map
		
		while(isalpha(input))
        	{
          		cin.get(input);
          		CharMap[input]++;
          		char temp = tolower(input);

			//attaches the now lower-case input to the empty string as it keeps reading input
			//continues the loop or ends depending on the input
			
			inp = inp + temp;
         	 	input = cin.peek();
        	}

		//searches for the inputed word in WordMap
		//if the word does not exist, then increment the word num_tracker
		//increment the counter or create a new pair

		order_word = WordMap.find(inp);

          	if(order_word == WordMap.end())
          	{
            		word_order[inp] = word_tracker++;
          	}

          	WordMap[inp]++;
      		}
	
		//repeat the same process but for the number case

		else if (isdigit(input))
      		{
        		inp1 = "";

        		while(isdigit(input))
        		{
         	 		cin.get(input);
          			CharMap[input]++;
          			inp1 = inp1 + input;
          			input = cin.peek();
        		}

        		order_num = NumMap.find(inp1);

        		if(order_num == NumMap.end())
        		{
          			num_order[inp1] = num_tracker++;
        		}

        		NumMap[inp1]++;
      		}

		//this case is for the non alphatectic and non digits
	
		else
		{
			cin.get(input);
			CharMap[input]++;
			input = cin.peek();
		}

	} while (!cin.eof());

	//the case for the character case 
	int letter_size = CharMap.size();	//the size of the char container
	int letter_loop;			//variable for the size of the loop

	//calculation for the size of the loop
	//if the variable top that is set to 10 is less than or equal to the size of the char container then the size of the loop equals the amount in the top variable 
	//else the amount of times it loops is equal to the size of the container
	if(top <= letter_size)				
		letter_loop = top;
	else 
		letter_loop = letter_size;

	//printing of the header,the size of the container is printed and the amount of times the loop runs is printed
	cout << "\nTotal  " << letter_size << " different characters, " << letter_loop << " most used characters:\n";

	//start the counter and continue till it reached the end of the loop size with one more added
	for(int i = 1; i < letter_loop + 1; i++)
	{
		char letter = 0;		//tracker for the current most used character
		int letter_time = 0;		//the amount of times the character is used
	
		//start at the beginning of the character map
		//run until the character iterator map is not equal to the end of the character map 
		for(CharIt = CharMap.begin(); CharIt != CharMap.end(); CharIt++)
		{
			//here the character in the iterator map has to occur more times 
			//or occur the same amount of times its being used and it has to occur earlier
			//therefore it can replace the character as most used
			if(((*CharIt).second > letter_time) || (((*CharIt).second == letter_time) && ((*CharIt).first < (letter))))
			{
				letter = (*CharIt).first;
				letter_time = (*CharIt).second;
			}
		}

		//erase the current most used word
		CharMap.erase(letter);
		

		//the different cases for different characters
		//if the character is a new line then we print out the symbol for a new-line
		//the same goes for the tab
		//if none of those are found then print as normal in symmetrical columns 
		if(letter == '\n')	
			cout << "No." << i   << ":\t" << setw(18) << left << "\\n" << letter_time << endl;
		else if(letter == '\t')
			cout << "No." << i << ":\t" << setw(18) << left << "\\t" << letter_time << endl;
		else
			cout << "No." << i << ":\t" << setw(18) << left << letter << letter_time << endl;
		
	}


	//here is the case for the word 

	int size_word = WordMap.size();		//the size of the char container
	int word_loop;				//variable for size of the loop 

	//here we calculate the size of the loop 
	//if the variable top that is set to 10 is less than or equal to the size of the word container then the size of the loop equals the amount in the container
	//else the amount of times it loops is equal the size of the container
	if(top <= size_word)
		word_loop = top;
	else
		word_loop = size_word;
	
	//printing of the header, the size of the container is printed but only ran certain amount of times
	cout << "\nTotal " << size_word << " different words, " << word_loop << " most used words:\n";

	//start the counter at and continue till the reaches the end of the loop size with one more added
	for(int i = 1; i < word_loop + 1; i++)
	{
		//the tracker for the current most used string
		string word = "";
		//the times it's being used
		int word_time = 0;
	
		//start at the beginning of the word iterator map
		//run until the iterator map doesn't equal the end of the word map
		for(WordIt = WordMap.begin(); WordIt != WordMap.end(); WordIt++)
		{
			//here the word in the iterator map has to occur more times 
			//or occur the same amount of times its being used and it has to occur earlier
			//therefore it can replace the word as most used 
			if(((*WordIt).second > word_time) || (((*WordIt).second == word_time) && (word_order[(*WordIt).first] < word_order[word])))
			{
				word = (*WordIt).first;
				word_time = (*WordIt).second;
			}
		}
		
		//we erase the current most used word
		WordMap.erase(word);

		cout << "No." << i << ":\t" << setw(18) << left << word << word_time << endl;
	}

	//here we have the case for the numbers

	int size_num = NumMap.size();			//the size of the container
	int loop_size;

	if(top <= size_num)
		loop_size = top;
	else
		loop_size = size_num;
 
	cout << "\nTotal " << size_num << " different numbers, " << loop_size << " most used numbers:\n";

	for(int i = 1; i < loop_size + 1 ; i++)
	{

		string num = "";

		int times = 0;

		for(NumIt = NumMap.begin(); NumIt != NumMap.end(); NumIt++)
		{
			if(((*NumIt).second > times ) || (((*NumIt).second == times) && (num_order[(*NumIt).first] < num_order[num])))
			{
				num = (*NumIt).first;
				times = (*NumIt).second;
			}
		}

		NumMap.erase(num);

		cout << "No." << i << ":\t" << setw(18) << left << num << times << endl;
	}

	
	return 0;
}
