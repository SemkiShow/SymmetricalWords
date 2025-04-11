#include <iostream>
#include <vector>
#include <bits/stdc++.h>

int main()
{
    // Load the dataset
    std::cout << "Loading the dataset...\n";
    std::fstream datasetFile;
    datasetFile.open("dataset.txt", std::ios::in);
    std::vector<std::string> dataset;
    std::string buf = "";
    while (std::getline(datasetFile, buf))
        dataset.push_back(buf);
    datasetFile.close();
    
    // Convert all the words to uppercase
    std::cout << "Converting all the letters to uppercase...\n";
    for (int i = 0; i < dataset.size(); i++)
    {
        for (int j = 0; j < dataset[i].size(); j++)
        {
            dataset[i][j] = std::toupper(dataset[i][j]);
        }
    }

    // Find symmetrical words
    std::cout << "Finding symmetrical words...\n";
    std::string notHorizontalLetters = "AFGJLMNPRSTUVWYZĄĘŚŃŻŹŁÓ";
    std::string notVerticalLetters = "BCDEFGJKLNPRSXZĄĘŚŃŻŹŁÓ";
    bool isHorizontal = true;
    bool isVertical = true;
    std::vector<std::string> output;
    for (int i = 0; i < dataset.size(); i++)
    {
        isHorizontal = true;
        for (int j = 0; j < dataset[i].size(); j++)
        {
            for (int k = 0; k < notHorizontalLetters.size(); k++)
            {
                if (dataset[i][j] == notHorizontalLetters[k])
                {
                    isHorizontal = false;
                    break;
                }
            }
            if (!isHorizontal) break;
        }
        
        isVertical = true;
        for (int j = 0; j < dataset[i].size(); j++)
        {
            for (int k = 0; k < notVerticalLetters.size(); k++)
            {
                if (dataset[i][j] == notVerticalLetters[k])
                {
                    isVertical = false;
                    break;
                }
            }
            if (!isVertical) break;
        }

        if (isHorizontal || isVertical)
            output.push_back(dataset[i]);
    }

    // Find the longest word
    std::string longestWord = "";
    for (int i = 0; i < output.size(); i++)
    {
        if (output[i].size() > longestWord.size())
            longestWord = output[i];
    }
    std::cout << "The longest word is " << longestWord << "\n";

    // Write the output
    std::fstream outputFile;
    outputFile.open("output.txt", std::ios::out);
    for (int i = 0; i < output.size(); i++)
        outputFile << output[i] << "\n";
    outputFile.close();

    return 0;
}
