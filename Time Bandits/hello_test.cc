#include <gtest/gtest.h>
#include <fstream>
#include <string>
#include <vector>
#include "action.h"
#include "actionListener.h"
#include "character.h"
#include "fileMessagesToString.h"
#include "message.h"
#include "fileToString.h"

using std::vector;

// Demonstrate some basic assertions.
TEST(HelloTest, BasicAssertions) {
	// Expect two strings not to be equal.
	EXPECT_STRNE("hello", "world");
	// Expect equality.
	EXPECT_EQ(7 * 6, 42);
}


// Test for file opening
bool CanOpenFile(const std::string& filename) {
	std::ifstream file(filename);
	return file.is_open();
}

TEST(FileOpenTest, CanOpenExistingFile) {
    std::string filename = "blankScreen.txt"; // Replace with the path to a real file

    EXPECT_TRUE(CanOpenFile(filename)) << "File " << filename << " could not be opened.";
}

TEST(FileOpenTest, CannotOpenNonExistentFile) {
    std::string filename = "blankScreen2.txt"; // Replace with a path to a file that doesn't exist


    EXPECT_FALSE(CanOpenFile(filename)) << "File " << filename << " should not be opened.";
}


// Test Action class

//TEST(ActionTest, BasicAssertions) {
    //action ac, ac2;
    //ac2.setActionDetails("Here", "R", 32);
    //ac.setActionDetails("This is cool", "E", 34);

    //EXPECT_EQ("This is cool", ac.getActionName());
    //EXPECT_EQ("E", ac.getKeyCodeName());
    //EXPECT_EQ(34, ac.getkeyCode());


    // Expect fail
    //EXPECT_NE("This is cool", ac2.getActionName());
    //EXPECT_NE("E", ac2.getKeyCodeName());
    //EXPECT_NE(34, ac2.getkeyCode());

    // -----------
    //EXPECT_TRUE(ac2.checkAction(32));
    //EXPECT_FALSE(ac2.checkAction(31));
//}


// Test Action Listener / color (Implement this later)
/**
TEST(ActionListener, BasicAssertions) {
    actionListener ac, ac2;
}
*/


// Test character

TEST(Character, BasicAssertions) {
    character ac, ac2;
    ac.setColor(0, 15);
    ac2.setColor(4, 3);
    ac.setChar("H");
    ac2.setCharNull(true);

    EXPECT_EQ(15,ac.getBackgroundColor());
    EXPECT_NE(15, ac2.getBackgroundColor());

    EXPECT_EQ(0, ac.getTextColor());
    EXPECT_NE(0, ac2.getTextColor());

    EXPECT_EQ(ac.getChar(), "H");
    EXPECT_NE(ac.getChar(), "E");

}

// Test fileMessagesToString W.I.P
/**
TEST(fileMessagesToString, BasicAssertions) {
    fileMessagesToString ac = fileMessagesToString("helloTestFile");
    vector<message> m = ac.getLines();
    ASSERT_GE(m.size(), 1) << "The message vector should have at least one element.";
    EXPECT_EQ("abc", m[0].getMessage(0));

}
*/


/**
fileMessagesToString::fileMessagesToString(string file) {
    string filePath = file + ".text";

    str = getText(filePath);
}

vector<message> fileMessagesToString::getLines() { return str; }

vector<message> fileMessagesToString::getText(string filePath) {
    fstream file;
    file.open(filePath, ios::in);
    if (!file.is_open()) { return std::vector<message>(); }

    vector<message> lines;
    string tp = "";
    int pos = 0;
    while (getline(file, tp)) {
        vector<string> msg;
        while (tp.length() > 85) {
            for (int splitChar = tp.length(); splitChar > 0; splitChar--) {
                if (splitChar > 85) { splitChar = 85; }
                if (tp.at(splitChar) == ' ') {
                    string cutStr = tp.substr(0, splitChar);
                    tp = tp.substr(splitChar + 1);
                    msg.push_back(" <     " + cutStr);
                    break;
                }
            }
        }
        msg.push_back(" <     " + tp);
        message mess;
        mess.setMessages(msg);
        lines.push_back(mess);
    }

    file.close();
    return lines;
}

*/

TEST(MessageTest, PrintMessages) {
    message msgObj;
    msgObj.addMessage("Hello");
    msgObj.addMessage("World");

    // Redirect cout to a stringstream to capture the output
    std::stringstream buffer;
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());

    msgObj.printMessages();

    std::cout.rdbuf(old); // Restore cout's original buffer

    // Check the output
    EXPECT_EQ(buffer.str(), "Hello\nWorld\n"); // Adjust this based on your expected output
}

/*
    unable to test anything in the game engine file as it contains multiple classes for efficency
TEST(ScreenTest, RefreshScreen) {
    Screen screen;
    // Test if the method does not crash or throw any errors
    EXPECT_NO_THROW(screen.refreshScreen());
    EXPECT_NO_THROW(screen.changeScreenSize(100, 50)); // Test for a typical screen size
    vector<character> characters = screen.loadAsset("Backgrounds/test.txt"); // Replace with a valid file for the test
    EXPECT_GT(characters.size(), 0); // Assuming the file contains characters, expect size > 0
}
*/

TEST(FileToStringTest, ConstructorAndGetText) {
    // Create a test file
    std::ofstream file("testFile.txt");
    file << "Hello, World!";
    file.close();

    std::ofstream colorFile("testFile.color");
    colorFile << "wwwwwwwwwwwww";  // Dummy color data
    colorFile.close();

    std::ofstream bgColorFile("testFile.background");
    bgColorFile << "bbbbbbbbbbbbb";  // Dummy background color data
    bgColorFile.close();

    // Create fileToString object
    fileToString fileObj("testFile");
    EXPECT_EQ(fileObj.getText(), "\nHello, World!");

    // Clean up test files
    remove("testFile.txt");
    remove("testFile.color");
    remove("testFile.background");
}

TEST(FileToStringTest, GetTextFileDoesNotExist) {
    EXPECT_ANY_THROW(fileToString fileObj = fileToString("nonexistentFile"););

}

TEST(FileToStringTest, TextToChar) {
    // Create test files
    std::ofstream file("testFile.txt");
    file << "ABC";
    file.close();

    std::ofstream colorFile("testFile.color");
    colorFile << "01253";  // Text color data
    colorFile.close();

    std::ofstream bgColorFile("testFile.background");
    bgColorFile << "34535";  // Background color data
    bgColorFile.close();

    // Create fileToSting object
    
    fileToString fileObj = fileToString("testFile");
    std::vector<character> chars = fileObj.textToChar();
    
    
    //ASSERT_EQ(chars.size(), 3);
    EXPECT_EQ(chars[1].getChar(), "A");
    EXPECT_EQ(chars[2].getChar(), "B");
    EXPECT_EQ(chars[3].getChar(), "C");

    
    // Expected color mappings (based on the colors and background color strings)
    EXPECT_EQ(chars[1].getTextColor(), 2);
    EXPECT_EQ(chars[1].getBackgroundColor(), 5);

    EXPECT_EQ(chars[2].getTextColor(), 5);
    EXPECT_EQ(chars[2].getBackgroundColor(), 3);

    EXPECT_EQ(chars[3].getTextColor(), 3);
    EXPECT_EQ(chars[3].getBackgroundColor(), 5);
   
    

    // Clean up test files
    remove("testFile.txt");
    remove("testFile.color");
    remove("testFile.background");
}
