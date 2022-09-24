#include "crypt.hpp"

int main(){
    string filename, tip, message;
    string op;


    while(true){
        cout << "------------------------------------------" << endl;
        cout << "MESSAGES ENCRYPTOR AND DECRYPTOR:" << endl;
        cout << "1. Encrypt message;" << endl;
        cout << "2. Decrypt message;" << endl;
        cout << "3. Write message;" << endl;
        cout << "4. How to use;" << endl;
        cout << "5. Quit." << endl;
        cout << endl <<"Option: ";
        getline(cin, op);

        if (op == "1"){ 
            cout << "Correspondent operator: ";
            cin >> filename;
            cin.ignore();
            filename = "./encoders/" + filename + ".txt";
            if(EncryptMessage(filename)){
                cout << "Message encrypted successfully!" << endl;
            } else{
                cout << "Somthing went wrong!" << endl;
            }

            continue;
        }

        if (op == "2"){
            string operatorName;
            cout << "Name of the file containing the message: ";
            cin >> filename;
            cout << "The tip is: " << getTip(filename) << endl;
            cout << "What is you answer?: ";
            cin >> operatorName;
            cin.ignore();
            operatorName = "./encoders/" + operatorName + ".txt";
            cout << "The message is:" << endl;
            cout << DecryptMessage(filename, operatorName) << endl;
            continue;
        }

        if (op == "3"){
            cout << "Tip: ";
            getline(cin, tip);
            int tmp;
            string filenameMessage;
            cout << "Do you want to select a file containing the message (type 1) or write a new one (type 2)?: ";
            cin >> tmp;
            cin.ignore();
            if (tmp == 1){
                char resp;
                cout << "What is the file's name?: ";
                cin >> filenameMessage;
                message = LoadMessage(filenameMessage);
                cout << "So, the message is: " << message << endl;
                cout << "Do you want to procede writing the message? (y or n): ";
                cin >> resp;
                cin.ignore();
                if(resp == 'y'){
                    if (WriteMessage(tip, message)){
                        cout << "Message written succesfully!" << endl;
                    }else{
                        cout << "Something went wrong!" << endl;
                    }
                }
            }

            if(tmp == 2){
                cout << "Message: " << endl;
                getline(cin, message);
                if (WriteMessage(tip, message)){
                    cout << "Message written succesfully!" << endl;
                }else{
                    cout << "Something went wrong!" << endl;
                }
            }

            if (tmp > 3 || tmp <= 0){
                continue;
            }
            continue;
        }

        if (op == "4"){
            cout << endl << "a) Think of a Rainbow Six Siege operator;" << endl;
            cout << "b) Type 3 in the main menu;" << endl;
            cout << "c) Type a hint that leads to the operator you thought " << endl << "  (something that only the one who you want to send this to would understand, preferably);" << endl;
            cout << "d) Insert the message you want to send;" << endl;
            cout << "e) To encrypt the message, type 1 in the main menu;" << endl;
            cout << "f) Inform the name of the operator you thought of " << endl << "  (with a capital letter in the beginning);" << endl;
            cout << "g) The encrypted message will appear in the same folder" << endl << "   you left the program executable and encoders folder" << endl << "   as \"encrypted_message.txt\"" << endl;
            cout << "h) You can then rename that file and send it;" << endl;
            cout << "i) To decrypt a message, type 2 in the main menu;" << endl;
            cout << "j) Inform the name of the file that contains the encrypted message you were sent;" << endl;
            cout << "k) A tip to find out the name of the \"key\" operator name will appear;" << endl;
            cout << "l) Type the name of the operator you think it is;" << endl << "  (with a capital letter in the beginning);" << endl;
            cout << "m) If you guessed it right, the decrypted message will appear." << endl << "   If not, only a strange sequence of characters will be shown;" << endl;
            cout << "n) In that case, don't worry, just do steps i-l again and try again!" << endl;

            continue;
        }

        if (op == "5"){
            break;
        }
    }

    return 0;
}