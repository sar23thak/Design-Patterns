#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class DocumentEditor{
    private:
    vector<string> documentElements;
    string renderedDocument;

    public:
        //add text as a plain string to the document
        void addText(string text){
            documentElements.push_back(text);
        }

        //add image represented by its file path
        void addImage(string imagePath){
            documentElements.push_back(imagePath);
        }

        string renderDocument(){
            if(renderedDocument.empty())
            {
                string result;
                for(auto element:documentElements){
                    if(element.size()>4 && (element.substr(element.size()-4) == ".jpg"||
                    element.substr(element.size()-4) == ".png")){
                        result += "[Image: " + element + "]" + "\n";
                    }
                    else{
                        result += element + "\n";
                    }
                }
                renderedDocument = result;
            }
            return renderedDocument;
        }
        void saveToFile()
        {
            ofstream file("document.txt");
            if(file.is_open()){
                file << renderDocument();
                file.close();
            }
            else{
                cout << "Unable to open file for writing." << endl;
            }
        }
};

int main(){
    DocumentEditor editor;
    editor.addText("This is a sample document.");
    editor.addImage("image1.jpg");
    editor.addText("This document contains an image.");
    cout<<editor.renderDocument() << endl;
    editor.saveToFile();
    return 0;
}