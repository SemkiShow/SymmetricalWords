#include <bits/stdc++.h>

bool IsHorizontallySymmetrical(std::string word)
{
    std::string horizontallySymmetricalSymbols = "BCDEHIKOX";
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
    std::string verticallySymmetricalSymbols = "AHIMOTUVWXY";
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

bool HasPointOfReflection(std::string word)
{
    std::string pointOfReflectionSymbols = "HINOSXZ";
    bool isSymmetrical = false;
    for (int i = 0; i < word.size(); i++)
    {
        isSymmetrical = false;
        for (int j = 0; j < pointOfReflectionSymbols.size(); j++)
        {
            if (word[i] == pointOfReflectionSymbols[j])
            {
                isSymmetrical = true;
                break;
            }
        }
        if (!isSymmetrical) return false;
    }
    for (int i = 0; i < floor(word.size() / 2.0); i++)
    {
        if (word[i] != word[word.size()-1-i]) return false;
    }
    return true;
}

std::string trim(const std::string & s)
{
    auto first = s.find_first_not_of("\f\n\r\t\v");
    auto last  = s.find_last_not_of ("\f\n\r\t\v");
    return (first == s.npos) ? "" : s.substr(first, last+1);
}

int main()
{
    // Load the dataset
    std::cout << "Loading the dataset...\n";
    std::fstream datasetFile;
    datasetFile.open("dataset.txt", std::ios::in);
    std::vector<std::string> dataset;
    std::string buf = "";
    while (std::getline(datasetFile, buf))
        dataset.push_back(trim(buf));
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
    std::vector<std::string> pointOfReflectionWords;
    for (int i = 0; i < dataset.size(); i++)
    {
        if (IsHorizontallySymmetrical(dataset[i])) horizontallySymmetricalWords.push_back(dataset[i]);
        if (IsVerticallySymmetrical(dataset[i])) verticallySymmetricalWords.push_back(dataset[i]);
        if (HasPointOfReflection(dataset[i])) pointOfReflectionWords.push_back(dataset[i]);
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
    longestWord = "";
    for (int i = 0; i < pointOfReflectionWords.size(); i++)
    {
        if (pointOfReflectionWords[i].size() > longestWord.size())
            longestWord = pointOfReflectionWords[i];
    }
    std::cout << "The longest word with a point of reflection is " << longestWord << "\n";

    // Write the output
    std::fstream horizontalOutputFile;
    horizontalOutputFile.open("horizontal_output.txt", std::ios::out);
    std::fstream verticalOutputFile;
    verticalOutputFile.open("vertical_output.txt", std::ios::out);
    std::fstream pointOfReflectionOutputFile;
    pointOfReflectionOutputFile.open("point_output.txt", std::ios::out);
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
    for (int i = 0; i < pointOfReflectionWords.size(); i++)
    {
        pointOfReflectionOutputFile << pointOfReflectionWords[i] << "\n";
        combinedOutputFile << pointOfReflectionWords[i] << "\n";
    }

    horizontalOutputFile.close();
    verticalOutputFile.close();
    pointOfReflectionOutputFile.close();
    combinedOutputFile.close();

    return 0;
}
