#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <stdio.h>

using namespace std;

int lineNumber;
int lines=1;

string paragraph = "";
int len = paragraph.length();

//function for getting user input
void userInput(){
    string input;
    cout << "Please enter the string" << endl;
    cin.sync();
    getline(cin, input);
    //int len = input.length(); // length of the string;
    lines += len/75;
    paragraph+=input;
    cout << input << endl
         << "length: " << len <<endl
         << "lines: "  << lines << endl;

}

//---------------------GAP BUFFER---------------------------

class GapBuffer{
public:
    vector<char> buffer;
    int buffer_size=100;
    int gap_size = 10;
    int gap_left = 0;
    int gap_right = gap_size - gap_left - 1;
    int size = 50;

    void initializeArray(){
    for(int i = 0; i<buffer_size; i++){
        buffer.push_back('_');
    }
    }


void growSize(int position, int k){



        char temp_storage[size];



        //storing to replace the buffer
        for(int i = 0; i <size-position ; i++){
            temp_storage[i] = buffer[position + i];
        }
        for(int i = 0; i < k;i++){
            buffer[position+i] = 'x';
        }
        for(int i = 0;i<size-(position);i++){
            buffer[position+k+i] = temp_storage[i];
        }

                    gap_right+=k;
                    size+=k;

                    for(int i = 0; i < sizeof(temp_storage);i++){
                      //  cout << temp_storage[i];

                    }
                    cout << endl;



    }

    void growSize(){
        int position;
        int k;
        cout << "Enter the position to to grow the buffer!" << endl;
        cin >> position;
        cout << "Enter the number of spaces you need:" << endl;
        cin >> k;


        char temp_storage[size];



        //storing to replace the buffer
        for(int i = 0; i <size-position ; i++){
            temp_storage[i] = buffer[position + i];
        }
        for(int i = 0; i < k;i++){
            buffer[position+i] = 'x';
        }
        for(int i = 0;i<size-(position);i++){
            buffer[position+k+i] = temp_storage[i];
        }

                    gap_right+=k;
                    size+=k;

                    for(int i = 0; i < sizeof(temp_storage);i++){
                      //  cout << temp_storage[i];

                    }
                    cout << endl;



    }

    void insertText(int position){
        string inputText;
        cout << "Please enter the text:" << endl;
        cin.sync();
        getline(cin, inputText);

        paragraph+=inputText;

        moveCursor(position);
        int lengthOfText = inputText.length(); //LENGTH OF TEXT
        int iter=0; // ITERATOR
            while(iter<lengthOfText){
                    if(len>=size-5){
                        buffer.resize(size+50,'_');
                        size+=500;
                      //cout << "buffer empty!" << endl;
                    }else{
                        //buffer[gap_right] = buffer[gap_left];
                        buffer[gap_left] = inputText[iter];

                        size++;
                        gap_left++;
                        gap_right++;
                        iter++;
                    }



            }
        }

void insertText(){
        int position;
        cout << "Enter the position:" << endl;
        cin >> position;
        string inputText;
        cout << "Please enter the text:" << endl;
        cin.sync();
        getline(cin, inputText);
        int lengthOfText = inputText.length(); //LENGTH OF TEXT
        //moveCursor(position);
        //growSize(position,lengthOfText);
       //char arr[buffer_size];

       // for (int i = 0; i <buffer_size; i++){
         //              arr[i] = buffer[gap_left];
           //          buffer[gap_left] = inputText[i];
             //        buffer[i+position+lengthOfText]=arr[i];
                //        size++;
                  //      gap_left++;
                       // moveCursor(len);
                        //gap_right++;
        growSize(position,lengthOfText);
        for (int i = 0; i <lengthOfText; i++){
            buffer[position+i] = inputText[i];
        }








                    }




    void moveGapLeft(int position){
        if(gap_left>position){
                while(gap_left>position){
            buffer[gap_right--]=buffer[--gap_left];
            buffer[gap_left]='_';
            }
        }else{
            cout << "Cannot move the gap to the specified position(left)" << endl;

        }

    }
    void moveGapRight(int position){
        if(gap_right<position){
            while(gap_left<position){
                buffer[gap_left++]=buffer[++gap_right];
                buffer[gap_right]='_';
            }
        }else{
            cout << "Cannot move the gap to the specified position(right)" << endl;
        }
    }

    void moveCursor(int position){
        if(position<=gap_left){
            moveGapLeft(position);
        }else{
            moveGapRight(position);
        }
    }


    void displayBuffer(vector<char> arr){
        for(int i = 0; i<size;i++){
            cout << arr[i];
        }
        cout <<endl;

    }
};

int main()

{
    //int len = paragraph.length();
    GapBuffer gb;
    gb.initializeArray();
    int choice;

   while(1){

   cout << " Select from below: " << endl;
   cout << "1. Enter text normally." << endl;
   cout << "2. to grow." << endl;
   cout << "3. to insert text at a specific position." << endl;
   cout << "4. Display buffer." << endl;
   cin >> choice;

   switch(choice){
   case 1:
        gb.insertText(gb.gap_left);
    break;

    case 2:
        gb.growSize();
        break;
    case 3:
        gb.insertText();
        break;
    case 4:
        gb.displayBuffer(gb.buffer);
        break;
    default:
        cout << "invalid" << endl;
   }
    gb.displayBuffer(gb.buffer);
    cout << len  << endl;
    cout << paragraph << endl;


   }
    return 0;
}
