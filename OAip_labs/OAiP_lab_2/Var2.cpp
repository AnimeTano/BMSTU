#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;


bool isletter(char letter){
    return (letter >= 'a' && letter <= 'z') || (letter >= 'A' && letter <= 'Z');
}


bool Strochnaya(char letter){
    return (letter >= 'A' && letter <= 'Z');
}


vector<string> LineSpliting(char* stroka){
    vector<string> words;
    string word;

    for (short i = 0; i <= strlen(stroka); i++){
        if (isletter(stroka[i]) && i < strlen(stroka)){
            word += stroka[i];
        } else {
            if (word.size() > 0){
                words.push_back(word);
                word.clear();
            }
        }
    }

    return words;
}


string TwoPointer(string word1, string word2){
    string shortest, res = "";
    short minlen = 30000;

    for (short start = 0; start < word1.size(); start++){
        for (short end = (start + 1); end < word1.size() + 1; end++){
            res = word1.substr(start, end - start);

            if (word2.find(res) != string::npos){
                if (res.length() < minlen){
                    minlen = res.length();
                    shortest = res;
                }
            }
        }
    }

    // for (short i = 0; i < min(word1.size(), word2.size()); i++){
    //     for (short j = 0; j < max(word1.size(), word2.size()); j++){
    //         if (word1[j] == word2[j]){
    //             length++;
    //             res += word1[j];
    //             ans.push_back({res, length});
    //         } else {
    //             if (length > 0){
    //                 ans.push_back({res, length});
    //                 length = 0;
    //                 res = "";
    //             }
    //         }
    //     }
    // }

    // auto mv = min_element(ans.begin(), ans.end(), [](auto& x, auto& y){
    //     return x.second < y.second;
    // })->second;

    // vector<pair<string, short>> result;
    // copy_if(ans.begin(), ans.end(), back_inserter(result), [mv](auto& element){
    //     return element.second == mv;
    // });

    return shortest;
}



int main(){
    const short size = 500;
    char stroka[size];

    cout << "Enter str:";
    cin.getline(stroka, size);


    short count = 0, mn = 30000, length = 0;

    short cnt_b = 0, word = 0, equal_f_l = 0;
    char letter;

    for (short i = 0; i <= strlen(stroka); i++){
        
        if (isletter(stroka[i]) && i < strlen(stroka)){
            length++;

            if (word == 1){
                if (stroka[i] == 'b'){
                    cnt_b++;
                }
            }

            if (Strochnaya(stroka[i])){
                stroka[i] = tolower(stroka[i]);
            }

        } else {
            if (length > 0){

                if (stroka[i - 1] == 'a'){
                    count++;
                }

                if (length < mn){
                    mn = length;
                }

                if (stroka[i - 1] == stroka[i - length]){
                    equal_f_l++;
                }

                length = 0;
                word++;
            }
        }

    }

    cout << "End with 'a':" << count << endl;
    cout << "P.S. We search only 'a' in the end, not 'A'" << endl;

    cout << "Min len:" << mn << "\n";

    cout << "Count b:" << cnt_b << "\n";

    cout << "String in low register:" << "\n";
    cout << stroka << "\n";

    cout << "Words with equal first and last letter:" << equal_f_l << std::endl;

    vector<string> words = LineSpliting(stroka);

    short sz;
    if (10 < words.size()){
        sz = 10;
    } else sz = words.size();

    for (short i = 0; i < sz; i++){
        for (short j = (i + 1); j < sz; j++){
            string st = TwoPointer(words[i], words[j]);

            if (st.size() > 0){
                cout << "Min substr between " << words[i] << " and " << words[j] << " is:" << st << "\n";
            } else cout << "No substr between " << words[i] << " and " << words[j] << "\n";

        }
    }

    return 0;
}