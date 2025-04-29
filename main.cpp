#include <bits/stdc++.h>

bool IsHorizontallySymmetrical(std::string word)
{
    std::string horizontallySymmetricalSymbols = "BCDEHIKOX\f\n\r\t\v";
    bool isSymmetrical = false;
    for (int i = 0; i < word.size(); i++)
    {
        isSymmetrical = false;
        for (int j = 0; j < horizontallySymmetricalSymbols.size(); j++)
        {
            // std::cout << word[i] << " " << horizontallySymmetricalSymbols[j] << "\n";
            if (word[i] == horizontallySymmetricalSymbols[j])
            {
                isSymmetrical = true;
                break;
            }
        }
        if (!isSymmetrical) return false;
    }
    return true;
}

bool IsVerticallySymmetrical(std::string word)
{
    std::string verticallySymmetricalSymbols = "AHIMOTUVWXY\f\n\r\t\v";
    bool isSymmetrical = false;
    for (int i = 0; i < word.size(); i++)
    {
        isSymmetrical = false;
        for (int j = 0; j < verticallySymmetricalSymbols.size(); j++)
        {
            if (word[i] == verticallySymmetricalSymbols[j])
            {
                isSymmetrical = true;
                break;
            }
        }
        if (!isSymmetrical) return false;
    }
    return true;
}

int main()
{
    // Load the dataset
    std::cout << "Loading the dataset...\n";
    std::fstream datasetFile;
    datasetFile.open("dataset.txt", std::ios::in);
    std::vector<std::string> dataset;
    dataset.push_back("obco");
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
    std::vector<std::string> horizontallySymmetricalWords;
    std::vector<std::string> verticallySymmetricalWords;
    for (int i = 0; i < dataset.size(); i++)
    {
        if (IsHorizontallySymmetrical(dataset[i])) horizontallySymmetricalWords.push_back(dataset[i]);
        if (IsVerticallySymmetrical(dataset[i])) verticallySymmetricalWords.push_back(dataset[i]);
    }

    // Find the longest words
    std::string longestWord = "";
    for (int i = 0; i < horizontallySymmetricalWords.size(); i++)
    {
        if (horizontallySymmetricalWords[i].size() > longestWord.size())
            longestWord = horizontallySymmetricalWords[i];
    }
    std::cout << "The longest horizontally symmetrical word is " << longestWord << "\n";
    longestWord = "";
    for (int i = 0; i < verticallySymmetricalWords.size(); i++)
    {
        if (verticallySymmetricalWords[i].size() > longestWord.size())
            longestWord = verticallySymmetricalWords[i];
    }
    std::cout << "The longest vertically symmetrical word is " << longestWord << "\n";

    // Write the output
    std::fstream horizontalOutputFile;
    horizontalOutputFile.open("horizontal_output.txt", std::ios::out);
    std::fstream verticalOutputFile;
    verticalOutputFile.open("vertical_output.txt", std::ios::out);
    std::fstream combinedOutputFile;
    combinedOutputFile.open("combined_output.txt", std::ios::out);

    for (int i = 0; i < horizontallySymmetricalWords.size(); i++)
    {
        horizontalOutputFile << horizontallySymmetricalWords[i] << "\n";
        combinedOutputFile << horizontallySymmetricalWords[i] << "\n";
    }
    for (int i = 0; i < verticallySymmetricalWords.size(); i++)
    {
        verticalOutputFile << verticallySymmetricalWords[i] << "\n";
        combinedOutputFile << verticallySymmetricalWords[i] << "\n";
    }

    horizontalOutputFile.close();
    verticalOutputFile.close();
    combinedOutputFile.close();

    return 0;
}
